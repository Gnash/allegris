#include "BlockFactory.h"


BlockFactory::BlockFactory(void) {
	srand(time(0));
}


BlockFactory::~BlockFactory(void)
{
}

Block* BlockFactory::createRandomBlock(void) {
	int block = rand() % 7;
	switch (block) {
	case 0:
		return new Block_L(BLOCK_SPAWN_X, BLOCK_SPAWN_Y);
		break;
	case 1:
		return new Block_O(BLOCK_SPAWN_X, BLOCK_SPAWN_Y);
		break;
	case 2:		
		return new Block_L_Mirrored(BLOCK_SPAWN_X, BLOCK_SPAWN_Y);
		break;
	case 3:
		return new Block_S(BLOCK_SPAWN_X, BLOCK_SPAWN_Y);
		break;
	case 4:
		return new Block_S_Mirrored(BLOCK_SPAWN_X, BLOCK_SPAWN_Y);
		break;
	case 5:
		return new Block_I(BLOCK_SPAWN_X, BLOCK_SPAWN_Y);
		break;
	case 6:
		return new Block_T(BLOCK_SPAWN_X, BLOCK_SPAWN_Y);
		break;
	}
	return 0;
}