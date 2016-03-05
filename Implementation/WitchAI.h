#ifndef _WITCH_AI_H
#define _WITCH_AI_H

#include "AI.h"
#include "DamageAction.h"

class WitchAI : public AI{

public:
	WitchAI();
	WitchAI(NonPlayerCharacter* npc, Map* map);
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

};

#endif //!_WITCH_AI_H