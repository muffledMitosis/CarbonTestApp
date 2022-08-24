#include "TestApp.hpp"
#include <Carbon.hpp>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

Carbon::Serial* serial;
Carbon::Window* window;
float f;

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
  // serial = new Carbon::Serial({9600, "/dev/ttyACM0"});
  window = new Carbon::Window();
  this->ExitCondition = !glfwWindowShouldClose(window->window);
  // glClearColor(1.0, 0, 0, 0);
  ImGui::CreateContext();
  ImGui_ImplGlfw_InitForOpenGL(window->window, true);
  ImGui_ImplOpenGL3_Init();
}

void TestApp::Update()
{
  this->ExitCondition = !glfwWindowShouldClose(window->window);
  // serial->readLine();
  glClear(GL_COLOR_BUFFER_BIT);

  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();

  ImGui::NewFrame();

  ImGui::SetNextWindowBgAlpha(0.7f);
  // create a window and append into it
  ImGui::Begin("Controls", NULL, NULL);

  ImGui::Dummy(ImVec2(0.0f, 1.0f));
  ImGui::TextColored(ImVec4(1.0f, 0.0f, 1.0f, 1.0f), "Time");
  ImGui::Text("%s", currentTime(std::chrono::system_clock::now()).c_str());
  ImGui::End();

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  glfwSwapBuffers(window->window);
  glfwPollEvents();
}
