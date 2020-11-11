#pragma once

#include <SDL2/SDL.h>
#include "core/Engine.hpp"

namespace Input
{
	class InputHandler
	{
	public:
		static InputHandler* GetInstance();

		void Listen();
		bool GetKeyDown(SDL_Scancode key);
	private:
		InputHandler();
		static InputHandler* s_Instance;

		void KeyUp();
		void KeyDown();

		const Uint8* m_KeyStates;
	};
}