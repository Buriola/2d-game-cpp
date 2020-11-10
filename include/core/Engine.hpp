#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH  960
#define SCREEN_HEIGHT 640

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