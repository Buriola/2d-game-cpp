#include "include/map/GameMap.hpp"

void Maps::GameMap::Render()
{
	for(unsigned int i = 0; i < m_MapLayers.size(); i++)
	{
		m_MapLayers[i]->Render();
	}
}

void Maps::GameMap::Update()
{
	for(unsigned int i = 0; i < m_MapLayers.size(); i++)
	{
		m_MapLayers[i]->Update();
	}
}