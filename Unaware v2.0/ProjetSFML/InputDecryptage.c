#include "InputDecryptage.h"

void InputDecryptage(GameData* _gd)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouse = { mouse.x,mouse.y };

	if (_gd->event.type == sfEvtKeyPressed)
	{
		int sizeChar = strlen(_gd->enigme.decryptage.word);
		//only the alphabet in upper case
		if (_gd->event.key.code >= sfKeyA
			&& _gd->event.key.code <= sfKeyZ
			&& sizeChar < 7)
		{
			sfSound_play(_gd->enigme.decryptage.writeSound.sound);

			char temp[2] = { _gd->event.key.code + 65 };
			strcat(_gd->enigme.decryptage.word, temp);
			//printf("%s\n", _gd->enigme.decryptage.word);
			sfText_setString(_gd->enigme.decryptage.text, _gd->enigme.decryptage.word);
		}
		//remove the last character
		if (_gd->event.key.code == sfKeyBackspace && sizeChar > 0)
		{
			sfSound_play(_gd->enigme.decryptage.writeSound.sound);

			sizeChar--;
			_gd->enigme.decryptage.word[sizeChar] = '\0';
			sfText_setString(_gd->enigme.decryptage.text, _gd->enigme.decryptage.word);

		}

		// verification de si le mot de passe est le bon 
		if (_gd->event.key.code == sfKeyEnter)
		{
			if (!strcmp(_gd->enigme.decryptage.word, SOLUTION_DECRYPTAGE))
			{
				if (sfSound_getStatus(_gd->sucessSound.sound) == sfStopped)
				{
					sfSound_play(_gd->sucessSound.sound);
				}

				_gd->inGameState = exploration;
				_gd->enigmeState = none;
				_gd->player.pos.x = _gd->mapJungle->mapPoint[10].pos.x;
				_gd->player.pos.y = _gd->mapJungle->mapPoint[10].pos.y;
			}
			else
			{
				if (sfSound_getStatus(_gd->errorSound.sound) == sfStopped)
				{
					sfSound_play(_gd->errorSound.sound);
				}
			}


		}
	}
	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (isCollidingWithMouse(_gd->enigme.decryptage.quitDecryptage.forme, posMouse, 0))
			{
				_gd->enigme.decryptage.clickQuitDecryptage = sfTrue;
			}
			if (isCollidingWithMouse(_gd->enigme.decryptage.validateDecryptage.forme, posMouse, 0))
			{
				_gd->enigme.decryptage.clickValidateDecryptage = sfTrue;
			}
			if (isCollidingWithMouse(_gd->enigme.decryptage.resetDecryptage.forme, posMouse, 0))
			{
				_gd->enigme.decryptage.clickResetDecryptage = sfTrue;
			}
			if (isCollidingWithMouse(_gd->enigme.decryptage.aideDecryptage.forme, posMouse, 0))
			{
				_gd->enigme.decryptage.clickAideDecryptage = sfTrue;
			}
		}
	}

	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->enigme.decryptage.clickQuitDecryptage = sfFalse;
			_gd->enigme.decryptage.clickValidateDecryptage = sfFalse;
			_gd->enigme.decryptage.clickResetDecryptage = sfFalse;
			_gd->enigme.decryptage.clickAideDecryptage = sfFalse;

			if (isCollidingWithMouse(_gd->enigme.decryptage.quitDecryptage.forme, posMouse, 0))
			{
				_gd->inGameState = exploration;
				_gd->enigmeState = none;
			}
			if (isCollidingWithMouse(_gd->enigme.decryptage.validateDecryptage.forme, posMouse, 0))
			{
				if (strcmp(_gd->enigme.decryptage.word, SOLUTION_DECRYPTAGE) == 0)
				{
					if (sfSound_getStatus(_gd->sucessSound.sound) == sfStopped)
					{
						sfSound_play(_gd->sucessSound.sound);
					}
					_gd->inGameState = exploration;
					_gd->enigmeState = none;
					_gd->player.pos.x = _gd->mapJungle->mapPoint[10].pos.x;
					_gd->player.pos.y = _gd->mapJungle->mapPoint[10].pos.y;
				}
				else
				{
					if (sfSound_getStatus(_gd->errorSound.sound) == sfStopped)
					{
						sfSound_play(_gd->errorSound.sound);
					}

				}
			}
			if (isCollidingWithMouse(_gd->enigme.decryptage.resetDecryptage.forme, posMouse, 0))
			{
				int sizeChar = strlen(_gd->enigme.decryptage.word);
				if (sfSound_getStatus(_gd->enigme.decryptage.ripPaperSound.sound) == sfStopped)
				{
					sfSound_play(_gd->enigme.decryptage.ripPaperSound.sound);
				}
				for (int i = sizeChar; i >= 0; i--)
				{
					//i--;
					_gd->enigme.decryptage.word[i] = '\0';
					sfText_setString(_gd->enigme.decryptage.text, _gd->enigme.decryptage.word);
				}


			}
			if (isCollidingWithMouse(_gd->enigme.decryptage.aideDecryptage.forme, posMouse, 0))
			{
				sfSound_play(_gd->helpSound.sound);
				_gd->inGameState = tuto;
			}
		}
	}
}
