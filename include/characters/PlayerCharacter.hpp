#pragma once

#include <SDL2/SDL.h>

#include "Character.hpp"
#include "graphics/TextureManager.hpp"

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
		int m_Row;
		int m_Frame;
		int m_FrameCount;
		int m_AnimSpeed;
	};
}