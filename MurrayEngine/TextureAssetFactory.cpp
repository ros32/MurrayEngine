#include "TextureAssetFactory.h"

TextureAssetFactory::TextureAssetFactory() : AssetFactory()
{

}

TextureAssetFactory::TextureAssetFactory(SDL_Renderer* renderer) : AssetFactory()
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

Asset	TextureAssetFactory::createAsset(Configuration configuration)
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
	if (filePath != "UNKNOWN" && name != "UNKNOWN")
	{
		TextureAsset returnAsset = TextureAsset(this->instanceRenderer, filePath.c_str(), cellSize, offset, color);
		return returnAsset;
		//	Create texture name mapping from config
	}
	return InvalidAsset();
}