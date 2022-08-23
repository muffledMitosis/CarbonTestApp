#pragma once

#include <Carbon.hpp>

class TestApp : public Carbon::Application
{
private:
  
public:
  void Init();
  TestApp() {Init();};
  void Update();
  ~TestApp() {};
};

Carbon::Application* Carbon::CreateApplication()
{
  return new TestApp();
}
