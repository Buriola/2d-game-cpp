#pragma once
#include "SDL2/include/SDL.h"
#include "SDL2/include/SDL_image.h"
#include <iostream>

#include "Time.hpp"
#include "../graphics/TextureManager.hpp"
#include "../characters/PlayerCharacter.hpp"
#include "../input/InputHandler.hpp"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

namespace Characters { class PlayerCharacter; }

namespace Core
{
	class Engine
	{
	public:
		static Engine* GetInstance();
		bool Init();
		bool Clean();
		void Quit();

		void Update();
		void Render();
		void Events();

		inline bool IsRunning() { return m_IsRunning; }
		inline SDL_Renderer* GetRenderer() { return m_Renderer; }
	private:
		Engine();
		static Engine* s_Instance;

		bool m_IsRunning;
		SDL_Window* m_Window;
		SDL_Renderer* m_Renderer;

		Characters::PlayerCharacter* m_player;
	};
}