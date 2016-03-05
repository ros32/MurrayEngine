#ifndef _NON_PLAYER_CHARACTER_H
#define	_NON_PLAYER_CHARACTER_H

#include	<queue>
#include	"AnimatedObject.h"
#include	"AI.h"

class AI;

class NonPlayerCharacter : public AnimatedObject
{
public:
	NonPlayerCharacter(std::string id, Position currentPosition, std::shared_ptr<Animation> animation, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool isCollidable);
	~NonPlayerCharacter();

	virtual AI*						getAI();
	virtual void					setAI(AI* ai);

	virtual void					addAction(Action* action);
	virtual Action*					getAction();
	virtual void					doAction();

	virtual bool actionExists();

protected:

	

private:

	AI*								ai;

	std::queue<Action*>	actionQueue;

};

#endif // !_NON_PLAYER_CHARACTER_H
