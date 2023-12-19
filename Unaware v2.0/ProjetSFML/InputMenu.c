#include "InputMenu.h"

void PlaySoundAgain(GameData* _gd)
{
	if (_gd->world == begin)
	{
		sfSound_setVolume(_gd->menuMusic.sound, _gd->soundGlobal * _gd->soundMusic);
	}
	if (_gd->world == intro)
	{
		sfSound_setVolume(_gd->worldAmbience.sound, _gd->soundGlobal * _gd->soundMusic);
		sfSound_setVolume(_gd->bedInteract.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->helpSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->enigme.doorDigicode.interactSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->enigme.doorDigicode.errorSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->enigme.doorDigicode.validSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->enigme.doorDigicode.arrowSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->player.stepSound.sound, _gd->soundGlobal * _gd->soundAmbiance);
	}
	if (_gd->world == island)
	{
		sfSound_setVolume(_gd->player.stepSound.sound, _gd->soundGlobal * _gd->soundAmbiance);
		sfSound_setVolume(_gd->worldAmbience.sound, _gd->soundGlobal * _gd->soundMusic);
		sfSound_setVolume(_gd->errorSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->sucessSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->enigme.utilityPuzzle.woodPickUpSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->enigme.utilityPuzzle.placePuzzleSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->enigme.utilityPuzzle.resetPuzzleSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->enigme.dialogue.letterSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->enigme.dialogue.writeSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->utilityPieceBoite.pickUpCoinSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->utilityPieceBoite.unscrewSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->utilityPieceBoite.plateSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->utilityPieceBoite.wirePickUpSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->utilityCable.wiresSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->utilityCable.powerOnSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->enigme.voltage.switchSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->enigme.doorDigicode.errorSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->enigme.doorDigicode.validSound.sound, _gd->soundGlobal * _gd->soundInterraction);
		sfSound_setVolume(_gd->enigme.doorDigicode.arrowSound.sound, _gd->soundGlobal * _gd->soundInterraction);
	}
}

void MuteSound(GameData* _gd)
{
	if (_gd->world == begin)
	{
		sfSound_setVolume(_gd->menuMusic.sound, 0);
	}
	if (_gd->world == intro)
	{
		sfSound_setVolume(_gd->worldAmbience.sound, 0);
	}
	if (_gd->world == island)
	{
		sfSound_setVolume(_gd->worldAmbience.sound, 0);
	}
}

void InputMenu(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos;
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (isCollidingWithMouse(_gd->buttons[0].forme, tempPos, 1) == 1)
			{
				sfSound_play(_gd->menuInteract.sound);
				_gd->gameState = selecteurPerso;
			}
			if (isCollidingWithMouse(_gd->buttons[1].forme, tempPos, 1) == 1)
			{
				sfSound_play(_gd->menuInteract.sound);
				_gd->gameState = option;
				MuteSound(_gd);
			}
			if (isCollidingWithMouse(_gd->buttons[2].forme, tempPos, 1) == 1)
			{
				sfSound_play(_gd->menuInteract.sound);
				_gd->gameState = credit;
			}
			if (isCollidingWithMouse(_gd->buttons[3].forme, tempPos, 1) == 1)
			{
				sfSound_play(_gd->menuInteract.sound);
				_gd->gameState = controle;
			}
			if (isCollidingWithMouse(_gd->buttons[4].forme, tempPos, 1) == 1)
			{
				sfSound_play(_gd->menuInteract.sound);
				exit(0);
			}
		}
	}

}


void InputCredit(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos;
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;
	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (isCollidingWithMouse(_gd->quitCredit, tempPos, 1) == 1)
			{
				sfSound_play(_gd->menuInteract.sound);
				_gd->gameState = menu;
			}
		}
	}
}

void InputOptions(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos;
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;
	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (isCollidingWithMouse(_gd->quitOptions, tempPos, 1) == 1)
			{
				sfSound_play(_gd->menuInteract.sound);
				_gd->gameState = menu;
				PlaySoundAgain(_gd);
			}
			if (isCollidingWithMouse(_gd->buttons[5].forme, tempPos, 1) == 1)
			{
				sfSound_play(_gd->menuInteract.sound);
				_gd->gameState = volume;
			}
		}
	}
}

