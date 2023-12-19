#include "UpdateVoltage.h"

void UpdateTimerVoltageCard(GameData* _gd)
{
	_gd->enigme.voltage.timerVoltageCard += 0.1;

	if (_gd->enigme.voltage.timerVoltageCard >= 5.0
		&& _gd->enigme.voltage.timerVoltageCard < 10.0)
	{
		_gd->enigme.voltage.stageCard = 1;
	}
	else if (_gd->enigme.voltage.timerVoltageCard >= 10.0)
	{
		_gd->enigme.voltage.stageCard = 2;
	}
}

void UpdateVoltageBox(GameData* _gd)
{
	sfVector2i posMouseI = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouseF = { posMouseI.x, posMouseI.y };

	if (isCollidingWithMouse(_gd->enigme.voltage.helpButtonVoltageBox.forme, posMouseF, 0))
	{
		_gd->enigme.voltage.onSpriteHelpButtonVoltageBox = sfTrue;
	}
	else
	{
		_gd->enigme.voltage.onSpriteHelpButtonVoltageBox = sfFalse;
	}

	if (isCollidingWithMouse(_gd->enigme.voltage.validateButtonVoltageBox.forme, posMouseF, 0))
	{
		_gd->enigme.voltage.onSpriteValidateVoltageBox = sfTrue;
	}
	else
	{
		_gd->enigme.voltage.onSpriteValidateVoltageBox = sfFalse;
	}

	if (_gd->enigme.voltage.leavingCard == sfTrue)
	{
		UpdateTimerVoltageCard(_gd);
	}

	char stringDraw[999];
	sprintf(stringDraw, "%d", _gd->enigme.voltage.voltmetre);
	sfText_setString(_gd->enigme.voltage.volt, stringDraw);
}