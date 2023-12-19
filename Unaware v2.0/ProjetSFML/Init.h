#ifndef INIT_H
#define INIT_H

#include "definition.h"
//enigme
#include "InitMastermindIntro.h"
#include "InitMastermindBox.h"
#include "InitPuzzle.h"
#include "InitDialogue.h"
#include "InitPlaqueVis.h"
#include "InitCable.h"
#include "InitVoltage.h"
#include "InitDiode.h"
#include "InitPuzzleJungle.h"
#include "InitDecryptage.h"
//map
#include "InitIntroMap.h"
#include "InitIslandMap.h"
#include "InitBedRoomMap.h"
#include "InitJungleMap.h"
#include "InitShipEndMap.h"
//state
#include "InitMenu.h"
//autres
#include "InitAnim.h"
#include "InitSoundGame.h"
#include "InitCutScene.h"
#include "InitIA.h"


//init le début du jeu
void InitIntro(GameData*);
//
void ReInitIntro(GameData* _gd);
void ReInitBedRoom(GameData* _gd);

//init l'ile 
void InitIsland(GameData*);
//init de la chambre
void InitBedRoom(GameData*);
void InitJungle(GameData*);
void InitShipEnd(GameData*);
void InitAllGame(GameData*);

#endif // !INITIALISATION_H