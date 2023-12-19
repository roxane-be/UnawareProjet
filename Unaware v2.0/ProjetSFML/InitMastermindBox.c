#include "InitMastermindBox.h"

void InitAnimButtonMastermindBox(GameData* _gd, int _id)
{
	_gd->nbSpriteAnim = 0;
	_gd->push = 0;

	char chemin[100] = "../Ressources/Assets/Mastermind/touche/"; //chemin d'acces au dossier de sprite pour charger l'anim

	FILE* f;
	char tab[1000] = { 0 };

	if (!(f = fopen("../Ressources/Assets/Mastermind/touche/animation.txt", "r"))) //lecteur du fichier
	{
		printf("Erreur d'acces au fichier\n");
		exit(EXIT_FAILURE);
	}

	while (fscanf(f, "%s", tab) != EOF)
	{
		if (!_stricmp(tab, "SPRITES"))
		{
			fscanf(f, "%d", &_gd->nbSpriteAnim);

			_gd->enigme.houseBox.arrowBox[_id].Timeline = (sfSprite**)malloc(sizeof(sfSprite*) * _gd->nbSpriteAnim);

			for (int i = 0; i < _gd->nbSpriteAnim; i++)
			{
				fscanf(f, "%s", tab);
				char temp[100] = { 0 };
				strcpy(temp, chemin);
				strcat(temp, tab);
				_gd->enigme.houseBox.arrowBox[_id].Timeline[i] = LoadSprite(temp, 1);
			}
		}

		if (!_stricmp(tab, "ANIM"))
		{
			fscanf(f, "%s", tab);

			if (!_stricmp(tab, "PRESS_DOWN") && _id >= 4)
			{
				fscanf(f, "%d", &_gd->enigme.houseBox.arrowBox[_id].sequence[0].begin);
				fscanf(f, "%d", &_gd->enigme.houseBox.arrowBox[_id].sequence[0].end);
				fscanf(f, "%f", &_gd->enigme.houseBox.arrowBox[_id].sequence[0].total);
			}

			if (!_stricmp(tab, "PRESS_UP") && _id < 4)
			{
				fscanf(f, "%d", &_gd->enigme.houseBox.arrowBox[_id].sequence[0].begin);
				fscanf(f, "%d", &_gd->enigme.houseBox.arrowBox[_id].sequence[0].end);
				fscanf(f, "%f", &_gd->enigme.houseBox.arrowBox[_id].sequence[0].total);
			}
			if (!_stricmp(tab, "IDLE_PRESS_DOWN") && _id >= 4)
			{
				fscanf(f, "%d", &_gd->enigme.houseBox.arrowBox[_id].sequence[1].begin);
				fscanf(f, "%d", &_gd->enigme.houseBox.arrowBox[_id].sequence[1].end);
				fscanf(f, "%f", &_gd->enigme.houseBox.arrowBox[_id].sequence[1].total);
			}

			if (!_stricmp(tab, "IDLE_PRESS_UP") && _id < 4)
			{
				fscanf(f, "%d", &_gd->enigme.houseBox.arrowBox[_id].sequence[1].begin);
				fscanf(f, "%d", &_gd->enigme.houseBox.arrowBox[_id].sequence[1].end);
				fscanf(f, "%f", &_gd->enigme.houseBox.arrowBox[_id].sequence[1].total);
			}
		}
	}

	fclose(f);
}
void InitHelpButtonMastermindBox(GameData* _gd)
{
	//A decommenter quand on aura les assets du bouton aide mastermind de la boite
	_gd->enigme.houseBox.buttonHelpMastermindBox.buttonSprite[0] = LoadSprite("../Ressources/Assets/Box/aide.png", 0);
	_gd->enigme.houseBox.buttonHelpMastermindBox.buttonSprite[1] = LoadSprite("../Ressources/Assets/Box/aide2.png", 0);
	_gd->enigme.houseBox.buttonHelpMastermindBox.buttonSprite[2] = LoadSprite("../Ressources/Assets/Box/aide3.png", 0);

	_gd->enigme.houseBox.onSpriteHelpMastermindBox = sfFalse;
	_gd->enigme.houseBox.clickHelpMastermindBox = sfFalse;

	_gd->enigme.houseBox.buttonHelpMastermindBox.pos.x = 0;
	_gd->enigme.houseBox.buttonHelpMastermindBox.pos.y = 100;

	_gd->enigme.houseBox.buttonHelpMastermindBox.size.x = 170;
	_gd->enigme.houseBox.buttonHelpMastermindBox.size.y = 300;

	_gd->enigme.houseBox.buttonHelpMastermindBox.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.houseBox.buttonHelpMastermindBox.forme, _gd->enigme.houseBox.buttonHelpMastermindBox.pos,
		_gd->enigme.houseBox.buttonHelpMastermindBox.size.x, _gd->enigme.houseBox.buttonHelpMastermindBox.size.y, 0);
}

