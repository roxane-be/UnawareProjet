#ifndef UPDATEINGAME_H
#define UPDATEINGAME_H

#include "definition.h"
#include "Init.h"

//update des animations des npc
void UpdateAnimationNPC(GameData*);
//anime des boutons E et space
void UpdateAnimationInterraction(GameData*);
//Camera
void UpdateCamera(GameData*);
void UpdatePointPlayerSoundIntro(GameData*);
void UpdatePointPlayerSoundIsland(GameData* _gd);
void UpdatePointPlayerSoundHub(GameData* _gd);
void UpdatePointPlayerSoundJungle(GameData* _gd);
void UpdatePointPlayerSoundShipEnd(GameData* _gd);

//parallaxe
void UpdateSkyIsland(GameData*);

#endif // !UPDATEINGAME_H
