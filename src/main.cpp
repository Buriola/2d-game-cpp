#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Core/Engine.hpp"

using namespace Core;

int main(int argc, char* argv[])
{
	Engine::GetInstance()->Init();

	// Game loop
	while(Engine::GetInstance()->IsRunning())
	{
		Engine::GetInstance()->Events();
		Engine::GetInstance()->Update(0.0f);
		Engine::GetInstance()->Render();
	}

	Engine::GetInstance()->Clean();
	return 0;
}