#ifndef _GENERIC_OBJECT_FACTORY_H
#define	_GENERIC_OBJECT_FACTORY_H

#include	"GenericObject.h"
#include	"Configuration.h"
#include	<vector>

class GenericObjectFactory
{
public:
	GenericObjectFactory();
	GenericObjectFactory(Configuration config);
	~GenericObjectFactory();

	bool						loadConfiguration(Configuration config);

	std::vector<GenericObject>	createObjects();

private:

	Configuration	factoryConfiguration;

};

#endif // !_GENERIC_OBJECT_FACTORY_H
