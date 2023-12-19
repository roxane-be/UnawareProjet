#include "DisplayTutoDialogue.h"

void DisplayTutoDialogue(GameData* _gd)
{
	BlitSprite(_gd->enigme.dialogue.backgroundDialogue, 0, 0, 0, 1, 1, _gd);
	BlitSprite(_gd->enigme.dialogue.backgroundTutoDialogue, -17, 30, 0, 1, 1, _gd);
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.dialogue.retourDialogue.forme, NULL);

	BlitSprite(_gd->enigme.dialogue.retourDialogue.buttonSprite[0], _gd->enigme.dialogue.retourDialogue.pos.x, _gd->enigme.dialogue.retourDialogue.pos.y, 0, 1, 1, _gd);

	if (_gd->enigme.dialogue.onSpriteRetourDialogue == sfTrue)
	{
		BlitSprite(_gd->enigme.dialogue.retourDialogue.buttonSprite[1], _gd->enigme.dialogue.retourDialogue.pos.x, _gd->enigme.dialogue.retourDialogue.pos.y, 0, 1, 1, _gd);
	}

	if (_gd->enigme.dialogue.clickRetourDialogue == sfTrue)
	{
		BlitSprite(_gd->enigme.dialogue.retourDialogue.buttonSprite[2], _gd->enigme.dialogue.retourDialogue.pos.x, _gd->enigme.dialogue.retourDialogue.pos.y, 0, 1, 1, _gd);
	}
}