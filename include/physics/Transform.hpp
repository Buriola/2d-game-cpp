#pragma once

#include "physics/Vector2.hpp"

namespace Physics
{
	struct Transform
	{
	public:
		Transform(Vector2 position) : Position(position) {}
		Vector2 Position;
	
	private:
		inline void Translate(Vector2 newPosition) { Position += newPosition; }
	}
}