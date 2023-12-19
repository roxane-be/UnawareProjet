#include "DisplayPuzzleJungle.h"

void DisplayPuzzleRotation(GameData* _gd, int _i)
{
	switch (_gd->enigme.puzzleJungle.pieceJungle[_i].rotationPiece)
	{
	case vertical:
		_gd->enigme.puzzleJungle.pieceJungle[_i].sprite = _gd->enigme.puzzleJungle.spritePieceRotation[vertical];
		break;
	case horizontal:
		_gd->enigme.puzzleJungle.pieceJungle[_i].sprite = _gd->enigme.puzzleJungle.spritePieceRotation[horizontal];
		break;
	case sudEst:
		_gd->enigme.puzzleJungle.pieceJungle[_i].sprite = _gd->enigme.puzzleJungle.spritePieceRotation[sudEst];
		break;
	case sudOuest:
		_gd->enigme.puzzleJungle.pieceJungle[_i].sprite = _gd->enigme.puzzleJungle.spritePieceRotation[sudOuest];
		break;
	case nordEst:
		_gd->enigme.puzzleJungle.pieceJungle[_i].sprite = _gd->enigme.puzzleJungle.spritePieceRotation[nordEst];
		break;
	case nordOuest:
		_gd->enigme.puzzleJungle.pieceJungle[_i].sprite = _gd->enigme.puzzleJungle.spritePieceRotation[nordOuest];
		break;
	default:
		break;
	}
}

void DisplayButtonPuzzleJungle(GameData* _gd)
{
	//Bouton Valider
	BlitSprite(_gd->enigme.puzzleJungle.validatePuzzleJungle.buttonSprite[0], _gd->enigme.puzzleJungle.validatePuzzleJungle.pos.x - 30,
		_gd->enigme.puzzleJungle.validatePuzzleJungle.pos.y - 30, 0, 1, 1, _gd);

	if (_gd->enigme.puzzleJungle.onSpriteValidatePuzzleJungle == sfTrue
		&& _gd->enigme.puzzleJungle.clickValidatePuzzleJungle == sfFalse)
	{
		BlitSprite(_gd->enigme.puzzleJungle.validatePuzzleJungle.buttonSprite[1], _gd->enigme.puzzleJungle.validatePuzzleJungle.pos.x - 30,
			_gd->enigme.puzzleJungle.validatePuzzleJungle.pos.y - 30, 0, 1, 1, _gd);
	}
	if (_gd->enigme.puzzleJungle.clickValidatePuzzleJungle == sfTrue)
	{
		BlitSprite(_gd->enigme.puzzleJungle.validatePuzzleJungle.buttonSprite[2], _gd->enigme.puzzleJungle.validatePuzzleJungle.pos.x - 30,
			_gd->enigme.puzzleJungle.validatePuzzleJungle.pos.y - 30, 0, 1, 1, _gd);
	}
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.puzzleJungle.validatePuzzleJungle.forme, NULL);

	//Bouton Reset
	BlitSprite(_gd->enigme.puzzleJungle.resetPuzzleJungle.buttonSprite[0], _gd->enigme.puzzleJungle.resetPuzzleJungle.pos.x - 30,
		_gd->enigme.puzzleJungle.resetPuzzleJungle.pos.y - 30, 0, 1, 1, _gd);

	if (_gd->enigme.puzzleJungle.onSpriteResetPuzzleJungle == sfTrue
		&& _gd->enigme.puzzleJungle.clickResetPuzzleJungle == sfFalse)
	{
		BlitSprite(_gd->enigme.puzzleJungle.resetPuzzleJungle.buttonSprite[1], _gd->enigme.puzzleJungle.resetPuzzleJungle.pos.x - 30,
			_gd->enigme.puzzleJungle.resetPuzzleJungle.pos.y - 30, 0, 1, 1, _gd);
	}
	if (_gd->enigme.puzzleJungle.clickResetPuzzleJungle == sfTrue)
	{
		BlitSprite(_gd->enigme.puzzleJungle.resetPuzzleJungle.buttonSprite[2], _gd->enigme.puzzleJungle.resetPuzzleJungle.pos.x - 30,
			_gd->enigme.puzzleJungle.resetPuzzleJungle.pos.y - 30, 0, 1, 1, _gd);
	}
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.puzzleJungle.resetPuzzleJungle.forme, NULL);

	//Bouton Quitter
	BlitSprite(_gd->enigme.puzzleJungle.quitPuzzleJungle.buttonSprite[0], _gd->enigme.puzzleJungle.quitPuzzleJungle.pos.x - 30,
		_gd->enigme.puzzleJungle.quitPuzzleJungle.pos.y - 30, 0, 1, 1, _gd);

	if (_gd->enigme.puzzleJungle.onSpriteQuitPuzzleJungle == sfTrue
		&& _gd->enigme.puzzleJungle.clickQuitPuzzleJungle == sfFalse)
	{
		BlitSprite(_gd->enigme.puzzleJungle.quitPuzzleJungle.buttonSprite[1], _gd->enigme.puzzleJungle.quitPuzzleJungle.pos.x - 30,
			_gd->enigme.puzzleJungle.quitPuzzleJungle.pos.y - 30, 0, 1, 1, _gd);
	}
	if (_gd->enigme.puzzleJungle.clickQuitPuzzleJungle == sfTrue)
	{
		BlitSprite(_gd->enigme.puzzleJungle.quitPuzzleJungle.buttonSprite[2], _gd->enigme.puzzleJungle.quitPuzzleJungle.pos.x - 30,
			_gd->enigme.puzzleJungle.quitPuzzleJungle.pos.y - 30, 0, 1, 1, _gd);
	}
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.puzzleJungle.quitPuzzleJungle.forme, NULL);

	//Boutton Aide
	BlitSprite(_gd->enigme.puzzleJungle.aidePuzzleJungle.buttonSprite[0], _gd->enigme.puzzleJungle.aidePuzzleJungle.pos.x - 60,
		_gd->enigme.puzzleJungle.aidePuzzleJungle.pos.y, 0, 1, 1, _gd);

	if (_gd->enigme.puzzleJungle.onSpriteAidePuzzleJungle == sfTrue
		&& _gd->enigme.puzzleJungle.clickAidePuzzleJungle == sfFalse)
	{
		BlitSprite(_gd->enigme.puzzleJungle.aidePuzzleJungle.buttonSprite[1], _gd->enigme.puzzleJungle.aidePuzzleJungle.pos.x - 60,
			_gd->enigme.puzzleJungle.aidePuzzleJungle.pos.y, 0, 1, 1, _gd);
	}
	if (_gd->enigme.puzzleJungle.clickAidePuzzleJungle == sfTrue)
	{
		BlitSprite(_gd->enigme.puzzleJungle.aidePuzzleJungle.buttonSprite[2], _gd->enigme.puzzleJungle.aidePuzzleJungle.pos.x - 60,
			_gd->enigme.puzzleJungle.aidePuzzleJungle.pos.y, 0, 1, 1, _gd);
	}
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.puzzleJungle.aidePuzzleJungle.forme, NULL);
}

