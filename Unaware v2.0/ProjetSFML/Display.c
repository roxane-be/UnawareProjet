#include "Display.h"

void DisplayPlayer(GameData* _gd)
{
	BlitSprite(_gd->player.persoDef->Timeline[_gd->player.currentAnim], _gd->player.pos.x - _gd->cam.x, _gd->player.pos.y - _gd->cam.y, 0, 1, 1, _gd);
}

void DisplayPlancheHUD(GameData* _gd)
{
	BlitSprite(_gd->sprites.spriteTimer[_gd->enigme.utilityPuzzle.nbPlancheRecup].sprite, (_gd->sizeWindow.width / 2) + 19, 120, 0, 0.5, 0.5, _gd);
	BlitSprite(_gd->sprites.spriteTimerBarre.sprite, (_gd->sizeWindow.width / 2) + 47, 120, 0, 0.5, 0.5, _gd);
	BlitSprite(_gd->sprites.spriteTimer[9].sprite, (_gd->sizeWindow.width / 2) + 75, 120, 0, 0.5, 0.5, _gd);

	BlitSprite(_gd->enigme.utilityPuzzle.planche, (_gd->sizeWindow.width / 2) + 90, 100, 0, 0.5, 0.5, _gd);
}

void DisplayPaperHUD(GameData* _gd)
{
	BlitSprite(_gd->sprites.spriteTimer[_gd->enigme.decryptage.nbPaperRecup].sprite, (_gd->sizeWindow.width / 2) + 19, 120, 0, 0.5, 0.5, _gd);
	BlitSprite(_gd->sprites.spriteTimerBarre.sprite, (_gd->sizeWindow.width / 2) + 47, 120, 0, 0.5, 0.5, _gd);
	BlitSprite(_gd->sprites.spriteTimer[9].sprite, (_gd->sizeWindow.width / 2) + 75, 120, 0, 0.5, 0.5, _gd);
	BlitSprite(_gd->enigme.decryptage.paperHUD, (_gd->sizeWindow.width / 2) + 90, 100, 0, 0.5, 0.5, _gd);

}

void DisplayPlanchePlus(GameData* _gd)
{
	_gd->enigme.utilityPuzzle.posPlusPlanche.x = _gd->player.pos.x;
	_gd->enigme.utilityPuzzle.posPlusPlanche.y = _gd->player.pos.y - _gd->enigme.utilityPuzzle.upPlus;

	if (_gd->enigme.utilityPuzzle.posPlusPlanche.y > _gd->player.pos.y - 70 - 20
		&& _gd->enigme.utilityPuzzle.isTwoPlanche == sfTrue)
	{
		_gd->enigme.utilityPuzzle.upPlus += 0.9f;
		BlitSprite(_gd->enigme.utilityPuzzle.plusPlanche, _gd->enigme.utilityPuzzle.posPlusPlanche.x - _gd->cam.x + 30, _gd->enigme.utilityPuzzle.posPlusPlanche.y - _gd->cam.y - 35, 0, 1, 1, _gd);
		BlitSprite(_gd->enigme.utilityPuzzle.planche, _gd->enigme.utilityPuzzle.posPlusPlanche.x - _gd->cam.x + 40 + 30, _gd->enigme.utilityPuzzle.posPlusPlanche.y - _gd->cam.y - 35, 0, 0.5, 0.5, _gd);

	}
	if (_gd->enigme.utilityPuzzle.posPlusPlanche.y > _gd->player.pos.y - 70 - 20)
	{
		_gd->enigme.utilityPuzzle.upPlus += 0.9f;
		BlitSprite(_gd->enigme.utilityPuzzle.plusPlanche, _gd->enigme.utilityPuzzle.posPlusPlanche.x - _gd->cam.x - 5, _gd->enigme.utilityPuzzle.posPlusPlanche.y - _gd->cam.y - 70, 0, 1, 1, _gd);
		BlitSprite(_gd->enigme.utilityPuzzle.planche, _gd->enigme.utilityPuzzle.posPlusPlanche.x - _gd->cam.x + 40, _gd->enigme.utilityPuzzle.posPlusPlanche.y - _gd->cam.y - 70, 0, 0.5, 0.5, _gd);

	}
	else
	{
		_gd->enigme.utilityPuzzle.recupPlanche = sfFalse;
		_gd->enigme.utilityPuzzle.upPlus = 0;
		_gd->enigme.utilityPuzzle.isTwoPlanche = sfFalse;
	}
}


