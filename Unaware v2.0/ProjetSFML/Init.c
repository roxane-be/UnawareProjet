#include "Init.h"

void InitTimer(GameData* _gd)
{
	_gd->interfaceTimer = LoadSprite("../Ressources/Assets/Interface/interface_temps.png", 0);
	_gd->interfaceTimerEnigme = LoadSprite("../Ressources/Assets/Interface/interface_temps2.png", 0);
	_gd->sprites.spriteTimerPoint.sprite = LoadSprite("../Ressources/Assets/Interface/Deux_point.png", 0);

	for (int i = 0; i < 10; i++)
	{
		char nameSprite[70];
		sprintf(nameSprite, "../Ressources/Assets/Interface/%d.png", i);
		_gd->sprites.spriteTimer[i].sprite = LoadSprite(nameSprite, 1);
	}

	_gd->sprites.spriteTimerBarre.sprite = LoadSprite("../Ressources/Assets/Interface/Barre.png", 1);

	_gd->timer.timerTotal = 45 * 60; //minutes * secondes
	_gd->timer.timerMin = 30; //minutes * secondes
	_gd->timer.timerSec = 0; //minutes * secondes
}

void InitTimerJungle(GameData* _gd)
{
	_gd->interfaceTimer = LoadSprite("../Ressources/Assets/Interface/interface_temps_jungle.png", 0);
	_gd->interfaceTimerEnigme = LoadSprite("../Ressources/Assets/Interface/interface_temps2_jungle.png", 0);;
	_gd->sprites.spriteTimerPoint.sprite = LoadSprite("../Ressources/Assets/Interface/Deux_point.png", 0);

	for (int i = 0; i < 10; i++)
	{
		char nameSprite[70];
		sprintf(nameSprite, "../Ressources/Assets/Interface/%d.png", i);
		_gd->sprites.spriteTimer[i].sprite = LoadSprite(nameSprite, 1);
	}

	_gd->sprites.spriteTimerBarre.sprite = LoadSprite("../Ressources/Assets/Interface/Barre.png", 1);

	_gd->timer.timerTotal = 60 * 60; //minutes * secondes
	_gd->timer.timerMin = 30; //minutes * secondes
	_gd->timer.timerSec = 0; //minutes * secondes
}

void InitPlayer(GameData* _gd)
{
	//init du joueur
	_gd->player.pos.x = 150.f;
	_gd->player.pos.y = 250.f;
	_gd->player.currentAnim = 0;
	_gd->player.currentTime = 0.f;
	_gd->player.dir = droite;
	_gd->player.idSeq = droiteI;
	_gd->inDream = sfFalse;

	//init du joueur dans le vaisseau 
	_gd->player.pos.x = 0.f;
	_gd->player.pos.y = 0.f;


	//Init camera
	_gd->cam.x = _gd->player.pos.x - _gd->sizeWindow.width / 2;
	_gd->cam.y = _gd->player.pos.y - _gd->sizeWindow.height / 2;

	InitAnim(_gd);

	_gd->player.bulleInteraction[0] = LoadSprite("../Ressources/Assets/Player/interaction_1.png", 0);
	_gd->player.bulleInteraction[1] = LoadSprite("../Ressources/Assets/Player/interaction_2.png", 0);
	_gd->player.bulleDialogue[0] = LoadSprite("../Ressources/Assets/Player/passe.png", 0);
	_gd->player.bulleDialogue[1] = LoadSprite("../Ressources/Assets/Player/passe1.png", 0);
	_gd->player.timeInterraction = 0;
	_gd->player.currentAnimInterraction = 0;
}

