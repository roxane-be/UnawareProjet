#include "InputPuzzleJungle.h"

void InputPuzzleJungle(GameData* _gd)
{
	sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouseF = { posMouse.x, posMouse.y };

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		//on pose les pieces
		if (_gd->event.mouseButton.button == sfMouseLeft
			&& _gd->enigme.puzzleJungle.isSelected == sfTrue)
		{
			_gd->enigme.puzzleJungle.idCurrentPuzzle = GetIdPuzzleJungle(_gd, posMouseF);

			if (_gd->enigme.puzzleJungle.idCurrentPuzzle != -1)
			{
				if (IsCollidingRectangleRectangle(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].forme,
					_gd->enigme.puzzleJungle.piecePuzzleJungle[_gd->enigme.puzzleJungle.idCurrentPuzzle].forme))
				{
					if (_gd->enigme.puzzleJungle.piecePuzzleJungle[_gd->enigme.puzzleJungle.idCurrentPuzzle].isOccupied == sfFalse)
					{
						sfRectangleShape_setPosition(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].forme,
							_gd->enigme.puzzleJungle.piecePuzzleJungle[_gd->enigme.puzzleJungle.idCurrentPuzzle].pos);
						_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].isPosed = sfTrue;
						_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].isInPuzzle = sfTrue;
						_gd->enigme.puzzleJungle.piecePuzzleJungle[_gd->enigme.puzzleJungle.idCurrentPuzzle].isOccupied = sfTrue;
						_gd->enigme.puzzleJungle.piecePuzzleJungle[_gd->enigme.puzzleJungle.idCurrentPuzzle].idPiece = _gd->enigme.puzzleJungle.idCurrentPiece;

					}
					else
					{
						sfRectangleShape_setPosition(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].forme,
							_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].pos);
					}
					sfSound_play(_gd->enigme.puzzleJungle.placePuzzleSound.sound);

				}
			}
			else
			{
				sfRectangleShape_setPosition(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].forme,
					_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].pos);
				sfSound_play(_gd->enigme.puzzleJungle.placePuzzleSound.sound);
			}
			_gd->enigme.puzzleJungle.isSelected = sfFalse;
		}
		//on prend les pieces
		else if (_gd->event.mouseButton.button == sfMouseLeft
			&& _gd->enigme.puzzleJungle.isSelected == sfFalse)
		{
			_gd->enigme.puzzleJungle.idCurrentPiece = GetIdPiecePuzzleJungle(_gd, posMouseF);

			if (_gd->enigme.puzzleJungle.idCurrentPiece < NB_PIECE_JUNGLE
				&& _gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].isVisible == sfTrue
				&& _gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].isInPuzzle == sfFalse)
			{
				if (isCollidingWithMouse(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].forme, posMouseF, 0))
				{
					if (_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].isPosed == sfTrue)
					{
						_gd->enigme.puzzleJungle.isSelected = sfTrue;
						sfSound_play(_gd->enigme.puzzleJungle.placePuzzleSound.sound);
					}
				}
			}
			else if (_gd->enigme.puzzleJungle.idCurrentPiece < NB_PIECE_JUNGLE
				&& _gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].isVisible == sfTrue
				&& _gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].isInPuzzle == sfTrue)
			{
				if (isCollidingWithMouse(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].forme, posMouseF, 0))
				{
					if (_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].isPosed == sfTrue)
					{
						_gd->enigme.puzzleJungle.idCurrentPuzzle = GetIdPuzzleJungle(_gd, posMouseF);

						_gd->enigme.puzzleJungle.isSelected = sfTrue;
						_gd->enigme.puzzleJungle.piecePuzzleJungle[_gd->enigme.puzzleJungle.idCurrentPuzzle].isOccupied = sfFalse;
						_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].isInPuzzle = sfFalse;
						sfSound_play(_gd->enigme.puzzleJungle.placePuzzleSound.sound);
					}
				}
			}
		}

		if (_gd->event.mouseButton.button == sfMouseRight
			&& _gd->enigme.puzzleJungle.isSelected == sfFalse)
		{
			_gd->enigme.puzzleJungle.idCurrentPiece = GetIdPiecePuzzleJungle(_gd, posMouseF);
			_gd->enigme.puzzleJungle.idCurrentPuzzle = GetIdPuzzleJungle(_gd, posMouseF);

			if (_gd->enigme.puzzleJungle.idCurrentPiece < NB_PIECE_JUNGLE
				&& _gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].isVisible == sfTrue
				&& _gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].isInPuzzle == sfTrue)
			{
				if (isCollidingWithMouse(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].forme, posMouseF, 0))
				{
					if (_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].isPosed == sfTrue)
					{
						sfRectangleShape_setPosition(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].forme,
							_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].pos);
						_gd->enigme.puzzleJungle.piecePuzzleJungle[_gd->enigme.puzzleJungle.idCurrentPuzzle].isOccupied = sfFalse;
						_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].isInPuzzle = sfFalse;
						sfSound_play(_gd->enigme.puzzleJungle.placePuzzleSound.sound);
					}
				}
			}
		}

		// on tourne les pièces
		else if (_gd->event.mouseButton.button == sfMouseRight
			&& _gd->enigme.puzzleJungle.isSelected == sfTrue)
		{
			sfSound_play(_gd->enigme.puzzleJungle.rotatePuzzleSound.sound);
			switch (_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].rotationPiece)
			{
			case vertical:
				_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].rotationPiece = horizontal;
				break;
			case horizontal:
				_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].rotationPiece = vertical;
				break;
			case sudEst:
				_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].rotationPiece = sudOuest;
				break;
			case sudOuest:
				_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].rotationPiece = nordOuest;
				break;
			case nordOuest:
				_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].rotationPiece = nordEst;
				break;
			case nordEst:
				_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].rotationPiece = sudEst;
				break;
			default:
				break;
			}
		}

		//gestion des boutons
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->enigme.puzzleJungle.onSpriteValidatePuzzleJungle = sfFalse;
			_gd->enigme.puzzleJungle.onSpriteResetPuzzleJungle = sfFalse;
			_gd->enigme.puzzleJungle.onSpriteQuitPuzzleJungle = sfFalse;
			_gd->enigme.puzzleJungle.onSpriteAidePuzzleJungle = sfFalse;


			if (isCollidingWithMouse(_gd->enigme.puzzleJungle.validatePuzzleJungle.forme, posMouseF, 0))
			{
				_gd->enigme.puzzleJungle.clickValidatePuzzleJungle = sfTrue;
			}
			if (isCollidingWithMouse(_gd->enigme.puzzleJungle.resetPuzzleJungle.forme, posMouseF, 0))
			{
				_gd->enigme.puzzleJungle.clickResetPuzzleJungle = sfTrue;
			}
			if (isCollidingWithMouse(_gd->enigme.puzzleJungle.quitPuzzleJungle.forme, posMouseF, 0))
			{
				_gd->enigme.puzzleJungle.clickQuitPuzzleJungle = sfTrue;
			}
			if (isCollidingWithMouse(_gd->enigme.puzzleJungle.aidePuzzleJungle.forme, posMouseF, 0))
			{
				_gd->enigme.puzzleJungle.clickAidePuzzleJungle = sfTrue;
			}
		}

	}
	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->enigme.puzzleJungle.clickValidatePuzzleJungle = sfFalse;
			_gd->enigme.puzzleJungle.clickResetPuzzleJungle = sfFalse;
			_gd->enigme.puzzleJungle.clickQuitPuzzleJungle = sfFalse;
			_gd->enigme.puzzleJungle.clickAidePuzzleJungle = sfFalse;

			if (isCollidingWithMouse(_gd->enigme.puzzleJungle.validatePuzzleJungle.forme, posMouseF, 0))
			{
				ValidatePuzzle(_gd, 0);
				if (_gd->enigme.puzzleJungle.puzzleAllumer == sfFalse)
				{
					sfSound_play(_gd->errorSound.sound);
				}
			}

			if (isCollidingWithMouse(_gd->enigme.puzzleJungle.resetPuzzleJungle.forme, posMouseF, 0))
			{
				if (sfSound_getStatus(_gd->enigme.puzzleJungle.placePuzzleSound.sound) == sfStopped)
				{
					sfSound_play(_gd->enigme.puzzleJungle.placePuzzleSound.sound);
				}

				for (int i = 0; i < NB_PIECE_JUNGLE; i++)
				{
					sfRectangleShape_setPosition(_gd->enigme.puzzleJungle.pieceJungle[i].forme,
						_gd->enigme.puzzleJungle.pieceJungle[i].pos);
					_gd->enigme.puzzleJungle.pieceJungle[i].isInPuzzle = sfFalse;

					if (_gd->enigme.puzzleJungle.pieceJungle[i].typeTuyau == tuyauDroit)
					{
						_gd->enigme.puzzleJungle.pieceJungle[i].rotationPiece = vertical;
					}
					else
					{
						_gd->enigme.puzzleJungle.pieceJungle[i].rotationPiece = sudEst;
					}

				}
				for (int i = 0; i < NB_PIECEPUZZLE_JUNGLE; i++)
				{
					if (i != 0 && i != 2 && i != 3 && i != 4
						&& i != 0 && i != 6 && i != 7 && i != 11
						&& i != 13 && i != 15)
						_gd->enigme.puzzleJungle.piecePuzzleJungle[i].isOccupied = sfFalse;
				}
			}
			if (isCollidingWithMouse(_gd->enigme.puzzleJungle.quitPuzzleJungle.forme, posMouseF, 0))
			{
				_gd->inGameState = exploration;
				_gd->enigmeState = none;
			}
			if (isCollidingWithMouse(_gd->enigme.puzzleJungle.aidePuzzleJungle.forme, posMouseF, 0))
			{
				_gd->inGameState = tuto;
				sfSound_play(_gd->helpSound.sound);
			}
		}
	}
}