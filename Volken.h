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
	bool checkValidationLayerSupport();



	GLFWwindow* window;
	VkInstance instance;
	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 600;
	std::vector<const char*> validationLayers = {
		"VK_LAYER_KHRONOS_validation"
	};
#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif 

public:
	void run();
};
