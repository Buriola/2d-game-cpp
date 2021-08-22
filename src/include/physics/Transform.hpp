#pragma once

#include "Vector2.hpp"

namespace Physics
{
	struct Transform
	{
	public:
		Transform(Vector2 position) : Position(position) {}
		Vector2 Position;
		inline void Translate(Vector2 newPosition) { Position += newPosition; }
	};
}