void InitSkyIsland(GameData* _gd)
{
	char sprint[999];
	_gd->utilityParallaxe.sky = LoadSprite("../Ressources/Assets/ParallaxeSky/sky.png", 0);

	_gd->utilityParallaxe.horloge = sfClock_create();

	for (int j = 0; j < NB_BIRD; j++)
	{
		_gd->utilityParallaxe.tabBird[j].currentAnimBird = rand() % NB_BIRD;
		_gd->utilityParallaxe.tabBird[j].ttl = 0;

		_gd->utilityParallaxe.tabBird[j].pos.x = -50;
		_gd->utilityParallaxe.tabBird[j].pos.y = (j * 30) + (j * 315);
		_gd->utilityParallaxe.tabBird[j].speed = 1 + rand() % 1;
		_gd->utilityParallaxe.tabBird[j].birdTtlOff = rand() % 10;
		_gd->utilityParallaxe.tabBird[j].birdTtlMaxOff = rand() % 20;
		_gd->utilityParallaxe.tabBird[j].display = sfFalse;
		_gd->utilityParallaxe.tabBird[j].currentBird = rand() % NB_TYPE_BIRD;
	}
	for (int i = 0; i < NB_ANIM_BIRD; i++)
	{
		for (int j = 0; j < NB_TYPE_BIRD; j++)
		{
			sprintf(sprint, "../Ressources/Assets/ParallaxeSky/bird/%d/bird%d.png", j, i);
			_gd->utilityParallaxe.bird[j][i] = LoadSprite(sprint, 0);
		}
	}

	for (int i = 0; i < NB_TYPE_CLOUD; i++)
	{
		sprintf(sprint, "../Ressources/Assets/ParallaxeSky/cloud%d.png", i);
		_gd->utilityParallaxe.cloud[i] = LoadSprite(sprint, 0);
	}

	for (int i = 0; i < NB_CLOUD; i++)
	{
		_gd->utilityParallaxe.tabSky[i].sprite = _gd->utilityParallaxe.cloud[rand() % NB_TYPE_CLOUD];
		_gd->utilityParallaxe.tabSky[i].pos.x = -1000 + rand() % 4000;
		_gd->utilityParallaxe.tabSky[i].pos.y = rand() % 900;
		_gd->utilityParallaxe.tabSky[i].speed = 0.05 + ((float)(rand() % 5) / 100);
		_gd->utilityParallaxe.tabSky[i].pos.z = 0.2f + 0.01f * (rand() % 300);
		_gd->utilityParallaxe.tabSky[i].display = sfTrue;

		if (_gd->utilityParallaxe.tabSky[i].pos.z < 1)
		{
			_gd->utilityParallaxe.tabSky[i].pos.z = 1;
		}
	}
}


void InitArrowBox(GameData* _gd)
{
	//fleche gaudhe
	_gd->arrowBox[0] = LoadSprite("../Ressources/Assets/Box/flecheg1.png", 0);
	_gd->arrowBox[1] = LoadSprite("../Ressources/Assets/Box/flecheg2.png", 0);
	_gd->arrowBox[2] = LoadSprite("../Ressources/Assets/Box/flecheg3.png", 0);
	//fleche droite
	_gd->arrowBox[3] = LoadSprite("../Ressources/Assets/Box/fleched1.png", 0);
	_gd->arrowBox[4] = LoadSprite("../Ressources/Assets/Box/fleched2.png", 0);
	_gd->arrowBox[5] = LoadSprite("../Ressources/Assets/Box/fleched3.png", 0);

	_gd->onSpriteArrowLeft = sfFalse;
	_gd->onSpriteArrowRight = sfFalse;

	_gd->clickSpriteArrowLeft = sfFalse;
	_gd->clickSpriteArrowRight = sfFalse;

	//Pointe gauche du triangle de gauche
	_gd->arrowTriBox[0].vertex[0].x = 208;
	_gd->arrowTriBox[0].vertex[0].y = 505;
	//Pointe haut du triangle de gauche
	_gd->arrowTriBox[0].vertex[1].x = 350;
	_gd->arrowTriBox[0].vertex[1].y = 335;
	//Pointe bas du triangle de gauche
	_gd->arrowTriBox[0].vertex[2].x = 350;
	_gd->arrowTriBox[0].vertex[2].y = 671;
	//Pointe haut du triangle de droite
	_gd->arrowTriBox[1].vertex[0].x = 1615;
	_gd->arrowTriBox[1].vertex[0].y = 335;
	//Pointe bas du triangle de droite
	_gd->arrowTriBox[1].vertex[1].x = 1615;
	_gd->arrowTriBox[1].vertex[1].y = 671;
	//Pointe droite du triangle de droite
	_gd->arrowTriBox[1].vertex[2].x = 1755;
	_gd->arrowTriBox[1].vertex[2].y = 505;

	_gd->trap = LoadSprite("../Ressources/Assets/Box/trap_1.png", 0);

}

