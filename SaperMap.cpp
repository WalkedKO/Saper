#include "SaperMap.h"
#include <vector>
#include <cstdlib>
SaperMap::SaperMap(int size, int bombs) : size(size), bombs(bombs), state(0), clickedBlocks(0)
{
	saperMap = createSaperMap();
	std::vector<int*> bombsVec = bombsLocation();
	for (int* block : bombsVec) saperMap[block[0]][block[1]][block[2]][block[3]]->isBomb = true;
	for (int w = 0; w < size; w++)
	{
		for (int z = 0; z < size; z++)
		{
			for (int y = 0; y < size; y++)
			{
				for (int x = 0; x < size; x++) countNeighbours(x, y, z, w);
			}
		}
	}

}
void SaperMap::click(int x, int y, int z, int w)
{

}
void SaperMap::flag(int x, int y, int z, int w)
{

}
int SaperMap::getClickedBlocks()
{

}
int SaperMap::getBombs()
{

}
Block** SaperMap::getPanel(int z, int w)
{

}

void SaperMap::fill(int x, int y, int z, int w)
{

}
int SaperMap::countNeighbours(int centX, int centY, int centZ, int centW)
{
	int counter = 0;
	for (int w = -1; w <= 1; w++) {
		for (int z = -1; z <= 1; z++) {
			for (int y = -1; y <= 1; y++) {
				for (int x = -1; x <= 1; x++) {
					if (centW + w < 0 || centZ + z < 0 || centY + y < 0 || centX + x < 0) break;
					if (centW + w >= size || centZ + z >= size || centY + y >= size || centX + x >= size) break;
					if (w == 0 && z == 0 && y == 0 && x == 0) break;
					if (saperMap[centW + w][centZ + z][centY + y][centX + x]->isBomb) counter++;
				}
			}
		}
	}
	return counter;
}
Block***** SaperMap::createSaperMap() {
	Block***** tempSaperMap = new Block****[size];
	for (int w = 0; w < size; w++)
	{
		tempSaperMap[w] = new Block * **[size];
		for (int z = 0; z < size; z++) {
			tempSaperMap[w][z] = new Block * *[size];
			for (int y = 0; y < size; y++) {
				tempSaperMap[w][z][y] = new Block * [size];
				for (int x = 0; x < size; x++) tempSaperMap[w][z][y][x] = new Block(x, y, z, w);
			}
		}

	}
	return tempSaperMap;
}
std::vector<int*> SaperMap::bombsLocation() {
	std::vector<int*> bombsLoc;
	int similarity;
	for (int i = 0; i < bombs; i++) 
	{
		int* tempArr;
		tempArr = new int[4];
		for (int j = 0; j < 4; j++) tempArr[j] = rand() % size;
		for (int* element : bombsLoc)
		{
			similarity = 0;
			int j = 0;
			for (j = 0; j < 4; j++)
			{
				if (tempArr[j] == element[j]) similarity++;
			}
			if (similarity != 4) bombsLoc.push_back(tempArr);
			else 
			{
				i--;
				break;
			}
		}
	}
	return bombsLoc;
}