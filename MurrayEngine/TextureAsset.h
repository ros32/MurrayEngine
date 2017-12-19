#ifndef TEXTURE_ASSET_H
#define TEXTURE_ASSET_H

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif
#include <vector>
#include <map>
#include "Asset.h"
#include "Position.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	The TextureAsset class is an implementation of the Asset interface that handles
/// 			textures.
/// 			
/// 			The TextureAsset class creates a large SDL_Texture from an image file, and indexes it
/// 			with SDL_Rects, thus creating a sprite sheet.
/// 			
/// 			The TextureAsset class can also render text to SDL_Texture </summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
class TextureAsset : public Asset
{
private:
	SDL_Surface*			surface;
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
	TextureAsset(SDL_Renderer* renderer, const char* filePath, unsigned int fontSize, std::string text, SDL_Color color);
	~TextureAsset();


	SDL_Texture*	getTexture();
	SDL_Rect*		getSourceRect(unsigned int x, unsigned int y);
	SDL_Rect*		getSourceRect(std::string name);
	SDL_Surface*	getSurface();

	void			loadFile(const char* filePath);
	void			loadText(const char* filePath, unsigned int fontSize, std::string text, SDL_Color color);

	void	load() = delete;
	void	unload();

	void	setTextureNameIndex(std::map<std::string, Position> map);
	std::string		getType() override;

	int		getCellSize();

	int		getWidth();
	int		getHeight();

	void	render(int x, int y, SDL_Rect* clip);

	void	render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip);

};



#endif // !TEXTURE_ASSET_H
