#include "characters/PlayerCharacter.hpp"


Characters::PlayerCharacter::PlayerCharacter(Object::Properties* props) : Characters::Character(props)
{
	m_Row = 0;
	m_FrameCount = 4;
	m_AnimSpeed = 120;
}

void Characters::PlayerCharacter::Draw()
{
	Graphics::TextureManager::GetInstance()->DrawFrame(m_TextureId, m_Transform->Position.X, m_Transform->Position.Y, m_Width, m_Height, m_Row, m_Frame);
}

void Characters::PlayerCharacter::Update(float delta)
{
	m_Frame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount;
}

void Characters::PlayerCharacter::Clean()
{
	Graphics::TextureManager::GetInstance()->Drop(m_TextureId);
}