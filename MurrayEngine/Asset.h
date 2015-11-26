#ifndef _ASSET_H
#define _ASSET_H

///	<summary>
///	An Asset is a representation of an external resource used by the game. This could be textures, sounds etc.
///	</summary>
class Asset
{
public:
	Asset();
	~Asset();
	virtual void	load();
	virtual void	unload();
};

#endif // !_ASSET_H
