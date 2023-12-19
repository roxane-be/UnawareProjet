#ifndef INPUTMENU_H
#define INPUTMENU_H

#include "definition.h"
#include "InitCutScene.h"
#include "InitMenu.h"
#include "Init.h"

//input pour l'enigme de dialogue de l'island
void InputMenu(GameData*);
void InputCredit(GameData*);
void InputOptions(GameData*);
void InputPause(GameData*);
void InputVolume(GameData*);
void InputControle(GameData*);

void MuteSound(GameData*);
void PlaySoundAgain(GameData*);




#endif