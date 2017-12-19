#include	"Action.h"

Action::Action()
{
	this->progress = 0;
}

Action::~Action()
{

}

bool	Action::isCompleted() const
{
	return (this->progress >= 1);
}

void	Action::setProgress(const double progress)
{
	this->progress = progress;
}

void	Action::updateProgress(const double progress)
{
	this->progress += progress;
}