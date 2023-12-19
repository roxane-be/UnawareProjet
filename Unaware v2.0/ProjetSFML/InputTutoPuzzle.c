#include "InputTutoPuzzle.h"

void InputTutoPuzzle(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos = { 0, 0 };
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.retour.forme, tempPos, 0))
			{
				_gd->enigme.utilityPuzzle.clickRetour = sfTrue;
			}
		}
	}

	//permet d'activer le bouton que si on release le clic dessus
	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->enigme.utilityPuzzle.clickRetour = sfFalse;

			if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.retour.forme, tempPos, 0))
			{
				//retour a l'enigme sans perte des piece posées
				_gd->inGameState = enigme;
			}
		}
	}
}