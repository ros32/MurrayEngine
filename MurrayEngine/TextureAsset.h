#ifndef TEXTURE_ASSET_H
#define TEXTURE_ASSET_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Asset.h"

class TextureAsset : public Asset
{
private:
//	SDL_Surface*			surface;
	SDL_Texture*			texture;
	SDL_Renderer*			renderer;
	const char*				filePath;
	std::vector< std::vector<SDL_Rect>>	index;
	int						cellSize;
	int						offset;
	void					generateIndex();
	SDL_Color				colorKey;

public:
	TextureAsset(SDL_Renderer* renderer, const char* filePath, unsigned int cellSize, unsigned int offset, SDL_Color colorKey);
	~TextureAsset();

	SDL_Texture*	getTexture();
	SDL_Rect*		getSourceRect(unsigned int x, unsigned int y);

	void	load();
	void	unload();
};

#endif // !TEXTURE_ASSET_H
