#include "include/core/Time.hpp"

namespace core 
{
	Time* Time::s_Instance = nullptr; 

	Time::Time() {}

	void Time::Tick()
	{
		m_DeltaTime = (float)(SDL_GetTicks() - m_LastTime) * (TARGET_FPS * 0.001f);

		if(m_DeltaTime > TARGET_DELTATIME)
			m_DeltaTime = TARGET_DELTATIME;

		m_LastTime = (float)SDL_GetTicks();
	}
}