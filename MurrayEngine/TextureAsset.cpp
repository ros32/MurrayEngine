#include "TextureAsset.h"

TextureAsset::TextureAsset(SDL_Renderer* renderer, const char* filePath, unsigned int cellSize, unsigned int offset, SDL_Color colorKey)
{
	this->renderer	= renderer;
	this->filePath	= filePath;
	this->cellSize	= cellSize;
	this->offset	= offset;
	this->colorKey	= colorKey;
	this->load();
	this->index;
	this->generateIndex();
	this->nameIndex;
}

TextureAsset::~TextureAsset()
{
	this->unload();
}

void			TextureAsset::load()
{
	this->texture = IMG_LoadTexture(this->renderer, this->filePath);
	if (this->texture == nullptr)
		SDL_Log(SDL_GetError());
}

void			TextureAsset::unload()
{
	SDL_DestroyTexture(texture);
}

SDL_Texture*	TextureAsset::getTexture()
{
	return this->texture;
}

void			TextureAsset::generateIndex()
{
	int sizeX = 0;
	int sizeY = 0;
	int posX = 0;
	int posY = 0;
	int offsetX = this->offset;
	int offsetY = this->offset;
	int i = 0;

	SDL_QueryTexture(this->texture, NULL, NULL, &sizeX, &sizeY);
	do
	{
		posY = 0;
		std::vector<SDL_Rect> tempVector;
		this->index.push_back(tempVector);
		do
		{
			//	int j = 0;
			SDL_Rect tempRect = { (posX + this->offset), (posY + this->offset), this->cellSize, this->cellSize };
			this->index[i].push_back(tempRect);
			posY += (this->cellSize + offsetY);
			//	j++;
		} while (sizeY - (posY + (this->cellSize + offsetY)) >= 0);
		posX += (this->cellSize + offsetX);
		i++;
	} while (sizeX - (posX + (this->cellSize + offsetX)) >= 0);
	std::string tempXString = "Max X:" + std::to_string(index.size());
	std::string tempYString = "Max Y:" + std::to_string(index[0].size());
	SDL_Log(tempXString.c_str());
	SDL_Log(tempYString.c_str());

}

SDL_Rect*		TextureAsset::getSourceRect(unsigned int x, unsigned int y)
{
	size_t sizeX = 0;
	size_t sizeY = 0;
	if (x >= 0)
		sizeX = (size_t)x;
	if (y >= 0)
		sizeY = (size_t)y;

	if (this->index.size() >  sizeX)
	{
		if (this->index[x].size() > sizeY)
		{
			return &index[x][y];
		}
	}
	return &index[0][0];
}

SDL_Rect*	TextureAsset::getSourceRect(std::string name)
{
	std::map<std::string, Position>::iterator iterator;
	iterator = this->nameIndex.find(name);

	if (iterator != this->nameIndex.end())
		return this->getSourceRect(iterator->second.x, iterator->second.y);
	else
		return this->getSourceRect(0, 0);
}

void		TextureAsset::setTextureNameIndex(std::map<std::string, Position> map)
{
	this->nameIndex = map;
}

std::string		TextureAsset::getType()
{
	return "TextureAsset";
}