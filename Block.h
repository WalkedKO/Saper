#pragma once
class Block
{
	public:
		int x, y, z, w; // positions
		/// <summary>
		/// The neighbours with bombs counter
		/// </summary>
		int neighboursWithBomb;
		/// <summary>
		/// If the block is clicked
		/// </summary>
		bool isClicked;
		Block(int x, int y, int z, int w, bool bomb, int neighbours) :
			x(x), y(y), z(z), w(w),
			isBomb(bomb),
			isFlagged(false),
			isClicked(false),
			neighboursWithBomb(neighbours) {}
		/// <summary>
		/// If false, there is no bomb, if true, there is
		/// </summary>
		bool isClear();
		void flag();
	private:
		bool isFlagged;
		bool isBomb;
		
};

