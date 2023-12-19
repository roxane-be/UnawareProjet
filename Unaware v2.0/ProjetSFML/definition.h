#ifndef DEFINITION_H
#define DEFINITION_H

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <SFML/Network.h>
#include <SFML/Audio.h>
#include "time.h"
#include "windows.h"
#include "math.h"
#include <string.h>

//definitions
#include "definitionEntities.h"
#include "definitionMastermind.h"
#include "definitionPuzzle.h"
#include "definitionDialogue.h"
#include "definitionPlaqueVis.h"
#include "definitionCable.h"
#include "definitionVoltage.h"
#include "definitionPuzzleJungle.h"
#include "definitionDiode.h"
#include "definitionDecryptage.h"
#include "definitionMap.h"
#include "definitionMenu.h"
#include "definitionCutScene.h"
//autres includes de fonctions
#include "Collision.h"
#include "MathFonctions.h"

typedef struct GameData GameData;

// Prototype

// char : nom (chemin du sprite), int : centrer ou non
sfSprite* LoadSprite(char*, int);

// char : nom (chemin du sprite), int : centrer ou non
sfText* LoadText(const char*, const char*, int);

//random entre deux int, min puis max
int RandomInt(int, int);

//si la cellule est dispo, line, colonne, taille line et taille colonne
int IsCellAvailable(int, int, int, int);

//si le point se trouve dans l'écran 
int IsPointIsInCamera(float, float, sfVector2f, sfVector2f);

//rotation d'un sprite sur tiled 
void RotationSpriteSheet(sfVector2f*, sfVector2f*, float*, int);

//upper du player sur son environnement 
int UpperUnderPlayer(char[999], int, int);
int UpperOnPlayer(char[999], int, int);


//récupere la line avec le y(float)
int getLine(float);

//recupere la colonne avec le x(float)
int getColumn(float);

//recupere le y avec le numero(int) de la line
float getY(int);

//recupere le x avec le numero(int) de la colonne
float getX(int);

//fonction de l'ecran vers le monde, float x puis float y
sfVector2f ScreenToWorld(float, float);

//fonction du jeu vers l'ecran, float x puis float y
sfVector2f WorldToScreen(float, float);

//recupere la taille du sprite, avec un sfSprite
sfVector2u GetSizeFromSprite(sfSprite*);

//fonction d'affichage du sprite, 
//sfSprite 
//position : en float x, float y
//l'angle : en float
//le scale : en float x puis float y 
//le gamedata pour finir
void BlitSprite(sfSprite*, float, float, float, float, float, GameData*);

//Fonction de suppression de sprite
//sprite : avec sfSprite*
void DeleteSprite(sfSprite*);

//fonction modifier la couleur du sprite
//sfSprite
//int : quel cas on veut (0 opacity, 1 couleur à assombrir,2 remttre comme avant la couleur)
void BlitSpriteColor(sfSprite*, int);

//fonction pour dessiner les pixel, 
//sfImage 
//la position : int x puis int y 
//la couleur : sfColor
void DrawPixel(sfImage*, int, int, sfColor);

//fonction affichage du texte
//sfText
//la position : float x puis float y
//la couleur : SfColor
//le scale : sfVector
//la window
void BlitText(sfText*, float, float, sfColor, sfVector2f, sfRenderWindow*);

//fonction pour recuperer du son avec un ficher, creer le son et le joue
void SoundPlay(char*);


//Fonction Math

//Fonction pour creer un vecteur, avec float x puis float y
sfVector2f CreateSFVector(float x, float y);

//Permet de recuperer la longeur d'un vecteur
float GetVectorLength(sfVector2f vector);

//Permet de normaliser un vecteur
sfVector2f NormalizeVector(sfVector2f vector);

//Permet de faire une rotation sur un vecteur avec un float angle
sfVector2f RotateVector(sfVector2f vector, float angle);

//Permet de faire un produit scalaire entre deux sfVector
float DotProduct(sfVector2f v1, sfVector2f v2);

//Fonction de conversion de degres vers radian
float DegreesToRadians(float angle);

//Fonction de conversion de radian vers degres
float RadiansToDegrees(float angle);

