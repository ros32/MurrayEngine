#include	"Factory.h"

Factory::Factory() { }
Factory::~Factory()	{ }

void	Factory::setWindow(SDL_Window* window)
{
	this->window = window;
	this->renderer = SDL_GetRenderer(window);
}

void	Factory::setGameInstance(GameInstance*	instance)
{
	this->gameInstance = instance;
}

//	FIXME
GenericObject*		Factory::createObject(Configuration configuration)	{ return nullptr; }

Map*				Factory::createMap(Configuration configuration)
{
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
			Position	pos = { posX * (cellSize), posY * (cellSize) };
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

		if (tiles.size() < i + 1)
		{
			tiles.resize(i + 1);
			tiles[i] = std::vector<Tile>();
		}
		if (tiles[i].size() < j + 1)
		{
			tiles[i].resize(j + 1);
		}

		tiles[i][j] = key;
	}

	map->setTiles(tiles);

	return map;
}

TextureAsset*	Factory::createAsset(Configuration configuration)
{

	std::string name = configuration.getProperty("NAME", "UNKNOWN");
	std::string filePath = configuration.getProperty("PATH", "UNKNOWN");
	unsigned int	cellSize = configuration.getProperty("CELL_SIZE", 32);
	unsigned int	offset = configuration.getProperty("OFFSET", 0);
	SDL_Color	color =
	{
		configuration.getProperty("COLOR_R", 255),
		configuration.getProperty("COLOR_G", 255),
		configuration.getProperty("COLOR_B", 255)
	};

	TextureAsset* returnAsset = new TextureAsset(this->renderer, filePath.c_str(), cellSize, offset, color);

	//	Create texture name mapping from config

	std::map<std::string, Position>	nameIndex;

	for (auto key : configuration)
	{
		// bool	keyIdentified = false;
		std::size_t found = key.first.find("TEXTURE_");
		if (found != std::string::npos)
		{
			int posX = atoi(key.first.substr(8, 2).c_str());
			int posY = atoi(key.first.substr(11, 2).c_str());
			Position	pos = { posX, posY };
			nameIndex.insert(std::map<std::string, Position>::value_type(key.second, pos));
		}
	}
	returnAsset->setTextureNameIndex(nameIndex);
	return returnAsset;
}