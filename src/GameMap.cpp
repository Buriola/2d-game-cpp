#include "include/map/GameMap.hpp"

namespace maps 
{
	void GameMap::Render()
	{
		for(unsigned int i = 0; i < m_MapLayers.size(); i++)
		{
			m_MapLayers[i]->Render();
		}
	}

	void GameMap::Update()
	{
		for(unsigned int i = 0; i < m_MapLayers.size(); i++)
		{
			m_MapLayers[i]->Update();
		}
	}
}