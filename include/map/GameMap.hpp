#pragma once

#include <vector>
#include "Layer.hpp"

namespace Maps
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