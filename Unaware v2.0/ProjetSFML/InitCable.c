#include "InitCable.h"

void InitHelpButtonCableBox(GameData* _gd)
{
	//A decommenter quand on aura les assets pour le bouton aide de l'enigme des cable de la boite

	_gd->utilityCable.helpButtonCableBox.buttonSprite[0] = LoadSprite("../Ressources/Assets/Box/aide.png", 0);
	_gd->utilityCable.helpButtonCableBox.buttonSprite[1] = LoadSprite("../Ressources/Assets/Box/aide2.png", 0);
	_gd->utilityCable.helpButtonCableBox.buttonSprite[2] = LoadSprite("../Ressources/Assets/Box/aide3.png", 0);

	_gd->utilityCable.onSpriteHelpButtonCableBox = sfFalse;
	_gd->utilityCable.clickHelpButtonCableBox = sfFalse;

	_gd->utilityCable.helpButtonCableBox.pos.x = 0;
	_gd->utilityCable.helpButtonCableBox.pos.y = 100;

	_gd->utilityCable.helpButtonCableBox.size.x = 170;
	_gd->utilityCable.helpButtonCableBox.size.y = 300;

	_gd->utilityCable.helpButtonCableBox.forme = sfRectangleShape_create();
	createRectangle(_gd->utilityCable.helpButtonCableBox.forme, _gd->utilityCable.helpButtonCableBox.pos, _gd->utilityCable.helpButtonCableBox.size.x, _gd->utilityCable.helpButtonCableBox.size.y, 0);
}

void InitValidateButtonCableBox(GameData* _gd)
{
	sfVector2f posButton = { 800, 880 };
	sfVector2f sizeButton = { 350, 150 };
	_gd->utilityCable.validateOnButtonCableBox.buttonSprite[0] = LoadSprite("../Ressources/Assets/CableBox/switch_on.png", 0);
	_gd->utilityCable.validateOnButtonCableBox.buttonSprite[1] = LoadSprite("../Ressources/Assets/CableBox/switch_on2.png", 0);
	_gd->utilityCable.validateOnButtonCableBox.buttonSprite[2] = LoadSprite("../Ressources/Assets/CableBox/switch_on3.png", 0);

	_gd->utilityCable.onSpriteValidateOnCableBox = sfFalse;
	_gd->utilityCable.clickValidateOnCableBox = sfFalse;

	_gd->utilityCable.validateOnButtonCableBox.pos = posButton;
	_gd->utilityCable.validateOnButtonCableBox.size = sizeButton;

	_gd->utilityCable.validateOnButtonCableBox.forme = sfRectangleShape_create();
	createRectangle(_gd->utilityCable.validateOnButtonCableBox.forme, _gd->utilityCable.validateOnButtonCableBox.pos,
		_gd->utilityCable.validateOnButtonCableBox.size.x, _gd->utilityCable.validateOnButtonCableBox.size.y, 0);

	_gd->utilityCable.validateOffButtonCableBox.buttonSprite[0] = LoadSprite("../Ressources/Assets/CableBox/switch_off.png", 0);
	_gd->utilityCable.validateOffButtonCableBox.buttonSprite[1] = LoadSprite("../Ressources/Assets/CableBox/switch_off2.png", 0);
	_gd->utilityCable.validateOffButtonCableBox.buttonSprite[2] = LoadSprite("../Ressources/Assets/CableBox/switch_off3.png", 0);

	_gd->utilityCable.onSpriteValidateOffCableBox = sfFalse;
	_gd->utilityCable.clickValidateOffCableBox = sfFalse;

	_gd->utilityCable.validateOffButtonCableBox.pos = posButton;
	_gd->utilityCable.validateOffButtonCableBox.size = sizeButton;

	_gd->utilityCable.validateOffButtonCableBox.forme = sfRectangleShape_create();
	createRectangle(_gd->utilityCable.validateOffButtonCableBox.forme, _gd->utilityCable.validateOffButtonCableBox.pos,
		_gd->utilityCable.validateOffButtonCableBox.size.x, _gd->utilityCable.validateOffButtonCableBox.size.y, 0);
}

