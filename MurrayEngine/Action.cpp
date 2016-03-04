#include	"Action.h"

Action::Action()
{
	this->progress = 0;
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