#ifndef _OBJECT_FACTORY_H
#define	_OBJECT_FACTORY_H

#include	"GameInstance.h"

class GameInstance;
class ObjectFactory 
{
public:
	ObjectFactory(GameInstance* gameInstance);
	~ObjectFactory();

	void createGhostGroup(std::string type);
	void createGhost(std::string Id, Orientation orientation, Position pos);
	void createWitch();
	void createPlayer();
	void init();

	bool witchCreated, playerCreated, ghostCreated;

private:
	GameInstance* gameInstance;
	Orientation orientation;

	int counter;


	void clearVectors();
	void loadVectors(std::string type);

	std::vector<std::shared_ptr<Texture>> spawnV;
	std::vector<std::shared_ptr<Texture>> northV;
	std::vector<std::shared_ptr<Texture>> southV;
	std::vector<std::shared_ptr<Texture>> westV;
	std::vector<std::shared_ptr<Texture>> eastV;
	std::vector<std::shared_ptr<Texture>> inactiveV;
	std::vector<std::shared_ptr<Texture>> deathV;
	std::vector<std::shared_ptr<Texture>> projectileV;

};

#endif // !_OBJECT_FACTORY_H
