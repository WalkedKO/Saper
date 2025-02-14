#pragma once
#include "Block.h"
#include <vector>
class SaperMap
{
public:
	int state;

	SaperMap(int size, int bombs);
	void click(int x, int y, int z, int w);
	void flag(int x, int y, int z, int w);
	int getClickedBlocks();
	int getBombs();
	Block** getPanel(int z, int w);
	
private:
	int size;
	int bombs;
	int clickedBlocks;
	Block***** saperMap;

	void fill(int x, int y, int z, int w);
	int countNeighbours(int centX, int centY, int centZ, int centW);
	Block***** createSaperMap();
	std::vector<int*> bombsLocation();
		


};