void InputPause(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos;
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (isCollidingWithMouse(_gd->quitPause, tempPos, 1) == 1)
			{
				sfSound_play(_gd->menuInteract.sound);
				_gd->gameState = play;
				PlaySoundAgain(_gd);
			}
			if (isCollidingWithMouse(_gd->buttons[5].forme, tempPos, 1) == 1)
			{
				sfSound_play(_gd->menuInteract.sound);
				_gd->gameState = volume;
			}
			if (isCollidingWithMouse(_gd->buttons[6].forme, tempPos, 1))
			{
				sfSound_play(_gd->menuInteract.sound);
				_gd->clickSpriteQuitPauseMenu = sfTrue;
			}
			if (isCollidingWithMouse(_gd->controleMenuPause.forme, tempPos, 0))
			{
				sfSound_play(_gd->menuInteract.sound);
				_gd->gameState = controle;

			}
		}
	}
	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->clickSpriteQuitPauseMenu = sfFalse;

			if (isCollidingWithMouse(_gd->buttons[6].forme, tempPos, 0))
			{
				if (_gd->world == intro)
				{
					//suppresion du son de l'intro
					DestroySoundIntro(_gd);
					//suppression de la map Intro
					DestroyIntroMap(_gd);
				}
				else if (_gd->world == island)
				{
					//suppresion du son de l'island
					DestroySoundWorld1(_gd);
					//suppression de la map island
					DestroyIslandMap(_gd);
				}
				else if (_gd->world == bedroom)
				{
					//suppresion du son deu bedroom
					DestroySoundHub(_gd);
					//suppression de la map bedroom
					DestroyBedRoomMap(_gd);
				}
				else if (_gd->world == jungle)
				{
					//suppresion du son de la jungle
					DestroySoundWorld2(_gd);
					//suppression de la map jungle
					DestroyJungleMap(_gd);
				}
				_gd->gameState = menu; //menu pour menu 
				_gd->world = begin; // begin pour menu
				_gd->inGameState = load; // load pour menu
				_gd->enigmeState = none; // none quand pas d'enigme
				_gd->enigmeBox = none; // none de base, pour box d'island
				_gd->cutSceneState = noCin; // none de base, pour cinématique
				_gd->enigme.dialogue.state = NONE;
				_gd->worldAmbience.isPlaying = sfFalse;
				_gd->enigme.doorDigicode.resolvedIntro = sfFalse;
				sfSound_destroy(_gd->worldAmbience.sound);

				InitMenu(_gd);
			}
		}
	}
}

void InputControle(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos;
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (isCollidingWithMouse(_gd->quitControle, tempPos, 0) == 1)
			{
				sfSound_play(_gd->menuInteract.sound);
				if (_gd->inGameState == load)
				{
					_gd->gameState = menu;
					PlaySoundAgain(_gd);
				}
				else if (_gd->inGameState == exploration || _gd->inGameState == enigme || _gd->inGameState == tuto)
				{
					_gd->gameState = pause;
				}
			}
		}
	}
}

void InputVolume(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos;
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{

		for (int i = 0; i < NB_CAT_SOUND; i++)
		{
			if (_gd->event.mouseButton.button == sfMouseLeft
				&& isCollidingWithMouse(_gd->rectTestVolume[i], tempPos, 1) == 1)
			{
				Sound soundtest;
				soundtest.sound = sfSound_create();
				if (i == 0)
				{
					soundtest.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Menu/Musique/musicTest.wav");
					soundtest.volume = _gd->soundGlobal * _gd->soundMusic;
					sfSound_setBuffer(soundtest.sound, soundtest.buffer);
					sfSound_setVolume(soundtest.sound, soundtest.volume);
					sfSound_play(soundtest.sound);
				}
				else if (i == 1)
				{
					//soundtest.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Menu/Musique/miaou.wav");
					soundtest.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Electricity.wav");
					soundtest.volume = _gd->soundGlobal * _gd->soundAmbiance;
					sfSound_setBuffer(soundtest.sound, soundtest.buffer);
					sfSound_setVolume(soundtest.sound, soundtest.volume);
					sfSound_play(soundtest.sound);
				}
				else if (i == 2)
				{
					soundtest.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Interaction/Sucess.wav");
					soundtest.volume = _gd->soundGlobal * _gd->soundInterraction;
					sfSound_setBuffer(soundtest.sound, soundtest.buffer);
					sfSound_setVolume(soundtest.sound, soundtest.volume);
					sfSound_play(soundtest.sound);
				}
			}

		}
	}


}