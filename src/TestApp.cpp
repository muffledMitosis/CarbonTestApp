#include "TestApp.hpp"
#include <Carbon.hpp>

#include <iostream>

Carbon::Serial* serial;

void TestApp::Init()
{
  this->ExitCondition = true;
  serial = new Carbon::Serial({9600, "/dev/ttyACM0"});
}

void TestApp::Update()
{
  serial->readBytes();
}
