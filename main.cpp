#include <iostream>
#include <string>
#include "TapTempo.h"

int main() {
	TapTempo tapper;
	std::string input;

	std::cout << "--- TAP TEMPO ---\n" << std::endl;
	std::cout << "[ENTER] to tap.\n";
	std::cout << "[0] then [ENTER] to reset.\n";
	std::cout << "[Ctrl+C] to quit.\n\n";

	std::cout << "Start tapping..";

	while (true) {
		std::getline(std::cin, input);

		if (input == "0") {
			tapper.reset();
			std::cout << "--- RESET ---\n" << std::endl;
			continue;
		}

		bool isBeat = tapper.tap();
		if (!isBeat) {
			std::cout << "First tap registered. Keep tapping!" << std::endl;
		}
		else {
			std::cout << "BPM: " << tapper.getBPM() << std::endl;
		}
	}
	return 0;
}