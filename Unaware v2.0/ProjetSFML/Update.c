#include "Update.h"

void UpdateIntro(GameData* _gd)
{
	switch (_gd->inGameState)
	{
	case exploration:
		UpdateIntroMap(_gd);
		UpdatePlayer(_gd); // a continuer une fois les sprites dispo
		UpdateTimingIAIntro(_gd);
		UpdatePointPlayerSoundIntro(_gd);
		UpdateCamera(_gd);
		UpdateAnimationInterraction(_gd);
		break;
	case enigme:
		UpdateButtonMastermindIntro(_gd);
		break;
	case tuto:
		UpdateButtonMastermindIntroTuto(_gd);
		break;
	case cutscene:
		UpdateCutSceneIntro(_gd);
		if (_gd->failDream == sfTrue)
		{
			UpdateCutSceneFail(_gd);
		}
		break;
	default:
		break;
	}
}

//gestion de la box de l'island, fleche
void UpdateArrowBox(GameData* _gd)
{
	sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouse2f = { posMouse.x,posMouse.y };

	if (CollisionTriangleMouse(posMouse2f, &_gd->arrowTriBox[0]))
	{
		_gd->onSpriteArrowLeft = sfTrue;
	}
	else
	{
		_gd->onSpriteArrowLeft = sfFalse;
	}

	if (CollisionTriangleMouse(posMouse2f, &_gd->arrowTriBox[1]))
	{
		_gd->onSpriteArrowRight = sfTrue;
	}
	else
	{
		_gd->onSpriteArrowRight = sfFalse;
	}
}
//gestion de la box de l'island, quitter
void UpdateButtonQuitBox(GameData* _gd)
{
	sfVector2i posMouseI = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouseF = { posMouseI.x, posMouseI.y };

	if (isCollidingWithMouse(_gd->enigme.houseBox.buttonQuitBox.forme, posMouseF, 0))
	{
		_gd->enigme.houseBox.onSpriteQuitButtonBox = sfTrue;
	}
	else
	{
		_gd->enigme.houseBox.onSpriteQuitButtonBox = sfFalse;
	}
}

void UpdateTutoIsland(GameData* _gd)
{
	//permet de gerer les tuto des enigmes island
	switch (_gd->enigmeState)
	{
	case puzzleIsland:
		UpdateTutoPuzzle(_gd);
		break;
	case dialogueIsland:
		UpdateTutoDialogue(_gd);
		break;
	case mastermindBox:
		UpdateTutoBox(_gd);
	case plaqueBox:
		UpdateTutoBox(_gd);
		break;
	case cableBox:
		UpdateTutoBox(_gd);
		break;
	case voltageBox:
		UpdateTutoBox(_gd);
		break;
	default:
		break;
	}
}


void UpdateIsland(GameData* _gd)
{
	UpdateTimerIsland(_gd);

	switch (_gd->inGameState)
	{
	case exploration:
		UpdateIslandMap(_gd);
		UpdateSkyIsland(_gd);
		UpdatePointPlayerSoundIsland(_gd);
		UpdatePlayer(_gd); // a continuer une fois les sprites dispo
		UpdateCamera(_gd);
		UpdateAnimationNPC(_gd);
		UpdateDialogue(_gd);
		UpdateAnimationInterraction(_gd);
		break;

	case enigme:
		switch (_gd->enigmeState)
		{
		case puzzleIsland:
			UpdatePuzzle(_gd);
			break;
		case mastermindBox:
			UpdateButtonHelpMastermindBox(_gd);
			UpdateButtonQuitBox(_gd);
			UpdateArrowBox(_gd);
			break;
		case plaqueBox:
			UpdatePlaqueVisBox(_gd);
			UpdateButtonQuitBox(_gd);
			UpdateArrowBox(_gd);
			break;
		case cableBox:
			UpdateCableBox(_gd);
			UpdateButtonQuitBox(_gd);
			UpdateArrowBox(_gd);
			break;
		case voltageBox:
			UpdateVoltageBox(_gd);
			UpdateButtonQuitBox(_gd);
			UpdateArrowBox(_gd);
			break;
		default:
			break;
		}
		break;
	case tuto:
		UpdateTutoIsland(_gd);
		break;
	case cutscene:
		UpdateCutSceneIsland(_gd);
		break;
	default:
		break;
	}
}

void UpdateBedRoom(GameData* _gd)
{
	switch (_gd->inGameState)
	{
	case exploration:
		UpdateBedRoomMap(_gd);
		UpdatePointPlayerSoundHub(_gd);
		UpdatePlayer(_gd); // a continuer une fois les sprites dispo
		UpdateCamera(_gd);
		UpdateTimingIABedRoom(_gd);
		UpdateAnimationInterraction(_gd);
		break;
	case cutscene:
		UpdateCutSceneBedRoom(_gd);
		if (_gd->failDream == sfTrue)
		{
			UpdateCutSceneFail(_gd);
		}
		break;
	default:
		break;
	}
}

void UpdateSymboleDiode(GameData* _gd)
{
	sfVector2i posMouseI = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouseF = { posMouseI.x, posMouseI.y };

	if (isCollidingWithMouse(_gd->enigme.interupteur.retourButtonDiode.forme, posMouseF, 0))
	{
		_gd->enigme.interupteur.onSpriteRetourButtonDiode = sfTrue;
	}
	else
	{
		_gd->enigme.interupteur.onSpriteRetourButtonDiode = sfFalse;
	}
}

void UpdateTutoLabyrinthe(GameData* _gd)
{
	sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouse2f = { posMouse.x,posMouse.y };

	if (isCollidingWithMouse(_gd->retourTutoLaby.forme, posMouse2f, 0))
	{
		_gd->onSpriteRetourTutoLaby = sfTrue;
	}
	else
	{
		_gd->onSpriteRetourTutoLaby = sfFalse;
	}
}


