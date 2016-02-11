#ifndef _NON_PLAYER_CHARACTER_H
#define	_NON_PLAYER_CHARACTER_H

#include	<queue>
#include	"AnimatedObject.h"
#include	"AI.h"

class AI;

class NonPlayerCharacter : public AnimatedObject
{
public:
	NonPlayerCharacter();
	NonPlayerCharacter(AnimatedObject* base);
	~NonPlayerCharacter();

	virtual AnimatedObject*			getBaseObject();
	virtual void					setBaseObject(AnimatedObject* base);

	virtual AI*						getAI();
	virtual void					setAI(AI* ai);

	//	Basic
	virtual std::string				getId();
	virtual void					setId(std::string id);

	//	Position
	virtual Position				getCurrentPosition();
	virtual Position				getTargetPosition();
	virtual void					setCurrentPosition(Position pos);
	virtual void					setCurrentPosition(int x, int y);
	virtual void					setTargetPosition(Position pos);
	virtual void					setTargetPosition(int x, int y);

	//	Speed
	virtual int						getCurrentSpeed();
	virtual double					getMaxSpeed();
	virtual void					setMaxSpeed(double maxSpeed);

	//	Direction
	virtual Orientation				getOrientation();
	virtual void					setOrientation(Orientation orientation);

	//	Texture & Rendering
	virtual Texture					getTexture();
	virtual void					setTexture(Texture texture);
	virtual void					render(int x, int y);

	//	Collision
	virtual bool					collideBox(Object* objectB);
	virtual bool					collidePixel(Object* objectB);
	virtual bool					getIsCollidable();

	// Timer counters
	virtual Uint32					getLastMove();
	virtual Uint32					getLastRender();
	virtual void					setLastRender(Uint32 lastRender);
	virtual void					setLastMove(Uint32 lastMove);

	//	Actions
	virtual void					move();
	virtual void					reverseMove();
	virtual void					jump();
	virtual void					doDamage();
	virtual void					takeDamage();

	//	Action queue
	virtual void					addAction(Action* action);
	virtual void					doAction();

	virtual Animation				getAnimation();


	virtual void					setAnimation(Animation animation);
	virtual void					addAnimation(std::string key, Animation animation);
	virtual void					changeAnimation(std::string key);

	virtual bool readAlpha(SDL_Surface* surface, int x, int y);

protected:

	

private:

	AnimatedObject*					baseObject;
	AI*								ai;

	std::queue<Action*>	actionQueue;

};

#endif // !_NON_PLAYER_CHARACTER_H
