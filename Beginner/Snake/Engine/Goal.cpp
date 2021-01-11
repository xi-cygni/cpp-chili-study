#include "Goal.h"

Goal::Goal(std::mt19937 & rnd, const Board & brd, const Snake & snake)
{
	Respawn(rnd, brd, snake);
}

void Goal::Respawn(std::mt19937 & rnd, const Board & brd, const Snake & snake)
{
	std::uniform_int_distribution<int> xDist(0, brd.GridGetWidth() - 1);  // we generate rand location for our goal from 0 to width-1
	std::uniform_int_distribution<int> yDist(0, brd.GridGetHeight() - 1); // these are just definitions!!

	Location newLoc;
	do
	{
		newLoc.x = xDist(rnd);
		newLoc.y = yDist(rnd);
	} while (snake.isInTileWithEnd(newLoc));

	loc = newLoc;
}

void Goal::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

const Location & Goal::GetLocation() const
{
	return loc;
}