void DisplayPaperPlus(GameData* _gd)
{
	_gd->enigme.decryptage.posPaperHUD.x = _gd->player.pos.x;
	_gd->enigme.decryptage.posPaperHUD.y = _gd->player.pos.y - _gd->enigme.decryptage.upPlus;

	if (_gd->enigme.decryptage.posPaperHUD.y > _gd->player.pos.y - 70 - 20
		&& _gd->enigme.decryptage.TwoPaper == sfTrue)
	{
		_gd->enigme.decryptage.upPlus += 0.7f;
		BlitSprite(_gd->enigme.decryptage.plus1, _gd->enigme.decryptage.posPaperHUD.x - _gd->cam.x + 30, _gd->enigme.decryptage.posPaperHUD.y - _gd->cam.y - 35, 0, 1, 1, _gd);
		BlitSprite(_gd->enigme.decryptage.paperHUD, _gd->enigme.decryptage.posPaperHUD.x - _gd->cam.x + 40 + 30, _gd->enigme.decryptage.posPaperHUD.y - _gd->cam.y - 35, 0, 0.5, 0.5, _gd);

	}
	if (_gd->enigme.decryptage.posPaperHUD.y > _gd->player.pos.y - 70 - 20)
	{
		_gd->enigme.decryptage.upPlus += 0.7f;
		BlitSprite(_gd->enigme.decryptage.plus1, _gd->enigme.decryptage.posPaperHUD.x - _gd->cam.x - 5, _gd->enigme.decryptage.posPaperHUD.y - _gd->cam.y - 70, 0, 1, 1, _gd);
		BlitSprite(_gd->enigme.decryptage.paperHUD, _gd->enigme.decryptage.posPaperHUD.x - _gd->cam.x + 40, _gd->enigme.decryptage.posPaperHUD.y - _gd->cam.y - 70, 0, 0.5, 0.5, _gd);

	}
	else
	{
		_gd->enigme.decryptage.TwoPaper = sfFalse;
		_gd->enigme.decryptage.InRecup = sfFalse;
		_gd->enigme.decryptage.upPlus = 0;
	}
}

void DisplayButtonQuitBox(GameData* _gd)
{
	BlitSprite(_gd->enigme.houseBox.buttonQuitBox.buttonSprite[0],
		_gd->enigme.houseBox.buttonQuitBox.pos.x - 10,
		_gd->enigme.houseBox.buttonQuitBox.pos.y - 5, 0, 1, 1, _gd);

	if (_gd->enigme.houseBox.onSpriteQuitButtonBox == sfTrue)
	{
		BlitSprite(_gd->enigme.houseBox.buttonQuitBox.buttonSprite[1],
			_gd->enigme.houseBox.buttonQuitBox.pos.x - 10,
			_gd->enigme.houseBox.buttonQuitBox.pos.y - 5, 0, 1, 1, _gd);
	}

	if (_gd->enigme.houseBox.clickQuitButtonBox == sfTrue)
	{
		BlitSprite(_gd->enigme.houseBox.buttonQuitBox.buttonSprite[2],
			_gd->enigme.houseBox.buttonQuitBox.pos.x - 10,
			_gd->enigme.houseBox.buttonQuitBox.pos.y - 5, 0, 1, 1, _gd);
	}

	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.houseBox.buttonQuitBox.forme, NULL);
}

