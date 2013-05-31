#include "Block_L.h"


Block_L::Block_L(int x, int y) {
	this->setParent(0);
	this->setRelativeCoord(new Coordinate(x, y));
	this->setHeight(3);
	this->setWidth(2);
	this->setColor(BLUE);

	BlockPart* p = new BlockPart(0, 0, getColor());
	this->addBlockPart(p);
	p->setParent(this);
	p = new BlockPart(0, 1, getColor());
	this->addBlockPart(p);
	p->setParent(this);
	p = new BlockPart(0, 2, getColor());
	this->addBlockPart(p);
	p->setParent(this);
	p = new BlockPart(1, 2, getColor());
	this->addBlockPart(p);
	p->setParent(this);
}


Block_L::~Block_L(void) {
	deleteBlockParts();
}
