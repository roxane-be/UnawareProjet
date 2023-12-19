#include "InitTutoBox.h"

void InitTutoBox(GameData* _gd)
{
	_gd->enigme.houseBox.backgroundTutoBox = LoadSprite("../Ressources/Assets/Box/fond.png", 0);
	_gd->enigme.houseBox.backgroundTutoMastermindBox = LoadSprite("../Ressources/Assets/Mastermind/aide_interface_mastermindbox.png", 0);
	_gd->utilityPieceBoite.backgroundTutoVis = LoadSprite("../Ressources/Assets/BoxPlaque/aide_interface_plaquevis.png", 0);
	_gd->utilityCable.backgroundTutoCableBox = LoadSprite("../Ressources/Assets/CableBox/aide_interface_cable.png", 0);
	_gd->enigme.voltage.backgroundTutoVoltage = LoadSprite("../Ressources/Assets/Voltage/aide_interface_voltage.png", 0);

	//Bouton retour
	_gd->enigme.houseBox.retourButtonBox.buttonSprite[0] = LoadSprite("../Ressources/Assets/Box/retour_1.png", 0);
	_gd->enigme.houseBox.retourButtonBox.buttonSprite[1] = LoadSprite("../Ressources/Assets/Box/retour_2.png", 0);
	_gd->enigme.houseBox.retourButtonBox.buttonSprite[2] = LoadSprite("../Ressources/Assets/Box/retour_3.png", 0);

	_gd->enigme.houseBox.onSpriteRetourButtonBox = sfFalse;
	_gd->enigme.houseBox.clickRetourButtonBox = sfFalse;

	_gd->enigme.houseBox.retourButtonBox.pos.x = _gd->sizeWindow.width / 2 + 373;
	_gd->enigme.houseBox.retourButtonBox.pos.y = 941;

	_gd->enigme.houseBox.retourButtonBox.size.x = 150;
	_gd->enigme.houseBox.retourButtonBox.size.y = 150;

	_gd->enigme.houseBox.retourButtonBox.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.houseBox.retourButtonBox.forme, _gd->enigme.houseBox.retourButtonBox.pos,
		_gd->enigme.houseBox.retourButtonBox.size.x, _gd->enigme.houseBox.retourButtonBox.size.y, 0);


}