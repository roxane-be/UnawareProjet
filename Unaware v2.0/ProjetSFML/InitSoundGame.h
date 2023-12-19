#ifndef INITSOUNDGAME_H
#define INITSOUNDGAME_H

#include "definition.h"

void InitSoundCutScenes(GameData*);
void InitSoundAmbience(GameData*);
void InitSoundIntro(GameData*);
void InitSoundMenu(GameData*);
void InitSoundWorld1(GameData*);
void DestroySoundIntro(GameData*);
void DestroySoundWorld1(GameData*);
void DestroySoundWorld2(GameData*);
void InitSoundHub(GameData*);
void DestroySoundHub(GameData*);
void InitSoundWorld2(GameData*);
void InitSoundShipEnd(GameData*);
void DestroySoundShipEnd(GameData*);
#endif