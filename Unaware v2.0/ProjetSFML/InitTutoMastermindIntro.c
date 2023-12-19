#include "InitTutoMastermindIntro.h"

void InitTutoMastermindIntro(GameData* _gd)
{
	//Init Background Tuto
	_gd->enigme.doorDigicode.backgroundTuto = LoadSprite("../Ressources/Assets/Mastermind/aide_mastermind.png", 0);

	//Init retour button
	_gd->enigme.doorDigicode.buttonRetour.buttonSprite[0] = LoadSprite("../Ressources/Assets/Mastermind/boutons/retour_1.png", 0);
	_gd->enigme.doorDigicode.buttonRetour.buttonSprite[1] = LoadSprite("../Ressources/Assets/Mastermind/boutons/retour_2.png", 0);
	_gd->enigme.doorDigicode.buttonRetour.buttonSprite[2] = LoadSprite("../Ressources/Assets/Mastermind/boutons/retour_3.png", 0);

	_gd->enigme.doorDigicode.buttonRetour.isQuit = sfFalse;
	_gd->enigme.doorDigicode.onSpriteRetour = sfFalse;
	_gd->enigme.doorDigicode.clickRetour = sfFalse;

	_gd->enigme.doorDigicode.buttonRetour.size.x = 200;
	_gd->enigme.doorDigicode.buttonRetour.size.y = 200;

	_gd->enigme.doorDigicode.buttonRetour.pos.x = (_gd->sizeWindow.width / 2) - 100;
	_gd->enigme.doorDigicode.buttonRetour.pos.y = 800;

	_gd->enigme.doorDigicode.buttonRetour.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.doorDigicode.buttonRetour.forme, _gd->enigme.doorDigicode.buttonRetour.pos,
		_gd->enigme.doorDigicode.buttonRetour.size.x, _gd->enigme.doorDigicode.buttonRetour.size.y, 0);
}

void DeleteTutoMastermindIntroSprite(GameData* _gd)
{
	DeleteSprite(_gd->enigme.doorDigicode.backgroundTuto);
	for (int i = 0; i < 3; i++)
	{
		DeleteSprite(_gd->enigme.doorDigicode.buttonRetour.buttonSprite[i]);
	}
	sfRectangleShape_destroy(_gd->enigme.doorDigicode.buttonRetour.forme);

}