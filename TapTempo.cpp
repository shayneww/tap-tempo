#include "TapTempo.h"
#include <numeric>
#include <cmath>

TapTempo::TapTempo() {
	reset();
}

void TapTempo::reset() {
	intervals.clear();
	isFirstTap = true;
}

bool TapTempo::tap() {
	auto currentTapTime = std::chrono::steady_clock::now(); // get current time

	if (isFirstTap) {
		lastTapTime = currentTapTime;
		isFirstTap = false;
		return false; // just started, no interval yet
	}

	std::chrono::duration<double> elapsed = currentTapTime - lastTapTime;
	double interval = elapsed.count(); // get the interval in seconds

	intervals.push_back(interval);

	if (intervals.size() > ROLLING_AVERAGE) { // only keep the last 16 intervals to get the rolling average
		intervals.erase(intervals.begin());
	}

	lastTapTime = currentTapTime;
	return true;
}

int TapTempo::getBPM() {
	if (intervals.empty()) return 0;

	double sum = std::accumulate(intervals.begin(), intervals.end(), 0.0);
	double avg = sum / intervals.size();
	if (avg == 0) return 0;
	return std::round(60.0 / avg); // BPM = 60 seconds / average interval in seconds
}
