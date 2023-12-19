#ifndef UPDATE_H
#define UPDATE_H

#include "definition.h"
//enigme
#include "UpdateMastermindBox.h"
#include "UpdateMastermindIntro.h"
#include "UpdatePuzzle.h"
#include "UpdateDialogue.h"
#include "UpdatePlaqueVis.h"
#include "UpdateCable.h"
#include "UpdateVoltage.h"
#include "UpdateDiode.h"
#include "UpdatePuzzleJungle.h"
#include "UpdateDecryptage.h"
//tuto
#include "UpdateTutoMastermindIntro.h"
#include "UpdateTutoPuzzle.h"
#include "UpdateTutoDialogue.h"
#include "UpdateTutoBox.h"
#include "UpdateTutoDiode.h"
#include "UpdateTutoPuzzleJungle.h"
#include "UpdateTutoDecryptage.h"
//state
#include "UpdateInGame.h"
#include "UpdateMenu.h"
//map
#include "UpdateIntroMap.h"
#include "UpdateIslandMap.h"
#include "UpdateBedRoomMap.h"
#include "UpdateJungleMap.h"
#include "UpdateShipEndMap.h"

//autres
#include "UpdateTimer.h"
#include "UpdatePlayer.h"
#include "UpdateCutScene.h"
#include "UpdateSelecteurPerso.h"
#include "UpdateIA.h"

void UpdateInGame(GameData*);
void UpdatePause(GameData*);
void UpdateAllGame(GameData*);


#endif