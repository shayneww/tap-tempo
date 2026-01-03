#pragma once
#include <vector>
#include <chrono>

class TapTempo
{
public:
	TapTempo();
	bool tap();
	int getBPM();
	void reset();
private:
	std::vector<double> intervals;
	std::chrono::time_point<std::chrono::steady_clock> lastTapTime;
	bool isFirstTap;
	const int AVERAGE = 16;
};

