#include "FrameTimer.h"
using namespace std::chrono;

FrameTimer::FrameTimer()
{
	last = steady_clock::now(); //initializes last to the current position of the clock
}

float FrameTimer::Mark() // takes time of last frame, how much it took to continue to next operations
{
	const auto old = last;          
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}
