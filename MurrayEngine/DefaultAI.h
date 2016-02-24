#ifndef _DEFAULT_AI_H
#define	_DEFAULT_AI_H

#include "AI.h"

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

};

#endif // !_DEFAULT_AI_H
