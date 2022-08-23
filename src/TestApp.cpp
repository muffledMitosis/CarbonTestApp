#include <Carbon.hpp>

class TestApp : public Carbon::Application
{
private:
  
public:
  TestApp() {};
  ~TestApp() {};
};

Carbon::Application* Carbon::CreateApplication()
{
  return new TestApp();
}
