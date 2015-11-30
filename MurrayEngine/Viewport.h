#ifndef _VIEWPORT_H
#define	_VIEWPORT_H

#include	<SDL.h>
#include	"GenericObject.h"
#include	"Position.h"

class Viewport
{
public:
	Viewport(SDL_Renderer* renderer);
	~Viewport();

	SDL_Rect			getViewportRect();

	Position			getPosition();
	void				setPosition(Position pos);
	void				setPosition(GenericObject object);



private:

	Position			position;
	SDL_Renderer*		renderer;
	SDL_Rect			viewportRect;

};

#endif // !_VIEWPORT_H
