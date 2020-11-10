#pragma once

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

	private:
		Engine();
		bool m_IsRunning;
		static Engine* s_Instance;
	};
}