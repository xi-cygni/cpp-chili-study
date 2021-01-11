#pragma once
#include "Graphics.h"
#include "Location.h"
#include <random>

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int GridGetWidth() const;
	int GridGetHeight() const;
	bool IsInBoard(const Location & loc) const;
	bool CheckForObstacle(const Location& loc) const;
	void SpawnRandomObstacle(std::mt19937& rng, const class Snake& snake, const class Goal& goal);
	void DrawBorder();
	void DrawObstacles();
private:
	static constexpr Color colorBorder = Colors::Blue;
	static constexpr Color colorObstacle = Colors::Gray;
	static constexpr int dimension = 20;
	static constexpr int width = 32;
	static constexpr int height = 24;
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 2;
	static constexpr int cellPadding = 1;
	static constexpr int x = 70;
	static constexpr int y = 50;
	bool hasObstacle[width * height] = { false };
	Graphics &gfx; 
};