#include "InputTutoMastermindIntro.h"

void InputTutoMastermindIntro(GameData* _gd)
{
	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft) //Clic gauche
		{
			sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
			sfVector2f posMouse2f = { posMouse.x,posMouse.y };

			if (isCollidingWithMouse(_gd->enigme.doorDigicode.buttonRetour.forme, posMouse2f, 0))
			{
				_gd->enigme.doorDigicode.clickRetour = sfTrue;
			}
		}
	}

	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
			sfVector2f posMouse2f = { posMouse.x,posMouse.y };

			_gd->enigme.doorDigicode.clickRetour = sfFalse;

			if (isCollidingWithMouse(_gd->enigme.doorDigicode.buttonRetour.forme, posMouse2f, 0))
			{
				_gd->inGameState = enigme;
			}

		}
	}
}