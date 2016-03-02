#define _CRTDBG_MAP_ALLOC
#include	"GameInstance.h"

#define		DEFAULT_FRAME_LIMIT		30

GameInstance::GameInstance()
{
	
}

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
	this->keyState;
	this->factory = nullptr;
	this->keyController = nullptr;
	this->objectFactory = nullptr;
}

GameInstance::~GameInstance()
{
	delete this->frameRateGUIObject;

	//	Delete texture assets
	for (auto asset : this->textureAssets)
	{
		delete asset.second;
	}

	this->textureAssets.clear();

	for (auto asset : this->assets)
	{
		delete asset.second;
	}

	this->assets.clear();

	//	Delete map
	delete this->map;

	//	Delete key controller
	delete this->keyController;

	//	Delete factory
	if (this->factory != nullptr)
		delete this->factory;

	if (this->objectFactory != nullptr)
		delete this->objectFactory;

}

bool GameInstance::initialize()
{
	bool tempFactory = false;
	bool tempKeyController = false;
	bool tempObjFactory = false;

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
	}
	if (this->objectFactory == nullptr)
	{
		tempObjFactory = true;
		this->objectFactory = new ObjectFactory(this);

		std::string output = "No ObjectFactory defined, creating default temporary.";
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, output.c_str());
	}
	else
	{
		std::string output = "Using defined objectFactory";
		SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, output.c_str());
	}


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

	this->factory->setGameInstance(this);

	std::vector<Configuration>	configurations;
	bool	mapLoaded = false;

	//	Load configurations
	for (auto key : this->mainConfig)
	{
		// bool	keyIdentified = false;
		std::size_t found = key.first.find("_CONFIG");
		if (found != std::string::npos)
		{
			// keyIdentified = true;
			std::string fileName = key.second;
			Configuration newConfig = Configuration(fileName);
			if (newConfig.getProperty("NAME", "NOTFOUND") != "NOTFOUND")
				this->configurations.insert(std::map<std::string, Configuration>::value_type(newConfig.getProperty("NAME", "NOTFOUND"), newConfig));
		}

	}

	//	Load assets
	for (auto key : this->configurations)
	{
		Configuration config = key.second;
		const std::string type = config.getProperty("TYPE", "UNKNOWN");

		if (type == "TextureAsset")
		{
			//TextureAssetFactory assetFactory = TextureAssetFactory(this->instanceRenderer);
			TextureAsset* tempAsset = this->factory->createAsset(config);
			//	HACK: Create class InvalidAsset and use for invalid assets
			//if (tempAsset.getType() != "InvalidAsset")
			//{
				this->textureAssets.insert(std::map<std::string, TextureAsset*>::value_type(config.getProperty("NAME", "UNKNOWN"), tempAsset));
				SDL_Log("Asset Loaded");
			//}
		}
		else if (type == "SoundAsset")
		{

		}
		else if (type == "Map")
		{

		}
	}


	//	Load map
	for (auto key : this->configurations)
	{
		if (key.second.getProperty("TYPE", "UNKNOWN") == "Map")
		{
			//MapFactory mapFactory = MapFactory(this->instanceWindow, this->instanceRenderer, this);
			if (!mapLoaded)
			{
				this->setMap(this->factory->createMap(key.second));


				objectFactory->init();
				objectFactory->createGhost("Evolved", SOUTH, { 33, 350 });
				
				mapLoaded = true;
			}
		}
	
	
	}
	/*
	
	
	
	for (auto key : this->configurations)
	{
		Configuration config = key.second;
		if (config.getProperty("TYPE", "UNKNOWN") == "Object")
		{
			Object* tempObject = this->objectFactory->createObject(config);

			this->tempHolder.push_back(tempObject);

		}
	}

	for (auto key : this->configurations)
	{
		Configuration config = key.second;
		if (config.getProperty("TYPE", "UNKNOWN") == "Animation")
		{

			if (tempMap.size() > 0){
				tempMap.clear();
			}

			tempMap = this->objectFactory->createAnimation(config);

			for (auto obj : tempHolder)
			{
				std::string objID = obj->getId();
				SDL_Log(objID.c_str());

				if (objID.find(key.second.getProperty("ID", "UNKNOWN")))
				{

					for (auto v : tempMap)
					{
						std::string identifier = v.first;

						std::vector<std::shared_ptr<Texture>> vec = v.second;
						obj->addAnimation(identifier, std::make_shared<Animation>(vec, 200));

						this->map->addObject(obj);
	
					}

				}
			}

		}
	}

	*/


	//	Test map

	//	Everything initialized below this point

	//	Set game instance on key controller. If we do this before things might be missing from GameInstance, causing
	//	strange behaviour
	this->keyController->setGameInstance(this);

	if (tempFactory)
	{
		delete this->factory;
		this->factory = nullptr;

		std::string output = "Removing temporary factory";
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, output.c_str());
	}

	if (tempObjFactory){
		delete this->objectFactory;
		this->objectFactory = nullptr;
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
