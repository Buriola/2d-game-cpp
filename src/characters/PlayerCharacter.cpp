#include "characters/PlayerCharacter.hpp"

Characters::PlayerCharacter::PlayerCharacter(Object::Properties* props) : Characters::Character(props)
{
	m_Animation = new Animations::Animation();
	m_Animation->SetProperties(m_TextureId, 0, 4, 120, SDL_FLIP_HORIZONTAL);

	m_Rigidbody = new Physics::Rigidbody2D();
}

void Characters::PlayerCharacter::Draw()
{
	m_Animation->Draw(m_Transform->Position.X, m_Transform->Position.Y, m_Width, m_Height);
}

void Characters::PlayerCharacter::Update(float delta)
{
	m_Animation->Update();
	m_Rigidbody->Update(0.2);

	m_Transform->Translate(m_Rigidbody->GetPosition());
}

void Characters::PlayerCharacter::Clean()
{
	Graphics::TextureManager::GetInstance()->Drop(m_TextureId);
}