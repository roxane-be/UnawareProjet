#include "InitMastermindIntro.h"

void InitAnimButtonMastermindIntro(GameData* _gd, int _id)
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

			_gd->enigme.doorDigicode.arrowIntro[_id].Timeline = (sfSprite**)malloc(sizeof(sfSprite*) * _gd->nbSpriteAnim);

			for (int i = 0; i < _gd->nbSpriteAnim; i++)
			{
				fscanf(f, "%s", tab);
				char temp[100] = { 0 };
				strcpy(temp, chemin);
				strcat(temp, tab);
				_gd->enigme.doorDigicode.arrowIntro[_id].Timeline[i] = LoadSprite(temp, 1);
			}
		}

		if (!_stricmp(tab, "ANIM"))
		{
			fscanf(f, "%s", tab);

			if (!_stricmp(tab, "PRESS_DOWN") && _id >= 4)
			{
				fscanf(f, "%d", &_gd->enigme.doorDigicode.arrowIntro[_id].sequence[0].begin);
				fscanf(f, "%d", &_gd->enigme.doorDigicode.arrowIntro[_id].sequence[0].end);
				fscanf(f, "%f", &_gd->enigme.doorDigicode.arrowIntro[_id].sequence[0].total);
			}

			if (!_stricmp(tab, "PRESS_UP") && _id < 4)
			{
				fscanf(f, "%d", &_gd->enigme.doorDigicode.arrowIntro[_id].sequence[0].begin);
				fscanf(f, "%d", &_gd->enigme.doorDigicode.arrowIntro[_id].sequence[0].end);
				fscanf(f, "%f", &_gd->enigme.doorDigicode.arrowIntro[_id].sequence[0].total);
			}
			if (!_stricmp(tab, "IDLE_PRESS_DOWN") && _id >= 4)
			{
				fscanf(f, "%d", &_gd->enigme.doorDigicode.arrowIntro[_id].sequence[1].begin);
				fscanf(f, "%d", &_gd->enigme.doorDigicode.arrowIntro[_id].sequence[1].end);
				fscanf(f, "%f", &_gd->enigme.doorDigicode.arrowIntro[_id].sequence[1].total);
			}

			if (!_stricmp(tab, "IDLE_PRESS_UP") && _id < 4)
			{
				fscanf(f, "%d", &_gd->enigme.doorDigicode.arrowIntro[_id].sequence[1].begin);
				fscanf(f, "%d", &_gd->enigme.doorDigicode.arrowIntro[_id].sequence[1].end);
				fscanf(f, "%f", &_gd->enigme.doorDigicode.arrowIntro[_id].sequence[1].total);
			}
		}
	}

	fclose(f);
}

