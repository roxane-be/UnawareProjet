#include "UpdateSelecteurPerso.h"

void UpdateSelectPerso(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos;
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	if (isCollidingWithMouse(_gd->buttonsSelecteur[0].forme, tempPos, 0))
	{
		_gd->onSpriteButtonSelectG = sfTrue;
	}
	else
	{
		_gd->onSpriteButtonSelectG = sfFalse;
	}

	if (isCollidingWithMouse(_gd->buttonsSelecteur[1].forme, tempPos, 0))
	{
		_gd->onSpriteButtonSelectF = sfTrue;
	}
	else
	{
		_gd->onSpriteButtonSelectF = sfFalse;
	}

	if (isCollidingWithMouse(_gd->buttonCadreText.forme, tempPos, 0))
	{
		_gd->onSpriteCadreText = sfTrue;
	}
	else
	{
		_gd->onSpriteCadreText = sfFalse;
	}

	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (isCollidingWithMouse(_gd->buttonsSelecteur[0].forme, tempPos, 0))
			{
				_gd->choixPerso = 0;
				_gd->isSelect = sfTrue;

			}
			else if (isCollidingWithMouse(_gd->buttonsSelecteur[1].forme, tempPos, 0))
			{
				_gd->choixPerso = 1;
				_gd->isSelect = sfTrue;
			}
			else if (!isCollidingWithMouse(_gd->buttonCadreText.forme, tempPos, 0))
			{
				_gd->choixPerso = -1;
				_gd->isSelect = sfFalse;
			}

			if (isCollidingWithMouse(_gd->buttonCadreText.forme, tempPos, 0))
			{
				_gd->clickCadreText = sfTrue;
			}
			else if (!(isCollidingWithMouse(_gd->buttonsSelecteur[0].forme, tempPos, 0)
				|| isCollidingWithMouse(_gd->buttonsSelecteur[1].forme, tempPos, 0)))
			{
				_gd->clickCadreText = sfFalse;
			}
		}
	}

	if (_gd->clickCadreText == sfTrue)
	{
		char stringDraw[70];
		sprintf(stringDraw, "%s", _gd->persoName);
		sfText_setString(_gd->texts.namePerso.text, stringDraw);
	}
	else if (_gd->clickCadreText == sfFalse && _gd->persoName[0] == NULL)
	{
		char stringDraw[70] = "Entrez votre pseudo";
		sfText_setString(_gd->texts.namePerso.text, stringDraw);
	}

	if (sfKeyboard_isKeyPressed(sfKeyEscape))
	{
		_gd->gameState = menu;
	}

	if (sfKeyboard_isKeyPressed(sfKeyEnter) && _gd->isSelect == sfTrue)
	{
		_gd->gameState = play;
		_gd->world = intro;
		_gd->enigmeState = none;
		_gd->inGameState = cutscene;
		_gd->cutSceneState = vaisseauIntro;
		DeleteSpriteSelecteurPerso(_gd);
		InitCutScene(_gd);

		if (_gd->persoName[0] == NULL)
		{
			if (_gd->choixPerso == 0)
			{
				strcpy(_gd->persoName, _gd->tempNameG);
			}
			else if (_gd->choixPerso == 1)
			{
				strcpy(_gd->persoName, _gd->tempNameF);
			}

		}

		//printf("name : %s\n", _gd->persoName);

	}

}