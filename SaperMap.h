#pragma once
#include "Block.h"
#include <vector>
class SaperMap
{
public:
	int state;

	SaperMap(int size, int bombs);
	// true - no bomb, false - bomb
	bool click(int centX, int centY, int centZ, int centW);
	void flag(int x, int y, int z, int w);
	int getClickedBlocks();
	int getBombs();
	Block*** getPanel(int z, int w);
	// for debug, to delete
	void AltPrint();


private:
	int size;
	int bombs;
	Block***** saperMap;
	std::vector<int*> clickedBlocksVec;
	std::vector<std::array<int, 4>> bombsVec;

	void fill(int x, int y, int z, int w);
	int countNeighbours(int centX, int centY, int centZ, int centW);
	Block***** createSaperMap();
	std::vector<std::array<int,4>> bombsLocation();
	
	
		


};

