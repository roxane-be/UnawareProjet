#include "InitTutoPuzzleJungle.h"

void InitTutoPuzzleJungle(GameData* _gd)
{
	_gd->enigme.puzzleJungle.backgroundTutoPuzzleJungle = LoadSprite("../Ressources/Assets/PuzzleJungle/Tuto/tuto_tuyaux.png", 0);

	//boutton retour
	sfVector2f posButton = { 1530, 548 };
	sfVector2f sizeButton = { 200, 200 };

	_gd->enigme.puzzleJungle.retourPuzzleJungle.buttonSprite[0] = LoadSprite("../Ressources/Assets/PuzzleJungle/Tuto/retour_tuyaux1.png", 0);
	_gd->enigme.puzzleJungle.retourPuzzleJungle.buttonSprite[1] = LoadSprite("../Ressources/Assets/PuzzleJungle/Tuto/retour_tuyaux2.png", 0);
	_gd->enigme.puzzleJungle.retourPuzzleJungle.buttonSprite[2] = LoadSprite("../Ressources/Assets/PuzzleJungle/Tuto/retour_tuyaux3.png", 0);

	_gd->enigme.puzzleJungle.onSpriteRetourPuzzleJungle = sfFalse;
	_gd->enigme.puzzleJungle.clickRetourPuzzleJungle = sfFalse;

	_gd->enigme.puzzleJungle.retourPuzzleJungle.pos = posButton;
	_gd->enigme.puzzleJungle.retourPuzzleJungle.size = sizeButton;

	_gd->enigme.puzzleJungle.retourPuzzleJungle.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.puzzleJungle.retourPuzzleJungle.forme, _gd->enigme.puzzleJungle.retourPuzzleJungle.pos, _gd->enigme.puzzleJungle.retourPuzzleJungle.size.x,
		_gd->enigme.puzzleJungle.retourPuzzleJungle.size.y, 0);
}