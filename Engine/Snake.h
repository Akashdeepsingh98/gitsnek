#pragma once
#include "Board.h"
#include <assert.h>
class Snake			//represents snake as whole entity.manage all segments within snake
{
private:
	class Segment 
	{
	public:
		void InitHead(const Location& loc);
		void InitBody(Color in_c);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd)const;
		const Location& getLocation()const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd);
	Location GetNextHeadPosition(const Location& delta_loc)const;
	bool IsInTileExceptEnd(const Location& target)const;
	bool IsInTile(const Location& target)const;
private:
	static constexpr int n_SegmentsMax = 100;
	static constexpr Color headColor = Colors::Yellow;
	Segment segments[n_SegmentsMax];
	int n_Segments = 1;
};