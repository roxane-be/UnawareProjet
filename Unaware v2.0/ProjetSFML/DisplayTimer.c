#include "DisplayTimer.h"

void DisplayTimerInterface(GameData* _gd)
{
	if (_gd->inGameState == exploration)
	{
		if (_gd->enigmeState == none)
		{
			BlitSprite(_gd->interfaceTimer, (_gd->sizeWindow.width / 2) - 100, 0, 0, 0.6, 0.6, _gd);
		}
		if (_gd->enigme.dialogue.state == INDIALOGUE)
		{
			BlitSprite(_gd->interfaceTimer, (_gd->sizeWindow.width / 2) - 100, 0, 0, 0.6, 0.6, _gd);

		}
		if (_gd->enigmeState == dialogueIsland && _gd->enigme.dialogue.state == DOOR && _gd->enigme.dialogue.resolvedDream_1 == sfFalse)
		{
			BlitSprite(_gd->interfaceTimerEnigme, (_gd->sizeWindow.width / 2) - 175, -35, 0, 0.9, 0.9, _gd);
		}
	}

	else if (_gd->inGameState == enigme)
	{
		BlitSprite(_gd->interfaceTimerEnigme, (_gd->sizeWindow.width / 2) - 175, -35, 0, 0.9, 0.9, _gd);
	}
	else if (_gd->inGameState == tuto)
	{
		BlitSprite(_gd->interfaceTimerEnigme, (_gd->sizeWindow.width / 2) - 175, -35, 0, 0.9, 0.9, _gd);
	}

}

void DisplayTimerIsland(GameData* _gd)
{
	int minUnite = (int)_gd->timer.timerMin % 10;
	int minDizaine = 0;

	for (int i = _gd->timer.timerMin - minUnite; i > 0; i -= 10)
	{
		minDizaine++;
	}

	int secUnite = (int)_gd->timer.timerSec % 10;
	int secDizaine = 0;

	for (int i = _gd->timer.timerSec - secUnite; i > 0; i -= 10)
	{
		secDizaine++;
	}

	if (_gd->enigmeState == none || _gd->enigme.dialogue.state == INDIALOGUE)
	{
		BlitSprite(_gd->sprites.spriteTimer[minDizaine].sprite, (_gd->sizeWindow.width / 2) - 10, 55, 0, 0.5, 0.5, _gd);
		BlitSprite(_gd->sprites.spriteTimer[minUnite].sprite, (_gd->sizeWindow.width / 2) + 19, 55, 0, 0.5, 0.5, _gd);
		BlitSprite(_gd->sprites.spriteTimerPoint.sprite, (_gd->sizeWindow.width / 2) + 30, 40, 0, 0.5, 0.5, _gd);
		BlitSprite(_gd->sprites.spriteTimer[secDizaine].sprite, (_gd->sizeWindow.width / 2) + 75, 55, 0, 0.5, 0.5, _gd);
		BlitSprite(_gd->sprites.spriteTimer[secUnite].sprite, (_gd->sizeWindow.width / 2) + 100, 55, 0, 0.5, 0.5, _gd);
	}
	else if (_gd->enigmeState != none || _gd->enigme.dialogue.state == DOOR)
	{
		//sfSprite_setColor(_gd->sprites.spriteTimer[minDizaine].sprite, sfBlack);
		BlitSprite(_gd->sprites.spriteTimer[minDizaine].sprite, (_gd->sizeWindow.width / 2) - 10, 45, 0, 0.5, 0.5, _gd);

		//sfSprite_setColor(_gd->sprites.spriteTimer[minUnite].sprite, sfBlack);
		BlitSprite(_gd->sprites.spriteTimer[minUnite].sprite, (_gd->sizeWindow.width / 2) + 19, 45, 0, 0.5, 0.5, _gd);

		//sfSprite_setColor(_gd->sprites.spriteTimerPoint.sprite, sfBlack);
		BlitSprite(_gd->sprites.spriteTimerPoint.sprite, (_gd->sizeWindow.width / 2) + 30, 31, 0, 0.5, 0.5, _gd);

		//sfSprite_setColor(_gd->sprites.spriteTimer[secDizaine].sprite, sfBlack);
		BlitSprite(_gd->sprites.spriteTimer[secDizaine].sprite, (_gd->sizeWindow.width / 2) + 75, 45, 0, 0.5, 0.5, _gd);

		//sfSprite_setColor(_gd->sprites.spriteTimer[secUnite].sprite, sfBlack);
		BlitSprite(_gd->sprites.spriteTimer[secUnite].sprite, (_gd->sizeWindow.width / 2) + 100, 45, 0, 0.5, 0.5, _gd);
	}

}

