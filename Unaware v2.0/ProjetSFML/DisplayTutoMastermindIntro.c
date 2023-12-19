#include "DisplayTutoMastermindIntro.h"

void DisplayTutoMastermindIntro(GameData* _gd)
{
	//interface enigme
	BlitSprite(_gd->sprites.backgroundInterfaceIntro.sprite, 0, 0, 0, 1, 1, _gd);
	BlitSprite(_gd->enigme.doorDigicode.backgroundTuto, 0, -40, 0, 1, 1, _gd);

	//Affichage boutton quitter mastermind
	//sfRectangleShape_setFillColor(_gd->enigme.doorDigicode.buttonQuit.forme, sfBlue);
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.doorDigicode.buttonQuit.forme, NULL);

	//Affichage boutton retour tuto
	//sfRectangleShape_setFillColor(_gd->enigme.doorDigicode.buttonRetour.forme, sfRed);
	BlitSprite(_gd->enigme.doorDigicode.buttonRetour.buttonSprite[0], _gd->enigme.doorDigicode.buttonRetour.pos.x, _gd->enigme.doorDigicode.buttonRetour.pos.y,
		0, 1.25, 1.25, _gd);

	if (_gd->enigme.doorDigicode.onSpriteRetour == sfTrue)
	{
		BlitSprite(_gd->enigme.doorDigicode.buttonRetour.buttonSprite[1], _gd->enigme.doorDigicode.buttonRetour.pos.x, _gd->enigme.doorDigicode.buttonRetour.pos.y,
			0, 1.25, 1.25, _gd);
	}
	if (_gd->enigme.doorDigicode.clickRetour == sfTrue)
	{
		BlitSprite(_gd->enigme.doorDigicode.buttonRetour.buttonSprite[2], _gd->enigme.doorDigicode.buttonRetour.pos.x, _gd->enigme.doorDigicode.buttonRetour.pos.y,
			0, 1.25, 1.25, _gd);
	}
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.doorDigicode.buttonRetour.forme, NULL);
}