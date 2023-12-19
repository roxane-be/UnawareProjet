#ifndef UPDATEMASTERMINDINTRO_H
#define UPDATEMASTERMINDINTRO_H

#include "definition.h"
#include "InitCutScene.h"
#include "InitMastermindIntro.h"

void isValidateIntro(GameData*);
void ChoiceNumberIntro(GameData*, int);
//anim pour les fleches
void UpdateAnimationButtonMastermindIntro(GameData*, int);
//update pour les sprites d'interface
void UpdateButtonMastermindIntro(GameData* _gd);

#endif // 