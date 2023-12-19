#ifndef UPDATEPLAYER_H
#define UPDATEPLAYER_H

#include "definition.h"
#include "Init.h"
#include "UpdateInGame.h"
#include "UpdateIA.h"

//collision avec la map
int CollisionPlayer(GameData*);
//trigger dialogue IA
void TriggerIA(GameData*);
//collision des destructible et supprime
int TriggerPlayerDestructible(GameData* _gd);

//Permet de gerer les interaction de l'intro
int TriggerPlayerInteractionIntro(GameData*, int*);
//permet de gerer les interaction de island
int TriggerPlayerInteractionIsland(GameData*, int*, int*);
//permet de gerer les interaction de la chambre
int TriggerPlayerInteractionBedRoom(GameData*, int*);
//permet de gerer les interaction de la jungle
int TriggerPlayerInteractionJungle(GameData*, int*, int*);
//permet de gerer les interaction de le vaisseau de fin
int TriggerPlayerInteractionShipEnd(GameData*, int*);

//zone de changement pour le son
void TriggerPlayerSoundIntro(GameData*);
void TriggerPlayerSoundIsland(GameData*);

//Interraction avec E dans intro
void InteractionPlayerIntro(GameData*, int);
//Interraction avec E dans iles
void InteractionPlayerIsland(GameData*, int, int);
//Interraction avec E dans chambre
void InteractionPlayerBedRoom(GameData*, int);
//Interraction avec E dans jungle
void InteractionPlayerJungle(GameData* , int , int);

//Interraction avec E dans la map de fun
void InteractionPlayerShipEnd(GameData*, int);
//Update globale pour le player
void UpdatePlayer(GameData*);


#endif // !UPDATEINGAME_H
