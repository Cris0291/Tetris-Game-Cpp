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
			DrawRectangle(column * m_cellSize +11, row * m_cellSize + 11, m_cellSize - 1, m_cellSize - 1, colors[cellValue]);
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

bool Grid::isCellEmpty(int row, int column)
{
	if (grid[row][column] == 0) {
		return true;
	}
	return false;
}

int Grid::ClearFullRows()
{
	int completed = 0;
	for (int row = m_numRows - 1; row >= 0; row--) 
	{
		if (IsRowFull(row)) 
		{
			ClearRow(row);
			completed++;
		}
		else if (completed > 0) 
		{
			MoveRowDown(row, completed);
		}
	}
	return completed;
}

bool Grid::IsRowFull(int row)
{
	for (int column = 0; column < m_numCols; column++) 
	{
		if (grid[row][column] == 0) 
		{
			return false;
		}
	}
	return true;
}

void Grid::ClearRow(int row)
{
	for (int column = 0; column < m_numCols; column++) 
	{
		grid[row][column] = 0;
	}
}

void Grid::MoveRowDown(int row, int numRows)
{
	for (int column = 0; column < m_numCols; column++) 
	{
		grid[row + numRows][column] = grid[row][column];
		grid[row][column] = 0;
	}
}
