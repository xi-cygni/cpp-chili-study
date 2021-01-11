#include "Board.h"
#include <assert.h>
#include "Snake.h"
#include "Goal.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{}

void Board::DrawCell(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);

	const int off_x = x + borderWidth + borderPadding;
	const int off_y = y + borderWidth + borderPadding;

	gfx.DrawRectDim(loc.x * dimension + off_x + cellPadding, loc.y * dimension + off_y + cellPadding, dimension - cellPadding * 2, dimension - cellPadding * 2, c);
}

int Board::GridGetWidth() const
{
	return width;
}

int Board::GridGetHeight() const
{
	return height;
}

bool Board::IsInBoard(const Location & loc) const
{
	return loc.x >= 0 && loc.x <= width &&
		   loc.y >= 0 && loc.y <=height;
}

bool Board::CheckForObstacle(const Location & loc) const
{
	return hasObstacle[loc.y * width + loc.x]; //2d mapping
}

void Board::SpawnRandomObstacle(std::mt19937 & rng, const Snake & snake, const Goal& goal)
{
	std::uniform_int_distribution<int> xDist(0, GridGetWidth() - 1);  // we generate rand location for our goal from 0 to width-1
	std::uniform_int_distribution<int> yDist(0, GridGetHeight() - 1); // these are just definitions!!

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.isInTileWithEnd(newLoc) || CheckForObstacle(newLoc) || goal.GetLocation() == newLoc);

	hasObstacle[newLoc.y * width + newLoc.x] = true;
}

void Board::DrawBorder()
{
	const int top = y;
	const int left = x;
	const int bottom = top + (borderWidth + borderPadding) * 2 + height * dimension;
	const int right = left + (borderWidth + borderPadding) * 2 + width * dimension;

	gfx.DrawRect(left, top, right, top + borderWidth, colorBorder); // top
	gfx.DrawRect(left, top + borderWidth, left + borderWidth, bottom - borderWidth, colorBorder); // left
	gfx.DrawRect(right - borderWidth, top + borderWidth, right , bottom - borderWidth, colorBorder); // right
	gfx.DrawRect(left, bottom - borderWidth, right, bottom, colorBorder); // bottom
}

void Board::DrawObstacles()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (CheckForObstacle({ j,i }))
			{
				DrawCell({ j,i }, colorObstacle);
			}
		}
	}
}
