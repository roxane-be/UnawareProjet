#include "UpdateCutScene.h"

void UpdateCutSceneIntro(GameData* _gd)
{
	int zoom = 0;
	switch (_gd->world)
	{
	case intro:
		switch (_gd->cutSceneState)
		{
		case vaisseauIntro:
			if (_gd->cinematique.currentAnim == 0 && _gd->worldAmbience.isPlaying == sfFalse)
			{
				DeleteCutScene(_gd);
				InitSoundAmbience(_gd);
			}
			else if (_gd->cinematique.currentAnim == NB_CUTSCENE_SHIP_INTRO)
			{
				_gd->cinematique.currentTime = 0;
				_gd->cinematique.currentAnim = 0;
				_gd->cinematique.pos.z = 0.8;
				_gd->cinematique.opacity = 0;
				_gd->gameState = play;
				_gd->world = intro;
				_gd->inGameState = exploration;
				_gd->enigmeState = none;
				_gd->cutSceneState = noCin;
				_gd->inDream = sfFalse;
				InitAnim(_gd);
				InitIntro(_gd);
			}
			break;

		case vaisseauOpenDoor:
			if (_gd->cinematique.currentAnim == 0 && _gd->cutScenesSounds.spaceShipDoor.isPlaying == sfFalse)
			{
				DeleteCutScene(_gd);
				_gd->cutScenesSounds.spaceShipDoor.isPlaying = sfTrue;
				sfSound_play(_gd->cutScenesSounds.spaceShipDoor.sound);
			}
			else if (_gd->cinematique.currentAnim == NB_CUTSCENE_SHIP_DOOR)
			{
				_gd->cinematique.currentTime = 0;
				_gd->cinematique.currentAnim = 0;
				_gd->cinematique.pos.z = 0.8;
				_gd->cinematique.opacity = 0;
				_gd->inGameState = exploration;
				_gd->enigmeState = none;
			}
			break;

		case vaisseauSleep:
			if (_gd->cinematique.currentAnim == 2 && _gd->bedInteract.isPlaying == sfFalse)
			{
				DeleteCutScene(_gd);
				_gd->bedInteract.isPlaying = sfTrue;
				sfSound_play(_gd->bedInteract.sound);
			}
			else if (_gd->cinematique.currentAnim == NB_CUTSCENE_SHIP_SLEEP)
			{
				_gd->cinematique.currentTime = 0;
				_gd->cinematique.currentAnim = 0;
				_gd->cinematique.pos.z = 0.8;
				_gd->cinematique.opacity = 0;
				_gd->cutSceneState = islandIntro;
				_gd->inGameState = cutscene;
				_gd->world = island;
				InitTimer(_gd);
				InitCutScene(_gd);
				InitSoundAmbience(_gd);
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void UpdateCutSceneIsland(GameData* _gd)
{
	int zoom = 0;
	switch (_gd->world)
	{
	case island:
		switch (_gd->cutSceneState)
		{
		case islandIntro:
			if (_gd->cinematique.currentAnim == 1 && _gd->cutScenesSounds.bed.isPlaying == sfFalse)
			{
				DeleteCutScene(_gd);
				_gd->cutScenesSounds.bed.isPlaying = sfTrue;
				sfSound_play(_gd->cutScenesSounds.bed.sound);
			}
			else if (_gd->cinematique.currentAnim == NB_CUTSCENE_ISLAND_INTRO)
			{
				_gd->cinematique.currentTime = 0;
				_gd->cinematique.currentAnim = 0;
				_gd->cinematique.pos.z = 0.8;
				_gd->cinematique.opacity = 0;
				_gd->gameState = play;
				_gd->world = island;
				_gd->inGameState = exploration;
				_gd->enigmeState = none;
				_gd->inDream = sfTrue;
				_gd->cutScenesSounds.bed.isPlaying = sfFalse;
				InitAnim(_gd);
				InitIsland(_gd);
			}
			break;

		case islandLeaveHouse:
			if (_gd->cinematique.currentTime == 0)
			{
				DeleteCutScene(_gd);
			}
			if (_gd->cinematique.exitHouse == sfFalse
				&& _gd->cinematique.currentAnim == NB_CUTSCENE_ISLAND_LEAVE_HOUSE)
			{
				_gd->cinematique.currentTime = 0;
				_gd->cinematique.currentAnim = 0;
				_gd->cinematique.pos.z = 0.8;
				_gd->cinematique.opacity = 0;
				_gd->inGameState = exploration;
				_gd->enigmeState = none;
				_gd->cinematique.exitHouse = sfTrue;
			}
			break;

		case islandPont:
			if (_gd->cinematique.currentTime == 0)
			{
				DeleteCutScene(_gd);
			}
			if (_gd->cinematique.currentAnim == 1 && _gd->cutScenesSounds.bridge.isPlaying == sfFalse)
			{
				_gd->cutScenesSounds.bridge.isPlaying = sfTrue;
				sfSound_play(_gd->cutScenesSounds.bridge.sound);
			}
			if (_gd->cinematique.currentAnim == 2 && _gd->cutScenesSounds.bridge.isPlaying == sfTrue)
			{
				_gd->cutScenesSounds.bridge.isPlaying = sfFalse;
				sfSound_play(_gd->sucessSound.sound);
			}
			else if (_gd->cinematique.currentAnim == NB_CUTSCENE_ISLAND_PONT)
			{
				_gd->cinematique.currentTime = 0;
				_gd->cinematique.currentAnim = 0;
				_gd->cinematique.pos.z = 0.8;
				_gd->cinematique.opacity = 0;
				_gd->inGameState = exploration;
				_gd->enigmeState = none;
			}
			break;

		case islandDialogue:
			if (_gd->cinematique.currentAnim == 0 && _gd->cutScenesSounds.islandDoor.isPlaying == sfFalse)
			{
				DeleteCutScene(_gd);
				_gd->cutScenesSounds.islandDoor.isPlaying = sfTrue;
				sfSound_play(_gd->cutScenesSounds.islandDoor.sound);
			}
			else if (_gd->cinematique.currentAnim == NB_CUTSCENE_ISLAND_DIALOGUE)
			{
				_gd->cinematique.currentTime = 0;
				_gd->cinematique.currentAnim = 0;
				_gd->cinematique.pos.z = 0.8;
				_gd->cinematique.opacity = 0;
				_gd->inGameState = exploration;
				_gd->enigmeState = none;
			}
			break;

		case islandEnd:
			if (_gd->cinematique.currentTime == 0)
			{
				DeleteCutScene(_gd);
			}
			if (_gd->cinematique.currentAnim == 1 && _gd->cutScenesSounds.boxTicket.isPlaying == sfFalse)
			{
				_gd->cutScenesSounds.boxTicket.isPlaying = sfTrue;
				sfSound_play(_gd->cutScenesSounds.boxTicket.sound);
			}
			else if (_gd->cinematique.currentAnim == NB_CUTSCENE_ISLAND_END)
			{
				_gd->cinematique.currentTime = 0;
				_gd->cinematique.currentAnim = 0;
				_gd->cinematique.pos.z = 0.8;
				_gd->cinematique.opacity = 0;
				_gd->cutSceneState = bedRoomIntro;
				_gd->inGameState = cutscene;
				_gd->world = bedroom;
				InitCutScene(_gd);
				InitSoundAmbience(_gd);
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void UpdateCutSceneBedRoom(GameData* _gd)
{
	int zoom = 0;
	switch (_gd->world)
	{
	case bedroom:
		switch (_gd->cutSceneState)
		{
		case bedRoomIntro:
			if (_gd->cinematique.currentAnim == 0 && _gd->cutScenesSounds.spaceShipConsole.isPlaying == sfFalse)
			{
				DeleteCutScene(_gd);
				_gd->cutScenesSounds.spaceShipConsole.isPlaying = sfTrue;
				sfSound_play(_gd->cutScenesSounds.spaceShipConsole.sound);
			}
			else if (_gd->cinematique.currentAnim == NB_CUTSCENE_BEDROOM_INTRO)
			{
				_gd->cinematique.currentTime = 0;
				_gd->cinematique.currentAnim = 0;
				_gd->cinematique.pos.z = 0.8;
				_gd->cinematique.opacity = 0;
				_gd->gameState = play;
				_gd->world = bedroom;
				_gd->inGameState = exploration;
				_gd->enigmeState = none;
				InitBedRoom(_gd);
				//a laisser après l'init de bedroom pour eviter une erreur
				_gd->inDream = sfFalse;
				InitAnim(_gd);
			}
			break;
		case bedRoomExit:
			if (_gd->cinematique.currentAnim == 0 && _gd->cutScenesSounds.bed.isPlaying == sfFalse)
			{
				DeleteCutScene(_gd);
				_gd->cutScenesSounds.bed.isPlaying = sfTrue;
				sfSound_play(_gd->cutScenesSounds.bed.sound);
			}
			else if (_gd->cinematique.currentAnim == NB_CUTSCENE_BEDROOM_EXIT)
			{
				_gd->cinematique.currentTime = 0;
				_gd->cinematique.currentAnim = 0;
				_gd->cinematique.pos.z = 0.8;
				_gd->cinematique.opacity = 0;
				_gd->world = jungle;
				_gd->inGameState = cutscene;
				_gd->cutSceneState = JungleReveil;
				_gd->enigmeState = none;
				InitCutScene(_gd);
				InitSoundAmbience(_gd);
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void UpdateCutSceneJungle(GameData* _gd)
{
	int zoom = 0;
	int opacity = 1;
	float time;
	switch (_gd->world)
	{
	case jungle:
		switch (_gd->cutSceneState)
		{
		case JungleReveil:
			if (_gd->cinematique.currentTime == 0)
			{
				//DeleteCutScene(_gd);
			}
			if (_gd->cinematique.currentAnim == NB_CUTSCENE_JUNGLE_REVEIL)
			{
				_gd->cinematique.currentTime = 0;
				_gd->cinematique.currentAnim = 0;
				_gd->cinematique.pos.z = 1;
				_gd->cinematique.opacity = 0;
				_gd->inGameState = exploration;
				_gd->world = jungle;
				_gd->inDream = sfTrue;
				InitAnim(_gd);
				InitJungle(_gd);
			}
			break;
		case JungleEnd:
			if (_gd->cinematique.currentTime == 0 && _gd->cutScenesSounds.endBed.isPlaying == sfFalse)
			{
				sfSound_stop(_gd->worldAmbience.sound);
				//DeleteCutScene(_gd);
				_gd->cutScenesSounds.endBed.isPlaying = sfTrue;
				sfSound_play(_gd->cutScenesSounds.endBed.sound);
			}
			if (_gd->cinematique.currentAnim == NB_CUTSCENE_JUNGLE_END)
			{
				_gd->cinematique.currentTime = 0;
				_gd->cinematique.currentAnim = 0;
				_gd->cinematique.pos.z = 1;
				_gd->cinematique.opacity = 0;
				_gd->cutSceneState = EndReveil;
				_gd->inGameState = cutscene;
				_gd->world = shipEnd;
				InitCutScene(_gd);
				_gd->inDream = sfFalse;
				InitAnim(_gd);
			}
			break;
		}
		break;
	}
}


void UpdateCutSceneShipEnd(GameData* _gd)
{
	int zoom = 0;
	int opacity = 1;
	float time;
	switch (_gd->world)
	{
	case shipEnd:
		switch (_gd->cutSceneState)
		{
		case EndReveil:
			if (_gd->cinematique.currentTime == 0 && sfSound_getStatus(_gd->worldAmbience.sound) == sfStopped)
			{
				DeleteCutScene(_gd);
				InitSoundAmbience(_gd);
			}
			if (_gd->cinematique.currentAnim == NB_CUTSCENE_END_REVEIL)
			{
				_gd->cinematique.currentTime = 0;
				_gd->cinematique.currentAnim = 0;
				_gd->cinematique.pos.z = 1;
				_gd->cinematique.opacity = 0;
				_gd->inGameState = exploration;
				_gd->enigmeState = none;
				InitShipEnd(_gd);

			}
			break;
		case EndCasque:
			if (_gd->cinematique.currentTime == 0 && _gd->cutScenesSounds.endShip.isPlaying == sfFalse)
			{
				sfSound_stop(_gd->worldAmbience.sound);
				DeleteCutScene(_gd);
				_gd->cutScenesSounds.endShip.isPlaying = sfTrue;
				sfSound_play(_gd->cutScenesSounds.endShip.sound);
			}
			if (_gd->cinematique.currentAnim == NB_CUTSCENE_END_CASQUE)
			{
				_gd->cinematique.currentTime = 0;
				_gd->cinematique.currentAnim = 0;
				_gd->cinematique.pos.z = 1;
				_gd->cinematique.opacity = 0;
				_gd->cutSceneState = EndEnd;
				_gd->inGameState = cutscene;
				_gd->world = shipEnd;
				InitCutScene(_gd);
			}
			break;
		case EndEnd:
			if (_gd->cinematique.currentTime == 0)
			{
				DeleteCutScene(_gd);
			}
			if (_gd->cinematique.currentAnim == 4 && sfSound_getStatus(_gd->menuMusic.sound) == sfStopped)
			{

				sfSound_play(_gd->menuMusic.sound);
			}
			if (_gd->cinematique.currentAnim == NB_CUTSCENE_END_END)
			{
				_gd->cinematique.currentTime = 0;
				_gd->cinematique.currentAnim = 0;
				_gd->cinematique.pos.z = 1;
				_gd->cinematique.opacity = 0;
				_gd->inGameState = exploration;
				_gd->enigmeState = none;
				_gd->gameState = menu; //menu pour menu 
				_gd->world = begin; // begin pour menu
				_gd->inGameState = load; // load pour menu
				_gd->enigmeState = none; // none quand pas d'enigme
				_gd->enigmeBox = none; // none de base, pour box d'island
				_gd->cutSceneState = noCin; // none de base, pour cinématique
				_gd->enigme.dialogue.state = NONE;
				_gd->worldAmbience.isPlaying = sfFalse;
				DestroySoundShipEnd(_gd);
				InitMenu(_gd);
			}
			break;
		}
		break;
	}
}

void UpdateCutSceneFail(GameData* _gd)
{
	switch (_gd->cutSceneState)
	{
	case fail:
		if (_gd->cinematique.currentTime == 0)
		{
			DeleteCutScene(_gd);
			InitSoundAmbience(_gd);
		}
		if (_gd->cinematique.currentAnim == NB_CUTSCENE_FAIL)
		{
			_gd->cinematique.currentTime = 0;
			_gd->cinematique.currentAnim = 0;
			_gd->cinematique.pos.z = 0.8;
			_gd->cinematique.opacity = 0;
			_gd->gameState = play;
			_gd->inGameState = exploration;
			_gd->enigmeState = none;
			_gd->cutSceneState = noCin;
			_gd->inDream = sfFalse;

			if (_gd->world == intro)
			{
				ReInitIntro(_gd);
			}
			else if (_gd->world == bedroom)
			{
				ReInitBedRoom(_gd);
			}
		}
		break;
	default:
		break;
	}
}