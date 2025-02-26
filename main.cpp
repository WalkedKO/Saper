#include <iostream>
#include "SaperMap.h"

using namespace std;
void PrintPlain(Block*** plain, int size) {
	string temp;
	//int counter = 0;
	for (int y = 0; y < size; y++) {
		temp = "| ";
		for (int x = 0; x < size; x++) {
			temp = temp + plain[y][x]->toString() + " ";
			//if (plain[y][x]->ifBomb()) counter++;
		}
		temp += "|";
		cout << temp << endl;
	}
	//return counter;
}

int main()
{
	SaperMap* tester = new SaperMap(4,100);
	Block*** block = tester->getPanel(1, 1);
	PrintPlain(block, 4);
}