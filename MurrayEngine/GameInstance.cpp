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
}

GameInstance::~GameInstance()
{

}

bool GameInstance::initialize()
{

	std::vector<Configuration>	configurations;

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
			TextureAsset tempAsset = assetFactory.createAsset(config);
			//	HACK: Create class InvalidAsset and use for invalid assets
			//if (tempAsset.getType() != "InvalidAsset")
			//{
				this->textureAssets.insert(std::map<std::string, TextureAsset>::value_type(config.getProperty("NAME", "UNKNOWN"), tempAsset));
				SDL_Log("Asset Loaded");
			//}
		}
		else if (type == "SoundAsset")
		{

		}
	}

	//	Load map


	//	Test map

	TextureAsset*	tileset = this->getTextureAsset("tileset");
	if (tileset != nullptr)
	{
		GenericObject tempObject = GenericObject("object1", { 100, 100 }, tileset, "Grass", 0.0, 0.0, NORTH);
		this->map.addObject(tempObject);
	}




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

}

void GameInstance::renderObjects()
{
	this->map.render();
}

TextureAsset*	GameInstance::getTextureAsset(std::string name)
{
	std::map<std::string, TextureAsset>::iterator iterator;
	iterator = this->textureAssets.find(name);
	if (iterator != this->textureAssets.end())
		return &iterator->second;
	return nullptr;
}