void InitValidateButtonMastermindBox(GameData* _gd)
{
	sfVector2f tempPos = { 1140, 634 };
	sfVector2f tempSize = { 300, 280 };

	_gd->enigme.houseBox.buttonValidateBox.buttonSprite[0] = LoadSprite("../Ressources/Assets/Mastermind/trap_val1.png", 0);
	_gd->enigme.houseBox.buttonValidateBox.buttonSprite[1] = LoadSprite("../Ressources/Assets/Mastermind/trap_val2.png", 0);
	_gd->enigme.houseBox.buttonValidateBox.buttonSprite[2] = LoadSprite("../Ressources/Assets/Mastermind/trap_val3.png", 0);

	_gd->enigme.houseBox.buttonValidateBox.pos = tempPos;
	_gd->enigme.houseBox.buttonValidateBox.size = tempSize;

	_gd->enigme.houseBox.buttonValidateBox.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.houseBox.buttonValidateBox.forme, _gd->enigme.houseBox.buttonValidateBox.pos,
		_gd->enigme.houseBox.buttonValidateBox.size.x, _gd->enigme.houseBox.buttonValidateBox.size.y, 0);
}

void InitBoutonPieceMastermindBox(GameData* _gd)
{
	_gd->enigme.houseBox.pieceMastermindBox.buttonSprite[0] = LoadSprite("../Ressources/Assets/Mastermind/ama_piece.png", 0);

	_gd->enigme.houseBox.pieceMastermindBox.pos = _gd->enigme.houseBox.buttonValidateBox.pos;
	_gd->enigme.houseBox.pieceMastermindBox.size = _gd->enigme.houseBox.buttonValidateBox.size;

	_gd->enigme.houseBox.pieceMastermindBox.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.houseBox.pieceMastermindBox.forme, _gd->enigme.houseBox.pieceMastermindBox.pos,
		_gd->enigme.houseBox.pieceMastermindBox.size.x, _gd->enigme.houseBox.pieceMastermindBox.size.y, 0);

	_gd->enigme.houseBox.pieceRecup = sfFalse;

}

void InitBoutonQuitBox(GameData* _gd)
{
	//Bouton quitter
	_gd->enigme.houseBox.buttonQuitBox.buttonSprite[0] = LoadSprite("../Ressources/Assets/Puzzle/bouton/quitter_1.png", 0);
	_gd->enigme.houseBox.buttonQuitBox.buttonSprite[1] = LoadSprite("../Ressources/Assets/Puzzle/bouton/quitter_2.png", 0);
	_gd->enigme.houseBox.buttonQuitBox.buttonSprite[2] = LoadSprite("../Ressources/Assets/Puzzle/bouton/quitter_3.png", 0);

	_gd->enigme.houseBox.onSpriteQuitButtonBox = sfFalse;
	_gd->enigme.houseBox.clickQuitButtonBox = sfFalse;

	_gd->enigme.houseBox.buttonQuitBox.pos.x = _gd->sizeWindow.width - 200;
	_gd->enigme.houseBox.buttonQuitBox.pos.y = 28;

	_gd->enigme.houseBox.buttonQuitBox.size.x = 150;
	_gd->enigme.houseBox.buttonQuitBox.size.y = 150;

	_gd->enigme.houseBox.buttonQuitBox.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.houseBox.buttonQuitBox.forme, _gd->enigme.houseBox.buttonQuitBox.pos,
		_gd->enigme.houseBox.buttonQuitBox.size.x, _gd->enigme.houseBox.buttonQuitBox.size.y, 0);
}

