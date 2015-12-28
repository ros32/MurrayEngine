/*
The Action interface
*/

#ifndef _ACTION_H
#define _ACTION_H

//#include "GameInstance.h"
#include "GenericObject.h"

class Action{

public:
//	virtual ~Action();

	virtual void execute() = 0;
//	virtual void execute(GenericObject* source) = 0;
//  virtual void execute(GameInstance* instance, GenericObject* sourceObject, std::vector<GenericObject*> targetObjects) = 0;

private:
	GenericObject* source;
};

 #endif // !_ACTION_H