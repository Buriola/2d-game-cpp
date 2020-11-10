#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "graphics/TextureManager.hpp"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

namespace Core
{
	class Engine
	{
	public:
		static Engine* GetInstance();
		bool Init();
		bool Clean();
		void Quit();

		void Update(float deltaTime);
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
	};
}