void InitMastermindBox(GameData* _gd)
{
	_gd->enigme.houseBox.backgroundMastermindBox = LoadSprite("../Ressources/Assets/Mastermind/interface_box.png", 0);
	InitTutoBox(_gd);
	InitValidateButtonMastermindBox(_gd);
	InitBoutonPieceMastermindBox(_gd);
	InitHelpButtonMastermindBox(_gd);
	InitBoutonQuitBox(_gd);
	//init sprite diode
	_gd->sprites.diodeGreenBox.sprite = LoadSprite("../Ressources/Assets/Mastermind/diode_verte.png", 1);
	_gd->sprites.diodeGreyBox.sprite = LoadSprite("../Ressources/Assets/Mastermind/diode_grise.png", 1);
	_gd->sprites.diodeYellowBox.sprite = LoadSprite("../Ressources/Assets/Mastermind/diode_orange.png", 1);
	_gd->sprites.diodeRedBox.sprite = LoadSprite("../Ressources/Assets/Mastermind/diode_rouge.png", 1);
	_gd->sprites.backgroundInterfaceBox.sprite = LoadSprite("../Ressources/Assets/Puzzle/interface_game.png", 0);

	_gd->enigme.houseBox.diodeMastermindBoxEnigmeNonFini = LoadSprite("../Ressources/Assets/Mastermind/diode_rouge.png", 0);
	_gd->enigme.houseBox.diodeMastermindBoxEnigmeFini = LoadSprite("../Ressources/Assets/Mastermind/diode_verte.png", 0);

	_gd->enigme.houseBox.boiteOuverte = sfFalse;
	_gd->enigme.houseBox.resolvedDream_1Box = sfFalse;
	_gd->enigme.houseBox.pieceRecup = sfFalse;
	_gd->enigme.houseBox.nbDiodeGreen = 0;
	_gd->enigme.houseBox.nbDiodeYellow = 0;

	_gd->enigme.houseBox.state[mastermindBox] = TAB_TRY_MASTERMIND_BOX;
	_gd->enigmeBox = none;

	_gd->enigme.houseBox.isFull = sfFalse;
	//init tab try
	for (int i = 0; i < _gd->enigme.houseBox.state[mastermindBox]; i++)
	{
		for (int j = 0; j < NB_DIGICODE; j++)
		{
			//init du tableau à zero, vide 
			_gd->enigme.houseBox.tabTry[i][j] = 0;
			_gd->enigme.houseBox.diodeGreen[i][j] = sfFalse;
			_gd->enigme.houseBox.diodeYellow[i][j] = sfFalse;
		}
	}

	//savoir dans le tableau à quel essai on est,
	_gd->enigme.houseBox.current = 0;

	//changement de position ici pour le code qu'on va vouloir entrer 
	for (int i = 0; i < NB_DIGICODE; i++)
	{
		_gd->enigme.houseBox.value[i] = 0;

		_gd->enigme.houseBox.caseDigicode[i].x = i * 128 + 600;
		_gd->enigme.houseBox.caseDigicode[i].y = 70 + 694;

		_gd->enigme.houseBox.duplicate[i].value = -1;
	}
	//pour le mastermind de la boite du monde 1
	// mastermindBox

	_gd->enigme.houseBox.valueCode[0] = 4;
	_gd->enigme.houseBox.valueCode[1] = 0;
	_gd->enigme.houseBox.valueCode[2] = 5;
	_gd->enigme.houseBox.valueCode[3] = 3;
	_gd->enigme.houseBox.valueMin = 0;
	_gd->enigme.houseBox.valueMax = 5;


	for (int i = 0; i < 10; i++)
	{
		char stringSprite[70];
		sprintf(stringSprite, "../Ressources/Assets/Mastermind/_%d.png", i);
		_gd->sprites.tabChiffreBox[i].sprite = LoadSprite(stringSprite, 1);
	}

	//changement de position ici pour les flèches(sprites)
	for (int i = 0; i < NB_ARROW; i++)
	{
		InitAnimButtonMastermindBox(_gd, i);
		_gd->enigme.houseBox.arrowBox[i].idSeq = 1;
		_gd->enigme.houseBox.arrowBox[i].currentTime = 0.f;
		_gd->enigme.houseBox.arrowBox[i].isClicked = sfFalse;

		_gd->enigme.houseBox.arrowBox[i].pos.x = (i % 4) * 129 + 600;
		if (i < 4)
		{
			_gd->enigme.houseBox.arrowBox[i].currentAnim = 3;
			_gd->enigme.houseBox.arrowBox[i].pos.y = 650;
		}
		else
		{
			_gd->enigme.houseBox.arrowBox[i].currentAnim = 0;
			_gd->enigme.houseBox.arrowBox[i].pos.y = 185 + 694;
		}
	}

	////changement de position ici pour les flèches(collision)
	for (int i = 0; i < NB_ARROW; i++)
	{
		if (i < 4)
		{
			_gd->enigme.houseBox.colTriangle[i].vertex[0].x = _gd->enigme.houseBox.arrowBox[i].pos.x + 1;
			_gd->enigme.houseBox.colTriangle[i].vertex[0].y = _gd->enigme.houseBox.arrowBox[i].pos.y - 15;

			_gd->enigme.houseBox.colTriangle[i].vertex[1].x = _gd->enigme.houseBox.arrowBox[i].pos.x + 29;
			_gd->enigme.houseBox.colTriangle[i].vertex[1].y = _gd->enigme.houseBox.arrowBox[i].pos.y + 13;

			_gd->enigme.houseBox.colTriangle[i].vertex[2].x = _gd->enigme.houseBox.arrowBox[i].pos.x - 27;
			_gd->enigme.houseBox.colTriangle[i].vertex[2].y = _gd->enigme.houseBox.arrowBox[i].pos.y + 13;
		}
		else
		{
			_gd->enigme.houseBox.colTriangle[i].vertex[0].x = _gd->enigme.houseBox.arrowBox[i].pos.x - 1;
			_gd->enigme.houseBox.colTriangle[i].vertex[0].y = _gd->enigme.houseBox.arrowBox[i].pos.y + 15;

			_gd->enigme.houseBox.colTriangle[i].vertex[1].x = _gd->enigme.houseBox.arrowBox[i].pos.x + 27;
			_gd->enigme.houseBox.colTriangle[i].vertex[1].y = _gd->enigme.houseBox.arrowBox[i].pos.y - 13;

			_gd->enigme.houseBox.colTriangle[i].vertex[2].x = _gd->enigme.houseBox.arrowBox[i].pos.x - 29;
			_gd->enigme.houseBox.colTriangle[i].vertex[2].y = _gd->enigme.houseBox.arrowBox[i].pos.y - 13;
		}
	}
}

