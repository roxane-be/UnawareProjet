#include "UpdatePuzzleJungle.h"

int GetIdPiecePuzzleJungle(GameData* _gd, sfVector2f _mouse)
{
	for (int i = 0; i < NB_PIECE_JUNGLE; i++)
	{
		if (isCollidingWithMouse(_gd->enigme.puzzleJungle.pieceJungle[i].forme, _mouse, 0))
		{
			return _gd->enigme.puzzleJungle.pieceJungle[i].identifiant;
		}
	}
	return -1;
}

int GetIdPuzzleJungle(GameData* _gd, sfVector2f _mouse)
{
	for (int i = 0; i < NB_PIECEPUZZLE_JUNGLE; i++)
	{
		if (isCollidingWithMouse(_gd->enigme.puzzleJungle.piecePuzzleJungle[i].forme, _mouse, 0))
		{
			return _gd->enigme.puzzleJungle.piecePuzzleJungle[i].identifiant;
		}
	}
	return -1;
}

void ValidatePuzzle(GameData* _gd, int _indice)
{
	if (_indice == 4)
	{
		//_gd->enigme.puzzleJungle.resolvedPuzzleJungle = sfTrue;
		_gd->enigme.puzzleJungle.puzzleAllumer = sfTrue;
	}
	if (_gd->enigme.puzzleJungle.piecePuzzleJungle[_indice].isOccupied == sfTrue)
	{
		if (_gd->enigme.puzzleJungle.piecePuzzleJungle[_indice].isUntouchable == sfTrue)
		{
			switch (_indice)
			{
			case 0:
				ValidatePuzzle(_gd, _indice + 1);
				break;
			case 3:
				ValidatePuzzle(_gd, _indice + 1);
				break;
			case 6:
				ValidatePuzzle(_gd, _indice - 1);
				break;
			case 11:
				ValidatePuzzle(_gd, _indice + 5);
				break;
			case 7:
				ValidatePuzzle(_gd, _indice + 1);
				break;
				/*	case 13:
						printf("mur!!!!!!!!!!!!!!!!!!!!!!!!!!");
						break;
					case 15:
						printf("mur!!!!!!!!!!!!!!!!!!!!!!!!!!");
						break;*/
			default:
				break;
			}
		}
		else if (_gd->enigme.puzzleJungle.piecePuzzleJungle[_indice].isUntouchable == sfFalse)
		{
			if (_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[_indice].idPiece].typeTuyau == tuyauDroit)
			{
				if (_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[_indice].idPiece].rotationPiece == vertical)
				{
					ValidatePuzzle(_gd, _indice - 5);
				}
			}
			else
			{
				if (_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[_indice].idPiece].rotationPiece == sudOuest)
				{
					ValidatePuzzle(_gd, _indice + 5);
				}
				else if (_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[_indice].idPiece].rotationPiece == sudEst)
				{
					ValidatePuzzle(_gd, _indice + 5);
				}
				else if (_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[_indice].idPiece].rotationPiece == nordEst)
				{
					if (_indice + 1 != 6)
					{
						ValidatePuzzle(_gd, _indice + 1);

					}
				}
				else if (_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[_indice].idPiece].rotationPiece == nordOuest)
				{
					ValidatePuzzle(_gd, _indice - 5);
				}
			}
		}
	}
}

void UpdatePuzzleJungle(GameData* _gd)
{
	sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouseF = { posMouse.x, posMouse.y };

	if (_gd->enigme.puzzleJungle.puzzleAllumer == sfTrue)
	{
		if (_gd->enigme.puzzleJungle.laserOnPuzzleSound.isPlaying == sfFalse)
		{
			_gd->enigme.puzzleJungle.laserOnPuzzleSound.isPlaying = sfTrue;
			sfSound_play(_gd->enigme.puzzleJungle.laserOnPuzzleSound.sound);
		}
		_gd->enigme.puzzleJungle.timerPuzzle += 0.03f;

		if (_gd->enigme.puzzleJungle.timerPuzzle > 5.0f)
		{
			_gd->enigme.puzzleJungle.resolvedPuzzleJungle = sfTrue;
			_gd->inGameState = exploration;
			_gd->enigmeState = none;
			sfSound_play(_gd->sucessSound.sound);
			
		}
		
	}

	if (_gd->enigme.puzzleJungle.resolvedPuzzleJungle == sfFalse)
	{
		if (_gd->enigme.puzzleJungle.isSelected == sfTrue)
		{
			sfVector2f tempPos = { posMouseF.x - 100, posMouseF.y - 100 };
			sfRectangleShape_setPosition(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].forme, tempPos);

		}

		if (isCollidingWithMouse(_gd->enigme.puzzleJungle.quitPuzzleJungle.forme, posMouseF, 0))
		{
			_gd->enigme.puzzleJungle.onSpriteQuitPuzzleJungle = sfTrue;
		}
		else
		{
			_gd->enigme.puzzleJungle.onSpriteQuitPuzzleJungle = sfFalse;
		}

		if (isCollidingWithMouse(_gd->enigme.puzzleJungle.aidePuzzleJungle.forme, posMouseF, 0))
		{
			_gd->enigme.puzzleJungle.onSpriteAidePuzzleJungle = sfTrue;
		}
		else
		{
			_gd->enigme.puzzleJungle.onSpriteAidePuzzleJungle = sfFalse;
		}


		if (isCollidingWithMouse(_gd->enigme.puzzleJungle.resetPuzzleJungle.forme, posMouseF, 0))
		{
			_gd->enigme.puzzleJungle.onSpriteResetPuzzleJungle = sfTrue;
		}
		else
		{
			_gd->enigme.puzzleJungle.onSpriteResetPuzzleJungle = sfFalse;
		}


		if (isCollidingWithMouse(_gd->enigme.puzzleJungle.validatePuzzleJungle.forme, posMouseF, 0))
		{
			_gd->enigme.puzzleJungle.onSpriteValidatePuzzleJungle = sfTrue;
		}
		else
		{
			_gd->enigme.puzzleJungle.onSpriteValidatePuzzleJungle = sfFalse;
		}
	}
	
}