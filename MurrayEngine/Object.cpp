#define _CRTDBG_MAP_ALLOC
#include "Object.h"

Object::Object()
{

}

Object::Object(std::string id, Position currentPosition, std::shared_ptr<Texture> texture, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool isCollidable)
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
	this->collisionEvent;

}

Object::~Object()
{

}

std::string Object::getId()
{
	return id;
}

void	Object::setId(std::string id)
{
	this->id = id;
}

Position Object::getCurrentPosition()
{
	return currentPosition;
}

void Object::setCurrentPosition(int x, int y)
{
	this->currentPosition = { x, y };
}

void	Object::setCurrentPosition(Position pos)
{
	this->currentPosition = pos;
}

Position Object::getTargetPosition(){

	return targetPosition;
}

void Object::setTargetPosition(int x, int y)
{
	this->targetPosition = { x, y };
}

void	Object::setTargetPosition(Position pos)
{
	this->targetPosition = pos;
}

void Object::setOrientation(Orientation orientation)
{
	this->orientation = orientation;
}

Orientation Object::getOrientation()
{
	return orientation;
}

double Object::getMaxSpeed()
{
	return maxSpeed;
}

void	Object::setMaxSpeed(double speed)
{
	this->maxSpeed = speed;
}

bool Object::getIsCollidable()
{
	return isCollidable;
}

void Object::reverseMove()
{
		//North 
		if (this->orientation == 0){ this->currentPosition.y += 1; }
		//East 
		if (this->orientation == 1){ this->currentPosition.x -= 1; }
		//South
		if (this->orientation == 2){ this->currentPosition.y -= 1; }
		//West
		if (this->orientation == 3){ this->currentPosition.x += 1; }

}

void Object::move()
{
	/*
	//Save the currentposition before we move
	
	this->lastPosition = this->currentPosition;

	//Add the velocity to the current position
	currentPosition.x += this->currentSpeed * this->targetPosition.x;
	currentPosition.y += this->currentSpeed * this->targetPosition.y;

	this->targetPosition = { 0, 0 };
	*/
}



bool Object::collideBox(Object* objectB)
{
	if (objectB == nullptr)
		return false;

	bool hit = true;

	int left = this->getCurrentPosition().x;
	int right = this->getCurrentPosition().x + this->getCollisionTexture()->asset->getWidth();
	int bottom = this->getCurrentPosition().y;
	int top = this->getCurrentPosition().y + this->getCollisionTexture()->asset->getHeight();

	int otherLeft = objectB->getCurrentPosition().x;
	int otherRight = objectB->getCurrentPosition().x + objectB->getCollisionTexture()->asset->getWidth();
	int otherBottom = objectB->getCurrentPosition().y;
	int otherTop = objectB->getCurrentPosition().y + objectB->getCollisionTexture()->asset->getHeight();

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
	return hit;
}



bool Object::readAlpha(SDL_Surface* surface, int x, int y)
{

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
		//	SDL_Log("Bpp is 2");
		pixelColor = *(Uint16*)p;
		break;
	case(3):
		//	SDL_Log("Bpp is 3");
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
		pixelColor = p[0] << 16 | p[1] << 8 | p[2];
		else
		pixelColor = p[0] | p[1] << 8 | p[2] << 16;
		break;
	case(4):
		//	SDL_Log("Bpp is 4");
		pixelColor = *(Uint32*)p;
		break;
	default:
		break;
	}

//   Uint8 red, green, blue, alpha;
	SDL_GetRGBA(pixelColor, surface->format, &red, &green, &blue, &alpha);

	return alpha > 1;

}


