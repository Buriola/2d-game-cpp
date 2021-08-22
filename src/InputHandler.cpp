#include "include/input/InputHandler.hpp"

namespace input 
{
	InputHandler* InputHandler::s_Instance = nullptr;

	InputHandler* InputHandler::GetInstance() 
	{ 
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new InputHandler(); 
	}

	InputHandler::InputHandler()
	{
		m_KeyStates = SDL_GetKeyboardState(nullptr);
	}

	void InputHandler::Listen() 
	{
		SDL_Event event;

		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT: 
					core::Engine::GetInstance()->Quit();
					break;
				case SDL_KEYDOWN:
					KeyDown();
					break;
				case SDL_KEYUP:
					KeyUp();
					break;
			}
		}
	}

	bool InputHandler::GetKeyDown(SDL_Scancode key) 
	{
		return m_KeyStates[key] == 1;
	}

	void InputHandler::KeyUp() 
	{
		m_KeyStates = SDL_GetKeyboardState(nullptr);
	}

	void InputHandler::KeyDown()
	{
		m_KeyStates = SDL_GetKeyboardState(nullptr);
	}
}