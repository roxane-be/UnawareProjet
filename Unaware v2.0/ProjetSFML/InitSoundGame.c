#include "InitSoundGame.h"

void InitSoundCutScenes(GameData* _gd)
{
	_gd->cutScenesSounds.spaceShipDoor.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Cinematique/Spaceship_door.wav");
	_gd->cutScenesSounds.spaceShipDoor.sound = sfSound_create();
	_gd->cutScenesSounds.spaceShipDoor.volume = _gd->soundGlobal * _gd->soundAmbiance;
	_gd->cutScenesSounds.spaceShipDoor.loop = 1;
	_gd->cutScenesSounds.spaceShipDoor.isPlaying = sfFalse;
	sfSound_setBuffer(_gd->cutScenesSounds.spaceShipDoor.sound, _gd->cutScenesSounds.spaceShipDoor.buffer);
	sfSound_setVolume(_gd->cutScenesSounds.spaceShipDoor.sound, _gd->cutScenesSounds.spaceShipDoor.volume);

	_gd->cutScenesSounds.bed.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Cinematique/Bed.wav");
	_gd->cutScenesSounds.bed.sound = sfSound_create();
	_gd->cutScenesSounds.bed.volume = _gd->soundGlobal * _gd->soundAmbiance;
	_gd->cutScenesSounds.bed.loop = 1;
	_gd->cutScenesSounds.bed.isPlaying = sfFalse;
	sfSound_setBuffer(_gd->cutScenesSounds.bed.sound, _gd->cutScenesSounds.bed.buffer);
	sfSound_setVolume(_gd->cutScenesSounds.bed.sound, _gd->cutScenesSounds.bed.volume);

	_gd->cutScenesSounds.bridge.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Cinematique/Bridge.wav");
	_gd->cutScenesSounds.bridge.sound = sfSound_create();
	_gd->cutScenesSounds.bridge.volume = _gd->soundGlobal * _gd->soundAmbiance;
	_gd->cutScenesSounds.bridge.loop = 1;
	_gd->cutScenesSounds.bridge.isPlaying = sfFalse;
	sfSound_setBuffer(_gd->cutScenesSounds.bridge.sound, _gd->cutScenesSounds.bridge.buffer);
	sfSound_setVolume(_gd->cutScenesSounds.bridge.sound, _gd->cutScenesSounds.bridge.volume);

	_gd->cutScenesSounds.islandDoor.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Cinematique/Door_opening.wav");
	_gd->cutScenesSounds.islandDoor.sound = sfSound_create();
	_gd->cutScenesSounds.islandDoor.volume = _gd->soundGlobal * _gd->soundAmbiance;
	_gd->cutScenesSounds.islandDoor.loop = 1;
	_gd->cutScenesSounds.islandDoor.isPlaying = sfFalse;
	sfSound_setBuffer(_gd->cutScenesSounds.islandDoor.sound, _gd->cutScenesSounds.islandDoor.buffer);
	sfSound_setVolume(_gd->cutScenesSounds.islandDoor.sound, _gd->cutScenesSounds.islandDoor.volume);

	_gd->cutScenesSounds.boxTicket.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Cinematique/Ticket.wav");
	_gd->cutScenesSounds.boxTicket.sound = sfSound_create();
	_gd->cutScenesSounds.boxTicket.volume = _gd->soundGlobal * _gd->soundAmbiance;
	_gd->cutScenesSounds.boxTicket.loop = 1;
	_gd->cutScenesSounds.boxTicket.isPlaying = sfFalse;
	sfSound_setBuffer(_gd->cutScenesSounds.boxTicket.sound, _gd->cutScenesSounds.boxTicket.buffer);
	sfSound_setVolume(_gd->cutScenesSounds.boxTicket.sound, _gd->cutScenesSounds.boxTicket.volume);

	_gd->cutScenesSounds.spaceShipConsole.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Cinematique/Console.wav");
	_gd->cutScenesSounds.spaceShipConsole.sound = sfSound_create();
	_gd->cutScenesSounds.spaceShipConsole.volume = _gd->soundGlobal * _gd->soundAmbiance;
	_gd->cutScenesSounds.spaceShipConsole.loop = 1;
	_gd->cutScenesSounds.spaceShipConsole.isPlaying = sfFalse;
	sfSound_setBuffer(_gd->cutScenesSounds.spaceShipConsole.sound, _gd->cutScenesSounds.spaceShipConsole.buffer);
	sfSound_setVolume(_gd->cutScenesSounds.spaceShipConsole.sound, _gd->cutScenesSounds.spaceShipConsole.volume);

	_gd->cutScenesSounds.endBed.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Cinematique/Alert.wav");
	_gd->cutScenesSounds.endBed.sound = sfSound_create();
	_gd->cutScenesSounds.endBed.volume = _gd->soundGlobal * _gd->soundAmbiance;
	_gd->cutScenesSounds.endBed.loop = 1;
	_gd->cutScenesSounds.endBed.isPlaying = sfFalse;
	sfSound_setBuffer(_gd->cutScenesSounds.endBed.sound, _gd->cutScenesSounds.endBed.buffer);
	sfSound_setVolume(_gd->cutScenesSounds.endBed.sound, _gd->cutScenesSounds.endBed.volume);

	_gd->cutScenesSounds.endShip.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Cinematique/End.wav");
	_gd->cutScenesSounds.endShip.sound = sfSound_create();
	_gd->cutScenesSounds.endShip.volume = _gd->soundGlobal * _gd->soundAmbiance;
	_gd->cutScenesSounds.endShip.loop = 1;
	_gd->cutScenesSounds.endShip.isPlaying = sfFalse;
	sfSound_setBuffer(_gd->cutScenesSounds.endShip.sound, _gd->cutScenesSounds.endShip.buffer);
	sfSound_setVolume(_gd->cutScenesSounds.endShip.sound, _gd->cutScenesSounds.endShip.volume);
}

void InitSoundAmbience(GameData* _gd)
{
	switch (_gd->world)
	{
	case intro:
		//Stop de la musique du menu
		sfSound_stop(_gd->menuMusic.sound);
		if (_gd->failDream == sfTrue)
		{
			sfSound_stop(_gd->worldAmbience.sound);
		}
		_gd->worldAmbience.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Ambiance/Ambience1.wav");
		_gd->worldAmbience.sound = sfSound_create();
		_gd->worldAmbience.volume = _gd->soundGlobal * _gd->soundMusic;
		_gd->worldAmbience.loop = 1;
		_gd->worldAmbience.isPlaying = sfTrue;
		sfSound_setBuffer(_gd->worldAmbience.sound, _gd->worldAmbience.buffer);
		sfSound_setVolume(_gd->worldAmbience.sound, _gd->worldAmbience.volume);
		sfSound_setLoop(_gd->worldAmbience.sound, _gd->worldAmbience.loop);
		sfSound_play(_gd->worldAmbience.sound);
		//IA
		_gd->aiSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/BrokenAI.wav");
		_gd->aiSound.sound = sfSound_create();
		_gd->aiSound.volume = _gd->soundGlobal * _gd->soundAmbiance;
		_gd->aiSound.isPlaying = sfFalse;
		sfSound_setBuffer(_gd->aiSound.sound, _gd->aiSound.buffer);
		sfSound_setVolume(_gd->aiSound.sound, _gd->aiSound.volume);

		break;
	case island:
		sfSound_stop(_gd->worldAmbience.sound);
		_gd->worldAmbience.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Ambiance/World1AmbienceInside.wav");
		_gd->worldAmbience.isPlaying = sfTrue;
		sfSound_setBuffer(_gd->worldAmbience.sound, _gd->worldAmbience.buffer);
		sfSound_play(_gd->worldAmbience.sound);
		break;
	case bedroom:
		sfSound_stop(_gd->worldAmbience.sound);
		//Ambience
		_gd->worldAmbience.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Ambiance/Ambience1.wav");
		_gd->worldAmbience.isPlaying = sfTrue;
		sfSound_setBuffer(_gd->worldAmbience.sound, _gd->worldAmbience.buffer);
		sfSound_play(_gd->worldAmbience.sound);
		//IA
		_gd->aiSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/AI.wav");
		_gd->aiSound.isPlaying = sfFalse;
		sfSound_setBuffer(_gd->aiSound.sound, _gd->aiSound.buffer);

		break;
	case jungle:
		sfSound_stop(_gd->worldAmbience.sound);
		_gd->worldAmbience.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Ambiance/World2Ambience.wav");
		_gd->worldAmbience.isPlaying = sfTrue;
		sfSound_setBuffer(_gd->worldAmbience.sound, _gd->worldAmbience.buffer);
		sfSound_play(_gd->worldAmbience.sound);
		break;
	case shipEnd:
		sfSound_stop(_gd->worldAmbience.sound);
		_gd->worldAmbience.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Ambiance/Ambience1.wav");
		_gd->worldAmbience.isPlaying = sfTrue;
		sfSound_setBuffer(_gd->worldAmbience.sound, _gd->worldAmbience.buffer);
		sfSound_play(_gd->worldAmbience.sound);
		//IA
		_gd->aiSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/AI.wav");
		_gd->aiSound.isPlaying = sfFalse;
		sfSound_setBuffer(_gd->aiSound.sound, _gd->aiSound.buffer);
		break;
	default:
		break;
	}
}

