#include "InitPuzzleJungle.h"

void InitPuzzleJungle(GameData* _gd)
{
	_gd->enigme.puzzleJungle.backgroundPuzzleJungle = LoadSprite("../Ressources/Assets/PuzzleJungle/interfacetuyaux.png", 0);

	_gd->enigme.puzzleJungle.timerPuzzle = 0.0f;

	//cadre 
	sfVector2f pos = { 95,420 };
	_gd->enigme.puzzleJungle.cadre[0] = sfRectangleShape_create();
	createRectangle(_gd->enigme.puzzleJungle.cadre[0], pos, 630, 600, 0);
	sfRectangleShape_setOutlineColor(_gd->enigme.puzzleJungle.cadre[0], sfGreen);

	pos.x = 870;
	pos.y = 230;
	_gd->enigme.puzzleJungle.cadre[1] = sfRectangleShape_create();
	createRectangle(_gd->enigme.puzzleJungle.cadre[1], pos, 990, 800, 0);
	sfRectangleShape_setOutlineColor(_gd->enigme.puzzleJungle.cadre[1], sfGreen);

	_gd->enigme.puzzleJungle.idCurrentPiece = 0;
	_gd->enigme.puzzleJungle.idCurrentPuzzle = 0;
	_gd->enigme.puzzleJungle.resolvedPuzzleJungle = sfFalse;
	_gd->enigme.puzzleJungle.isSelected = sfFalse;

	int countPuzzle = 0;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			_gd->enigme.puzzleJungle.piecePuzzleJungle[countPuzzle].isOccupied = sfFalse;
			_gd->enigme.puzzleJungle.piecePuzzleJungle[countPuzzle].isUntouchable = sfFalse;
			_gd->enigme.puzzleJungle.piecePuzzleJungle[countPuzzle].identifiant = countPuzzle;
			_gd->enigme.puzzleJungle.piecePuzzleJungle[countPuzzle].pos.x = 907 + (i % 5) * 184;
			_gd->enigme.puzzleJungle.piecePuzzleJungle[countPuzzle].pos.y = 267 + (j % 4) * 180;
			_gd->enigme.puzzleJungle.piecePuzzleJungle[countPuzzle].forme = sfRectangleShape_create();
			createRectangle(_gd->enigme.puzzleJungle.piecePuzzleJungle[countPuzzle].forme,
				_gd->enigme.puzzleJungle.piecePuzzleJungle[countPuzzle].pos, 182, 179, 0);
			sfRectangleShape_setOutlineColor(_gd->enigme.puzzleJungle.piecePuzzleJungle[countPuzzle].forme, sfGreen);
			countPuzzle++;
		}
	}


	int countPiece = 0;
	for (int j = 0; j < NB_PIECE_JUNGLE / 3; j++)
	{
		for (int i = 0; i < NB_PIECE_JUNGLE / 3; i++)
		{
			char chemin[255];
			_gd->enigme.puzzleJungle.pieceJungle[countPiece].identifiant = countPiece;

			_gd->enigme.puzzleJungle.pieceJungle[countPiece].isPosed = sfTrue;
			_gd->enigme.puzzleJungle.pieceJungle[countPiece].isVisible = sfTrue;
			_gd->enigme.puzzleJungle.pieceJungle[countPiece].isInPuzzle = sfFalse;


			if (i < 2)
			{
				_gd->enigme.puzzleJungle.pieceJungle[countPiece].typeTuyau = tuyauAngle;//j = 0 tuyauDroit, 1 = TuyauAngle
				_gd->enigme.puzzleJungle.pieceJungle[countPiece].rotationPiece = sudEst;

			}
			else
			{
				_gd->enigme.puzzleJungle.pieceJungle[countPiece].typeTuyau = tuyauDroit;//j = 0 tuyauDroit, 1 = TuyauAngle
				_gd->enigme.puzzleJungle.pieceJungle[countPiece].rotationPiece = vertical;

			}


			_gd->enigme.puzzleJungle.pieceJungle[countPiece].pos.x = 140 + (i * 184);//i * 200 + 120;
			_gd->enigme.puzzleJungle.pieceJungle[countPiece].pos.y = 450 + (j * 180);//j * 200 + 440;
			_gd->enigme.puzzleJungle.pieceJungle[countPiece].forme = sfRectangleShape_create();
			createRectangle(_gd->enigme.puzzleJungle.pieceJungle[countPiece].forme,
				_gd->enigme.puzzleJungle.pieceJungle[countPiece].pos, 182, 179, 0);
			sfRectangleShape_setOutlineColor(_gd->enigme.puzzleJungle.pieceJungle[countPiece].forme, sfGreen);
			countPiece++;
		}
	}


	_gd->enigme.puzzleJungle.spritePieceRotation[vertical] = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/vertical.png", 0);
	_gd->enigme.puzzleJungle.spritePieceRotation[horizontal] = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/horizontal.png", 0);
	_gd->enigme.puzzleJungle.spritePieceRotation[nordEst] = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/nordEst.png", 0);
	_gd->enigme.puzzleJungle.spritePieceRotation[nordOuest] = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/nordOuest.png", 0);
	_gd->enigme.puzzleJungle.spritePieceRotation[sudEst] = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/sudEst.png", 0);
	_gd->enigme.puzzleJungle.spritePieceRotation[sudOuest] = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/sudOuest.png", 0);


	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].sprite = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/debut.png", 0);
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].isOccupied = sfTrue;
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_0].isUntouchable = sfTrue;

	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_2].sprite = LoadSprite("../Ressources/Assets/PuzzleJungle/base.png", 0);
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_2].isOccupied = sfTrue;
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_2].isUntouchable = sfTrue;

	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_3].sprite = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/fix2.png", 0);
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_3].isUntouchable = sfTrue;
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_3].isOccupied = sfTrue;

	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_4].sprite = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/fin_tube1.png", 0);
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_4].isUntouchable = sfTrue;
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_4].isOccupied = sfTrue;

	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_6].sprite = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/fix3.png", 0);
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_6].isUntouchable = sfTrue;
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_6].isOccupied = sfTrue;

	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_7].sprite = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/fix2.png", 0);
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_7].isUntouchable = sfTrue;
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_7].isOccupied = sfTrue;

	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_11].sprite = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/fix4.png", 0);
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_11].isUntouchable = sfTrue;
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_11].isOccupied = sfTrue;

	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_13].sprite = LoadSprite("../Ressources/Assets/PuzzleJungle/base.png", 0);
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_13].isOccupied = sfTrue;
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_13].isUntouchable = sfTrue;

	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_15].sprite = LoadSprite("../Ressources/Assets/PuzzleJungle/base.png", 0);
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_15].isOccupied = sfTrue;
	_gd->enigme.puzzleJungle.piecePuzzleJungle[PIECE_POSED_15].isUntouchable = sfTrue;

	//piece fini
	_gd->enigme.puzzleJungle.puzzleFini[0] = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/debut_2.png", 0);//debut
	_gd->enigme.puzzleJungle.puzzleFini[1] = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/fin_tube2_2.png", 0);//fin
	_gd->enigme.puzzleJungle.puzzleFini[2] = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/horizontal_fini.png", 0);
	_gd->enigme.puzzleJungle.puzzleFini[3] = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/vertical_fini.png", 0);
	_gd->enigme.puzzleJungle.puzzleFini[4] = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/nordEst_fini.png", 0);
	_gd->enigme.puzzleJungle.puzzleFini[5] = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/nordOuest_fini.png", 0);
	_gd->enigme.puzzleJungle.puzzleFini[6] = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/sudOuest_fini.png", 0);
	_gd->enigme.puzzleJungle.puzzleFini[7] = LoadSprite("../Ressources/Assets/PuzzleJungle/tok/sudEst_fini.png", 0);

	_gd->enigme.puzzleJungle.puzzleAllumer = sfFalse;


	sfVector2f temp;
	sfVector2f size = { 190, 180 };
	temp.x = 125;
	temp.y = 200;
	//Bouton
	_gd->enigme.puzzleJungle.validatePuzzleJungle.buttonSprite[0] = LoadSprite("../Ressources/Assets/PuzzleJungle/val'.png", 0);
	_gd->enigme.puzzleJungle.validatePuzzleJungle.buttonSprite[1] = LoadSprite("../Ressources/Assets/PuzzleJungle/val'2.png", 0);
	_gd->enigme.puzzleJungle.validatePuzzleJungle.buttonSprite[2] = LoadSprite("../Ressources/Assets/PuzzleJungle/val'3.png", 0);

	_gd->enigme.puzzleJungle.validatePuzzleJungle.pos = temp;
	_gd->enigme.puzzleJungle.validatePuzzleJungle.size = size;

	_gd->enigme.puzzleJungle.onSpriteValidatePuzzleJungle = sfFalse;
	_gd->enigme.puzzleJungle.clickValidatePuzzleJungle = sfFalse;

	_gd->enigme.puzzleJungle.validatePuzzleJungle.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.puzzleJungle.validatePuzzleJungle.forme, _gd->enigme.puzzleJungle.validatePuzzleJungle.pos,
		_gd->enigme.puzzleJungle.validatePuzzleJungle.size.x, _gd->enigme.puzzleJungle.validatePuzzleJungle.size.y, 0);


	temp.x = 325;
	temp.y = 200;
	_gd->enigme.puzzleJungle.resetPuzzleJungle.buttonSprite[0] = LoadSprite("../Ressources/Assets/PuzzleJungle/rei.png", 0);
	_gd->enigme.puzzleJungle.resetPuzzleJungle.buttonSprite[1] = LoadSprite("../Ressources/Assets/PuzzleJungle/rei2.png", 0);
	_gd->enigme.puzzleJungle.resetPuzzleJungle.buttonSprite[2] = LoadSprite("../Ressources/Assets/PuzzleJungle/rei3.png", 0);

	_gd->enigme.puzzleJungle.resetPuzzleJungle.pos = temp;
	_gd->enigme.puzzleJungle.resetPuzzleJungle.size = size;

	_gd->enigme.puzzleJungle.onSpriteResetPuzzleJungle = sfFalse;
	_gd->enigme.puzzleJungle.clickResetPuzzleJungle = sfFalse;

	_gd->enigme.puzzleJungle.resetPuzzleJungle.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.puzzleJungle.resetPuzzleJungle.forme, _gd->enigme.puzzleJungle.resetPuzzleJungle.pos, _gd->enigme.puzzleJungle.resetPuzzleJungle.size.x,
		_gd->enigme.puzzleJungle.resetPuzzleJungle.size.y, 0);

	temp.x = 525;
	temp.y = 200;
	_gd->enigme.puzzleJungle.quitPuzzleJungle.buttonSprite[0] = LoadSprite("../Ressources/Assets/PuzzleJungle/quit.png", 0);
	_gd->enigme.puzzleJungle.quitPuzzleJungle.buttonSprite[1] = LoadSprite("../Ressources/Assets/PuzzleJungle/quit2.png", 0);
	_gd->enigme.puzzleJungle.quitPuzzleJungle.buttonSprite[2] = LoadSprite("../Ressources/Assets/PuzzleJungle/quit3.png", 0);

	_gd->enigme.puzzleJungle.quitPuzzleJungle.pos = temp;
	_gd->enigme.puzzleJungle.quitPuzzleJungle.size = size;

	_gd->enigme.puzzleJungle.onSpriteQuitPuzzleJungle = sfFalse;
	_gd->enigme.puzzleJungle.clickQuitPuzzleJungle = sfFalse;

	_gd->enigme.puzzleJungle.quitPuzzleJungle.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.puzzleJungle.quitPuzzleJungle.forme, _gd->enigme.puzzleJungle.quitPuzzleJungle.pos, _gd->enigme.puzzleJungle.quitPuzzleJungle.size.x,
		_gd->enigme.puzzleJungle.quitPuzzleJungle.size.y, 0);

	temp.x = _gd->sizeWindow.width - 250;
	temp.y = 5;

	_gd->enigme.puzzleJungle.aidePuzzleJungle.buttonSprite[0] = LoadSprite("../Ressources/Assets/PuzzleJungle/aide_tuyaux1.png", 0);
	_gd->enigme.puzzleJungle.aidePuzzleJungle.buttonSprite[1] = LoadSprite("../Ressources/Assets/PuzzleJungle/aide_tuyaux2.png", 0);
	_gd->enigme.puzzleJungle.aidePuzzleJungle.buttonSprite[2] = LoadSprite("../Ressources/Assets/PuzzleJungle/aide_tuyaux3.png", 0);

	_gd->enigme.puzzleJungle.aidePuzzleJungle.pos = temp;
	_gd->enigme.puzzleJungle.aidePuzzleJungle.size = size;

	_gd->enigme.puzzleJungle.onSpriteAidePuzzleJungle = sfFalse;
	_gd->enigme.puzzleJungle.clickAidePuzzleJungle = sfFalse;

	_gd->enigme.puzzleJungle.aidePuzzleJungle.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.puzzleJungle.aidePuzzleJungle.forme, _gd->enigme.puzzleJungle.aidePuzzleJungle.pos, _gd->enigme.puzzleJungle.aidePuzzleJungle.size.x,
		_gd->enigme.puzzleJungle.aidePuzzleJungle.size.y, 0);

	InitTutoPuzzleJungle(_gd);

}