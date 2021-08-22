#ifndef RIGIDBODY2D_HPP
#define RIGIDBODY2D_HPP

#include "Vector2.hpp"

namespace physics
{
	static const float UNI_MASS = 1.0f;
	static const float GRAVITY = 9.81f; //Negative Y is up.

	class Rigidbody2D
	{
	public:
		Rigidbody2D()
		{
			m_Mass = UNI_MASS;
			m_Gravity = GRAVITY;
		}

		inline void SetMass(float mass) { m_Mass = mass; }
		inline void SetGravity(float gravity) { m_Gravity = gravity; }

		inline void AddForce(Vector2 force) { m_Force = force; }
		inline void AddForceX(float forceX) { m_Force.X = forceX; }
		inline void AddForceY(float forceY) { m_Force.Y = forceY; }
		inline void ResetForce() { m_Force = Vector2::Zero(); }

		inline void AddFriction(Vector2 friction) { m_Friction = friction; }
		inline void ResetFriction() { m_Friction = Vector2::Zero(); }

		inline float GetMass(){ return m_Mass; }
		inline Vector2 GetPosition() { return m_Position; }
		inline Vector2 GetAcceleration() { return m_Acceleration; }
		inline Vector2 GetVelocity() { return m_Velocity; }

		void Update(float deltaTime) 
		{
			m_Acceleration.X = (m_Force.X + m_Friction.X) / m_Mass;
			//m_Acceleration.Y = (m_Gravity + m_Force.Y) / m_Mass;

			m_Velocity = m_Acceleration * deltaTime;
			m_Position = m_Velocity * deltaTime;
		}

	private:
		float m_Mass;
		float m_Gravity;

		Vector2 m_Position;
		Vector2 m_Velocity;
		Vector2 m_Acceleration;
		Vector2 m_Force;
		Vector2 m_Friction;
	};
}
#endif // RIGIDBODY2D_HPP