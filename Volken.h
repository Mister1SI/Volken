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
#include <set>
#include <cstdint>
#include <limits>
#include <algorithm>
#include <fstream>




struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool isComplete() {
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
};

struct SwapChainSupportDetails {
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
};



class Volken {
private:
	
	// Main methods
	void initVulkan();
	void mainLoop();
	void cleanup();

	// Device Functions
	void createInstance();
	bool checkValidationLayerSupport();
	std::vector<const char*> getRequiredExtensions();
	void setupDebugMessenger();
	void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
	VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
		const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	void pickPhysicalDevice();
	bool isDeviceSuitable(VkPhysicalDevice device);
	bool deviceExtensionSupport(VkPhysicalDevice device);
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	void createLogicalDevice();
	void createSurface();

	// Swap Chain Functions
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
	VkSurfaceFormatKHR chooseSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR choosePresentMode(const std::vector<VkPresentModeKHR>& availableModes);
	VkExtent2D chooseExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	void createSwapChain();

	// Images
	void createImageViews();

	// Graphics Pipeline
	void createGraphicsPipeline();
	VkShaderModule createShaderModule(const std::vector<char>& code);


	static std::vector<char> readFile(const std::string& filename) {
		std::ifstream file(filename, std::ios::ate | std::ios::binary);
		if (!file.is_open()) {
			throw std::runtime_error("failed to open file!");
		}

		size_t fileSize = (size_t)file.tellg();
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();

		return buffer;
	}



	// Debug
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
			VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
			VkDebugUtilsMessageTypeFlagsEXT messageType,
			const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
			void* pUserData);
#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif 
	VkDebugUtilsMessengerEXT debugMessenger;



	// Members
	GLFWwindow* window;
	VkInstance instance;
	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 600;
	char* deviceName = new char[VK_MAX_PHYSICAL_DEVICE_NAME_SIZE];
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkDevice device;
	VkPhysicalDeviceFeatures deviceFeatures{};
	VkQueue graphicsQueue;
	VkQueue presentQueue;
	VkSurfaceKHR surface;
	VkSwapchainKHR swapchain;
	std::vector<VkImage> swapchainImages;
	VkFormat swapchainImageFormat;
	VkExtent2D swapchainExtent;
	std::vector<VkImageView> imageViews;



	std::vector<const char*> validationLayers = {
		"VK_LAYER_KHRONOS_validation"
	};

	std::vector<const char*> deviceExtensions = {
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};



public:
	void run();
};