void InitSoundIntro(GameData* _gd)
{
	strcpy(_gd->player.stepName, "Metal");

	//Init des sons de l'intro
	_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Pas/MetalSteps.wav");
	_gd->player.stepSound.sound = sfSound_create();
	_gd->player.stepSound.volume = _gd->soundGlobal * _gd->soundAmbiance;
	_gd->player.stepSound.loop = 1;
	_gd->player.stepSound.isPlaying = sfFalse;
	sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
	sfSound_setVolume(_gd->player.stepSound.sound, _gd->player.stepSound.volume);
	sfSound_setLoop(_gd->player.stepSound.sound, _gd->player.stepSound.loop);

	_gd->enigme.doorDigicode.arrowSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Boutons/Selection/Select1.wav");
	_gd->enigme.doorDigicode.arrowSound.sound = sfSound_create();
	_gd->enigme.doorDigicode.arrowSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.doorDigicode.arrowSound.sound, _gd->enigme.doorDigicode.arrowSound.buffer);
	sfSound_setVolume(_gd->enigme.doorDigicode.arrowSound.sound, _gd->enigme.doorDigicode.arrowSound.volume);

	_gd->enigme.doorDigicode.validSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Boutons/Validation/Valid2.wav");
	_gd->enigme.doorDigicode.validSound.sound = sfSound_create();
	_gd->enigme.doorDigicode.validSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.doorDigicode.validSound.sound, _gd->enigme.doorDigicode.validSound.buffer);
	sfSound_setVolume(_gd->enigme.doorDigicode.validSound.sound, _gd->enigme.doorDigicode.validSound.volume);

	_gd->enigme.doorDigicode.errorSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Boutons/Erreur/Error1.wav");
	_gd->enigme.doorDigicode.errorSound.sound = sfSound_create();
	_gd->enigme.doorDigicode.errorSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.doorDigicode.errorSound.sound, _gd->enigme.doorDigicode.errorSound.buffer);
	sfSound_setVolume(_gd->enigme.doorDigicode.errorSound.sound, _gd->enigme.doorDigicode.errorSound.volume);

	_gd->enigme.doorDigicode.interactSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Boutons/Mastermind.wav");
	_gd->enigme.doorDigicode.interactSound.sound = sfSound_create();
	_gd->enigme.doorDigicode.interactSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.doorDigicode.interactSound.sound, _gd->enigme.doorDigicode.interactSound.buffer);
	sfSound_setVolume(_gd->enigme.doorDigicode.interactSound.sound, _gd->enigme.doorDigicode.interactSound.volume);

	_gd->helpSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Boutons/PaperHint.wav");
	_gd->helpSound.sound = sfSound_create();
	_gd->helpSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->helpSound.sound, _gd->helpSound.buffer);
	sfSound_setVolume(_gd->helpSound.sound, _gd->helpSound.volume);

	_gd->bedInteract.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Lit.wav");
	_gd->bedInteract.sound = sfSound_create();
	_gd->bedInteract.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->bedInteract.sound, _gd->bedInteract.buffer);
	sfSound_setVolume(_gd->bedInteract.sound, _gd->bedInteract.volume);

	_gd->mapIntro->introPointSound.electricity[0].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Electricity.wav");
	_gd->mapIntro->introPointSound.electricity[0].sound = sfSound_create();
	_gd->mapIntro->introPointSound.electricity[1].sound = sfSound_create();
	_gd->mapIntro->introPointSound.electricity[0].loop = 1;
	_gd->mapIntro->introPointSound.electricity[0].isPlaying = sfFalse;
	_gd->mapIntro->introPointSound.electricity[1].isPlaying = sfFalse;
	sfSound_setBuffer(_gd->mapIntro->introPointSound.electricity[0].sound, _gd->mapIntro->introPointSound.electricity[0].buffer);
	sfSound_setBuffer(_gd->mapIntro->introPointSound.electricity[1].sound, _gd->mapIntro->introPointSound.electricity[0].buffer);
	sfSound_setLoop(_gd->mapIntro->introPointSound.electricity[0].sound, _gd->mapIntro->introPointSound.electricity[0].loop);
	sfSound_setLoop(_gd->mapIntro->introPointSound.electricity[1].sound, _gd->mapIntro->introPointSound.electricity[0].loop);
	sfSound_setVolume(_gd->mapIntro->introPointSound.electricity[0].sound, 0);
	sfSound_setVolume(_gd->mapIntro->introPointSound.electricity[1].sound, 0);

	_gd->mapIntro->introPointSound.cat[0].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Cat.wav");
	_gd->mapIntro->introPointSound.cat[0].sound = sfSound_create();
	_gd->mapIntro->introPointSound.cat[0].loop = 1;
	_gd->mapIntro->introPointSound.cat[0].isPlaying = sfFalse;
	sfSound_setBuffer(_gd->mapIntro->introPointSound.cat[0].sound, _gd->mapIntro->introPointSound.cat[0].buffer);
	sfSound_setLoop(_gd->mapIntro->introPointSound.cat[0].sound, _gd->mapIntro->introPointSound.cat[0].loop);
	sfSound_setVolume(_gd->mapIntro->introPointSound.cat[0].sound, 0);

	_gd->mapIntro->introPointSound.ventilation[0].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Ventillation.wav");
	_gd->mapIntro->introPointSound.ventilation[0].sound = sfSound_create();
	_gd->mapIntro->introPointSound.ventilation[1].sound = sfSound_create();
	_gd->mapIntro->introPointSound.ventilation[0].loop = 1;
	_gd->mapIntro->introPointSound.ventilation[0].isPlaying = sfFalse;
	_gd->mapIntro->introPointSound.ventilation[1].isPlaying = sfFalse;
	sfSound_setBuffer(_gd->mapIntro->introPointSound.ventilation[0].sound, _gd->mapIntro->introPointSound.ventilation[0].buffer);
	sfSound_setBuffer(_gd->mapIntro->introPointSound.ventilation[1].sound, _gd->mapIntro->introPointSound.ventilation[0].buffer);
	sfSound_setLoop(_gd->mapIntro->introPointSound.ventilation[0].sound, _gd->mapIntro->introPointSound.ventilation[0].loop);
	sfSound_setLoop(_gd->mapIntro->introPointSound.ventilation[1].sound, _gd->mapIntro->introPointSound.ventilation[0].loop);
	sfSound_setVolume(_gd->mapIntro->introPointSound.ventilation[0].sound, 0);
	sfSound_setVolume(_gd->mapIntro->introPointSound.ventilation[1].sound, 0);

	_gd->mapIntro->introPointSound.console[0].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Console.wav");
	_gd->mapIntro->introPointSound.console[0].sound = sfSound_create();
	_gd->mapIntro->introPointSound.console[0].loop = 1;
	_gd->mapIntro->introPointSound.console[0].isPlaying = sfTrue;
	sfSound_setBuffer(_gd->mapIntro->introPointSound.console[0].sound, _gd->mapIntro->introPointSound.console[0].buffer);
	sfSound_setLoop(_gd->mapIntro->introPointSound.console[0].sound, _gd->mapIntro->introPointSound.console[0].loop);
	sfSound_setVolume(_gd->mapIntro->introPointSound.console[0].sound, 0);
	sfSound_play(_gd->mapIntro->introPointSound.console[0].sound);


}

