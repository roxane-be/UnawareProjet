#include "InputMastermindIntro.h"

void InputMastermindIntro(GameData* _gd)
{
	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft) //Clic gauche
		{
			sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
			sfVector2f posMouse2f = { posMouse.x,posMouse.y };
			int sizeChaine = strlen(_gd->enigme.doorDigicode.value);
			if (sizeChaine < NB_DIGICODE)
			{
				for (int i = 0; i < NB_ARROW; i++)
				{
					struct Collision tempTab[1] = { _gd->enigme.doorDigicode.colTriangle[i] };
					if (CollisionTriangleMouse(posMouse2f, tempTab))
					{
						//joue le son d'appuie sur les flèches
						sfSound_play(_gd->enigme.doorDigicode.arrowSound.sound);
						_gd->enigme.doorDigicode.arrowIntro[i].idSeq = 0;
						_gd->enigme.doorDigicode.arrowIntro[i].isClicked = sfTrue;
					}
				}
			}

			sfVector2f corner = { 120,40 };

			if (isCollidingWithMouse(_gd->enigme.doorDigicode.buttonValidate.forme, posMouse2f, 0))
			{
				_gd->enigme.doorDigicode.clickValidate = sfTrue;
			}

			if (isCollidingWithMouse(_gd->enigme.doorDigicode.buttonHelp.forme, posMouse2f, 0))
			{
				_gd->enigme.doorDigicode.clickHelp = sfTrue;
			}

			if (CollisionAABB((sfVector2f) { posMouse.x, posMouse.y }, _gd->enigme.doorDigicode.buttonQuit.pos, _gd->enigme.doorDigicode.buttonQuit.size))
			{
				//joue le son d'appuie sur le bouton de sortie
				sfSound_play(_gd->enigme.doorDigicode.arrowSound.sound);
				_gd->enigme.doorDigicode.clickQuit = sfTrue;
			}
		}
	}

	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
			sfVector2f posMouse2f = { posMouse.x,posMouse.y };

			_gd->enigme.doorDigicode.clickHelp = sfFalse;
			_gd->enigme.doorDigicode.clickValidate = sfFalse;
			_gd->enigme.doorDigicode.clickQuit = sfFalse;

			//release du bouton pour valider
			if (isCollidingWithMouse(_gd->enigme.doorDigicode.buttonValidate.forme, posMouse2f, 0))
			{
				isValidateIntro(_gd);
				//si le code est bon
				if (_gd->enigme.doorDigicode.value[0] == _gd->enigme.doorDigicode.valueCode[0]
					&& _gd->enigme.doorDigicode.value[1] == _gd->enigme.doorDigicode.valueCode[1]
					&& _gd->enigme.doorDigicode.value[2] == _gd->enigme.doorDigicode.valueCode[2]
					&& _gd->enigme.doorDigicode.value[3] == _gd->enigme.doorDigicode.valueCode[3])
				{
					//joue le son de validation
					sfSound_play(_gd->enigme.doorDigicode.validSound.sound);
				}
				else
				{
					//joue le son d'echec
					sfSound_play(_gd->enigme.doorDigicode.errorSound.sound);
				}
			}

			if (isCollidingWithMouse(_gd->enigme.doorDigicode.buttonHelp.forme, posMouse2f, 0))
			{
				//joue le son d'ouverture de l'aide
				sfSound_play(_gd->helpSound.sound);
				_gd->inGameState = tuto;
			}

			if (isCollidingWithMouse(_gd->enigme.doorDigicode.buttonQuit.forme, posMouse2f, 0))
			{
				_gd->inGameState = exploration;
			}

		}
	}
}
