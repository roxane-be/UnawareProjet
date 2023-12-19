#include "UpdateMastermindIntro.h"

void UpdateAnimationButtonMastermindIntro(GameData* _gd, int _idArrow)
{
	_gd->enigme.doorDigicode.arrowIntro[_idArrow].currentTime += _gd->frameRate.dt / 10.f;

	float totalTime = _gd->enigme.doorDigicode.arrowIntro[_idArrow].sequence[_gd->enigme.doorDigicode.arrowIntro[_idArrow].idSeq].total;
	int start = _gd->enigme.doorDigicode.arrowIntro[_idArrow].sequence[_gd->enigme.doorDigicode.arrowIntro[_idArrow].idSeq].begin;
	int end = _gd->enigme.doorDigicode.arrowIntro[_idArrow].sequence[_gd->enigme.doorDigicode.arrowIntro[_idArrow].idSeq].end;
	int nbAnim = 1 + (end - start);

	_gd->enigme.doorDigicode.arrowIntro[_idArrow].currentAnim = nbAnim * _gd->enigme.doorDigicode.arrowIntro[_idArrow].currentTime / totalTime + start;

	if (_gd->enigme.doorDigicode.arrowIntro[_idArrow].currentTime >=
		_gd->enigme.doorDigicode.arrowIntro[_idArrow].sequence[_gd->enigme.doorDigicode.arrowIntro[_idArrow].idSeq].total)
	{
		ChoiceNumberIntro(_gd, _idArrow);
		_gd->enigme.doorDigicode.arrowIntro[_idArrow].idSeq = 1;
		_gd->enigme.doorDigicode.arrowIntro[_idArrow].currentTime = 0.f;
		_gd->enigme.doorDigicode.arrowIntro[_idArrow].isClicked = sfFalse;
		if (_idArrow < 4)
		{
			_gd->enigme.doorDigicode.arrowIntro[_idArrow].currentAnim = 3;
		}
		else
		{
			_gd->enigme.doorDigicode.arrowIntro[_idArrow].currentAnim = 0;
		}
	}
}

void UpdateButtonMastermindIntro(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos = { 0, 0 };
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	if (isCollidingWithMouse(_gd->enigme.doorDigicode.buttonHelp.forme, tempPos, 0))
	{
		_gd->enigme.doorDigicode.onSpriteHelp = sfTrue;
	}
	else
	{
		_gd->enigme.doorDigicode.onSpriteHelp = sfFalse;
	}

	if (isCollidingWithMouse(_gd->enigme.doorDigicode.buttonQuit.forme, tempPos, 0))
	{
		_gd->enigme.doorDigicode.onSpriteQuit = sfTrue;
	}
	else
	{
		_gd->enigme.doorDigicode.onSpriteQuit = sfFalse;
	}

	if (isCollidingWithMouse(_gd->enigme.doorDigicode.buttonValidate.forme, tempPos, 0))
	{
		_gd->enigme.doorDigicode.onSpriteValidate = sfTrue;
	}
	else
	{
		_gd->enigme.doorDigicode.onSpriteValidate = sfFalse;
	}
}

