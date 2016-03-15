#include	"GameInstance.h"

#define		DEFAULT_FRAME_LIMIT		30

GameInstance::GameInstance(SDL_Window* window, SDL_Renderer* renderer, Configuration configuration)
{
	this->frameLimiter = FrameLimiter(Timer(), configuration.getProperty("FRAME_LIMIT", DEFAULT_FRAME_LIMIT));
	this->instanceWindow = window;
	this->instanceRenderer = renderer;
	this->initialized = false;
	this->runned = false;
	this->exited = false;
	this->mainConfig = configuration;
	this->configurations;
	this->map;
	this->factory = nullptr;
	this->keyController = nullptr;
	this->inputGUIObject = new InputGUIObject(renderer, { 64, 32 });
}

GameInstance::~GameInstance()
{
	delete this->frameRateGUIObject;

	//	Delete texture assets
	for (auto asset : this->textureAssets)
	{
		delete asset.second;
	}

	//	Delete map
	delete this->map;

	//	Delete key controller
	delete this->keyController;

	//	Delete factory
	if (this->factory != nullptr)
		delete this->factory;

}

bool GameInstance::initialize()
{
	bool tempFactory = false;
	bool tempKeyController = false;
	bool tempObjFactory = false;

	//	Create a default Factory object if no Factory has been provided
	if (this->factory == nullptr)
	{
		tempFactory = true;
		this->factory = new Factory();
		this->factory->setWindow(this->instanceWindow);

		std::string output = "No Factory defined, creating default temporary.";
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, output.c_str());
	}
	else
	{
		std::string output = "Using defined factory";
		SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, output.c_str());
		if (this->factory->getWindow() == nullptr)
			this->factory->setWindow(this->instanceWindow);
	}

	//	Create a default KeyController if no KeyController has been provided
	if (this->keyController == nullptr)
	{
		tempKeyController = true;
		this->keyController = new KeyController();

		std::string output = "No Key Controller defined, creating default.";
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, output.c_str());
	}
	else
	{
		std::string output = "Using defined key controller";
		SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, output.c_str());
	}

	//	Set GameInstance call-back on Factory
	this->factory->setGameInstance(this);

	std::vector<Configuration>	configurations;
	bool	mapLoaded = false;

	//	Load configurations
	for (auto key : this->mainConfig)
	{
		//	Configuration files are identified by having _CONFIG at the end of the key
		std::size_t found = key.first.find("_CONFIG");
		if (found != std::string::npos)
		{
			std::string fileName = key.second;
			Configuration newConfig = Configuration(fileName);

			//	All configuration files must have a NAME key defining its name, if not it will not be loaded
			if (newConfig.getProperty("NAME", "NOTFOUND") != "NOTFOUND")
				this->configurations.insert(std::map<std::string, Configuration>::value_type(newConfig.getProperty("NAME", "NOTFOUND"), newConfig));
		}

	}

	//	Load assets
	for (auto key : this->configurations)
	{
		Configuration config = key.second;

		//	An asset configuration file is defined by the key TYPE
		const std::string type = config.getProperty("TYPE", "UNKNOWN");

		//	If TYPE is TextureAsset, the file will be loaded
		if (type == "TextureAsset")
		{
			//	Create TextureAsset from configuration file
			TextureAsset* tempAsset = this->factory->createAsset(config);

			//	Insert asset into textureAssets
			this->textureAssets.insert(std::map<std::string, TextureAsset*>::value_type(config.getProperty("NAME", "UNKNOWN"), tempAsset));
		}
	}


	//	Map must be loaded separate from other assets in configurations, since it depends on all
	//	other assets already being loaded
	for (auto key : this->configurations)
	{
		if (key.second.getProperty("TYPE", "UNKNOWN") == "Map")
		{
			if (!mapLoaded)
			{
				this->setMap(this->factory->createMap(key.second));
				mapLoaded = true;
			}
		}
	}

	//	Everything initialized below this point

	//	GameInstance must be set on KeyController *AFTER* assets and map has been initialized,
	//	otherwise actions defined that depends on Object* will not have valid pointers
	this->keyController->setGameInstance(this);
	this->map->getCamera()->getGUI()->addObject(this->inputGUIObject);

	if (tempFactory)
	{
		delete this->factory;
		this->factory = nullptr;

		std::string output = "Removing temporary factory";
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, output.c_str());
	}

	this->frameRateGUIObject = new GUIObject({ 10, 10 }, nullptr);
	this->getMap()->getCamera()->getGUI()->addObject(this->frameRateGUIObject);

	this->initialized = true;
	return true;

}

bool GameInstance::run()
{
	while (1)
	{
		this->frameLimiter.start();
		//	Define SDL Event
		SDL_Event e;

		//	Poll for pending event into &e
		if (SDL_PollEvent(&e))
		{
			//	If Event Type is SDL_QUIT then break loop
			if (e.type == SDL_QUIT)
				break;
		}
		
		this->keyController->checkState();
		this->doActions();
		//	Clear renderer
		SDL_RenderClear(this->instanceRenderer);
		TextureAsset*	tempTexture = new TextureAsset(this->instanceRenderer, "8bitOperatorPlusSC-Bold.ttf", 24, std::to_string(frameLimiter.getAvgFrames()), { 255, 255, 255 });
		this->frameRateGUIObject->setTexture(tempTexture);
		
		this->moveObjects();
		this->renderObjects();
		SDL_RenderPresent(this->instanceRenderer);
		delete tempTexture;
		this->frameRateGUIObject->setTexture(nullptr);
		this->frameLimiter.limit();
	}

	this->runned = true;
	return true;
}

bool GameInstance::exit()
{

	this->exited = true;
	return true;
}

void GameInstance::loadConfigurations()
{

}

bool GameInstance::isInitialized()
{
	return this->initialized;
}

bool GameInstance::isRun()
{
	return this->runned;
}

bool GameInstance::isExited()
{
	return this->exited;
}

void GameInstance::moveObjects()
{
	this->map->move();
	if (this->map->getCamera()->getFocusType() == OBJECT_FOCUS)
		this->map->getCamera()->center(this->map->getPlayerCharacter()->getCurrentPosition());
}

void GameInstance::renderObjects()
{
	this->map->render();
	this->map->getCamera()->getGUI()->render();
}

TextureAsset*	GameInstance::getTextureAsset(std::string name)
{
	std::map<std::string, TextureAsset*>::iterator iterator;
	iterator = this->textureAssets.find(name);
	if (iterator != this->textureAssets.end())
		return iterator->second;
	return nullptr;
}

void			GameInstance::setMap(Map* map)
{
	this->map = map;
}

Factory*		GameInstance::getFactory()
{
	return this->factory;
}

void			GameInstance::setFactory(Factory* factory)
{
	this->factory = factory;
}

Map*			GameInstance::getMap()
{
	return this->map;
}

void			GameInstance::doActions()
{
	if (this->map != nullptr)
		this->map->doActionQueue();
}

KeyController*	GameInstance::getKeyController()
{
	return this->keyController;
}

InputGUIObject*	GameInstance::getInputObject()
{
	return this->inputGUIObject;
}