#include "UpdateMenu.h"

void UpdateMenu(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos;
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	if (isCollidingWithMouse(_gd->buttons[0].forme, tempPos, 1))
	{
		_gd->onSpriteBN = sfTrue;
	}
	else
	{
		_gd->onSpriteBN = sfFalse;
	}

	if (isCollidingWithMouse(_gd->buttons[1].forme, tempPos, 1))
	{
		_gd->onSpriteSO = sfTrue;
	}
	else
	{
		_gd->onSpriteSO = sfFalse;
	}

	if (isCollidingWithMouse(_gd->buttons[2].forme, tempPos, 1))
	{
		_gd->onSpriteBC = sfTrue;
	}
	else
	{
		_gd->onSpriteBC = sfFalse;
	}

	if (isCollidingWithMouse(_gd->buttons[3].forme, tempPos, 1))
	{
		_gd->onSpriteSA = sfTrue;
	}
	else
	{
		_gd->onSpriteSA = sfFalse;
	}

	if (isCollidingWithMouse(_gd->buttons[4].forme, tempPos, 1))
	{
		_gd->onSpriteBQ = sfTrue;
	}
	else
	{
		_gd->onSpriteBQ = sfFalse;
	}

	if (isCollidingWithMouse(_gd->buttons[5].forme, tempPos, 1)
		&& _gd->gameState == option)
	{
		_gd->onSpriteBV = sfTrue;
	}
	else
	{
		_gd->onSpriteBV = sfFalse;
	}

}


void UpdateVolume(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos;
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;
	char stringDraw[999];

	
	if (sfMouse_isButtonPressed(sfMouseLeft))
	{

		if (isCollidingWithMouse(_gd->quitVolume, tempPos, 1) == 1
			&& _gd->world == begin)
		{
			sfSound_play(_gd->menuInteract.sound);
			_gd->gameState = option;
		}
		else if (isCollidingWithMouse(_gd->quitVolume, tempPos, 1) == 1)
		{
			sfSound_play(_gd->menuInteract.sound);
			_gd->gameState = pause;
		}


		for (int i = 0; i < NB_CAT_SOUND; i++)
		{
			
			if (isCollidingWithMouse(_gd->rectVolume[i], tempPos, 1) == 1
				&& i == 0)
			{
				//printf("%d   %d\n", mousePos.x, mousePos.y);
				sfSound_play(_gd->menuInteract.sound);
				_gd->posCursorVolume[i].x = mousePos.x - 420;
				_gd->soundGlobal = (tempPos.x - 780) / 6.85;
				if (_gd->soundGlobal < 0)
				{
					_gd->soundGlobal = 0;
				}
				else if (_gd->soundGlobal > 100)
				{
					_gd->soundGlobal = 100;
				}
				sprintf(stringDraw, "%.f%%", (_gd->soundGlobal));
				sfText_setString(_gd->volumePourcentage[i], stringDraw);
				sfSound_setVolume(_gd->menuInteract.sound, _gd->soundGlobal * _gd->soundInterraction);
			}
			else if (isCollidingWithMouse(_gd->rectVolume[i], tempPos, 1) == 1
				&& i == 1)
			{
				sfSound_play(_gd->menuInteract.sound);
				_gd->posCursorVolume[i].x = mousePos.x - 420;
				_gd->soundMusic = (tempPos.x - 780) / 685;

				if (_gd->soundMusic < 0)
				{
					_gd->soundMusic = 0;
				}
				else if (_gd->soundMusic > 1)
				{
					_gd->soundMusic = 1;
				}
				sprintf(stringDraw, "%.f%%", (_gd->soundMusic * 100));
				sfText_setString(_gd->volumePourcentage[i], stringDraw);
			}
			else if (isCollidingWithMouse(_gd->rectVolume[i], tempPos, 1) == 1
				&& i == 2)
			{
				sfSound_play(_gd->menuInteract.sound);
				_gd->posCursorVolume[i].x = mousePos.x - 420;
				_gd->soundAmbiance = (tempPos.x - 780) / 685;

				if (_gd->soundAmbiance < 0)
				{
					_gd->soundAmbiance = 0;
				}
				else if (_gd->soundAmbiance > 1)
				{
					_gd->soundAmbiance = 1;
				}
				sprintf(stringDraw, "%.f%%", (_gd->soundAmbiance * 100));
				sfText_setString(_gd->volumePourcentage[i], stringDraw);
			}
			else if (isCollidingWithMouse(_gd->rectVolume[i], tempPos, 1) == 1
				&& i == 3)
			{
				sfSound_play(_gd->menuInteract.sound);
				_gd->posCursorVolume[i].x = mousePos.x - 420;
				_gd->soundInterraction = (tempPos.x - 780) / 685;

				if (_gd->soundInterraction < 0)
				{
					_gd->soundInterraction = 0;
				}
				else if (_gd->soundInterraction > 1)
				{
					_gd->soundInterraction = 1;
				}
				sprintf(stringDraw, "%.f%%", (_gd->soundInterraction * 100));
				sfText_setString(_gd->volumePourcentage[i], stringDraw);
				sfSound_setVolume(_gd->menuInteract.sound, _gd->soundGlobal * _gd->soundInterraction);
			}

		}

	}
}