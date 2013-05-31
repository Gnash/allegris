#include "Block_O.h"


Block_O::Block_O(int x, int y) {
	this->setParent(0);
	this->setRelativeCoord(new Coordinate(x, y));
	this->setHeight(2);
	this->setWidth(2);
	this->setColor(YELLOW);

	BlockPart* p = new BlockPart(0, 0, getColor());
	this->addBlockPart(p);
	p->setParent(this);
	p = new BlockPart(0, 1, getColor());
	this->addBlockPart(p);
	p->setParent(this);
	p = new BlockPart(1, 0, getColor());
	this->addBlockPart(p);
	p->setParent(this);
	p = new BlockPart(1, 1, getColor());
	this->addBlockPart(p);
	p->setParent(this);
}


Block_O::~Block_O(void)
{
}
