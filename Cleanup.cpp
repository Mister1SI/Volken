#include "Volken.h"

void Volken::cleanup() {
	vkDestroyInstance(instance, nullptr);

	glfwDestroyWindow(window);

	glfwTerminate();
}