bool Object::collidePixel(Object* objectB)
{
	if (objectB == nullptr)
		return true;

	if (!collideBox(objectB))
	{
		return false;
	}

	//	Store Textures
	const std::shared_ptr<Texture> textureA = this->getCollisionTexture();
	const std::shared_ptr<Texture> textureB = objectB->getCollisionTexture();

	const Position currentPositionA = this->getCurrentPosition();
	const Position currentPositionB = objectB->getCurrentPosition();

	const int widthA = textureA->asset->getWidth();
	const int heightA = textureA->asset->getHeight();

	const int widthB = textureB->asset->getWidth();
	const int heightB = textureB->asset->getHeight();

	//Map positions of rectangles for objectA (this)
	int axLeft = currentPositionA.x;
	int ayTop = currentPositionA.y;
	int axRight = currentPositionA.x + widthA - 1;
	int ayBottom = currentPositionA.y + heightA - 1;

	//Map positions of rectangles for objectB
	int bxLeft = currentPositionB.x;
	int byTop = currentPositionB.y;
	int bxRight = currentPositionB.x + widthB - 1;
	int byBottom = currentPositionB.y + heightB - 1;

	//Get the values of the intersected rectangle where our pixel collision check will occur
	int left = std::max(axLeft, bxLeft);
	int right = std::min(axRight, bxRight);
	int top = std::max(ayTop, byTop);
	int bottom = std::min(ayBottom, byBottom);

	SDL_Rect* aRect = textureA->name;
	SDL_Rect* bRect = textureB->name;

	SDL_Rect targetRectA;
	SDL_Rect targetRectB;

	targetRectA.x = 0;
	targetRectA.y = 0;
	targetRectB.x = 0;
	targetRectB.y = 0;

	//Get the surfaces we need to pass to readAlpha
	SDL_Surface* orgSurfaceA = textureA->asset->getSurface();
	SDL_Surface* orgSurfaceB = textureB->asset->getSurface();

	//Create destination surfaces for the blit;
	SDL_Surface* SurfaceA;
	SDL_Surface* SurfaceB;

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

	SurfaceA = SDL_CreateRGBSurface(NULL, widthA, heightA, 32, rmask, gmask, bmask, amask);
	SurfaceB = SDL_CreateRGBSurface(NULL, widthB, heightB, 32, rmask, gmask, bmask, amask);

	SDL_BlitSurface(orgSurfaceA, aRect, SurfaceA, &targetRectA);
	SDL_BlitSurface(orgSurfaceB, bRect, SurfaceB, &targetRectB);

	if (SurfaceA == nullptr || SurfaceB == nullptr)
	{
		SDL_Log(SDL_GetError());
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
				this->reverseMove();
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

	SDL_FreeSurface(SurfaceA);
	SDL_FreeSurface(SurfaceB);
	return false;
}

CollisionEvent* Object::getCollisionEvent(){

	return this->collisionEvent;
}

void Object::setCollisionEvent(CollisionEvent* collisionEvent){

	this->collisionEvent = collisionEvent;
}


std::shared_ptr<Texture>			Object::getTexture()
{
	return this->texture;
}

void Object::render(int x, int y)
{
	if (this->texture->asset != nullptr && this->texture->name != nullptr)
	{
		this->texture->asset->render(x, y, this->texture->name);
		this->lastRender = this->timer.getTicks();
}
}

int		Object::getCurrentSpeed()
{
	return this->currentSpeed;
}

void   Object::jump()
{
	SDL_Log("Jumping");
}
void   Object::doDamage()
{
	SDL_Log("doing some damage");
}
void  Object::takeDamage()
{
	SDL_Log("Taking some damage");
}

void	Object::setTexture(std::shared_ptr<Texture> texture)
{
	this->texture = texture;
}

Uint32	Object::getLastRender()
{
	return this->lastRender;
}

Uint32	Object::getLastMove()
{
	return this->lastMove;
}

void	Object::setLastMove(Uint32 lastMove)
{
	this->lastMove = lastMove;
}

void	Object::setLastRender(Uint32 lastRender)
{
	this->lastRender = lastRender;
}

void	Object::addAction(Action* action)
{
	delete action;
}

void	Object::changeAnimation(std::string key){

}

void	Object::doAction()
{

}

Action*	Object::getAction()
{
	return nullptr;
}
//std::vector<Texture>
std::vector<std::shared_ptr<Texture>> Object::getAnimationVector(std::string key){
	std::vector<std::shared_ptr<Texture>> temp;
	return temp;
}
int Object::getAnimationTime(std::string key){
	
	return 0;
}

std::shared_ptr<Texture>	Object::getCollisionTexture()
{
	return this->texture;
}
