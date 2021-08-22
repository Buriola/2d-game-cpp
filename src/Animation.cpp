#include "include/animations/Animation.hpp"
#include "include/graphics/TextureManager.hpp"

namespace animations 
{
	void Animation::Update()
	{
		m_SpriteFrame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount;
	}
			
	void Animation::Draw(float x, float y, int spriteWidth, int spriteHeight)
	{
		graphics::TextureManager::GetInstance()->DrawFrame(m_TextureId, (int)x, (int)y, spriteWidth, spriteHeight, m_SpriteRow, m_SpriteRowElementIndex, m_SpriteFrame, m_Flip);
	}

	void Animation::SetProperties(std::string textureId, int spriteRow, int rowElementIndex, int frameCount, int animSpeed, SDL_RendererFlip flip)
	{
		m_TextureId = textureId;
		m_SpriteRow = spriteRow;
		m_SpriteRowElementIndex = rowElementIndex;
		m_FrameCount = frameCount;
		m_AnimSpeed = animSpeed;
		m_Flip = flip;
	}

	void Animation::SetFlip(int direction)
	{
		m_Flip = direction == -1 ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
	}
}