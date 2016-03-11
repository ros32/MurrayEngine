#ifndef _WITCH_AI_H
#define _WITCH_AI_H

#include "AI.h"
#include "DamageAction.h"
#include "ObjectFactory.h"

class ObjectFactory;
class WitchAI : public AI{

public:
	WitchAI();
	WitchAI(NonPlayerCharacter* npc, Map* map, ObjectFactory* objectFactory);
	~WitchAI();

	void	doNext();

private:

	Position playerPosition;
	Position bossPosition;

	int bossHeight;
	int bossWidth;
	int playerHeight;
	int playerWidth;

	void lookForPlayer();

	ObjectFactory* objectFactory;

};

#endif //!_WITCH_AI_H