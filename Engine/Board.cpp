#include "Board.h"

Board::Board(Graphics & gfx):
	gfx(gfx)
{
}

int Board::GetWidth()
{
	return width;
}

int Board::GetHeight()
{
	return height;
}

void Board::DrawCell(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	const int off_x = x + borderWidth + borderPadding;
	const int off_y = y + borderWidth + borderPadding;		//by declaring separate offset variables the complexity is reduced while drawing border
	gfx.DrawRectDim(loc.x*dimension + off_x + cellPadding, loc.y*dimension + off_y + cellPadding, dimension - 2 * cellPadding, dimension - 2 * cellPadding, c);
}

bool Board::IsInsideBoard(Location & loc) const
{
	return loc.x >= 0 && loc.x < width &&
		loc.y >= 0 && loc.y < height;
}

void Board::DrawBorder()
{
	//these variables handle complexity since x and y are unchangeable.
	//the top left of board is now the top of border.
	const int top = y;
	const int left = x;
	const int bottom = top + (borderPadding + borderWidth) * 2 + height * dimension;
	const int right = left + (borderPadding + borderWidth) * 2 + width * dimension;
	//gfx reference for board is already initialized so we can call it.
	//note to always specify the coordinates of top left and bottom right of rectangle
	//top border rectangle
	gfx.DrawRect(left, top, right, top + borderWidth, borderColor);
	//left border rectnagle
	gfx.DrawRect(left,top+borderWidth,left+borderWidth,bottom-borderWidth,borderColor);
	//right border rectangle
	gfx.DrawRect(right-borderWidth,top+borderWidth,right,bottom-borderWidth,borderColor);
	//bottom border rectangle
	gfx.DrawRect(left, bottom - borderWidth, right, bottom, borderColor);
}
