#ifndef VECTOR2_HPP
#define VECTOR2_HPP

namespace physics
{
	struct Vector2
	{
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

		inline Vector2& operator+=(const Vector2& otherVector)
		{
			this->X += otherVector.X;
			this->Y += otherVector.Y;

			return *this;
		}

		inline void Set(float x, float y) 
		{
			X = x;
			Y = y;
		}

		inline void Set(Vector2 newValue)
		{
			X = newValue.X;
			Y = newValue.Y;
		}

		static const Vector2& Zero() { return zero(); }
		
	private:
		inline static Vector2& zero() 
		{ 
			static Vector2 _zero = Vector2();
			return _zero;
		}
	};
}
#endif //VECTOR2_HPP