void DisplayPuzzleJungle(GameData* _gd)
{
	BlitSprite(_gd->enigme.puzzleJungle.backgroundPuzzleJungle, 0, 0, 0, 1, 1, _gd);

	if (_gd->enigme.puzzleJungle.resolvedPuzzleJungle == sfFalse)
	{
		sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
		sfVector2f posMouseF = { posMouse.x, posMouse.y };
		/*for (int i = 0; i < NB_CADRE_JUNGLE; i++)
		{
			sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.puzzleJungle.cadre[i], NULL);
		}
		for (int i = 0; i < NB_PIECEPUZZLE_JUNGLE; i++)
		{
			sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.puzzleJungle.piecePuzzleJungle[i].forme, NULL);
		}*/

		//piece du puzzle a display avant 
		{
			//point depart/arrivé
			
			BlitSprite(_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_4].
				sprite, _gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_4].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_4].pos.y - 11,
				0, 1, 1, _gd);

			//piece mur
			BlitSprite(_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_2].sprite,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_2].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_2].pos.y - 11,
				0, 1, 1, _gd);

			BlitSprite(_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_15].sprite,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_15].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_15].pos.y - 11,
				0, 1, 1, _gd);

			BlitSprite(_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_13].sprite,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_13].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_13].pos.y - 11,
				0, 1, 1, _gd);

			//piece placé à l'avance
			BlitSprite(_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_3].sprite,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_3].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_3].pos.y - 11,
				0, 1, 1, _gd);

			BlitSprite(_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_6].sprite,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_6].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_6].pos.y - 11,
				0, 1, 1, _gd);


			BlitSprite(_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_11].sprite,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_11].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_11].pos.y - 11,
				0, 1, 1, _gd);
		}

		


		if (_gd->enigme.puzzleJungle.puzzleAllumer == sfTrue)
		{
			//point depart/arrivé
			BlitSprite(_gd->enigme.puzzleJungle.puzzleFini[0],
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.y - 11,
				0, 1, 1, _gd);

			BlitSprite(_gd->enigme.puzzleJungle.puzzleFini[1], _gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_4].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_4].pos.y - 11,
				0, 1, 1, _gd);

			//piece mur
			BlitSprite(_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_2].sprite,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_2].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_2].pos.y - 11,
				0, 1, 1, _gd);

			BlitSprite(_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_15].sprite,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_15].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_15].pos.y - 11,
				0, 1, 1, _gd);

			BlitSprite(_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_13].sprite,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_13].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_13].pos.y - 11,
				0, 1, 1, _gd);

			//piece placé à l'avance
			BlitSprite(_gd->enigme.puzzleJungle.puzzleFini[7],
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_3].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_3].pos.y - 11,
				0, 1, 1, _gd);

			BlitSprite(_gd->enigme.puzzleJungle.puzzleFini[5],
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_6].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_6].pos.y - 11,
				0, 1, 1, _gd);

			BlitSprite(_gd->enigme.puzzleJungle.puzzleFini[7],
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_7].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_7].pos.y - 11,
				0, 1, 1, _gd);

			BlitSprite(_gd->enigme.puzzleJungle.puzzleFini[6],
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_11].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_11].pos.y - 11,
				0, 1, 1, _gd);
		}

		//piece en attente 
		for (int i = 0; i < NB_PIECE_JUNGLE; i++)
		{
			sfVector2f decalage = { -9,-11 };
			sfVector2f pos = sfRectangleShape_getPosition(_gd->enigme.puzzleJungle.pieceJungle[i].forme);
			DisplayPuzzleRotation(_gd, i);
			BlitSprite(_gd->enigme.puzzleJungle.pieceJungle[i].sprite,
				pos.x + decalage.x, pos.y + decalage.y, 0, 1, 1, _gd);
		}

		//piece placé sur le puzzle 
		for (int i = 0; i < NB_PIECEPUZZLE_JUNGLE; i++)
		{
			if (_gd->enigme.puzzleJungle.piecePuzzleJungle[i].isUntouchable != sfTrue
				&& _gd->enigme.puzzleJungle.piecePuzzleJungle[i].isOccupied != sfFalse)
			{
				sfVector2f decalage = { -9,-11 };
				sfVector2f pos = sfRectangleShape_getPosition(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[i].idPiece].forme);
				DisplayPuzzleRotation(_gd, i);
				BlitSprite(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[i].idPiece].sprite,
					pos.x + decalage.x, pos.y + decalage.y, 0, 1, 1, _gd);
			}
		}


		//piece du puzzle a display après 
		if (_gd->enigme.puzzleJungle.puzzleAllumer != sfTrue)
		{

			if (_gd->enigme.puzzleJungle.piecePuzzleJungle[1].isOccupied == sfTrue)
			{
				sfVector2f decalage = { -9,-11 };
				sfVector2f pos = sfRectangleShape_getPosition(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[1].idPiece].forme);
				BlitSprite(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[1].idPiece].sprite,
					pos.x + decalage.x, pos.y + decalage.y, 0, 1, 1, _gd);
			}

			BlitSprite(_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_6].sprite,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_6].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_6].pos.y - 11,
				0, 1, 1, _gd);

			if (_gd->enigme.puzzleJungle.piecePuzzleJungle[5].isOccupied == sfTrue)
			{
				sfVector2f decalage = { -9,-11 };
				sfVector2f pos = sfRectangleShape_getPosition(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[5].idPiece].forme);
				BlitSprite(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[5].idPiece].sprite,
					pos.x + decalage.x, pos.y + decalage.y, 0, 1, 1, _gd);
			}
			
			if (_gd->enigme.puzzleJungle.piecePuzzleJungle[10].isOccupied == sfTrue)
			{
				sfVector2f decalage = { -9,-11 };
				sfVector2f pos = sfRectangleShape_getPosition(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[10].idPiece].forme);
				BlitSprite(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[10].idPiece].sprite,
					pos.x + decalage.x, pos.y + decalage.y, 0, 1, 1, _gd);
			}

			//point depart/arrivé
			BlitSprite(_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].sprite,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.y - 11,
				0, 1, 1, _gd);

			if (_gd->enigme.puzzleJungle.piecePuzzleJungle[8].isOccupied == sfTrue)
			{
				sfVector2f decalage = { -9,-11 };
				sfVector2f pos = sfRectangleShape_getPosition(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[8].idPiece].forme);
				BlitSprite(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[8].idPiece].sprite,
					pos.x + decalage.x, pos.y + decalage.y, 0, 1, 1, _gd);
			}

			BlitSprite(_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_7].sprite,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_7].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_7].pos.y - 11,
				0, 1, 1, _gd);

			if (_gd->enigme.puzzleJungle.piecePuzzleJungle[12].isOccupied == sfTrue)
			{
				sfVector2f decalage = { -9,-11 };
				sfVector2f pos = sfRectangleShape_getPosition(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[12].idPiece].forme);
				BlitSprite(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[12].idPiece].sprite,
					pos.x + decalage.x, pos.y + decalage.y, 0, 1, 1, _gd);
			}

		}
		

		if (_gd->enigme.puzzleJungle.piecePuzzleJungle[18].isOccupied == sfTrue)
		{
			sfVector2f decalage = { -9,-11 };
			sfVector2f pos = sfRectangleShape_getPosition(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[18].idPiece].forme);
			BlitSprite(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[18].idPiece].sprite,
				pos.x + decalage.x, pos.y + decalage.y, 0, 1, 1, _gd);
		}
		if (_gd->enigme.puzzleJungle.piecePuzzleJungle[17].isOccupied == sfTrue)
		{
			sfVector2f decalage = { -9,-11 };
			sfVector2f pos = sfRectangleShape_getPosition(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[17].idPiece].forme);
			BlitSprite(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[17].idPiece].sprite,
				pos.x + decalage.x, pos.y + decalage.y, 0, 1, 1, _gd);
		}
		if (_gd->enigme.puzzleJungle.piecePuzzleJungle[16].isOccupied == sfTrue)
		{
			sfVector2f decalage = { -9,-11 };
			sfVector2f pos = sfRectangleShape_getPosition(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[16].idPiece].forme);
			BlitSprite(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.piecePuzzleJungle[16].idPiece].sprite,
				pos.x + decalage.x, pos.y + decalage.y, 0, 1, 1, _gd);
		}


		//
		if (_gd->enigme.puzzleJungle.puzzleAllumer == sfTrue)
		{
			BlitSprite(_gd->enigme.puzzleJungle.puzzleFini[6], _gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.x + 175,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.y - 11, 0, 1, 1, _gd);

			BlitSprite(_gd->enigme.puzzleJungle.puzzleFini[7], _gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.y + 169, 0, 1, 1, _gd);

			BlitSprite(_gd->enigme.puzzleJungle.puzzleFini[4], _gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.x - 9,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.y + 349, 0, 1, 1, _gd);

			BlitSprite(_gd->enigme.puzzleJungle.puzzleFini[4], _gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.x + 175,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.y + 529, 0, 1, 1, _gd);

			BlitSprite(_gd->enigme.puzzleJungle.puzzleFini[5], _gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.x + 359,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.y + 529, 0, 1, 1, _gd);


			BlitSprite(_gd->enigme.puzzleJungle.puzzleFini[3], _gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.x + 359,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.y + 349, 0, 1, 1, _gd);

			BlitSprite(_gd->enigme.puzzleJungle.puzzleFini[5], _gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.x + 543,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].pos.y + 169, 0, 1, 1, _gd);

		}



		

		//piece en selection 
		if (_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].isInPuzzle == sfFalse
			&& _gd->enigme.puzzleJungle.isSelected == sfTrue)
		{
			sfVector2f decalage = { -9,-11 };
			sfVector2f pos = sfRectangleShape_getPosition(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].forme);
			DisplayPuzzleRotation(_gd, _gd->enigme.puzzleJungle.idCurrentPiece);
			BlitSprite(_gd->enigme.puzzleJungle.pieceJungle[_gd->enigme.puzzleJungle.idCurrentPiece].sprite,
				pos.x + decalage.x, pos.y + decalage.y, 0, 1, 1, _gd);
		}

		DisplayButtonPuzzleJungle(_gd);

	}
}