void InitButtonMastermindIntro(GameData* _gd)
{
	//Init help button
	_gd->enigme.doorDigicode.buttonHelp.buttonSprite[0] = LoadSprite("../Ressources/Assets/Mastermind/boutons/aide1.png", 0);
	_gd->enigme.doorDigicode.buttonHelp.buttonSprite[1] = LoadSprite("../Ressources/Assets/Mastermind/boutons/aide2.png", 0);
	_gd->enigme.doorDigicode.buttonHelp.buttonSprite[2] = LoadSprite("../Ressources/Assets/Mastermind/boutons/aide3.png", 0);

	_gd->enigme.doorDigicode.buttonHelp.isQuit = sfFalse;
	_gd->enigme.doorDigicode.buttonHelp.pos.x = 305;
	_gd->enigme.doorDigicode.buttonHelp.pos.y = 0;

	_gd->enigme.doorDigicode.buttonHelp.size.x = 175;
	_gd->enigme.doorDigicode.buttonHelp.size.y = 175;

	sfVector2f tempPosHelp = { _gd->enigme.doorDigicode.buttonHelp.pos.x + 110, _gd->enigme.doorDigicode.buttonHelp.pos.y + 50 };

	_gd->enigme.doorDigicode.buttonHelp.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.doorDigicode.buttonHelp.forme, tempPosHelp,
		_gd->enigme.doorDigicode.buttonHelp.size.x, _gd->enigme.doorDigicode.buttonHelp.size.y, 0);

	_gd->enigme.doorDigicode.onSpriteHelp = sfFalse;
	_gd->enigme.doorDigicode.clickHelp = sfFalse;

	//Init quit button
	_gd->enigme.doorDigicode.buttonQuit.buttonSprite[0] = LoadSprite("../Ressources/Assets/Mastermind/boutons/quitter_1.png", 0);
	_gd->enigme.doorDigicode.buttonQuit.buttonSprite[1] = LoadSprite("../Ressources/Assets/Mastermind/boutons/quitter_2.png", 0);
	_gd->enigme.doorDigicode.buttonQuit.buttonSprite[2] = LoadSprite("../Ressources/Assets/Mastermind/boutons/quitter_3.png", 0);

	_gd->enigme.doorDigicode.buttonQuit.pos.x = _gd->sizeWindow.width - 300;
	_gd->enigme.doorDigicode.buttonQuit.pos.y = 50;

	_gd->enigme.doorDigicode.buttonQuit.size.x = 150;
	_gd->enigme.doorDigicode.buttonQuit.size.y = 150;

	_gd->enigme.doorDigicode.buttonQuit.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.doorDigicode.buttonQuit.forme, _gd->enigme.doorDigicode.buttonQuit.pos,
		_gd->enigme.doorDigicode.buttonQuit.size.x, _gd->enigme.doorDigicode.buttonQuit.size.y, 0);

	_gd->enigme.doorDigicode.onSpriteQuit = sfFalse;
	_gd->enigme.doorDigicode.clickQuit = sfFalse;

	//Init Validate button
	_gd->enigme.doorDigicode.buttonValidate.buttonSprite[0] = LoadSprite("../Ressources/Assets/Mastermind/boutons/valider1.png", 0);
	_gd->enigme.doorDigicode.buttonValidate.buttonSprite[1] = LoadSprite("../Ressources/Assets/Mastermind/boutons/valider2.png", 0);
	_gd->enigme.doorDigicode.buttonValidate.buttonSprite[2] = LoadSprite("../Ressources/Assets/Mastermind/boutons/valider3.png", 0);

	_gd->enigme.doorDigicode.buttonValidate.pos.x = 1020;
	_gd->enigme.doorDigicode.buttonValidate.pos.y = 740;

	_gd->enigme.doorDigicode.buttonValidate.size.x = 270;
	_gd->enigme.doorDigicode.buttonValidate.size.y = 250;

	sfVector2f tempPosValidate = { _gd->enigme.doorDigicode.buttonValidate.pos.x + 20, _gd->enigme.doorDigicode.buttonValidate.pos.y - 50 };

	_gd->enigme.doorDigicode.buttonValidate.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.doorDigicode.buttonValidate.forme, tempPosValidate,
		_gd->enigme.doorDigicode.buttonValidate.size.x, _gd->enigme.doorDigicode.buttonValidate.size.y, 0);

	_gd->enigme.doorDigicode.onSpriteValidate = sfFalse;
	_gd->enigme.doorDigicode.clickValidate = sfFalse;
}

