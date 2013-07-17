#include "PreviewWindowGraphics.h"
#include "PreviewWindow.h"
#include "globals.h"
#include <allegro5/allegro_primitives.h>


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
	al_draw_filled_rectangle(x, y, x + PREVIEW_WINDOW_WIDTH, y + SCREEN_HEIGHT, al_map_rgb(20, 40, 20));
	al_draw_bitmap(backgroundImage, x, y, 0);
	success = success && getPreviewWindow()->getNextBlock()->draw();
	return success;
}

PreviewWindow* PreviewWindowGraphics::getPreviewWindow(void) {
	return this->previewWindow;
}