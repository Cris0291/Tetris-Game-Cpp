#include "Block.h"

Block::Block() {
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
}

void Block::Draw() {

	std::vector<Position> tiles = cells[rotationState];

	for (auto tile : tiles) {
		DrawRectangle(tile.column * cellSize + 1, tile.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
	}
}