void DestroySoundIntro(GameData* _gd)
{
	/*sfSound_destroy(_gd->enigme.doorDigicode.arrowSound.sound);
	sfSound_destroy(_gd->enigme.doorDigicode.validSound.sound);
	sfSound_destroy(_gd->enigme.doorDigicode.errorSound.sound);*/
	sfSound_destroy(_gd->enigme.doorDigicode.interactSound.sound);
	sfSound_destroy(_gd->mapIntro->introPointSound.electricity[0].sound);
	sfSound_destroy(_gd->mapIntro->introPointSound.electricity[1].sound);
	sfSound_destroy(_gd->mapIntro->introPointSound.ventilation[0].sound);
	sfSound_destroy(_gd->mapIntro->introPointSound.ventilation[1].sound);
	sfSound_destroy(_gd->mapIntro->introPointSound.cat[0].sound);
	sfSound_destroy(_gd->mapIntro->introPointSound.console[0].sound);
}

void InitSoundWorld1(GameData* _gd)
{
	strcpy(_gd->player.stepName, "Grass");

	//Init des sons du monde 1
	_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Pas/GrassSteps.wav");
	_gd->player.stepSound.isPlaying = sfFalse;
	sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);

	//outside/inside
	_gd->worldAmbienceOutside.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Ambiance/World1Ambience.wav");
	_gd->worldAmbienceOutside.sound = sfSound_create();
	_gd->worldAmbienceOutside.volume = _gd->soundGlobal * _gd->soundMusic;
	sfSound_setBuffer(_gd->worldAmbienceOutside.sound, _gd->worldAmbienceOutside.buffer);
	sfSound_setVolume(_gd->worldAmbienceOutside.sound, _gd->worldAmbienceOutside.volume);
	sfSound_setLoop(_gd->worldAmbienceOutside.sound, 1);

	_gd->errorSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Wrong.wav");
	_gd->errorSound.sound = sfSound_create();
	_gd->errorSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->errorSound.sound, _gd->errorSound.buffer);
	sfSound_setVolume(_gd->errorSound.sound, _gd->errorSound.volume);

	_gd->sucessSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Sucess.wav");
	_gd->sucessSound.sound = sfSound_create();
	_gd->sucessSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->sucessSound.sound, _gd->sucessSound.buffer);
	sfSound_setVolume(_gd->sucessSound.sound, _gd->sucessSound.volume);

	_gd->bushSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Bush.wav");
	_gd->bushSound.isPlaying = sfFalse;
	_gd->bushSound.sound = sfSound_create();
	_gd->bushSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->bushSound.sound, _gd->bushSound.buffer);
	sfSound_setVolume(_gd->bushSound.sound, _gd->bushSound.volume);

	//puzzle

	_gd->enigme.utilityPuzzle.woodPickUpSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Puzzle/PickUpWood.wav");
	_gd->enigme.utilityPuzzle.woodPickUpSound.sound = sfSound_create();
	_gd->enigme.utilityPuzzle.woodPickUpSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.utilityPuzzle.woodPickUpSound.sound, _gd->enigme.utilityPuzzle.woodPickUpSound.buffer);
	sfSound_setVolume(_gd->enigme.utilityPuzzle.woodPickUpSound.sound, _gd->enigme.utilityPuzzle.woodPickUpSound.volume);

	_gd->enigme.utilityPuzzle.placePuzzleSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Puzzle/PlacePuzzle.wav");
	_gd->enigme.utilityPuzzle.placePuzzleSound.sound = sfSound_create();
	_gd->enigme.utilityPuzzle.placePuzzleSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.utilityPuzzle.placePuzzleSound.sound, _gd->enigme.utilityPuzzle.placePuzzleSound.buffer);
	sfSound_setVolume(_gd->enigme.utilityPuzzle.placePuzzleSound.sound, _gd->enigme.utilityPuzzle.placePuzzleSound.volume);

	_gd->enigme.utilityPuzzle.resetPuzzleSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Puzzle/ResetPuzzle.wav");
	_gd->enigme.utilityPuzzle.resetPuzzleSound.sound = sfSound_create();
	_gd->enigme.utilityPuzzle.resetPuzzleSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.utilityPuzzle.resetPuzzleSound.sound, _gd->enigme.utilityPuzzle.resetPuzzleSound.buffer);
	sfSound_setVolume(_gd->enigme.utilityPuzzle.resetPuzzleSound.sound, _gd->enigme.utilityPuzzle.resetPuzzleSound.volume);

	//dialogues

	_gd->enigme.dialogue.letterSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Dialogue/Letter.wav");
	_gd->enigme.dialogue.letterSound.sound = sfSound_create();
	_gd->enigme.dialogue.letterSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	_gd->enigme.dialogue.letterSound.isPlaying = sfFalse;
	sfSound_setBuffer(_gd->enigme.dialogue.letterSound.sound, _gd->enigme.dialogue.letterSound.buffer);
	sfSound_setVolume(_gd->enigme.dialogue.letterSound.sound, _gd->enigme.dialogue.letterSound.volume);
	sfSound_setLoop(_gd->enigme.dialogue.letterSound.sound, 0);

	_gd->enigme.dialogue.writeSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Dialogue/TypeLetter.wav");
	_gd->enigme.dialogue.writeSound.sound = sfSound_create();
	_gd->enigme.dialogue.writeSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.dialogue.writeSound.sound, _gd->enigme.dialogue.writeSound.buffer);
	sfSound_setVolume(_gd->enigme.dialogue.writeSound.sound, _gd->enigme.dialogue.writeSound.volume);

	_gd->npc[0].voice.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/PNJ/Moo.wav");
	_gd->npc[0].voice.sound = sfSound_create();
	_gd->npc[0].voice.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->npc[0].voice.sound, _gd->npc[0].voice.buffer);
	sfSound_setVolume(_gd->npc[0].voice.sound, _gd->npc[0].voice.volume);

	_gd->npc[1].voice.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/PNJ/huh.wav");
	_gd->npc[1].voice.sound = sfSound_create();
	_gd->npc[1].voice.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->npc[1].voice.sound, _gd->npc[1].voice.buffer);
	sfSound_setVolume(_gd->npc[1].voice.sound, _gd->npc[1].voice.volume);

	_gd->npc[2].voice.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/PNJ/heh.wav");
	_gd->npc[2].voice.sound = sfSound_create();
	_gd->npc[2].voice.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->npc[2].voice.sound, _gd->npc[2].voice.buffer);
	sfSound_setVolume(_gd->npc[2].voice.sound, _gd->npc[2].voice.volume);

	_gd->npc[3].voice.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/PNJ/hey.wav");
	_gd->npc[3].voice.sound = sfSound_create();
	_gd->npc[3].voice.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->npc[3].voice.sound, _gd->npc[3].voice.buffer);
	sfSound_setVolume(_gd->npc[3].voice.sound, _gd->npc[3].voice.volume);

	_gd->npc[4].voice.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/PNJ/Hello.wav");
	_gd->npc[4].voice.sound = sfSound_create();
	_gd->npc[4].voice.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->npc[4].voice.sound, _gd->npc[4].voice.buffer);
	sfSound_setVolume(_gd->npc[4].voice.sound, _gd->npc[4].voice.volume);

	//Box sound

	_gd->enigme.doorDigicode.errorSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Box/MetalError.wav");
	sfSound_setBuffer(_gd->enigme.doorDigicode.errorSound.sound, _gd->enigme.doorDigicode.errorSound.buffer);

	_gd->enigme.doorDigicode.validSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Box/TrapOpen.wav");
	sfSound_setBuffer(_gd->enigme.doorDigicode.validSound.sound, _gd->enigme.doorDigicode.validSound.buffer);

	_gd->boxSwishSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Box/Swish.wav");
	_gd->boxSwishSound.sound = sfSound_create();
	_gd->boxSwishSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->boxSwishSound.sound, _gd->boxSwishSound.buffer);
	sfSound_setVolume(_gd->boxSwishSound.sound, _gd->boxSwishSound.volume);

	_gd->utilityPieceBoite.pickUpCoinSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Box/CoinPickUp.wav");
	_gd->utilityPieceBoite.pickUpCoinSound.sound = sfSound_create();
	_gd->utilityPieceBoite.pickUpCoinSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->utilityPieceBoite.pickUpCoinSound.sound, _gd->utilityPieceBoite.pickUpCoinSound.buffer);
	sfSound_setVolume(_gd->utilityPieceBoite.pickUpCoinSound.sound, _gd->utilityPieceBoite.pickUpCoinSound.volume);

	_gd->utilityPieceBoite.unscrewSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Box/Unscrew.wav");
	_gd->utilityPieceBoite.unscrewSound.sound = sfSound_create();
	_gd->utilityPieceBoite.unscrewSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->utilityPieceBoite.unscrewSound.sound, _gd->utilityPieceBoite.unscrewSound.buffer);
	sfSound_setVolume(_gd->utilityPieceBoite.unscrewSound.sound, _gd->utilityPieceBoite.unscrewSound.volume);

	_gd->utilityPieceBoite.plateSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Box/Compartment.wav");
	_gd->utilityPieceBoite.plateSound.sound = sfSound_create();
	_gd->utilityPieceBoite.plateSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->utilityPieceBoite.plateSound.sound, _gd->utilityPieceBoite.plateSound.buffer);
	sfSound_setVolume(_gd->utilityPieceBoite.plateSound.sound, _gd->utilityPieceBoite.plateSound.volume);

	_gd->utilityPieceBoite.wirePickUpSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Box/WirePickUp.wav");
	_gd->utilityPieceBoite.wirePickUpSound.sound = sfSound_create();
	_gd->utilityPieceBoite.wirePickUpSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->utilityPieceBoite.wirePickUpSound.sound, _gd->utilityPieceBoite.wirePickUpSound.buffer);
	sfSound_setVolume(_gd->utilityPieceBoite.wirePickUpSound.sound, _gd->utilityPieceBoite.wirePickUpSound.volume);

	_gd->utilityCable.wiresSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Box/Wires.wav");
	_gd->utilityCable.wiresSound.sound = sfSound_create();
	_gd->utilityCable.wiresSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->utilityCable.wiresSound.sound, _gd->utilityCable.wiresSound.buffer);
	sfSound_setVolume(_gd->utilityCable.wiresSound.sound, _gd->utilityCable.wiresSound.volume);

	_gd->utilityCable.powerOnSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Box/PowerOn.wav");
	_gd->utilityCable.powerOnSound.sound = sfSound_create();
	_gd->utilityCable.powerOnSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->utilityCable.powerOnSound.sound, _gd->utilityCable.powerOnSound.buffer);
	sfSound_setVolume(_gd->utilityCable.powerOnSound.sound, _gd->utilityCable.powerOnSound.volume);

	_gd->utilityCable.switchOnOff.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Box/ButtonSwitched.wav");
	_gd->utilityCable.switchOnOff.sound = sfSound_create();
	_gd->utilityCable.switchOnOff.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->utilityCable.switchOnOff.sound, _gd->utilityCable.switchOnOff.buffer);
	sfSound_setVolume(_gd->utilityCable.switchOnOff.sound, _gd->utilityCable.switchOnOff.volume);

	_gd->enigme.voltage.switchSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Box/Switch.wav");
	_gd->enigme.voltage.switchSound.sound = sfSound_create();
	_gd->enigme.voltage.switchSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.voltage.switchSound.sound, _gd->enigme.voltage.switchSound.buffer);
	sfSound_setVolume(_gd->enigme.voltage.switchSound.sound, _gd->enigme.voltage.switchSound.volume);

	_gd->enigme.voltage.deniedSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Box/Denied.wav");
	_gd->enigme.voltage.deniedSound.sound = sfSound_create();
	_gd->enigme.voltage.deniedSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.voltage.deniedSound.sound, _gd->enigme.voltage.deniedSound.buffer);
	sfSound_setVolume(_gd->enigme.voltage.deniedSound.sound, _gd->enigme.voltage.deniedSound.volume);

	//PointSound

	_gd->mapIsland->islandPointSound.waterfall[0].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Ambiance/Waterfall.wav");
	_gd->mapIsland->islandPointSound.waterfall[0].sound = sfSound_create();
	_gd->mapIsland->islandPointSound.waterfall[1].sound = sfSound_create();
	_gd->mapIsland->islandPointSound.waterfall[2].sound = sfSound_create();
	_gd->mapIsland->islandPointSound.waterfall[3].sound = sfSound_create();
	_gd->mapIsland->islandPointSound.waterfall[0].loop = 1;
	_gd->mapIsland->islandPointSound.waterfall[0].isPlaying = sfFalse;
	_gd->mapIsland->islandPointSound.waterfall[1].isPlaying = sfFalse;
	_gd->mapIsland->islandPointSound.waterfall[2].isPlaying = sfFalse;
	_gd->mapIsland->islandPointSound.waterfall[3].isPlaying = sfFalse;
	sfSound_setBuffer(_gd->mapIsland->islandPointSound.waterfall[0].sound, _gd->mapIsland->islandPointSound.waterfall[0].buffer);
	sfSound_setBuffer(_gd->mapIsland->islandPointSound.waterfall[1].sound, _gd->mapIsland->islandPointSound.waterfall[0].buffer);
	sfSound_setBuffer(_gd->mapIsland->islandPointSound.waterfall[2].sound, _gd->mapIsland->islandPointSound.waterfall[0].buffer);
	sfSound_setBuffer(_gd->mapIsland->islandPointSound.waterfall[3].sound, _gd->mapIsland->islandPointSound.waterfall[0].buffer);
	sfSound_setLoop(_gd->mapIsland->islandPointSound.waterfall[0].sound, _gd->mapIsland->islandPointSound.waterfall[0].loop);
	sfSound_setLoop(_gd->mapIsland->islandPointSound.waterfall[1].sound, _gd->mapIsland->islandPointSound.waterfall[0].loop);
	sfSound_setLoop(_gd->mapIsland->islandPointSound.waterfall[2].sound, _gd->mapIsland->islandPointSound.waterfall[0].loop);
	sfSound_setLoop(_gd->mapIsland->islandPointSound.waterfall[3].sound, _gd->mapIsland->islandPointSound.waterfall[0].loop);
	sfSound_setVolume(_gd->mapIsland->islandPointSound.waterfall[0].sound, 0);
	sfSound_setVolume(_gd->mapIsland->islandPointSound.waterfall[1].sound, 0);
	sfSound_setVolume(_gd->mapIsland->islandPointSound.waterfall[2].sound, 0);
	sfSound_setVolume(_gd->mapIsland->islandPointSound.waterfall[3].sound, 0);

	_gd->mapIsland->islandPointSound.well[0].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Ambiance/Well.wav");
	_gd->mapIsland->islandPointSound.well[0].sound = sfSound_create();
	_gd->mapIsland->islandPointSound.well[1].sound = sfSound_create();
	_gd->mapIsland->islandPointSound.well[2].sound = sfSound_create();
	_gd->mapIsland->islandPointSound.well[0].loop = 0;
	_gd->mapIsland->islandPointSound.well[0].isPlaying = sfFalse;
	_gd->mapIsland->islandPointSound.well[1].isPlaying = sfFalse;
	_gd->mapIsland->islandPointSound.well[2].isPlaying = sfFalse;
	sfSound_setBuffer(_gd->mapIsland->islandPointSound.well[0].sound, _gd->mapIsland->islandPointSound.well[0].buffer);
	sfSound_setBuffer(_gd->mapIsland->islandPointSound.well[1].sound, _gd->mapIsland->islandPointSound.well[0].buffer);
	sfSound_setBuffer(_gd->mapIsland->islandPointSound.well[2].sound, _gd->mapIsland->islandPointSound.well[0].buffer);
	sfSound_setLoop(_gd->mapIsland->islandPointSound.well[0].sound, _gd->mapIsland->islandPointSound.well[0].loop);
	sfSound_setLoop(_gd->mapIsland->islandPointSound.well[1].sound, _gd->mapIsland->islandPointSound.well[0].loop);
	sfSound_setLoop(_gd->mapIsland->islandPointSound.well[2].sound, _gd->mapIsland->islandPointSound.well[0].loop);
	sfSound_setVolume(_gd->mapIsland->islandPointSound.well[0].sound, 0);
	sfSound_setVolume(_gd->mapIsland->islandPointSound.well[1].sound, 0);
	sfSound_setVolume(_gd->mapIsland->islandPointSound.well[2].sound, 0);

	_gd->mapIsland->islandPointSound.fire[0].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Ambiance/Fire.wav");
	_gd->mapIsland->islandPointSound.fire[0].sound = sfSound_create();
	_gd->mapIsland->islandPointSound.fire[0].loop = 1;
	_gd->mapIsland->islandPointSound.fire[0].isPlaying = sfFalse;
	sfSound_setBuffer(_gd->mapIsland->islandPointSound.fire[0].sound, _gd->mapIsland->islandPointSound.fire[0].buffer);
	sfSound_setLoop(_gd->mapIsland->islandPointSound.fire[0].sound, _gd->mapIsland->islandPointSound.fire[0].loop);
	sfSound_setVolume(_gd->mapIsland->islandPointSound.fire[0].sound, 0);

	_gd->mapIsland->islandPointSound.lake[0].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Ambiance/Lake.wav");
	_gd->mapIsland->islandPointSound.lake[0].sound = sfSound_create();
	_gd->mapIsland->islandPointSound.lake[1].sound = sfSound_create();
	_gd->mapIsland->islandPointSound.lake[2].sound = sfSound_create();
	_gd->mapIsland->islandPointSound.lake[0].loop = 1;
	_gd->mapIsland->islandPointSound.lake[0].isPlaying = sfFalse;
	_gd->mapIsland->islandPointSound.lake[1].isPlaying = sfFalse;
	_gd->mapIsland->islandPointSound.lake[2].isPlaying = sfFalse;
	sfSound_setBuffer(_gd->mapIsland->islandPointSound.lake[0].sound, _gd->mapIsland->islandPointSound.lake[0].buffer);
	sfSound_setBuffer(_gd->mapIsland->islandPointSound.lake[1].sound, _gd->mapIsland->islandPointSound.lake[0].buffer);
	sfSound_setBuffer(_gd->mapIsland->islandPointSound.lake[2].sound, _gd->mapIsland->islandPointSound.lake[0].buffer);
	sfSound_setLoop(_gd->mapIsland->islandPointSound.lake[0].sound, _gd->mapIsland->islandPointSound.lake[0].loop);
	sfSound_setLoop(_gd->mapIsland->islandPointSound.lake[1].sound, _gd->mapIsland->islandPointSound.lake[0].loop);
	sfSound_setLoop(_gd->mapIsland->islandPointSound.lake[2].sound, _gd->mapIsland->islandPointSound.lake[0].loop);
	sfSound_setVolume(_gd->mapIsland->islandPointSound.lake[0].sound, 0);
	sfSound_setVolume(_gd->mapIsland->islandPointSound.lake[1].sound, 0);
	sfSound_setVolume(_gd->mapIsland->islandPointSound.lake[2].sound, 0);

	_gd->mapIsland->islandPointSound.fish[0].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Ambiance/Fish.wav");
	_gd->mapIsland->islandPointSound.fish[0].sound = sfSound_create();
	_gd->mapIsland->islandPointSound.fish[1].sound = sfSound_create();
	_gd->mapIsland->islandPointSound.fish[0].loop = 1;
	_gd->mapIsland->islandPointSound.fish[0].isPlaying = sfFalse;
	_gd->mapIsland->islandPointSound.fish[1].isPlaying = sfFalse;
	sfSound_setBuffer(_gd->mapIsland->islandPointSound.fish[0].sound, _gd->mapIsland->islandPointSound.fish[0].buffer);
	sfSound_setBuffer(_gd->mapIsland->islandPointSound.fish[1].sound, _gd->mapIsland->islandPointSound.fish[0].buffer);
	sfSound_setLoop(_gd->mapIsland->islandPointSound.fish[0].sound, _gd->mapIsland->islandPointSound.fish[0].loop);
	sfSound_setLoop(_gd->mapIsland->islandPointSound.fish[1].sound, _gd->mapIsland->islandPointSound.fish[0].loop);
	sfSound_setVolume(_gd->mapIsland->islandPointSound.fish[0].sound, 0);
	sfSound_setVolume(_gd->mapIsland->islandPointSound.fish[1].sound, 0);
	sfSound_play(_gd->mapIsland->islandPointSound.fish[0].sound);
	sfSound_play(_gd->mapIsland->islandPointSound.fish[1].sound);
}

