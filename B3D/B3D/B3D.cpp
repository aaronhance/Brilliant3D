// B3D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdexcept>
#include "Renderer.h"
#include "Window.h"

//temp
#include <chrono>
#include <thread>

int main()
{
	//TODO, start error logger
	Window *window = new Window();
	window->createWindow(800, 600, nullptr);
	Renderer *renderer = new Renderer(); // INIT in new thread

	std::chrono::time_point<std::chrono::system_clock> start, end;
	double tickLength = 1000 / 50;

	try {
		renderer->init();
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}


	while (!glfwWindowShouldClose(window->getWindow())) {
		start = std::chrono::system_clock::now();

		glfwPollEvents();

		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed = (end - start) / 1000;
		if (elapsed.count() < tickLength) {
			std::this_thread::sleep_for(std::chrono::milliseconds((uint32_t)(tickLength - elapsed.count())));
		}
	}

	delete renderer;
	delete window;
    return 0;
}

