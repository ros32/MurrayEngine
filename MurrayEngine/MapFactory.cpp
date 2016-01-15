#include "MapFactory.h"

MapFactory::MapFactory()
{

}

MapFactory::MapFactory(SDL_Window* window, SDL_Renderer* renderer, GameInstance* gameInstance)
{
	this->window = window;
	this->renderer = renderer;
	this->gameInstance = gameInstance;
}

MapFactory::~MapFactory()
{

}

Map*	MapFactory::createMap(Configuration configuration)
{/*
	int cellSize = configuration.getProperty("CELL_SIZE", 32);
	std::vector<std::vector<Tile>> tiles;
	std::vector<Tile> tileMap;
	Map* map = new Map(this->window, this->renderer);
	map->setTileSize(cellSize);
	// bool	keyIdentified = false;
	for (auto key : configuration)
	{
		std::size_t found = key.first.find("TILE_");
		if (found != std::string::npos)
		{
			int posX = atoi(key.first.substr(5, 2).c_str());
			int posY = atoi(key.first.substr(8, 2).c_str());
			Position	pos = { posX * (cellSize), posY * (cellSize)};
			std::stringstream ss(key.second);
			std::string segment;
			std::vector<std::string> splitString;
			std::string tileset;
			std::string texture;

			while (std::getline(ss, segment, '.'))
			{
				splitString.push_back(segment);
			}

			if (splitString.size() >= 2)
			{
				tileset = splitString[0];
				texture = splitString[1];
			}
			else
			{

			}
			if (gameInstance != nullptr)
				tileMap.push_back(Tile(pos, Texture(gameInstance->getTextureAsset(tileset), texture), NORTH));
		}
	}

	while (tileMap.size() != 0)
	{
		Tile key = tileMap.back();
		tileMap.pop_back();
		int posX = (key.getCurrentPosition().x / 32);
		int posY = (key.getCurrentPosition().y / 32);

		if (posX < 0)
			posX = 0;
		if (posY < 0)
			posY = 0;

		size_t i = (size_t)posX;
		size_t j = (size_t)posY;

		if (tiles.size() < i +1)
		{
			tiles.resize(i +1);
			tiles[i] = std::vector<Tile>();
		}
		if (tiles[i].size() < j +1)
		{
			tiles[i].resize(j +1);
		}

		tiles[i][j] = key;
	}

	map->setTiles(tiles);

	return map;*/
	return new Map();
}