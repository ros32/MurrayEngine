#include "GenericObject.h"

GenericObject::GenericObject()
{

}

GenericObject::GenericObject(std::string id, Position currentPosition, Texture texture, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool isCollidable)
{
	this->id = id;
	this->currentPosition = currentPosition;
	this->texture = texture;
	this->maxSpeed = maxSpeed;
	this->currentSpeed = currentSpeed;
	//this->acceleration = acceleration;
	this->orientation = orientation;
	this->targetPosition = { 0, 0 };
	this->isCollidable = isCollidable;
	this->lastPosition;
	this->timer = Timer();

	this->timer.start();
	this->lastRender = 0;
	this->lastMove = 0;
	

}

GenericObject::~GenericObject()
{

}

std::string GenericObject::getId()
{
	return id;
}

Position GenericObject::getCurrentPosition()
{
	return currentPosition;
}

void GenericObject::setCurrentPosition(int x, int y)
{
	this->currentPosition = { x, y };
}

Position GenericObject::getTargetPosition(){

	return targetPosition;
}

void GenericObject::setTargetPosition(int x, int y)
{
	this->targetPosition = { x, y };
}

void GenericObject::setOrientation(Orientation orientation)
{
	this->orientation = orientation;
}

Orientation GenericObject::getOrientation()
{
	return orientation;
}

double GenericObject::getMaxSpeed()
{
	return maxSpeed;
}

bool GenericObject::getIsCollidable()
{
	return isCollidable;
}

void GenericObject::reverseMove()
{
	SDL_Log("Moving back through reverseMove");
		//North 
		if (this->orientation == 0){ this->currentPosition.y += 1; }
		//East 
		if (this->orientation == 1){ this->currentPosition.x -= 1; }
		//South
		if (this->orientation == 2){ this->currentPosition.y -= 1; }
		//West
		if (this->orientation == 3){ this->currentPosition.x += 1; }

}

void GenericObject::move()
{
	//Save the currentposition before we move
	
	
	this->lastPosition = this->currentPosition;

	//Add the velocity to the current position
	currentPosition.x += this->currentSpeed * this->targetPosition.x;
	currentPosition.y += this->currentSpeed * this->targetPosition.y;

	this->targetPosition = { 0, 0 };
	
}

bool GenericObject::collideBox(GenericObject* objectB)
{
	
	bool hit = true;
	
	int left = currentPosition.x;
	int right = currentPosition.x + this->texture.asset->getWidth();
	int bottom = currentPosition.y;
	int top = currentPosition.y + this->texture.asset->getHeight();

	int otherLeft = objectB->currentPosition.x;
	int otherRight = objectB->currentPosition.x + objectB->texture.asset->getWidth();
	int otherBottom = objectB->currentPosition.y;
	int otherTop = objectB->currentPosition.y + objectB->texture.asset->getHeight();

	//Checks if there is a distance between the current object sides and the other object sides.
	if (right < otherLeft){
		hit =  false;
	} 
	if (left > otherRight){
		hit = false;
	}
	if (top < otherBottom){
		hit =  false;
	} 
	if (bottom > otherTop){
		hit = false;
	} 

	if (hit)
		SDL_Log("Hit in CollideBox is true");
	
	
		return hit;	
}

bool GenericObject::readAlpha(SDL_Surface* surface, int x, int y)
{	
	std::string Output = "xAxis is: " + std::to_string(x) + " " + "yAxis is: " + std::to_string(y);
	SDL_Log(Output.c_str());

	//Nån annans kod, för testning
	int bpp = surface->format->BytesPerPixel;
    Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;
    Uint32 pixelColor;
     
    switch(bpp)
    {
	case(1) :

	//	SDL_Log("Bpp is 1");
            pixelColor = *p;
            break;
        case(2):
	//		SDL_Log("Bpp is 2");
            pixelColor = *(Uint16*)p;
            break;
        case(3):
	//		SDL_Log("Bpp is 3");
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
                pixelColor = p[0] << 16 | p[1] << 8 | p[2];
            else
                pixelColor = p[0] | p[1] << 8 | p[2] << 16;
            break;
        case(4):
	//		SDL_Log("Bpp is 4");
            pixelColor = *(Uint32*)p;
            break;
		default:
			break;
    }
     
 //   Uint8 red, green, blue, alpha;
    SDL_GetRGBA(pixelColor, surface->format, &red, &green, &blue, &alpha);
 
	if (alpha > 200){
		SDL_Log("Alpha is true");
	}
	else{
		SDL_Log("Alpha is false");
	}

	return alpha > 200;
//	return alpha;

	

	//-------------------------------


	/*
	SDL_Log("Assering alpha");
	
	SDL_PixelFormat* pixelFormat = surface->format;
	int pixelByte = pixelFormat->BytesPerPixel;

	Uint8* pixel = (Uint8*)surface->pixels + y * surface->pitch + x * pixelByte;
	
	Uint32 pixelData = *pixel;

	// get the values of RGBA
	SDL_GetRGBA(pixelData, pixelFormat, &red, &green, &blue, &alpha);

	if (alpha < 1){
		SDL_Log("Pixel is transparent");
	}
	else {
		SDL_Log("Pixel is not transparent");
	}

	return alpha;
	
	
	*/


}

