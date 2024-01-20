#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "Volken.h"

int main() {
	Volken app;
	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
