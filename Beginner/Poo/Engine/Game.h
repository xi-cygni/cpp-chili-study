/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	void DrawBox(int x, int y, int r, int g, int b); //fixed
	void DrawCursor(int x, int y, int r, int g, int b); //mobile
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	int x = 400;
	int y = 300;
	int vx = 0;
	int vy = 0;
	int r = 255;
	int g = 255;
	int b = 255;
	bool inhibitUp = false; 
	bool inhibitDown = false;
	bool inhibitRight = false;
	bool inhibitLeft = false;
	int x_fixed = 500;
	int y_fixed = 500;
	bool collsion = false;
	bool OverlapTest(int box0x, int box0y, int cursor0x, int cursor0y);
	int clampScreenX(int x);
	int clampScreenY(int y);
};