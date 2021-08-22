#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "Vector2.hpp"

namespace physics
{
	struct Transform
	{
	public:
		Transform(Vector2 position) : Position(position) {}
		Vector2 Position;
		inline void Translate(Vector2 newPosition) { Position += newPosition; }
	};
}
#endif // TRANSFORM_HPP