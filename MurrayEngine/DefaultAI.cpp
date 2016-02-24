#include "DefaultAI.h"

DefaultAI::DefaultAI() : AI()
{
	this->lastMovePosition = { 0, 0 };
	this->lastMoveSuccess = true;
}

DefaultAI::DefaultAI(NonPlayerCharacter* npc, Map* map) : AI(npc, map)
{
	this->lastMovePosition = { 0, 0 };
	this->lastMoveSuccess = true;
}

void	DefaultAI::doNext()
{
	NonPlayerCharacter* npc = AI::getSourceNPC();

	if (npc != nullptr)
	{
		Position	targetPosition;

		const int width = npc->getTexture().asset->getWidth();
		const int height = npc->getTexture().asset->getHeight();

		//	Check if last move was successful
		if (npc->getCurrentPosition().x == this->lastMovePosition.x && npc->getCurrentPosition().y == this->lastMovePosition.y)
			lastMoveSuccess = false;
		else
			lastMoveSuccess = true;


		if (lastMoveSuccess)
		{
			switch (npc->getOrientation())
			{
			case NORTH:
				break;
			case SOUTH:
				break;
			case EAST:
				break;
			case WEST:
				break;
			default:
				break;
			}
		}
	}
}