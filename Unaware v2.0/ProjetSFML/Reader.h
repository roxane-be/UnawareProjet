#ifndef READER__H
#define READER__H

#include "definition.h"

//void ReadFileTiled(GameData*);
void ReadFileTiledLayer(MapParameter*, char*);
void ReadFileTiledCollision(MapParameter*, char*);
void ReadFileTiledInteraction(MapParameter*, char*);
void ReadFileTiledDestructible(MapParameter*, char*);
void ReadFileTiledPoint(MapParameter*, char*);
void ReadFileTiledAnim(MapParameter*, char*);
void ReadFileTiledNPC(MapParameter*, char*);
void ReadFileTiledPointSound(MapParameter*, char*);
void ReadFileTiledTriggerSound(MapParameter*, char*);
void ReadFileTiledTriggerIA(MapParameter*, char*);
void ReadFileTiledLabyrinthe(MapParameter* , char* );

#endif