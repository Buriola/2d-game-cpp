#include "include/input/InputHandler.hpp"

Input::InputHandler* Input::InputHandler::s_Instance = nullptr;

Input::InputHandler* Input::InputHandler::GetInstance() 
{ 
	return s_Instance = (s_Instance != nullptr) ? s_Instance : new InputHandler(); 
}

Input::InputHandler::InputHandler()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void Input::InputHandler::Listen() 
{
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT: 
				Core::Engine::GetInstance()->Quit();
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

bool Input::InputHandler::GetKeyDown(SDL_Scancode key) 
{
	return m_KeyStates[key] == 1;
}

void Input::InputHandler::KeyUp() 
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void Input::InputHandler::KeyDown()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}