#ifndef TEXTURE_ASSET_H
#define TEXTURE_ASSET_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <map>
#include "Asset.h"
#include "Position.h"

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
	

public:
	TextureAsset(SDL_Renderer* renderer, const char* filePath, unsigned int cellSize, unsigned int offset, SDL_Color colorKey);
	~TextureAsset();

	SDL_Texture*	getTexture();
	SDL_Rect*		getSourceRect(unsigned int x, unsigned int y);
	SDL_Rect*		getSourceRect(std::string name);

	void	load();
	void	unload();

	void	setTextureNameIndex(std::map<std::string, Position> map);
	std::string		getType();

	void	render(int x, int y, SDL_Rect* clip);

	void	render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip);
};

#endif // !TEXTURE_ASSET_H
