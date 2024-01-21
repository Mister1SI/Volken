#include "Volken.h"

void Volken::initVulkan() {
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	window = glfwCreateWindow(WIDTH, HEIGHT, "Volken", nullptr, nullptr);

	createInstance();
	setupDebugMessenger();
	pickPhysicalDevice();
	createLogicalDevice();
}


