#ifndef _TEXTURE_ASSET_FACTORY_H
#define	_TEXTURE_ASSET_FACTORY_H

#include "Configuration.h"
#include "TextureAsset.h"
#include "InvalidAsset.h"
#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif

class TextureAssetFactory
{
public:
	TextureAssetFactory();
	TextureAssetFactory(SDL_Renderer* renderer);
	~TextureAssetFactory();

	void			setRenderer(SDL_Renderer* renderer);
	TextureAsset*	createAsset(Configuration configuration);

private:

	SDL_Renderer*	instanceRenderer;

};

#endif // !_TEXTURE_ASSET_FACTORY_H
