#pragma once
#include "Graphics.h"
#include "Dude.h"

class Goal
{
public:
	Goal(int in_x, int in_y)
		:
		x(in_x),
		y(in_y)
	{}
	void draw(Graphics& gfx) const
	{
		gfx.DrawRectangle2(x, y, dimension, dimension, c);
	}
	bool TestCollision(const Dude& dude) const;
	void Respawn(int in_x, int in_y);
	void UpdateColor();
private:
	static constexpr int dimension = 20;
	Color c = { 127,0,0 };
	int x;
	int y;
	bool colorIncreasing = true;

};