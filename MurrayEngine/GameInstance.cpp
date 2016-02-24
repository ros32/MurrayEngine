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
}

GameInstance::~GameInstance()
{

}

bool GameInstance::initialize()
{
	bool tempFactory = false;
	bool tempKeyController = false;

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

			if (newConfig.getProperty("NAME", "NOTFOUND") == "WitchSpritesheet"){
				SDL_Log("WitchSpriteSheet Loaded");
			}
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

				//				Object* tempObject = new Object("test001", { 100, 100 }, Texture(this->getTextureAsset("tileset"), "TreeM"), 1.0, 1.0, 5, NORTH, true);
				//				this->map->addObject(tempObject);
				//				this->map->setPlayerCharacter(tempObject);	


				//Set up player animations for north, south, east and west
				std::vector<Texture> playerNorth;
				playerNorth.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroBack1"));
				playerNorth.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroBack2"));
				playerNorth.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroBack3"));
				playerNorth.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroBack2"));
				playerNorth.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroBack1"));
				playerNorth.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroBack4"));
				playerNorth.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroBack5"));
				playerNorth.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroBack4"));


				std::vector<Texture> playerSouth;
				playerSouth.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroFront1"));
				playerSouth.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroFront2"));
				playerSouth.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroFront3"));
				playerSouth.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroFront2"));
				playerSouth.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroFront1"));
				playerSouth.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroFront4"));
				playerSouth.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroFront5"));
				playerSouth.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroFront4"));


				std::vector<Texture> playerLeft;
				playerLeft.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroLeft1"));
				playerLeft.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroLeft2"));
				playerLeft.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroLeft3"));
				playerLeft.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroLeft4"));
				playerLeft.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroLeft3"));
				playerLeft.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroLeft2"));

				std::vector<Texture> playerRight;
				playerRight.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroRight1"));
				playerRight.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroRight2"));
				playerRight.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroRight3"));
				playerRight.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroRight4"));
				playerRight.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroRight3"));
				playerRight.push_back(Texture(this->getTextureAsset("HeroSpriteSheet"), "HeroRight2"));
		
				NonPlayerCharacter* HeroPlayer = new NonPlayerCharacter(new AnimatedObject("test006", { 120, 250 }, Animation(playerSouth, 200), 1.0, 1.0, 3, SOUTH, true));
				
				HeroPlayer->addAnimation("North", Animation(playerNorth, 200));
				HeroPlayer->addAnimation("South", Animation(playerSouth, 200));
				HeroPlayer->addAnimation("East", Animation(playerRight, 200));
				HeroPlayer->addAnimation("West", Animation(playerLeft, 200));
				


				this->map->addObject(HeroPlayer);
				this->map->setPlayerCharacter(HeroPlayer);
				

				std::vector<Texture> witchCraft;
				witchCraft.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "WalkingFront0"));
				witchCraft.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "WalkingFront1"));
				witchCraft.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "WalkingFront2"));
				witchCraft.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "WalkingFront3"));


				//AnimatedObject* witchPlayerObject = new AnimatedObject("test006", { 100, 250 }, Animation(witchCraft, 200), 1.0, 1.0, 3, SOUTH, true);

				//this->map->addObject(witchPlayerObject);
				//this->map->setPlayerCharacter(witchPlayerObject);

				SDL_Log("Testutskrift");




				std::vector<Texture> textures;
				textures.push_back(Texture(this->getTextureAsset("tileset"), "TreeD"));
				textures.push_back(Texture(this->getTextureAsset("tileset"), "TreeM"));
				textures.push_back(Texture(this->getTextureAsset("tileset"), "TreeL"));


				AnimatedObject* animatedObject = new AnimatedObject("test003", { 160, 350 }, Animation(textures, 200), 1.0, 1.0, 2, NORTH, true);
				NonPlayerCharacter* granges = new NonPlayerCharacter(animatedObject);
				granges->setAI(new DefaultAI(granges, this->map));

				this->map->addObject(granges);


				std::vector<Texture> witchTextures;
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft0"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft1"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft2"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft3"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft4"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft5"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft6"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft7"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft8"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft9"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft10"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft11"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft12"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft13"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft11"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft12"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft13"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft11"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft12"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft13"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft11"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft12"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft13"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft14"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft15"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft16"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft17"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft18"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft19"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft20"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft19"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft18"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft17"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft16"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft15"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft14"));
				witchTextures.push_back(Texture(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft0"));


				AnimatedObject* witchObject = new AnimatedObject("test004", { 1095, 1095 }, Animation(witchTextures, 200), 1.0, 1.0, 0, NONE, true);
				this->map->addObject(witchObject);


				mapLoaded = true;
			}
		}
	
	
	}


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