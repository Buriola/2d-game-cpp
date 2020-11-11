#pragma once

#include <SDL2/SDL.h>

const int TARGET_FPS = 60;
const float TARGET_DELTATIME = 1.5f;

namespace Core
{
	class Time
	{
	public:
		void Tick();
		inline float DeltaTime() { return m_DeltaTime; }
		inline static Time* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new Time(); }
	private:
		Time();
		static Time* s_Instance;
		float m_DeltaTime;
		float m_LastTime;
	};
}