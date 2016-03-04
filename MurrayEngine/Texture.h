#ifndef _TEXTURE_H
#define	_TEXTURE_H

#include	"TextureAsset.h"

struct Texture
{
	TextureAsset*	asset;
	SDL_Rect*		name;

	Texture(TextureAsset* texture, std::string textureName)
	{
		asset = texture;
		if (asset != nullptr)
			name = texture->getSourceRect(textureName);
		else
			name = nullptr;
	}
};

#endif // !_TEXTURE_H
