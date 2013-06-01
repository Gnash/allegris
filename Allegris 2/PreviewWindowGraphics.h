#pragma once
#include "graphicscomponent.h"
#include "Block.h"
class PreviewWindow;
class PreviewWindowGraphics :
	public GraphicsComponent
{
public:
	PreviewWindowGraphics(void);
	PreviewWindowGraphics(PreviewWindow* previewWindow);
	virtual ~PreviewWindowGraphics(void);
	PreviewWindow* getPreviewWindow(void);
	bool draw(void);

private:
	PreviewWindow* previewWindow;
	ALLEGRO_BITMAP* backgroundImage;
};

