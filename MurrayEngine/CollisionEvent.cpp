#define _CRTDBG_MAP_ALLOC
#include "CollisionEvent.h"

CollisionEvent::CollisionEvent(Object* objectA, Object* objectB){
	this->objectA = objectA;
	this->objectB = objectB;

}

CollisionEvent::~CollisionEvent(){

}


void CollisionEvent::execute(Object* objectA, Object* objectB){
	
	if (collideBox(objectA, objectB)){
		
	}		
}

// Collide on sprite box
bool CollisionEvent::collideBox(Object* objectA, Object* objectB)
{
	bool hit = true;

	std::shared_ptr<Texture> aTexture = objectA->getTexture();
	std::shared_ptr<Texture> bTexture = objectB->getTexture();

	//x/y corners for object A
	int Aleft = objectA->getCurrentPosition().x;
	int Aright = objectA->getCurrentPosition().x + aTexture->asset->getWidth();
	int Abottom = objectA->getCurrentPosition().y;
	int Atop = objectA->getCurrentPosition().y + aTexture->asset->getHeight();

	//x/y corners for object B
	int BLeft = objectB->getCurrentPosition().x;
	int BRight = objectB->getCurrentPosition().x + bTexture->asset->getWidth();
	int BBottom = objectB->getCurrentPosition().y;
	int BTop = objectB->getCurrentPosition().y + bTexture->asset->getHeight();

	//Checks if there is a distance between the current object sides and the other object sides.
	if (Aright < BLeft){
		hit = false;
	}
	if (Aleft > BRight){
		hit = false;
	}
	if (Atop < BBottom){
		hit = false;
	}
	if (Abottom > BTop){
		hit = false;
	}
	return hit;
}

bool CollisionEvent::collidePixel()
{

	this->objectA;
	this->objectB;

	
	if (!collideBox(objectA, objectB))
	{
		return false;
	}
	

	this->aTexture = objectA->getTexture();
	this->bTexture = objectB->getTexture();

	//Map positions of rectangles for objectA (this)
	int axLeft = objectA->getCurrentPosition().x;
	int ayTop = objectA->getCurrentPosition().y;
	int axRight = objectA->getCurrentPosition().x + aTexture->asset->getWidth() - 1;
	int ayBottom = objectA->getCurrentPosition().y + aTexture->asset->getHeight() - 1;

	//Map positions of rectangles for objectB
	int bxLeft = objectB->getCurrentPosition().x;
	int byTop = objectB->getCurrentPosition().y;
	int bxRight = objectB->getCurrentPosition().x + bTexture->asset->getWidth() - 1;
	int byBottom = objectB->getCurrentPosition().y + bTexture->asset->getHeight() - 1;

	//Get the values of the intersected rectangle where our pixel collision check will occur
	int left = std::max(axLeft, bxLeft);
	int right = std::min(axRight, bxRight);
	int top = std::max(ayTop, byTop);
	int bottom = std::min(ayBottom, byBottom);

	this->aRect = aTexture->name;
	this->bRect = bTexture->name;

	this->targetRectA.x = 0;
	this->targetRectA.y = 0;
	this->targetRectB.x = 0;
	this->targetRectB.y = 0;
	
	//Uint8 red, green, blue, alpha;
	//Uint32 rmask, gmask, bmask, amask;

	if (SDL_BYTEORDER == SDL_BIG_ENDIAN){
		rmask = 0xff000000;
		gmask = 0x00ff0000;
		bmask = 0x0000ff00;
		amask = 0x000000ff;
	}
	else{
		rmask = 0x000000ff;
		gmask = 0x0000ff00;
		bmask = 0x00ff0000;
		amask = 0xff000000;
	}

	//Get the surfaces we need to pass to readAlpha
	orgSurfaceA = aTexture->asset->getSurface();
	orgSurfaceB = bTexture->asset->getSurface();

	//Create destination surfaces for the blit;	

	SurfaceA = SDL_CreateRGBSurface(NULL, aTexture->asset->getWidth(), aTexture->asset->getHeight(), 32, rmask, gmask, bmask, amask);
	SurfaceB = SDL_CreateRGBSurface(NULL, bTexture->asset->getWidth(), bTexture->asset->getHeight(), 32, rmask, gmask, bmask, amask);

	SDL_BlitSurface(orgSurfaceA, aRect, SurfaceA, &targetRectA);
	SDL_BlitSurface(orgSurfaceB, bRect, SurfaceB, &targetRectB);

	if (SurfaceA == nullptr || SurfaceB == nullptr)
	{
		SDL_Log("Surfaces is nullptr!! ", SDL_GetError());
	}

	bool alphaA;
	bool alphaB;

	//Loop through the pixels of the intersection
	for (int yAxis = top; yAxis <= bottom; yAxis++)
	{
		for (int xAxis = left; xAxis <= right; xAxis++)
		{
			alphaA = readAlpha(SurfaceA, xAxis - axLeft, yAxis - ayTop);
			alphaB = readAlpha(SurfaceB, xAxis - bxLeft, yAxis - byTop);

			if (alphaA && alphaB)
			{
				SDL_FreeSurface(SurfaceA);
				SDL_FreeSurface(SurfaceB);
				return true;
			}
			if ((yAxis == bottom) && (xAxis == right))
			{
				if (!alphaA && !alphaB)
				{
					SDL_FreeSurface(SurfaceA);
					SDL_FreeSurface(SurfaceB);
					return false;
				}
			}

		}
	}

	return false;
}

bool CollisionEvent::readAlpha(SDL_Surface* surface, int x, int y)
{
	int bpp = surface->format->BytesPerPixel;
	Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;
	Uint32 pixelColor;

	switch (bpp)
	{
	case(1) :
		pixelColor = *p;
		break;
	case(2) :
		pixelColor = *(Uint16*)p;
		break;
	case(3) :
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			pixelColor = p[0] << 16 | p[1] << 8 | p[2];
		else
			pixelColor = p[0] | p[1] << 8 | p[2] << 16;
		break;
	case(4) :
		pixelColor = *(Uint32*)p;
		break;
	default:
		break;
	}

	//   Uint8 red, green, blue, alpha;
	SDL_GetRGBA(pixelColor, surface->format, &red, &green, &blue, &alpha);

	return alpha > 1;

}

void CollisionEvent::reverseMove(Object* object)
{
	//North 
	if (object->getOrientation() == 0){ object->setCurrentPosition(object->getCurrentPosition().x, object->getCurrentPosition().y + 1); }
	//East 
	if (object->getOrientation() == 1){ object->setCurrentPosition(object->getCurrentPosition().x - 1, object->getCurrentPosition().y); }
	//South
	if (object->getOrientation() == 2){ object->setCurrentPosition(object->getCurrentPosition().x, object->getCurrentPosition().y - 1); }
	//West
	if (object->getOrientation() == 3){ object->setCurrentPosition(object->getCurrentPosition().x + 1, object->getCurrentPosition().y); }

}