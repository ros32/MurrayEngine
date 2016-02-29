#include "ObjectFactory.h"

ObjectFactory::ObjectFactory(){

}
ObjectFactory::~ObjectFactory(){

}

Object*	 ObjectFactory::createObject(Configuration config){
	


	int id = 0;
	std::string objType = "";
	Position position = {0,0};
	//Animation
	double maxSpeed = config.getProperty("mSPEED", 0.0);
	double acceleration = config.getProperty("ACCELERATION", 0.0);
	int currentSpeed = config.getProperty("CURRENTSPEED", 0);
	int direction = config.getProperty("ORIENTATION", 0);
	bool isCollided = config.getProperty("ISCOLLIDABLE", true);

	std::string delimiter = "_";
	//	unsigned int offset = configuration.getProperty("OFFSET", 0);

	std::string s = config.getProperty("CURRENTPOSITION", "UNKNOWN");



	return nullptr;
}

std::shared_ptr < Animation> ObjectFactory::createAnimation(Configuration config){
	//IMAGE



	return nullptr;
}