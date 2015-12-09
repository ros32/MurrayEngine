#include "TextureAssetFactory.h"

TextureAssetFactory::TextureAssetFactory()
{

}

TextureAssetFactory::TextureAssetFactory(SDL_Renderer* renderer)
{
	this->instanceRenderer = renderer;
}

TextureAssetFactory::~TextureAssetFactory()
{

}

void	TextureAssetFactory::setRenderer(SDL_Renderer* renderer)
{
	this->instanceRenderer = renderer;
}

TextureAsset	TextureAssetFactory::createAsset(Configuration configuration)
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

	TextureAsset returnAsset = TextureAsset(this->instanceRenderer, filePath.c_str(), cellSize, offset, color);

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
	returnAsset.setTextureNameIndex(nameIndex);
	return returnAsset;
}