void InitIntro(GameData* _gd)
{
	_gd->failDream = sfFalse;
	InitPlayer(_gd);
	InitIntroMap(_gd); //map
	InitSoundIntro(_gd);
	InitSoundCutScenes(_gd);
	InitIA(_gd);
	//InitMastermindIntro(_gd); // a voir dans update player
	_gd->inTp = sfFalse;
}


void InitIsland(GameData* _gd)
{
	_gd->failDream = sfFalse;
	//suppresion du son de l'intro
	DestroySoundIntro(_gd);
	//suppression de la map Intro
	DestroyIntroMap(_gd);
	//init du ciel en parallaxe
	InitSkyIsland(_gd);

	InitAllPuzzle(_gd);
	InitDialogue(_gd);
	InitMastermindBox(_gd);
	//plaque vis a modifier
	InitPlaqueVisBox(_gd);
	//map
	InitIslandMap(_gd);
	//lancement du son du monde 1
	InitSoundWorld1(_gd);
	//InitTimer(_gd); //dans cutscene 
	InitCableBox(_gd);
	InitVoltageBox(_gd);
	//init qui permet de switch entre les enigmes de box
	InitArrowBox(_gd);
}

void DeleteIslandSprite(GameData* _gd)
{
	DeleteSprite(_gd->spriteIsland);
	DeleteSprite(_gd->utilityParallaxe.sky);
	for (int i = 0; i < 6; i++)
	{
		DeleteSprite(_gd->arrowBox[i]);
	}
	for (int i = 0; i < NB_ANIM_BIRD; i++)
	{
		for (int j = 0; j < NB_TYPE_BIRD; j++)
		{
			DeleteSprite(_gd->utilityParallaxe.bird[j][i]);
		}
	}

	for (int i = 0; i < NB_TYPE_CLOUD; i++)
	{
		DeleteSprite(_gd->utilityParallaxe.cloud[i]);
	}

	for (int i = 0; i < _gd->mapIsland->nbNPC; i++)
	{
		DeleteSprite(_gd->npc[i].pnjBox);
		DeleteSprite(_gd->npc[i].dialogueBox);
		for (int j = 0; j < _gd->nbSpriteAnim; j++)
		{
			DeleteSprite(_gd->npc[i].npcDef.Timeline[j]);
		}
	}
}

//si le joueur arrive a la fin du timer de l'island
void ReInitIntro(GameData* _gd)
{
	//delete engime box sprite
	DeleteMastermindBoxSprite(_gd);
	DeletePlaqueVisSprite(_gd);
	DeleteCableSprite(_gd);
	DeleteVoltageSprite(_gd);
	//delete sprite island other enigme 
	DeleteIslandSprite(_gd);
	DestroyIslandMap(_gd);

	_gd->enigme.dialogue.state = NONE;
	InitAnim(_gd); //du perso pour son skin
	InitIntroMap(_gd); //map
	InitSoundIntro(_gd);
	InitSoundCutScenes(_gd);
	InitIA(_gd);
	_gd->enigme.doorDigicode.resolvedIntro = sfTrue;
}

void InitBedRoom(GameData* _gd)
{
	_gd->failDream = sfFalse;
	//delete engime box sprite
	DeleteMastermindBoxSprite(_gd);
	DeletePlaqueVisSprite(_gd);
	DeleteCableSprite(_gd);
	DeleteVoltageSprite(_gd);
	//delete sprite island other enigme 
	DeleteIslandSprite(_gd);
	DestroyIslandMap(_gd);

	InitBedRoomMap(_gd);
	InitSoundHub(_gd);
	InitIA(_gd);

}

