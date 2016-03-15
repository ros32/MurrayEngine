#ifndef _OBJECT_FACTORY_H
#define	_OBJECT_FACTORY_H

#include	"GameInstance.h"
#include	"Factory.h"
#include	"DefaultAI.h"
#include	"WitchAI.h"
#include	"ExtendedCollisionAction.h"

class ExtendedCollisionAction;

class GameInstance;
class ObjectFactory: public Factory
{
public:
	ObjectFactory();
	~ObjectFactory();

	Map*					createMap(Configuration configuration);

	NonPlayerCharacter*		createNonPlayerCharacter(std::string type, std::string id, Orientation direction, Position pos);

	void					createPlayer(Map* map, Orientation direction, Position pos);
	void					createGhost(Map* map, Orientation direction, Position pos);
	void					createEvolvedGhost(Map* map, Orientation direction, Position pos);
	void					createWitch(Map* map, Orientation direction, Position pos);

private:

	int counter;
};

#endif // !_OBJECT_FACTORY_H