void DisplaySkyIsland(GameData* _gd)
{
	BlitSprite(_gd->utilityParallaxe.sky, 0, 0, 0, 1, 1, _gd);
	for (int i = 0; i < NB_CLOUD; i++)
	{
		float tempTaille = 1.0f / _gd->utilityParallaxe.tabSky[i].pos.z;
		//rajouter ici le sizewindow, avec un + et - 
		if (_gd->utilityParallaxe.tabSky[i].pos.x > -180 &&
			_gd->utilityParallaxe.tabSky[i].pos.x < _gd->mapIsland->witdh * _gd->mapIsland->tilewitdh)
		{
			BlitSprite(_gd->utilityParallaxe.tabSky[i].sprite, _gd->utilityParallaxe.tabSky[i].pos.x,
				_gd->utilityParallaxe.tabSky[i].pos.y, 0, tempTaille, tempTaille, _gd);
		}
	}

	for (int i = 0; i < NB_BIRD; i++)
	{
		if (_gd->utilityParallaxe.tabBird[i].display)
		{
			_gd->utilityParallaxe.tabBird[i].sprite = _gd->utilityParallaxe.bird[_gd->utilityParallaxe.tabBird[i].currentBird][_gd->utilityParallaxe.tabBird[i].currentAnimBird];
			BlitSprite(_gd->utilityParallaxe.tabBird[i].sprite, _gd->utilityParallaxe.tabBird[i].pos.x, _gd->utilityParallaxe.tabBird[i].pos.y, 0, 1, 1, _gd);
		}
	}
}

void DisplayIntro(GameData* _gd)
{
	switch (_gd->inGameState)
	{
	case enigme:
		switch (_gd->enigmeState)
		{
		case mastermindIntro:
			DisplayMastermindIntro(_gd);
			break;

		default:
			break;
		}
		break;
	case exploration:
		DisplayIntroMap(_gd);
		DisplayPlayer(_gd);
		DisplayIntroMapUpper(_gd);
		DisplayIA(_gd);
		if (_gd->player.interaction == sfTrue)
		{
			BlitSprite(_gd->player.bulleInteraction[_gd->player.currentAnimInterraction], _gd->player.pos.x - _gd->cam.x - 20, _gd->player.pos.y - _gd->cam.y - 140, 0, 1, 1, _gd);
		}

		break;
	case tuto:
		switch (_gd->enigmeState)
		{
		case mastermindIntro:
			DisplayTutoMastermindIntro(_gd);
			break;

		default:
			break;
		}
		break;
	case cutscene:
		DisplayCutSceneIntro(_gd);
		if (_gd->failDream == sfTrue)
		{
			DisplayCutSceneFail(_gd);
		}
		break;
	default:
		break;
	}
}

void DisplayTutoIsland(GameData* _gd)
{
	switch (_gd->enigmeState)
	{
	case puzzleIsland:
		DisplayTutoPuzzle(_gd);
		break;
	case dialogueIsland:
		DisplayTutoDialogue(_gd);
		break;
	case mastermindBox:
		DisplayTutoBox(_gd);
		break;
	case plaqueBox:
		DisplayTutoBox(_gd);
		break;
	case cableBox:
		DisplayTutoBox(_gd);
		break;
	case voltageBox:
		DisplayTutoBox(_gd);
		break;
	default:
		break;
	}
}

