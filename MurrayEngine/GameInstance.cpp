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
	this->map = Map(window, renderer);
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

		std::vector<std::vector<Tile>> tiles(2, std::vector<Tile>(20));


		tiles[0][0] = Tile(	{ 0, 0 },	this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][1] = Tile(	{ 32, 0 },	this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][2] = Tile(	{ 64, 0 },	this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][3] = Tile(	{ 96, 0 },	this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][4] = Tile(	{ 128, 0 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][5] = Tile(	{ 160, 0 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][6] = Tile(	{ 192, 0 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][7] = Tile(	{ 224, 0 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][8] = Tile(	{ 256, 0 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][9] = Tile(	{ 288, 0 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][10] = Tile({ 320, 0 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][11] = Tile({ 352, 0 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][12] = Tile({ 384, 0 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][13] = Tile({ 416, 0 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][14] = Tile({ 448, 0 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][15] = Tile({ 480, 0 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][16] = Tile({ 512, 0 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][17] = Tile({ 544, 0 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[0][18] = Tile({ 576, 0 }, this->getTextureAsset("tileset"), "StoneStairsUp", NORTH);
		tiles[0][19] = Tile({ 608, 0 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);

		tiles[1][0] = Tile({ 0, 32 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[1][1] = Tile({ 32, 32 }, this->getTextureAsset("tileset"), "StoneFloorNormal", NORTH);
		tiles[1][2] = Tile({ 64, 32 }, this->getTextureAsset("tileset"), "StoneFloorNormal", NORTH);
		tiles[1][3] = Tile({ 96, 32 }, this->getTextureAsset("tileset"), "StoneFloorNormal", NORTH);
		tiles[1][4] = Tile({ 128, 32 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[1][5] = Tile({ 160, 32 }, this->getTextureAsset("tileset"), "StoneFloorNormal", NORTH);
		tiles[1][6] = Tile({ 192, 32 }, this->getTextureAsset("tileset"), "StoneFloorNormal", NORTH);
		tiles[1][7] = Tile({ 224, 32 }, this->getTextureAsset("tileset"), "StoneFloorNormal", NORTH);
		tiles[1][8] = Tile({ 256, 32 }, this->getTextureAsset("tileset"), "StoneFloorNormal", NORTH);
		tiles[1][9] = Tile({ 288, 32 }, this->getTextureAsset("tileset"), "StoneFloorNormal", NORTH);
		tiles[1][10] = Tile({ 320, 32 }, this->getTextureAsset("tileset"), "StoneFloorNormal", NORTH);
		tiles[1][11] = Tile({ 352, 32 }, this->getTextureAsset("tileset"), "StoneFloorNormal", NORTH);
		tiles[1][12] = Tile({ 384, 32 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[1][13] = Tile({ 416, 32 }, this->getTextureAsset("tileset"), "StoneFloorNormal", NORTH);
		tiles[1][14] = Tile({ 448, 32 }, this->getTextureAsset("tileset"), "StoneFloorNormal", NORTH);
		tiles[1][15] = Tile({ 480, 32 }, this->getTextureAsset("tileset"), "StoneFloorNormal", NORTH);
		tiles[1][16] = Tile({ 512, 32 }, this->getTextureAsset("tileset"), "StoneFloorNormal", NORTH);
		tiles[1][17] = Tile({ 544, 32 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);
		tiles[1][18] = Tile({ 576, 32 }, this->getTextureAsset("tileset"), "StoneFloorNormal", NORTH);
		tiles[1][19] = Tile({ 608, 32 }, this->getTextureAsset("tileset"), "StoneWallNormal", NORTH);

		this->map.setTiles(tiles);
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