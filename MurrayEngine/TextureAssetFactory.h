#ifndef _TEXTURE_ASSET_FACTORY_H
#define	_TEXTURE_ASSET_FACTORY_H

#include "Configuration.h"
#include "TextureAsset.h"
#include "InvalidAsset.h"
#include <SDL.h>

class TextureAssetFactory
{
public:
	TextureAssetFactory();
	TextureAssetFactory(SDL_Renderer* renderer);
	~TextureAssetFactory();

	void	setRenderer(SDL_Renderer* renderer);
	Asset	createAsset(Configuration configuration);

private:

	SDL_Renderer*	instanceRenderer;

};

#endif // !_TEXTURE_ASSET_FACTORY_H