void DisplayTimerInterfaceJungle(GameData* _gd)
{
	if (_gd->inGameState == exploration)
	{
		BlitSprite(_gd->interfaceTimer, (_gd->sizeWindow.width / 2) - 100, 0, 0, 0.6, 0.6, _gd);
	}
	else if (_gd->inGameState == enigme)
	{
		BlitSprite(_gd->interfaceTimerEnigme, (_gd->sizeWindow.width / 2) - 175, -35, 0, 0.9, 0.9, _gd);
	}
	else if (_gd->inGameState == tuto)
	{
		BlitSprite(_gd->interfaceTimerEnigme, (_gd->sizeWindow.width / 2) - 175, -35, 0, 0.9, 0.9, _gd);
	}
	else if (_gd->inGameState == symbole)
	{
		BlitSprite(_gd->interfaceTimerEnigme, (_gd->sizeWindow.width / 2) - 175, -35, 0, 0.9, 0.9, _gd);
	}
}

void DisplayTimerJungle(GameData* _gd)
{
	int minUnite = (int)_gd->timer.timerMin % 10;
	int minDizaine = 0;

	for (int i = _gd->timer.timerMin - minUnite; i > 0; i -= 10)
	{
		minDizaine++;
	}

	int secUnite = (int)_gd->timer.timerSec % 10;
	int secDizaine = 0;

	for (int i = _gd->timer.timerSec - secUnite; i > 0; i -= 10)
	{
		secDizaine++;
	}

	if (_gd->enigmeState == none || _gd->enigme.dialogue.state == INDIALOGUE)
	{
		BlitSprite(_gd->sprites.spriteTimer[minDizaine].sprite, (_gd->sizeWindow.width / 2) - 10, 55, 0, 0.5, 0.5, _gd);
		BlitSprite(_gd->sprites.spriteTimer[minUnite].sprite, (_gd->sizeWindow.width / 2) + 19, 55, 0, 0.5, 0.5, _gd);
		BlitSprite(_gd->sprites.spriteTimerPoint.sprite, (_gd->sizeWindow.width / 2) + 30, 40, 0, 0.5, 0.5, _gd);
		BlitSprite(_gd->sprites.spriteTimer[secDizaine].sprite, (_gd->sizeWindow.width / 2) + 75, 55, 0, 0.5, 0.5, _gd);
		BlitSprite(_gd->sprites.spriteTimer[secUnite].sprite, (_gd->sizeWindow.width / 2) + 100, 55, 0, 0.5, 0.5, _gd);
	}
	else if (_gd->enigmeState != none || _gd->enigme.dialogue.state == DOOR)
	{
		//sfSprite_setColor(_gd->sprites.spriteTimer[minDizaine].sprite, sfBlack);
		BlitSprite(_gd->sprites.spriteTimer[minDizaine].sprite, (_gd->sizeWindow.width / 2) - 10, 45, 0, 0.5, 0.5, _gd);

		//sfSprite_setColor(_gd->sprites.spriteTimer[minUnite].sprite, sfBlack);
		BlitSprite(_gd->sprites.spriteTimer[minUnite].sprite, (_gd->sizeWindow.width / 2) + 19, 45, 0, 0.5, 0.5, _gd);

		//sfSprite_setColor(_gd->sprites.spriteTimerPoint.sprite, sfBlack);
		BlitSprite(_gd->sprites.spriteTimerPoint.sprite, (_gd->sizeWindow.width / 2) + 30, 31, 0, 0.5, 0.5, _gd);

		//sfSprite_setColor(_gd->sprites.spriteTimer[secDizaine].sprite, sfBlack);
		BlitSprite(_gd->sprites.spriteTimer[secDizaine].sprite, (_gd->sizeWindow.width / 2) + 75, 45, 0, 0.5, 0.5, _gd);

		//sfSprite_setColor(_gd->sprites.spriteTimer[secUnite].sprite, sfBlack);
		BlitSprite(_gd->sprites.spriteTimer[secUnite].sprite, (_gd->sizeWindow.width / 2) + 100, 45, 0, 0.5, 0.5, _gd);
	}
}