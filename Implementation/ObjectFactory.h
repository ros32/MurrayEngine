#ifndef _OBJECT_FACTORY_H
#define	_OBJECT_FACTORY_H

#include	"GameInstance.h"
#include	"Factory.h"
#include	"DefaultAI.h"
#include	"WitchAI.h"
#include	"ExtendedCollisionAction.h"

class ExtendedCollisionAction;

class GameInstance;

///-------------------------------------------------------------------------------------------------
/// <summary>	The ObjectFactory class is an extension of the default Factory class in the Engine,
/// 			and includes several methods to create game objects. </summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
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
