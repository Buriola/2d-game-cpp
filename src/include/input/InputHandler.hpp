#ifndef GAME_INPUT_HPP
#define GAME_INPUT_HPP

#include "../core/Engine.hpp"

namespace input
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
#endif //GAME_INPUT_HPP