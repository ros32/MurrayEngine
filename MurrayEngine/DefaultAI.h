#ifndef _DEFAULT_AI_H
#define	_DEFAULT_AI_H

#include "AI.h"
#include "MoveAction.h"

class DefaultAI: public AI
{
public:
	DefaultAI();
	DefaultAI(NonPlayerCharacter* npc, Map* map);
	~DefaultAI();

	void	doNext();

	void	move();

private:

	Position	lastMovePosition;
	bool		lastMoveSuccess;

	Action*		currentAction;

};

#endif // !_DEFAULT_AI_H
