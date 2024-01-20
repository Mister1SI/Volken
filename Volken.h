#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>
#include <iostream>

class Volken {
private:
	void initVulkan();
	void mainLoop();
	void cleanup();
	void createInstance();

	GLFWwindow* window;
	VkInstance instance;

public:
	void run();
};
