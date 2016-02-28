#ifndef _AI_H
#define	_AI_H

#include	<vector>
#include	"Object.h"
#include	"Map.h"

class NonPlayerCharacter;
class Map;

class AI
{
public:
	AI();
	AI(Object* npc, Map* map);
	~AI();

	virtual void		doNext();

	void				setSourceNPC(Object* npc);
	Object*				getSourceNPC();

	void				setMap(Map* map);
	Map*				getMap();

private:

	Object*	npc;
	Map*				map;

};

#endif // !_AI_HJ
