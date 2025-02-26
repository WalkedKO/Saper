#include "Block.h"
#include <iostream>
#include <string>
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
std::string Block::toString()
{
	if (isBomb) return "*";
	else if (neighboursWithBomb > 0) return std::to_string(neighboursWithBomb);
	else return " ";
}
