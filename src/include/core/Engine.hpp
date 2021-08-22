#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include "SDL2/include/SDL.h"
#include "SDL2/include/SDL_image.h"

#ifndef GAME_RELEASE
	#include <stdio.h>
	#define LogMsg(prefix, msg, ...) do {printf("\n%s - ", prefix); printf(msg, __VA_ARGS__);} while(0)
	#define LogMsgAndFileLine(prefix, msg, ...) do {printf("\n%s - ", prefix); printf(msg, __VA_ARGS__); printf("@ %s:%d", __FILE__, __LINE__); } while(0)
	#define LogInfo(msg, ...) LogMsg("[INFO]", msg, __VA_ARGS__)
	#define LogWarning(msg, ...) LogMsgAndFileLine("[WARNING]", msg, __VA_ARGS__)
	#define LogError(msg, ...) LogMsgAndFileLine("[ERROR]", msg, __VA_ARGS__)
	#define ENGINE_ASSERT(condition, msg, ...) do{if (!(condition)) { LogMsgAndFileLine("[Assertion Failed]", msg, __VA_ARGS__); *((int*)0) = 0;} } while(0)
#else
    #define GAME_EMPTY_MACRO do{} while(0)
        #define LogMsg(prefix, msg, ...) GAME_EMPTY_MACRO
        #define LogInfo(msg, ...) GAME_EMPTY_MACRO
        #define LogMsgAndFileLine(prefix, msg, ...) GAME_EMPTY_MACRO
        #define LogInfo(msg, ...) GAME_EMPTY_MACRO
        #define LogWarning(msg, ...) GAME_EMPTY_MACRO
        #define LogError(msg, ...) GAME_EMPTY_MACRO
        #define ENGINE_ASSERT(condition, msg, ...) GAME_EMPTY_MACRO
#endif // NOT GAME RELEASE


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