void UpdateTutoJungle(GameData* _gd)
{
	//permet de gerer les tuto des enigmes island
	switch (_gd->enigmeState)
	{
	case diodeJungle:
		UpdateTutoDiodeJungle(_gd);
		break;
	case puzzleJungle:
		UpdateTutoPuzzleJungle(_gd);
		break;
	case decryptageJungle:
		UpdateTutoDecryptage(_gd);
		break;
	case labyrinthe:
		UpdateTutoLabyrinthe(_gd);
		break;
	default:
		break;
	}
}

void UpdateJungle(GameData* _gd)
{
	UpdateTimerJungle(_gd);

	switch (_gd->inGameState)
	{
	case exploration:
		UpdateJungleMap(_gd);
		UpdatePointPlayerSoundJungle(_gd);
		UpdatePlayer(_gd); // a continuer une fois les sprites dispo
		UpdateLabyrinth(_gd);
		UpdateCamera(_gd);
		UpdateAnimationInterraction(_gd);
		
		if (_gd->enigme.puzzleJungle.resolvedPuzzleJungle == sfTrue
			&& _gd->enigme.decryptage.isVisible[6] == sfFalse)
		{
			_gd->enigme.decryptage.nbPaperRecup++;
			_gd->enigme.decryptage.isVisible[6] = sfTrue;
			
		}
		if (_gd->labyFinish == sfTrue)
		{
			_gd->enigme.decryptage.isVisible[4] = sfTrue;
			_gd->enigme.decryptage.isVisible[5] = sfTrue;
		}
	
		break;
	case enigme:
		switch (_gd->enigmeState)
		{
		case diodeJungle:
			UpdateButtonJungle(_gd);
			break;
		case puzzleJungle:
			UpdatePuzzleJungle(_gd);		
			break;
		case decryptageJungle:
			UpdateDecryptage(_gd);
			break;
		default:
			break;
		}
		break;
	case tuto:
		UpdateTutoJungle(_gd);
		break;
	case symbole:
		UpdateSymboleDiode(_gd);
		break;
	case cutscene:
		UpdateCutSceneJungle(_gd);
		break;
	default:
		break;
	}
}

void UpdateShipEnd(GameData* _gd)
{
	switch (_gd->inGameState)
	{
	case exploration:
		UpdateShipEndMap(_gd);
		UpdatePointPlayerSoundShipEnd(_gd);
		UpdatePlayer(_gd); // a continuer une fois les sprites dispo
		UpdateCamera(_gd);
		UpdateTimingIABedEnd(_gd);
		UpdateAnimationInterraction(_gd);
		break;
	case cutscene:
		UpdateCutSceneShipEnd(_gd);
		break;
	}
}

void UpdatePause(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos;
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	if (isCollidingWithMouse(_gd->buttons[5].forme, tempPos, 1))
	{
		_gd->onSpriteBV = sfTrue;
	}
	else
	{
		_gd->onSpriteBV = sfFalse;
	}
	if (isCollidingWithMouse(_gd->buttons[6].forme, tempPos, 0))
	{
		_gd->onSpriteQuitPauseMenu = sfTrue;
	}
	else
	{
		_gd->onSpriteQuitPauseMenu = sfFalse;
	}
	if (isCollidingWithMouse(_gd->controleMenuPause.forme, tempPos, 0))
	{
		_gd->onSpriteControleMenuPause = sfTrue;
	}
	else
	{
		_gd->onSpriteControleMenuPause = sfFalse;
	}
	////mute sound ambiance point 
	//switch (_gd->world)
	//{
	//case intro:
	//	for (int i = 0; i < _gd->mapIntro->nbElec; i++)
	//	{
	//		sfSound_setVolume(_gd->mapIntro->introPointSound.electricity[i].sound, 0);
	//	}
	//	for (int i = 0; i < _gd->mapIntro->nbVent; i++)
	//	{
	//		sfSound_setVolume(_gd->mapIntro->introPointSound.ventilation[i].sound, 0);

	//	}
	//	/*for (int i = 0; i < _gd->mapIntro->nbCat; i++)
	//	{
	//		sfSound_setVolume(_gd->mapIntro->introPointSound.cat[i].sound, 0);
	//	}*/
	//	for (int i = 0; i < _gd->mapIntro->nbConsole; i++)
	//	{
	//		sfSound_setVolume(_gd->mapIntro->introPointSound.console[i].sound, 0);

	//	}
	//	break;
	//	//y'avait un updateIsland perdu ici
	//default:
	//	break;
	//}

}

void UpdateInGame(GameData* _gd)
{
	switch (_gd->world)
	{
	case intro:
		UpdateIntro(_gd);
		break;
	case island:
		UpdateIsland(_gd);
		break;
	case bedroom:
		UpdateBedRoom(_gd);
		break;
	case jungle:
		UpdateJungle(_gd);
		break;
	case shipEnd:
		UpdateShipEnd(_gd);
		break;
	default:
		break;
	}
}

void UpdateAllGame(GameData* _gd)
{
	//update de tout le jeu
	//un update pour chaque chose
	//machine a état

	switch (_gd->gameState)
	{
	case menu:
		UpdateMenu(_gd);
		break;
	case option:
		UpdateMenu(_gd);
		break;
	case selecteurPerso:
		UpdateSelectPerso(_gd);
		break;
	case play:
		UpdateInGame(_gd);
		break;
	case pause:
		UpdatePause(_gd);
		break;
	case volume:
		UpdateVolume(_gd);
		break;
	default:
		break;
	}
}
