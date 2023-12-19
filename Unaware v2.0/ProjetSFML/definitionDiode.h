#ifndef DEFINITIONDIODE_H
#define DEFINITIONDIODE_h



#define NB_COLUMNS_TUTO 3
#define NB_LIGNE_TUTO 3

#define NB_COLUMNS_SYMBOLE 4
#define NB_LIGNE_SYMBOLE 4

#define NB_COLUMNS_FULL 6
#define NB_LIGNE_FULL 5

typedef enum Light Light;
enum Light
{
	on = -1,
	off = 1
};

typedef enum InterupteurState InterupteurState;
enum InterupteurState
{
	tutoDiode,
	symboleDiode,
	fullDiode,
};

struct ButtonDiode
{
	sfVector2f pos;
	sfVector2f size;
	sfRectangleShape* forme;
	sfSprite* buttonSprite[3];
};
typedef struct ButtonDiode ButtonDiode;

typedef struct Interupteur Interupteur;
struct Interupteur
{
	sfRectangleShape*** rectInterupteur;
	sfRectangleShape* reset;

	sfVector2f** pos;
	sfVector2f sizeTab;
	sfBool resolvedDiode;
	//state
	InterupteurState interupteurState;
	Light** etat;

	//diode et background
	sfSprite* backgroundDiode;
	sfSprite* spriteOn;
	sfSprite* spriteOff;

	//bouton aide diode 3x3
	sfSprite* backgroundTutoDiode3x3;
	ButtonDiode helpButtonDiode3x3;
	sfBool onSpriteHelpButtonDiode3x3;
	sfBool clickHelpButtonDiode3x3;

	//bouton aide diode symbole
	sfSprite* backgroundTutoDiodeSymbole;
	ButtonDiode helpButtonDiodeSymbole;
	sfBool onSpriteHelpButtonDiodeSymbole;
	sfBool clickHelpButtonDiodeSymbole;

	sfSprite* backgroundSymboleDiode;
	// bouton symbole diode de l'interface principale
	ButtonDiode symboleButtonDiode;
	sfBool onSpriteSymboleButtonDiode;
	sfBool clickSymboleButtonDiode;
	// bouton symbole diode du tuto
	ButtonDiode symboleButtonDiodeTuto;
	sfBool onSpriteSymboleButtonDiodeTuto;
	sfBool clickSymboleButtonDiodeTuto;

	//bouton aide diode fin
	sfSprite* backgroundTutoDiodeFin;
	ButtonDiode helpButtonDiodeFin;
	sfBool onSpriteHelpButtonDiodeFin;
	sfBool clickHelpButtonDiodeFin;

	//bouton retour
	ButtonDiode retourButtonDiode;
	sfBool onSpriteRetourButtonDiode;
	sfBool clickRetourButtonDiode;

	//bouton valider
	ButtonDiode validateButtonDiode;
	sfBool onSpriteValidateButtonDiode;
	sfBool clickValidateButtonDiode;

	//bouton reset
	ButtonDiode resetButtonDiode;
	sfBool onSpriteResetButtonDiode;
	sfBool clickResetButtonDiode;

	//bouton quitter
	ButtonDiode quitButtonDiode;
	sfBool onSpriteQuitButtonDiode;
	sfBool clickQuitButtonDiode;

	//Audio interaction
	Sound fireflyOn;
	Sound fireflyOff;
	Sound fireflyError;
	Sound fireflyInstruction;
	Sound fireflyQuit;

	sfBool diodeFini[3];
	sfBool diodeResolved;
};



#endif // !DEFINITIONDIODE_H
