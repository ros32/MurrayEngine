#include	"KeyController.h"

KeyController::KeyController()
{
	this->gameInstance = nullptr;

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

	this->chars;

	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_0, '0'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_1, '1'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_2, '2'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_3, '3'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_4, '4'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_5, '5'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_6, '6'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_7, '7'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_8, '8'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_9, '9'));

	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_A, 'A'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_B, 'B'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_C, 'C'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_D, 'D'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_E, 'E'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_F, 'F'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_G, 'G'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_H, 'H'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_I, 'I'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_J, 'J'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_K, 'K'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_L, 'L'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_M, 'M'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_N, 'N'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_O, 'O'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_P, 'P'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_Q, 'Q'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_R, 'R'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_S, 'S'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_T, 'T'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_U, 'U'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_V, 'V'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_W, 'W'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_X, 'X'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_Y, 'Y'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_Z, 'Z'));
	this->chars.insert(std::map<SDL_Scancode, char>::value_type(SDL_SCANCODE_SPACE, ' '));



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

	this->textInputMode = false;
	
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
	if (this->gameInstance != nullptr && this->gameInstance->getMap() != nullptr)
	{
		const Uint8*	currentKeyState = SDL_GetKeyboardState(NULL);

		for (auto key : this->keys)
		{
			if (currentKeyState[key.first] && (this->repeat[key.first] || !this->lastStatus[key.first]))
			{
				this->keys[key.first] = true;
				if (this->textInputMode)
					this->keys[key.first] = (currentKeyState[key.first] != this->lastStatus[key.first]);
			}
			else
			{
				this->keys[key.first] = false;
			}
			this->lastStatus[key.first] = (currentKeyState[key.first]) ? true : false;
		}
		if (this->textInputMode)
		{
			if (keys[SDL_SCANCODE_BACKSPACE])
				this->gameInstance->getMap()->getCamera()->getGUI()->getInputObject()->removeChar();
			else if (keys[SDL_SCANCODE_RETURN] || keys[SDL_SCANCODE_RETURN2])
			{
				this->textInputMode = false;
			}
			else
			{
				for (auto key : this->chars)
				{
					if (this->keys[key.first])
					{
						this->gameInstance->getMap()->getCamera()->getGUI()->getInputObject()->addChar(key.second);
					}
				}
			
			}

		}
		else
		{
			for (auto key : this->actions)
			{
				if (this->keys[key.first] && key.second != nullptr)
				{		
					key.second->execute();
				}	
			}
		}
	}
}

void	KeyController::setGameInstance(GameInstance* instance)
{
	this->gameInstance = instance;
}

void	KeyController::addAction(SDL_Scancode key, Action* action, bool repeat)
{
	this->actions[key] = action;
	this->repeat[key] = repeat;
}

void	KeyController::setTextInputMode(bool inputMode)
{
	this->textInputMode = inputMode;
}

bool	KeyController::getTextInputMode()
{
	return this->textInputMode;
}