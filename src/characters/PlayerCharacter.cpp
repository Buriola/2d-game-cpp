#include "characters/PlayerCharacter.hpp"

Characters::PlayerCharacter::PlayerCharacter(Object::Properties* props) : Characters::Character(props)
{
	m_DirectionX = 1;

	m_Animation = new Animations::Animation();
	m_Animation->SetProperties(m_TextureId, 0, 0, 4, 100);

	m_Rigidbody = new Physics::Rigidbody2D();
}

void Characters::PlayerCharacter::Draw()
{
	m_Animation->Draw(m_Transform->Position.X, m_Transform->Position.Y, m_Width, m_Height);
}

void Characters::PlayerCharacter::Update(float delta)
{
	m_Animation->SetProperties(m_TextureId, 0, 0, 4, 100);
	m_Animation->SetFlip(m_DirectionX);
	m_Rigidbody->ResetForce();

	GetInputs();

	m_Animation->Update();
	m_Rigidbody->Update(0.2);

	m_Transform->Translate(m_Rigidbody->GetPosition());
}

void Characters::PlayerCharacter::GetInputs()
{
	bool leftInput = Input::InputHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_A);
	bool rightInput = Input::InputHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_D);

	if(leftInput || rightInput)
	{
		m_DirectionX = leftInput ? -1 : 1;
		Movement(m_DirectionX);
	}
}

void Characters::PlayerCharacter::Movement(int direction)
{
	m_Animation->SetProperties(m_TextureId, 1, 0, 6, 120);
	m_Animation->SetFlip(direction);

	m_Rigidbody->AddForceX(30 * direction);
}

void Characters::PlayerCharacter::Clean()
{
	Graphics::TextureManager::GetInstance()->Drop(m_TextureId);
}