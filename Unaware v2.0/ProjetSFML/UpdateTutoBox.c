#include "UpdateTutoBox.h"

void UpdateTutoBox(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos = { 0, 0 };
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	if (isCollidingWithMouse(_gd->enigme.houseBox.retourButtonBox.forme, tempPos, 0))
	{
		_gd->enigme.houseBox.onSpriteRetourButtonBox = sfTrue;
	}
	else
	{
		_gd->enigme.houseBox.onSpriteRetourButtonBox = sfFalse;
	}
}