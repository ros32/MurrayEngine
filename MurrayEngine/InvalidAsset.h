#ifndef _INVALID_ASSET_H
#define _INVALID_ASSET_H

#include "Asset.h"

class InvalidAsset : public Asset
{
public:
	InvalidAsset();
	~InvalidAsset();
	std::string		getType();

private:

};

#endif // !_INVALID_ASSET_H
