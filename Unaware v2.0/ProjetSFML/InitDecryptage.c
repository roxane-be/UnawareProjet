#include "initDecryptage.h"

void InitButtonDecryptage(GameData* _gd)
{
	//bouton valider
	sfVector2f posButton = { 230, 568 };
	sfVector2f sizeButton = { 150, 150 };

	_gd->enigme.decryptage.validateDecryptage.buttonSprite[0] = LoadSprite("../Ressources/Assets/Decryptage/valid1.png", 0);
	_gd->enigme.decryptage.validateDecryptage.buttonSprite[1] = LoadSprite("../Ressources/Assets/Decryptage/valid2.png", 0);
	_gd->enigme.decryptage.validateDecryptage.buttonSprite[2] = LoadSprite("../Ressources/Assets/Decryptage/valid3.png", 0);

	_gd->enigme.decryptage.onSpriteValidateDecryptage = sfFalse;
	_gd->enigme.decryptage.clickValidateDecryptage = sfFalse;

	_gd->enigme.decryptage.validateDecryptage.pos = posButton;
	_gd->enigme.decryptage.validateDecryptage.size = sizeButton;

	_gd->enigme.decryptage.validateDecryptage.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.decryptage.validateDecryptage.forme, _gd->enigme.decryptage.validateDecryptage.pos,
		_gd->enigme.decryptage.validateDecryptage.size.x, _gd->enigme.decryptage.validateDecryptage.size.y, 0);

	//bouton reset
	posButton.x = 381;
	posButton.y = 569;

	_gd->enigme.decryptage.resetDecryptage.buttonSprite[0] = LoadSprite("../Ressources/Assets/Decryptage/rei1.png", 0);
	_gd->enigme.decryptage.resetDecryptage.buttonSprite[1] = LoadSprite("../Ressources/Assets/Decryptage/rei2.png", 0);
	_gd->enigme.decryptage.resetDecryptage.buttonSprite[2] = LoadSprite("../Ressources/Assets/Decryptage/rei3.png", 0);

	_gd->enigme.decryptage.onSpriteResetDecryptage = sfFalse;
	_gd->enigme.decryptage.clickResetDecryptage = sfFalse;

	_gd->enigme.decryptage.resetDecryptage.pos = posButton;
	_gd->enigme.decryptage.resetDecryptage.size = sizeButton;

	_gd->enigme.decryptage.resetDecryptage.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.decryptage.resetDecryptage.forme, _gd->enigme.decryptage.resetDecryptage.pos,
		_gd->enigme.decryptage.resetDecryptage.size.x, _gd->enigme.decryptage.resetDecryptage.size.y, 0);

	//bouton quitter
	posButton.x = 535;
	posButton.y = 569;

	_gd->enigme.decryptage.quitDecryptage.buttonSprite[0] = LoadSprite("../Ressources/Assets/Decryptage/quit1.png", 0);
	_gd->enigme.decryptage.quitDecryptage.buttonSprite[1] = LoadSprite("../Ressources/Assets/Decryptage/quit2.png", 0);
	_gd->enigme.decryptage.quitDecryptage.buttonSprite[2] = LoadSprite("../Ressources/Assets/Decryptage/quit3.png", 0);

	_gd->enigme.decryptage.onSpriteQuitDecryptage = sfFalse;
	_gd->enigme.decryptage.clickQuitDecryptage = sfFalse;

	_gd->enigme.decryptage.quitDecryptage.pos = posButton;
	_gd->enigme.decryptage.quitDecryptage.size = sizeButton;

	_gd->enigme.decryptage.quitDecryptage.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.decryptage.quitDecryptage.forme, _gd->enigme.decryptage.quitDecryptage.pos,
		_gd->enigme.decryptage.quitDecryptage.size.x, _gd->enigme.decryptage.quitDecryptage.size.y, 0);

	//bouton aide
	posButton.x = 40;
	posButton.y = 932;
	sizeButton.x = 340;
	sizeButton.y = 150;

	_gd->enigme.decryptage.aideDecryptage.buttonSprite[0] = LoadSprite("../Ressources/Assets/Decryptage/aid1.png", 0);
	_gd->enigme.decryptage.aideDecryptage.buttonSprite[1] = LoadSprite("../Ressources/Assets/Decryptage/aid2.png", 0);
	_gd->enigme.decryptage.aideDecryptage.buttonSprite[2] = LoadSprite("../Ressources/Assets/Decryptage/aid3.png", 0);

	_gd->enigme.decryptage.onSpriteAideDecryptage = sfFalse;
	_gd->enigme.decryptage.clickAideDecryptage = sfFalse;

	_gd->enigme.decryptage.aideDecryptage.pos = posButton;
	_gd->enigme.decryptage.aideDecryptage.size = sizeButton;

	_gd->enigme.decryptage.aideDecryptage.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.decryptage.aideDecryptage.forme, _gd->enigme.decryptage.aideDecryptage.pos,
		_gd->enigme.decryptage.aideDecryptage.size.x, _gd->enigme.decryptage.aideDecryptage.size.y, 0);
}

