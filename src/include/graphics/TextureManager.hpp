#pragma once

#include <iostream>
#include <string>
#include "SDL2/include/SDL.h"
#include "SDL2/include/SDL_image.h"
#include <map>

#include "../core/Engine.hpp"

namespace Graphics
{
	class TextureManager
	{
	public:
		static TextureManager* GetInstance();

		bool Load(std::string id, std::string filename);
		void Drop(std::string id);
		void Clean();

		void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void DrawFrame(std::string id, int x, int y, int width, int height, int row, int rowElementIndex, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);
	private:
		TextureManager(){};
		static TextureManager* s_Instance;

		std::map<std::string, SDL_Texture*> m_TextureMap;
	};
}