void DisplayIsland(GameData* _gd)
{
	switch (_gd->inGameState)
	{
	case enigme:
		switch (_gd->enigmeState)
		{
		case mastermindBox:
			DisplayMastermindBox(_gd);
			DisplayButtonQuitBox(_gd);
			break;
		case puzzleIsland:
			DisplayPuzzle(_gd);
			break;
		case plaqueBox:
			DisplayPlaqueVisBox(_gd);
			DisplayButtonQuitBox(_gd);
			break;
		case cableBox:
			DisplayCableBox(_gd);
			DisplayButtonQuitBox(_gd);
			break;
		case voltageBox:
			DisplayVoltageBox(_gd);
			DisplayButtonQuitBox(_gd);
			break;
		default:
			break;
		}
		break;

	case exploration:
		DisplaySkyIsland(_gd);
		DisplayIslandMap(_gd);
		DisplayPlayer(_gd);
		//affichage des +1planches
		if (_gd->enigme.utilityPuzzle.recupPlanche == sfTrue)
		{
			DisplayPlanchePlus(_gd);
		}
		//HUD des planches à récuperer
		if (_gd->enigme.utilityPuzzle.openFirstTime == sfTrue && _gd->enigme.utilityPuzzle.resolvedPuzzleDream_1 == sfFalse)
		{
			DisplayPlancheHUD(_gd);
		}
		else if (_gd->enigme.utilityPuzzle.nbPlancheRecup > 0 && _gd->enigme.utilityPuzzle.resolvedPuzzleDream_1 == sfFalse)
		{
			DisplayPlancheHUD(_gd);
		}
		DisplayIslandMapUpper(_gd);
		DisplayDialogue(_gd);
		//pour avoir le E par dessus tout
		if (_gd->player.interaction == sfTrue
			&& _gd->enigme.dialogue.state == NONE)
		{
			BlitSprite(_gd->player.bulleInteraction[_gd->player.currentAnimInterraction], _gd->player.pos.x - _gd->cam.x - 20, _gd->player.pos.y - _gd->cam.y - 140, 0, 1, 1, _gd);
		}
		else if (_gd->player.interaction == sfTrue
			&& _gd->enigme.dialogue.state == INDIALOGUE)
		{
			BlitSprite(_gd->player.bulleDialogue[_gd->player.currentAnimInterraction], 820, 920, 0, 1, 1, _gd);
		}


		break;
	case tuto:
		DisplayTutoIsland(_gd);
		break;

	case cutscene:
		DisplayCutSceneIsland(_gd);
		break;
	default:
		break;
	}

	if (_gd->enigmeBox == box && _gd->inGameState != tuto && _gd->inGameState != cutscene)
	{
		BlitSprite(_gd->arrowBox[0], 150, 300, 0, 1, 1, _gd);

		if (_gd->onSpriteArrowLeft)
		{
			BlitSprite(_gd->arrowBox[1], 150, 300, 0, 1, 1, _gd);
		}
		if (_gd->clickSpriteArrowLeft == sfTrue)
		{
			BlitSprite(_gd->arrowBox[2], 150, 300, 0, 1, 1, _gd);
		}

		BlitSprite(_gd->arrowBox[3], 1550, 300, 0, 1, 1, _gd);

		if (_gd->onSpriteArrowRight)
		{
			BlitSprite(_gd->arrowBox[4], 1550, 300, 0, 1, 1, _gd);
		}
		if (_gd->clickSpriteArrowRight == sfTrue)
		{
			BlitSprite(_gd->arrowBox[5], 1550, 300, 0, 1, 1, _gd);
		}
	}

	DisplayTimerInterface(_gd);

	if (_gd->timer.timerTotal > 0 && _gd->inGameState != cutscene)
	{
		DisplayTimerIsland(_gd);
	}

}

void DisplayBedRoom(GameData* _gd)
{
	switch (_gd->inGameState)
	{
	case exploration:
		DisplayBedRoomMap(_gd);
		DisplayPlayer(_gd);
		DisplayBedRoomMapUpper(_gd);
		DisplayIA(_gd);

		if (_gd->player.interaction == sfTrue)
		{
			BlitSprite(_gd->player.bulleInteraction[_gd->player.currentAnimInterraction], _gd->player.pos.x - _gd->cam.x - 20, _gd->player.pos.y - _gd->cam.y - 140, 0, 1, 1, _gd);
		}

		break;
	case cutscene:
		DisplayCutSceneBedRoom(_gd);
		if (_gd->failDream == sfTrue)
		{
			DisplayCutSceneFail(_gd);
		}
		break;
	default:
		break;
	}
}

