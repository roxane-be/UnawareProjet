#include "DisplayTutoPuzzle.h"

void DisplayTutoPuzzle(GameData* _gd)
{
	BlitSprite(_gd->enigme.utilityPuzzle.backgroundInterface, 0, 0, 0, 1, 1, _gd);
	BlitSprite(_gd->enigme.utilityPuzzle.backgroundTutoPuzzle, 0, -35, 0, 1, 1, _gd);

	BlitSprite(_gd->enigme.utilityPuzzle.retour.buttonSprite[0], _gd->enigme.utilityPuzzle.retour.pos.x, _gd->enigme.utilityPuzzle.retour.pos.y, 0, 1, 1, _gd);

	if (_gd->enigme.utilityPuzzle.onSpriteRetour == sfTrue)
	{
		BlitSprite(_gd->enigme.utilityPuzzle.retour.buttonSprite[1], _gd->enigme.utilityPuzzle.retour.pos.x, _gd->enigme.utilityPuzzle.retour.pos.y, 0, 1, 1, _gd);
	}

	if (_gd->enigme.utilityPuzzle.clickRetour == sfTrue)
	{
		BlitSprite(_gd->enigme.utilityPuzzle.retour.buttonSprite[2], _gd->enigme.utilityPuzzle.retour.pos.x, _gd->enigme.utilityPuzzle.retour.pos.y, 0, 1, 1, _gd);
	}
}