void isValidateIntro(struct GameData* _gd)
{
	int currentI = _gd->enigme.doorDigicode.current;
	int currentJ = 0;
	_gd->enigme.doorDigicode.nbDiodeGreen = 0;
	_gd->enigme.doorDigicode.nbDiodeYellow = 0;

	int tab[1][4];
	for (int j = 0; j < NB_DIGICODE; j++)
	{
		tab[0][j] = _gd->enigme.doorDigicode.tabTry[0][j];
	}

	_gd->enigme.doorDigicode.nbDiodeGreen = 0;
	_gd->enigme.doorDigicode.nbDiodeYellow = 0;

	if (_gd->enigme.doorDigicode.isFull == sfFalse)
	{
		for (int j = 0; j < NB_DIGICODE; j++)
		{

			if (_gd->enigme.doorDigicode.value[j] == _gd->enigme.doorDigicode.valueCode[0]
				|| _gd->enigme.doorDigicode.value[j] == _gd->enigme.doorDigicode.valueCode[1]
				|| _gd->enigme.doorDigicode.value[j] == _gd->enigme.doorDigicode.valueCode[2]
				|| _gd->enigme.doorDigicode.value[j] == _gd->enigme.doorDigicode.valueCode[3])
			{
				if (_gd->enigme.doorDigicode.value[j] == _gd->enigme.doorDigicode.valueCode[j])
				{
					//printf("%d", _gd->enigme.doorDigicode.value[j]);
					_gd->enigme.doorDigicode.nbDiodeGreen++;
					currentJ++;
					for (int i = 0; i < j; i++)
					{
						if (_gd->enigme.doorDigicode.duplicate[j].value == _gd->enigme.doorDigicode.value[i] &&
							_gd->enigme.doorDigicode.nbDiodeYellow > 0)
						{
							_gd->enigme.doorDigicode.nbDiodeYellow--;
						}
					}
				}
				else
				{
					_gd->enigme.doorDigicode.nbDiodeYellow++;
					currentJ++;
					for (int i = 0; i < j; i++)
					{
						if (_gd->enigme.doorDigicode.duplicate[j].value == _gd->enigme.doorDigicode.value[i])
						{
							if (_gd->enigme.doorDigicode.nbDiodeYellow > 0)
							{
								_gd->enigme.doorDigicode.nbDiodeYellow--;
								i = j;
							}
						}
					}
				}
			}
		}
	}

	for (int k = 0; k < _gd->enigme.doorDigicode.nbDiodeGreen; k++)
	{
		_gd->enigme.doorDigicode.diodeGreen[_gd->enigme.doorDigicode.current][k] = sfTrue;
	}

	for (int k = _gd->enigme.doorDigicode.nbDiodeGreen; k < _gd->enigme.doorDigicode.nbDiodeYellow + _gd->enigme.doorDigicode.nbDiodeGreen; k++)
	{
		_gd->enigme.doorDigicode.diodeYellow[_gd->enigme.doorDigicode.current][k] = sfTrue;
	}

	if (_gd->enigme.doorDigicode.value[0] == _gd->enigme.doorDigicode.valueCode[0]
		&& _gd->enigme.doorDigicode.value[1] == _gd->enigme.doorDigicode.valueCode[1]
		&& _gd->enigme.doorDigicode.value[2] == _gd->enigme.doorDigicode.valueCode[2]
		&& _gd->enigme.doorDigicode.value[3] == _gd->enigme.doorDigicode.valueCode[3])
	{
		for (int i = 0; i < _gd->mapIntro->nbDestructible; i++)
		{
			if (!strcmp(_gd->mapIntro->mapDestructible[i].name, "code"))
			{
				_gd->mapIntro->mapDestructible[i].active = sfFalse;
			}
		}

		//si bug a check

		_gd->inGameState = cutscene;
		_gd->cutSceneState = vaisseauOpenDoor;
		_gd->enigmeState = none;
		InitCutScene(_gd);
		_gd->player.interaction = sfFalse;
		_gd->enigme.doorDigicode.resolvedIntro = sfTrue;
		DeleteMastermindIntroSprite(_gd);
		DeleteTutoMastermindIntroSprite(_gd);
	}

	_gd->enigme.doorDigicode.current++;

	if (_gd->enigme.doorDigicode.current > _gd->enigme.doorDigicode.state[_gd->enigmeState])
	{
		_gd->enigme.doorDigicode.current = 0;
	}

}

void ChoiceNumberIntro(GameData* _gd, int i)
{
	int value = i;
	if (i > NB_DIGICODE - 1)
	{
		value -= NB_DIGICODE;
		_gd->enigme.doorDigicode.value[value]--;
		if (_gd->enigme.doorDigicode.value[value] < _gd->enigme.doorDigicode.valueMin)
		{
			_gd->enigme.doorDigicode.value[value] = _gd->enigme.doorDigicode.valueMax;
		}
	}
	else
	{
		_gd->enigme.doorDigicode.value[value]++;
		if (_gd->enigme.doorDigicode.value[value] > _gd->enigme.doorDigicode.valueMax)
		{
			_gd->enigme.doorDigicode.value[value] = _gd->enigme.doorDigicode.valueMin;
		}
	}
}
