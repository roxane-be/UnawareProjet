#include "InitTutoDiode.h"

void InitTutoDiode(GameData* _gd)
{
	sfVector2f posRetour = { 1400, 865 };
	sfVector2f sizeRetour = { 200, 200 };

	_gd->enigme.interupteur.backgroundTutoDiode3x3 = LoadSprite("../Ressources/Assets/EnigmeDiode/AideDiode/tuto_feuille.png", 0);
	_gd->enigme.interupteur.backgroundTutoDiodeSymbole = LoadSprite("../Ressources/Assets/EnigmeDiode/AideDiode/tuto_feuilleSymbole.png", 0);
	_gd->enigme.interupteur.backgroundSymboleDiode = LoadSprite("../Ressources/Assets/EnigmeDiode/AideDiode/aide_feuilleSymbole.png", 0);
	_gd->enigme.interupteur.backgroundTutoDiodeFin = LoadSprite("../Ressources/Assets/EnigmeDiode/AideDiode/tuto_feuille.png", 0);

	//bouton retour
	_gd->enigme.interupteur.retourButtonDiode.buttonSprite[0] = LoadSprite("../Ressources/Assets/EnigmeDiode/AideDiode/retourfeuille1.png", 0);
	_gd->enigme.interupteur.retourButtonDiode.buttonSprite[1] = LoadSprite("../Ressources/Assets/EnigmeDiode/AideDiode/retourfeuille2.png", 0);
	_gd->enigme.interupteur.retourButtonDiode.buttonSprite[2] = LoadSprite("../Ressources/Assets/EnigmeDiode/AideDiode/retourfeuille3.png", 0);

	_gd->enigme.interupteur.retourButtonDiode.pos = posRetour;
	_gd->enigme.interupteur.retourButtonDiode.size = sizeRetour;

	_gd->enigme.interupteur.onSpriteRetourButtonDiode = sfFalse;
	_gd->enigme.interupteur.clickRetourButtonDiode = sfFalse;

	_gd->enigme.interupteur.retourButtonDiode.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.interupteur.retourButtonDiode.forme, _gd->enigme.interupteur.retourButtonDiode.pos,
		_gd->enigme.interupteur.retourButtonDiode.size.x, _gd->enigme.interupteur.retourButtonDiode.size.y, 0);

	//Bouton amenant au symbole a partir du tuto
	sfVector2f posSymboleButtonTuto = { 259, 745 };
	sfVector2f sizeSymboleButtonTuto = { 200, 200 };

	_gd->enigme.interupteur.symboleButtonDiodeTuto.buttonSprite[0] = LoadSprite("../Ressources/Assets/EnigmeDiode/AideDiode/feuille_symbole.png", 0);
	_gd->enigme.interupteur.symboleButtonDiodeTuto.buttonSprite[1] = LoadSprite("../Ressources/Assets/EnigmeDiode/AideDiode/feuille_symbole2.png", 0);
	_gd->enigme.interupteur.symboleButtonDiodeTuto.buttonSprite[2] = LoadSprite("../Ressources/Assets/EnigmeDiode/AideDiode/feuille_symbole3.png", 0);

	_gd->enigme.interupteur.onSpriteSymboleButtonDiodeTuto = sfFalse;
	_gd->enigme.interupteur.clickSymboleButtonDiodeTuto = sfFalse;

	_gd->enigme.interupteur.symboleButtonDiodeTuto.pos = posSymboleButtonTuto;
	_gd->enigme.interupteur.symboleButtonDiodeTuto.size = sizeSymboleButtonTuto;

	_gd->enigme.interupteur.symboleButtonDiodeTuto.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.interupteur.symboleButtonDiodeTuto.forme, _gd->enigme.interupteur.symboleButtonDiodeTuto.pos,
		_gd->enigme.interupteur.symboleButtonDiodeTuto.size.x, _gd->enigme.interupteur.symboleButtonDiodeTuto.size.y, 0);

}