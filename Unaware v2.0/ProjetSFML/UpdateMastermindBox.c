#include "UpdateMastermindBox.h"

void UpdateAnimationButtonMastermindBox(GameData* _gd, int _idArrow)
{
	_gd->enigme.houseBox.arrowBox[_idArrow].currentTime += _gd->frameRate.dt / 10.f;

	float totalTime = _gd->enigme.houseBox.arrowBox[_idArrow].sequence[_gd->enigme.houseBox.arrowBox[_idArrow].idSeq].total;
	int start = _gd->enigme.houseBox.arrowBox[_idArrow].sequence[_gd->enigme.houseBox.arrowBox[_idArrow].idSeq].begin;
	int end = _gd->enigme.houseBox.arrowBox[_idArrow].sequence[_gd->enigme.houseBox.arrowBox[_idArrow].idSeq].end;
	int nbAnim = 1 + (end - start);

	_gd->enigme.houseBox.arrowBox[_idArrow].currentAnim = nbAnim * _gd->enigme.houseBox.arrowBox[_idArrow].currentTime / totalTime + start;

	if (_gd->enigme.houseBox.arrowBox[_idArrow].currentTime >=
		_gd->enigme.houseBox.arrowBox[_idArrow].sequence[_gd->enigme.houseBox.arrowBox[_idArrow].idSeq].total)
	{
		ChoiceNumberBox(_gd, _idArrow);
		_gd->enigme.houseBox.arrowBox[_idArrow].idSeq = 1;
		_gd->enigme.houseBox.arrowBox[_idArrow].currentTime = 0.f;
		_gd->enigme.houseBox.arrowBox[_idArrow].isClicked = sfFalse;
		if (_idArrow < 4)
		{
			_gd->enigme.houseBox.arrowBox[_idArrow].currentAnim = 3;
		}
		else
		{
			_gd->enigme.houseBox.arrowBox[_idArrow].currentAnim = 0;
		}
	}
}