void InitJungle(GameData* _gd)
{
	_gd->failDream = sfFalse;
	//suppression du son de bedroom
	DestroySoundHub(_gd);
	////suppression de la map de bedroom
	DestroyBedRoomMap(_gd);
	//init de la map
	InitJungleMap(_gd);
	//init des sons du monde
	InitSoundWorld2(_gd);
	//enigme diode jungle
	InitDiode(_gd);
	//enigme puzzle jungle
	InitPuzzleJungle(_gd);
	//enigme decryptage jungle
	InitDecryptage(_gd);

	//init du timer du niveau
	InitTimerJungle(_gd);

	_gd->CoffreGood = sfFalse;
	_gd->CoffreWrong = sfFalse;
	_gd->CoffreGoodOpen = sfFalse;
	_gd->CoffreWrongOpen = sfFalse;
	_gd->AnimCurrentCoffre = '0';
	_gd->timeAnimCoffre = 0;
	_gd->labyFinish = sfFalse;

	for (int i = 0; i < 3; i++)
	{
		_gd->enigme.interupteur.diodeFini[i] = sfFalse;
	}
	_gd->enigme.interupteur.diodeResolved = sfFalse;

	for (int i = 0; i < 16; i++)
	{
		char chemin[200];
		sprintf(chemin, "../Ressources/Assets/Player/NPC_Fourmi/%d.png", i + 1);
		_gd->fourmi[i] = LoadSprite(chemin, 0);
	}
	_gd->currentAnimFourmi = 0;
	_gd->currentTimeFourmi = 0;
	_gd->inFourmiTp = sfFalse;
	_gd->currentinFourmiTp = 0;

	_gd->steleLabyTuto = LoadSprite("../Ressources/Assets/Interface/steleAide.png", 0);

	sfVector2f postuto = { -10,620 };
	sfVector2f posButton = { 50, 700 };
	_gd->retourTutoLaby.sprite[0] = LoadSprite("../Ressources/Assets/Interface/stelret1.png", 0);
	_gd->retourTutoLaby.sprite[1] = LoadSprite("../Ressources/Assets/Interface/stelret2.png", 0);
	_gd->retourTutoLaby.sprite[2] = LoadSprite("../Ressources/Assets/Interface/stelret3.png", 0);

	_gd->retourTutoLaby.pos = postuto;
	_gd->retourTutoLaby.w = 640;
	_gd->retourTutoLaby.h = 460;

	_gd->onSpriteRetourTutoLaby = sfFalse;
	_gd->clickRetourTutoLaby = sfFalse;

	_gd->retourTutoLaby.forme = sfRectangleShape_create();
	createRectangle(_gd->retourTutoLaby.forme, posButton, 300,
		400, 0);
	//voice Fourmi

	_gd->voiceFourmi.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Interaction/fourmiVoice.wav");
	_gd->voiceFourmi.sound = sfSound_create();
	_gd->voiceFourmi.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->voiceFourmi.sound, _gd->voiceFourmi.buffer);
	sfSound_setVolume(_gd->voiceFourmi.sound, _gd->voiceFourmi.volume);

}

void ReInitBedRoom(GameData* _gd)
{
	//delete engime box sprite
	/*DeleteDiode(_gd);
	DeletePuzzleJungle(_gd);
	DeleteDecryptage(_gd);*/
	//delete sprite island other enigme 
	/*DeleteJungleSprite(_gd);*/
	DeleteSprite(_gd->spriteJungle);

	DestroySoundWorld2(_gd);
	DestroyJungleMap(_gd);

	InitAnim(_gd);
	InitBedRoomMap(_gd);
	InitSoundHub(_gd);
	InitIA(_gd);
}

void InitShipEnd(GameData* _gd)
{
	_gd->failDream == sfFalse;
	_gd->ia_ship.actif = sfFalse;
	DeleteSprite(_gd->spriteJungle);
	//suppresion du son de la jungle
	DestroySoundWorld2(_gd);
	//suppression de la map jungle
	DestroyJungleMap(_gd);

	InitShipEndMap(_gd);
	InitSoundShipEnd(_gd);
	InitIA(_gd);

}

