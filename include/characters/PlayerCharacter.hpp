#pragma once

#include <SDL2/SDL.h>
#include "Character.hpp"
#include "graphics/TextureManager.hpp"
#include "animations/Animation.hpp"
#include "physics/Rigidbody2D.hpp"

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
	};
}