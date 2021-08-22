#ifndef GAME_TIME_HPP
#define GAME_TIME_HPP

#include "../core/Engine.hpp"

namespace core
{
	static const int TARGET_FPS = 60;
	static const float TARGET_DELTATIME = 1.5f;

	class Time
	{
	public:
		void Tick();
		inline float DeltaTime() { return m_DeltaTime; }
		inline static Time* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new Time(); }
		static void DestroyInstance();
	private:
		Time();
		static Time* s_Instance;
		float m_DeltaTime;
		float m_LastTime;
	};
}

#endif // GAME_TIME_HPP