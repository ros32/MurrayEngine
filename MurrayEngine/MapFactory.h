#ifndef _MAP_FACTORY_H
#define	_MAP_FACTORY_H

#include "Configuration.h"
#include "Map.h"

class MapFactory
{
public:
	MapFactory();
	~MapFactory();

	Map		createMap(Configuration config);

private:

};

#endif // !_MAP_FACTORY_H
