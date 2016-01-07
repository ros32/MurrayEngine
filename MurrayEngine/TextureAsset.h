#ifndef TEXTURE_ASSET_H
#define TEXTURE_ASSET_H

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif
#include <vector>
#include <map>
#include "Asset.h"
#include "Position.h"

//	Inform about TextureAsset so Texture knows what it is.
class TextureAsset;

struct Texture
{
	TextureAsset*	asset;
	std::string		name;

	Texture(TextureAsset* texture, std::string textureName)
	{
		asset = texture;
		name = textureName;
	}

	Texture() : Texture(nullptr, "")
	{ }
};

class TextureAsset : public Asset
{
private:
//	SDL_Surface*			surface;
	SDL_Texture*			texture;
	SDL_Renderer*			renderer;
	const char*				filePath;
	std::vector< std::vector<SDL_Rect>>	index;
	std::map<std::string, Position>	nameIndex;
	int						cellSize;
	int						offset;
	void					generateIndex();
	SDL_Color				colorKey;

	int						width;
	int						height;
	

public:
	TextureAsset(SDL_Renderer* renderer, const char* filePath, unsigned int cellSize, unsigned int offset, SDL_Color colorKey);
	TextureAsset(SDL_Renderer* renderer, const char* filePath, unsigned int width, unsigned int height, unsigned int offset, SDL_Color colorKey);
	~TextureAsset();


	SDL_Texture*	getTexture();
	SDL_Rect*		getSourceRect(unsigned int x, unsigned int y);
	SDL_Rect*		getSourceRect(std::string name);

	void			loadFile(const char* filePath);
	void			loadText(const char* filePath, SDL_Color color);

	void	load();
	void	unload();

	void	setTextureNameIndex(std::map<std::string, Position> map);
	std::string		getType();

	int		getCellSize();

	int		getWidth();
	int		getHeight();

	void	render(int x, int y, SDL_Rect* clip);

	void	render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip);
};

#endif // !TEXTURE_ASSET_H
