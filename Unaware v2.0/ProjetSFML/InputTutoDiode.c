#include "InputTutoDiode.h"

void InputTutoDiode(GameData* _gd)
{
	sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouse2f = { posMouse.x,posMouse.y };

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (_gd->enigme.interupteur.interupteurState == tutoDiode)
			{
				if (isCollidingWithMouse(_gd->enigme.interupteur.retourButtonDiode.forme, posMouse2f, 0))
				{
					_gd->enigme.interupteur.clickRetourButtonDiode = sfTrue;
				}
			}
			else if (_gd->enigme.interupteur.interupteurState == symboleDiode)
			{
				if (isCollidingWithMouse(_gd->enigme.interupteur.retourButtonDiode.forme, posMouse2f, 0))
				{
					_gd->enigme.interupteur.clickRetourButtonDiode = sfTrue;
				}
				if (isCollidingWithMouse(_gd->enigme.interupteur.symboleButtonDiodeTuto.forme, posMouse2f, 0)
					&& _gd->inGameState == tuto)
				{
					_gd->enigme.interupteur.clickSymboleButtonDiodeTuto = sfTrue;
				}

			}
			else if (_gd->enigme.interupteur.interupteurState == fullDiode)
			{
				if (isCollidingWithMouse(_gd->enigme.interupteur.retourButtonDiode.forme, posMouse2f, 0))
				{
					_gd->enigme.interupteur.clickRetourButtonDiode = sfTrue;
				}
			}
		}
	}
	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->enigme.interupteur.clickRetourButtonDiode = sfFalse;
			_gd->enigme.interupteur.clickSymboleButtonDiodeTuto = sfFalse;

			if (_gd->enigme.interupteur.interupteurState == tutoDiode)
			{
				if (isCollidingWithMouse(_gd->enigme.interupteur.retourButtonDiode.forme, posMouse2f, 0))
				{

					_gd->inGameState = enigme;
				}
			}
			else if (_gd->enigme.interupteur.interupteurState == symboleDiode)
			{
				if (isCollidingWithMouse(_gd->enigme.interupteur.retourButtonDiode.forme, posMouse2f, 0))
				{
					_gd->inGameState = enigme;
				}
				if (isCollidingWithMouse(_gd->enigme.interupteur.symboleButtonDiodeTuto.forme, posMouse2f, 0)
					&& _gd->inGameState == tuto)
				{
					sfSound_play(_gd->enigme.interupteur.fireflyInstruction.sound);
					_gd->inGameState = symbole;
				}

			}
			else if (_gd->enigme.interupteur.interupteurState == fullDiode)
			{
				if (isCollidingWithMouse(_gd->enigme.interupteur.retourButtonDiode.forme, posMouse2f, 0))
				{
					_gd->inGameState = enigme;
				}
			}
		}
	}
}