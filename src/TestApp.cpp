#include <Carbon.h>

class TestApp : Carbon::Application
{
private:
  
public:
  TestApp();
  ~TestApp();
};

Carbon::Application* Carbon::CreateApplication()
{
  return new TestApp();
}
