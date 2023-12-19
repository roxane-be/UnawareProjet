#include "InputTutoDecryptage.h"

void InputTutoDecryptage(GameData* _gd)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouse = { mouse.x,mouse.y };

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (isCollidingWithMouse(_gd->enigme.decryptage.retourDecryptage.forme, posMouse, 0))
			{
				_gd->enigme.decryptage.clickRetourDecryptage = sfTrue;
			}
		}
	}

	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->enigme.decryptage.clickRetourDecryptage = sfFalse;

			if (isCollidingWithMouse(_gd->enigme.decryptage.retourDecryptage.forme, posMouse, 0))
			{
				_gd->inGameState = enigme;

			}
		}
	}
}