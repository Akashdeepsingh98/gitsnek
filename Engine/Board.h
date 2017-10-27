#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "Location.h"
#include <assert.h>
class Board
{
public:
	Board(Graphics& gfx);
	int GetWidth();
	int GetHeight();
	void DrawCell(const Location& loc,Color c);
	bool IsInsideBoard(Location& loc)const;
	void DrawBorder();
private:
	static constexpr int width = 25;	//width of board i.e. number of cells vertically
	static constexpr int height =25;	//height of board i.e. number of cells horizontally
	static constexpr int dimension = 20;
	static constexpr int cellPadding = 1;		//add padding around every cell for beauty
	static constexpr int x = 20;		//postion of the board
	static constexpr int y = 20;		//position of the board
	static constexpr int borderPadding = 2;
	static constexpr int borderWidth = 4;
	static constexpr Color borderColor = Colors::Blue;
	Graphics& gfx;
};