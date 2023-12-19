#ifndef DISPLAY_H
#define DISPLAY_H

#include "definition.h"

//enigme
#include "DisplayMastermindIntro.h"
#include "DisplayPuzzle.h"
#include "DisplayMastermindBox.h"
#include "DisplayPlaqueVis.h"
#include "DisplayDialogue.h"
#include "DisplayCable.h"
#include "DisplayVoltage.h"
#include "DisplayDiode.h"
#include "DisplayPuzzleJungle.h"
#include "DisplayDecryptage.h"
//tuto
#include "DisplayTutoMastermindIntro.h"
#include "DisplayTutoPuzzle.h"
#include "DisplayTutoDialogue.h"
#include "DisplayTutoBox.h"
#include "DisplayTutoDiode.h"
#include "DisplayTutoPuzzleJungle.h"
#include "DisplayTutoDecryptage.h"
//menu
#include "DisplayMenu.h"
//maps
#include "DisplayIntroMap.h"
#include "DisplayIslandMap.h"
#include "DisplayBedRoomMap.h"
#include "DisplayJungleMap.h"
#include "DisplayShipEndMap.h"
//autre
#include "DisplayTimer.h"
#include "DisplayCutScene.h"
#include "DisplayIA.h"

void DisplayInGame(GameData*);
void DisplayMenu(GameData*);
void DisplayAllGame(GameData*);

#endif
