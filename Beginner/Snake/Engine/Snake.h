#pragma once
#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& in_loc);
		void InitBody(Color c_in);
		void MoveBy(const Location& delta_loc);
		void Follow(const Segment& next);
		void Draw(Board& brd) const;
		const Location & GetLocation() const;
	private:
		Location loc;
		Color c;

	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc); // moves snake by certain delta value
	void Grow();
	void Draw(Board brd)const;
	Location GetNextHeadLocation(const Location& delta_loc) const; // const coz doesnt change the snake, it just gives info
	bool isInTile(const Location& target) const;
	bool isInTileWithEnd(const Location& target) const;
private:
	static constexpr int nSegmentsMax = 100;
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	Segment segments[nSegmentsMax];
	int nSegments = 1; // how much segments we use
};