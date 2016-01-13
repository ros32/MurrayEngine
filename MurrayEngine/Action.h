/*
The Action interface
*/

#ifndef _ACTION_H
#define _ACTION_H

#include "GenericObject.h"

class GenericObject;

class Action{

public:
	Action();
	~Action();

	virtual void execute() = 0;

	bool	isCompleted();

	double	getProgress();
	void	setProgress(double progress);
	void	updateProgress(double progress);


private:

	GenericObject* source;

	double progress;

};

 #endif // !_ACTION_H