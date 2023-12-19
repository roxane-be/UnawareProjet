#include "InputPuzzle.h"

void InputPuzzle(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos = { 0, 0 };
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		//on pose la piece
		if (_gd->event.mouseButton.button == sfMouseLeft && _gd->enigme.utilityPuzzle.isSelected == 1)
		{
			_gd->enigme.utilityPuzzle.idPuzzle = GetIdPuzzle(_gd, tempPos);
			sfVector2f size = { _gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.idPuzzle].width,
				_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.idPuzzle].height };

			_gd->enigme.utilityPuzzle.isSelected = 0;

			if (_gd->enigme.utilityPuzzle.idPuzzle != -1)
			{
				if (IsCollidingRectangleRectangle(_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].forme,
					_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.idPuzzle].forme))
				{
					sfSound_play(_gd->enigme.utilityPuzzle.placePuzzleSound.sound);
					if (_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.idPuzzle].isOccupied == 0)
					{
						sfRectangleShape_setPosition(_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].forme,
							_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.idPuzzle].position);

						sfRectangleShape_setSize(_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].forme, size);
						_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isPosed = 1;
						_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.idPuzzle].isOccupied = 1;
						_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isInPuzzle = sfTrue;
						_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isOccupied = 0;
					}
					else
					{
						_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isOccupied = 0;
						sfRectangleShape_setPosition(_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].forme,
							_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].position);
					}
				}
			}
			else
			{
				sfRectangleShape_setPosition(_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].forme,
					_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].position);
				_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isOccupied = 0;
			}
		}
		//Selection des pieces
		else if (_gd->event.mouseButton.button == sfMouseLeft
			&& _gd->enigme.utilityPuzzle.isSelected == 0)
		{
			_gd->enigme.utilityPuzzle.idPiece = GetIdPiece(_gd, tempPos);
			if (_gd->enigme.utilityPuzzle.idPiece < 25
				&& _gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isVisible == sfTrue
				&& _gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isInPuzzle == sfFalse)
			{
				if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].forme, tempPos, 0))
				{
					if (_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isPosed == 0)
					{
						_gd->enigme.utilityPuzzle.isSelected = 1;
					}
				}
			}
			else if (_gd->enigme.utilityPuzzle.idPiece < NB_PIECES_PUZZLE_ILE * NB_PIECES_PUZZLE_ILE
				&& _gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isVisible == sfTrue
				&& _gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isInPuzzle == sfTrue)
			{
				if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].forme, tempPos, 0))
				{
					if (_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isPosed == 1)
					{
						_gd->enigme.utilityPuzzle.idPuzzle = GetIdPuzzle(_gd, tempPos);
						sfVector2f size = { 77,77 };
						sfRectangleShape_setSize(_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].forme, size);
						_gd->enigme.utilityPuzzle.isSelected = 1;
						_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isPosed = 0;
						_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.idPuzzle].isOccupied = 0;
						_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isInPuzzle = sfFalse;
					}
				}
			}
		}

		if (_gd->event.mouseButton.button == sfMouseRight
			&& _gd->enigme.utilityPuzzle.isSelected == 0)
		{
			_gd->enigme.utilityPuzzle.idPiece = GetIdPiece(_gd, tempPos);
			_gd->enigme.utilityPuzzle.idPuzzle = GetIdPuzzle(_gd, tempPos);
			if (_gd->enigme.utilityPuzzle.idPiece < 25)
			{
				if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].forme, tempPos, 0))
				{
					sfSound_play(_gd->enigme.utilityPuzzle.placePuzzleSound.sound);
					sfRectangleShape_setPosition(_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].forme,
						_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].position);

					sfRectangleShape_setSize(_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].forme, (sfVector2f) { 77, 77 });
					_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isPosed = 0;
					_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.idPuzzle].isOccupied = 0;
					_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isInPuzzle = sfFalse;
					_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isOccupied = 0;

				}
			}
		}

		//Les boutons
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.quit.forme, tempPos, 0))
			{
				_gd->enigme.utilityPuzzle.clickQuit = sfTrue;
			}
			if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.reset.forme, tempPos, 0))
			{
				_gd->enigme.utilityPuzzle.clickReset = sfTrue;
				sfSound_play(_gd->enigme.utilityPuzzle.resetPuzzleSound.sound);
				for (int i = 0; i < 25; i++)
				{
					sfRectangleShape_setPosition(_gd->enigme.utilityPuzzle.piece[i].forme,
						_gd->enigme.utilityPuzzle.piece[i].position);
					sfRectangleShape_setSize(_gd->enigme.utilityPuzzle.piece[i].forme, (sfVector2f) { 77, 77 });
					_gd->enigme.utilityPuzzle.piece[i].isPosed = 0;
					_gd->enigme.utilityPuzzle.piece[i].isInPuzzle = sfFalse;
					_gd->enigme.utilityPuzzle.puzzle[i].isOccupied = 0;
				}
			}
			if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.validate.forme, tempPos, 0))
			{
				_gd->enigme.utilityPuzzle.clickValidate = sfTrue;
				int wellPlaced = 0;

				for (int i = 0; i < 25; i++)
				{
					if (IsCollidingRectangleRectangle(_gd->enigme.utilityPuzzle.piece[i].forme,
						_gd->enigme.utilityPuzzle.puzzle[i].forme))
					{
						wellPlaced++;
					}
				}
				if (wellPlaced == 25)
				{
					for (int i = 0; i < _gd->mapIsland->nbDestructible; i++)
					{
						_gd->mapIsland->mapDestructible[i].active = sfFalse;
					}
					_gd->inGameState = cutscene;
					_gd->cutSceneState = islandPont;
					_gd->enigmeState = none;
					_gd->player.interaction = sfFalse;
					InitCutScene(_gd);

					_gd->enigme.utilityPuzzle.resolvedPuzzleDream_1 = sfTrue;
				}
				else
				{
					sfSound_play(_gd->errorSound.sound);
				}
			}

		}
	}

	//relachement du clique pour sprite + effet du bouton
	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->enigme.utilityPuzzle.clickQuit = sfFalse;
			_gd->enigme.utilityPuzzle.clickReset = sfFalse;
			_gd->enigme.utilityPuzzle.clickValidate = sfFalse;
			_gd->enigme.utilityPuzzle.clickHelp = sfFalse;

			//quitter uniquement au release
			if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.quit.forme, tempPos, 0))
			{
				_gd->inGameState = exploration;
				_gd->enigmeState = none;
			}
			if (isCollidingWithMouse(_gd->enigme.utilityPuzzle.help.forme, tempPos, 0))
			{
				//permet de switch dans le tuto de l'enigme
				sfSound_play(_gd->helpSound.sound);
				_gd->inGameState = tuto;
			}
		}
	}

	if (_gd->enigme.utilityPuzzle.isSelected == 1)
	{
		sfRectangleShape_setPosition(_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].forme, tempPos);
		_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.idPiece].isOccupied = 1;
	}

}