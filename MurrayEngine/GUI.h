#ifndef _GUI_H
#define	_GUI_H

#include	<vector>
#include	<algorithm>
#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif
#include	"GUIObject.h"

class GUI
{
public:
	GUI();
	~GUI();

	std::vector<GUIObject*>	getGUIObjects();

	void	addObject(GUIObject* object);
	void	removeObject(GUIObject* object);

	void	render();

private:

	std::vector<GUIObject*>		guiObjects;

};

#endif // !_GUI_H
