#ifndef DEFINITIONMASTERMIND_H
#define DEFINITIONMASTERMIND_H

//Mastermind
#define NB_DIGICODE 4
#define NB_ARROW NB_DIGICODE*2

#define TAB_TRY_INTRO 4
#define TAB_TRY_MASTERMIND_BOX 4
#define TAB_TRY 4

//Enigme MASTERMIND

//collision pour les triangles
struct Collision
{
	sfColor color;
	sfVector2f vertex[3];
};
typedef struct Collision Collision;

//verifie si il y a un chiffre en double dans le code 
struct CheckDuplicate
{
	int value;
	sfBool check;
};
typedef struct CheckDuplicate CheckDuplicate;

struct Arrow
{
	sfSprite** Timeline;
	Sequence sequence[2];
	sfVector2f pos;
	int idSeq;
	int currentAnim;
	float currentTime;
	sfBool isClicked;
};
typedef struct Arrow Arrow;

struct ButtonMastermind
{
	sfSprite* buttonSprite[3];
	sfVector2f pos;
	sfVector2f size;
	sfRectangleShape* forme;
	sfBool isQuit;
};
typedef struct ButtonMastermind ButtonMastermind;

struct DoorDigicode
{
	//la valeur de notre chiffre
	int value[NB_DIGICODE];
	//les valeurs max ou min qu'on peut atteindre 
	int valueMin;
	int valueMax;
	//le code
	int valueCode[NB_DIGICODE];

	//3f, z correspont à l'angle
	// a supprimer quand animation pour mastermind box seront dans la struct arrow
	//sfVector3f arrow[NB_ARROW];
	sfVector2f caseDigicode[NB_DIGICODE];

	//collision pour les flèches
	Collision colTriangle[NB_ARROW];

	//un booleen pour savoir si la diode doit etre ou pas afficher
	sfBool diodeGreen[TAB_TRY + 1][NB_DIGICODE];
	sfBool diodeGrey[TAB_TRY + 1][NB_DIGICODE];
	sfBool diodeYellow[TAB_TRY + 1][NB_DIGICODE];
	sfBool diodeRed[TAB_TRY + 1][NB_DIGICODE];


	int tabTry[TAB_TRY][NB_DIGICODE];
	//a quelle test essai on se trouve
	int current;

	//le nombre de diode dans le 
	int nbDiodeGreen;
	int nbDiodeYellow;
	int nbDiodeRed;

	//verifie si il y a un chiffre en double dans le code 
	CheckDuplicate duplicate[4];

	//savoir dans quel stategame on est et attribuer un define 
	int state[10];

	//pour savoir si le tableau est plein
	//uniquement utile pour le HUB
	sfBool isFull;

	sfBool resolvedIntro; //resoltion pour l'intro
	sfBool resolvedDream_1Box; // resolution pour la boite

	//animation pour les fleches
	Arrow arrowIntro[NB_ARROW];
	Arrow arrowBox[NB_ARROW];
	Clock animatedButtonMastermindIntro; //horloge pour l'animation des fleches

	//Button utilisés pour changer entre menu aide et le mastermind
	ButtonMastermind buttonQuit;
	sfBool onSpriteQuit;
	sfBool clickQuit;
	//Button utilisés pour quitter le mastermind
	ButtonMastermind buttonHelp;
	sfBool onSpriteHelp;
	sfBool clickHelp;
	//Bouton utilisé pour valider le code
	ButtonMastermind buttonValidate;
	sfBool onSpriteValidate;
	sfBool clickValidate;
	//Button utilisés pour quitter l'aide dans le mastermind
	ButtonMastermind buttonRetour;
	sfBool onSpriteRetour;
	sfBool clickRetour;

	//Tuto mastermind
	sfSprite* backgroundTuto;
	//Tuto mastermindBox
	sfSprite* backgroundTutoMastermindBox;
	sfSprite* backgroundTutoBox;

	//Bouton aide le mastermind de la boite
	ButtonMastermind buttonHelpMastermindBox;
	sfBool onSpriteHelpMastermindBox;
	sfBool clickHelpMastermindBox;
	//bouton retour de la boite
	ButtonMastermind retourButtonBox;
	sfBool onSpriteRetourButtonBox;
	sfBool clickRetourButtonBox;
	//bouton Quitter de la boite
	ButtonMastermind buttonQuitBox; //De la meme maniere que le bouton retour du tuto, je savais pas ou le mettre
	sfBool onSpriteQuitButtonBox;
	sfBool clickQuitButtonBox;
	//Bouton valider du mastermind de la boite
	ButtonMastermind buttonValidateBox;
	sfBool onSpriteValidateBox;
	sfBool clickValidateBox;
	//Bouton pour recuperer les pieces
	ButtonMastermind pieceMastermindBox;
	sfBool pieceRecup;

	sfSprite* diodeMastermindBoxEnigmeNonFini;
	sfSprite* diodeMastermindBoxEnigmeFini;

	sfBool boiteOuverte;

	//interface mastermind de la boite
	sfSprite* backgroundMastermindBox;

	//Audio interaction
	Sound arrowSound;
	Sound validSound;
	Sound errorSound;
	Sound interactSound;
	Sound helpSound;
};
typedef struct DoorDigicode DoorDigicode;

#endif