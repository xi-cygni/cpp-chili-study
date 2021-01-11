/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (inhibitUp)
		{
		}
		else
		{
			vy = vy - 1;
			inhibitUp = true;
		}
	}
	else
	{
		inhibitUp = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (inhibitDown)
		{
		}
		else
		{
			vy = vy + 1;
			inhibitDown = true;
		}
	}
	else
	{
		inhibitDown = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (inhibitRight)
		{
		}
		else
		{
			vx = vx + 1;
			inhibitRight = true;
		}
	}
	else
	{
		inhibitRight = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (inhibitLeft)
		{
		}
		else
		{
			vx = vx - 1;
			inhibitLeft = true;
		}
	}
	else
	{
		inhibitLeft = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		vx = 0;
		vy = 0;
	}

	x = clampScreenX(x);
	y = clampScreenY(y);

	collsion = OverlapTest(x_fixed,y_fixed,x,y) ||
			   OverlapTest(700, 400, x, y);

	x = x + vx;
	y = y + vy;
}

void Game::ComposeFrame()
{
	DrawBox(x_fixed, y_fixed, 0, 255, 0);
	DrawBox(700, 400, 66, 77, 88);
	DrawCursor(x, y, r, g, b);

	if (collsion)
	{
		DrawCursor(x, y, r, 0, 0);
	}
	else
	{
		DrawCursor(x, y, r, g, b);
	}
	collsion = false;

}
	void Game::DrawBox(int x, int y, int r, int g, int b)
	{
		for (int i = 0; i <= 20; i++)
		{
			gfx.PutPixel(-5 + x, y + i, r, g, b);
			gfx.PutPixel(-5 + x + i, y + 20, r, g, b);
			gfx.PutPixel(-5 + x + i, y, r, g, b);
			gfx.PutPixel(15 + x, y + i, r, g, b);
		}
	}
	void Game::DrawCursor(int x, int y, int r, int g, int b)
	{
		//window keybored,certain key is being checked, virtual key codes !!!

		gfx.PutPixel(-5 + x, y, r, g, b); //puts pixel on board
		gfx.PutPixel(-4 + x, y, r, g, b);
		gfx.PutPixel(-3 + x, y, r, g, b);
		gfx.PutPixel(3 + x, y,  r, g, b);
		gfx.PutPixel(4 + x, y,  r, g, b);
		gfx.PutPixel(5 + x, y,  r, g, b);
		gfx.PutPixel(x, -5 + y, r, g, b);
		gfx.PutPixel(x, -4 + y, r, g, b);
		gfx.PutPixel(x, -3 + y, r, g, b);
		gfx.PutPixel(x, 3 + y,  r, g, b);
		gfx.PutPixel(x, 4 + y,  r, g, b);
		gfx.PutPixel(x, 5 + y,  r, g, b);
	}

	bool Game::OverlapTest(int box0x, int box0y, int cursor0x, int cursor0y)
	{
		return (cursor0x >= -10 + box0x && 
				cursor0x <= 20 + box0x && 
				cursor0y >= box0y - 5 && 
				cursor0y <= box0y + 25);
	}
	int Game::clampScreenX(int x)
	{
		if (x + 5 >= gfx.ScreenWidth)
		{
			return gfx.ScreenWidth - 5 - 1;
		}
		else if (x + 5 <= 0)
		{
			return 5;
		}
		else
		{
			return x;
		}
	}
	int Game::clampScreenY(int y)
	{
		if (y + 6 >= gfx.ScreenHeight)
		{
			return gfx.ScreenHeight - 5 - 2;	
		}
		else if (y - 6 <= 0)
		{
			return 7;
		}
		else
		{
			return y;
		}
	}