bool GenericObject::collidePixel(GenericObject* objectB)
{

	if (!collideBox(objectB))
	{
		return false;
	}
	/*
	SDL_Log("checking collision between:");
	SDL_Log(this->getId().c_str());
	SDL_Log(objectB->getId().c_str());
	
	*/


	//Map positions of rectangles for this and comparing object
	int axLeft = this->currentPosition.x;
	int ayTop = this->currentPosition.y;
	int axRight = this->currentPosition.x + this->texture.asset->getWidth() - 1;
	int ayBottom = this->currentPosition.y + this->texture.asset->getHeight() - 1;

	int bxLeft = objectB->currentPosition.x;
	int byTop = objectB->currentPosition.y;
	int bxRight = objectB->currentPosition.x + objectB->texture.asset->getWidth() - 1;
	int byBottom = objectB->currentPosition.y + objectB->texture.asset->getHeight() - 1;

	//Get the values of the intersected rectangle where our pixel collision check will occur
	int left = std::max(axLeft, bxLeft);
	int right = std::min(axRight, bxRight);
	int top = std::max(ayTop, byTop);
	int bottom = std::min(ayBottom, byBottom);

	//Get the surfaces we need to pass to readAlpha
	SDL_Surface* SurfaceA = this->texture.asset->getSurface();
	SDL_Surface* SurfaceB = objectB->texture.asset->getSurface();

	bool alphaA;
	bool alphaB;

	if (SurfaceA == nullptr || SurfaceB == nullptr)
	{
		SDL_Log(SDL_GetError());
	}

	//Loop through the pixels of the intersection
	for (int yAxis = top; yAxis <= bottom; yAxis++)
	{
		for (int xAxis = left; xAxis <= right; xAxis++)
		{

			// Check if the current pixel contains color by calling readAlpha

			std::string output1 = "Checking alpha for: " + this->getId();
			std::string output2 = "Checking alpha for: " + objectB->getId();

			//Tests
			SDL_Log(output1.c_str());
			alphaA = readAlpha(SurfaceA, xAxis - axLeft, (yAxis + 400) - ayTop);
			SDL_Log(output2.c_str());
			alphaB = readAlpha(SurfaceB, xAxis - bxLeft, yAxis - byTop);

			if (alphaA && alphaB)
			{
				SDL_Log("alpha-check returned True for both objects");
				return true;
			}
			if ((yAxis == bottom) && (xAxis == right))
			{
				if (!alphaA && !alphaB);
				SDL_Log("No hit was registered");
				return false;

			}

			}	
		}
		
	
}

Texture			GenericObject::getTexture()
{
	return this->texture;
}

void GenericObject::render(int x, int y)
{
	if (this->texture.asset != nullptr && this->texture.name != "")
	{
		this->texture.asset->render(x, y, this->texture.asset->getSourceRect(this->texture.name));
		this->lastRender = this->timer.getTicks();
}
}

int		GenericObject::getCurrentSpeed()
{
	return this->currentSpeed;
}

void   GenericObject::jump()
{
	SDL_Log("Jumping");
}
void   GenericObject::doDamage()
{
	SDL_Log("doing some damage");
}
void  GenericObject::takeDamage()
{
	SDL_Log("Taking some damage");
}

void	GenericObject::setTexture(Texture texture)
{
	this->texture = texture;
}

Uint32	GenericObject::getLastRender()
{
	return this->lastRender;
}

void	GenericObject::setLastRender(Uint32 lastRender)
{
	this->lastRender = lastRender;
}