#pragma once
#include "Grid.h"
#include "Blocks.cpp"

class Game {
public:
	Game();
	void Draw();
	void HandleInput();
	void MoverBlockDown();
	bool gameOver;
	int score;

private:
	bool IsBlockOutside();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	void MoveBlockLeft();
	void MoveBlockRight();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void UpdateScore(int linesCleared, int moveDownPoints);
	Grid grid;
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
};
