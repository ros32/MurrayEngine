#include "Object.h"

Object::Object(const std::string id, const Position currentPosition, const std::shared_ptr<Texture> texture, const double maxSpeed, double acceleration, const int currentSpeed, const Orientation orientation, const bool isCollidable):
	red(0), green(0), blue(0), alpha(0), rmask(0), gmask(0), bmask(0), amask(0)
{
	this->id = id;
	this->currentPosition = currentPosition;
	this->texture = texture;
	this->maxSpeed = maxSpeed;
	this->currentSpeed = currentSpeed;
	//this->acceleration = acceleration;
	this->orientation = orientation;
	this->targetPosition = {0, 0};
	this->isCollidable = isCollidable;
	this->lastPosition = currentPosition;
	this->timer = Timer();

	this->timer.start();
	this->lastRender = 0;
	this->lastMove = 0;
	this->collisionAction = nullptr;
}

Object::~Object()
{

}

std::string Object::getId()
{
	return id;
}

void	Object::setId(const std::string id)
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

void	Object::setCurrentPosition(const Position pos)
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

void	Object::setTargetPosition(const Position pos)
{
	this->targetPosition = pos;
}

void Object::setOrientation(const Orientation orientation)
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

void	Object::setMaxSpeed(const double speed)
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

bool Object::collideBox(Object* objectB)
{
	if (objectB == nullptr)
		return false;

	auto hit = true;

	const auto left = this->getCurrentPosition().x;
	const auto right = this->getCurrentPosition().x + this->getCollisionTexture()->asset->getWidth();
	const auto bottom = this->getCurrentPosition().y;
	const auto top = this->getCurrentPosition().y + this->getCollisionTexture()->asset->getHeight();

	const auto otherLeft = objectB->getCurrentPosition().x;
	const auto otherRight = objectB->getCurrentPosition().x + objectB->getCollisionTexture()->asset->getWidth();
	const auto otherBottom = objectB->getCurrentPosition().y;
	const auto otherTop = objectB->getCurrentPosition().y + objectB->getCollisionTexture()->asset->getHeight();

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



bool Object::readAlpha(SDL_Surface* surface, const int x, const int y)
{
	const int bpp = surface->format->BytesPerPixel;
	auto p = static_cast<Uint8*>(surface->pixels) + y * surface->pitch + x * bpp;
	Uint32 pixelColor = 0;

	switch(bpp)
	{
	case(1) :

		//	SDL_Log("Bpp is 1");
		pixelColor = *p;
		break;
	case(2):
		//	SDL_Log("Bpp is 2");
		pixelColor = *reinterpret_cast<Uint16*>(p);
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
		pixelColor = *reinterpret_cast<Uint32*>(p);
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
	const auto textureA = this->getCollisionTexture();
	const auto textureB = objectB->getCollisionTexture();

	const auto currentPositionA = this->getCurrentPosition();
	const auto currentPositionB = objectB->getCurrentPosition();

	const auto widthA = textureA->asset->getWidth();
	const auto heightA = textureA->asset->getHeight();

	const auto widthB = textureB->asset->getWidth();
	const auto heightB = textureB->asset->getHeight();

	//Map positions of rectangles for objectA (this)
	const auto axLeft = currentPositionA.x;
	const auto ayTop = currentPositionA.y;
	const auto axRight = currentPositionA.x + widthA - 1;
	const auto ayBottom = currentPositionA.y + heightA - 1;

	//Map positions of rectangles for objectB
	const auto bxLeft = currentPositionB.x;
	const auto byTop = currentPositionB.y;
	const auto bxRight = currentPositionB.x + widthB - 1;
	const auto byBottom = currentPositionB.y + heightB - 1;

	//Get the values of the intersected rectangle where our pixel collision check will occur
	const auto left = std::max(axLeft, bxLeft);
	const auto right = std::min(axRight, bxRight);
	const auto top = std::max(ayTop, byTop);
	const auto bottom = std::min(ayBottom, byBottom);

	const auto aRect = textureA->name;
	const auto bRect = textureB->name;

	SDL_Rect targetRectA;
	SDL_Rect targetRectB;

	targetRectA.x = 0;
	targetRectA.y = 0;
	targetRectB.x = 0;
	targetRectB.y = 0;

	//Get the surfaces we need to pass to readAlpha
	const auto orgSurfaceA = textureA->asset->getSurface();
	const auto orgSurfaceB = textureB->asset->getSurface();

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

	const auto SurfaceA = SDL_CreateRGBSurface(NULL, widthA, heightA, 32, rmask, gmask, bmask, amask);
	const auto SurfaceB = SDL_CreateRGBSurface(NULL, widthB, heightB, 32, rmask, gmask, bmask, amask);

	SDL_BlitSurface(orgSurfaceA, aRect, SurfaceA, &targetRectA);
	SDL_BlitSurface(orgSurfaceB, bRect, SurfaceB, &targetRectB);

	if (SurfaceA == nullptr || SurfaceB == nullptr)
	{
		SDL_Log(SDL_GetError());
	}


	//Loop through the pixels of the intersection
	for (auto yAxis = top; yAxis <= bottom; yAxis++)
	{
		for (auto xAxis = left; xAxis <= right; xAxis++)
		{
			const auto alphaA = readAlpha(SurfaceA, xAxis - axLeft, yAxis - ayTop);
			const auto alphaB = readAlpha(SurfaceB, xAxis - bxLeft, yAxis - byTop);

			if (alphaA && alphaB)
			{
			//	this->reverseMove();
				this->doCollisionAction(objectB);
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

void	Object::setLastRender(const Uint32 lastRender)
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


std::shared_ptr<Texture>	Object::getCollisionTexture()
{
	return this->texture;
}

std::shared_ptr<Animation> Object::getAnimation(std::string key){

	return nullptr;
}
void Object::addAnimation(std::string key, std::shared_ptr<Animation> animation){

}
void Object::setCollisionAction(CollisionAction* collisionAction){
		
	this->collisionAction = collisionAction;

}
void Object::doCollisionAction(Object* obj){

	 if (this->collisionAction == nullptr){
		this->collisionAction = (new DefaultCollisionAction(this));
	 }
	this->collisionAction->execute(obj);

}


