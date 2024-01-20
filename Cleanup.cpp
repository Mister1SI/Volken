#include "Volken.h"

void Volken::cleanup() {
	glfwDestroyWindow(window);

	glfwTerminate();
}

