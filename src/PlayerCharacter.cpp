#include "include/characters/PlayerCharacter.hpp"
#include "include/input/InputHandler.hpp"
#include "include/graphics/TextureManager.hpp"

namespace characters 
{
	PlayerCharacter::PlayerCharacter(object::Properties* props) : Character(props)
	{
		m_DirectionX = 1;

		m_Animation = new animations::Animation();
		m_Animation->SetProperties(m_TextureId, 0, 0, 4, 100);

		m_Rigidbody = new physics::Rigidbody2D();
	}

	void PlayerCharacter::Draw()
	{
		m_Animation->Draw(m_Transform->Position.X, m_Transform->Position.Y, m_Width, m_Height);
	}

	void PlayerCharacter::Update(float delta)
	{
		m_Animation->SetProperties(m_TextureId, 0, 0, 4, 100);
		m_Animation->SetFlip(m_DirectionX);
		m_Rigidbody->ResetForce();

		GetInputs();

		m_Animation->Update();
		m_Rigidbody->Update(delta);

		m_Transform->Translate(m_Rigidbody->GetPosition());
	}

	void PlayerCharacter::GetInputs()
	{
		bool leftInput = input::InputHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_A);
		bool rightInput = input::InputHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_D);

		if(leftInput || rightInput)
		{
			m_DirectionX = leftInput ? -1 : 1;
			Movement(m_DirectionX);
		}
	}

	void PlayerCharacter::Movement(int direction)
	{
		m_Animation->SetProperties(m_TextureId, 1, 0, 6, 120);
		m_Animation->SetFlip(direction);

		m_Rigidbody->AddForceX((float)2 * direction);
	}

	void PlayerCharacter::Clean()
	{
		graphics::TextureManager::GetInstance()->Drop(m_TextureId);
	}
}