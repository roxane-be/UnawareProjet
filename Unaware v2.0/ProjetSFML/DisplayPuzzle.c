#include "DisplayPuzzle.h"

void drawButtons(GameData* _gd)
{
	sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.utilityPuzzle.validate.forme, NULL);
	sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.utilityPuzzle.quit.forme, NULL);
	sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.utilityPuzzle.reset.forme, NULL);
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->utilityPuzzle.help.forme, NULL);

	BlitSprite(_gd->enigme.utilityPuzzle.validate.buttonSprite[0], _gd->enigme.utilityPuzzle.validate.pos.x, _gd->enigme.utilityPuzzle.validate.pos.y, 0, 1, 1, _gd);

	BlitSprite(_gd->enigme.utilityPuzzle.reset.buttonSprite[0], _gd->enigme.utilityPuzzle.reset.pos.x - 6, _gd->enigme.utilityPuzzle.reset.pos.y + 15, 0, 1, 1, _gd);

	BlitSprite(_gd->enigme.utilityPuzzle.quit.buttonSprite[0], _gd->enigme.utilityPuzzle.quit.pos.x + 5, _gd->enigme.utilityPuzzle.quit.pos.y + 10, 0, 1, 1, _gd);

	BlitSprite(_gd->enigme.utilityPuzzle.help.buttonSprite[0], _gd->enigme.utilityPuzzle.help.pos.x - 30, _gd->enigme.utilityPuzzle.help.pos.y - 10, 0, 1, 1, _gd);

	if (_gd->enigme.utilityPuzzle.onSpriteValidate == sfTrue)
	{
		BlitSprite(_gd->enigme.utilityPuzzle.validate.buttonSprite[1], _gd->enigme.utilityPuzzle.validate.pos.x, _gd->enigme.utilityPuzzle.validate.pos.y, 0, 1, 1, _gd);
	}
	if (_gd->enigme.utilityPuzzle.onSpriteReset == sfTrue)
	{
		BlitSprite(_gd->enigme.utilityPuzzle.reset.buttonSprite[1], _gd->enigme.utilityPuzzle.reset.pos.x - 6, _gd->enigme.utilityPuzzle.reset.pos.y + 15, 0, 1, 1, _gd);
	}
	if (_gd->enigme.utilityPuzzle.onSpriteQuit == sfTrue)
	{
		BlitSprite(_gd->enigme.utilityPuzzle.quit.buttonSprite[1], _gd->enigme.utilityPuzzle.quit.pos.x + 5, _gd->enigme.utilityPuzzle.quit.pos.y + 10, 0, 1, 1, _gd);
	}
	if (_gd->enigme.utilityPuzzle.onSpriteHelp == sfTrue)
	{
		BlitSprite(_gd->enigme.utilityPuzzle.help.buttonSprite[1], _gd->enigme.utilityPuzzle.help.pos.x - 30, _gd->enigme.utilityPuzzle.help.pos.y - 10, 0, 1, 1, _gd);
	}

	if (_gd->enigme.utilityPuzzle.clickValidate == sfTrue)
	{

		(_gd->enigme.utilityPuzzle.validate.buttonSprite[2], _gd->enigme.utilityPuzzle.validate.pos.x, _gd->enigme.utilityPuzzle.validate.pos.y, 0, 1, 1, _gd);
	}
	if (_gd->enigme.utilityPuzzle.clickReset == sfTrue)
	{
		BlitSprite(_gd->enigme.utilityPuzzle.reset.buttonSprite[2], _gd->enigme.utilityPuzzle.reset.pos.x - 6, _gd->enigme.utilityPuzzle.reset.pos.y + 15, 0, 1, 1, _gd);
	}
	if (_gd->enigme.utilityPuzzle.clickQuit == sfTrue)
	{
		BlitSprite(_gd->enigme.utilityPuzzle.quit.buttonSprite[2], _gd->enigme.utilityPuzzle.quit.pos.x + 5, _gd->enigme.utilityPuzzle.quit.pos.y + 10, 0, 1, 1, _gd);
	}
	if (_gd->enigme.utilityPuzzle.clickHelp == sfTrue)
	{
		BlitSprite(_gd->enigme.utilityPuzzle.help.buttonSprite[2], _gd->enigme.utilityPuzzle.help.pos.x - 30, _gd->enigme.utilityPuzzle.help.pos.y - 10, 0, 1, 1, _gd);
	}
}

void DisplayPuzzle(GameData* _gd)
{
	BlitSprite(_gd->enigme.utilityPuzzle.backgroundInterface, 0, 0, 0, 1, 1, _gd);
	sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.utilityPuzzle.cadre1, NULL);
	sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.utilityPuzzle.cadre2, NULL);

	drawButtons(_gd);

	/*for (int i = 0; i < _gd->utilityPuzzle.countPuzzle; i++)
	{
		sfRenderWindow_drawRectangleShape(_gd->window, _gd->puzzle[i].forme, NULL);
	}*/

	for (int i = 0; i < _gd->enigme.utilityPuzzle.countPiece; i++)
	{
		if (_gd->enigme.utilityPuzzle.piece[i].isOccupied == 0
			&& _gd->enigme.utilityPuzzle.piece[i].isPosed == 0)
		{
			sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.utilityPuzzle.piece[i].forme, NULL);

		}
		sfVector2f temp = sfRectangleShape_getPosition(_gd->enigme.utilityPuzzle.piece[i].forme);

		sfVector2f scale = { 1, 1 };

		if (_gd->enigme.utilityPuzzle.piece[i].isPosed == 0
			&& _gd->enigme.utilityPuzzle.piece[i].isOccupied == 0)
		{
			scale.x = 0.54;
			scale.y = 0.54;
		}
		else if (_gd->enigme.utilityPuzzle.piece[i].isPosed == 1
			)
		{
			scale.x = 1.05;
			scale.y = 1.05;
		}

		if (_gd->enigme.utilityPuzzle.piece[i].isVisible == sfTrue
			&& _gd->enigme.utilityPuzzle.piece[i].isOccupied == 0)
		{
			BlitSprite(_gd->enigme.utilityPuzzle.piece[i].sprite, temp.x, temp.y, 0, scale.x, scale.y, _gd);
		}
	}


	for (int i = 0; i < _gd->enigme.utilityPuzzle.countPiece; i++)
	{
		if (_gd->enigme.utilityPuzzle.piece[i].isOccupied == 1
			&& _gd->enigme.utilityPuzzle.piece[i].isPosed == 0
			&& _gd->enigme.utilityPuzzle.piece[i].isVisible == sfTrue)
		{
			sfVector2f temp = sfRectangleShape_getPosition(_gd->enigme.utilityPuzzle.piece[i].forme);
			sfVector2f scale = { 1.05, 1.05 };
			temp.x -= 76.5;
			temp.y -= 76.5;
			BlitSprite(_gd->enigme.utilityPuzzle.piece[i].sprite, temp.x, temp.y, 0, scale.x, scale.y, _gd);
		}
	}
}