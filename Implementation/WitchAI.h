#ifndef _WITCH_AI_H
#define _WITCH_AI_H

#include "AI.h"
#include "DamageAction.h"

class WitchAI : public AI{

public:
	WitchAI();
	WitchAI(Object* npc, Map* map);
	~WitchAI();

	void	doNext();

private:

	Position playerPosition;
	Position bossPosition;

	Object*	npc;
	Map*	map;

	int bossHeight;
	int bossWidth;
	int playerHeight;
	int playerWidth;

	void lookForPlayer();

};

#endif //!_WITCH_AI_H