#include "InputVoltage.h"

void InputVoltageBox(GameData* _gd)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouse = { mouse.x,mouse.y };

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft) //Clic gauche
		{

			for (int i = 0; i < NB_LEVIER; i++)
			{
				if (isCollidingWithMouse(_gd->enigme.voltage.rectLevier[i], posMouse, 1))
				{
					sfSound_play(_gd->enigme.voltage.switchSound.sound);

					switch (_gd->enigme.voltage.etat[i])
					{
					case positif:
						_gd->enigme.voltage.etat[i] = neutre_positif;
						_gd->enigme.voltage.voltmetre -= _gd->enigme.voltage.levier[i];

						break;
					case negatif:
						_gd->enigme.voltage.etat[i] = neutre_negatif;
						_gd->enigme.voltage.voltmetre += _gd->enigme.voltage.levier[i];

						break;
					case neutre_negatif:
						_gd->enigme.voltage.etat[i] = positif;
						_gd->enigme.voltage.voltmetre += _gd->enigme.voltage.levier[i];

						break;
					case neutre_positif:
						_gd->enigme.voltage.etat[i] = negatif;
						_gd->enigme.voltage.voltmetre -= _gd->enigme.voltage.levier[i];
						break;
					default:
						break;
					}
				}
			}
			if (isCollidingWithMouse(_gd->enigme.voltage.helpButtonVoltageBox.forme, posMouse, 0))
			{
				_gd->enigme.voltage.clickHelpButtonVoltageBox = sfTrue;
			}

			if (isCollidingWithMouse(_gd->enigme.voltage.validateButtonVoltageBox.forme, posMouse, 1))
			{
				_gd->enigme.voltage.clickValidateVoltageBox = sfTrue;

			}
			if (isCollidingWithMouse(_gd->enigme.voltage.resetButtonVoltageBox.forme, posMouse, 1))
			{
				//a tester
				sfSound_play(_gd->enigme.voltage.switchSound.sound);

				_gd->enigme.voltage.voltmetre = 0;
				for (int i = 0; i < NB_LEVIER; i++)
				{
					_gd->enigme.voltage.etat[i] = neutre_negatif;
				}
			}
		}
	}
	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->enigme.voltage.clickValidateVoltageBox = sfFalse;
			_gd->enigme.voltage.clickHelpButtonVoltageBox = sfFalse;

			if (isCollidingWithMouse(_gd->enigme.voltage.helpButtonVoltageBox.forme, posMouse, 0))
			{
				sfSound_play(_gd->helpSound.sound);
				_gd->inGameState = tuto;
			}
			if (isCollidingWithMouse(_gd->enigme.voltage.validateButtonVoltageBox.forme, posMouse, 0))
			{
				if (_gd->enigme.voltage.voltmetre == SOLUTION_VOLTMETRE)
				{
					_gd->enigme.voltage.leavingCard = sfTrue;
				}
				else
				{
					sfSound_play(_gd->enigme.voltage.deniedSound.sound);
				}
			}
			if (isCollidingWithMouse(_gd->enigme.voltage.voltageCard.forme, posMouse, 0)
				&& _gd->enigme.voltage.leavingCard == sfTrue
				&& _gd->enigme.voltage.stageCard == 2)
			{
				sfSound_play(_gd->sucessSound.sound);
				_gd->cutSceneState = islandEnd;
				_gd->inGameState = cutscene;
				_gd->enigmeState = none;
				_gd->player.interaction = sfFalse;
				_gd->enigme.voltage.resolvedDream_1 = sfTrue;
				InitCutScene(_gd);

			}

		}
	}
}


