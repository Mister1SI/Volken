#include "Volken.h"


void Volken::mainLoop() {
	//std::cout << "Using device: " << deviceName << std::endl;
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}
}
