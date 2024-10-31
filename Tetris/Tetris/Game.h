#pragma once
#include "Grid.h"
#include "Blocks.cpp"

class Game {
public:
	Game();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	void Draw();
	void HandleInput();
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoverBlockDown();
	Grid grid;
private:
	bool IsBlockOutside();
	void RotateBlock();
	void LockBlock();
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
};