void InitMastermindIntro(GameData* _gd)
{
	//init sprite diode
	_gd->sprites.diodeGreenIntro.sprite = LoadSprite("../Ressources/Assets/Mastermind/diode_verte.png", 1);
	_gd->sprites.diodeGreyIntro.sprite = LoadSprite("../Ressources/Assets/Mastermind/diode_rouge.png", 1);
	_gd->sprites.diodeYellowIntro.sprite = LoadSprite("../Ressources/Assets/Mastermind/diode_orange.png", 1);
	_gd->sprites.backgroundInterfaceIntro.sprite = LoadSprite("../Ressources/Assets/Mastermind/interface.png", 0);

	//Init des bouttons pour le mastermind d'intro
	InitButtonMastermindIntro(_gd);
	InitTutoMastermindIntro(_gd);

	_gd->enigme.doorDigicode.state[mastermindIntro] = TAB_TRY_INTRO;
	_gd->enigme.doorDigicode.isFull = sfFalse;
	_gd->enigme.doorDigicode.resolvedIntro = sfFalse;

	//init tab try
	for (int i = 0; i < _gd->enigme.doorDigicode.state[_gd->enigmeState]; i++)
	{
		for (int j = 0; j < NB_DIGICODE; j++)
		{
			//init du tableau à zero, vide 
			_gd->enigme.doorDigicode.tabTry[i][j] = 0;
			_gd->enigme.doorDigicode.diodeGreen[i][j] = sfFalse;
			_gd->enigme.doorDigicode.diodeYellow[i][j] = sfFalse;
		}
	}

	//savoir dans le tableau à quel essai on est,
	_gd->enigme.doorDigicode.current = 0;


	//changement de position ici pour le code qu'on va vouloir entrer 
	for (int i = 0; i < NB_DIGICODE; i++)
	{
		_gd->enigme.doorDigicode.value[i] = 4;

		_gd->enigme.doorDigicode.caseDigicode[i].x = i * 115 + 630;
		_gd->enigme.doorDigicode.caseDigicode[i].y = 118 + 694;

		_gd->enigme.doorDigicode.duplicate[i].value = -1;
	}

	//pour le mastermind du HUB
	//code et les valeur min/max

	_gd->enigme.doorDigicode.valueCode[0] = 5;
	_gd->enigme.doorDigicode.valueCode[1] = 4;
	_gd->enigme.doorDigicode.valueCode[2] = 9;
	_gd->enigme.doorDigicode.valueCode[3] = 8;
	_gd->enigme.doorDigicode.valueMin = 4;
	_gd->enigme.doorDigicode.valueMax = 9;


	_gd->enigme.doorDigicode.current = 0;
	//a faire plus propre avec lecture de fichier txt
	//_gameData->enigme.doorDigicode.value[i];

	_gd->enigme.doorDigicode.value[0] = 7;
	_gd->enigme.doorDigicode.value[1] = 9;
	_gd->enigme.doorDigicode.value[2] = 4;
	_gd->enigme.doorDigicode.value[3] = 8;
	isValidateIntro(_gd);

	_gd->enigme.doorDigicode.value[0] = 5;
	_gd->enigme.doorDigicode.value[1] = 4;
	_gd->enigme.doorDigicode.value[2] = 6;
	_gd->enigme.doorDigicode.value[3] = 7;
	isValidateIntro(_gd);

	_gd->enigme.doorDigicode.value[0] = 7;
	_gd->enigme.doorDigicode.value[1] = 5;
	_gd->enigme.doorDigicode.value[2] = 9;
	_gd->enigme.doorDigicode.value[3] = 8;
	isValidateIntro(_gd);

	_gd->enigme.doorDigicode.value[0] = 8;
	_gd->enigme.doorDigicode.value[1] = 4;
	_gd->enigme.doorDigicode.value[2] = 9;
	_gd->enigme.doorDigicode.value[3] = 5;
	isValidateIntro(_gd);

	_gd->enigme.doorDigicode.isFull = sfTrue;

	_gd->enigme.doorDigicode.tabTry[0][0] = 7;
	_gd->enigme.doorDigicode.tabTry[0][1] = 9;
	_gd->enigme.doorDigicode.tabTry[0][2] = 4;
	_gd->enigme.doorDigicode.tabTry[0][3] = 8;
	_gd->enigme.doorDigicode.tabTry[1][0] = 5;
	_gd->enigme.doorDigicode.tabTry[1][1] = 4;
	_gd->enigme.doorDigicode.tabTry[1][2] = 6;
	_gd->enigme.doorDigicode.tabTry[1][3] = 7;
	_gd->enigme.doorDigicode.tabTry[2][0] = 7;
	_gd->enigme.doorDigicode.tabTry[2][1] = 5;
	_gd->enigme.doorDigicode.tabTry[2][2] = 9;
	_gd->enigme.doorDigicode.tabTry[2][3] = 8;
	_gd->enigme.doorDigicode.tabTry[3][0] = 8;
	_gd->enigme.doorDigicode.tabTry[3][1] = 4;
	_gd->enigme.doorDigicode.tabTry[3][2] = 9;
	_gd->enigme.doorDigicode.tabTry[3][3] = 5;

	for (int i = 0; i < 10; i++)
	{
		char stringSprite[70];
		sprintf(stringSprite, "../Ressources/Assets/Mastermind/_%d.png", i);
		_gd->sprites.tabChiffreIntro[i].sprite = LoadSprite(stringSprite, 1);
	}

	//changement de position ici pour les flèches(sprites)
	for (int i = 0; i < NB_ARROW; i++)
	{
		InitAnimButtonMastermindIntro(_gd, i);
		_gd->enigme.doorDigicode.arrowIntro[i].idSeq = 1;
		_gd->enigme.doorDigicode.arrowIntro[i].currentTime = 0.f;
		_gd->enigme.doorDigicode.arrowIntro[i].isClicked = sfFalse;

		_gd->enigme.doorDigicode.arrowIntro[i].pos.x = (i % 4) * 115 + 630;
		if (i < 4)
		{
			_gd->enigme.doorDigicode.arrowIntro[i].currentAnim = 3;
			_gd->enigme.doorDigicode.arrowIntro[i].pos.y = 47 + 694;
		}
		else
		{
			_gd->enigme.doorDigicode.arrowIntro[i].currentAnim = 0;
			_gd->enigme.doorDigicode.arrowIntro[i].pos.y = 188 + 694;
		}
	}

	//changement de position ici pour les flèches(collision)
	for (int i = 0; i < NB_ARROW; i++)
	{
		if (i < 4)
		{
			_gd->enigme.doorDigicode.colTriangle[i].vertex[0].x = _gd->enigme.doorDigicode.arrowIntro[i].pos.x + 1;
			_gd->enigme.doorDigicode.colTriangle[i].vertex[0].y = _gd->enigme.doorDigicode.arrowIntro[i].pos.y - 15;

			_gd->enigme.doorDigicode.colTriangle[i].vertex[1].x = _gd->enigme.doorDigicode.arrowIntro[i].pos.x + 29;
			_gd->enigme.doorDigicode.colTriangle[i].vertex[1].y = _gd->enigme.doorDigicode.arrowIntro[i].pos.y + 13;

			_gd->enigme.doorDigicode.colTriangle[i].vertex[2].x = _gd->enigme.doorDigicode.arrowIntro[i].pos.x - 27;
			_gd->enigme.doorDigicode.colTriangle[i].vertex[2].y = _gd->enigme.doorDigicode.arrowIntro[i].pos.y + 13;
		}
		else
		{
			_gd->enigme.doorDigicode.colTriangle[i].vertex[0].x = _gd->enigme.doorDigicode.arrowIntro[i].pos.x - 1;
			_gd->enigme.doorDigicode.colTriangle[i].vertex[0].y = _gd->enigme.doorDigicode.arrowIntro[i].pos.y + 15;

			_gd->enigme.doorDigicode.colTriangle[i].vertex[1].x = _gd->enigme.doorDigicode.arrowIntro[i].pos.x + 27;
			_gd->enigme.doorDigicode.colTriangle[i].vertex[1].y = _gd->enigme.doorDigicode.arrowIntro[i].pos.y - 13;

			_gd->enigme.doorDigicode.colTriangle[i].vertex[2].x = _gd->enigme.doorDigicode.arrowIntro[i].pos.x - 29;
			_gd->enigme.doorDigicode.colTriangle[i].vertex[2].y = _gd->enigme.doorDigicode.arrowIntro[i].pos.y - 13;
		}
	}
}

void DeleteMastermindIntroSprite(GameData* _gd)
{
	DeleteSprite(_gd->sprites.diodeGreenIntro.sprite);
	DeleteSprite(_gd->sprites.diodeGreyIntro.sprite);
	DeleteSprite(_gd->sprites.diodeYellowIntro.sprite);
	DeleteSprite(_gd->sprites.backgroundInterfaceIntro.sprite);

	for (int i = 0; i < 10; i++)
	{
		DeleteSprite(_gd->sprites.tabChiffreIntro[i].sprite);
	}

	for (int i = 0; i < 3; i++)
	{
		DeleteSprite(_gd->enigme.doorDigicode.buttonHelp.buttonSprite[i]);
		DeleteSprite(_gd->enigme.doorDigicode.buttonValidate.buttonSprite[i]);
		DeleteSprite(_gd->enigme.doorDigicode.buttonQuit.buttonSprite[i]);
	}

	sfRectangleShape_destroy(_gd->enigme.doorDigicode.buttonHelp.forme);
	sfRectangleShape_destroy(_gd->enigme.doorDigicode.buttonQuit.forme);
	sfRectangleShape_destroy(_gd->enigme.doorDigicode.buttonValidate.forme);
}