void InitCableBox(GameData* _gd)
{
	_gd->utilityCable.backgroundCable = LoadSprite("../Ressources/Assets/CableBox/interface_3.png", 0);
	_gd->utilityCable.diodeCableBoxEnigmeFini = LoadSprite("../Ressources/Assets/Mastermind/diode_verte.png", 0);
	_gd->utilityCable.diodeCableBoxEnigmeNonFini = LoadSprite("../Ressources/Assets/Mastermind/diode_rouge.png", 0);
	_gd->utilityCable.switchOn_Off = sfFalse;
	_gd->utilityCable.cableRaccorder = sfFalse;
	_gd->utilityCable.resolvedDream_1 = sfFalse;
	InitHelpButtonCableBox(_gd);
	InitValidateButtonCableBox(_gd);

	char tab[255];

	for (int i = 0; i < NB_CABLE; i++)
	{
		_gd->cables[i].id = i;

		sprintf(tab, "../Ressources/Assets/CableBox/cable%d.png", i + 1);
		_gd->cables[i].spriteCable = LoadSprite(tab, 1);

		_gd->cables[i].isPlaced = 0;
		_gd->cables[i].width = 125;
		_gd->cables[i].height = 36;

		_gd->cables[i].posStart.x = 490;
		_gd->cables[i].posEnd.x = 1250;

		if (i == 0)
		{
			_gd->cables[i].posStart.y = 185;
			_gd->cables[i].posEnd.y = 593;
		}
		else if (i == 1)
		{
			_gd->cables[i].posStart.y = 585;
			_gd->cables[i].posEnd.y = 400;
		}
		else if (i == 2)
		{
			_gd->cables[i].posStart.y = 785;
			_gd->cables[i].posEnd.y = 195;
		}
		else if (i == 3)
		{
			_gd->cables[i].posStart.y = 388;
			_gd->cables[i].posEnd.y = 798;
		}

		_gd->cables[i].posCable.x = _gd->cables[i].posStart.x + 125;
		_gd->cables[i].posCable.y = _gd->cables[i].posStart.y + 16;

		_gd->cables[i].direction = (sfVector2f){ 0,0 };
		_gd->cables[i].length = 0;
		_gd->cables[i].isPlaced = sfFalse;
		_gd->cables[i].click = sfFalse;

		_gd->cables[i].rectangleStart = sfRectangleShape_create();
		createRectangle(_gd->cables[i].rectangleStart, _gd->cables[i].posStart, _gd->cables[i].width, _gd->cables[i].height, 0);

		_gd->cables[i].rectangleEnd = sfRectangleShape_create();
		createRectangle(_gd->cables[i].rectangleEnd, _gd->cables[i].posEnd, _gd->cables[i].width, _gd->cables[i].height, 0);
	}
}

void DeleteCableSprite(GameData* _gd)
{
	for (int i = 0; i < 3; i++)
	{
		DeleteSprite(_gd->utilityCable.helpButtonCableBox.buttonSprite[i]);
		DeleteSprite(_gd->utilityCable.validateOnButtonCableBox.buttonSprite[i]);
		DeleteSprite(_gd->utilityCable.validateOffButtonCableBox.buttonSprite[i]);
	}
	for (int i = 0; i < NB_CABLE; i++)
	{
		DeleteSprite(_gd->cables[i].spriteCable);
		sfRectangleShape_destroy(_gd->cables[i].rectangleEnd);
		sfRectangleShape_destroy(_gd->cables[i].rectangleStart);
	}
	DeleteSprite(_gd->utilityCable.backgroundCable);
	DeleteSprite(_gd->utilityCable.diodeCableBoxEnigmeFini);
	DeleteSprite(_gd->utilityCable.diodeCableBoxEnigmeNonFini);
	DeleteSprite(_gd->utilityCable.backgroundTutoCableBox);

	sfRectangleShape_destroy(_gd->utilityCable.helpButtonCableBox.forme);
	sfRectangleShape_destroy(_gd->utilityCable.validateOnButtonCableBox.forme);
	sfRectangleShape_destroy(_gd->utilityCable.validateOffButtonCableBox.forme);

}
