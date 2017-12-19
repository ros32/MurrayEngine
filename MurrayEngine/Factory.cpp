#include	"Factory.h"

Factory::Factory()
{
	this->window = nullptr;
	this->renderer = nullptr;
	this->gameInstance = nullptr;
}
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


Map*				Factory::createMap(Configuration configuration)
{
	const auto cellSize = configuration.getProperty("CELL_SIZE", 32);
	std::vector<Tile*> tiles;
//	std::vector<Tile> tileMap;
	auto map = new Map(this->window, this->renderer);
	map->setTileSize(cellSize);
	// bool	keyIdentified = false;
	for (auto key : configuration)
	{
		const auto found = key.first.find("TILE_");
		if (found != std::string::npos)
		{
			auto collidable = false;
			auto passable = true;
			const auto posX = atoi(key.first.substr(5, 2).c_str());
			const auto posY = atoi(key.first.substr(8, 2).c_str());
			const std::string type = key.first.substr(11, 1).c_str();
			switch (type.at(0))
			{
			case 'W':
				collidable = true;
				passable = false;
				break;
			case 'F':
				collidable = false;
				passable = true;
				break;
			case 'I':
				collidable = true;
				passable = true;
				break;
			default:
				collidable = false;
				passable = true;
				break;
			}
			const Position	pos = { posX * (cellSize), posY * (cellSize) };
			std::basic_stringstream<char> ss(key.second);
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
			{
				const auto texture2 = std::make_shared<Texture>(gameInstance->getTextureAsset(tileset), texture);
				auto tempTile = new Tile(pos, texture2, NORTH, collidable, passable);
				tiles.push_back(tempTile);
			}
		}
	}

	map->setTiles(tiles);

	return map;
}

TextureAsset*	Factory::createAsset(Configuration configuration)
{
	auto filePath = configuration.getProperty("PATH", "UNKNOWN");
	const unsigned int	cellSize = configuration.getProperty("CELL_SIZE", 32);
	const unsigned int	offset = configuration.getProperty("OFFSET", 0);
	const SDL_Color	color =
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
		const auto found = key.first.find("TEXTURE_");
		if (found != std::string::npos)
		{
			const auto posX = atoi(key.first.substr(8, 2).c_str());
			const auto posY = atoi(key.first.substr(11, 2).c_str());
			Position	pos = { posX, posY };
			nameIndex.insert(std::map<std::string, Position>::value_type(key.second, pos));
		}
	}
	returnAsset->setTextureNameIndex(nameIndex);
	return returnAsset;
}

KeyController*	Factory::createKeyController(Configuration configuration)
{
	//	Error reading configuration, return empty controller
	if (configuration.getProperty("NAME", "UNKNOWN") == "UNKNOWN")
	{
		return new KeyController();
	}

	return new KeyController();

}

GameInstance*	Factory::getGameInstance() const
{
	return this->gameInstance;
}

SDL_Window*		Factory::getWindow() const
{
	return this->window;
}

