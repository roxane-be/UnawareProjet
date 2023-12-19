#include "InputCable.h"

void InputCableBox(GameData* _gd)
{
	sfVector2i posMouseI = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouseF = { posMouseI.x, posMouseI.y };

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->utilityCable.idCable = GetIdCable(_gd, posMouseF);
			if (_gd->utilityCable.idCable != -1 && _gd->cables[_gd->utilityCable.idCable].isPlaced == sfFalse)
			{

				_gd->cables[_gd->utilityCable.idCable].click = sfTrue;
			}

			if (_gd->utilityCable.switchOn_Off == sfFalse)
			{
				if (isCollidingWithMouse(_gd->utilityCable.validateOffButtonCableBox.forme, posMouseF, 0))
				{
					_gd->utilityCable.clickValidateOffCableBox = sfTrue;
				}
			}
			else if (_gd->utilityCable.switchOn_Off == sfTrue)
			{
				if (isCollidingWithMouse(_gd->utilityCable.validateOnButtonCableBox.forme, posMouseF, 0))
				{
					_gd->utilityCable.clickValidateOnCableBox = sfTrue;
				}
			}

			if (isCollidingWithMouse(_gd->utilityCable.helpButtonCableBox.forme, posMouseF, 0))
			{
				_gd->utilityCable.clickHelpButtonCableBox = sfTrue;
			}

		}
	}
	if (_gd->event.type == sfEvtMouseButtonReleased &&
		_gd->cables[_gd->utilityCable.idCable].click == sfTrue)
	{
		if (!isCollidingWithMouse(_gd->cables[_gd->utilityCable.idCable].rectangleEnd, posMouseF, 0))
		{
			_gd->cables[_gd->utilityCable.idCable].length = 0;
		}
		else
		{
			sfVector2f forward = { _gd->cables[_gd->utilityCable.idCable].posEnd.x - _gd->cables[_gd->utilityCable.idCable].posCable.x,
								   (_gd->cables[_gd->utilityCable.idCable].posEnd.y + 16) - _gd->cables[_gd->utilityCable.idCable].posCable.y };

			_gd->cables[_gd->utilityCable.idCable].direction = NormalizeVector(forward);
			_gd->cables[_gd->utilityCable.idCable].length = GetVectorLength(forward);
			_gd->cables[_gd->utilityCable.idCable].isPlaced = sfTrue;
			sfSound_play(_gd->utilityCable.wiresSound.sound);

		}
		_gd->cables[_gd->utilityCable.idCable].click = sfFalse;

	}
	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->utilityCable.clickValidateOffCableBox = sfFalse;
			_gd->utilityCable.clickValidateOnCableBox = sfFalse;
			_gd->utilityCable.clickHelpButtonCableBox = sfFalse;

			if (isCollidingWithMouse(_gd->utilityCable.helpButtonCableBox.forme, posMouseF, 0))
			{
				sfSound_play(_gd->helpSound.sound);
				_gd->inGameState = tuto;
			}
			if (_gd->utilityCable.switchOn_Off == sfFalse)
			{
				if (isCollidingWithMouse(_gd->utilityCable.validateOffButtonCableBox.forme, posMouseF, 0))
				{
					_gd->utilityCable.switchOn_Off = sfTrue;
					sfSound_play(_gd->utilityCable.switchOnOff.sound);
				}
			}
			else if (_gd->utilityCable.switchOn_Off == sfTrue)
			{
				if (isCollidingWithMouse(_gd->utilityCable.validateOnButtonCableBox.forme, posMouseF, 0))
				{
					_gd->utilityCable.switchOn_Off = sfFalse;
				sfSound_play(_gd->utilityCable.switchOnOff.sound);
				}
			}

			if (_gd->utilityCable.cableRaccorder == sfTrue
				&& _gd->utilityCable.switchOn_Off == sfTrue)
			{
				sfSound_play(_gd->utilityCable.powerOnSound.sound);
				_gd->enigmeState = voltageBox;
				_gd->utilityCable.resolvedDream_1 = sfTrue;
			}
		}
	}
}