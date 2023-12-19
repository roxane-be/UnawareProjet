#include "DisplayMastermindIntro.h"

void DisplayButtonsMastermindIntro(GameData* _gd)
{
	//Affichage boutton aide
	//sfRectangleShape_setFillColor(_gd->enigme.doorDigicode.buttonHelp.forme, sfGreen);
	BlitSprite(_gd->enigme.doorDigicode.buttonHelp.buttonSprite[0], _gd->enigme.doorDigicode.buttonHelp.pos.x, _gd->enigme.doorDigicode.buttonHelp.pos.y,
		0, 0.9, 0.9, _gd);
	if (_gd->enigme.doorDigicode.onSpriteHelp == sfTrue)
	{
		BlitSprite(_gd->enigme.doorDigicode.buttonHelp.buttonSprite[1], _gd->enigme.doorDigicode.buttonHelp.pos.x, _gd->enigme.doorDigicode.buttonHelp.pos.y,
			0, 0.9, 0.9, _gd);
	}

	if (_gd->enigme.doorDigicode.clickHelp == sfTrue)
	{
		BlitSprite(_gd->enigme.doorDigicode.buttonHelp.buttonSprite[2], _gd->enigme.doorDigicode.buttonHelp.pos.x, _gd->enigme.doorDigicode.buttonHelp.pos.y,
			0, 0.9, 0.9, _gd);
	}

	//sfRectangleShape_setOutlineColor(_gd->enigme.doorDigicode.buttonHelp.forme, sfBlack);
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.doorDigicode.buttonHelp.forme, NULL);

	//Affichage boutton quitter mastermind
	//sfRectangleShape_setFillColor(_gd->enigme.doorDigicode.buttonQuit.forme, sfBlue);
	BlitSprite(_gd->enigme.doorDigicode.buttonQuit.buttonSprite[0], _gd->enigme.doorDigicode.buttonQuit.pos.x, _gd->enigme.doorDigicode.buttonQuit.pos.y,
		0, 1, 1, _gd);

	if (_gd->enigme.doorDigicode.onSpriteQuit == sfTrue)
	{
		BlitSprite(_gd->enigme.doorDigicode.buttonQuit.buttonSprite[1], _gd->enigme.doorDigicode.buttonQuit.pos.x, _gd->enigme.doorDigicode.buttonQuit.pos.y,
			0, 1, 1, _gd);
	}

	if (_gd->enigme.doorDigicode.clickQuit == sfTrue)
	{
		BlitSprite(_gd->enigme.doorDigicode.buttonQuit.buttonSprite[2], _gd->enigme.doorDigicode.buttonQuit.pos.x, _gd->enigme.doorDigicode.buttonQuit.pos.y,
			0, 1, 1, _gd);
	}

	//sfRectangleShape_setOutlineColor(_gd->enigme.doorDigicode.buttonQuit.forme, sfBlack);
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.doorDigicode.buttonQuit.forme, NULL);

	BlitSprite(_gd->enigme.doorDigicode.buttonValidate.buttonSprite[0], _gd->enigme.doorDigicode.buttonValidate.pos.x, _gd->enigme.doorDigicode.buttonValidate.pos.y,
		0, 1, 1, _gd);

	if (_gd->enigme.doorDigicode.onSpriteValidate == sfTrue)
	{
		BlitSprite(_gd->enigme.doorDigicode.buttonValidate.buttonSprite[1], _gd->enigme.doorDigicode.buttonValidate.pos.x, _gd->enigme.doorDigicode.buttonValidate.pos.y,
			0, 1, 1, _gd);
	}

	if (_gd->enigme.doorDigicode.clickValidate == sfTrue)
	{
		BlitSprite(_gd->enigme.doorDigicode.buttonValidate.buttonSprite[2], _gd->enigme.doorDigicode.buttonValidate.pos.x, _gd->enigme.doorDigicode.buttonValidate.pos.y,
			0, 1, 1, _gd);
	}
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.doorDigicode.buttonValidate.forme, NULL);
}

void DisplayMastermindIntro(GameData* _gd)
{
	//interface enigme
	BlitSprite(_gd->sprites.backgroundInterfaceIntro.sprite, 0, 0, 0, 1, 1, _gd);

	//Afficher les bouttons d'interface
	DisplayButtonsMastermindIntro(_gd);

	int tabTry = TAB_TRY;

	//changement de position ici pour le tableau
	for (int i = 0; i < tabTry; i++)
	{
		for (int j = 0; j < NB_DIGICODE; j++)
		{
			int value = _gd->enigme.doorDigicode.tabTry[i][j];
			sfVector2f tempPos = { j * 115 + 630, i * 88 + 200 };

			//display chiffre numérique
			BlitSprite(_gd->sprites.tabChiffreIntro[value].sprite,
				tempPos.x, tempPos.y, 0, 1, 1, _gd);

			tempPos.x = j * 66 + 1075;
			tempPos.y = i * 88 + 200;

			//affiche les diode éteintes de base
			BlitSprite(_gd->sprites.diodeGreyIntro.sprite,
				tempPos.x, tempPos.y, 0, 1, 1, _gd);

			//affiche les diode orange
			if (_gd->enigme.doorDigicode.diodeYellow[i][j] == sfTrue)
			{
				BlitSprite(_gd->sprites.diodeYellowIntro.sprite,
					tempPos.x, tempPos.y, 0, 1, 1, _gd);
			}

			//affiche les diode verte
			if (_gd->enigme.doorDigicode.diodeGreen[i][j] == sfTrue)
			{
				BlitSprite(_gd->sprites.diodeGreenIntro.sprite,
					tempPos.x, tempPos.y, 0, 1, 1, _gd);
			}
		}
	}

	//affiche les fleches
	for (int i = 0; i < NB_ARROW; i++)
	{
		if (_gd->enigme.doorDigicode.arrowIntro[i].isClicked == sfTrue)
		{
			UpdateAnimationButtonMastermindIntro(_gd, i);
		}
		BlitSprite(_gd->enigme.doorDigicode.arrowIntro[i].Timeline[_gd->enigme.doorDigicode.arrowIntro[i].currentAnim],
			_gd->enigme.doorDigicode.arrowIntro[i].pos.x,
			_gd->enigme.doorDigicode.arrowIntro[i].pos.y,
			0, 1, 1, _gd);
	}

	//affiche les chiffres
	for (int i = 0; i < NB_DIGICODE; i++)
	{
		int value = _gd->enigme.doorDigicode.value[i];

		BlitSprite(_gd->sprites.tabChiffreIntro[value].sprite,
			_gd->enigme.doorDigicode.caseDigicode[i].x,
			_gd->enigme.doorDigicode.caseDigicode[i].y,
			0, 1, 1, _gd);
	}
}
