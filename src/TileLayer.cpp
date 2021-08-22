#include "include/map/TileLayer.hpp"

namespace maps 
{
	TileLayer::TileLayer(int tileSize, int rowCount, int colCount, Tilemap tilemap, TilesetList tilesets)
	{
		m_TileSize = tileSize;
		m_RowCount = rowCount;
		m_ColCount = colCount,
		m_Tilemap = tilemap;
		m_TilesetList = tilesets;
	}

	void TileLayer::Render()
	{

	}

	void TileLayer::Update()
	{

	}
}