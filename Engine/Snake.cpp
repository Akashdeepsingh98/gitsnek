#include "Snake.h"

Snake::Snake(const Location & loc)
{
	constexpr int nBodyColors = 4;		//we are going color1--color2--color3--color2--color1... and so on
	constexpr Color bodyColors[nBodyColors] = {
		{ 10,100,32 },
		{ 10,130,48 },
		{ 18,160,48 },
		{ 10,130,48 }
	};
	for (int i = 0; i < n_SegmentsMax; i++)
	{
		segments[i].InitBody(bodyColors[i%nBodyColors]);
	}
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location & delta_loc)
{
	for (int i = n_Segments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	if (n_Segments < n_SegmentsMax)
	{
		n_Segments++;
	}
}

void Snake::Draw(Board & brd)
{
	for (int i = 0; i < n_Segments; i++)
	{
		segments[i].Draw(brd);
	}
}

Location Snake::GetNextHeadPosition(const Location & delta_loc) const
{
	Location l(segments[0].getLocation());
	l.Add(delta_loc);
	return l;
}

bool Snake::IsInTileExceptEnd(const Location & target) const
{
	for (int i = 0; i < n_Segments-1; ++i)
	{
		if (segments[i].getLocation() == target)
		{
			return true;
		}
	}
	return false;
}

bool Snake::IsInTile(const Location & target) const
{
	for (int i = 0; i < n_Segments ; ++i)
	{
		if (segments[i].getLocation() == target)
		{
			return true;
		}
	}
	return false;
}

void Snake::Segment::InitHead(const Location & in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(Color in_c)
{
	c = in_c;
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Snake::Segment::getLocation() const
{
	return loc;
}
