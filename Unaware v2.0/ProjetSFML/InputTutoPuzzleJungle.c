#include "InputTutoPuzzleJungle.h"

void InputTutoPuzzleJungle(GameData* _gd)
{
	sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouse2f = { posMouse.x,posMouse.y };

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (isCollidingWithMouse(_gd->enigme.puzzleJungle.retourPuzzleJungle.forme, posMouse2f, 0))
			{
				_gd->enigme.puzzleJungle.clickRetourPuzzleJungle = sfTrue;
			}
		}
	}
	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->enigme.puzzleJungle.clickRetourPuzzleJungle = sfFalse;

			if (isCollidingWithMouse(_gd->enigme.puzzleJungle.retourPuzzleJungle.forme, posMouse2f, 0))
			{
				_gd->inGameState = enigme;
			}
		}
	}
}