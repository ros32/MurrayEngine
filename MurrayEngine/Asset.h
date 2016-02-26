#ifndef _ASSET_H
#define _ASSET_H

#include <string>

///	<summary>
///	An Asset is a representation of an external resource used by the game. This could be textures, sounds etc.
///	</summary>
class Asset
{
public:
	Asset();
	virtual ~Asset();

	std::string		getType();
};

#endif // !_ASSET_H
