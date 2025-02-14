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
		Block(int x, int y, int z, int w) :
			x(x), y(y), z(z), w(w),
			isFlagged(false),
			isClicked(false){}
		/// <summary>
		/// If false, there is no bomb, if true, there is
		/// </summary>
		bool isClear();
		void flag();
		friend class SaperMap;
	private:
		bool isFlagged;
		bool isBomb;
		
		
};

