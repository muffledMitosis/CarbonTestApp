#include "TestApp.hpp"
#include <Carbon.hpp>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <chrono>
#include <iterator>
#include <sstream>
#include <iomanip>
#include <thread>


Carbon::Module::Serial* serial;
Carbon::ApplicationWindow* window;
float f;
int pwm;

std::string currentTime(std::chrono::time_point<std::chrono::system_clock> now)
{
    // you need to get milliseconds explicitly
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()
        ) % 1000;
    // and that's a "normal" point of time with seconds
    auto timeNow = std::chrono::system_clock::to_time_t(now);
std::ostringstream currentTimeStream;
    currentTimeStream << std::put_time(localtime(&timeNow), "%d.%m.%Y %H:%M:%S")
                      << "." << std::setfill('0') << std::setw(3) << milliseconds.count()
                      << " " << std::put_time(localtime(&timeNow), "%z");

    return currentTimeStream.str();
}

void TestApp::Init()
{
  glfwInit();
  serial = new Carbon::Module::Serial({9600, "/dev/ttyUSB0"});
  window = new Carbon::ApplicationWindow();
  this->ExitCondition = !glfwWindowShouldClose(window->window);
   glClearColor(1.0, 0, 0, 0);
}

void TestApp::Update()
{
  this->ExitCondition = !glfwWindowShouldClose(window->window);
   serial->writeTestArduino();
  glClear(GL_COLOR_BUFFER_BIT);
  
  

  glfwSwapBuffers(window->window);
  glfwPollEvents();
}
