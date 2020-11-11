#include "characters/PlayerCharacter.hpp"

Characters::PlayerCharacter::PlayerCharacter(Object::Properties* props) : Characters::Character(props)
{
	m_Animation = new Animations::Animation();
	m_Animation->SetProperties(m_TextureId, 0, 4, 120, SDL_FLIP_HORIZONTAL);
}

void Characters::PlayerCharacter::Draw()
{
	m_Animation->Draw(m_Transform->Position.X, m_Transform->Position.Y, m_Width, m_Height);
}

void Characters::PlayerCharacter::Update(float delta)
{
	m_Animation->Update();
}

void Characters::PlayerCharacter::Clean()
{
	Graphics::TextureManager::GetInstance()->Drop(m_TextureId);
}