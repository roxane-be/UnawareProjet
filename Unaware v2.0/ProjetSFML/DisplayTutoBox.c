#include "DisplayTutoBox.h"

void DisplayBackgroundTutoBox(GameData* _gd)
{
	BlitSprite(_gd->enigme.houseBox.backgroundTutoBox, 0, 0, 0, 1, 1, _gd);

	if (_gd->enigmeState == mastermindBox)
	{
		BlitSprite(_gd->enigme.houseBox.backgroundTutoMastermindBox, 0, 0, 0, 1, 1, _gd);
	}
	else if (_gd->enigmeState == plaqueBox)
	{
		BlitSprite(_gd->utilityPieceBoite.backgroundTutoVis, 0, 0, 0, 1, 1, _gd);
	}
	else if (_gd->enigmeState == cableBox)
	{
		BlitSprite(_gd->utilityCable.backgroundTutoCableBox, 0, 0, 0, 1, 1, _gd);
	}
	else if (_gd->enigmeState == voltageBox)
	{
		BlitSprite(_gd->enigme.voltage.backgroundTutoVoltage, 0, 0, 0, 1, 1, _gd);
	}
}

void DisplayTutoBox(GameData* _gd)
{
	DisplayBackgroundTutoBox(_gd);

	//Bouton Retour
	BlitSprite(_gd->enigme.houseBox.retourButtonBox.buttonSprite[0],
		_gd->enigme.houseBox.retourButtonBox.pos.x,
		_gd->enigme.houseBox.retourButtonBox.pos.y, 0, 0.85, 0.85, _gd);

	if (_gd->enigme.houseBox.onSpriteRetourButtonBox == sfTrue)
	{
		BlitSprite(_gd->enigme.houseBox.retourButtonBox.buttonSprite[1],
			_gd->enigme.houseBox.retourButtonBox.pos.x,
			_gd->enigme.houseBox.retourButtonBox.pos.y, 0, 0.85, 0.85, _gd);
	}

	if (_gd->enigme.houseBox.clickRetourButtonBox == sfTrue)
	{
		BlitSprite(_gd->enigme.houseBox.retourButtonBox.buttonSprite[2],
			_gd->enigme.houseBox.retourButtonBox.pos.x,
			_gd->enigme.houseBox.retourButtonBox.pos.y, 0, 0.85, 0.85, _gd);
	}

	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.houseBox.retourButtonBox.forme, NULL);
}