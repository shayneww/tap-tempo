# Tap Tempo
A simple C++ tool to calculate a song's BPM (beats per minute) by tapping the `ENTER` key.

## Features
**Accurate timing:** Usage of std::chrono::steady_clock for high-precision interval measurement.

**BPM Smoothing:** Calculates a rolling average of the last 16 taps to get a stable value.

**BPM Reset (main loop):** Reset the counter instantly by entering `0` in the console.

## Usage example

Example in: Visual Studio 2022
- Create a new **Empty Project** in C++.
- Add `main.cpp`, `TapTempo.cpp`, and `TapTempo.h` to the project.
- Click Run.
- Tap `ENTER` to the rhythm of your favourite song.

> [!TIP]
> Main loop doesn't end until you reset it manually.

> [!NOTE]
> Calculated BPM values may vary depending on the consistency of the tapping!