//Permet de creer un rectangle de type sfRectanfleShape
//la position : sfVector2f
//la taille (width) : float
// la hauteur (height) : float
//l'origine : int
void createRectangle(sfRectangleShape*, sfVector2f, float, float, int);

//Collision
int CollisionTriangleMouse(sfVector2f _clickPt, struct Collision _triang[]);

//Collision rectangle
int CollisionAABB(sfVector2f posAABB1, sfVector2f posAABB2, sfVector2f cornerAABB2);
//Collision rectangle
int IsColliding(sfVector2f posAABB1, sfVector2f cornerAABB1, sfVector2f posAABB2, sfVector2f cornerAABB2);

//Collision entre un rectangle shape et un sfVector pour la souris
// sfRectangleShape
// sfVector2f
// int pour le centrage
int isCollidingWithMouse(sfRectangleShape*, sfVector2f, int);

//Collision entre deux rectangle shape
int IsCollidingRectangleRectangle(sfRectangleShape*, sfRectangleShape*);

//Define

//Général
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define PI 3.14f
#define TEXT_SIZE 40
#define SIZECELL 64 // A MODIFIER SUREMENT
#define SCALE_X(width) width/SCREEN_WIDTH
#define SCALE_Y(height) height/SCREEN_HEIGHT
//Parallaxe
#define NB_TYPE_CLOUD 11
#define NB_CLOUD 250
#define NB_TYPE_BIRD 5
#define NB_ANIM_BIRD 6
#define NB_BIRD 3

//upper player
#define UPPER_TOP 130
#define BASE_UPPER -20
#define UPPER 46

//Volume sound
#define NB_CAT_SOUND 4

//Struct & Enum
	//Struct

//Text en jeu
struct TextSettings
{
	sfText* text;
	sfVector2f pos;
	sfColor color;
};
typedef struct TextSettings TextSettings;

struct GameText
{
	TextSettings namePerso;
	TextSettings validate;
	//enigme dialogue
	TextSettings dialogue;
	TextSettings doorEnigme;
	//ia
	TextSettings ia_voice;
};
typedef struct GameText GameText;

//Gestion Sprites
struct SpriteSetting
{
	sfSprite* sprite;
	sfVector2f scale;
	sfVector2f pos;
	float angle;
	sfBool boolean;
};
typedef struct SpriteSetting SpriteSetting;

struct GameSprites
{
	//Sprite Timer
	SpriteSetting spriteTimer[10];
	SpriteSetting spriteTimerPoint;
	//hug planche
	SpriteSetting spriteTimerBarre;
	//Mastermind Intro
	SpriteSetting diodeGreenIntro;
	SpriteSetting diodeGreyIntro;
	SpriteSetting diodeYellowIntro;
	SpriteSetting tabChiffreIntro[10];
	SpriteSetting arrowIntro;
	SpriteSetting backgroundInterfaceIntro;
	//Mastermind Box
	SpriteSetting diodeGreenBox;
	SpriteSetting diodeGreyBox;
	SpriteSetting diodeYellowBox;
	SpriteSetting diodeRedBox;
	SpriteSetting tabChiffreBox[10];
	SpriteSetting arrowBox;
	SpriteSetting backgroundInterfaceBox;
	//enigme dialogues 
	SpriteSetting perso;
	SpriteSetting interaction;
	SpriteSetting houseEnigme;
};
typedef struct GameSprites GameSprites;

//Parallaxe
struct BackGroundParallaxe
{
	sfSprite* sprite;
	sfVector3f pos;
	float speed;
	int currentAnimBird;
	float ttl;

	int currentBird;
	float birdTtlOff;
	float birdTtlMaxOff;
	sfBool display;
};
typedef struct BackGroundParallaxe BackGroundParallaxe;
struct UtilityParallaxe
{
	sfSprite* sky;
	sfSprite* cloud[NB_TYPE_CLOUD];
	sfSprite* bird[NB_TYPE_BIRD][NB_ANIM_BIRD];

	BackGroundParallaxe tabSky[NB_CLOUD];
	BackGroundParallaxe tabBird[NB_BIRD];

	float dt;
	sfClock* horloge;
};
typedef struct UtilityParallaxe UtilityParallaxe;

