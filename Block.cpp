#include "Block.h"
bool Block::isClear()
{
	return isBomb;
}
void Block::flag() 
{
	isFlagged = !isFlagged;
}