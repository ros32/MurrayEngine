#ifndef _ANIMATION_H
#define	_ANIMATION_H

#include	<vector>
#include	<memory>
#include	"Texture.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	An Animation is a struct containing a set of Textures, the time each texture should 
/// 			be displayed and the last texture displayed. </summary>
///
/// <remarks>	Rosen, 2016-02-28. </remarks>
///-------------------------------------------------------------------------------------------------
struct Animation
{
	/// <summary>	The textures. </summary>
	std::vector<std::shared_ptr<Texture>>	textures;

	/// <summary>	The time. </summary>
	int time;

	/// <summary>	The last texture. </summary>
	int lastTexture;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	Animation()
	{
		textures.push_back(nullptr);
		time = 10000;
		lastTexture = 0;
	}

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="tx">	The transmit. </param>
	/// <param name="tm">	The time. </param>
	///-------------------------------------------------------------------------------------------------
	Animation(std::vector<std::shared_ptr<Texture>> tx, int tm)
	{
		textures = tx;
		time = tm;
		lastTexture = 0;
	}

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	~Animation()
	{
		textures.clear();
	}
};

#endif // !_ANIMATION_H
