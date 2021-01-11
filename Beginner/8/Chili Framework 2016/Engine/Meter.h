#pragma once
#include "Graphics.h"

class Meter
{
public:
	Meter(int x, int y)
		:
		x(x),
		y(y)
	{}
	void IncreaseLevel()
	{
		level++;
	}
	int GetLevel() const
	{
		return level;
	}
	void Draw(Graphics& gfx)
	{
		gfx.DrawRectangle2(x, y, level*scale, girth, c);
	}
private:
	static constexpr Color c = Colors::Blue;
	static constexpr int girth = 12; // how fat the meter is
	static constexpr int scale = 4;
	int level = 0;
	int x;
	int y;
};