#ifndef DEFINITIONSENTITIES_H
#define DEFINITIONSENTITIES_H

//Animation
struct Sequence
{
	int begin;
	int end;
	float total;
};
typedef struct Sequence Sequence;

struct PersoDef
{
	sfSprite** Timeline;
	Sequence sequence[8];
};
typedef struct PersoDef PersoDef;

struct NPCDef
{
	sfSprite** Timeline;
	Sequence sequence[8];
};
typedef struct NPCDef NPCDef;

//Horloge animation
struct Clock
{
	float tempsTotal;
	float tempsCourant;
	sfClock* tempClock;
};
typedef struct Clock Clock;

//Audio
struct Sound
{
	sfSoundBuffer* buffer;
	sfSound* sound;
	float volume;
	float loop;
	sfBool isPlaying;
};
typedef struct Sound Sound;

//Direction
enum Direction
{
	haut,
	bas,
	droite,
	gauche
};
typedef enum Direction Direction;

//Player
struct Personnage
{
	sfSprite* bulleInteraction[2];
	sfSprite* bulleDialogue[2];
	int currentAnimInterraction;
	float timeInterraction;
	sfVector2f pos;
	PersoDef* persoDef;
	int idSeq;
	int currentAnim;
	Direction dir;
	float currentTime;
	//autres infos perso
	//si le joueur est actuellement en collision avec quelque chose pour interagir avec
	sfBool interaction;
	//Audio joueur
	Sound stepSound;
	char stepName[999];
};
typedef struct Personnage Personnage;

//NPC
struct NPC
{
	sfVector2f pos;
	sfSprite* pnjBox;
	//Autres infos NPC
	sfSprite* dialogueBox;
	//Anim
	NPCDef npcDef;
	int idSeq;
	int currentAnim;
	Direction dir;
	float currentTime;
	Sound voice;
};
typedef struct NPC NPC;

//Animation
enum TypeAnim
{
	hautM,
	basM,
	droiteM,
	gaucheM,
	hautI,
	basI,
	droiteI,
	gaucheI
};
typedef enum TypeAnim TypeAnim;



#endif // !DEFINITIONENTITIES_H
