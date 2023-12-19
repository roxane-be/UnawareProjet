#include "InitVoltage.h"

void InitButtonHelpVoltageBox(GameData* _gd)
{
	//Partie a decommenter quand on aura les assets du bouton aide pour le voltage

	_gd->enigme.voltage.helpButtonVoltageBox.buttonSprite[0] = LoadSprite("../Ressources/Assets/Box/aide.png", 0);
	_gd->enigme.voltage.helpButtonVoltageBox.buttonSprite[1] = LoadSprite("../Ressources/Assets/Box/aide2.png", 0);
	_gd->enigme.voltage.helpButtonVoltageBox.buttonSprite[2] = LoadSprite("../Ressources/Assets/Box/aide3.png", 0);

	_gd->enigme.voltage.onSpriteHelpButtonVoltageBox = sfFalse;
	_gd->enigme.voltage.clickHelpButtonVoltageBox = sfFalse;

	_gd->enigme.voltage.helpButtonVoltageBox.pos.x = 0;
	_gd->enigme.voltage.helpButtonVoltageBox.pos.y = 100;

	_gd->enigme.voltage.helpButtonVoltageBox.size.x = 170;
	_gd->enigme.voltage.helpButtonVoltageBox.size.y = 300;

	_gd->enigme.voltage.helpButtonVoltageBox.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.voltage.helpButtonVoltageBox.forme, _gd->enigme.voltage.helpButtonVoltageBox.pos, _gd->enigme.voltage.helpButtonVoltageBox.size.x,
		_gd->enigme.voltage.helpButtonVoltageBox.size.y, 0);
}

void InitResetButton(GameData* _gd)
{
	sfVector2f posReset = { 700 , 800 };
	sfVector2f sizeReset = { 150 , 150 };

	_gd->enigme.voltage.resetButtonVoltageBox.buttonSprite[0] = LoadSprite("../Ressources/Assets/Voltage/reinit.png", 0);

	_gd->enigme.voltage.resetButtonVoltageBox.pos = posReset;
	_gd->enigme.voltage.resetButtonVoltageBox.size = sizeReset;

	_gd->enigme.voltage.resetButtonVoltageBox.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.voltage.resetButtonVoltageBox.forme, _gd->enigme.voltage.resetButtonVoltageBox.pos, _gd->enigme.voltage.resetButtonVoltageBox.size.x,
		_gd->enigme.voltage.resetButtonVoltageBox.size.y, 0);
}

void InitValidateButton(GameData* _gd)
{
	sfVector2f posValidate = { 1100 , 800 };
	sfVector2f sizeValidate = { 150 , 150 };

	_gd->enigme.voltage.validateButtonVoltageBox.buttonSprite[0] = LoadSprite("../Ressources/Assets/Voltage/val1.png", 0);
	_gd->enigme.voltage.validateButtonVoltageBox.buttonSprite[1] = LoadSprite("../Ressources/Assets/Voltage/val2.png", 0);
	_gd->enigme.voltage.validateButtonVoltageBox.buttonSprite[2] = LoadSprite("../Ressources/Assets/Voltage/val3.png", 0);

	_gd->enigme.voltage.validateButtonVoltageBox.pos = posValidate;
	_gd->enigme.voltage.validateButtonVoltageBox.size = sizeValidate;

	_gd->enigme.voltage.onSpriteValidateVoltageBox = sfFalse;
	_gd->enigme.voltage.clickValidateVoltageBox = sfFalse;

	_gd->enigme.voltage.validateButtonVoltageBox.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.voltage.validateButtonVoltageBox.forme, _gd->enigme.voltage.validateButtonVoltageBox.pos, _gd->enigme.voltage.validateButtonVoltageBox.size.x,
		_gd->enigme.voltage.validateButtonVoltageBox.size.y, 0);
}

void InitCardVoltage(GameData* _gd)
{
	sfVector2f posCard = { 800, _gd->sizeWindow.height / 2 - 130 };
	sfVector2f sizeCard = { 350, 350 };

	_gd->enigme.voltage.voltageCard.buttonSprite[0] = LoadSprite("../Ressources/Assets/Voltage/sortie_carte_1.png", 0);
	_gd->enigme.voltage.voltageCard.buttonSprite[1] = LoadSprite("../Ressources/Assets/Voltage/sortie_carte_2.png", 0);
	_gd->enigme.voltage.voltageCard.buttonSprite[2] = LoadSprite("../Ressources/Assets/Voltage/sortie_carte_3.png", 0);

	_gd->enigme.voltage.voltageCard.pos = posCard;
	_gd->enigme.voltage.voltageCard.size = sizeCard;

	_gd->enigme.voltage.leavingCard = sfFalse;

	_gd->enigme.voltage.stageCard = 0;
	_gd->enigme.voltage.timerVoltageCard = 0.0;

	_gd->enigme.voltage.voltageCard.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.voltage.voltageCard.forme, _gd->enigme.voltage.voltageCard.pos, _gd->enigme.voltage.voltageCard.size.x,
		_gd->enigme.voltage.voltageCard.size.y, 0);
}

