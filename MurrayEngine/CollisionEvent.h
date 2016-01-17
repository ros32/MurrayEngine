#ifndef COLLISION_EVENT_H
#define COLLISION_EVENT_H


#include "Object.h"
#include "TextureAsset.h"
#include "Position.h"
#include "TextureAsset.h"
#include <SDL.h>


class CollisionEvent {

public:
	CollisionEvent();
	~CollisionEvent();

	void execute(Object* objectA, Object* objectB);
	bool collidePixel(Object* objectA, Object* objectB);

private:
	bool collideBox(Object* objectA, Object* objectB);
	bool readAlpha(SDL_Surface* surface, int x, int y);


	void reverseMove(Object* object);

	//Map* map;
	Object* objectA;
	Object* objectB;

	
	Texture aTexture;
	Texture bTexture;
	//The original surfaces we need to pass to readAlpha
	SDL_Surface* orgSurfaceA;
	SDL_Surface* orgSurfaceB;

	//Create destination surfaces for the blit;
	SDL_Surface* SurfaceA;
	SDL_Surface* SurfaceB;

	SDL_Rect* aRect;
	SDL_Rect* bRect;

	SDL_Rect targetRectA;
	SDL_Rect targetRectB;

	Uint8 red, green, blue, alpha;
	Uint32 rmask, gmask, bmask, amask;

};


#endif