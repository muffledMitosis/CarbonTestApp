#include "TestApp.hpp"
#include "Engine/Graphics/OpenGL/API/Buffers.hpp"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Carbon.hpp>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <thread>
#include <vector>

Carbon::Module::Serial* serial;
Carbon::ApplicationWindow* window;
float f;
int pwm;

std::string currentTime(std::chrono::time_point<std::chrono::system_clock> now)
{
	// you need to get milliseconds explicitly
	auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
												now.time_since_epoch())
											% 1000;
	// and that's a "normal" point of time with seconds
	auto timeNow = std::chrono::system_clock::to_time_t(now);
	std::ostringstream currentTimeStream;
	currentTimeStream << std::put_time(localtime(&timeNow), "%d.%m.%Y %H:%M:%S")
										<< "." << std::setfill('0') << std::setw(3)
										<< milliseconds.count() << " "
										<< std::put_time(localtime(&timeNow), "%z");

	return currentTimeStream.str();
}

std::vector<double> vertices =
	{-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

void TestApp::Init()
{
	if(!glfwInit())
	{
		std::cout << "Could not initialize glfw" << std::endl;
	}
	serial = new Carbon::Module::Serial({9600, "/dev/ttyUSB0"});
	window = new Carbon::ApplicationWindow();
	this->ExitCondition = !glfwWindowShouldClose(window->window);
	// glfwMakeContextCurrent(window->window);
	gladLoadGL();
	glClearColor(1.0, 0, 0, 0);

	Graphics::VBO* vbo = new Graphics::VBO();
	vbo->BufferData(vertices, GL_STATIC_DRAW);
}

void TestApp::Update()
{
	this->ExitCondition = !glfwWindowShouldClose(window->window);
	serial->writeTestArduino();
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(window->window);
	glfwPollEvents();
}
