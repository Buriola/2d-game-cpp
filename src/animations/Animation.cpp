#include "animations/Animation.hpp"

void Animations::Animation::Update()
{
	m_SpriteFrame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount;
}
		
void Animations::Animation::Draw(float x, float y, int spriteWidth, int spriteHeight)
{
	Graphics::TextureManager::GetInstance()->DrawFrame(m_TextureId, x, y, spriteWidth, spriteHeight, m_SpriteRow, m_SpriteFrame, m_Flip);
}

void Animations::Animation::SetProperties(std::string textureId, int spriteRow, int frameCount, int animSpeed, SDL_RendererFlip flip)
{
	m_TextureId = textureId;
	m_SpriteRow = spriteRow;
	m_FrameCount = frameCount;
	m_AnimSpeed = animSpeed;
	m_Flip = flip;
}