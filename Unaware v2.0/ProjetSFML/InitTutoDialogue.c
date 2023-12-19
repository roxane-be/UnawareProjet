#include "InitTutoDialogue.h"

void InitTutoDialogue(GameData* _gd)
{
	_gd->enigme.dialogue.backgroundTutoDialogue = LoadSprite("../Ressources/Assets/Dialogue/aide_mdp1.png", 0);

	_gd->enigme.dialogue.retourDialogue.buttonSprite[0] = LoadSprite("../Ressources/Assets/Puzzle/bouton/retour_1.png", 0);
	_gd->enigme.dialogue.retourDialogue.buttonSprite[1] = LoadSprite("../Ressources/Assets/Puzzle/bouton/retour_2.png", 0);
	_gd->enigme.dialogue.retourDialogue.buttonSprite[2] = LoadSprite("../Ressources/Assets/Puzzle/bouton/retour_3.png", 0);

	_gd->enigme.dialogue.retourDialogue.size.x = 170;
	_gd->enigme.dialogue.retourDialogue.size.y = 150;

	_gd->enigme.dialogue.retourDialogue.pos.x = ((int)_gd->sizeWindow.width / 2) - (_gd->enigme.dialogue.retourDialogue.size.x / 2);
	_gd->enigme.dialogue.retourDialogue.pos.y = 850;

	_gd->enigme.dialogue.retourDialogue.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.dialogue.retourDialogue.forme, _gd->enigme.dialogue.retourDialogue.pos, _gd->enigme.dialogue.retourDialogue.size.x, _gd->enigme.dialogue.retourDialogue.size.y, 0);
}