#include "PreviewWindowGraphics.h"
#include "PreviewWindow.h"


PreviewWindowGraphics::PreviewWindowGraphics(void) {
}

PreviewWindowGraphics::PreviewWindowGraphics(PreviewWindow* previewWindow) {
	this->previewWindow = previewWindow;
	this->backgroundImage = BitmapHandler::getBitmap(BITMAP_INDEX_BLOCK_PREVIEWWINDOW);
}


PreviewWindowGraphics::~PreviewWindowGraphics(void)
{
}


bool PreviewWindowGraphics::draw(void) {
	bool success = true;
	int x = getPreviewWindow()->getAbsoluteXPos();
	int y = getPreviewWindow()->getAbsoluteYPos();
	al_draw_bitmap(backgroundImage, x, y, 0);
	success = success && getPreviewWindow()->getNextBlock()->draw();
	int bla = SCREEN_WIDTH;
	return success;
}

PreviewWindow* PreviewWindowGraphics::getPreviewWindow(void) {
	return this->previewWindow;
}