void DisplayTutoLabyrinthe(GameData* _gd)
{
	BlitSprite(_gd->steleLabyTuto, 0, 0, 0, 1, 1, _gd);

	BlitSprite(_gd->retourTutoLaby.sprite[0], _gd->retourTutoLaby.pos.x, _gd->retourTutoLaby.pos.y,
		0, 1, 1, _gd);

	if (_gd->onSpriteRetourTutoLaby == sfTrue
		&& _gd->clickRetourTutoLaby == sfFalse)
	{
		BlitSprite(_gd->retourTutoLaby.sprite[1], _gd->retourTutoLaby.pos.x, _gd->retourTutoLaby.pos.y,
			0, 1, 1, _gd);
	}
	if (_gd->clickRetourTutoLaby == sfTrue)
	{
		BlitSprite(_gd->retourTutoLaby.sprite[2], _gd->retourTutoLaby.pos.x, _gd->retourTutoLaby.pos.y,
			0, 1, 1, _gd);
	}

}

void DisplayTutoJungle(GameData* _gd)
{
	switch (_gd->enigmeState)
	{
	case diodeJungle:
		DisplayTutoDiode(_gd);
		break;
	case puzzleJungle:
		DisplayTutoPuzzleJungle(_gd);
		break;
	case decryptageJungle:
		DisplayTutoDecryptage(_gd);
		break;
	case labyrinthe:
		DisplayTutoLabyrinthe(_gd);
		break;
	default:
		break;
	}
}

void DisplaySymboleDiodeJungle(GameData* _gd)
{
	BlitSprite(_gd->enigme.interupteur.backgroundDiode, 0, 0, 0, 1, 1, _gd);
	BlitSprite(_gd->enigme.interupteur.backgroundSymboleDiode, 0, 0, 0, 1, 1, _gd);

	BlitSprite(_gd->enigme.interupteur.retourButtonDiode.buttonSprite[0], _gd->enigme.interupteur.retourButtonDiode.pos.x - 40,
		_gd->enigme.interupteur.retourButtonDiode.pos.y - 40, 0, 1, 1, _gd);

	if (_gd->enigme.interupteur.onSpriteRetourButtonDiode == sfTrue)
	{
		BlitSprite(_gd->enigme.interupteur.retourButtonDiode.buttonSprite[1], _gd->enigme.interupteur.retourButtonDiode.pos.x - 40,
			_gd->enigme.interupteur.retourButtonDiode.pos.y - 40, 0, 1, 1, _gd);
	}
	if (_gd->enigme.interupteur.clickRetourButtonDiode == sfTrue)
	{
		BlitSprite(_gd->enigme.interupteur.retourButtonDiode.buttonSprite[2], _gd->enigme.interupteur.retourButtonDiode.pos.x - 40,
			_gd->enigme.interupteur.retourButtonDiode.pos.y - 40, 0, 1, 1, _gd);
	}

	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.interupteur.retourButtonDiode.forme, NULL);
}

void DisplayJungle(GameData* _gd)
{
	switch (_gd->inGameState)
	{
	case exploration:
		DisplayJungleMap(_gd);
		DisplayPlayer(_gd);
		DisplayJungleMapUpper(_gd);
		if (_gd->player.interaction == sfTrue)
		{
			BlitSprite(_gd->player.bulleInteraction[_gd->player.currentAnimInterraction], _gd->player.pos.x - _gd->cam.x - 20, _gd->player.pos.y - _gd->cam.y - 140, 0, 1, 1, _gd);
		}
		if (_gd->enigme.decryptage.InRecup == sfTrue)
		{
			DisplayPaperPlus(_gd);
		}
		if (_gd->enigme.decryptage.againOpen == sfTrue)
		{
			//
		}
		DisplayPaperHUD(_gd);

		break;
	case enigme:
		switch (_gd->enigmeState)
		{
		case diodeJungle:
			DisplayDiode(_gd);
			break;
		case puzzleJungle:
			DisplayPuzzleJungle(_gd);
			break;
		case decryptageJungle:
			DisplayDecryptage(_gd);
			break;
		default:
			break;
		}
		break;
	case tuto:
		DisplayTutoJungle(_gd);
		break;
	case symbole:
		DisplaySymboleDiodeJungle(_gd);
		break;
	case cutscene:
		DisplayCutSceneJungle(_gd);
		break;
	default:
		break;
	}

	if (_gd->timer.timerTotal > 0.0f && _gd->inGameState != cutscene)
	{
		DisplayTimerInterfaceJungle(_gd);
		DisplayTimerJungle(_gd);
	}
}

