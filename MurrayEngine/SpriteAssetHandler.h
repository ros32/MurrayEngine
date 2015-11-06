#ifndef SPRITE_ASSET_HANDLER_H
#define SPRITE_ASSET_HANDLER_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "AssetHandler.h"

class SpriteAssetHandler : public AssetHandler
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
	SpriteAssetHandler(SDL_Renderer* renderer, const char* filePath, unsigned int cellSize, unsigned int offset, SDL_Color colorKey);
	~SpriteAssetHandler();

	SDL_Texture*	getTexture();
	SDL_Rect*		getSourceRect(unsigned int x, unsigned int y);

	void	load();
	void	unload();
};

#endif // !SPRITE_ASSET_HANDLER_H