void DeleteMastermindBoxSprite(GameData* _gd)
{
	DeleteSprite(_gd->enigme.houseBox.backgroundMastermindBox);
	DeleteSprite(_gd->sprites.diodeGreenBox.sprite);
	DeleteSprite(_gd->sprites.diodeGreyBox.sprite);
	DeleteSprite(_gd->sprites.diodeRedBox.sprite);
	DeleteSprite(_gd->sprites.diodeYellowBox.sprite);
	DeleteSprite(_gd->sprites.backgroundInterfaceBox.sprite);
	DeleteSprite(_gd->enigme.houseBox.diodeMastermindBoxEnigmeNonFini);
	DeleteSprite(_gd->enigme.houseBox.diodeMastermindBoxEnigmeFini);

	for (int i = 0; i < 10; i++)
	{
		DeleteSprite(_gd->sprites.tabChiffreBox[i].sprite);
	}

	for (int i = 0; i < 3; i++)
	{
		DeleteSprite(_gd->enigme.houseBox.buttonQuitBox.buttonSprite[i]);
		DeleteSprite(_gd->enigme.houseBox.buttonValidateBox.buttonSprite[i]);
		DeleteSprite(_gd->enigme.houseBox.buttonHelpMastermindBox.buttonSprite[i]);
		DeleteSprite(_gd->enigme.houseBox.retourButtonBox.buttonSprite[i]);
	}
	DeleteSprite(_gd->enigme.houseBox.pieceMastermindBox.buttonSprite[0]);
	DeleteSprite(_gd->enigme.houseBox.backgroundTutoMastermindBox);

	sfRectangleShape_destroy(_gd->enigme.houseBox.buttonQuitBox.forme);
	sfRectangleShape_destroy(_gd->enigme.houseBox.buttonValidateBox.forme);
	sfRectangleShape_destroy(_gd->enigme.houseBox.buttonHelpMastermindBox.forme);
	sfRectangleShape_destroy(_gd->enigme.houseBox.pieceMastermindBox.forme);
	sfRectangleShape_destroy(_gd->enigme.houseBox.retourButtonBox.forme);


}