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
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rnd(std::random_device()()),
	snake({ 2,2 }),
	goal(rnd, brd, snake),
	ft()
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
	const float dt = ft.Mark(); // set up delta time we'll be using 

	if (gameStarted)
	{
		if (!gameOver)
		{
			if (wnd.kbd.KeyIsPressed(VK_UP))
			{
				delta_loc = { 0,-1 };
			}
			else if (wnd.kbd.KeyIsPressed(VK_DOWN))
			{
				delta_loc = { 0,1 };
			}
			else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				delta_loc = { 1,0 };
			}
			else if (wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				delta_loc = { -1,0 };
			}
			float snakeModifiedMovePeriod = snakeMovePeriodMin;
			if (wnd.kbd.KeyIsPressed(VK_CONTROL))
			{
				snakeModifiedMovePeriod = std::min(snakeMovePeriodMin, snakeMovePeriodSpeedup);
			}
			snakeMoveConuter += dt;
			if (snakeMoveConuter >= snakeModifiedMovePeriod)         // makes snake to move slower
			{
				snakeMoveConuter -= snakeModifiedMovePeriod;
				const Location next = snake.GetNextHeadLocation(delta_loc);
				if (!brd.IsInBoard(next) || snake.isInTile(next) || brd.CheckForObstacle(next))
				{
					gameOver = true;
				}
				else
				{
					const bool eatin = next == goal.GetLocation();
					if (eatin)
					{
						snake.Grow();
					}
					snake.MoveBy(delta_loc);

					if (eatin)
					{
						goal.Respawn(rnd, brd, snake);
						brd.SpawnRandomObstacle(rnd, snake, goal);
					}
				}
			}

			snakeMoveRate = std::max(snakeMoveRate - dt * snakeSpeedupFactor, snakeMovePeriodMin);
				
				/*nakeSpeedupCpunter++;
			if (snakeSpeedupCpunter >= snakeSpeedupPeriod)
			{
				snakeSpeedupCpunter = 0;
				if(snakeMoveRate > snakeMovePeriodMin)
				{
					snakeMoveRate--;
				}
				// or we could make it: snakeMoveRate = std::max(snakeMoveRate - 1, snakeMovePeriodMin); where snakeMovePeriodMin = 10;  
				//returns the biggest value out of 2 given in brackets.
			}*/
		}
	}
	else
	{
		gameStarted = wnd.kbd.KeyIsPressed(VK_RETURN);
	}
}


void Game::ComposeFrame()
{
	if (gameStarted)
	{
		snake.Draw(brd);
		goal.Draw(brd);
		if (gameOver)
		{
			SpriteCodex::DrawGameOver(350, 265, gfx);
		}
		brd.DrawBorder();
		brd.DrawObstacles();
	}
	else
	{
		SpriteCodex::DrawTitle(290, 225, gfx);
	}
}
