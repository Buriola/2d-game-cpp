#pragma once

#include <vector>
#include <string>
#include "Layer.hpp"

namespace Maps
{
	struct Tileset
	{
		int First;
		int LastId;
		int NumberRows;
		int NumberCols;
		int TileCount;
		int TileSize;
		std::string Name;
		std::string Source;
	};

	using TilesetList = std::vector<Maps::Tileset>;
	using Tilemap = std::vector<std::vector<int>>;

	class TileLayer : public Layer
	{
	public:
		TileLayer(int tileSize, int rowCount, int colCount, Tilemap tilemap, TilesetList tilesets);
		virtual void Render();
		virtual void Update();

		inline Tilemap GetTilemap() { return m_Tilemap; }

	private:
		int m_TileSize;
		int m_RowCount;
		int m_ColCount;
		Tilemap m_Tilemap;
		TilesetList m_TilesetList;
	};
}