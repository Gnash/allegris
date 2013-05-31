#include "Block_S_Mirrored.h"


Block_S_Mirrored::Block_S_Mirrored(int x, int y) {
	this->setParent(0);
	this->setRelativeCoord(new Coordinate(x, y));
	this->setHeight(3);
	this->setWidth(2);
	this->setColor(MAGENTA);

	BlockPart* p = new BlockPart(1, 0, getColor());
	this->addBlockPart(p);
	p->setParent(this);
	p = new BlockPart(1, 1, getColor());
	this->addBlockPart(p);
	p->setParent(this);
	p = new BlockPart(0, 1, getColor());
	this->addBlockPart(p);
	p->setParent(this);
	p = new BlockPart(0, 2, getColor());
	this->addBlockPart(p);
	p->setParent(this);
}


Block_S_Mirrored::~Block_S_Mirrored(void)
{
}
