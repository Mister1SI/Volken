#pragma once

#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>


#include <stdexcept>
#include <vector>
#include <iostream>
#include <optional>

struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
};



class Volken {
private:
	
	void initVulkan();
	void mainLoop();
	void cleanup();
	void createInstance();
	bool checkValidationLayerSupport();
	std::vector<const char*> getRequiredExtensions();
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData);
	void setupDebugMessenger();
	void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
	VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
		const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	void pickPhysicalDevice();
	bool isDeviceSuitable(VkPhysicalDevice device);
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	void createLogicalDevice();
	void createSurface();


	GLFWwindow* window;
	VkInstance instance;
	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 600;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkDevice device;
	VkPhysicalDeviceFeatures deviceFeatures{};
	VkQueue graphicsQueue;
	VkSurfaceKHR surface;


	char* deviceName = new char[VK_MAX_PHYSICAL_DEVICE_NAME_SIZE];





	std::vector<const char*> validationLayers = {
		"VK_LAYER_KHRONOS_validation"
	};
#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif 
	VkDebugUtilsMessengerEXT debugMessenger;




public:
	void run();
};
