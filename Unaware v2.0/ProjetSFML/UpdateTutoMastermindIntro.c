#include "UpdateTutoMastermindIntro.h"

void UpdateButtonMastermindIntroTuto(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos = { 0, 0 };
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	if (isCollidingWithMouse(_gd->enigme.doorDigicode.buttonRetour.forme, tempPos, 0))
	{
		_gd->enigme.doorDigicode.onSpriteRetour = sfTrue;
	}
	else
	{
		_gd->enigme.doorDigicode.onSpriteRetour = sfFalse;
	}
}