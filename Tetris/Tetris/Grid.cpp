#include "Grid.h"
#include <iostream>

Grid::Grid() {
	m_numRows = 20;
	m_numCols = 10;
	m_cellSize = 30;
	Initialize();
}

void Grid::Initialize() {
	for (int row = 0; row < m_numRows; row++) {
		for (int column = 0; column < m_numCols; column++) {
			grid[row][column] = 0;
		}
	}
}

void Grid::Print() {
	for (int row = 0; row < m_numRows; row++) {
		for (int column = 0; column < m_numCols; column++) {
			std::cout << grid[row][column] << " ";
		}
		std::cout << std::endl ;
	}
}

std::vector<Color> Grid::GetCellColors() {
	Color darkGrey = { 26, 31, 40, 255 };
	Color green = { 47, 230, 23, 255 };
	Color red = { 232, 18, 18, 155 };
	Color orange = { 226, 116, 17, 255 };
	Color yellow = { 237, 234, 4, 255 };
	Color purple = {166, 0, 247, 255};
	Color cyan = { 21, 204, 209, 255 };
	Color blue = { 13, 64, 216, 255 };

	return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}