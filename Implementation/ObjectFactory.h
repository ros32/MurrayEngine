#ifndef _OBJECTFACTORY_
#define	_OBJECTFACTORY_

#include	"Configuration.h"
#include	"Object.h"
#include	"Factory.h"



class ObjectFactory : public Factory
{

public:
	ObjectFactory();
	~ObjectFactory();

	Object*	 createObject(Configuration config);
	std::shared_ptr<Animation> createAnimation(Configuration config);

private:

	Configuration config;
	Animation animation;
};





#endif !_OBJECTFACTORY_