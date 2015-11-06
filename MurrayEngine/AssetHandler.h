#ifndef _ASSET_HANDLER_H
#define _ASSET_HANDLER_H

class AssetHandler
{
public:
	AssetHandler();
	~AssetHandler();
	virtual void	load();
	virtual void	unload();
};

#endif // !_ASSET_HANDLER_H