//enigme
struct Enigme
{
	//mastermind intro
	DoorDigicode doorDigicode;
	//puzzle island
	UtilityPuzzle utilityPuzzle;
	//mastermind box
	DoorDigicode houseBox;
	//enigme du dialogue reve 1 enigme2 
	Dialogue dialogue;
	//enigme voltage de la boite
	Voltage voltage;
	//enigme diode jungle
	Interupteur interupteur;
	//enigme du puzzle jungle
	EnigmePuzzleJungle puzzleJungle;
	Decryptage decryptage;
};
typedef struct Enigme Enigme;

//Framerate
struct FrameRate
{
	sfClock* frameClock;
	float dt;
};
typedef struct FrameRate FrameRate;

//Timer
struct Timer
{
	float timerTotal; //Temps restant en secondes (soit minutes * secondes)
	float timerSec; //Les secondes restantes
	float timerMin; //Les minutes restantes
};
typedef struct Timer Timer;

//Buttons 
struct Buttons
{
	//utiliser que pour le menu 
	sfVector2f pos;
	int w;
	int h;
	sfText* text;
	sfSprite* sprite[7];
	float scale;
	float scaleMin;
	float scaleMax;
	float scaleMove;
	sfRectangleShape* forme;
};
typedef struct Buttons Buttons;

//son pour cinematique
struct CutScenesSounds
{
	Sound spaceShipDoor;
	Sound bed;
	Sound bridge;
	Sound islandDoor;
	Sound boxTicket;
	Sound spaceShipConsole;
	Sound endBed;
	Sound endShip;
};
typedef struct CutScenesSounds CutScenesSounds;

//Enum

//Machine a état

//GameState pour gerer les état du jeu
enum GameState
{
	menu, // menu
	selecteurPerso, //ecran de selection de perso
	play, // en jeu
	pause, // menu pause
	credit, // credit du jeu
	option,// options du jeu
	controle, // controle du jeu
	volume, //option volume du jeu
	end // fin du jeu
};
typedef enum GameState GameState;

//World in game
enum World
{
	begin, // pour début du jeu au menu
	intro, // intro du jeu avec le tuto
	bedroom, // zone d'HUD qui est la chambre du joueur
	island, // premier reve du jeu
	jungle, // deuxieme reve du jeu
	shipEnd, //map final du vaisseau
};
typedef enum World World;

//Ingame
enum InGameState
{
	load, // etat de base quand on commence le jeu pour le menu
	enigme, // quand le joueur est dans une INTERFACE d'enigme
	exploration, // quand le joueur se deplace dans les maps
	cutscene, // pour les cut scene du jeu en transition
	tuto, //pour les tuto de chaque enigme
	symbole, //pour le symbole a reproduire dans la jungle

};
typedef enum InGameState InGameState;

//enigme
enum EnigmeState
{
	none, // si pas d'enigme en cours
	mastermindIntro, // hub
	puzzleIsland, // puzzle pont
	dialogueIsland, // enigme porte
	mastermindBox, // 1er enigme box
	plaqueBox, // 2eme enigme box
	cableBox, //3eme enigme box
	voltageBox, // 4eme enigme box
	box,
	diodeJungle, // enigme diode jungle
	puzzleJungle, // enigme puzzle jungle
	decryptageJungle, //enigme decryptage jungle
	labyrinthe, // enigme du laby sonore

};
typedef enum EnigmeState EnigmeState;

//cinematique
enum CutScene
{
	noCin, // quand pas de cinematique
	fail, //timer atteind 0
	vaisseauIntro, // intro du jeu
	vaisseauOpenDoor, //ouverture de la porte
	vaisseauSleep, //transition vers un monde
	islandIntro, // réveil sur l'island
	islandLeaveHouse, // quand on sort de la maison
	islandPont, // reparation du pont
	islandDialogue, // ouverture de la maison après dialogue
	islandEnd, // fin de l'island
	bedRoomIntro,//arrivée dans la chambre
	bedRoomExit,//arrivée dans la chambre
	JungleReveil, //flashback 
	JungleEnd, //flashback 
	EndReveil, // reveil dans le vaisseau une derniere fois
	EndCasque, // mis en place du casque sur la tete
	EndEnd,// et on s'envole
};
typedef enum CutScene CutScene;

