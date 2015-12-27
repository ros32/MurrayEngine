#include "InputControl.h"

InputControl::InputControl(){
	this->keyState;
}

InputControl::~InputControl(){

}

Action* InputControl::inputHandler(){

	Action* tempAction = NULL;
	const Uint8*	currentKeyState = SDL_GetKeyboardState(NULL);


	
	if (currentKeyState[SDL_GetScancodeFromKey(SDLK_SPACE)])	
		this->keyState.key_space = true;
	else
		this->keyState.key_space = false;
	if (currentKeyState[SDL_GetScancodeFromKey(SDLK_KP_ENTER)])
		this->keyState.key_enter = true;
	else
		this->keyState.key_enter = false;
	if (currentKeyState[SDL_GetScancodeFromKey(SDLK_m)])
		this->keyState.key_m = true;
	else
		this->keyState.key_m = false;

	if (keyState.key_space){
		SDL_Log("Pressed Space");
		return buttonSpace;
	}
	if (keyState.key_enter){
		SDL_Log("Pressed Enter");
		return buttonEnter;
	}
	if (keyState.key_m){
		SDL_Log("Pressed M");
		return buttonM;
	}


	return NULL;
}
