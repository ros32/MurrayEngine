#ifndef _FYSICS_
#define _FYSICS

#include "Map.h"

class Fysics{

public:
	Fysics(Map* map);
	~Fysics();

	void calculateImpact(Object* objA, Object* objB);
	void calculatePull(Object* objA, Object* objB, int maxDistance);


private:
	Object* objA;
	Object* objB;
	Map* map;
	Orientation aDirection;
	Orientation bDirection;

};



#endif //!_FYSICS