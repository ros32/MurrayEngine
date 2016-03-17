#ifndef _TEXTURE_H
#define	_TEXTURE_H

#include	"TextureAsset.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	The Texture struct combines a pointer to the TextureAsset with a pointer
/// 			to the SDL_Rect used in the TextureAsset to a single data type. </summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
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
