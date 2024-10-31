#include "Grid.h"
#include <iostream>
#include "Colors.h"

Grid::Grid() {
	m_numRows = 20;
	m_numCols = 10;
	m_cellSize = 30;
	Initialize();
	colors = GetCellColors();
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
  
void Grid::Draw() {
	for (int row = 0; row < m_numRows; row++) {
		for (int column = 0; column < m_numCols; column++) {
			int cellValue = grid[row][column];
			DrawRectangle(column * m_cellSize +1, row * m_cellSize + 1, m_cellSize - 1, m_cellSize - 1, colors[cellValue]);
		}
	}
}

bool Grid::IsCellOutside(int row, int column)
{
	if (row >= 0 && row < m_numRows && column >= 0 && column < m_numCols) {
		return false;
	}
	return true;
}
