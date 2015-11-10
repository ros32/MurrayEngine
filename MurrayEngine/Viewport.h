#ifndef _VIEWPORT_H
#define	_VIEWPORT_H

#include	<SDL.h>
#include	"GenericObject.h"

class Viewport
{
public:
	Viewport(SDL_Renderer* renderer, SDL_Rect viewportRect);
	~Viewport();

	SDL_Renderer*		getRenderer();
	SDL_Rect*			getViewportRect();

	void				center(GenericObject object);

private:

	SDL_Renderer*		renderer;
	SDL_Rect			viewportRect;

};

#endif // !_VIEWPORT_H
