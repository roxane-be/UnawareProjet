#include "InitDiode.h"

void InitDiode(GameData* _gd)
{
	sfVector2f posHelpButton = { 28, 145 };
	sfVector2f sizeHelpButton = { 200, 200 };


	_gd->enigme.interupteur.spriteOn = LoadSprite("../Ressources/Assets/EnigmeDiode/luciole_on.png", 1);
	_gd->enigme.interupteur.spriteOff = LoadSprite("../Ressources/Assets/EnigmeDiode/luciole_off.png", 1);
	_gd->enigme.interupteur.backgroundDiode = LoadSprite("../Ressources/Assets/EnigmeDiode/interface_jungle.png", 0);

	//bouton aide diode 3x3
	_gd->enigme.interupteur.helpButtonDiode3x3.buttonSprite[0] = LoadSprite("../Ressources/Assets/EnigmeDiode/aide_feuille.png", 0);
	_gd->enigme.interupteur.helpButtonDiode3x3.buttonSprite[1] = LoadSprite("../Ressources/Assets/EnigmeDiode/aide_feuille2.png", 0);
	_gd->enigme.interupteur.helpButtonDiode3x3.buttonSprite[2] = LoadSprite("../Ressources/Assets/EnigmeDiode/aide_feuille3.png", 0);

	_gd->enigme.interupteur.onSpriteHelpButtonDiode3x3 = sfFalse;
	_gd->enigme.interupteur.clickHelpButtonDiode3x3 = sfFalse;

	_gd->enigme.interupteur.helpButtonDiode3x3.pos = posHelpButton;
	_gd->enigme.interupteur.helpButtonDiode3x3.size = sizeHelpButton;

	_gd->enigme.interupteur.helpButtonDiode3x3.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.interupteur.helpButtonDiode3x3.forme, _gd->enigme.interupteur.helpButtonDiode3x3.pos, _gd->enigme.interupteur.helpButtonDiode3x3.size.x,
		_gd->enigme.interupteur.helpButtonDiode3x3.size.y, 0);


	//bouton aide diode symbole
	sfVector2f posSymboleButton = { 208, 35 };
	sfVector2f sizeSymboleButton = { 200, 200 };

	_gd->enigme.interupteur.helpButtonDiodeSymbole.buttonSprite[0] = LoadSprite("../Ressources/Assets/EnigmeDiode/aide_feuille.png", 0);
	_gd->enigme.interupteur.helpButtonDiodeSymbole.buttonSprite[1] = LoadSprite("../Ressources/Assets/EnigmeDiode/aide_feuille2.png", 0);
	_gd->enigme.interupteur.helpButtonDiodeSymbole.buttonSprite[2] = LoadSprite("../Ressources/Assets/EnigmeDiode/aide_feuille3.png", 0);

	_gd->enigme.interupteur.symboleButtonDiode.buttonSprite[0] = LoadSprite("../Ressources/Assets/EnigmeDiode/AideDiode/feuille_symbole.png", 0);
	_gd->enigme.interupteur.symboleButtonDiode.buttonSprite[1] = LoadSprite("../Ressources/Assets/EnigmeDiode/AideDiode/feuille_symbole2.png", 0);
	_gd->enigme.interupteur.symboleButtonDiode.buttonSprite[2] = LoadSprite("../Ressources/Assets/EnigmeDiode/AideDiode/feuille_symbole3.png", 0);

	_gd->enigme.interupteur.onSpriteHelpButtonDiodeSymbole = sfFalse;
	_gd->enigme.interupteur.clickHelpButtonDiodeSymbole = sfFalse;

	_gd->enigme.interupteur.onSpriteSymboleButtonDiode = sfFalse;
	_gd->enigme.interupteur.clickSymboleButtonDiode = sfFalse;

	_gd->enigme.interupteur.helpButtonDiodeSymbole.pos = posHelpButton;
	_gd->enigme.interupteur.helpButtonDiodeSymbole.size = sizeHelpButton;

	_gd->enigme.interupteur.symboleButtonDiode.pos = posSymboleButton;
	_gd->enigme.interupteur.symboleButtonDiode.size = sizeSymboleButton;

	_gd->enigme.interupteur.helpButtonDiodeSymbole.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.interupteur.helpButtonDiodeSymbole.forme, _gd->enigme.interupteur.helpButtonDiodeSymbole.pos, _gd->enigme.interupteur.helpButtonDiodeSymbole.size.x,
		_gd->enigme.interupteur.helpButtonDiodeSymbole.size.y, 0);

	_gd->enigme.interupteur.symboleButtonDiode.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.interupteur.symboleButtonDiode.forme, _gd->enigme.interupteur.symboleButtonDiode.pos,
		_gd->enigme.interupteur.symboleButtonDiode.size.x, _gd->enigme.interupteur.symboleButtonDiode.size.y, 0);

	//bouton aide diode fin
	_gd->enigme.interupteur.helpButtonDiodeFin.buttonSprite[0] = LoadSprite("../Ressources/Assets/EnigmeDiode/aide_feuille.png", 0);
	_gd->enigme.interupteur.helpButtonDiodeFin.buttonSprite[1] = LoadSprite("../Ressources/Assets/EnigmeDiode/aide_feuille2.png", 0);
	_gd->enigme.interupteur.helpButtonDiodeFin.buttonSprite[2] = LoadSprite("../Ressources/Assets/EnigmeDiode/aide_feuille3.png", 0);

	_gd->enigme.interupteur.onSpriteHelpButtonDiodeFin = sfFalse;
	_gd->enigme.interupteur.clickHelpButtonDiodeFin = sfFalse;

	_gd->enigme.interupteur.helpButtonDiodeFin.pos = posHelpButton;
	_gd->enigme.interupteur.helpButtonDiodeFin.size = sizeHelpButton;

	_gd->enigme.interupteur.helpButtonDiodeFin.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.interupteur.helpButtonDiodeFin.forme, _gd->enigme.interupteur.helpButtonDiodeFin.pos, _gd->enigme.interupteur.helpButtonDiodeFin.size.x,
		_gd->enigme.interupteur.helpButtonDiodeFin.size.y, 0);


	switch (_gd->enigme.interupteur.interupteurState)
	{
	case tutoDiode:
		_gd->enigme.interupteur.sizeTab.x = NB_COLUMNS_TUTO;
		_gd->enigme.interupteur.sizeTab.y = NB_LIGNE_TUTO;
		_gd->enigme.interupteur.diodeFini[tutoDiode] = sfFalse;
		break;
	case symboleDiode:
		_gd->enigme.interupteur.sizeTab.x = NB_COLUMNS_SYMBOLE;
		_gd->enigme.interupteur.sizeTab.y = NB_LIGNE_SYMBOLE;
		_gd->enigme.interupteur.diodeFini[symboleDiode] = sfFalse;
		break;
	case fullDiode:
		_gd->enigme.interupteur.sizeTab.x = NB_COLUMNS_FULL;
		_gd->enigme.interupteur.sizeTab.y = NB_LIGNE_FULL;
		_gd->enigme.interupteur.diodeFini[fullDiode] = sfFalse;
		break;
	default:
		break;
	}

	_gd->enigme.interupteur.etat = calloc(_gd->enigme.interupteur.sizeTab.x, sizeof(Light*));
	_gd->enigme.interupteur.pos = calloc(_gd->enigme.interupteur.sizeTab.x, sizeof(sfVector2f*));
	_gd->enigme.interupteur.rectInterupteur = calloc(_gd->enigme.interupteur.sizeTab.x, sizeof(sfRectangleShape**));

	for (int i = 0; i < _gd->enigme.interupteur.sizeTab.x; i++)
	{
		_gd->enigme.interupteur.etat[i] = calloc(_gd->enigme.interupteur.sizeTab.y, sizeof(Light));
		_gd->enigme.interupteur.pos[i] = calloc(_gd->enigme.interupteur.sizeTab.y, sizeof(sfVector2f));
		_gd->enigme.interupteur.rectInterupteur[i] = calloc(_gd->enigme.interupteur.sizeTab.y, sizeof(sfRectangleShape*));
	}

	for (int i = 0; i < _gd->enigme.interupteur.sizeTab.x; i++)
	{
		for (int j = 0; j < _gd->enigme.interupteur.sizeTab.y; j++)
		{
			sfVector2f posTemp;
			if (_gd->enigme.interupteur.interupteurState == tutoDiode)
			{


				_gd->enigme.interupteur.etat[i][j] = off;
				_gd->enigme.interupteur.pos[i][j].x = (275 * i) + 700; // (275 * i) + 700
				_gd->enigme.interupteur.pos[i][j].y = 200 + (280 * j); // 200 + (280 * j)
				posTemp.x = _gd->enigme.interupteur.pos[i][j].x + 6;
				posTemp.y = _gd->enigme.interupteur.pos[i][j].y; //+ 60
				_gd->enigme.interupteur.rectInterupteur[i][j] = sfRectangleShape_create();
				createRectangle(_gd->enigme.interupteur.rectInterupteur[i][j], posTemp, 65, 195, 1);
			}
			else if (_gd->enigme.interupteur.interupteurState == symboleDiode)
			{

				_gd->enigme.interupteur.etat[i][j] = off;
				_gd->enigme.interupteur.pos[i][j].x = (240 * i) + 605;
				_gd->enigme.interupteur.pos[i][j].y = 170 + (240 * j);
				posTemp.x = _gd->enigme.interupteur.pos[i][j].x + 6;
				posTemp.y = _gd->enigme.interupteur.pos[i][j].y; //+ 53
				_gd->enigme.interupteur.rectInterupteur[i][j] = sfRectangleShape_create();
				createRectangle(_gd->enigme.interupteur.rectInterupteur[i][j], posTemp, 65, 180, 1); //y = 85
			}
			else if (_gd->enigme.interupteur.interupteurState == fullDiode)
			{


				_gd->enigme.interupteur.etat[i][j] = off;
				_gd->enigme.interupteur.pos[i][j].x = (180 * i) + 560;
				_gd->enigme.interupteur.pos[i][j].y = 140 + (190 * j);
				posTemp.x = _gd->enigme.interupteur.pos[i][j].x + 4;
				posTemp.y = _gd->enigme.interupteur.pos[i][j].y; //+ 40
				_gd->enigme.interupteur.rectInterupteur[i][j] = sfRectangleShape_create();
				createRectangle(_gd->enigme.interupteur.rectInterupteur[i][j], posTemp, 40, 140, 1); //x = 40, y = 60
			}
		}
	}
	sfVector2f tempSize = { 200, 200 };
	sfVector2f temp;
	temp.x = 1670;
	temp.y = 740;
	//bouton valider
	_gd->enigme.interupteur.validateButtonDiode.buttonSprite[0] = LoadSprite("../Ressources/Assets/EnigmeDiode/valifeuille.png", 0);
	_gd->enigme.interupteur.validateButtonDiode.buttonSprite[1] = LoadSprite("../Ressources/Assets/EnigmeDiode/valifeuille2.png", 0);
	_gd->enigme.interupteur.validateButtonDiode.buttonSprite[2] = LoadSprite("../Ressources/Assets/EnigmeDiode/valifeuille3.png", 0);

	_gd->enigme.interupteur.validateButtonDiode.pos = temp;
	_gd->enigme.interupteur.validateButtonDiode.size = tempSize;

	_gd->enigme.interupteur.onSpriteValidateButtonDiode = sfFalse;
	_gd->enigme.interupteur.clickValidateButtonDiode = sfFalse;

	_gd->enigme.interupteur.validateButtonDiode.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.interupteur.validateButtonDiode.forme, _gd->enigme.interupteur.validateButtonDiode.pos, _gd->enigme.interupteur.validateButtonDiode.size.x,
		_gd->enigme.interupteur.validateButtonDiode.size.y, 0);

	temp.x = 50;
	temp.y = 710;
	tempSize.x = 300;
	tempSize.y = 300;
	//bouton reset
	_gd->enigme.interupteur.resetButtonDiode.buttonSprite[0] = LoadSprite("../Ressources/Assets/EnigmeDiode/reset1.png", 0);
	_gd->enigme.interupteur.resetButtonDiode.buttonSprite[1] = LoadSprite("../Ressources/Assets/EnigmeDiode/reset2.png", 0);
	_gd->enigme.interupteur.resetButtonDiode.buttonSprite[2] = LoadSprite("../Ressources/Assets/EnigmeDiode/reset3.png", 0);

	_gd->enigme.interupteur.resetButtonDiode.pos = temp;
	_gd->enigme.interupteur.resetButtonDiode.size = tempSize;

	_gd->enigme.interupteur.resetButtonDiode.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.interupteur.resetButtonDiode.forme, temp, _gd->enigme.interupteur.resetButtonDiode.size.x,
		_gd->enigme.interupteur.resetButtonDiode.size.y, 0);

	temp.x = 1700;
	temp.y = 10;
	tempSize.x = 200;
	tempSize.y = 200;
	//bouton quitter
	_gd->enigme.interupteur.quitButtonDiode.buttonSprite[0] = LoadSprite("../Ressources/Assets/EnigmeDiode/renouille1.png", 0);
	_gd->enigme.interupteur.quitButtonDiode.buttonSprite[1] = LoadSprite("../Ressources/Assets/EnigmeDiode/renouille2.png", 0);
	_gd->enigme.interupteur.quitButtonDiode.buttonSprite[2] = LoadSprite("../Ressources/Assets/EnigmeDiode/renouille3.png", 0);

	_gd->enigme.interupteur.quitButtonDiode.pos = temp;
	_gd->enigme.interupteur.quitButtonDiode.size = tempSize;

	_gd->enigme.interupteur.onSpriteQuitButtonDiode = sfFalse;
	_gd->enigme.interupteur.clickQuitButtonDiode = sfFalse;

	_gd->enigme.interupteur.quitButtonDiode.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.interupteur.quitButtonDiode.forme, _gd->enigme.interupteur.quitButtonDiode.pos, _gd->enigme.interupteur.quitButtonDiode.size.x,
		_gd->enigme.interupteur.quitButtonDiode.size.y, 0);


	_gd->enigme.interupteur.resolvedDiode = sfFalse;


	//pour faire le full a partir d'une grille déjà préremplis 
	if (_gd->enigme.interupteur.interupteurState == fullDiode)
	{
		//version presque fini 
		//_gd->enigme.interupteur.etat[0][0] = on;
		//_gd->enigme.interupteur.etat[0][2] = on;
		//_gd->enigme.interupteur.etat[0][4] = on;
		////
		//_gd->enigme.interupteur.etat[2][0] = on;
		//_gd->enigme.interupteur.etat[2][1] = on;
		//_gd->enigme.interupteur.etat[2][2] = on;
		//_gd->enigme.interupteur.etat[2][3] = on;
		//_gd->enigme.interupteur.etat[2][4] = on;
		////
		//_gd->enigme.interupteur.etat[3][1] = on;
		//_gd->enigme.interupteur.etat[3][2] = on;
		//_gd->enigme.interupteur.etat[3][4] = on;
		////
		//_gd->enigme.interupteur.etat[4][1] = on;
		//_gd->enigme.interupteur.etat[4][2] = on;
		//_gd->enigme.interupteur.etat[4][4] = on;
		////
		//_gd->enigme.interupteur.etat[5][0] = on;
		//_gd->enigme.interupteur.etat[5][1] = on;


		////version début
		_gd->enigme.interupteur.etat[0][0] = on;
		_gd->enigme.interupteur.etat[2][0] = on;

		_gd->enigme.interupteur.etat[1][2] = on;
		_gd->enigme.interupteur.etat[0][2] = on;
		_gd->enigme.interupteur.etat[0][4] = on;


		_gd->enigme.interupteur.etat[3][3] = on;
		_gd->enigme.interupteur.etat[5][1] = on;
	}

	InitTutoDiode(_gd);
}

