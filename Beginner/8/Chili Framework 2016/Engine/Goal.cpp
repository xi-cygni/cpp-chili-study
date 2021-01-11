#include "Goal.h"

bool Goal::TestCollision(const Dude & dude) const
{
	const int right0 = dude.getX() + dude.getWidth();
	const int bottom0 = dude.getY() + dude.getHeight();
	const int right1 = x + dimension;
	const int bottom1 = y + dimension;

	return (right0 >= x && bottom0 >= y && right1 >= dude.getX() && dude.getY() <= bottom1);
}

void Goal::Respawn(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}

void Goal::UpdateColor()
{
	if (colorIncreasing)
	{
		if (c.GetR() >= 253)
		{
			colorIncreasing = false;
		}
		else
		{
			c = Color(c.GetR() + 2, c.GetG() + 4, c.GetB() + 4);
		}
	}
	else
	{
		if (c.GetR() <= 127)
		{
			colorIncreasing = true;
		}
		else
		{
			c = Color(c.GetR() - 2, c.GetG() - 4, c.GetB() - 4);
		}
	}
}

