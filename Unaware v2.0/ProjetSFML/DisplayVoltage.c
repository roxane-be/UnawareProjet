#include "DisplayVoltage.h"

void DisplayHelpButtonVoltageBox(GameData* _gd)
{
	//A decommenter avec les assets du bouton aide pour le voltage de la boite

	BlitSprite(_gd->enigme.voltage.helpButtonVoltageBox.buttonSprite[0], _gd->enigme.voltage.helpButtonVoltageBox.pos.x,
		_gd->enigme.voltage.helpButtonVoltageBox.pos.y, 0, 1, 1, _gd);

	if (_gd->enigme.voltage.onSpriteHelpButtonVoltageBox == sfTrue)
	{
		BlitSprite(_gd->enigme.voltage.helpButtonVoltageBox.buttonSprite[1], _gd->enigme.voltage.helpButtonVoltageBox.pos.x,
			_gd->enigme.voltage.helpButtonVoltageBox.pos.y, 0, 1, 1, _gd);
	}
	if (_gd->enigme.voltage.clickHelpButtonVoltageBox == sfTrue)
	{
		BlitSprite(_gd->enigme.voltage.helpButtonVoltageBox.buttonSprite[2], _gd->enigme.voltage.helpButtonVoltageBox.pos.x,
			_gd->enigme.voltage.helpButtonVoltageBox.pos.y, 0, 1, 1, _gd);
	}

	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.voltage.helpButtonVoltageBox.forme, NULL);
}

void DisplayResetButtonVoltageBox(GameData* _gd)
{
	BlitSprite(_gd->enigme.voltage.resetButtonVoltageBox.buttonSprite[0],
		_gd->enigme.voltage.resetButtonVoltageBox.pos.x - 20,
		_gd->enigme.voltage.resetButtonVoltageBox.pos.y - 17,
		0, 1, 1, _gd);

	//version eteinte
	if (_gd->utilityCable.resolvedDream_1 == sfFalse)
	{
		BlitSpriteColor(_gd->enigme.voltage.resetButtonVoltageBox.buttonSprite[0], 1);
	}
	else
	{
		BlitSpriteColor(_gd->enigme.voltage.resetButtonVoltageBox.buttonSprite[0], 2);

	}
}

void DisplayValidateButtonVoltageBox(GameData* _gd)
{
	BlitSprite(_gd->enigme.voltage.validateButtonVoltageBox.buttonSprite[0], _gd->enigme.voltage.validateButtonVoltageBox.pos.x - 50,
		_gd->enigme.voltage.validateButtonVoltageBox.pos.y - 30, 0, 1, 1, _gd);

	if (_gd->enigme.voltage.onSpriteValidateVoltageBox == sfTrue)
	{
		BlitSprite(_gd->enigme.voltage.validateButtonVoltageBox.buttonSprite[1], _gd->enigme.voltage.validateButtonVoltageBox.pos.x - 50,
			_gd->enigme.voltage.validateButtonVoltageBox.pos.y - 30, 0, 1, 1, _gd);
	}
	if (_gd->enigme.voltage.clickValidateVoltageBox == sfTrue)
	{
		BlitSprite(_gd->enigme.voltage.validateButtonVoltageBox.buttonSprite[2], _gd->enigme.voltage.validateButtonVoltageBox.pos.x - 50,
			_gd->enigme.voltage.validateButtonVoltageBox.pos.y - 30, 0, 1, 1, _gd);
	}

	//version eteinte
	for (int i = 0; i < 2; i++)
	{
		if (_gd->utilityCable.resolvedDream_1 == sfFalse)
		{
			BlitSpriteColor(_gd->enigme.voltage.validateButtonVoltageBox.buttonSprite[i], 1);
		}
		else
		{
			BlitSpriteColor(_gd->enigme.voltage.validateButtonVoltageBox.buttonSprite[i], 2);
		}
	}
}

void DisplayVoltageCard(GameData* _gd)
{
	if (_gd->enigme.voltage.leavingCard == sfTrue)
	{
		if (_gd->enigme.voltage.stageCard == 0)
		{
			BlitSprite(_gd->enigme.voltage.voltageCard.buttonSprite[0], _gd->enigme.voltage.voltageCard.pos.x, _gd->enigme.voltage.voltageCard.pos.y, 0, 1, 1, _gd);
		}
		if (_gd->enigme.voltage.stageCard == 1)
		{
			BlitSprite(_gd->enigme.voltage.voltageCard.buttonSprite[1], _gd->enigme.voltage.voltageCard.pos.x, _gd->enigme.voltage.voltageCard.pos.y, 0, 1, 1, _gd);
		}
		if (_gd->enigme.voltage.stageCard == 2)
		{
			BlitSprite(_gd->enigme.voltage.voltageCard.buttonSprite[2], _gd->enigme.voltage.voltageCard.pos.x, _gd->enigme.voltage.voltageCard.pos.y - 72, 0, 1, 1, _gd);
		}
	}
}


void DisplayVoltageBox(GameData* _gd)
{
	BlitSprite(_gd->enigme.voltage.backgroundVoltage, 0, 0, 0, 1, 1, _gd);

	if (_gd->enigme.voltage.leavingCard == sfFalse)
	{
		BlitSprite(_gd->enigme.voltage.diodeVoltageBoxEnigmeNonFini, 1420, 930, 0, 1, 1, _gd);
	}
	else
	{
		BlitSprite(_gd->enigme.voltage.diodeVoltageBoxEnigmeFini, 1420, 930, 0, 1, 1, _gd);
	}

	DisplayHelpButtonVoltageBox(_gd);
	DisplayResetButtonVoltageBox(_gd);
	DisplayValidateButtonVoltageBox(_gd);

	for (int i = 0; i < NB_LEVIER; i++)
	{
		//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.voltage.rectLevier[i], NULL);

		if (_gd->enigme.voltage.etat[i] == neutre_positif
			|| _gd->enigme.voltage.etat[i] == neutre_negatif)
		{
			BlitSprite(_gd->enigme.voltage.levierNeutre, _gd->enigme.voltage.pos[i].x - 3, _gd->enigme.voltage.pos[i].y + 14, 0, 1, 1, _gd);
		}
		else if (_gd->enigme.voltage.etat[i] == positif)
		{
			BlitSprite(_gd->enigme.voltage.levierPositif, _gd->enigme.voltage.pos[i].x - 3, _gd->enigme.voltage.pos[i].y + 14, 0, 1, 1, _gd);
		}
		else if (_gd->enigme.voltage.etat[i] == negatif)
		{
			BlitSprite(_gd->enigme.voltage.levierNegatif, _gd->enigme.voltage.pos[i].x - 3, _gd->enigme.voltage.pos[i].y + 14, 0, 1, 1, _gd);
		}


		if (_gd->utilityCable.resolvedDream_1 == sfTrue)
		{
			if (_gd->enigme.voltage.voltmetre < SOLUTION_VOLTMETRE)
			{
				BlitSprite(_gd->enigme.voltage.plus, 800, 290, 0, 1, 1, _gd);
			}
			if (_gd->enigme.voltage.voltmetre > SOLUTION_VOLTMETRE)
			{
				BlitSprite(_gd->enigme.voltage.moins, 800, 265, 0, 1, 1, _gd);
			}
			BlitText(_gd->enigme.voltage.volt, 950, 200, sfGreen, (sfVector2f) { 3, 3 }, _gd->window);
		}
	}
	DisplayVoltageCard(_gd);

	if (_gd->utilityCable.resolvedDream_1 == sfFalse)
	{
		BlitSprite(_gd->trap, 0, 0, 0, 1, 1, _gd);
	}
}