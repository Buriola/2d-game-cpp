#include "include/core/Engine.hpp"
#include "include/core/Time.hpp"

namespace core 
{
	int gameMain(int argc, char* argv[])
	{
		if(!Engine::GetInstance()->Init())
		{
			LogError("Failed initializing Game Engine!");
			return 1;
		}

		// Game loop
		while(Engine::GetInstance()->IsRunning())
		{
			Engine::GetInstance()->Events();
			Engine::GetInstance()->Update();
			Engine::GetInstance()->Render();
			Time::GetInstance()->Tick();
		}

		Engine::GetInstance()->Clean();
		Time::DestroyInstance();
		return 0;
	}
}

int main(int argc, char* argv[])
{
	return core::gameMain(argc, argv);
}