#ifndef DEFINITIONCUTSCENE_H
#define DEFINITIONCUTSCENE_H

#define NB_CUTSCENE_SHIP_INTRO 3
#define NB_CUTSCENE_SHIP_DOOR 3
#define NB_CUTSCENE_SHIP_SLEEP 4

#define NB_CUTSCENE_ISLAND_INTRO 2
#define NB_CUTSCENE_ISLAND_LEAVE_HOUSE 2
#define NB_CUTSCENE_ISLAND_PONT 3
#define NB_CUTSCENE_ISLAND_DIALOGUE 3
#define NB_CUTSCENE_ISLAND_END 2

#define NB_CUTSCENE_BEDROOM_INTRO 4
#define NB_CUTSCENE_BEDROOM_EXIT 2


#define NB_CUTSCENE_JUNGLE_END 9
#define NB_CUTSCENE_JUNGLE_REVEIL 1

#define NB_CUTSCENE_END_REVEIL 3
#define NB_CUTSCENE_END_CASQUE 3
#define NB_CUTSCENE_END_END 5

#define NB_CUTSCENE_FAIL 2

#define TIME_SHIP_INTRO_0 5.5 //5.5
#define TIME_SHIP_DOOR 1.f
#define TIME_SHIP_SLEEP 4

#define TIME_ISLAND_INTRO 4
#define TIME_ISLAND_LEAVE_HOUSE 4
#define TIME_ISLAND_PONT 4
#define TIME_ISLAND_DIALOGUE 2
#define TIME_ISLAND_END 1.5

#define TIME_BEDROOM_INTRO 2.5
#define TIME_BEDROOM_EXIT 4

#define TIME_CUTSCENE_JUNGLE_END 1
#define TIME_CUTSCENE_JUNGLE_REVEIL 6


#define TIME_CUTSCENE_END_REVEIL 5
#define TIME_CUTSCENE_END_CASQUE 1
#define TIME_CUTSCENE_END_END 5.5

#define TIME_FAIL 2.5
//4 pour les cinematiques

struct Cinematique
{
	float currentTime;
	int currentAnim;
	sfSprite* shipIntro[NB_CUTSCENE_SHIP_INTRO];
	sfSprite* shipDoor[NB_CUTSCENE_SHIP_DOOR];
	sfSprite* shipSleep[NB_CUTSCENE_SHIP_SLEEP];
	sfSprite* IslandIntro[NB_CUTSCENE_ISLAND_INTRO];
	sfSprite* IslandPont[NB_CUTSCENE_ISLAND_PONT];
	sfSprite* IslandLeaveHouse[NB_CUTSCENE_ISLAND_LEAVE_HOUSE];
	sfSprite* IslandDialogue[NB_CUTSCENE_ISLAND_DIALOGUE];
	sfSprite* IslandEnd[NB_CUTSCENE_ISLAND_END];
	sfSprite* BedRoomIntro[NB_CUTSCENE_BEDROOM_INTRO];
	sfSprite* BedRoomExit[NB_CUTSCENE_BEDROOM_EXIT];
	sfSprite* JungleEnd[NB_CUTSCENE_JUNGLE_END];
	sfSprite* JungleReveil[NB_CUTSCENE_JUNGLE_REVEIL];
	sfSprite* EndReveil[NB_CUTSCENE_END_REVEIL];
	sfSprite* EndCasque[NB_CUTSCENE_END_CASQUE];
	sfSprite* EndEnd[NB_CUTSCENE_END_END];
	sfSprite* Fail[NB_CUTSCENE_END_END];

	sfVector3f pos;
	int opacity;
	sfSprite* blackScreen;
	sfSprite* WhiteScreen;
	sfBool exitHouse;
};
typedef struct Cinematique Cinematique;


//Gestion de l'IA
#define NB_SENTENCE_IA 12

#define SENTENCE_INTRO_1 "*Bzz*.. Attention.. Tu dois.. *zz*"
#define SENTENCE_INTRO_2 "Survivre.. *Bzzz*! Lit.. *Aarh*"
#define SENTENCE_INTRO_3 "Noon.. Cham-*bzz*-re.."
#define SENTENCE_FAIL_1 "Recomm-*bzz*-ence.."
#define SENTENCE_HUB_1 "Merci.. Je me sens bien mieux !\nEst-ce-que.. Ta mémoire ?..\n..\nJe vois."
#define SENTENCE_HUB_2 "Ce n'est pas le moment pour\nsortir, bientôt tu pourras..\nMais sois patient, d'accord ?"
#define SENTENCE_HUB_3 "Je me rends compte que tu es\nencore un peu confus.\nRetourne t'allonger alors,\nje vais te guider.. Jusqu'au bout."
#define SENTENCE_FAIL_2 "Je sais que tu n'es pas\nloin du but..\nJ'attends ton retour."
#define SENTENCE_END_1 "Je vois que tu te souviens\nà présent. Je suis soulagée .."
#define SENTENCE_END_2 "Je compte sur toi pour\nt'en sortir cette fois aussi\nD'accord ?"
#define SENTENCE_END_3 "Et.. Merci.. Je veillerais\ntoujours sur toi. Il est\ntemps pour toi de partir\nd'ici et de survivre.."

enum IAState
{
	intro_1, //quand on avance dans la map au début du jeu
	intro_2, // pour nous dire d'aller dormir
	intro_3, // si le joueur va de l'autre côté du chemin
	fail_1, //si fail du monde island
	hub_1, // au retour dans le monde devant la console
	hub_2, // a voir
	hub_3, // a voir
	fail_2, // si fail du monde jungle
	end_1,
	end_2,
	end_3
};
typedef enum IAState IAState;

struct IA_SHIP
{
	sfSprite* dialogueBox;
	char* sentenceIA[NB_SENTENCE_IA];
	int whereTalking;
	IAState state;
	sfBool actif;
	float timerText;
};
typedef struct IA_SHIP IA_SHIP;


#endif // !DEFINITIONCUTSCENE__H
