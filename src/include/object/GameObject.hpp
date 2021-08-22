#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "../core/Engine.hpp"
#include "IObject.hpp"
#include "../physics/Transform.hpp"
#include "../physics/Vector2.hpp"

namespace object
{
	struct Properties
	{
		Properties(std::string textureId, float x, float y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE)
		{
			X = x;
			Y = y;
			Width = width;
			Height = height;
			TextureId = textureId;
			Flip = flip;
		}

		std::string TextureId;
		int Width;
		int Height;
		float X;
		float Y;
		SDL_RendererFlip Flip;
	};

	class GameObject : public IObject
	{
	public:
		GameObject(Properties& props)
		{
			m_TextureId = props.TextureId;
			m_Width = props.Width;
			m_Height = props.Height;
			m_Flip = props.Flip;
			m_Transform = new physics::Transform(physics::Vector2(props.X, props.Y));
		}

		virtual void Draw() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Clean() = 0;

	protected:
		physics::Transform* m_Transform;
		int m_Width;
		int m_Height;
		std::string m_TextureId;
		SDL_RendererFlip m_Flip;
	};
}
#endif // GAME_OBJECT_HPP