#include "DisplayDialogue.h"

void DisplayDialogue(GameData* _gd)
{
	//modifier le rendu
	if (_gd->enigme.dialogue.state == INDIALOGUE)
	{
		BlitSprite(_gd->npc[0].dialogueBox, 600, 650, 0, 1.3, 1.3, _gd);

		//tete des pnj dans cadre
		if (_gd->enigme.dialogue.whoTalk == PNJ_HELP)
		{
			BlitSprite(_gd->npc[0].pnjBox, 1140, 688, 0, 1, 1, _gd); //pnj d'aide
		}
		else if (_gd->enigme.dialogue.whoTalk == PNJ_0)
		{
			BlitSprite(_gd->npc[3].pnjBox, 1205, 731, 0, 1.3, 1.3, _gd); //pnj casquette
		}
		else if (_gd->enigme.dialogue.whoTalk == PNJ_1)
		{
			BlitSprite(_gd->npc[2].pnjBox, 1213, 725, 0, 1.3, 1.3, _gd); //pnj fumé
		}
		else if (_gd->enigme.dialogue.whoTalk == PNJ_2)
		{
			BlitSprite(_gd->npc[1].pnjBox, 1212, 725, 0, 1.3, 1.3, _gd); //pnj fermiere
		}
		else if (_gd->enigme.dialogue.whoTalk == PNJ_3)
		{
			BlitSprite(_gd->npc[4].pnjBox, 1205, 724, 0, 1.3, 1.3, _gd); //pnj tailleur
		}

		BlitText(_gd->texts.dialogue.text,
			_gd->texts.dialogue.pos.x,
			_gd->texts.dialogue.pos.y,
			sfBlack, (sfVector2f) { 1, 1 }, _gd->window);
	}

	if (_gd->enigme.dialogue.state == DOOR &&
		_gd->enigme.dialogue.resolvedDream_1 == sfFalse)
	{
		BlitSprite(_gd->enigme.dialogue.backgroundDialogue, 0, 0, 0, 1, 1, _gd);

		BlitSprite(_gd->enigme.dialogue.helpDialogue.buttonSprite[0], _gd->enigme.dialogue.helpDialogue.pos.x - 7, _gd->enigme.dialogue.helpDialogue.pos.y - 5, 0, 1, 1, _gd);

		//valider
		BlitSprite(_gd->enigme.dialogue.validatePassword.buttonSprite[0], _gd->enigme.dialogue.validatePassword.pos.x - 30, _gd->enigme.dialogue.validatePassword.pos.y - 20, 0, 1, 1, _gd);

		if (_gd->enigme.dialogue.onSpriteValidateDialogue == sfTrue)
		{
			BlitSprite(_gd->enigme.dialogue.validatePassword.buttonSprite[1], _gd->enigme.dialogue.validatePassword.pos.x - 30, _gd->enigme.dialogue.validatePassword.pos.y - 20, 0, 1, 1, _gd);
		}

		if (_gd->enigme.dialogue.clickHelpDialogue == sfTrue)
		{
			BlitSprite(_gd->enigme.dialogue.helpDialogue.buttonSprite[2], _gd->enigme.dialogue.helpDialogue.pos.x - 7, _gd->enigme.dialogue.helpDialogue.pos.y - 5, 0, 1, 1, _gd);
		}

		//Bouton quitter
		BlitSprite(_gd->enigme.dialogue.quitDialogue.buttonSprite[0], _gd->enigme.dialogue.quitDialogue.pos.x, _gd->enigme.dialogue.quitDialogue.pos.y, 0, 1, 1, _gd);

		if (_gd->enigme.dialogue.onSpriteQuitDialogue == sfTrue)
		{
			BlitSprite(_gd->enigme.dialogue.quitDialogue.buttonSprite[1], _gd->enigme.dialogue.quitDialogue.pos.x, _gd->enigme.dialogue.quitDialogue.pos.y, 0, 1, 1, _gd);
		}

		if (_gd->enigme.dialogue.clickQuitDialogue == sfTrue)
		{
			BlitSprite(_gd->enigme.dialogue.quitDialogue.buttonSprite[2], _gd->enigme.dialogue.quitDialogue.pos.x, _gd->enigme.dialogue.quitDialogue.pos.y, 0, 1, 1, _gd);
		}

		//Bouton help
		if (_gd->enigme.dialogue.onSpriteHelpDialogue == sfTrue)
		{
			BlitSprite(_gd->enigme.dialogue.helpDialogue.buttonSprite[1], _gd->enigme.dialogue.helpDialogue.pos.x - 7, _gd->enigme.dialogue.helpDialogue.pos.y - 5, 0, 1, 1, _gd);
		}

		if (_gd->enigme.dialogue.clickHelpDialogue == sfTrue)
		{
			BlitSprite(_gd->enigme.dialogue.helpDialogue.buttonSprite[2], _gd->enigme.dialogue.helpDialogue.pos.x - 7, _gd->enigme.dialogue.helpDialogue.pos.y - 5, 0, 1, 1, _gd);
		}

		BlitText(_gd->texts.doorEnigme.text,
			_gd->texts.doorEnigme.pos.x,
			_gd->texts.doorEnigme.pos.y,
			sfBlack, (sfVector2f) { 1, 1 }, _gd->window);
		//a supp
		_gd->player.interaction = sfFalse;
	}
}