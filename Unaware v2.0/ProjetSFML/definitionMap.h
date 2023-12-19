#ifndef DEFINITIONMAP_H
#define DEFINITIONMAP_H

//#define NB_CALQUE_MAP 14
#define SPEED_CAM 10.f

struct MapID
{
	//tableau dynamique pour le tableau qui va contenir tout les id
	int** idMap;
	sfBool** needRotate;
	//nom du layer
	char name[999];
};
typedef struct MapID MapID;

struct AnimationID
{
	//id qui doit déclencher l'animation
	int idMother;
	int* id;
	float* ttl;
	int nbImageInAnim;
	int ttlMAX;
	float currentTime;
	int currentAnim;
};
typedef struct AnimationID AnimationID;

struct AnimationTiled
{
	int* id;
	sfBool* needRotate;
	AnimationID* spriteAnim;
};
typedef struct AnimationTiled AnimationTiled;

struct MapCollision
{
	int id;
	sfVector2f pos;
	sfVector2f size;
};
typedef struct MapCollision MapCollision;

struct ProprietySprite
{
	int id;
	char name[999];
};
typedef struct ProprietySprite ProprietySprite;


//struct Profondeur
//{
//	int id;
//	sfVector2f pos;
//	char name[999];
//};
//typerdef struct Profondeur Profondeur;

//IntroPointSound
struct IntroPointSound
{
	Sound* electricity;
	Sound* cat;
	Sound* ventilation;
	Sound* console;
};
typedef struct IntroPointSound IntroPointSound;

//IslandPointSound
struct IslandPointSound
{
	Sound* waterfall;
	Sound* fire;
	Sound* lake;
	Sound* fish;
	Sound* well;
};
typedef struct IslandPointSound IslandPointSound;

//IslandPointSound
struct JunglePointSound
{
	Sound* snake;
};
typedef struct JunglePointSound JunglePointSound;

struct MapInteraction
{
	int id;
	sfVector2f pos;
	sfVector2f size;
	char name[999];
};
typedef struct MapInteraction MapInteraction;

struct MapDestructible
{
	int id;
	sfVector2f pos;
	sfVector2f size;
	sfBool active;
	sfBool recup;

	char name[999];
};
typedef struct MapDestructible MapDestructible;

struct MapPoint
{
	int id;
	sfVector2i pos;
	sfBool active;
	char name[999];
};
typedef struct MapPoint MapPoint;

struct MapNPC
{
	int id;
	sfVector2i pos;
	char name[999];
};
typedef struct MapNPC MapNPC;

struct MapPointSound
{
	int id;
	sfVector2i pos;
	char name[999];
	float minDistance;
};
typedef struct MapPointSound MapPointSound;

struct MapTriggerSound
{
	int id;
	sfVector2f pos;
	sfVector2f size;
	char name[999];
};
typedef struct MapTriggerSound MapTriggerSound;

struct MapLabyrinthe
{
	int id;
	sfVector2f pos;
	sfVector2f size;
	char name[999];
};
typedef struct MapLabyrinthe MapLabyrinthe;

struct MapTriggerIA
{
	int id;
	sfVector2f pos;
	sfVector2f size;
	sfBool done;
	char name[999];
};
typedef struct MapTriggerIA MapTriggerIA;

struct MapParameter
{
	int witdh;
	int height;
	int tilewitdh;
	int tileheight;
	int columns;
	int nbCalque;

	int* id;
	MapID* mapID;
	MapCollision* mapCollision;
	int nbCollision;
	//int nbObjectDecor;
	//Profondeur* prof;
	AnimationTiled animTiled;
	//
	int nbAnimSprite;
	int nbAnimSpriteVillage;

	MapInteraction* mapInteraction;
	int nbInteraction;

	MapDestructible* mapDestructible;
	int nbDestructible;

	//point pour spwan etc
	MapPoint* mapPoint;
	int nbPoint;

	//PNJ sur la map
	MapNPC* mapNPC;
	int nbNPC;

	//Pour les tuiles qui changent en fonction d'un evenement
	ProprietySprite* proprietySprite;
	int nbProprietySprite;

	MapPointSound* mapPointSound;
	int nbPointSound;

	//point pour les sons sur les maps
	IntroPointSound introPointSound;
	IslandPointSound islandPointSound;
	JunglePointSound junglePointSound;
	int nbElec;
	int nbCat;
	int nbVent;
	int nbConsole;
	int nbWaterfall;
	int nbWell;
	int nbFire;
	int nbLake;
	int nbFish;
	int nbSnake;

	MapTriggerSound* mapTriggerSound;
	int nbTriggerSound;

	MapLabyrinthe* mapLabyrinthe;
	int nbMapLabyrinthe;

	MapTriggerIA* mapTriggerIA;
	int nbMapTriggerIA;
};
typedef struct MapParameter MapParameter;

#endif