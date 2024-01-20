#include "Volken.h"


void Volken::run() {
	initVulkan();
	mainLoop();
	cleanup();
}