enum LabyrinthColor
{
	red,
	blue,
	green,
	yellow
};
typedef enum LabyrinthColor LabyrinthColor;

//GameParameter pour la gestion des fichiers

struct GameParameter
{
	sfVector2i* resolution;
	float playerPosX;
	float playerPosY;
	//load config, toute valeurs écrite dans les fichiers
};
typedef struct GameParameter GameParameter;

//GameData pour la gestion des données du jeu
struct GameData
{
	//Valeur global du jeu
	sfRenderWindow* window;
	sfVideoMode sizeWindow;
	sfEvent event;
	GameParameter gameParameters; // pour la gestion de fichier/sauvegarde du jeu
	sfVector2f cam; // camera du jeu
	Timer timer; // timer du jeu
	sfSprite* interfaceTimer;
	sfSprite* interfaceTimerEnigme;

	//si on rate le timer
	sfBool failDream;

	//cursor
	sfSprite* cursor;

	//Parseur Map tiled
	MapParameter* mapIntro; // Permet de gerer l'import de la map d'intro
	MapParameter* mapIsland; // Permet de gerer l'import de la map d'island
	MapParameter* mapBedRoom; // Permet de gerer l'import de la map de la chambre 
	MapParameter* mapJungle; // Permet de gerer l'import de la map de la jungle
	MapParameter* mapShipEnd; // Permet de gerer l'import de la map du vaisseau final

	sfSprite* spriteShip; //sprite pour le vaisseau
	sfSprite* spriteIsland; //sprite pour l'islande 
	sfSprite* spriteJungle; //sprite pour la jungle

	sfSprite* blockColli; // pour afficher les collisions
	sfSprite* blockDestruc; // pour afficher les destructible
	sfSprite* blockInterac; // pour afficher les interractions
	sfSprite* blockPoint; // pour afficher les points 
	sfSprite* blockSound; //pour afficher les sons trigger

	//struct general pour text et sprite
	GameSprites sprites; //Une partie des sprites des enigmes
	GameText texts; //une partie du texte en jeu
	//Menu
	sfSprite* selectSprite[2];
	sfSprite* background;
	sfSprite* credit;
	sfSprite* options;
	sfSprite* controle;
	sfSprite* volume;
	sfSprite* pause;
	sfSprite* returnMenu;
	Buttons returnMenuPause;
	sfBool onSpriteQuitPauseMenu;
	sfBool clickSpriteQuitPauseMenu;
	//pour controle
	Buttons controleMenuPause;
	sfBool onSpriteControleMenuPause;

	sfRectangleShape* quitCredit;
	sfRectangleShape* quitOptions;
	sfRectangleShape* quitPause;
	sfRectangleShape* quitStart;
	sfRectangleShape* quitControle;
	sfRectangleShape* optionsSound;
	sfRectangleShape* pauseSound;
	sfBool onSpriteBN; //utiliser pour savoir sur quel bouton on se trouve
	sfBool onSpriteBC; // et utiliser la bonne prévisu
	sfBool onSpriteBQ;
	sfBool onSpriteSO;
	sfBool onSpriteSA;
	sfBool onSpriteBV;
	Buttons buttons[7]; // boutons pour le menu

	//Selecteur de perso
	sfSprite* backgroundSelectPerso;
	sfSprite* backgroundGarcon;
	sfSprite* backgroundFille;
	Buttons buttonCadreText;
	sfBool onSpriteCadreText;
	sfBool clickCadreText;
	Buttons buttonsSelecteur[2]; //boutons pour le selecteur de perso
	sfBool onSpriteButtonSelectG;
	sfBool onSpriteButtonSelectF;
	sfBool clickButtonSelectG;
	sfBool clickButtonSelectF;
	sfBool isSelect; // savoir si l'un des 2 choix a été selectionné
	char choixPerso; // 0 : garçon, 1 : fille
	char tempNameG[999]; //nom par defaut pour le garçon
	char tempNameF[999]; //nom par défaut pour la fille
	char persoName[999];

