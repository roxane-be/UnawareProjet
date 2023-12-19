#include "InitTutoDecryptage.h"

void InitTutoDecryptage(GameData* _gd)
{
	sfVector2f posButton = { 325, 915 };
	sfVector2f sizeButton = { 150, 150 };

	_gd->enigme.decryptage.backgroundTutoDecryptage = LoadSprite("../Ressources/Assets/Decryptage/Tuto/aide_ecrit.png", 0);

	_gd->enigme.decryptage.retourDecryptage.buttonSprite[0] = LoadSprite("../Ressources/Assets/Decryptage/Tuto/ret1.png", 0);
	_gd->enigme.decryptage.retourDecryptage.buttonSprite[1] = LoadSprite("../Ressources/Assets/Decryptage/Tuto/ret2.png", 0);
	_gd->enigme.decryptage.retourDecryptage.buttonSprite[2] = LoadSprite("../Ressources/Assets/Decryptage/Tuto/ret3.png", 0);

	_gd->enigme.decryptage.onSpriteRetourDecryptage = sfFalse;
	_gd->enigme.decryptage.clickRetourDecryptage = sfFalse;

	_gd->enigme.decryptage.retourDecryptage.pos = posButton;
	_gd->enigme.decryptage.retourDecryptage.size = sizeButton;

	_gd->enigme.decryptage.retourDecryptage.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.decryptage.retourDecryptage.forme, _gd->enigme.decryptage.retourDecryptage.pos, _gd->enigme.decryptage.retourDecryptage.size.x,
		_gd->enigme.decryptage.retourDecryptage.size.y, 0);
}