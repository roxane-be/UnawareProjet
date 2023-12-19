#include "UpdateTutoPuzzle.h"

void UpdateTutoPuzzle(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos = { 0, 0 };
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.retour.forme, tempPos, 0))
	{
		_gd->enigme.utilityPuzzle.onSpriteRetour = sfTrue;
	}
	else
	{
		_gd->enigme.utilityPuzzle.onSpriteRetour = sfFalse;
	}
}