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
}

GameInstance::~GameInstance()
{

}

bool GameInstance::initialize()
{

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
			Configuration newConfig = Configuration(key.second);
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
			TextureAssetFactory assetFactory = TextureAssetFactory(this->instanceRenderer);
			TextureAsset* tempAsset = assetFactory.createAsset(config);
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
			MapFactory mapFactory = MapFactory(this->instanceWindow, this->instanceRenderer, this);
			if (!mapLoaded)
			{
				this->setMap(mapFactory.createMap(key.second));
				GenericObject* tempObject = new GenericObject("test001", { 100, 100 }, this->getTextureAsset("tileset"), "TreeM", 1.0, 1.0, 1, NORTH, false);
				this->map->addObject(tempObject);
				this->map->setPlayerCharacter(tempObject);
				
				mapLoaded = true;
			}
		}
	
	
	}


	//	Test map




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

		//	Handle keys
		const Uint8*	currentKeyState = SDL_GetKeyboardState(NULL);

		if (currentKeyState[SDL_GetScancodeFromKey(SDLK_w)])
			this->keyState.key_w = true;
		else
			this->keyState.key_w = false;
		if (currentKeyState[SDL_GetScancodeFromKey(SDLK_s)])
			this->keyState.key_s = true;
		else
			this->keyState.key_s = false;
		if (currentKeyState[SDL_GetScancodeFromKey(SDLK_a)])
			this->keyState.key_a = true;
		else
			this->keyState.key_a = false;
		if (currentKeyState[SDL_GetScancodeFromKey(SDLK_d)])
			this->keyState.key_d = true;
		else
			this->keyState.key_d = false;
		if (currentKeyState[SDL_GetScancodeFromKey(SDLK_LEFT)])
			this->keyState.key_left = true;
		else
			this->keyState.key_left = false;
		if (currentKeyState[SDL_GetScancodeFromKey(SDLK_RIGHT)])
			this->keyState.key_right = true;
		else
			this->keyState.key_right = false;
		if (currentKeyState[SDL_GetScancodeFromKey(SDLK_UP)])
			this->keyState.key_up = true;
		else
			this->keyState.key_up = false;
		if (currentKeyState[SDL_GetScancodeFromKey(SDLK_DOWN)])
			this->keyState.key_down = true;
		else
			this->keyState.key_down = false;


		if (keyState.key_w)
		{
			if (this->map->getCamera() != nullptr)
			{
				if (this->map->getCamera()->getFocusType() == FREE_FOCUS)
					this->map->getCamera()->move(0, -5);
				else if (this->map->getCamera()->getFocusType() == OBJECT_FOCUS)
					this->map->getPlayerCharacter()->setTargetPosition(0, -5);
			}
		}
		if (keyState.key_s)
		{
			if (this->map->getCamera() != nullptr)
			{
				if (this->map->getCamera()->getFocusType() == FREE_FOCUS)
					this->map->getCamera()->move(0, 5);
				else if (this->map->getCamera()->getFocusType() == OBJECT_FOCUS)
					this->map->getPlayerCharacter()->setTargetPosition(0, 5);
			}
		}
		if (keyState.key_a)
		{
			if (this->map->getCamera() != nullptr)
			{
				if (this->map->getCamera()->getFocusType() == FREE_FOCUS)
					this->map->getCamera()->move(-5, 0);
				else if (this->map->getCamera()->getFocusType() == OBJECT_FOCUS)
					this->map->getPlayerCharacter()->setTargetPosition(-5, 0);
			}
		}
		if (keyState.key_d)
		{
			if (this->map->getCamera() != nullptr)
			{
				if (this->map->getCamera()->getFocusType() == FREE_FOCUS)
					this->map->getCamera()->move(5, 0);
				else if (this->map->getCamera()->getFocusType() == OBJECT_FOCUS)
					this->map->getPlayerCharacter()->setTargetPosition(5, 0);
			}
		}
		//	if (keyState.key_left)
			//set an objects orientation to west
		//	if (keyState.key_right)
			//set an objects orientation to east
		//	if (keyState.key_up)
			//set an objects orientation to north
		//	if (keyState.key_down)
			//set an objects orientation to south
		

		//	const Uint8* keyState = SDL_GetKeyboardState(NULL);
	//	if (keyState[SDLK_w])
	//		this->map.getCamera()->move(0, -1);
		
		//	Clear renderer
		SDL_RenderClear(this->instanceRenderer);
		this->moveObjects();
		this->renderObjects();
		SDL_RenderPresent(this->instanceRenderer);

		this->frameLimiter.limit();
	}

	this->runned = true;
	return true;
}

bool GameInstance::exit()
{

	//	Delete texture assets
	for (auto asset : this->textureAssets)
	{
		delete asset.second;
	}

	//	Delete map
	delete this->map;

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