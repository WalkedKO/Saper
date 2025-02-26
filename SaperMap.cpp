#include "SaperMap.h"
#include <vector>
#include <cstdlib>
SaperMap::SaperMap(int size, int bombs) : size(size), bombs(bombs), state(0)
{
	saperMap = createSaperMap();
	bombsVec = bombsLocation();
	for (int* block : bombsVec) saperMap[block[0]][block[1]][block[2]][block[3]]->isBomb = true;
	for (int w = 0; w < size; w++)
	{
		for (int z = 0; z < size; z++)
		{
			for (int y = 0; y < size; y++)
			{
				for (int x = 0; x < size; x++) {
					Block* tempBlock = saperMap[w][z][y][x];
					if(!tempBlock->ifBomb()) tempBlock->neighboursWithBomb = countNeighbours(x, y, z, w);
				}
			}
		}
	}

}
bool SaperMap::click(int x, int y, int z, int w)
{
	// if clicked or not yet, doesnt make a difference in logic
	Block* blockRef = saperMap[w][z][y][x];
	int tempArr[4] = {x, y, z, w};
	if (!blockRef->isClicked) clickedBlocksVec.push_back(tempArr);
	if (blockRef->isBomb) return false;
	return true; 
}
void SaperMap::flag(int x, int y, int z, int w)
{
	Block* blockRef = saperMap[w][z][y][x];
	blockRef->flag();
}
int SaperMap::getClickedBlocks()
{
	return clickedBlocksVec.size();
}
int SaperMap::getBombs()
{
	return bombsVec.size();
}
Block*** SaperMap::getPanel(int z, int w)
{
	return saperMap[w][z];
}

void SaperMap::fill(int centX, int centY, int centZ, int centW)
{
	for (int w = -1; w <= 1; w++) {
		for (int z = -1; z <= 1; z++) {
			for (int y = -1; y <= 1; y++) {
				for (int x = -1; x <= 1; x++) {
					if (centW + w < 0 || centZ + z < 0 || centY + y < 0 || centX + x < 0) break;
					if (centW + w >= size || centZ + z >= size || centY + y >= size || centX + x >= size) break;
					if (w == 0 && z == 0 && y == 0 && x == 0) break;
					Block* tempBlock = saperMap[centW + w][centZ + z][centY + y][centX + x];
					if (tempBlock->neighboursWithBomb == 0 && !(tempBlock->ifBomb()) && !(tempBlock->ifClicked())) {
						fill(centX + x, centY + y, centZ + z, centW + w);
					}
				}
			}
		}
	}
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