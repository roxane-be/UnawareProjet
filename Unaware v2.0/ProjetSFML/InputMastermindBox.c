#include "InputMastermindBox.h"

void InputMastermindBox(GameData* _gd)
{
	sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouse2f = { posMouse.x,posMouse.y };

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft) //Clic gauche
		{
			if (isCollidingWithMouse(_gd->enigme.houseBox.buttonHelpMastermindBox.forme, posMouse2f, 0))
			{
				_gd->enigme.houseBox.clickHelpMastermindBox = sfTrue;
			}

			int sizeChaine = strlen(_gd->enigme.houseBox.value);
			if (sizeChaine < NB_DIGICODE)
			{
				for (int i = 0; i < NB_ARROW; i++)
				{
					Collision tempTab[1] = { _gd->enigme.houseBox.colTriangle[i] };
					if (CollisionTriangleMouse(posMouse2f, tempTab))
					{
						// joue le son d'appuie sur les flèches
						sfSound_play(_gd->enigme.doorDigicode.arrowSound.sound);
						_gd->enigme.houseBox.arrowBox[i].idSeq = 0;
						_gd->enigme.houseBox.arrowBox[i].isClicked = sfTrue;
					}
				}
			}
		}
	}

	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->enigme.houseBox.clickHelpMastermindBox = sfFalse;

			if (isCollidingWithMouse(_gd->enigme.houseBox.buttonHelpMastermindBox.forme, posMouse2f, 0))
			{
				sfSound_play(_gd->helpSound.sound);
				_gd->inGameState = tuto;
			}
			if (_gd->enigme.houseBox.boiteOuverte == sfFalse)
			{
				if (isCollidingWithMouse(_gd->enigme.houseBox.buttonValidateBox.forme, posMouse2f, 0))
				{
					isValidateBox(_gd);
				}
			}
			else if (_gd->enigme.houseBox.boiteOuverte == sfTrue)
			{
				if (isCollidingWithMouse(_gd->enigme.houseBox.pieceMastermindBox.forme, posMouse2f, 0))
				{
					sfSound_play(_gd->utilityPieceBoite.pickUpCoinSound.sound);
					_gd->enigme.houseBox.pieceRecup = sfTrue;
					_gd->enigmeBox = box;
					_gd->enigmeState = plaqueBox;
					_gd->enigme.houseBox.resolvedDream_1Box = sfTrue;
				}
			}

		}
	}
}

