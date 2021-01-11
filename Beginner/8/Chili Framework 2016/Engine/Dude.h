#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	void clampToScreen();
	void Draw(Graphics& gfx) const;
	void Update(const Keyboard& kbd);
	int getX() const;
	int getY() const;
	int getWidth() const; 
	int getHeight() const;
private:
	static constexpr int speed = 1;
	static constexpr int width = 20;
	static constexpr int height = 20;
	int x = 400;
	int y = 300;
};