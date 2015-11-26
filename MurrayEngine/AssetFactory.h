#ifndef _ASSET_FACTORY_H
#define	_ASSET_FACTORY_H

#include	<vector>
#include	"Asset.h"
#include	"Configuration.h"

class AssetFactory
{
public:
	AssetFactory();
	~AssetFactory();

	std::vector< Asset >	createAsset(Configuration configuration);

private:

};

#endif // !_ASSET_FACTORY_H
