#ifndef _DEFAULT_AI_H
#define	_DEFAULT_AI_H

#include <stdlib.h>
#include <ctime>
#include "AI.h"
#include "MoveAction.h"

class DefaultAI: public AI
{
public:
	DefaultAI();
	DefaultAI(NonPlayerCharacter* npc, Map* map);
	~DefaultAI();

	void	doNext();

	

private:

	Position	lastMovePosition;
	bool		lastMoveSuccess;

	Orientation	playerLastSeenDirection;
	bool		playerRecentlySeen;

	std::vector<Orientation>	getValidDirections();
	Orientation					getOppositeDirection(Orientation direction);

	Action*		currentAction;

	void	move();

	//	Return relative position to player from NPC
	bool	findPlayer(Orientation orientation);

	//	Return true if there is a clear path to player from NPC
	bool	canSeePlayer();


};

#endif // !_DEFAULT_AI_H
