#include "Block.h"
bool Block::ifBomb()
{
	return isBomb;
}
bool Block::ifClicked()
{
	return isClicked;
}
void Block::flag() 
{
	isFlagged = !isFlagged;
}
