#include "UpdateCable.h"

int GetIdCable(GameData* _gd, sfVector2f _mouse)
{
	for (int i = 0; i < NB_CABLE; i++)
	{
		if (isCollidingWithMouse(_gd->cables[i].rectangleStart, _mouse, 0))
		{
			return _gd->cables[i].id;
		}
	}
	return -1;
}

void UpdateCableBox(GameData* _gd)
{
	int conditionVictory = 0;

	sfVector2i posMouseI = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouseF = { posMouseI.x, posMouseI.y };

	for (int i = 0; i < NB_CABLE; i++)
	{
		if (_gd->cables[i].click == sfTrue)
		{
			sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
			if (posMouse.x > _gd->cables[i].posStart.x + _gd->cables[i].width)
			{
				sfVector2f forward = { posMouse.x - _gd->cables[i].posCable.x,
									   posMouse.y - _gd->cables[i].posCable.y };

				_gd->cables[i].direction = NormalizeVector(forward);
				_gd->cables[i].length = GetVectorLength(forward);
			}
		}
		if (_gd->cables[i].isPlaced == sfTrue)
		{
			conditionVictory++;
		}
	}

	if (isCollidingWithMouse(_gd->utilityCable.helpButtonCableBox.forme, posMouseF, 0))
	{
		_gd->utilityCable.onSpriteHelpButtonCableBox = sfTrue;
	}
	else
	{
		_gd->utilityCable.onSpriteHelpButtonCableBox = sfFalse;
	}

	if (_gd->utilityCable.switchOn_Off == sfFalse)
	{
		if (isCollidingWithMouse(_gd->utilityCable.validateOffButtonCableBox.forme, posMouseF, 0))
		{
			_gd->utilityCable.onSpriteValidateOffCableBox = sfTrue;
		}
		else
		{
			_gd->utilityCable.onSpriteValidateOffCableBox = sfFalse;
		}
	}
	else if (_gd->utilityCable.switchOn_Off == sfTrue)
	{
		if (isCollidingWithMouse(_gd->utilityCable.validateOnButtonCableBox.forme, posMouseF, 0))
		{
			_gd->utilityCable.onSpriteValidateOnCableBox = sfTrue;
		}
		else
		{
			_gd->utilityCable.onSpriteValidateOnCableBox = sfFalse;
		}
	}
	if (conditionVictory == NB_CABLE
		&& _gd->utilityCable.resolvedDream_1 == sfFalse)
	{
		_gd->utilityCable.cableRaccorder = sfTrue;

	}
}