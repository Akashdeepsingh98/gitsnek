#include "Goal.h"

Goal::Goal(std::mt19937 & rng, Board & brd, const Snake & snake)
{
	Respawn(rng, brd, snake);
}

void Goal::Respawn(std::mt19937 & rng, Board & brd, const Snake & snake)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetHeight() - 1);

	Location newloc;
	do
	{
		newloc.x = xDist(rng);
		newloc.y = yDist(rng);
	} while (snake.IsInTile(newloc));
	loc = newloc;
}

void Goal::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

const Location & Goal::GetLocation() const
{
	// TODO: insert return statement here
	return loc;
}
