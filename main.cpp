#include <iostream>
#include "SaperMap.h"

using namespace std;
class Tester
{
	Block*** currentPlain;
	int size, bombs;
	int curW, curZ;
	SaperMap* saperMap;
	Tester(int size, int bombs) : curZ(0), curW(0), size(size), bombs(bombs)
	{
		saperMap = new SaperMap(size, bombs);
		currentPlain = saperMap->getPanel(curZ, curW);
	}
	void PrintPlain() {
		string temp;
		for (int y = 0; y < size; y++) {
			temp = "| ";
			for (int x = 0; x < size; x++) {
				temp = temp + currentPlain[y][x]->toString() + " ";
			}
			temp += "|";
			cout << temp << endl;
		}
	}
	void ChangePlain(int w, int z)
	{
		currentPlain = saperMap->getPanel(z, w);
		PrintPlain();
	}
};


int main()
{
	
}