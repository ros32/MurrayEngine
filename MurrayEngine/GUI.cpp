#include "GUI.h"

GUI::GUI()
{
	this->guiObjects;
}

GUI::~GUI()
{

}

std::vector<GUIObject*>	GUI::getGUIObjects()
{
	return this->guiObjects;
}

void	GUI::addObject(GUIObject* object)
{
	if (std::find(this->guiObjects.begin(), this->guiObjects.end(), object) == this->guiObjects.end())
	{
		this->guiObjects.push_back(object);

		std::string output = "GUI object at position: { " + std::to_string(object->getPosition().x) + ", " + std::to_string(object->getPosition().y) + " } was added.";
		SDL_LogVerbose(SDL_LOG_CATEGORY_APPLICATION, output.c_str());
	}
	else
	{
		std::string output = "GUI object at position: { " + std::to_string(object->getPosition().x) + ", " + std::to_string(object->getPosition().y) + " } was already exist!.";
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, output.c_str());
	}

}

void	GUI::removeObject(GUIObject* object)
{
	if (std::find(this->guiObjects.begin(), this->guiObjects.end(), object) != this->guiObjects.end())
	{
		delete object;
		this->guiObjects.erase(std::remove(this->guiObjects.begin(), this->guiObjects.end(), object));

		std::string output = "GUI object at position: { " + std::to_string(object->getPosition().x) + ", " + std::to_string(object->getPosition().y) + " } was added.";
		SDL_LogVerbose(SDL_LOG_CATEGORY_APPLICATION, output.c_str());
	}
	else
	{
		std::string output = "GUI object at position: { " + std::to_string(object->getPosition().x) + ", " + std::to_string(object->getPosition().y) + " } was already exist!.";
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, output.c_str());
	}
}

void	GUI::render()
{
	if (this->guiObjects.size() != 0)
	{
		for (GUIObject* object : this->guiObjects)
		{
			
			if (object != nullptr)
				object->getTexture()->render(object->getPosition().x, object->getPosition().y, NULL);
		}
	}
}