void isValidateBox(struct GameData* _gd)
{
	int currentI = _gd->enigme.houseBox.current;
	int currentJ = 0;
	_gd->enigme.houseBox.nbDiodeGreen = 0;
	_gd->enigme.houseBox.nbDiodeYellow = 0;

	int tab[1][4];
	for (int j = 0; j < NB_DIGICODE; j++)
	{
		tab[0][j] = _gd->enigme.houseBox.tabTry[0][j];
	}

	if (_gd->enigme.houseBox.current > (_gd->enigme.houseBox.state[_gd->enigmeState] - 1))
	{
		for (int i = 0; i < _gd->enigme.houseBox.state[_gd->enigmeState] - 1; i++)
		{
			for (int j = 0; j < NB_DIGICODE; j++)
			{
				_gd->enigme.houseBox.tabTry[i][j] = _gd->enigme.houseBox.tabTry[i + 1][j];

			}
			for (int k = 0; k < NB_DIGICODE; k++)
			{
				_gd->enigme.houseBox.diodeGreen[i][k] = _gd->enigme.houseBox.diodeGreen[i + 1][k];
				_gd->enigme.houseBox.diodeGreen[_gd->enigme.houseBox.current][k] = sfFalse;
			}

			for (int k = 0; k < NB_DIGICODE; k++)
			{
				_gd->enigme.houseBox.diodeYellow[i][k] = _gd->enigme.houseBox.diodeYellow[i + 1][k];
				_gd->enigme.houseBox.diodeYellow[_gd->enigme.houseBox.current][k] = sfFalse;
			}
		}

		_gd->enigme.houseBox.current--;
		currentI--;

		for (int k = 0; k < NB_DIGICODE; k++)
		{
			_gd->enigme.houseBox.diodeGreen[_gd->enigme.houseBox.current][k] = sfFalse;
		}

		for (int k = 0; k < NB_DIGICODE; k++)
		{
			_gd->enigme.houseBox.diodeYellow[_gd->enigme.houseBox.current][k] = sfFalse;
		}
	}

	_gd->enigme.houseBox.nbDiodeGreen = 0;
	_gd->enigme.houseBox.nbDiodeYellow = 0;

	if (_gd->enigme.houseBox.isFull == sfFalse)
	{
		for (int j = 0; j < NB_DIGICODE; j++)
		{

			_gd->enigme.houseBox.tabTry[currentI][j] = _gd->enigme.houseBox.value[j];
			_gd->enigme.houseBox.duplicate[j].value = _gd->enigme.houseBox.value[j];

			if (_gd->enigme.houseBox.value[j] == _gd->enigme.houseBox.valueCode[0]
				|| _gd->enigme.houseBox.value[j] == _gd->enigme.houseBox.valueCode[1]
				|| _gd->enigme.houseBox.value[j] == _gd->enigme.houseBox.valueCode[2]
				|| _gd->enigme.houseBox.value[j] == _gd->enigme.houseBox.valueCode[3])
			{
				if (_gd->enigme.houseBox.value[j] == _gd->enigme.houseBox.valueCode[j])
				{
					_gd->enigme.houseBox.nbDiodeGreen++;
					currentJ++;
					for (int i = 0; i < j; i++)
					{
						if (_gd->enigme.houseBox.duplicate[j].value == _gd->enigme.houseBox.value[i] &&
							_gd->enigme.houseBox.nbDiodeYellow > 0)
						{
							_gd->enigme.houseBox.nbDiodeYellow--;
						}
					}
				}
				else
				{
					_gd->enigme.houseBox.nbDiodeYellow++;
					currentJ++;
					for (int i = 0; i < j; i++)
					{
						if (_gd->enigme.houseBox.duplicate[j].value == _gd->enigme.houseBox.value[i])
						{
							if (_gd->enigme.houseBox.nbDiodeYellow > 0)
							{
								_gd->enigme.houseBox.nbDiodeYellow--;
								i = j;
							}
						}
						
					}
				}
			}
		}
	}

	for (int k = 0; k < _gd->enigme.houseBox.nbDiodeGreen; k++)
	{
		_gd->enigme.houseBox.diodeGreen[_gd->enigme.houseBox.current][k] = sfTrue;
	}

	for (int k = _gd->enigme.houseBox.nbDiodeGreen; k < _gd->enigme.houseBox.nbDiodeYellow + _gd->enigme.houseBox.nbDiodeGreen; k++)
	{
		_gd->enigme.houseBox.diodeYellow[_gd->enigme.houseBox.current][k] = sfTrue;
	}

	if (_gd->enigme.houseBox.value[0] == _gd->enigme.houseBox.valueCode[0]
		&& _gd->enigme.houseBox.value[1] == _gd->enigme.houseBox.valueCode[1]
		&& _gd->enigme.houseBox.value[2] == _gd->enigme.houseBox.valueCode[2]
		&& _gd->enigme.houseBox.value[3] == _gd->enigme.houseBox.valueCode[3])
	{
		//a modifier les gamestate pour la box
		sfSound_play(_gd->enigme.doorDigicode.validSound.sound);
		_gd->enigme.houseBox.boiteOuverte = sfTrue;

	}
	else
	{
		sfSound_play(_gd->enigme.doorDigicode.errorSound.sound);
	}

	_gd->enigme.houseBox.current++;

	if (_gd->enigme.houseBox.current == 6)
	{
		for (int j = 0; j < NB_DIGICODE; j++)
		{
			_gd->enigme.houseBox.tabTry[0][j] = tab[0][j];
		}
	}
}

void ChoiceNumberBox(struct GameData* _gameData, int i)
{
	int value = i;
	if (i > NB_DIGICODE - 1)
	{
		value -= NB_DIGICODE;
		_gameData->enigme.houseBox.value[value]--;
		if (_gameData->enigme.houseBox.value[value] < _gameData->enigme.houseBox.valueMin)
		{
			_gameData->enigme.houseBox.value[value] = _gameData->enigme.houseBox.valueMax;
		}
	}
	else
	{
		_gameData->enigme.houseBox.value[value]++;
		if (_gameData->enigme.houseBox.value[value] > _gameData->enigme.houseBox.valueMax)
		{
			_gameData->enigme.houseBox.value[value] = _gameData->enigme.houseBox.valueMin;
		}
	}
}

void UpdateButtonHelpMastermindBox(GameData* _gd)
{
	sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouse2f = { posMouse.x,posMouse.y };

	//Bouton Aide
	if (isCollidingWithMouse(_gd->enigme.houseBox.buttonHelpMastermindBox.forme, posMouse2f, 0))
	{
		_gd->enigme.houseBox.onSpriteHelpMastermindBox = sfTrue;
	}
	else
	{
		_gd->enigme.houseBox.onSpriteHelpMastermindBox = sfFalse;
	}

	//Bouton Valider
	if (isCollidingWithMouse(_gd->enigme.houseBox.buttonValidateBox.forme, posMouse2f, 0))
	{
		_gd->enigme.houseBox.onSpriteValidateBox = sfTrue;
	}
	else
	{
		_gd->enigme.houseBox.onSpriteValidateBox = sfFalse;
	}
}