void DestroySoundWorld1(GameData* _gd)
{
	sfSound_destroy(_gd->enigme.utilityPuzzle.woodPickUpSound.sound);
	sfSound_destroy(_gd->enigme.utilityPuzzle.placePuzzleSound.sound);
	sfSound_destroy(_gd->enigme.utilityPuzzle.resetPuzzleSound.sound);
	sfSound_destroy(_gd->enigme.dialogue.letterSound.sound);
	sfSound_destroy(_gd->enigme.dialogue.writeSound.sound);
}

void InitSoundHub(GameData* _gd)
{
	strcpy(_gd->player.stepName, "Metal");

	//Init des sons de l'hub
	_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Pas/MetalSteps.wav");
	_gd->player.stepSound.isPlaying = sfFalse;
	sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);

	_gd->mapBedRoom->introPointSound.cat[0].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Cat.wav");
	_gd->mapBedRoom->introPointSound.cat[0].sound = sfSound_create();
	_gd->mapBedRoom->introPointSound.cat[0].loop = 1;
	_gd->mapBedRoom->introPointSound.cat[0].isPlaying = sfFalse;
	sfSound_setBuffer(_gd->mapBedRoom->introPointSound.cat[0].sound, _gd->mapBedRoom->introPointSound.cat[0].buffer);
	sfSound_setLoop(_gd->mapBedRoom->introPointSound.cat[0].sound, _gd->mapBedRoom->introPointSound.cat[0].loop);
	sfSound_setVolume(_gd->mapBedRoom->introPointSound.cat[0].sound, 0);

	_gd->mapBedRoom->introPointSound.ventilation[0].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Ventillation.wav");
	_gd->mapBedRoom->introPointSound.ventilation[0].sound = sfSound_create();
	_gd->mapBedRoom->introPointSound.ventilation[0].loop = 1;
	_gd->mapBedRoom->introPointSound.ventilation[0].isPlaying = sfFalse;
	sfSound_setBuffer(_gd->mapBedRoom->introPointSound.ventilation[0].sound, _gd->mapBedRoom->introPointSound.ventilation[0].buffer);
	sfSound_setLoop(_gd->mapBedRoom->introPointSound.ventilation[0].sound, _gd->mapBedRoom->introPointSound.ventilation[0].loop);
	sfSound_setVolume(_gd->mapBedRoom->introPointSound.ventilation[0].sound, 0);
}

