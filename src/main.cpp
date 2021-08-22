#include <iostream>
#include "include/core/Engine.hpp"
#include "include/core/Time.hpp"

using Core::Engine;
using Core::Time;

int main(int argc, char* argv[])
{
	Engine::GetInstance()->Init();

	// Game loop
	while(Engine::GetInstance()->IsRunning())
	{
		Engine::GetInstance()->Events();
		Engine::GetInstance()->Update();
		Engine::GetInstance()->Render();
		Time::GetInstance()->Tick();
	}

	Engine::GetInstance()->Clean();
	std::cin.get();
	return 0;
}