void InitPause(GameData* _gd)
{
	_gd->pause = LoadSprite("../Ressources/Assets/Menu/MenuPause.png", 0);

	_gd->returnMenuPause.sprite[0] = LoadSprite("../Ressources/Assets/Menu/quitter_1.png", 0);
	_gd->returnMenuPause.sprite[1] = LoadSprite("../Ressources/Assets/Menu/quitter_2.png", 0);
	_gd->returnMenuPause.sprite[2] = LoadSprite("../Ressources/Assets/Menu/quitter_3.png", 0);

	sfVector2f posQuit = { 1500, 100 };
	sfVector2f sizeQuit = { 200, 200 };

	_gd->returnMenuPause.pos = posQuit;
	_gd->returnMenuPause.w = sizeQuit.x;
	_gd->returnMenuPause.h = sizeQuit.y;

	_gd->onSpriteQuitPauseMenu = sfFalse;
	_gd->clickSpriteQuitPauseMenu = sfFalse;

	_gd->returnMenuPause.forme = sfRectangleShape_create();
	createRectangle(_gd->returnMenuPause.forme, _gd->returnMenuPause.pos, _gd->returnMenuPause.w, _gd->returnMenuPause.h, 0);

	_gd->quitPause = sfRectangleShape_create();
	//temp
	sfVector2f pos = { 66,77 };
	createRectangle(_gd->quitPause, pos, 165, 142, 0);
	sfRectangleShape_setOutlineColor(_gd->quitPause, sfRed);

	_gd->buttons[5].w = GetSizeFromSprite(_gd->buttons[5].sprite[5]).x;
	_gd->buttons[5].h = GetSizeFromSprite(_gd->buttons[5].sprite[5]).y;
	_gd->buttons[5].pos.x = _gd->sizeWindow.width / 2 - _gd->buttons[3].w / 2;
	_gd->buttons[5].pos.y = 350;

	_gd->buttons[5].forme = sfRectangleShape_create();
	createRectangle(_gd->buttons[5].forme, _gd->buttons[5].pos, (float)_gd->buttons[5].w, (float)_gd->buttons[5].h, 0);
	_gd->onSpriteBV = sfFalse;

	_gd->buttons[6].w = GetSizeFromSprite(_gd->buttons[4].sprite[4]).x;
	_gd->buttons[6].h = GetSizeFromSprite(_gd->buttons[4].sprite[4]).y;
	_gd->buttons[6].pos.x = _gd->buttons[5].pos.x;
	_gd->buttons[6].pos.y = 650 + _gd->buttons[5].h * 2;

	_gd->buttons[6].forme = sfRectangleShape_create();
	createRectangle(_gd->buttons[6].forme, _gd->buttons[6].pos, (float)_gd->buttons[6].w, (float)_gd->buttons[6].h, 0);

	//controle dans pause
	sfVector2f posControle = { _gd->buttons[5].pos.x , 350 + _gd->buttons[5].h * 2 };
	_gd->controleMenuPause.sprite[0] = LoadSprite("../Ressources/Assets/Menu/Controles.png", 0);
	_gd->controleMenuPause.pos = posControle;
	_gd->controleMenuPause.w = GetSizeFromSprite(_gd->buttons[3].sprite[3]).x;
	_gd->controleMenuPause.h = GetSizeFromSprite(_gd->buttons[3].sprite[3]).y;

	_gd->onSpriteControleMenuPause = sfFalse;

	_gd->controleMenuPause.forme = sfRectangleShape_create();
	createRectangle(_gd->controleMenuPause.forme, _gd->controleMenuPause.pos, _gd->controleMenuPause.w, _gd->controleMenuPause.h, 0);
}

void InitAllGame(GameData* _gd)
{
	_gd->sizeWindow.width = 1920;
	_gd->sizeWindow.height = 1080;
	sfVideoMode mode = { _gd->sizeWindow.width, _gd->sizeWindow.height, 32 };
	_gd->window = sfRenderWindow_create(mode, "SFML window", sfNone, NULL); //  | sfFullscreen |   
	sfWindow_setVerticalSyncEnabled(_gd->window, sfTrue);
	//pour le curseur
	sfRenderWindow_setMouseCursorVisible(_gd->window, sfFalse);
	_gd->cursor = LoadSprite("../Ressources/Assets/Cursor/cursor.png", 0);
	_gd->frameRate.frameClock = sfClock_create();

	//init des gamestates du jeu
	_gd->gameState = menu; //menu pour menu 
	_gd->world = begin; // begin pour menu
	_gd->inGameState = load; // load pour menu
	_gd->enigmeState = none; // none quand pas d'enigme
	_gd->enigmeBox = none; // none de base, pour box d'island
	_gd->cutSceneState = noCin; // none de base, pour cinématique
	_gd->enigme.dialogue.state = NONE;

	_gd->soundGlobal = 50;
	_gd->soundMusic = 0.5;
	_gd->soundAmbiance = 0.5;
	_gd->soundInterraction = 0.5;

	srand((unsigned)time(NULL));
	rand();

	switch (_gd->gameState)
	{
	case menu:
		InitMenu(_gd);
		InitPause(_gd);
		break;
	case play:
		/*InitIntro(_gd);
		InitIsland(_gd);
		InitBedRoom(_gd);
		InitJungle(_gd);*/
		break;
	case pause:
		break;

	default:
		break;
	}

	//Recupère l'init de toutes les autres fonctions

}