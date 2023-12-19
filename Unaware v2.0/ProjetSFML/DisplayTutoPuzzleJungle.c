#include "DisplayTutoPuzzleJungle.h"

void DisplayTutoPuzzleJungle(GameData* _gd)
{
	BlitSprite(_gd->enigme.puzzleJungle.backgroundPuzzleJungle, 0, 0, 0, 1, 1, _gd);
	BlitSprite(_gd->enigme.puzzleJungle.backgroundTutoPuzzleJungle, 0, 0, 0, 1, 1, _gd);

	BlitSprite(_gd->enigme.puzzleJungle.retourPuzzleJungle.buttonSprite[0], _gd->enigme.puzzleJungle.retourPuzzleJungle.pos.x - 30,
		_gd->enigme.puzzleJungle.retourPuzzleJungle.pos.y - 32, 0, 1, 1, _gd);

	if (_gd->enigme.puzzleJungle.onSpriteRetourPuzzleJungle == sfTrue
		&& _gd->enigme.puzzleJungle.clickRetourPuzzleJungle == sfFalse)
	{
		BlitSprite(_gd->enigme.puzzleJungle.retourPuzzleJungle.buttonSprite[1], _gd->enigme.puzzleJungle.retourPuzzleJungle.pos.x - 30,
			_gd->enigme.puzzleJungle.retourPuzzleJungle.pos.y - 32, 0, 1, 1, _gd);
	}
	if (_gd->enigme.puzzleJungle.clickRetourPuzzleJungle == sfTrue)
	{
		BlitSprite(_gd->enigme.puzzleJungle.retourPuzzleJungle.buttonSprite[2], _gd->enigme.puzzleJungle.retourPuzzleJungle.pos.x - 30,
			_gd->enigme.puzzleJungle.retourPuzzleJungle.pos.y - 32, 0, 1, 1, _gd);
	}

	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.puzzleJungle.retourPuzzleJungle.forme, NULL);
}