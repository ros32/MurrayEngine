#ifndef _GENERIC_OBJECT_FACTORY_H
#define	_GENERIC_OBJECT_FACTORY_H

#include	"Object.h"
#include	"Configuration.h"
#include	<vector>

class ObjectFactory
{
public:
	ObjectFactory();
	ObjectFactory(Configuration config);
	~ObjectFactory();

	bool						loadConfiguration(Configuration config);

	std::vector<Object>	createObjects();

private:

	Configuration	factoryConfiguration;

};

#endif // !_GENERIC_OBJECT_FACTORY_H
