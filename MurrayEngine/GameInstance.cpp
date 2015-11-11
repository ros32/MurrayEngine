#include	"GameInstance.h"

GameInstance::GameInstance()
{
	this->frameLimiter = FrameLimiter(Timer(), 30);
}

GameInstance::~GameInstance()
{

}

bool GameInstance::initialize()
{
	return false;
}

bool GameInstance::run()
{
	return false;
}

bool GameInstance::exit()
{
	return false;
}

void GameInstance::loadConfigurations()
{

}
