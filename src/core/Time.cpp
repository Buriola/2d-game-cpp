#include "core/Time.hpp"

Core::Time* Core::Time::s_Instance = nullptr; 

Core::Time::Time()
{

}

void Core::Time::Tick()
{
	m_DeltaTime = (SDL_GetTicks() - m_LastTime) * (TARGET_FPS * 0.001f);

	if(m_DeltaTime > TARGET_DELTATIME)
		m_DeltaTime = TARGET_DELTATIME;

	m_LastTime = SDL_GetTicks();
}