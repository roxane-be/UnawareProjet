#ifndef DEFINITIONBOX_H
#define DEFINITIONBOX_H

//Boite Intro
#define NB_PIECES_BOITE 5
#define NB_VIS 4


//Enigme de la boite
struct CadreBox
{
	sfVector2f pos;
	sfVector2f size;
	sfRectangleShape* forme;
};
typedef struct CadreBox CadreBox;

struct ButtonBox
{
	sfVector2f pos;
	sfVector2f size;
	sfRectangleShape* forme;
	sfSprite* buttonSprite[3];
};
typedef struct ButtonBox ButtonBox;

struct VisBox
{
	int identifiant;
	sfBool isPosed;
	sfBool isVisible;
	sfVector2f pos;
	sfVector2f size;
	sfRectangleShape* forme;
	sfSprite* sprite;
};
typedef struct VisBox VisBox;

typedef struct ListeVis ListeVis;
struct ListeVis
{
	ListeVis* next;
	sfVector2f pos;
	sfVector2f size;
	int toDelete;
};

struct UtilityPieceBoite
{
	CadreBox cadreBoite[2];
	char isSelected;
	int idPiece;
	int idVis;
	int countVis;
	int countPiece;
	sfBool resolvedDream_1;

	//Booleen pour savoir si la plaque est ouverte
	sfBool plaqueOuverte;
	//Booleen pour savoir si le cable est recuperais
	ButtonBox cableRecupPlaque;
	sfBool cableRecup;

	//Background de l'enigme cable
	sfSprite* backgroundPlaqueBox;
	sfSprite* backgroundPlaqueBoxFin;
	sfSprite* backgroundVisPlaqueBox;

	//Tranche des pieces
	sfSprite* tranchePiece[10];

	//bouton aide
	ButtonBox helpButtonBox;
	sfBool onSpriteHelpButtonBox;
	sfBool clickHelpButtonBox;

	//tuto plaque vis
	sfSprite* backgroundTutoVis;

	//vis retirer
	sfSprite* visRetirerSprite[4];
	sfBool visRetirer[4];

	sfSprite* diodePlaqueBoxEnigmeNonFini;
	sfSprite* diodePlaqueBoxEnigmeFini;

	//Audio interaction
	Sound pickUpCoinSound;
	Sound unscrewSound;
	Sound plateSound;
	Sound wirePickUpSound;
};
typedef struct UtilityPieceBoite UtilityPieceBoite;


#endif // !DEFINITIONBOX_H