void InitVoltageBox(GameData* _gd)
{
	InitButtonHelpVoltageBox(_gd);
	InitResetButton(_gd);
	InitValidateButton(_gd);
	InitCardVoltage(_gd);

	_gd->enigme.voltage.backgroundVoltage = LoadSprite("../Ressources/Assets/Voltage/interface_4.png", 0);

	_gd->enigme.voltage.levierNegatif = LoadSprite("../Ressources/Assets/Voltage/eteint.png", 1);
	_gd->enigme.voltage.levierNeutre = LoadSprite("../Ressources/Assets/Voltage/milieu.png", 1);
	_gd->enigme.voltage.levierPositif = LoadSprite("../Ressources/Assets/Voltage/allumer.png", 1);
	_gd->enigme.voltage.plus = LoadSprite("../Ressources/Assets/Voltage/plus.png", 1);
	_gd->enigme.voltage.moins = LoadSprite("../Ressources/Assets/Voltage/moins.png", 1);

	_gd->enigme.voltage.voltmetre = 0;
	_gd->enigme.voltage.volt = LoadText("../Ressources/Text/nasalization.ttf","", 1);
	_gd->enigme.voltage.resolvedDream_1 = sfFalse;
	_gd->enigme.voltage.leavingCard = sfFalse;

	_gd->enigme.voltage.diodeVoltageBoxEnigmeNonFini = LoadSprite("../Ressources/Assets/Mastermind/diode_rouge.png", 0);
	_gd->enigme.voltage.diodeVoltageBoxEnigmeFini = LoadSprite("../Ressources/Assets/Mastermind/diode_verte.png", 0);
	
	for (int i = 0; i < NB_LEVIER; i++)
	{
		_gd->enigme.voltage.etat[i] = neutre_negatif;
		_gd->enigme.voltage.pos[i].x = 100 * (i)+625;
		_gd->enigme.voltage.pos[i].y = 736;
		_gd->enigme.voltage.rectLevier[i] = sfRectangleShape_create();
		createRectangle(_gd->enigme.voltage.rectLevier[i], _gd->enigme.voltage.pos[i], 35, 35, 1);
	}

	_gd->enigme.voltage.levier[0] = 1;
	_gd->enigme.voltage.levier[1] = 2;
	_gd->enigme.voltage.levier[2] = 5;
	_gd->enigme.voltage.levier[3] = 10;
	_gd->enigme.voltage.levier[4] = 25;
	_gd->enigme.voltage.levier[5] = 50;
	_gd->enigme.voltage.levier[6] = 150;
	_gd->enigme.voltage.levier[7] = 300;

}

void DeleteVoltageSprite(GameData* _gd)
{
	for (int i = 0; i < 3; i++)
	{
		DeleteSprite(_gd->enigme.voltage.helpButtonVoltageBox.buttonSprite[i]);
		DeleteSprite(_gd->enigme.voltage.validateButtonVoltageBox.buttonSprite[i]);
		DeleteSprite(_gd->enigme.voltage.voltageCard.buttonSprite[i]);
	}
	for (int i = 0; i < NB_LEVIER; i++)
	{
		sfRectangleShape_destroy(_gd->enigme.voltage.rectLevier[i]);

	}
	DeleteSprite(_gd->enigme.voltage.backgroundVoltage);
	DeleteSprite(_gd->enigme.voltage.levierNeutre);
	DeleteSprite(_gd->enigme.voltage.levierNegatif);
	DeleteSprite(_gd->enigme.voltage.levierPositif);
	DeleteSprite(_gd->enigme.voltage.plus);
	DeleteSprite(_gd->enigme.voltage.moins);
	DeleteSprite(_gd->enigme.voltage.resetButtonVoltageBox.buttonSprite[0]);
	DeleteSprite(_gd->enigme.voltage.diodeVoltageBoxEnigmeFini);
	DeleteSprite(_gd->enigme.voltage.diodeVoltageBoxEnigmeNonFini);
	DeleteSprite(_gd->enigme.voltage.backgroundTutoVoltage);

	sfRectangleShape_destroy(_gd->enigme.voltage.helpButtonVoltageBox.forme);
	sfRectangleShape_destroy(_gd->enigme.voltage.resetButtonVoltageBox.forme);
	sfRectangleShape_destroy(_gd->enigme.voltage.validateButtonVoltageBox.forme);
	sfRectangleShape_destroy(_gd->enigme.voltage.voltageCard.forme);

	sfFont_destroy(sfText_getFont(_gd->enigme.voltage.volt));

}