void InitDecryptage(GameData* _gd) 
{
	_gd->enigme.decryptage.backgroundDecryptage = LoadSprite("../Ressources/Assets/Decryptage/fond.png", 0);
	_gd->enigme.decryptage.backgroundPapier[0] = LoadSprite("../Ressources/Assets/Decryptage/9_2.png", 0);
	_gd->enigme.decryptage.backgroundPapier[1] = LoadSprite("../Ressources/Assets/Decryptage/2_2.png", 0);
	_gd->enigme.decryptage.backgroundPapier[2] = LoadSprite("../Ressources/Assets/Decryptage/4_2.png", 0);
	_gd->enigme.decryptage.backgroundPapier[3] = LoadSprite("../Ressources/Assets/Decryptage/5_2.png", 0);
	_gd->enigme.decryptage.backgroundPapier[4] = LoadSprite("../Ressources/Assets/Decryptage/6_2.png", 0);
	_gd->enigme.decryptage.backgroundPapier[5] = LoadSprite("../Ressources/Assets/Decryptage/10_2.png", 0);
	_gd->enigme.decryptage.backgroundPapier[6] = LoadSprite("../Ressources/Assets/Decryptage/11_2.png", 0);
	_gd->enigme.decryptage.backgroundPapier[7] = LoadSprite("../Ressources/Assets/Decryptage/12_2.png", 0);
	_gd->enigme.decryptage.backgroundPapier[8] = LoadSprite("../Ressources/Assets/Decryptage/14_2.png", 0);
	InitButtonDecryptage(_gd);

	for (int i = 0; i < 9; i++)
	{
		_gd->enigme.decryptage.isVisible[i] = sfFalse;
	}

	//_gd->enigme.decryptage.word[0] = '/0';
	
	_gd->enigme.decryptage.text = LoadText("../Ressources/Text/HoneyCute.otf","", 0);
	sfText_setCharacterSize(_gd->enigme.decryptage.text, 150);
	_gd->enigme.decryptage.pos.x = 200;
	_gd->enigme.decryptage.pos.y = 700;

	_gd->enigme.decryptage.resolved = sfFalse;
	InitTutoDecryptage(_gd);


	_gd->enigme.decryptage.nbPaperRecup = 0;
	_gd->enigme.decryptage.againOpen = sfFalse;
	_gd->enigme.decryptage.paper = LoadSprite("../Ressources/Assets/Decryptage/morceau_papier.png", 0);
	_gd->enigme.decryptage.paperHUD = LoadSprite("../Ressources/Assets/Decryptage/tit_papier.png", 0);
	_gd->enigme.decryptage.plus1 = LoadSprite("../Ressources/Assets/Decryptage/plus1.png", 0);

	for (int i = 0; i < 4; i++)
	{
		_gd->enigme.decryptage.paperRecup[i] = sfFalse;
	}

	_gd->enigme.decryptage.PuzzleRec = sfFalse;
	_gd->enigme.decryptage.InRecup = sfFalse;
	_gd->enigme.decryptage.upPlus = 0;
	_gd->enigme.decryptage.TwoPaper = sfFalse;
}