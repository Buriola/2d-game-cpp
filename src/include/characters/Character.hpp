#pragma once

#include "../object/GameObject.hpp"
#include <string>

namespace Characters
{
	class Character : public Object::GameObject 
	{
	public:
		Character(Object::Properties* props) : Object::GameObject(props) { }

		virtual void Draw() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Clean() = 0;

	protected:
		std::string m_Name;
	};
}