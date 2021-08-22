#ifndef GAME_MAP_HPP
#define GAME_MAP_HPP

#include "../core/Engine.hpp"
#include "Layer.hpp"

namespace maps
{
	class GameMap
	{
	public:
		void Render();
		void Update();
		inline std::vector<Layer*> GetMapLayers() { return m_MapLayers; }
	private:
		std::vector<Layer*> m_MapLayers;
	};
}
#endif // GAME_MAP_HPP