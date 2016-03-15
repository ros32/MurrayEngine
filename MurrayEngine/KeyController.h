#ifndef _KEY_CONTROLLER_H
#define	_KEY_CONTROLLER_H

#include	<map>
#include	"GameInstance.h"
#include	"ChangeInputModeAction.h"
#include	"Object.h"

class GameInstance;

class KeyController
{
public:
	KeyController();
	~KeyController();

	void	checkState();

	void	addAction(SDL_Scancode key, Action* action, bool repeat);

	void	setGameInstance(GameInstance* instance);

	void	setTextInputMode(bool inputMode);

	bool	getTextInputMode();

private:

	GameInstance*					gameInstance;

	Object*							playerCharacter;

	std::map< SDL_Scancode, bool >	keys;
	std::map< SDL_Scancode, char >	chars;
	std::map< SDL_Scancode, bool >	lastStatus;
	std::map< SDL_Scancode, bool >	repeat;
	std::map< SDL_Scancode, Action* >	actions;

	void	debugSetup();

	bool	textInputMode;



};

#endif
