#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../core/Engine.hpp"
#include "../object/GameObject.hpp"

namespace characters
{
	class Character : public object::GameObject 
	{
	public:
		Character(object::Properties& props) : object::GameObject(props) { }

		virtual void Draw() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Clean() = 0;

	protected:
		std::string m_Name;
	};
}
#endif // CHARACTER_HPP