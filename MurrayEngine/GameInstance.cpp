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

			if (newConfig.getProperty("NAME", "NOTFOUND") == "ProjectileSheet"){
				SDL_Log("ProjectileSheet Loaded");
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
				std::vector<std::shared_ptr<Texture>> playerNorth;
				playerNorth.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "HeroBack1"));
				playerNorth.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "HeroBack2"));
				playerNorth.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "HeroBack1"));
				playerNorth.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "HeroBack3"));



				std::vector<std::shared_ptr<Texture>> playerSouth;
				playerSouth.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "HeroFront1"));
				playerSouth.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "HeroFront2"));
				playerSouth.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "HeroFront1"));
				playerSouth.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "HeroFront3"));



				std::vector<std::shared_ptr<Texture>> playerLeft;
				playerLeft.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "HeroLeft1"));
				playerLeft.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "HeroLeft2"));
				playerLeft.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "HeroLeft1"));
				playerLeft.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "HeroLeft3"));


				std::vector<std::shared_ptr<Texture>> playerRight;
				playerRight.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "HeroRight1"));
				playerRight.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "HeroRight2"));
				playerRight.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "HeroRight1"));
				playerRight.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "HeroRight3"));


				std::vector<std::shared_ptr<Texture>> playerProjectile;
				playerProjectile.push_back(std::make_shared<Texture>(this->getTextureAsset("ProjectileSheet"), "RedBall"));
				playerProjectile.push_back(std::make_shared<Texture>(this->getTextureAsset("ProjectileSheet"), "BlueBall"));
				playerProjectile.push_back(std::make_shared<Texture>(this->getTextureAsset("ProjectileSheet"), "GreenBall"));
		
				NonPlayerCharacter* HeroPlayer = new NonPlayerCharacter(new AnimatedObject("test006", { 33, 33 }, std::make_shared<Animation>(playerSouth, 200), 1.0, 1.0, 3, SOUTH, true));
				
				HeroPlayer->addAnimation("North", std::make_shared<Animation>(playerNorth, 200));
				HeroPlayer->addAnimation("South", std::make_shared<Animation>(playerSouth, 200));
				HeroPlayer->addAnimation("East", std::make_shared<Animation>(playerRight, 200));
				HeroPlayer->addAnimation("West", std::make_shared<Animation>(playerLeft, 200));
				HeroPlayer->addAnimation("Projectile", std::make_shared<Animation>(playerProjectile, 200));
				

				this->map->addObject(HeroPlayer);
				this->map->setPlayerCharacter(HeroPlayer);

				std::vector<std::shared_ptr<Texture>> murderFront;
				murderFront.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthFront1"));
				murderFront.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthFront2"));
				murderFront.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthFront3"));
				murderFront.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthFront4"));
				murderFront.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthFront5"));
				murderFront.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthFront6"));
				murderFront.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthFront7"));
				murderFront.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthFront4"));
				murderFront.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthFront8"));
				murderFront.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthFront2"));

				std::vector<std::shared_ptr<Texture>> murderRight;
				murderRight.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthRight1"));
				murderRight.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthRight2"));
				murderRight.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthRight3"));
				murderRight.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthRight4"));
				murderRight.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthRight5"));
				murderRight.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthRight6"));
				murderRight.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthRight7"));
				murderRight.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthRight4"));
				murderRight.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthRight8"));
				murderRight.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthRight2"));

				std::vector<std::shared_ptr<Texture>> murderLeft;
				murderLeft.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthLeft1"));
				murderLeft.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthLeft2"));
				murderLeft.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthLeft3"));
				murderLeft.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthLeft4"));
				murderLeft.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthLeft5"));
				murderLeft.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthLeft6"));
				murderLeft.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthLeft7"));
				murderLeft.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthLeft4"));
				murderLeft.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthLeft8"));
				murderLeft.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "MouthLeft2"));

				std::vector<std::shared_ptr<Texture>> murderBack;
				murderBack.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "GhostBack1"));
				murderBack.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "GhostBack2"));
				murderBack.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "GhostBack3"));
				murderBack.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "GhostBack2"));

				AnimatedObject* murderGhost = new AnimatedObject("WorldEater", { 35, 490 }, std::make_shared<Animation>(murderFront, 200), 1.0, 1.0, 5, SOUTH, true);

				NonPlayerCharacter* Eater = new NonPlayerCharacter(murderGhost);

				Eater->addAnimation("East", std::make_shared<Animation>(murderRight, 200));
				Eater->addAnimation("West", std::make_shared<Animation>(murderLeft, 200));
				Eater->addAnimation("North", std::make_shared<Animation>(murderBack, 200));
				Eater->addAnimation("South", std::make_shared<Animation>(murderFront, 200));

				Eater->setAI(new DefaultAI(Eater, this->map));
				this->map->addObject(Eater);



				std::vector<std::shared_ptr<Texture>> textures;
				textures.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "GhostFront1"));
				textures.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "GhostFront2"));
				textures.push_back(std::make_shared<Texture>(this->getTextureAsset("EpicSpriteSheet"), "GhostFront3"));


				AnimatedObject* animatedObject = new AnimatedObject("granges", { 35, 200 }, std::make_shared<Animation>(textures, 200), 1.0, 1.0, 2, NORTH, true);
				AnimatedObject* animatedObject2 = new AnimatedObject("evert", { 35, 240 }, std::make_shared<Animation>(textures, 200), 1.0, 1.0, 2, NORTH, true);
				AnimatedObject* animatedObject3 = new AnimatedObject("hakan", { 360, 520 }, std::make_shared<Animation>(textures, 200), 1.0, 1.0, 2, NORTH, true);
				AnimatedObject* animatedObject4 = new AnimatedObject("lisa", { 35, 400 }, std::make_shared<Animation>(textures, 200), 1.0, 1.0, 2, NORTH, true);
				AnimatedObject* animatedObject5 = new AnimatedObject("ulf", { 180, 360 }, std::make_shared<Animation>(textures, 200), 1.0, 1.0, 2, NORTH, true);
				NonPlayerCharacter* granges = new NonPlayerCharacter(animatedObject);
				NonPlayerCharacter* granges2 = new NonPlayerCharacter(animatedObject2);
				NonPlayerCharacter* granges3 = new NonPlayerCharacter(animatedObject3);
				NonPlayerCharacter* granges4 = new NonPlayerCharacter(animatedObject4);
				NonPlayerCharacter* granges5 = new NonPlayerCharacter(animatedObject5);
				granges->setAI(new DefaultAI(granges, this->map));
				granges2->setAI(new DefaultAI(granges2, this->map));
				granges3->setAI(new DefaultAI(granges3, this->map));
				granges4->setAI(new DefaultAI(granges4, this->map));
				granges5->setAI(new DefaultAI(granges5, this->map));

				this->map->addObject(granges);
				this->map->addObject(granges2);
				this->map->addObject(granges3);
				this->map->addObject(granges4);
				this->map->addObject(granges5);

				
				std::vector<std::shared_ptr<Texture>> witchTextures;
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft0"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft1"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft2"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft3"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft4"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft5"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft6"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft7"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft8"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft9"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft10"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft11"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft12"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft13"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft11"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft12"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft13"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft11"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft12"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft13"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft11"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft12"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft13"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft14"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft15"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft16"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft17"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft18"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft19"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft20"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft19"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft18"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft17"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft16"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft15"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft14"));
				witchTextures.push_back(std::make_shared<Texture>(this->getTextureAsset("WitchSpritesheet"), "CauldronLeft0"));


				AnimatedObject* witchObject = new AnimatedObject("test004", { 490, 360 }, std::make_shared<Animation>(witchTextures, 200), 1.0, 1.0, 0, NONE, true);
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