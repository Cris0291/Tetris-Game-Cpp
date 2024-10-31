#pragma once
#include <vector>
#include <raylib.h>

class Grid {
public:
	Grid();
	void Initialize();
	void Print();
	void Draw();
	bool IsCellOutside(int row, int column);
	int grid[20][10];
private:
	int m_numRows;
	int m_numCols;
	int m_cellSize;
	std::vector<Color> colors;
};
