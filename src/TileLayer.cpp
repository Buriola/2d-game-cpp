#include "include/map/TileLayer.hpp"

Maps::TileLayer::TileLayer(int tileSize, int rowCount, int colCount, Tilemap tilemap, TilesetList tilesets)
{
	m_TileSize = tileSize;
	m_RowCount = rowCount;
	m_ColCount = colCount,
	m_Tilemap = tilemap;
	m_TilesetList = tilesets;
}

void Maps::TileLayer::Render()
{

}

void Maps::TileLayer::Update()
{

}