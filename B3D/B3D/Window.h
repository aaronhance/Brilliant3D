#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
//TODO static list of windows
class Window {
public:
	Window();
	~Window();

	static Window* instance;

	void createWindow(uint32_t _width, uint32_t _height, GLFWwindow* _window);
	GLFWwindow* getWindow(); //TODO takes window
	void getWindowReselution(uint32_t* _width, uint32_t* height); //TODO takes window

private:
	uint32_t WIDTH = 800;
	uint32_t HEIGHT = 600;
	GLFWwindow *window;
};

