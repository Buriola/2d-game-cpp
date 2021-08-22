#include "include/core/Engine.hpp"
#include "include/core/Time.hpp"

namespace core 
{
	int gameMain(int argc, char* argv[])
	{
		if(!Engine::GetInstance()->Init())
		{
			std::cout << "Failed initializing Game Engine!" << std::endl;
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
		return 0;
	}
}

int main(int argc, char* argv[])
{
	return core::gameMain(argc, argv);
}