void DestroySoundHub(GameData* _gd)
{
	sfSound_destroy(_gd->mapBedRoom->introPointSound.ventilation[0].sound);
	sfSound_destroy(_gd->mapBedRoom->introPointSound.cat[0].sound);
}

void InitSoundWorld2(GameData* _gd)
{
	strcpy(_gd->player.stepName, "Grass");
	_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Pas/GrassSteps.wav");
	_gd->player.stepSound.isPlaying = sfFalse;
	sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);

	_gd->currentColor = red;
	_gd->lastColor = red;

	//Labyrinth
	_gd->musicLaby[red].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Laby/Chemin1.wav");
	_gd->musicLaby[red].sound = sfSound_create();
	_gd->musicLaby[red].volume = 100/*_gd->soundGlobal * _gd->soundAmbiance*/;
	sfSound_setBuffer(_gd->musicLaby[red].sound, _gd->musicLaby[red].buffer);
	sfSound_setVolume(_gd->musicLaby[red].sound, _gd->musicLaby[red].volume);
	sfSound_setLoop(_gd->musicLaby[red].sound, 1);

	_gd->musicLaby[blue].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Laby/Chemin2.wav");
	_gd->musicLaby[blue].sound = sfSound_create();
	_gd->musicLaby[blue].volume = 0;
	sfSound_setBuffer(_gd->musicLaby[blue].sound, _gd->musicLaby[blue].buffer);
	sfSound_setVolume(_gd->musicLaby[blue].sound, _gd->musicLaby[blue].volume);
	sfSound_setLoop(_gd->musicLaby[blue].sound, 1);

	_gd->musicLaby[green].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Laby/Chemin3.wav");
	_gd->musicLaby[green].sound = sfSound_create();
	_gd->musicLaby[green].volume = 0;
	sfSound_setBuffer(_gd->musicLaby[green].sound, _gd->musicLaby[green].buffer);
	sfSound_setVolume(_gd->musicLaby[green].sound, _gd->musicLaby[green].volume);
	sfSound_setLoop(_gd->musicLaby[green].sound, 1);

	_gd->musicLaby[yellow].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Laby/Chemin4.wav");
	_gd->musicLaby[yellow].sound = sfSound_create();
	_gd->musicLaby[yellow].volume = 0;
	sfSound_setBuffer(_gd->musicLaby[yellow].sound, _gd->musicLaby[yellow].buffer);
	sfSound_setVolume(_gd->musicLaby[yellow].sound, _gd->musicLaby[yellow].volume);
	sfSound_setLoop(_gd->musicLaby[yellow].sound, 1);

	//Lucioles
	_gd->enigme.interupteur.fireflyOn.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Interaction/Lucioles/FireflyOn.wav");
	_gd->enigme.interupteur.fireflyOn.sound = sfSound_create();
	_gd->enigme.interupteur.fireflyOn.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.interupteur.fireflyOn.sound, _gd->enigme.interupteur.fireflyOn.buffer);
	sfSound_setVolume(_gd->enigme.interupteur.fireflyOn.sound, _gd->enigme.interupteur.fireflyOn.volume);

	_gd->enigme.interupteur.fireflyOff.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Interaction/Lucioles/FireflyOff.wav");
	_gd->enigme.interupteur.fireflyOff.sound = sfSound_create();
	_gd->enigme.interupteur.fireflyOff.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.interupteur.fireflyOff.sound, _gd->enigme.interupteur.fireflyOff.buffer);
	sfSound_setVolume(_gd->enigme.interupteur.fireflyOff.sound, _gd->enigme.interupteur.fireflyOff.volume);

	_gd->enigme.interupteur.fireflyQuit.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Interaction/Lucioles/Frog.wav");
	_gd->enigme.interupteur.fireflyQuit.sound = sfSound_create();
	_gd->enigme.interupteur.fireflyQuit.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.interupteur.fireflyQuit.sound, _gd->enigme.interupteur.fireflyQuit.buffer);
	sfSound_setVolume(_gd->enigme.interupteur.fireflyQuit.sound, _gd->enigme.interupteur.fireflyQuit.volume);

	_gd->enigme.interupteur.fireflyError.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Interaction/Lucioles/Error.wav");
	_gd->enigme.interupteur.fireflyError.sound = sfSound_create();
	_gd->enigme.interupteur.fireflyError.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.interupteur.fireflyError.sound, _gd->enigme.interupteur.fireflyError.buffer);
	sfSound_setVolume(_gd->enigme.interupteur.fireflyError.sound, _gd->enigme.interupteur.fireflyError.volume);

	_gd->enigme.interupteur.fireflyInstruction.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Interaction/Lucioles/Leaf.wav");
	_gd->enigme.interupteur.fireflyInstruction.sound = sfSound_create();
	_gd->enigme.interupteur.fireflyInstruction.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.interupteur.fireflyInstruction.sound, _gd->enigme.interupteur.fireflyInstruction.buffer);
	sfSound_setVolume(_gd->enigme.interupteur.fireflyInstruction.sound, _gd->enigme.interupteur.fireflyInstruction.volume);

	//Puzzle
	_gd->enigme.puzzleJungle.placePuzzleSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Interaction/Puzzle/Place.wav");
	_gd->enigme.puzzleJungle.placePuzzleSound.sound = sfSound_create();
	_gd->enigme.puzzleJungle.placePuzzleSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.puzzleJungle.placePuzzleSound.sound, _gd->enigme.puzzleJungle.placePuzzleSound.buffer);
	sfSound_setVolume(_gd->enigme.puzzleJungle.placePuzzleSound.sound, _gd->enigme.puzzleJungle.placePuzzleSound.volume);

	_gd->enigme.puzzleJungle.rotatePuzzleSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Interaction/Puzzle/Rotation.wav");
	_gd->enigme.puzzleJungle.rotatePuzzleSound.sound = sfSound_create();
	_gd->enigme.puzzleJungle.rotatePuzzleSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.puzzleJungle.rotatePuzzleSound.sound, _gd->enigme.puzzleJungle.rotatePuzzleSound.buffer);
	sfSound_setVolume(_gd->enigme.puzzleJungle.rotatePuzzleSound.sound, _gd->enigme.puzzleJungle.rotatePuzzleSound.volume);

	_gd->enigme.puzzleJungle.helpPuzzleSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Interaction/Puzzle/Help.wav");
	_gd->enigme.puzzleJungle.helpPuzzleSound.sound = sfSound_create();
	_gd->enigme.puzzleJungle.helpPuzzleSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.puzzleJungle.helpPuzzleSound.sound, _gd->enigme.puzzleJungle.helpPuzzleSound.buffer);
	sfSound_setVolume(_gd->enigme.puzzleJungle.helpPuzzleSound.sound, _gd->enigme.puzzleJungle.helpPuzzleSound.volume);

	_gd->enigme.puzzleJungle.laserOnPuzzleSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Interaction/Puzzle/LaserOn.wav");
	_gd->enigme.puzzleJungle.laserOnPuzzleSound.sound = sfSound_create();
	_gd->enigme.puzzleJungle.laserOnPuzzleSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	_gd->enigme.puzzleJungle.laserOnPuzzleSound.isPlaying = sfFalse;
	sfSound_setBuffer(_gd->enigme.puzzleJungle.laserOnPuzzleSound.sound, _gd->enigme.puzzleJungle.laserOnPuzzleSound.buffer);
	sfSound_setVolume(_gd->enigme.puzzleJungle.laserOnPuzzleSound.sound, _gd->enigme.puzzleJungle.laserOnPuzzleSound.volume);

	//Décryptage

	_gd->enigme.decryptage.bookSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Interaction/Decryptage/Book.wav");
	_gd->enigme.decryptage.bookSound.sound = sfSound_create();
	_gd->enigme.decryptage.bookSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.decryptage.bookSound.sound, _gd->enigme.decryptage.bookSound.buffer);
	sfSound_setVolume(_gd->enigme.decryptage.bookSound.sound, _gd->enigme.decryptage.bookSound.volume);

	_gd->enigme.decryptage.writeSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Dialogue/TypeLetter.wav");
	_gd->enigme.decryptage.writeSound.sound = sfSound_create();
	_gd->enigme.decryptage.writeSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.decryptage.writeSound.sound, _gd->enigme.decryptage.writeSound.buffer);
	sfSound_setVolume(_gd->enigme.decryptage.writeSound.sound, _gd->enigme.decryptage.writeSound.volume);

	_gd->enigme.decryptage.ripPaperSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Interaction/Decryptage/Rip.wav");
	_gd->enigme.decryptage.ripPaperSound.sound = sfSound_create();
	_gd->enigme.decryptage.ripPaperSound.volume = _gd->soundGlobal * _gd->soundInterraction;
	sfSound_setBuffer(_gd->enigme.decryptage.ripPaperSound.sound, _gd->enigme.decryptage.ripPaperSound.buffer);
	sfSound_setVolume(_gd->enigme.decryptage.ripPaperSound.sound, _gd->enigme.decryptage.ripPaperSound.volume);

	//PointSound
	_gd->mapJungle->junglePointSound.snake[0].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Ambiance/Snake.wav");
	_gd->mapJungle->junglePointSound.snake[0].sound = sfSound_create();
	_gd->mapJungle->junglePointSound.snake[1].sound = sfSound_create();
	_gd->mapJungle->junglePointSound.snake[2].sound = sfSound_create();
	_gd->mapJungle->junglePointSound.snake[3].sound = sfSound_create();
	_gd->mapJungle->junglePointSound.snake[4].sound = sfSound_create();
	_gd->mapJungle->junglePointSound.snake[5].sound = sfSound_create();
	_gd->mapJungle->junglePointSound.snake[6].sound = sfSound_create();
	_gd->mapJungle->junglePointSound.snake[7].sound = sfSound_create();
	_gd->mapJungle->junglePointSound.snake[8].sound = sfSound_create();
	_gd->mapJungle->junglePointSound.snake[9].sound = sfSound_create();

	_gd->mapJungle->junglePointSound.snake[0].loop = 1;

	_gd->mapJungle->junglePointSound.snake[0].isPlaying = sfFalse;
	_gd->mapJungle->junglePointSound.snake[1].isPlaying = sfFalse;
	_gd->mapJungle->junglePointSound.snake[2].isPlaying = sfFalse;
	_gd->mapJungle->junglePointSound.snake[3].isPlaying = sfFalse;
	_gd->mapJungle->junglePointSound.snake[4].isPlaying = sfFalse;
	_gd->mapJungle->junglePointSound.snake[5].isPlaying = sfFalse;
	_gd->mapJungle->junglePointSound.snake[6].isPlaying = sfFalse;
	_gd->mapJungle->junglePointSound.snake[7].isPlaying = sfFalse;
	_gd->mapJungle->junglePointSound.snake[8].isPlaying = sfFalse;
	_gd->mapJungle->junglePointSound.snake[9].isPlaying = sfFalse;

	sfSound_setBuffer(_gd->mapJungle->junglePointSound.snake[0].sound, _gd->mapJungle->junglePointSound.snake[0].buffer);
	sfSound_setBuffer(_gd->mapJungle->junglePointSound.snake[1].sound, _gd->mapJungle->junglePointSound.snake[0].buffer);
	sfSound_setBuffer(_gd->mapJungle->junglePointSound.snake[2].sound, _gd->mapJungle->junglePointSound.snake[0].buffer);
	sfSound_setBuffer(_gd->mapJungle->junglePointSound.snake[3].sound, _gd->mapJungle->junglePointSound.snake[0].buffer);
	sfSound_setBuffer(_gd->mapJungle->junglePointSound.snake[4].sound, _gd->mapJungle->junglePointSound.snake[0].buffer);
	sfSound_setBuffer(_gd->mapJungle->junglePointSound.snake[5].sound, _gd->mapJungle->junglePointSound.snake[0].buffer);
	sfSound_setBuffer(_gd->mapJungle->junglePointSound.snake[6].sound, _gd->mapJungle->junglePointSound.snake[0].buffer);
	sfSound_setBuffer(_gd->mapJungle->junglePointSound.snake[7].sound, _gd->mapJungle->junglePointSound.snake[0].buffer);
	sfSound_setBuffer(_gd->mapJungle->junglePointSound.snake[8].sound, _gd->mapJungle->junglePointSound.snake[0].buffer);
	sfSound_setBuffer(_gd->mapJungle->junglePointSound.snake[9].sound, _gd->mapJungle->junglePointSound.snake[0].buffer);

	sfSound_setLoop(_gd->mapJungle->junglePointSound.snake[0].sound, _gd->mapJungle->junglePointSound.snake[0].loop);
	sfSound_setLoop(_gd->mapJungle->junglePointSound.snake[1].sound, _gd->mapJungle->junglePointSound.snake[0].loop);
	sfSound_setLoop(_gd->mapJungle->junglePointSound.snake[2].sound, _gd->mapJungle->junglePointSound.snake[0].loop);
	sfSound_setLoop(_gd->mapJungle->junglePointSound.snake[3].sound, _gd->mapJungle->junglePointSound.snake[0].loop);
	sfSound_setLoop(_gd->mapJungle->junglePointSound.snake[4].sound, _gd->mapJungle->junglePointSound.snake[0].loop);
	sfSound_setLoop(_gd->mapJungle->junglePointSound.snake[5].sound, _gd->mapJungle->junglePointSound.snake[0].loop);
	sfSound_setLoop(_gd->mapJungle->junglePointSound.snake[6].sound, _gd->mapJungle->junglePointSound.snake[0].loop);
	sfSound_setLoop(_gd->mapJungle->junglePointSound.snake[7].sound, _gd->mapJungle->junglePointSound.snake[0].loop);
	sfSound_setLoop(_gd->mapJungle->junglePointSound.snake[8].sound, _gd->mapJungle->junglePointSound.snake[0].loop);
	sfSound_setLoop(_gd->mapJungle->junglePointSound.snake[9].sound, _gd->mapJungle->junglePointSound.snake[0].loop);

	sfSound_setVolume(_gd->mapJungle->junglePointSound.snake[0].sound, 0);
	sfSound_setVolume(_gd->mapJungle->junglePointSound.snake[1].sound, 0);
	sfSound_setVolume(_gd->mapJungle->junglePointSound.snake[2].sound, 0);
	sfSound_setVolume(_gd->mapJungle->junglePointSound.snake[3].sound, 0);
	sfSound_setVolume(_gd->mapJungle->junglePointSound.snake[4].sound, 0);
	sfSound_setVolume(_gd->mapJungle->junglePointSound.snake[5].sound, 0);
	sfSound_setVolume(_gd->mapJungle->junglePointSound.snake[6].sound, 0);
	sfSound_setVolume(_gd->mapJungle->junglePointSound.snake[7].sound, 0);
	sfSound_setVolume(_gd->mapJungle->junglePointSound.snake[8].sound, 0);
	sfSound_setVolume(_gd->mapJungle->junglePointSound.snake[9].sound, 0);
}