void DisplayShipEnd(GameData* _gd)
{
	switch (_gd->inGameState)
	{
	case exploration:
		DisplayShipEndMap(_gd);
		DisplayPlayer(_gd);
		DisplayShipEndMapUpper(_gd);
		DisplayIA(_gd);
		if (_gd->player.interaction == sfTrue)
		{
			BlitSprite(_gd->player.bulleInteraction[_gd->player.currentAnimInterraction], _gd->player.pos.x - _gd->cam.x - 20, _gd->player.pos.y - _gd->cam.y - 140, 0, 1, 1, _gd);
		}
		break;
	case cutscene:
		DisplayCutSceneShipEnd(_gd);
		break;
	}

}


void DisplayInGame(GameData* _gd)
{
	//gameState Play
	switch (_gd->world)
	{
	case intro:
		DisplayIntro(_gd);
		break;

	case bedroom:
		DisplayBedRoom(_gd);
		break;

	case island:
		DisplayIsland(_gd);
		break;

	case jungle:
		DisplayJungle(_gd);
		break;

	case shipEnd:
		DisplayShipEnd(_gd);
		break;
	default:
		break;
	}
	//Affichage

}

void DisplaySelecteurPerso(GameData* _gd)
{
	BlitSprite(_gd->backgroundSelectPerso, 0, 0, 0, 1, 1, _gd);
	/*BlitSprite(_gd->returnMenu, 20, 50, 0, 1, 1, _gd);*/

	//Tout ca pour gerer quel sprites est dessus ou pas, a garder dans cette ordre...
	if (_gd->choixPerso == 0 && _gd->isSelect == sfTrue)
	{
		BlitSprite(_gd->buttonsSelecteur[0].sprite[2], _gd->buttonsSelecteur[0].pos.x + 10, _gd->buttonsSelecteur[0].pos.y + 15, 0, 1, 1, _gd);
		BlitSprite(_gd->buttonsSelecteur[0].sprite[1], _gd->buttonsSelecteur[0].pos.x, _gd->buttonsSelecteur[0].pos.y, 0, 1, 1, _gd);
	}

	BlitSprite(_gd->backgroundGarcon, 0, 0, 0, 1, 1, _gd);

	if (_gd->choixPerso == 1 && _gd->isSelect == sfTrue)
	{
		BlitSprite(_gd->buttonsSelecteur[0].sprite[3], _gd->buttonsSelecteur[0].pos.x + 10, _gd->buttonsSelecteur[0].pos.y + 15, 0, 1, 1, _gd);
		BlitSprite(_gd->buttonsSelecteur[0].sprite[0], _gd->buttonsSelecteur[0].pos.x, _gd->buttonsSelecteur[0].pos.y, 0, 1, 1, _gd);

	}

	if (_gd->choixPerso == 1 && _gd->isSelect == sfTrue)
	{
		BlitSprite(_gd->buttonsSelecteur[1].sprite[2], _gd->buttonsSelecteur[1].pos.x + 12, _gd->buttonsSelecteur[1].pos.y + 15, 0, 1, 1, _gd);
		BlitSprite(_gd->buttonsSelecteur[1].sprite[1], _gd->buttonsSelecteur[1].pos.x, _gd->buttonsSelecteur[1].pos.y, 0, 1, 1, _gd);
	}

	BlitSprite(_gd->backgroundFille, 0, 0, 0, 1, 1, _gd);


	if (_gd->choixPerso == 0 && _gd->isSelect == sfTrue)
	{
		BlitSprite(_gd->buttonsSelecteur[1].sprite[3], _gd->buttonsSelecteur[1].pos.x + 12, _gd->buttonsSelecteur[1].pos.y + 15, 0, 1, 1, _gd);
		BlitSprite(_gd->buttonsSelecteur[1].sprite[0], _gd->buttonsSelecteur[1].pos.x, _gd->buttonsSelecteur[1].pos.y, 0, 1, 1, _gd);
	}
	//...jusque la


	if (_gd->choixPerso == -1)
	{
		BlitSprite(_gd->buttonsSelecteur[0].sprite[3], _gd->buttonsSelecteur[0].pos.x + 10, _gd->buttonsSelecteur[0].pos.y + 15, 0, 1, 1, _gd);
		BlitSprite(_gd->buttonsSelecteur[1].sprite[3], _gd->buttonsSelecteur[1].pos.x + 12, _gd->buttonsSelecteur[1].pos.y + 15, 0, 1, 1, _gd);

		BlitSprite(_gd->buttonsSelecteur[0].sprite[0], _gd->buttonsSelecteur[0].pos.x, _gd->buttonsSelecteur[0].pos.y, 0, 1, 1, _gd);
		BlitSprite(_gd->buttonsSelecteur[1].sprite[0], _gd->buttonsSelecteur[1].pos.x, _gd->buttonsSelecteur[1].pos.y, 0, 1, 1, _gd);
	}

	if (_gd->onSpriteButtonSelectG == sfTrue)
	{
		BlitSprite(_gd->buttonsSelecteur[0].sprite[2], _gd->buttonsSelecteur[0].pos.x + 10, _gd->buttonsSelecteur[0].pos.y + 15, 0, 1, 1, _gd);
	}

	if (_gd->onSpriteButtonSelectF == sfTrue)
	{
		BlitSprite(_gd->buttonsSelecteur[1].sprite[2], _gd->buttonsSelecteur[1].pos.x + 12, _gd->buttonsSelecteur[1].pos.y + 15, 0, 1, 1, _gd);
	}

	BlitSprite(_gd->buttonCadreText.sprite[0], _gd->buttonCadreText.pos.x, _gd->buttonCadreText.pos.y, 0, 1, 1, _gd);

	if (_gd->onSpriteCadreText == sfTrue || _gd->clickCadreText == sfTrue)
	{
		BlitSprite(_gd->buttonCadreText.sprite[1], _gd->buttonCadreText.pos.x, _gd->buttonCadreText.pos.y, 0, 1, 1, _gd);
	}

	BlitText(_gd->texts.namePerso.text,
		_gd->texts.namePerso.pos.x,
		_gd->texts.namePerso.pos.y,
		sfBlack, (sfVector2f) { 1, 1 }, _gd->window);
}


void DisplayAllGame(GameData* _gd)
{
	sfRenderWindow_clear(_gd->window, sfBlue);

	//machine a etat pour l'affichage aussi

	switch (_gd->gameState)
	{
	case menu:
		DisplayMenu(_gd);
		break;
	case selecteurPerso:
		DisplaySelecteurPerso(_gd);
		break;
	case play:
		DisplayInGame(_gd);
		break;
	case pause:
		DisplayPause(_gd);
		break;
	case credit:
		DisplayCredit(_gd);
		break;
	case controle:
		DisplayControle(_gd);
		break;
	case option:
		DisplayOption(_gd);
		break;
	case volume:
		DisplayVolume(_gd);
		break;
	default:
		break;
	}

	sfVector2i mouse = sfMouse_getPositionRenderWindow(_gd->window);
	if ((_gd->inGameState != exploration
		&& _gd->inGameState != cutscene)
		|| _gd->gameState == pause || _gd->gameState == controle 
		|| _gd->gameState == volume 
		|| _gd->enigme.dialogue.state == DOOR)
	{
		BlitSprite(_gd->cursor, mouse.x - 18, mouse.y - 3, 0, 1, 1, _gd);
	}

	sfRenderWindow_display(_gd->window);
}