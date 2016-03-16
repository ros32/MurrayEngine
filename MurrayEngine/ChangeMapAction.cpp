#include	"ChangeMapAction.h"

ChangeMapAction::ChangeMapAction(GameInstance* gameInstance, std::string mapName)
{
	this->gameInstance = gameInstance;
	this->mapName = mapName;
}

ChangeMapAction::~ChangeMapAction()
{

}

void	ChangeMapAction::execute()
{
	this->gameInstance->setMap(mapName);
}

Action*	ChangeMapAction::copy()
{
	return new ChangeMapAction(this->gameInstance, this->mapName);
}