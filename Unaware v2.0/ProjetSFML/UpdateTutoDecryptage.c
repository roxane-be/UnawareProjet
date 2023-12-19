#include "UpdateTutoDecryptage.h"

void UpdateTutoDecryptage(GameData* _gd)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouse = { mouse.x,mouse.y };

	if (isCollidingWithMouse(_gd->enigme.decryptage.retourDecryptage.forme, posMouse, 0))
	{
		_gd->enigme.decryptage.onSpriteRetourDecryptage = sfTrue;
	}
	else
	{
		_gd->enigme.decryptage.onSpriteRetourDecryptage = sfFalse;
	}
}