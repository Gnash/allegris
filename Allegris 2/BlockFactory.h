#pragma once
#include "Block.h"
#include "Block_L.h"
#include "Block_O.h"
#include "Block_L_Mirrored.h"
#include "Block_S.h"
#include "Block_S_Mirrored.h"
#include "Block_I.h"
#include "Block_T.h"

class BlockFactory
{
public:
	BlockFactory(void);
	virtual ~BlockFactory(void);

	Block* createRandomBlock(void);
};

