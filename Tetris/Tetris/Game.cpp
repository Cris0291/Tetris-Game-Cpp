#include "Game.h"
#include <random>

Game::Game() {
	grid = Grid();
	blocks = {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock() {

	if (blocks.empty()) {
		blocks = GetAllBlocks();
	}
	int randomIndex = rand() % blocks.size();
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}

std::vector<Block> Game::GetAllBlocks(){
	return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

void Game::Draw() {
	grid.Draw(); 
	currentBlock.Draw();  
}