void DeleteDiodeJungle(GameData* _gd)
{
	/*for (int i = 0; i < 3; i++)
	{
		DeleteSprite(_gd->enigme.interupteur.helpButtonDiode3x3.buttonSprite[i]);
		DeleteSprite(_gd->enigme.interupteur.helpButtonDiodeSymbole.buttonSprite[i]);
		DeleteSprite(_gd->enigme.interupteur.symboleButtonDiode.buttonSprite[i]);

		DeleteSprite(_gd->enigme.interupteur.validateButtonDiode.buttonSprite[i]);
		DeleteSprite(_gd->enigme.interupteur.resetButtonDiode.buttonSprite[i]);
		DeleteSprite(_gd->enigme.interupteur.quitButtonDiode.buttonSprite[i]);
		DeleteSprite(_gd->enigme.interupteur.helpButtonDiodeFin.buttonSprite[i]);
	}

	DeleteSprite(_gd->enigme.interupteur.spriteOn);
	DeleteSprite(_gd->enigme.interupteur.spriteOff);
	DeleteSprite(_gd->enigme.interupteur.backgroundDiode);

	free(_gd->enigme.interupteur.etat);
	_gd->enigme.interupteur.etat = NULL;
	free(_gd->enigme.interupteur.pos);
	_gd->enigme.interupteur.pos = NULL;
	free(_gd->enigme.interupteur.rectInterupteur);
	_gd->enigme.interupteur.rectInterupteur = NULL;*/
}