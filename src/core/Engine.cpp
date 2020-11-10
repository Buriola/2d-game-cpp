#include "Core/Engine.hpp"
#include <iostream>

Core::Engine* Core::Engine::s_Instance = nullptr;

Core::Engine* Core::Engine::GetInstance() 
{ 
	return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine(); 
}

Core::Engine::Engine()
{

}

bool Core::Engine::Init()
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != 0)
	{
		std::cout << "Something went wrong while initializing the engine. Error: " << SDL_GetError() << std::endl;
		return false;
	}


	m_Window = SDL_CreateWindow("2D Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, 0);
	if(m_Window == nullptr)
	{
		std::cout << "Failed to create Window!. Error: " << SDL_GetError() << std::endl;
		return false;
	}


	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(m_Renderer == nullptr)
	{
		std::cout << "Failed to create Renderer!. Error: " << SDL_GetError() << std::endl;
		return false;
	}

	return m_IsRunning = true;
}

bool Core::Engine::Clean()
{
	return false;
}

void Core::Engine::Quit()
{
	m_IsRunning = false;
}

void Core::Engine::Update(float deltaTime)
{

}

void Core::Engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
	SDL_RenderPresent(m_Renderer);
}

void Core::Engine::Events()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch(event.type)
	{
		case SDL_QUIT:
			Quit();
			break;
	}
}