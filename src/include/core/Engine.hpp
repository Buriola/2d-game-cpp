#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include "SDL2/include/SDL.h"
#include "SDL2/include/SDL_image.h"

#include <string>
#include <iostream>
#include <map>
#include <vector>

namespace characters { class PlayerCharacter; }

namespace core
{
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;

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

		class characters::PlayerCharacter* m_player;
	};
}

#endif //GAME_ENGINE_HPP