void DestroySoundWorld2(GameData* _gd)
{
	sfSound_destroy(_gd->enigme.interupteur.fireflyOn.sound);
	sfSound_destroy(_gd->enigme.interupteur.fireflyOff.sound);
	sfSound_destroy(_gd->enigme.interupteur.fireflyError.sound);
	sfSound_destroy(_gd->enigme.interupteur.fireflyInstruction.sound);
	sfSound_destroy(_gd->enigme.interupteur.fireflyQuit.sound);
	sfSound_destroy(_gd->mapJungle->junglePointSound.snake[0].sound);
}

void InitSoundShipEnd(GameData* _gd)
{
	strcpy(_gd->player.stepName, "Metal");

	//Init des sons de l'intro
	_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Pas/MetalSteps.wav");
	_gd->player.stepSound.sound = sfSound_create();
	_gd->player.stepSound.volume = _gd->soundGlobal * _gd->soundAmbiance;
	_gd->player.stepSound.loop = 1;
	_gd->player.stepSound.isPlaying = sfFalse;
	sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
	sfSound_setVolume(_gd->player.stepSound.sound, _gd->player.stepSound.volume);
	sfSound_setLoop(_gd->player.stepSound.sound, _gd->player.stepSound.loop);

	_gd->mapShipEnd->introPointSound.electricity[0].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Electricity.wav");
	_gd->mapShipEnd->introPointSound.electricity[0].sound = sfSound_create();
	_gd->mapShipEnd->introPointSound.electricity[1].sound = sfSound_create();
	_gd->mapShipEnd->introPointSound.electricity[0].loop = 1;
	_gd->mapShipEnd->introPointSound.electricity[0].isPlaying = sfFalse;
	_gd->mapShipEnd->introPointSound.electricity[1].isPlaying = sfFalse;
	sfSound_setBuffer(_gd->mapShipEnd->introPointSound.electricity[0].sound, _gd->mapShipEnd->introPointSound.electricity[0].buffer);
	sfSound_setBuffer(_gd->mapShipEnd->introPointSound.electricity[1].sound, _gd->mapShipEnd->introPointSound.electricity[0].buffer);
	sfSound_setLoop(_gd->mapShipEnd->introPointSound.electricity[0].sound, _gd->mapShipEnd->introPointSound.electricity[0].loop);
	sfSound_setLoop(_gd->mapShipEnd->introPointSound.electricity[1].sound, _gd->mapShipEnd->introPointSound.electricity[0].loop);
	sfSound_setVolume(_gd->mapShipEnd->introPointSound.electricity[0].sound, 0);
	sfSound_setVolume(_gd->mapShipEnd->introPointSound.electricity[1].sound, 0);

	_gd->mapShipEnd->introPointSound.ventilation[0].buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Ventillation.wav");
	_gd->mapShipEnd->introPointSound.ventilation[0].sound = sfSound_create();
	_gd->mapShipEnd->introPointSound.ventilation[1].sound = sfSound_create();
	_gd->mapShipEnd->introPointSound.ventilation[0].loop = 1;
	_gd->mapShipEnd->introPointSound.ventilation[0].isPlaying = sfFalse;
	_gd->mapShipEnd->introPointSound.ventilation[1].isPlaying = sfFalse;
	sfSound_setBuffer(_gd->mapShipEnd->introPointSound.ventilation[0].sound, _gd->mapShipEnd->introPointSound.ventilation[0].buffer);
	sfSound_setBuffer(_gd->mapShipEnd->introPointSound.ventilation[1].sound, _gd->mapShipEnd->introPointSound.ventilation[0].buffer);
	sfSound_setLoop(_gd->mapShipEnd->introPointSound.ventilation[0].sound, _gd->mapShipEnd->introPointSound.ventilation[0].loop);
	sfSound_setLoop(_gd->mapShipEnd->introPointSound.ventilation[1].sound, _gd->mapShipEnd->introPointSound.ventilation[0].loop);
	sfSound_setVolume(_gd->mapShipEnd->introPointSound.ventilation[0].sound, 0);
	sfSound_setVolume(_gd->mapShipEnd->introPointSound.ventilation[1].sound, 0);
}

