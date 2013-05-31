#include "Block_I.h"


Block_I::Block_I(int x, int y) {
	this->setParent(0);
	this->setRelativeCoord(new Coordinate(x, y));
	this->setHeight(4);
	this->setWidth(1);
	this->setColor(RED);

	BlockPart* p = new BlockPart(0, 0, getColor());
	this->addBlockPart(p);
	p->setParent(this);
	p = new BlockPart(0, 1, getColor());
	this->addBlockPart(p);
	p->setParent(this);
	p = new BlockPart(0, 2, getColor());
	this->addBlockPart(p);
	p->setParent(this);
	p = new BlockPart(0, 3, getColor());
	this->addBlockPart(p);
	p->setParent(this);
}


Block_I::~Block_I(void)
{
}
