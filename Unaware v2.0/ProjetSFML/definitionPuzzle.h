#ifndef DEFINITIONPUZZLE_H
#define DEFINITIONPUZZLE_H

//Puzzle enigme 1 ile
#define NB_PIECES_PUZZLE_ILE 5

struct Puzzle
{
	int Id;
	int isPosed;
	int isOccupied;
	float width;
	float height;
	sfVector2f position;
	sfRectangleShape* forme;
	sfSprite* sprite;
	sfBool isVisible;
	sfBool isInPuzzle;

};
typedef struct Puzzle Puzzle;

typedef struct ListePosPuzzle ListePosPuzzle;
struct ListePosPuzzle
{
	ListePosPuzzle* next;
	sfVector2f pos;
	int toDelete;
};

struct ButtonPuzzle
{
	sfVector2f pos;
	sfVector2f size;
	sfRectangleShape* forme;
	sfSprite* buttonSprite[3];
};
typedef struct ButtonPuzzle ButtonPuzzle;

struct UtilityPuzzle
{
	//Puzzle, variable principale
	Puzzle puzzle[25];
	Puzzle piece[25];
	ListePosPuzzle* rouky;

	sfRectangleShape* cadre1;
	sfRectangleShape* cadre2;
	sfSprite* backgroundInterface;
	char isSelected;
	int idPiece;
	int idPuzzle;
	int countPuzzle;
	int countPiece;
	sfBool resolvedPuzzleDream_1; // permet de resoudre l'enigme

	//Gestion des planches
	sfVector2f posPlusPlanche;
	sfVector2f posPlanche;
	sfSprite* plusPlanche;
	sfSprite* planche;
	sfBool recupPlanche;
	float upPlus;
	int nbPlancheRecup;
	sfBool isTwoPlanche;
	sfBool openFirstTime;

	ButtonPuzzle quit; // bouton quitter du puzzle
	ButtonPuzzle validate; // bouton valider du puzzle
	ButtonPuzzle reset; // bouton reset puzzle
	ButtonPuzzle help; // bouton aide puzzle
	//Permet de savoir si le curseur est au dessus des boutons
	sfBool onSpriteValidate;
	sfBool onSpriteReset;
	sfBool onSpriteQuit;
	sfBool onSpriteHelp;
	//Permet de savoir si on a cliquer sur les boutons
	sfBool clickValidate;
	sfBool clickReset;
	sfBool clickQuit;
	sfBool clickHelp;

	//Gestion du tuto puzzle
	sfSprite* backgroundTutoPuzzle;
	//Le bouton de retour qui sera dans le tuto du puzzle
	ButtonPuzzle retour;
	sfBool clickRetour;
	sfBool onSpriteRetour;

	//Audio interaction
	Sound woodPickUpSound;
	Sound placePuzzleSound;
	Sound resetPuzzleSound;
};
typedef struct UtilityPuzzle UtilityPuzzle;

#endif 
