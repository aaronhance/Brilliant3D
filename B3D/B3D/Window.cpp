#include "stdafx.h"
#include "Window.h"
#include <stdexcept>
#include <iostream>

Window* Window::instance;


Window::Window() {

	instance = this;

	try {
		glfwInit();

	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

//create window function


Window::~Window() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Window::createWindow(uint32_t _width, uint32_t _height, GLFWwindow * _window) {

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); //TODO enable resizing

	window = glfwCreateWindow(_width, _height, "Brilliant3D", nullptr, nullptr);

}

GLFWwindow* Window::getWindow() {
	return window;
}

void Window::getWindowReselution(uint32_t * _width, uint32_t * _height)
{
	_width = &instance->WIDTH;
	_height = &instance->HEIGHT;
}
