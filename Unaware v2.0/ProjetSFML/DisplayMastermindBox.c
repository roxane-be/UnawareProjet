#include "DisplayMastermindBox.h"

void DisplayHelpButtonMastermindBox(GameData* _gd)
{
	//A decommenter quand on aura les assets du bouton aide pour le mastermind de la boite
	BlitSprite(_gd->enigme.houseBox.buttonHelpMastermindBox.buttonSprite[0], _gd->enigme.houseBox.buttonHelpMastermindBox.pos.x,
		_gd->enigme.houseBox.buttonHelpMastermindBox.pos.y, 0, 1, 1, _gd);

	if (_gd->enigme.houseBox.onSpriteHelpMastermindBox == sfTrue)
	{
		BlitSprite(_gd->enigme.houseBox.buttonHelpMastermindBox.buttonSprite[1], _gd->enigme.houseBox.buttonHelpMastermindBox.pos.x,
			_gd->enigme.houseBox.buttonHelpMastermindBox.pos.y, 0, 1, 1, _gd);
	}
	if (_gd->enigme.houseBox.clickHelpMastermindBox == sfTrue)
	{
		BlitSprite(_gd->enigme.houseBox.buttonHelpMastermindBox.buttonSprite[2], _gd->enigme.houseBox.buttonHelpMastermindBox.pos.x,
			_gd->enigme.houseBox.buttonHelpMastermindBox.pos.y, 0, 1, 1, _gd);
	}
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.doorDigicode.buttonHelpMastermindBox.forme, NULL);
}

void DisplayValidateButtonMastermindBox(GameData* _gd)
{
	BlitSprite(_gd->enigme.houseBox.buttonValidateBox.buttonSprite[0], _gd->enigme.houseBox.buttonValidateBox.pos.x - 30,
		_gd->enigme.houseBox.buttonValidateBox.pos.y - 20, 0, 1, 1, _gd);

	if (_gd->enigme.houseBox.onSpriteValidateBox == sfTrue)
	{
		BlitSprite(_gd->enigme.houseBox.buttonValidateBox.buttonSprite[1], _gd->enigme.houseBox.buttonValidateBox.pos.x - 30,
			_gd->enigme.houseBox.buttonValidateBox.pos.y - 20, 0, 1, 1, _gd);
	}

	if (_gd->enigme.houseBox.boiteOuverte == sfTrue)
	{
		BlitSprite(_gd->enigme.houseBox.buttonValidateBox.buttonSprite[2], _gd->enigme.houseBox.buttonValidateBox.pos.x - 30,
			_gd->enigme.houseBox.buttonValidateBox.pos.y - 20, 0, 1, 1, _gd);

		if (_gd->enigme.houseBox.pieceRecup == sfFalse)
		{
			BlitSprite(_gd->enigme.houseBox.pieceMastermindBox.buttonSprite[0], _gd->enigme.houseBox.buttonValidateBox.pos.x - 30,
				_gd->enigme.houseBox.buttonValidateBox.pos.y - 20, 0, 1, 1, _gd);
			//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.houseBox.pieceMastermindBox.forme, NULL);
		}
	}

	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.houseBox.buttonValidateBox.forme, NULL);
}

void DisplayMastermindBox(GameData* _gd)
{
	//affichage interface
	BlitSprite(_gd->enigme.houseBox.backgroundMastermindBox, 0, 0, 0, 1, 1, _gd);
	DisplayHelpButtonMastermindBox(_gd);
	DisplayValidateButtonMastermindBox(_gd);

	if (_gd->enigme.houseBox.boiteOuverte == sfFalse)
	{
		BlitSprite(_gd->enigme.houseBox.diodeMastermindBoxEnigmeNonFini, 1420, 930, 0, 1, 1, _gd);
	}
	else
	{
		BlitSprite(_gd->enigme.houseBox.diodeMastermindBoxEnigmeFini, 1420, 930, 0, 1, 1, _gd);
	}


	//changement de position ici pour le tableau
	for (int i = 0; i < TAB_TRY; i++)
	{
		for (int j = 0; j < NB_DIGICODE; j++)
		{
			int value = _gd->enigme.houseBox.tabTry[i][j];
			sfVector2f tempPos = { j * 115 + 620, i * 114 + 170 };

			//display chiffre numérique
			BlitSprite(_gd->sprites.tabChiffreBox[value].sprite,
				tempPos.x, tempPos.y, 0, 1, 1, _gd);

			tempPos.x = j * 66 + 1100;
			tempPos.y = i * 114 + 170;

			//affichage des diodes eteinte
			BlitSprite(_gd->sprites.diodeGreyBox.sprite,
				tempPos.x, tempPos.y, 0, 1, 1, _gd);
			//affiahche des diodes rouge

			if (i < _gd->enigme.houseBox.current)
			{
				BlitSprite(_gd->sprites.diodeRedBox.sprite,
					tempPos.x, tempPos.y, 0, 1, 1, _gd);
			}
			//affiache des diodes orange 
			if (_gd->enigme.houseBox.diodeYellow[i][j] == sfTrue)
			{
				BlitSprite(_gd->sprites.diodeYellowBox.sprite,
					tempPos.x, tempPos.y, 0, 1, 1, _gd);
			}

			//affiahche des diodes vertes
			if (_gd->enigme.houseBox.diodeGreen[i][j] == sfTrue)
			{
				BlitSprite(_gd->sprites.diodeGreenBox.sprite,
					tempPos.x, tempPos.y, 0, 1, 1, _gd);
			}


		}
	}

	//fleches de selection
	for (int i = 0; i < NB_ARROW; i++)
	{
		if (_gd->enigme.houseBox.arrowBox[i].isClicked == sfTrue)
		{
			UpdateAnimationButtonMastermindBox(_gd, i);
		}
		BlitSprite(_gd->enigme.houseBox.arrowBox[i].Timeline[_gd->enigme.houseBox.arrowBox[i].currentAnim],
			_gd->enigme.houseBox.arrowBox[i].pos.x,
			_gd->enigme.houseBox.arrowBox[i].pos.y,
			0, 1, 1, _gd);
	}

	//affiahche des nombres
	for (int i = 0; i < NB_DIGICODE; i++)
	{
		int value = _gd->enigme.houseBox.value[i];

		BlitSprite(_gd->sprites.tabChiffreBox[value].sprite,
			_gd->enigme.houseBox.caseDigicode[i].x,
			_gd->enigme.houseBox.caseDigicode[i].y,
			0, 1, 1, _gd);
	}
}
