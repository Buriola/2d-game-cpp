#pragma once

#include "SDL2/include/SDL.h"
#include "Character.hpp"
#include "../graphics/TextureManager.hpp"
#include "../animations/Animation.hpp"
#include "../physics/Rigidbody2D.hpp"
#include "../input/InputHandler.hpp"

namespace Animations { class Animation; }

namespace Characters
{
	class PlayerCharacter : public Character
	{
	public:
		PlayerCharacter(Object::Properties* props);
		
		virtual void Draw();
		virtual void Update(float deltaTime);
		virtual void Clean();
	private:
		Animations::Animation* m_Animation;
		Physics::Rigidbody2D* m_Rigidbody;
		int m_DirectionX;

		void GetInputs();
		void Movement(int direction);
	};
}