void DestroySoundShipEnd(GameData* _gd)
{
	sfSound_destroy(_gd->mapShipEnd->introPointSound.electricity[0].sound);
	sfSound_destroy(_gd->mapShipEnd->introPointSound.electricity[1].sound);
	sfSound_destroy(_gd->mapShipEnd->introPointSound.ventilation[0].sound);
	sfSound_destroy(_gd->mapShipEnd->introPointSound.ventilation[1].sound);
}

void InitSoundMenu(GameData* _gd)
{
	_gd->menuInteract.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Menu/Boutons/Select.wav");
	_gd->menuInteract.sound = sfSound_create();
	_gd->menuInteract.volume = _gd->soundGlobal;
	_gd->menuInteract.loop = 0;
	sfSound_setBuffer(_gd->menuInteract.sound, _gd->menuInteract.buffer);
	sfSound_setVolume(_gd->menuInteract.sound, _gd->menuInteract.volume);
	sfSound_setLoop(_gd->menuInteract.sound, _gd->menuInteract.loop);

	if (_gd->menuMusic.isPlaying == sfFalse)
	{
		_gd->menuMusic.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Menu/Musique/Music.wav");
		_gd->menuMusic.sound = sfSound_create();
		_gd->menuMusic.volume = _gd->soundGlobal;
		_gd->menuMusic.loop = 1;
		_gd->menuMusic.isPlaying = sfTrue;
		sfSound_setBuffer(_gd->menuMusic.sound, _gd->menuMusic.buffer);
		sfSound_setVolume(_gd->menuMusic.sound, _gd->menuMusic.volume);
		sfSound_setLoop(_gd->menuMusic.sound, _gd->menuMusic.loop);
	}

	if (sfSound_getStatus(_gd->menuMusic.sound) == sfStopped)
	{
		sfSound_play(_gd->menuMusic.sound);

	}
}
