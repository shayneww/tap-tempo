# Tap Tempo 🎶
A simple C++ tool to calculate a song's BPM (beats per minute) through user input.

## Features
**Accurate timing:** Usage of std::chrono::steady_clock for high-precision interval measurement.

**BPM Smoothing:** Calculates a rolling average of the last 16 taps to get a stable value.

**BPM Reset (main loop):** Reset the counter instantly by entering `0` in the console.

## Using it in your own project

- Copy `TapTempo.h` and `TapTempo.cpp` into your project directory.
- Include the header where you need it: `#include "TapTempo.h"`
- Create a `TapTempo` object and call `.tap()` whenever your input event (button click, MIDI signal, etc.) occurs.

**Example code:**
```cpp
#include <iostream>
#include "TapTempo.h"

int main() {
    TapTempo tapper;

    // call tap() whenever your input event occurs
    bool isBeat = tapper.tap(); 
    
    if (isBeat) {
        std::cout << "Current BPM: " << tapper.getBPM() << std::endl;
    }

    return 0;
}
```

> [!NOTE]
> Calculated BPM values may vary depending on the consistency of the tapping!
