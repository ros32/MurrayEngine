#ifndef _ASSET_H
#define _ASSET_H

class Asset
{
public:
	Asset();
	~Asset();
	virtual void	load();
	virtual void	unload();
};

#endif // !_ASSET_H
