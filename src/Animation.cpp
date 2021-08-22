#include "include/animations/Animation.hpp"

void Animations::Animation::Update()
{
	m_SpriteFrame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount;
}
		
void Animations::Animation::Draw(float x, float y, int spriteWidth, int spriteHeight)
{
	Graphics::TextureManager::GetInstance()->DrawFrame(m_TextureId, (int)x, (int)y, spriteWidth, spriteHeight, m_SpriteRow, m_SpriteRowElementIndex, m_SpriteFrame, m_Flip);
}

void Animations::Animation::SetProperties(std::string textureId, int spriteRow, int rowElementIndex, int frameCount, int animSpeed, SDL_RendererFlip flip)
{
	m_TextureId = textureId;
	m_SpriteRow = spriteRow;
	m_SpriteRowElementIndex = rowElementIndex;
	m_FrameCount = frameCount;
	m_AnimSpeed = animSpeed;
	m_Flip = flip;
}

void Animations::Animation::SetFlip(int direction)
{
	m_Flip = direction == -1 ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
}