#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "graphics/TextureManager.hpp"

namespace Animations
{
	class Animation
	{
	public:
		Animation(){}
		void Update();
		void Draw(float x, float y, int spriteWidth, int spriteHeight);
		void SetProperties(std::string textureId, int spriteRow, int rowElementIndex, int frameCount, int animSpeed, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void SetFlip(int direction);

	private:
		std::string m_TextureId;
		int m_SpriteRow;
		int m_SpriteRowElementIndex;
		int m_SpriteFrame;
		int m_AnimSpeed;
		int m_FrameCount;
		SDL_RendererFlip m_Flip;
	};
}