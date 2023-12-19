#include "UpdateTutoDialogue.h"

void UpdateTutoDialogue(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos = { 0, 0 };
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	if (isCollidingWithMouse(_gd->enigme.dialogue.retourDialogue.forme, tempPos, 0))
	{
		_gd->enigme.dialogue.onSpriteRetourDialogue = sfTrue;
	}
	else
	{
		_gd->enigme.dialogue.onSpriteRetourDialogue = sfFalse;
	}
}