	//Audio Menu
	Sound menuInteract;
	Sound menuMusic;

	//Definition perso et npc
	PersoDef persoDef; // struct de definition pour anim etc
	Personnage player; // struct du player
	NPCDef npcDef; // struct de definition pour anim etc pour npc
	NPC npc[5]; //struct npc 
	IA_SHIP ia_ship;


	//Framerate du jeu + cloc anim
	sfBool inDream;
	FrameRate frameRate;
	Clock actualClock;

	//Animation et dir du perso
	TypeAnim typeAnim;
	Direction dir;

	//machine a état
	GameState gameState; // état principal du jeu
	World world; // état du monde où l'on se trouve
	InGameState inGameState; // état en cours dans le monde 
	EnigmeState enigmeState; // quelle enigme est en cours
	EnigmeState enigmeBox; //pour gestion de la boite
	CutScene cutSceneState; // gestion des cinematiques

	//Audio monde
	Sound worldAmbience;
	Sound worldAmbienceOutside;
	Sound aiSound;
	Sound bedInteract;
	Sound sucessSound;
	Sound errorSound;
	Sound helpSound;
	Sound bushSound;
	Sound boxSwishSound;
	CutScenesSounds cutScenesSounds;

	//Enigme
	Enigme enigme; // enigme du jeu

	//Parallaxe monde 1
	UtilityParallaxe utilityParallaxe;

	//Map reve 1, enigme box
	sfSprite* arrowBox[6];
	sfBool onSpriteArrowLeft;
	sfBool clickSpriteArrowLeft;

	sfBool onSpriteArrowRight;
	sfBool clickSpriteArrowRight;
	Collision arrowTriBox[2];

	//Dialogues
	//les pos de PNJ, je savais pas réellement ou le mettre
	// ici ou dans la struct de l'enigme
	sfVector2f pnjPos[NB_PNJ];

	//BoiteVis
	VisBox visCadre[NB_VIS];
	VisBox visPiece[NB_PIECES_BOITE * 2];
	ListeVis* listePieces;
	ListeVis* listeVis;
	UtilityPieceBoite utilityPieceBoite;
	int identifiantVis;

	//BoiteCable
	Cable cables[NB_CABLE];
	UtilityCable utilityCable;

	//boite 
	sfSprite* trap;

	int nbSpriteAnim;
	int push; // utiliser pour gerer idle ou mouvement pour animation

	//gestion musique du laby
	Sound musicLaby[4];
	LabyrinthColor currentColor;
	LabyrinthColor lastColor;
	sfBool isInsideLaby;

	//CutScene
	Cinematique cinematique;
	sfSprite* fondCredit;
	sfSprite* terre;

	//Sound volume option
	float soundGlobal;
	float soundInterraction;
	float soundAmbiance;
	float soundMusic;
	sfSprite* barrVolume;
	sfSprite* cursorVolume;
	sfVector2f posBarrVolume[NB_CAT_SOUND];
	sfVector2f posCursorVolume[NB_CAT_SOUND];
	sfVector2f posCursorVolumeRect[NB_CAT_SOUND];
	sfRectangleShape* rectVolume[NB_CAT_SOUND];
	sfRectangleShape* rectTestVolume[NB_CAT_SOUND - 1];
	sfRectangleShape* quitVolume;
	sfText* volumePourcentage[NB_CAT_SOUND];
	sfSprite* soundTest;

	//Labyrinthe
	sfBool CoffreWrong;
	sfBool CoffreGood;
	sfBool inTp;
	int AnimCurrentCoffre;
	float timeAnimCoffre;
	sfBool CoffreWrongOpen;
	sfBool CoffreGoodOpen;
	sfBool labyFinish;
	sfSprite* fourmi[16];
	int currentAnimFourmi;
	float currentTimeFourmi;
	sfBool inFourmiTp;
	float currentinFourmiTp;
	sfBool inGrenouilleTp;
	float currentTimeGrenouille;
	sfSprite* steleLabyTuto;
	Buttons retourTutoLaby;
	sfBool onSpriteRetourTutoLaby;
	sfBool clickRetourTutoLaby;
	Sound voiceFourmi;

};



#endif