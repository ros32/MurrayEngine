#define _CRTDBG_MAP_ALLOC
#include	"Action.h"

Action::Action()
{
	this->progress = 0;
	this->source = nullptr;
}

Action::~Action()
{

}

bool	Action::isCompleted()
{
	return (this->progress >= 1);
}

void	Action::setProgress(double progress)
{
	this->progress = progress;
}

void	Action::updateProgress(double progress)
{
	this->progress += progress;
}