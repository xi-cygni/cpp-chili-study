#pragma once

#include "Graphics.h"
#include "Dude.h"

class Poo
{
private:
	int x;
	int y;
	int vx = 1;
	int vy = 1;
	static constexpr int height = 24; // static means that instead of storing height in every poo we will have 1 height shared with all poos
	static constexpr int width = 24; // constexpr - the value won't change & is known at the time of compiling the program
	bool isEaten = false;
	bool initialized = false;
public:
	void Initializer(int in_x, int in_y, int in_vx, int in_vy);
	bool TestCollision(const Dude& dude) const; // we would send then dude by value but it would take all variables -> a lot of needless data
	                                           // we make it const because we don't want to change it, we make it "read only" reference
	void Update();
	void Draw(Graphics& gfx) const; // this finction does'nt affect Poo class, it only reads, so we can make a member function constant
};
/* The difference between constexpr and regular const is that constexpr value is always the same , but const means that after this value is initialized
it cannot be changed but it can have a different value every time we run the function*/

/* If you make a variable private the only think that can access the variable is member function of the same class*/