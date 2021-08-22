#ifndef GAME_PLAYER_CHARACTER_HPP
#define GAME_PLAYER_CHARACTER_HPP

#include "Character.hpp"
#include "../core/Engine.hpp"
#include "../animations/Animation.hpp"
#include "../physics/Rigidbody2D.hpp"

namespace characters
{
	class PlayerCharacter : public Character
	{
	public:
		PlayerCharacter(object::Properties* props);
		
		virtual void Draw() override;
		virtual void Update(float deltaTime) override;
		virtual void Clean() override;
	private:
		animations::Animation* m_Animation;
		physics::Rigidbody2D* m_Rigidbody;
		int m_DirectionX;

		void GetInputs();
		void Movement(int direction);
	};
}
#endif // GAME_PLAYER_CHARACTER_HPP