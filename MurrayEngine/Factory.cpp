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

std::shared_ptr<Animation> Factory::createAnimation(Configuration configuration)
{
	unsigned int time = configuration.getProperty("TIME", 200);
	std::map < std::string, std::vector<std::string, std::string>> returnMap;

	for (auto key : configuration)
	{
		std::size_t found = key.first.find("IMAGE_");
		if (found != std::string::npos)
		{
			//std::string
		}
	}

	return nullptr;
}

//	FIXME
Object*		Factory::createObject(Configuration configuration)	
{ 
	return nullptr;
}

Map*				Factory::createMap(Configuration configuration)
{
	int cellSize = configuration.getProperty("CELL_SIZE", 32);
	std::vector<Tile*> tiles;
//	std::vector<Tile> tileMap;
	Map* map = new Map(this->window, this->renderer);
	map->setTileSize(cellSize);
	// bool	keyIdentified = false;
	for (auto key : configuration)
	{
		std::size_t found = key.first.find("TILE_");
		if (found != std::string::npos)
		{
			bool collidable = false;
			bool passable = true;
			int posX = atoi(key.first.substr(5, 2).c_str());
			int posY = atoi(key.first.substr(8, 2).c_str());
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
			Position	pos = { posX * (cellSize), posY * (cellSize) };
			std::stringstream ss(key.second);
			std::string segment;
			//std::vector<std::string> splitString;
			std::string tileset;
			std::string texture;

			while (std::getline(ss, segment, '.'))
			{
				//splitString.push_back(segment);
			}

			/*if (splitString.size() >= 2)
			{
				tileset = splitString[0];
				texture = splitString[1];
			}
			else
			{

			}*/
			tileset = "tileset";
			texture = "CobbleStoneM";

			if (gameInstance != nullptr)
			{
				auto texture2 = std::make_shared<Texture>(gameInstance->getTextureAsset(tileset), texture);
				Tile*	tempTile = new Tile(pos, texture2, NORTH, collidable, passable);
				tiles.push_back(tempTile);
			}
		}
	}

	/*while (tileMap.size() != 0)
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
	}*/

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

KeyController*	Factory::createKeyController(Configuration configuration)
{
	//	Error reading configuration, return empty controller
	if (configuration.getProperty("NAME", "UNKNOWN") == "UNKNOWN")
	{
		return new KeyController();

		std::string output = "Invalid configuration file for key controller. Returning empty key controller.";
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, output.c_str());
	}

	return new KeyController();

}

GameInstance*	Factory::getGameInstance()
{
	return this->gameInstance;
}

SDL_Window*		Factory::getWindow()
{
	return this->window;
}