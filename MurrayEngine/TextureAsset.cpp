#include "TextureAsset.h"

TextureAsset::TextureAsset(SDL_Renderer* renderer, const char* filePath, unsigned int cellSize, unsigned int offset, SDL_Color colorKey) : 
	TextureAsset(renderer, filePath, cellSize, cellSize, offset, colorKey) { }

TextureAsset::TextureAsset(SDL_Renderer* renderer, const char* filePath, unsigned int width, unsigned int height, unsigned int offset, SDL_Color colorKey)
{
	//	Set variables
	this->renderer = renderer;
	this->filePath = filePath;
	this->cellSize = width;
	this->height = height;
	this->width = width;
	this->offset = offset;
	this->colorKey = colorKey;
	this->surface;
	//	Initialize indices
	this->index;
	this->nameIndex;

	//	Load texture from file
	this->loadFile(filePath);

	//	Write debug output
	std::string output = "TextureAsset created: filePath: " + std::string(filePath) + ", width: " + std::to_string(width) +
		", height: " + std::to_string(height) + ", offset: " + std::to_string(offset) + ", colorKey: { " + std::to_string(colorKey.a) + ", " + std::to_string(colorKey.b) +
		", " + std::to_string(colorKey.g) + ", " + std::to_string(colorKey.r) + " }.";
	SDL_LogDebug(SDL_LOG_CATEGORY_VIDEO, output.c_str());
}

TextureAsset::TextureAsset(SDL_Renderer* renderer, const char* filePath, unsigned int fontSize, std::string text, SDL_Color color)
{
	this->renderer = renderer;
	this->filePath = filePath;
	this->cellSize = 0;
	this->height = 0;
	this->width = 0;
	this->offset = 0;
	this->colorKey = { 0, 240, 240, 240 };

	this->index;
	this->nameIndex;

	this->loadText(filePath, fontSize, text, color);

	std::string output = "TextureAsset created with font: \"" + std::string(filePath) + "\", size: " + std::to_string(fontSize) + ", text: \"" + text + "\", color: { " + 
		std::to_string(color.a) + ", " + std::to_string(color.b) + ", " + std::to_string(color.g) + ", " + std::to_string(color.r) + " }.";
	SDL_LogDebug(SDL_LOG_CATEGORY_VIDEO, output.c_str());
}

TextureAsset::~TextureAsset()
{
	//	Unload texture
	this->unload();
}

void			TextureAsset::loadFile(const char* filePath)
{
	//	Load texture using SDL_image
	this->surface = IMG_Load(this->filePath);
	this->texture = SDL_CreateTextureFromSurface(this->renderer, surface);

//	this->texture = IMG_LoadTexture(this->renderer, filePath);
	if (this->texture == nullptr)
		SDL_LogError(SDL_LOG_CATEGORY_VIDEO, SDL_GetError());
	else
	{
		std::string output = "File loaded: " + std::string(filePath);
		SDL_LogVerbose(SDL_LOG_CATEGORY_VIDEO, output.c_str());
	}

	//	Generate SDL_Rect index for texture
	this->generateIndex();
}

void			TextureAsset::loadText(const char* filePath, unsigned int fontSize, std::string text, SDL_Color color)
{
	TTF_Font*	font = TTF_OpenFont(filePath, fontSize);
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	TTF_CloseFont(font);
	if (textSurface == NULL)
	{
		std::string output = "Unable to render text, SDL_ttf error! " + std::string(TTF_GetError());
		SDL_LogError(SDL_LOG_CATEGORY_RENDER, output.c_str());
	}
	else
	{
		this->texture = SDL_CreateTextureFromSurface(this->renderer, textSurface);
		if (this->texture == NULL)
		{
			std::string output = "Could not create texture from rendered text!" + std::string(SDL_GetError());
			SDL_LogError(SDL_LOG_CATEGORY_RENDER, output.c_str());
		}
		else
		{
			this->width = textSurface->w;
			this->height = textSurface->h;
			this->cellSize = textSurface->w;
		}

		SDL_FreeSurface(textSurface);
		this->surface = nullptr;
	}
}

void			TextureAsset::unload()
{
	//	Destroy texture and set texture to nullpointer
	SDL_DestroyTexture(this->texture);
	SDL_FreeSurface(this->surface);
	this->texture = nullptr;
	this->surface = nullptr;

	//	Log to debuglog
	std::string output = "TextureAsset \"" + std::string(this->filePath) + "\" was unloaded";
	SDL_LogDebug(SDL_LOG_CATEGORY_VIDEO, output.c_str());
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

	//	Get width and height info from SDL_Texture
	SDL_QueryTexture(this->texture, NULL, NULL, &sizeX, &sizeY);

	//	As long as there fits SDL_Rects (+ offset) in the X-axis of the SDL_Texture, do:
	do
	{
		posY = 0;
		std::vector<SDL_Rect> tempVector;
		this->index.push_back(tempVector);

		//	As long as there fits SDL_Rects (+ offset) in the Y-axis of the SDL_Texture, do:
		do
		{
			//	int j = 0;
			SDL_Rect tempRect = { (posX + this->offset), (posY + this->offset), this->width, this->height };
			this->index[i].push_back(tempRect);
			posY += (this->height + offsetY);
			//	j++;
		} while (sizeY - (posY + (this->height + offsetY)) >= 0);
		posX += (this->width + offsetX);
		i++;
	} while (sizeX - (posX + (this->width + offsetX)) >= 0);

	std::string maxX = std::to_string(this->index.size());
	std::string maxY = std::to_string(this->index[0].size());
	std::string output = "Index generated: Max X = " + maxX + ", Max Y = " + maxY + ".";

	SDL_LogVerbose(SDL_LOG_CATEGORY_VIDEO, output.c_str());

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
	std::string output = "Soruce SDL_Rect was not found for index " + std::to_string(x) + ", " + std::to_string(y) + "; returning default (0,0)";
	SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, output.c_str());
	return &index[0][0];
}

SDL_Rect*	TextureAsset::getSourceRect(std::string name)
{
	std::map<std::string, Position>::iterator iterator;
	iterator = this->nameIndex.find(name);

	if (iterator != this->nameIndex.end())
		return this->getSourceRect(iterator->second.x, iterator->second.y);
	else
	{
		std::string output = "Source SDL_Rect was not found for name \"" + name + "\", returning default (0,0)";
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, output.c_str());
		return this->getSourceRect(0, 0);
}
}

void		TextureAsset::setTextureNameIndex(std::map<std::string, Position> map)
{
	this->nameIndex = map;
}

std::string		TextureAsset::getType()
{
	return "TextureAsset";
}

void	TextureAsset::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//	Create target SDL_Rect with given x and y positions, the width and height of a sprite
	SDL_Rect destination = { x, y, this->width, this->height };

	//	If clip is set, set width and height of destination to that of clip, to resize texture
	if (clip != NULL)
	{
		destination.w = clip->w;
		destination.h = clip->h;
	}

	//	Render and log error, if any
	if (SDL_RenderCopyEx(this->renderer, this->texture, clip, &destination, angle, center, flip) != 0)
		SDL_LogError(SDL_LOG_CATEGORY_RENDER, SDL_GetError());
}

void	TextureAsset::render(int x, int y, SDL_Rect* clip)
{
	this->render(x, y, clip, 0.0, NULL, SDL_FLIP_NONE);
}

int		TextureAsset::getCellSize()
{
	return this->cellSize;
}

int		TextureAsset::getWidth()
{
	return this->width;
}

int		TextureAsset::getHeight()
{
	return this->height;
}

SDL_Surface* TextureAsset::getSurface()
{
	return this->surface;
}