#include "TestApp.hpp"
#include <Carbon.hpp>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

Carbon::Serial* serial;
Carbon::Window* window;
float f;

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
  ImGui::Begin("Controls", NULL, ImGuiWindowFlags_NoResize);

  ImGui::Dummy(ImVec2(0.0f, 1.0f));
  ImGui::TextColored(ImVec4(1.0f, 0.0f, 1.0f, 1.0f), "Time");
  ImGui::Text("%s", "lmao");
  ImGui::End();

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  glfwSwapBuffers(window->window);
  glfwPollEvents();
}
