#include "TestApp.hpp"

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

Carbon::ApplicationWindow* window;

std::vector<double> vertices
	= {-0.5, 0.5, 0.0, 0.5, 0.5, 0.0, 0.5, -0.5, 0.0, -0.5, -0.5, 0.0};

std::vector<unsigned int> indices = {0, 1, 2, 0, 2, 3};

void TestApp::Init()
{
	if(!glfwInit())
	{
		std::cout << "Could not initialize glfw" << std::endl;
	}

	window							= new Carbon::ApplicationWindow();
	this->ExitCondition = !glfwWindowShouldClose(window->window);

	glfwMakeContextCurrent(window->window);
	gladLoadGL();

	glClearColor(1.0, 0, 0, 0);

	Graphics::VBO* vbo = new Graphics::VBO();
	vbo->BufferData(vertices, GL_STATIC_DRAW);

	Graphics::VAO* vao = new Graphics::VAO();
	vao->spec(0, 3, GL_DOUBLE, 3 * sizeof(double), 0);

	Graphics::EBO* ebo = new Graphics::EBO();
	ebo->BufferData(indices, GL_STATIC_DRAW);

	Graphics::Shader* shader = new Graphics::Shader(
		"/home/meth/dev/CarbonTestApp/libs/Carbon/Assets/basic.vert",
		"/home/meth/dev/CarbonTestApp/libs/Carbon/Assets/basic.frag");
}

void TestApp::Update()
{
	this->ExitCondition = !glfwWindowShouldClose(window->window);
	glClear(GL_COLOR_BUFFER_BIT);

	/* glDrawArrays(GL_TRIANGLES, 0, 3); */
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	glfwSwapBuffers(window->window);
	glfwPollEvents();
}
