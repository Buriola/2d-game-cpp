#include <iostream>
#include "include/core/Engine.hpp"
#include "include/core/Time.hpp"
#include "include/characters/PlayerCharacter.hpp"
#include "include/graphics/TextureManager.hpp"
#include "include/input/InputHandler.hpp"

namespace core 
{
	Engine* Engine::s_Instance = nullptr;

	Engine* Engine::GetInstance() 
	{ 
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine(); 
	}

	Engine::Engine(){ }

	bool Engine::Init()
	{
		if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_InitFlags::IMG_INIT_PNG |IMG_InitFlags::IMG_INIT_JPG) != 0)
		{
			LogError("Something went wrong while initializing the engine: %s\n", SDL_GetError());
			return false;
		}

		LogInfo("SDL initialized!");

		m_Window = SDL_CreateWindow("2D Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
		if(m_Window == nullptr)
		{
			LogError("Failed to create SDL Window: %s\n", SDL_GetError());
			return false;
		}

		LogInfo("SDL Window created successfully!");

		m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if(m_Renderer == nullptr)
		{
			LogError("Failed to create SDL Renderer: %s\n", SDL_GetError());
			return false;
		}

		LogInfo("SDL Renderer created successfully! Initializing game...");

		if(!graphics::TextureManager::GetInstance()->Load("player", "assets/player/adventurer_1.png"))
		{
			return false;
		}

		object::Properties props("player", 50, 100, 50, 37);
		m_player = new characters::PlayerCharacter(props);

		return m_IsRunning = true;
	}

	bool Engine::Clean()
	{
		m_player->Clean();
		delete m_player;

		graphics::TextureManager::GetInstance()->Clean();

		SDL_DestroyRenderer(m_Renderer);
		SDL_DestroyWindow(m_Window);

		IMG_Quit();
		SDL_Quit();

		if(s_Instance != nullptr)
		{
			delete s_Instance;
			s_Instance = nullptr;
		}

		LogInfo("Engine terminated!");

		return true;
	}

	void Engine::Quit()
	{
		m_IsRunning = false;
	}

	void Engine::Update()
	{
		float deltaTime = Time::GetInstance()->DeltaTime();
		m_player->Update(deltaTime);
	}

	void Engine::Render()
	{
		SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
		SDL_RenderClear(m_Renderer);

		m_player->Draw();

		SDL_RenderPresent(m_Renderer);
	}

	void Engine::Events()
	{
		input::InputHandler::GetInstance()->Listen();
	}
}