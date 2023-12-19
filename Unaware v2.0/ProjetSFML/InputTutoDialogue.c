#include "InputTutoDialogue.h"

void InputTutoDialogue(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos = { 0, 0 };
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->enigme.dialogue.clickRetourDialogue = sfTrue;
		}
	}

	//permet d'activer le bouton que si on release le clic dessus
	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->enigme.dialogue.clickRetourDialogue = sfFalse;

			if (isCollidingWithMouse(_gd->enigme.dialogue.retourDialogue.forme, tempPos, 0))
			{
				//retour a l'enigme
				_gd->inGameState = exploration; //a modifier
				_gd->enigme.dialogue.state = DOOR;

			}
		}
	}
}