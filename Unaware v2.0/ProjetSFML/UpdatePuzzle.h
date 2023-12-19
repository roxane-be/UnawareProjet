#ifndef UPDATEPUZZLE_H
#define UPDATEPUZZLE_H

#include "definition.h"

//permet de recup l'id sur la partie puzzle
int GetIdPuzzle(GameData*, sfVector2f);
//permet de recup l'id des pieces
int GetIdPiece(GameData*, sfVector2f);
//update pour les boutons
void UpdatePuzzle(GameData*);

#endif