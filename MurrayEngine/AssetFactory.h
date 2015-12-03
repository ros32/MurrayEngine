#ifndef _ASSET_FACTORY_H
#define	_ASSET_FACTORY_H

#include	<vector>
#include	"Asset.h"
#include	"Configuration.h"

///	<summary>
///	The AssetFactory is an abstract class that takes a Configuration object and creates Asset objects from it, depending on the implementation.
///	</summary>
class AssetFactory
{
public:
	AssetFactory();
	~AssetFactory();

	virtual Asset	createAsset(Configuration configuration) = 0;

private:

};

#endif // !_ASSET_FACTORY_H
