#pragma once

namespace Physics
{
	class Vector2
	{
	public:
		Vector2(): X(0.0f), Y(0.0f) { }
		Vector2(float x, float y) : X(x), Y(y) {}
		
		float X;
		float Y;

		inline Vector2 operator+(const Vector2& otherVector) const
		{ 
			return Vector2(X + otherVector.X, Y + otherVector.Y); 
		}
		
		inline Vector2 operator-(const Vector2& otherVector) const
		{ 
			return Vector2(X - otherVector.X, Y - otherVector.Y); 
		}
		
		inline Vector2 operator*(const float scalar) const
		{ 
			return Vector2(X * scalar , Y * scalar); 
		}

	private:
		inline static Vector2& zero() 
		{ 
			static Vector2 _zero = Vector2();
			return _zero;
		}

	public:
		static const Vector2& Zero() { return zero(); }
	};
}