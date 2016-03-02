#ifndef _KEY_CONTROLLER_H
#define	_KEY_CONTROLLER_H

#include	<map>
#include	<SDL.h>
#include	"Action.h"
#include	"GameInstance.h"
#include	"DamageAction.h"
#include	"CopyAction.h"

class KeyController
{
public:
	KeyController();
	~KeyController();

	void	checkState();

	void	addAction(SDL_Scancode key, Action* action);

	void	setGameInstance(GameInstance* instance);

private:

	GameInstance*					gameInstance;

	Object*							playerCharacter;

	std::map<SDL_Scancode, bool>	keys;
	std::map<SDL_Scancode, Action*>	actions;

	void	debugSetup();

	bool wasPressed;



};


#endif // !_KEY_CONTROLLER_H
