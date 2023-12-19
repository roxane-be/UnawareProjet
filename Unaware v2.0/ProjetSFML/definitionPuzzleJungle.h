#ifndef DEFINITIONPUZZLEJUNGLE_H
#define DEFINITIONPUZZLEJUNGLE_H

#define NB_PIECEPUZZLE_JUNGLE 20
#define NB_CADRE_JUNGLE 2
#define NB_PIECE_JUNGLE 9

#define PIECE_POSED_0 0
#define PIECE_POSED_2 2
#define PIECE_POSED_3 3
#define PIECE_POSED_4 4
#define PIECE_POSED_6 6
#define PIECE_POSED_11 11
#define PIECE_POSED_7 7
#define PIECE_POSED_13 13
#define PIECE_POSED_15 15

enum RotationPiece
{
	vertical,
	horizontal,
	sudOuest,
	sudEst,
	nordOuest,
	nordEst
};
typedef enum RotationPiece RotationPiece;

enum TypeTuyau
{
	tuyauDroit,
	tuyauAngle,
};
typedef enum TypeTuyau TypeTuyau;

struct ButtonPuzzleJungle
{
	sfVector2f pos;
	sfVector2f size;
	sfRectangleShape* forme;
	sfSprite* buttonSprite[3];
};
typedef struct ButtonPuzzleJungle ButtonPuzzleJungle;

struct PiecePuzzleJungle
{
	int identifiant;
	sfBool isPosed;
	sfBool isVisible;
	sfBool isOccupied;
	sfBool isInPuzzle;
	sfVector2f pos;
	sfVector2f size;
	sfRectangleShape* forme;
	sfSprite* sprite;
	RotationPiece rotationPiece;
	TypeTuyau typeTuyau;
	int idPiece;
	sfBool* isUntouchable;

};
typedef struct PiecePuzzleJungle PiecePuzzleJungle;

typedef struct EnigmePuzzleJungle EnigmePuzzleJungle;
struct EnigmePuzzleJungle
{
	sfSprite* backgroundPuzzleJungle;

	float timerPuzzle;

	PiecePuzzleJungle piecePuzzleJungle[NB_PIECEPUZZLE_JUNGLE];
	PiecePuzzleJungle pieceJungle[NB_PIECE_JUNGLE];
	int idCurrentPiece;
	int idCurrentPuzzle;
	sfBool isSelected;
	sfSprite* spritePieceRotation[6];

	sfRectangleShape* cadre[NB_CADRE_JUNGLE];

	sfSprite* puzzleFini[8];

	ButtonPuzzleJungle validatePuzzleJungle;
	sfBool onSpriteValidatePuzzleJungle;
	sfBool clickValidatePuzzleJungle;

	ButtonPuzzleJungle resetPuzzleJungle;
	sfBool onSpriteResetPuzzleJungle;
	sfBool clickResetPuzzleJungle;

	ButtonPuzzleJungle quitPuzzleJungle;
	sfBool onSpriteQuitPuzzleJungle;
	sfBool clickQuitPuzzleJungle;

	ButtonPuzzleJungle aidePuzzleJungle;
	sfBool onSpriteAidePuzzleJungle;
	sfBool clickAidePuzzleJungle;

	sfSprite* backgroundTutoPuzzleJungle;

	ButtonPuzzleJungle retourPuzzleJungle;
	sfBool onSpriteRetourPuzzleJungle;
	sfBool clickRetourPuzzleJungle;

	sfBool puzzleAllumer;
	sfBool resolvedPuzzleJungle;
	sfText* text;
	sfVector2f posText;

	//Audio interaction
	Sound placePuzzleSound;
	Sound rotatePuzzleSound;
	Sound helpPuzzleSound;
	Sound laserOnPuzzleSound;

};

#endif