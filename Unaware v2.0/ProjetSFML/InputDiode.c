#include "InputDiode.h"

int VerifInterupteurSymbole(int _i, int _j)
{
	return (_i == 0 && _j == 1) || (_i == 0 && _j == 3)
		|| (_i == 1 && _j == 3) || (_i == 2 && _j == 3)
		|| (_i == 2 && _j == 2) || (_i == 3 && _j == 2);
}

void EffetInterupteur(GameData* _gd, int _i, int _j)
{
	_gd->enigme.interupteur.etat[_i][_j] *= -off;

	if (_gd->enigme.interupteur.etat[_i][_j] == 1)
	{
		sfSound_play(_gd->enigme.interupteur.fireflyOn.sound);
	}
	else
	{
		sfSound_play(_gd->enigme.interupteur.fireflyOff.sound);
	}

	if (_i != _gd->enigme.interupteur.sizeTab.x - 1)
	{
		_gd->enigme.interupteur.etat[_i + 1][_j] *= -off;
	}
	if (_j != _gd->enigme.interupteur.sizeTab.y - 1)
	{
		_gd->enigme.interupteur.etat[_i][_j + 1] *= -off;
	}
	if (_i != 0)
	{
		_gd->enigme.interupteur.etat[_i - 1][_j] *= -off;
	}
	if (_j != 0)
	{
		_gd->enigme.interupteur.etat[_i][_j - 1] *= -off;
	}
}

