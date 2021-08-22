#ifndef GAME_TILELAYER_HPP
#define GAME_TILELAYER_HPP

#include "../core/Engine.hpp"
#include "Layer.hpp"

namespace maps
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

	using TilesetList = std::vector<Tileset>;
	using Tilemap = std::vector<std::vector<int>>;

	class TileLayer : public Layer
	{
	public:
		TileLayer(int tileSize, int rowCount, int colCount, Tilemap tilemap, TilesetList tilesets);
		virtual void Render() override;
		virtual void Update() override;

		inline Tilemap GetTilemap() { return m_Tilemap; }

	private:
		int m_TileSize;
		int m_RowCount;
		int m_ColCount;
		Tilemap m_Tilemap;
		TilesetList m_TilesetList;
	};
}
#endif // GAME_TILELAYER_HPP