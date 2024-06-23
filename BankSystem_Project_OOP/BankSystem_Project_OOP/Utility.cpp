#include <iostream>
//#include <exception>
#include "Utility.h"

void resetCin() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}