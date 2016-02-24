#ifndef _AI_H
#define	_AI_H

#include	<vector>
#include	"NonPlayerCharacter.h"
#include	"Map.h"

class NonPlayerCharacter;
class Map;

class AI
{
public:
	AI();
	AI(NonPlayerCharacter* npc, Map* map);
	~AI();

	virtual void		doNext();

	void				setSourceNPC(NonPlayerCharacter* npc);
	NonPlayerCharacter*	getSourceNPC();

	void				setMap(Map* map);
	Map*				getMap();

private:

	NonPlayerCharacter*	npc;
	Map*				map;

};

#endif // !_AI_HJ
