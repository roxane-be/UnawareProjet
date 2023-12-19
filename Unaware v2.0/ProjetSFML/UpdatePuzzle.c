#include "UpdatePuzzle.h"

int GetIdPiece(GameData* _gd, sfVector2f _mouse)
{
	for (int i = 0; i < 25; i++)
	{
		if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.piece[i].forme, _mouse, 0))
		{
			return _gd->enigme.utilityPuzzle.piece[i].Id;
		}
	}
}

int GetIdPuzzle(GameData* _gd, sfVector2f _mouse)
{
	for (int i = 0; i < 25; i++)
	{
		if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.puzzle[i].forme, _mouse, 0))
		{
			return _gd->enigme.utilityPuzzle.puzzle[i].Id;
			//printf("%d\n", _gd->enigme.utilityPuzzle.puzzle[i].Id);
		}
	}
	return -1;
}

void UpdatePuzzle(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos = { 0, 0 };
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	//bouton valider
	if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.validate.forme, tempPos, 0))
	{
		_gd->enigme.utilityPuzzle.onSpriteValidate = sfTrue;
	}
	else
	{
		_gd->enigme.utilityPuzzle.onSpriteValidate = sfFalse;
	}

	//bouton reset
	if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.reset.forme, tempPos, 0))
	{
		_gd->enigme.utilityPuzzle.onSpriteReset = sfTrue;
	}
	else
	{
		_gd->enigme.utilityPuzzle.onSpriteReset = sfFalse;
	}

	//bouton quitter
	if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.quit.forme, tempPos, 0))
	{
		_gd->enigme.utilityPuzzle.onSpriteQuit = sfTrue;
	}
	else
	{
		_gd->enigme.utilityPuzzle.onSpriteQuit = sfFalse;
	}

	//bouton d'aide
	if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.help.forme, tempPos, 0))
	{
		_gd->enigme.utilityPuzzle.onSpriteHelp = sfTrue;
	}
	else
	{
		_gd->enigme.utilityPuzzle.onSpriteHelp = sfFalse;
	}
}
