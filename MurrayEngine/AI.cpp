#include	"AI.h"

AI::AI()
{
	npc = nullptr;
	map = nullptr;
}

AI::AI(Object* npc, Map* map)
{
	this->npc = npc;
	this->map = map;
}

AI::~AI()
{

}

void	AI::doNext()
{
	if (npc != nullptr)
	{
		//	Let implementation handle this logic
	}
}

Object*	AI::getSourceNPC()
{
	return this->npc;
}

void	AI::setSourceNPC(Object* npc)
{
	this->npc = npc;
}

void	AI::setMap(Map* map)
{
	this->map = map;
}

Map*	AI::getMap()
{
	return this->map;
}