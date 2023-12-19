#include "UpdateTutoPuzzleJungle.h"

void UpdateTutoPuzzleJungle(GameData* _gd)
{
	sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouseF = { posMouse.x, posMouse.y };

	if (isCollidingWithMouse(_gd->enigme.puzzleJungle.retourPuzzleJungle.forme, posMouseF, 0))
	{
		_gd->enigme.puzzleJungle.onSpriteRetourPuzzleJungle = sfTrue;
	}
	else
	{
		_gd->enigme.puzzleJungle.onSpriteRetourPuzzleJungle = sfFalse;
	}
}