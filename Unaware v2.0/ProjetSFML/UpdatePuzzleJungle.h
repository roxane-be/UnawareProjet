#ifndef UPDATEPUZZLEJUNGLE_H
#define UPDATEPUZZLEJUNGLE_H

#include "definition.h"

int GetIdPiecePuzzleJungle(GameData*, sfVector2f);
int GetIdPuzzleJungle(GameData*, sfVector2f);
int ValidatePuzzleSolution2(GameData*);
int ValidatePuzzleSolution1(GameData*);

void ValidatePuzzle(GameData*, int);
void UpdatePuzzleJungle(GameData*);

#endif