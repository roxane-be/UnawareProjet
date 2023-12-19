#include "InitTutoPuzzle.h"

void InitTutoPuzzle(GameData* _gd)
{
	_gd->enigme.utilityPuzzle.backgroundTutoPuzzle = LoadSprite("../Ressources/Assets/Puzzle/aide_puzzle.png", 0);

	_gd->enigme.utilityPuzzle.retour.buttonSprite[0] = LoadSprite("../Ressources/Assets/Puzzle/bouton/retour_1.png", 0);
	_gd->enigme.utilityPuzzle.retour.buttonSprite[1] = LoadSprite("../Ressources/Assets/Puzzle/bouton/retour_2.png", 0);
	_gd->enigme.utilityPuzzle.retour.buttonSprite[2] = LoadSprite("../Ressources/Assets/Puzzle/bouton/retour_3.png", 0);

	_gd->enigme.utilityPuzzle.clickRetour = sfFalse;
	_gd->enigme.utilityPuzzle.onSpriteRetour = sfFalse;

	_gd->enigme.utilityPuzzle.retour.size.x = 170;
	_gd->enigme.utilityPuzzle.retour.size.y = 150;

	_gd->enigme.utilityPuzzle.retour.pos.x = (_gd->sizeWindow.width / 2) - (_gd->enigme.utilityPuzzle.retour.size.x / 2) + 5;
	_gd->enigme.utilityPuzzle.retour.pos.y = 790;

	_gd->enigme.utilityPuzzle.retour.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.utilityPuzzle.retour.forme, _gd->enigme.utilityPuzzle.retour.pos, _gd->enigme.utilityPuzzle.retour.size.x, _gd->enigme.utilityPuzzle.retour.size.y, 0);
}