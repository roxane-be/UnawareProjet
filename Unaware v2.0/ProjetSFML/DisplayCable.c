#include "DisplayCable.h"

void DisplayHelpButtonCableBox(GameData* _gd)
{
	BlitSprite(_gd->utilityCable.helpButtonCableBox.buttonSprite[0], _gd->utilityCable.helpButtonCableBox.pos.x,
		_gd->utilityCable.helpButtonCableBox.pos.y, 0, 1, 1, _gd);

	if (_gd->utilityCable.onSpriteHelpButtonCableBox == sfTrue)
	{
		BlitSprite(_gd->utilityCable.helpButtonCableBox.buttonSprite[1], _gd->utilityCable.helpButtonCableBox.pos.x,
			_gd->utilityCable.helpButtonCableBox.pos.y, 0, 1, 1, _gd);
	}
	if (_gd->utilityCable.clickHelpButtonCableBox == sfTrue)
	{
		BlitSprite(_gd->utilityCable.helpButtonCableBox.buttonSprite[2], _gd->utilityCable.helpButtonCableBox.pos.x,
			_gd->utilityCable.helpButtonCableBox.pos.y, 0, 1, 1, _gd);
	}
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->utilityCable.helpButtonCableBox.forme, NULL);
}

void DisplayValidateButtonCableBox(GameData* _gd)
{
	if (_gd->utilityCable.switchOn_Off == sfFalse)
	{
		BlitSprite(_gd->utilityCable.validateOffButtonCableBox.buttonSprite[0], _gd->utilityCable.validateOffButtonCableBox.pos.x,
			_gd->utilityCable.validateOffButtonCableBox.pos.y, 0, 1, 1, _gd);

		if (_gd->utilityCable.onSpriteValidateOffCableBox == sfTrue)
		{
			BlitSprite(_gd->utilityCable.validateOffButtonCableBox.buttonSprite[1], _gd->utilityCable.validateOffButtonCableBox.pos.x,
				_gd->utilityCable.validateOffButtonCableBox.pos.y, 0, 1, 1, _gd);
		}

		if (_gd->utilityCable.clickValidateOffCableBox == sfTrue)
		{
			BlitSprite(_gd->utilityCable.validateOffButtonCableBox.buttonSprite[2], _gd->utilityCable.validateOffButtonCableBox.pos.x,
				_gd->utilityCable.validateOffButtonCableBox.pos.y, 0, 1, 1, _gd);
		}
	}
	else if (_gd->utilityCable.switchOn_Off == sfTrue)
	{
		BlitSprite(_gd->utilityCable.validateOnButtonCableBox.buttonSprite[0], _gd->utilityCable.validateOnButtonCableBox.pos.x,
			_gd->utilityCable.validateOnButtonCableBox.pos.y, 0, 1, 1, _gd);

		if (_gd->utilityCable.onSpriteValidateOnCableBox == sfTrue)
		{
			BlitSprite(_gd->utilityCable.validateOnButtonCableBox.buttonSprite[1], _gd->utilityCable.validateOnButtonCableBox.pos.x,
				_gd->utilityCable.validateOnButtonCableBox.pos.y, 0, 1, 1, _gd);
		}

		if (_gd->utilityCable.clickValidateOnCableBox == sfTrue)
		{
			BlitSprite(_gd->utilityCable.validateOnButtonCableBox.buttonSprite[2], _gd->utilityCable.validateOnButtonCableBox.pos.x,
				_gd->utilityCable.validateOnButtonCableBox.pos.y, 0, 1, 1, _gd);
		}
	}

}
void DisplayCableBox(GameData* _gd)
{
	BlitSprite(_gd->utilityCable.backgroundCable, 0, 0, 0, 1, 1, _gd);

	if (_gd->utilityCable.cableRaccorder == sfFalse)
	{
		BlitSprite(_gd->utilityCable.diodeCableBoxEnigmeNonFini, 1420, 930, 0, 1, 1, _gd);
	}
	else
	{
		BlitSprite(_gd->utilityCable.diodeCableBoxEnigmeFini, 1420, 930, 0, 1, 1, _gd);
	}

	DisplayHelpButtonCableBox(_gd);
	DisplayValidateButtonCableBox(_gd);

	for (int i = 0; i < NB_CABLE; i++)
	{
		for (int j = 0; j < _gd->cables[i].length; j++)
		{
			if (_gd->utilityPieceBoite.resolvedDream_1 == sfFalse)
			{
				BlitSpriteColor(_gd->cables[i].spriteCable, 1);
			}
			else
			{
				BlitSpriteColor(_gd->cables[i].spriteCable, 2);
			}
			BlitSprite(_gd->cables[i].spriteCable, _gd->cables[i].posCable.x + _gd->cables[i].direction.x * j, _gd->cables[i].posCable.y + _gd->cables[i].direction.y * j, 0, 0.1, 0.1, _gd);

		}
	}

	if (_gd->utilityPieceBoite.resolvedDream_1 == sfFalse)
	{
		BlitSprite(_gd->trap, 0, 0, 0, 1, 1, _gd);
	}
}