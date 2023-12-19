#include "UpdateDecryptage.h"

void UpdateDecryptage(GameData* _gd)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouse = { mouse.x,mouse.y };

	if (isCollidingWithMouse(_gd->enigme.decryptage.validateDecryptage.forme, posMouse, 0))
	{
		_gd->enigme.decryptage.onSpriteValidateDecryptage = sfTrue;
	}
	else
	{
		_gd->enigme.decryptage.onSpriteValidateDecryptage = sfFalse;
	}

	if (isCollidingWithMouse(_gd->enigme.decryptage.resetDecryptage.forme, posMouse, 0))
	{
		_gd->enigme.decryptage.onSpriteResetDecryptage = sfTrue;
	}
	else
	{
		_gd->enigme.decryptage.onSpriteResetDecryptage = sfFalse;
	}

	if (isCollidingWithMouse(_gd->enigme.decryptage.quitDecryptage.forme, posMouse, 0))
	{
		_gd->enigme.decryptage.onSpriteQuitDecryptage = sfTrue;
	}
	else
	{
		_gd->enigme.decryptage.onSpriteQuitDecryptage = sfFalse;
	}

	if (isCollidingWithMouse(_gd->enigme.decryptage.aideDecryptage.forme, posMouse, 0))
	{
		_gd->enigme.decryptage.onSpriteAideDecryptage = sfTrue;
	}
	else
	{
		_gd->enigme.decryptage.onSpriteAideDecryptage = sfFalse;
	}
}