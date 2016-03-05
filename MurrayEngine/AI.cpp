#include	"AI.h"

AI::AI()
{
	npc = nullptr;
	map = nullptr;
}

AI::AI(NonPlayerCharacter* npc, Map* map)
{
	this->npc = npc;
	this->map = map;
}

AI::~AI()
{

}

NonPlayerCharacter*	AI::getSourceNPC()
{
	return this->npc;
}

void	AI::setSourceNPC(NonPlayerCharacter* npc)
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