void InputDiode(GameData* _gd)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouse = { mouse.x,mouse.y };

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft) //Clic gauche
		{
			if (_gd->enigme.interupteur.interupteurState == tutoDiode)
			{
				if (isCollidingWithMouse(_gd->enigme.interupteur.helpButtonDiode3x3.forme, posMouse, 0))
				{
					_gd->enigme.interupteur.clickHelpButtonDiode3x3 = sfTrue;
				}
			}
			else if (_gd->enigme.interupteur.interupteurState == symboleDiode)
			{
				if (isCollidingWithMouse(_gd->enigme.interupteur.helpButtonDiodeSymbole.forme, posMouse, 0))
				{
					_gd->enigme.interupteur.clickHelpButtonDiodeSymbole = sfTrue;
				}
				if (isCollidingWithMouse(_gd->enigme.interupteur.symboleButtonDiode.forme, posMouse, 0))
				{
					_gd->enigme.interupteur.clickSymboleButtonDiode = sfTrue;
				}
			}
			else if (_gd->enigme.interupteur.interupteurState == fullDiode)
			{
				if (isCollidingWithMouse(_gd->enigme.interupteur.helpButtonDiodeFin.forme, posMouse, 0))
				{
					_gd->enigme.interupteur.clickHelpButtonDiodeFin = sfTrue;
				}
			}

			for (int i = 0; i < _gd->enigme.interupteur.sizeTab.x; i++)
			{
				for (int j = 0; j < _gd->enigme.interupteur.sizeTab.y; j++)
				{
					if (isCollidingWithMouse(_gd->enigme.interupteur.rectInterupteur[i][j], posMouse, 1))
					{
						EffetInterupteur(_gd, i, j);
					}
				}
			}

			if (isCollidingWithMouse(_gd->enigme.interupteur.validateButtonDiode.forme, posMouse, 0))
			{
				_gd->enigme.interupteur.clickValidateButtonDiode = sfTrue;
			}


			if (isCollidingWithMouse(_gd->enigme.interupteur.quitButtonDiode.forme, posMouse, 1))
			{
				sfSound_play(_gd->enigme.interupteur.fireflyQuit.sound);
				_gd->enigme.interupteur.clickQuitButtonDiode = sfTrue;
			}

			if (isCollidingWithMouse(_gd->enigme.interupteur.resetButtonDiode.forme, posMouse, 0))
			{
				_gd->enigme.interupteur.clickResetButtonDiode = sfTrue;
			}

		}
	}
	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->enigme.interupteur.clickValidateButtonDiode = sfFalse;
			_gd->enigme.interupteur.clickQuitButtonDiode = sfFalse;
			_gd->enigme.interupteur.clickResetButtonDiode = sfFalse;

			if (_gd->enigme.interupteur.interupteurState == tutoDiode)
			{
				_gd->enigme.interupteur.clickHelpButtonDiode3x3 = sfFalse;

				if (isCollidingWithMouse(_gd->enigme.interupteur.helpButtonDiode3x3.forme, posMouse, 0))
				{
					sfSound_play(_gd->enigme.interupteur.fireflyInstruction.sound);
					_gd->inGameState = tuto;
				}

			}
			else if (_gd->enigme.interupteur.interupteurState == symboleDiode)
			{
				_gd->enigme.interupteur.clickHelpButtonDiodeSymbole = sfFalse;
				_gd->enigme.interupteur.clickSymboleButtonDiode = sfFalse;

				if (isCollidingWithMouse(_gd->enigme.interupteur.helpButtonDiodeSymbole.forme, posMouse, 0))
				{
					sfSound_play(_gd->enigme.interupteur.fireflyInstruction.sound);
					_gd->inGameState = tuto;
				}
				if (isCollidingWithMouse(_gd->enigme.interupteur.symboleButtonDiode.forme, posMouse, 0))
				{
					sfSound_play(_gd->enigme.interupteur.fireflyInstruction.sound);
					_gd->inGameState = symbole;
				}

			}
			else if (_gd->enigme.interupteur.interupteurState == fullDiode)
			{
				_gd->enigme.interupteur.clickHelpButtonDiodeFin = sfFalse;

				if (isCollidingWithMouse(_gd->enigme.interupteur.helpButtonDiodeFin.forme, posMouse, 0))
				{
					sfSound_play(_gd->enigme.interupteur.fireflyInstruction.sound);
					_gd->inGameState = tuto;
				}
			}

			if (isCollidingWithMouse(_gd->enigme.interupteur.validateButtonDiode.forme, posMouse, 0))
			{
				int compteur = 0;
				//si on divise comme le mastermind, j'espere que ça va marcher
				//sinon la malédiction du mastermind va nous suivre jusqu'à la jungle  
				if (_gd->enigme.interupteur.interupteurState != symboleDiode)
				{
					for (int i = 0; i < _gd->enigme.interupteur.sizeTab.x; i++)
					{
						for (int j = 0; j < _gd->enigme.interupteur.sizeTab.y; j++)
						{
							if (_gd->enigme.interupteur.etat[i][j] == on)
							{
								compteur++;
							}
						}
					}
					if (_gd->enigme.interupteur.sizeTab.x * _gd->enigme.interupteur.sizeTab.y == compteur
						&& _gd->enigme.interupteur.interupteurState == tutoDiode)
					{
						sfSound_play(_gd->sucessSound.sound);
						_gd->inGameState = exploration;
						_gd->enigmeState = none;
						_gd->enigme.interupteur.diodeFini[tutoDiode] = sfTrue;

						if (_gd->enigme.interupteur.diodeFini[tutoDiode] == sfTrue
							&& _gd->enigme.interupteur.diodeFini[symboleDiode] == sfTrue
							&& _gd->enigme.interupteur.diodeFini[fullDiode] == sfTrue)
						{
							_gd->enigme.interupteur.diodeResolved = sfTrue;
							_gd->enigme.decryptage.TwoPaper = sfTrue;
							_gd->enigme.decryptage.InRecup = sfTrue;
							_gd->enigme.decryptage.nbPaperRecup++;
							_gd->enigme.decryptage.nbPaperRecup++;
							_gd->enigme.decryptage.isVisible[7] = sfTrue;
							_gd->enigme.decryptage.isVisible[8] = sfTrue;
							DeleteDiodeJungle(_gd);
						}
					}
					else if (_gd->enigme.interupteur.sizeTab.x * _gd->enigme.interupteur.sizeTab.y == compteur
						&& _gd->enigme.interupteur.interupteurState == fullDiode)
					{
						sfSound_play(_gd->sucessSound.sound);
						_gd->inGameState = exploration;
						_gd->enigmeState = none;
						_gd->enigme.interupteur.diodeFini[fullDiode] = sfTrue;

						if (_gd->enigme.interupteur.diodeFini[tutoDiode] == sfTrue
							&& _gd->enigme.interupteur.diodeFini[symboleDiode] == sfTrue
							&& _gd->enigme.interupteur.diodeFini[fullDiode] == sfTrue)
						{
							_gd->enigme.interupteur.diodeResolved = sfTrue;
							_gd->enigme.decryptage.TwoPaper = sfTrue;
							_gd->enigme.decryptage.nbPaperRecup++;
							_gd->enigme.decryptage.nbPaperRecup++;
							_gd->enigme.decryptage.isVisible[7] = sfTrue;
							_gd->enigme.decryptage.isVisible[8] = sfTrue;
							_gd->enigme.decryptage.InRecup = sfTrue;
							DeleteDiodeJungle(_gd);
						}
					}
					else
					{
						sfSound_play(_gd->enigme.interupteur.fireflyError.sound);
					}
				}
				else
				{
					int compteurOn = 0;
					for (int i = 0; i < _gd->enigme.interupteur.sizeTab.x; i++)
					{
						for (int j = 0; j < _gd->enigme.interupteur.sizeTab.y; j++)
						{
							if (_gd->enigme.interupteur.etat[i][j] == off
								&& VerifInterupteurSymbole(i, j))
							{
								compteur++;
							}
							else if (_gd->enigme.interupteur.etat[i][j] == on)
							{
								compteurOn++;
							}
						}
					}
					if (compteur == 6
						&& compteurOn == 10)
					{
						sfSound_play(_gd->sucessSound.sound);
						_gd->inGameState = exploration;
						_gd->enigmeState = none;
						_gd->enigme.interupteur.diodeFini[symboleDiode] = sfTrue;

						if (_gd->enigme.interupteur.diodeFini[tutoDiode] == sfTrue
							&& _gd->enigme.interupteur.diodeFini[symboleDiode] == sfTrue
							&& _gd->enigme.interupteur.diodeFini[fullDiode] == sfTrue)
						{
							_gd->enigme.interupteur.diodeResolved = sfTrue;
							_gd->enigme.decryptage.TwoPaper = sfTrue;
							_gd->enigme.decryptage.nbPaperRecup++;
							_gd->enigme.decryptage.nbPaperRecup++;
							_gd->enigme.decryptage.isVisible[7] = sfTrue;
							_gd->enigme.decryptage.isVisible[8] = sfTrue;
							_gd->enigme.decryptage.InRecup = sfTrue;
							DeleteDiodeJungle(_gd);
						}
					}
					else
					{
						sfSound_play(_gd->enigme.interupteur.fireflyError.sound);
					}
				}
			}

			if (isCollidingWithMouse(_gd->enigme.interupteur.resetButtonDiode.forme, posMouse, 0))
			{
				sfSound_play(_gd->enigme.interupteur.fireflyInstruction.sound);
				for (int i = 0; i < _gd->enigme.interupteur.sizeTab.x; i++)
				{
					for (int j = 0; j < _gd->enigme.interupteur.sizeTab.y; j++)
					{
						_gd->enigme.interupteur.etat[i][j] = off;
						//pour faire le full a partir d'une grille déjà préremplis 
						if (_gd->enigme.interupteur.interupteurState == fullDiode)
						{
							//version presque fini 
							//_gd->enigme.interupteur.etat[0][0] = on;
							//_gd->enigme.interupteur.etat[0][2] = on;
							//_gd->enigme.interupteur.etat[0][4] = on;
							////
							//_gd->enigme.interupteur.etat[2][0] = on;
							//_gd->enigme.interupteur.etat[2][1] = on;
							//_gd->enigme.interupteur.etat[2][2] = on;
							//_gd->enigme.interupteur.etat[2][3] = on;
							//_gd->enigme.interupteur.etat[2][4] = on;
							////
							//_gd->enigme.interupteur.etat[3][1] = on;
							//_gd->enigme.interupteur.etat[3][2] = on;
							//_gd->enigme.interupteur.etat[3][4] = on;
							////
							//_gd->enigme.interupteur.etat[4][1] = on;
							//_gd->enigme.interupteur.etat[4][2] = on;
							//_gd->enigme.interupteur.etat[4][4] = on;
							////
							//_gd->enigme.interupteur.etat[5][0] = on;
							//_gd->enigme.interupteur.etat[5][1] = on;


							//version début
							_gd->enigme.interupteur.etat[0][0] = on;
							_gd->enigme.interupteur.etat[2][0] = on;

							_gd->enigme.interupteur.etat[1][2] = on;
							_gd->enigme.interupteur.etat[0][2] = on;
							_gd->enigme.interupteur.etat[0][4] = on;


							_gd->enigme.interupteur.etat[3][3] = on;
							_gd->enigme.interupteur.etat[5][1] = on;
						}
					}
				}
			}

			if (isCollidingWithMouse(_gd->enigme.interupteur.quitButtonDiode.forme, posMouse, 1))
			{
				DeleteDiodeJungle(_gd);
				_gd->inGameState = exploration;
				_gd->enigmeState = none;
			}

		}
	}
}