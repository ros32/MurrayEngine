#include	"KeyController.h"

KeyController::KeyController()
{
	this->keys;

	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_0, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_1, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_2, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_3, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_4, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_5, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_6, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_7, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_8, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_9, false));

	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_A, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_B, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_C, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_D, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_E, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_G, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_H, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_I, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_J, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_K, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_L, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_M, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_N, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_O, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_P, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_Q, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_R, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_S, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_T, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_U, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_V, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_W, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_X, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_Y, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_Z, false));

	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_LALT, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_LCTRL, false));

	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_RALT, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_RCTRL, false));

	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_SPACE, false));

	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_ESCAPE, false));

	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_TAB, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_CAPSLOCK, false));

	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F1, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F2, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F3, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F4, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F5, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F6, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F7, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F8, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F9, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F10, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F11, false));
	this->keys.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F12, false));

	this->actions;

	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_0, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_1, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_2, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_3, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_4, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_5, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_6, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_7, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_8, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_9, nullptr));

	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_A, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_B, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_C, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_D, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_E, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_F, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_G, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_H, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_I, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_J, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_K, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_L, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_M, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_N, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_O, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_P, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_Q, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_R, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_S, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_T, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_U, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_V, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_W, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_X, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_Y, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_Z, nullptr));

	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_LALT, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_LCTRL, nullptr));

	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_RALT, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_RCTRL, nullptr));

	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_SPACE, nullptr));

	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_ESCAPE, nullptr));

	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_TAB, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_CAPSLOCK, nullptr));

	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_F1, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_F2, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_F3, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_F4, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_F5, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_F6, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_F7, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_F8, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_F9, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_F10, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_F11, nullptr));
	this->actions.insert(std::map<SDL_Scancode, Action*>::value_type(SDL_SCANCODE_F12, nullptr));

	this->lastStatus;

	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_0, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_1, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_2, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_3, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_4, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_5, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_6, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_7, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_8, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_9, false));

	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_A, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_B, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_C, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_D, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_E, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_G, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_H, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_I, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_J, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_K, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_L, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_M, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_N, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_O, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_P, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_Q, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_R, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_S, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_T, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_U, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_V, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_W, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_X, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_Y, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_Z, false));

	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_LALT, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_LCTRL, false));

	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_RALT, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_RCTRL, false));

	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_SPACE, false));

	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_ESCAPE, false));

	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_TAB, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_CAPSLOCK, false));

	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F1, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F2, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F3, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F4, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F5, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F6, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F7, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F8, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F9, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F10, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F11, false));
	this->lastStatus.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F12, false));

	this->repeat;

	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_0, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_1, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_2, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_3, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_4, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_5, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_6, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_7, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_8, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_9, false));

	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_A, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_B, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_C, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_D, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_E, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_G, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_H, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_I, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_J, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_K, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_L, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_M, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_N, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_O, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_P, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_Q, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_R, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_S, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_T, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_U, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_V, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_W, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_X, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_Y, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_Z, false));

	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_LALT, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_LCTRL, false));

	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_RALT, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_RCTRL, false));

	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_SPACE, false));

	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_ESCAPE, false));

	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_TAB, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_CAPSLOCK, false));

	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F1, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F2, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F3, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F4, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F5, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F6, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F7, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F8, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F9, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F10, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F11, false));
	this->repeat.insert(std::map<SDL_Scancode, bool>::value_type(SDL_SCANCODE_F12, false));
	
}

KeyController::~KeyController()
{
	for (auto key : this->actions)
	{
		delete key.second;
	}
}

void	KeyController::checkState()
{
	
	
	const Uint8*	currentKeyState = SDL_GetKeyboardState(NULL);
	std::string tempS;


	for (auto key : this->keys)
	{
		if (currentKeyState[key.first] && (this->repeat[key.first] || !this->lastStatus[key.first]))
		{
			this->keys[key.first] = true;
		}
		else
		{
			this->keys[key.first] = false;
		}
		this->lastStatus[key.first] = (currentKeyState[key.first]) ? true : false;
	}

	for (auto key : this->actions)
	{
		if (this->keys[key.first] && key.second != nullptr)
		{		
			key.second->execute();
		}	
	}
}

void	KeyController::setGameInstance(GameInstance* instance)
{
	this->gameInstance = instance;

	if (this->gameInstance != nullptr && this->gameInstance->getMap() != nullptr)
		this->playerCharacter = this->gameInstance->getMap()->getPlayerCharacter();
	else
		this->playerCharacter = nullptr;

	//	Set up basic controls if not defined
	bool	keysDefined = false;
	for (auto key : this->actions)
	{
		if (key.second != nullptr)
		{
			keysDefined = true;
			break;
		}
	}
	if (!keysDefined)
		this->debugSetup();
}

void	KeyController::addAction(SDL_Scancode key, Action* action, bool repeat)
{
	this->actions[key] = action;
	this->repeat[key] = repeat;
}

void	KeyController::debugSetup()
{
	/*
	this->actions[SDL_SCANCODE_W] = new MoveAction(this->gameInstance->getMap()->getPlayerCharacter(), this->gameInstance->getMap(), NORTH);
	this->actions[SDL_SCANCODE_S] = new MoveAction(this->gameInstance->getMap()->getPlayerCharacter(), this->gameInstance->getMap(), SOUTH);
	this->actions[SDL_SCANCODE_D] = new MoveAction(this->gameInstance->getMap()->getPlayerCharacter(), this->gameInstance->getMap(), EAST);
	this->actions[SDL_SCANCODE_A] = new MoveAction(this->gameInstance->getMap()->getPlayerCharacter(), this->gameInstance->getMap(), WEST);
	this->actions[SDL_SCANCODE_SPACE] = new DamageAction(this->gameInstance->getMap()->getPlayerCharacter(),this->gameInstance->getMap());
	this->repeat[SDL_SCANCODE_W] = true;
	this->repeat[SDL_SCANCODE_S] = true;
	this->repeat[SDL_SCANCODE_A] = true;
	this->repeat[SDL_SCANCODE_D] = true;
	*/
}

void	KeyController::setTextInputMode(bool inputMode)
{
	this->textInputMode = inputMode;
}

bool	KeyController::getTextInputMode()
{
	return this->textInputMode;
}