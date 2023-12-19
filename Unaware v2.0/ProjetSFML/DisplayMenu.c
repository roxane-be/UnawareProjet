#include "DisplayMenu.h"

//Buttons
void DrawButton(GameData* _gd, sfColor _colorText, sfVector2f _scale)
{

	BlitSprite(_gd->background, 0, 0, 0, _scale.x, _scale.y, _gd);

	for (int i = 0; i < 5; i++)
	{
		BlitSprite(_gd->buttons[i].sprite[i], _gd->buttons[i].pos.x, _gd->buttons[i].pos.y, 0, _scale.x, _scale.y, _gd);
	}

	if (_gd->onSpriteBN == sfTrue)
	{
		BlitSprite(_gd->selectSprite[0], _gd->buttons[0].pos.x - 90, _gd->buttons[0].pos.y - 25, 0, _scale.x, _scale.y, _gd);
	}
	if (_gd->onSpriteSO == sfTrue)
	{
		BlitSprite(_gd->selectSprite[1], _gd->buttons[1].pos.x - 90, _gd->buttons[1].pos.y - 25, 0, _scale.x, _scale.y, _gd);
	}
	if (_gd->onSpriteBC == sfTrue)
	{
		BlitSprite(_gd->selectSprite[0], _gd->buttons[2].pos.x - 90, _gd->buttons[2].pos.y - 25, 0, _scale.x, _scale.y, _gd);
	}
	if (_gd->onSpriteSA == sfTrue)
	{
		BlitSprite(_gd->selectSprite[1], _gd->buttons[3].pos.x - 90, _gd->buttons[3].pos.y - 25, 0, _scale.x, _scale.y, _gd);
	}
	if (_gd->onSpriteBQ == sfTrue)
	{
		BlitSprite(_gd->selectSprite[0], _gd->buttons[4].pos.x - 90, _gd->buttons[4].pos.y - 25, 0, _scale.x, _scale.y, _gd);
	}
}

void DisplayMenu(GameData* _gd)
{
	sfColor tempCol = { 255, 255, 255 };
	sfVector2f size = { 1, 1 };
	DrawButton(_gd, tempCol, size);
}

void DisplayCredit(GameData* _gd)
{
	BlitSprite(_gd->credit, 0, 0, 0, 1, 1, _gd);
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->quitCredit, NULL);
	BlitSprite(_gd->returnMenu, 20, 50, 0, 1, 1, _gd);

}

void DisplayOption(GameData* _gd)
{
	BlitSprite(_gd->options, 0, 0, 0, 1, 1, _gd);
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->quitOptions, NULL);
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->optionsSound, NULL);
	BlitSprite(_gd->returnMenu, 20, 50, 0, 1, 1, _gd);

	BlitSprite(_gd->buttons[5].sprite[5], _gd->buttons[5].pos.x, _gd->buttons[5].pos.y, 0, 1, 1, _gd);


	if (_gd->onSpriteBV == sfTrue)
	{
		BlitSprite(_gd->selectSprite[1], _gd->buttons[5].pos.x - 90, _gd->buttons[5].pos.y - 25, 0, 1, 1, _gd);
	}
}

void DisplayControle(GameData* _gd)
{
	BlitSprite(_gd->controle, 0, 0, 0, 1, 1, _gd);

	BlitSprite(_gd->returnMenu, 20, 50, 0, 1, 1, _gd);
}

void DisplayVolume(GameData* _gd)
{
	BlitSprite(_gd->volume, 0, 0, 0, 1, 1, _gd);
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->quitVolume, NULL);

	for (int i = 0; i < NB_CAT_SOUND; i++)
	{
		BlitSprite(_gd->barrVolume, _gd->posBarrVolume[i].x, _gd->posBarrVolume[i].y-30, 0, 1, 1, _gd);
		BlitSprite(_gd->cursorVolume, _gd->posCursorVolume[i].x+394, _gd->posCursorVolume[i].y-10, 0, 1, 1, _gd);

		//sfRenderWindow_drawRectangleShape(_gd->window, _gd->rectVolume[i], NULL);
		sfVector2f scale = { 1,1 };
		BlitText(_gd->volumePourcentage[i], _gd->posBarrVolume[i].x + 420, _gd->posBarrVolume[i].y - 60, sfWhite, scale, _gd->window);
	}
	for (int i = 0; i < NB_CAT_SOUND - 1; i++)
	{
		//sfRenderWindow_drawRectangleShape(_gd->window, _gd->rectTestVolume[i], NULL);
		BlitSprite(_gd->soundTest, _gd->posCursorVolumeRect[i].x + 840, _gd->posCursorVolumeRect[i].y + 140, 0, 0.35, 0.35, _gd);

	}

	BlitSprite(_gd->returnMenu, 20, 50, 0, 1, 1, _gd);

}

void DisplayPause(GameData* _gd)
{
	BlitSprite(_gd->pause, 0, 0, 0, 1, 1, _gd);
	BlitSprite(_gd->returnMenu, 20, 50, 0, 1, 1, _gd);

	BlitSprite(_gd->buttons[5].sprite[5], _gd->buttons[5].pos.x, _gd->buttons[5].pos.y, 0, 1, 1, _gd);
	BlitSprite(_gd->buttons[6].sprite[6], _gd->buttons[6].pos.x, _gd->buttons[6].pos.y, 0, 1, 1, _gd);
	BlitSprite(_gd->controleMenuPause.sprite[0], _gd->controleMenuPause.pos.x, _gd->controleMenuPause.pos.y, 0, 1, 1, _gd);

	if (_gd->onSpriteBV == sfTrue)
	{
		BlitSprite(_gd->selectSprite[1], _gd->buttons[5].pos.x - 90, _gd->buttons[5].pos.y - 25, 0, 1, 1, _gd);
	}
	if (_gd->onSpriteQuitPauseMenu == sfTrue)
	{
		BlitSprite(_gd->selectSprite[1], _gd->buttons[6].pos.x - 90, _gd->buttons[6].pos.y - 25, 0, 1, 1, _gd);
	}
	if (_gd->onSpriteControleMenuPause == sfTrue)
	{
		BlitSprite(_gd->selectSprite[1], _gd->controleMenuPause.pos.x - 90, _gd->controleMenuPause.pos.y - 25, 0, 1, 1, _gd);
	}
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->quitPause, NULL);
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->pauseSound, NULL);
}