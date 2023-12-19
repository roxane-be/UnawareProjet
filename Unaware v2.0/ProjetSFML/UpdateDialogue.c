#include "UpdateDialogue.h"

void UpdateText(GameData* _gd, int _whoTalk)
{
	char stringDraw[999];
	sprintf(stringDraw, "%s", _gd->enigme.dialogue.sentence[_whoTalk]);
	sfText_setString(_gd->texts.dialogue.text, stringDraw);
}

void UpdateButtonDialgoue(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos = { 0, 0 };
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	//bouton d'aide
	if (isCollidingWithMouse(_gd->enigme.dialogue.helpDialogue.forme, tempPos, 0))
	{
		_gd->enigme.dialogue.onSpriteHelpDialogue = sfTrue;
	}
	else
	{
		_gd->enigme.dialogue.onSpriteHelpDialogue = sfFalse;
	}

	//bouton valider
	if (isCollidingWithMouse(_gd->enigme.dialogue.validatePassword.forme, tempPos, 0))
	{
		_gd->enigme.dialogue.onSpriteValidateDialogue = sfTrue;
	}
	else
	{
		_gd->enigme.dialogue.onSpriteValidateDialogue = sfFalse;
	}

	//bouton quitter
	if (isCollidingWithMouse(_gd->enigme.dialogue.quitDialogue.forme, tempPos, 0))
	{
		_gd->enigme.dialogue.onSpriteQuitDialogue = sfTrue;
	}
	else
	{
		_gd->enigme.dialogue.onSpriteQuitDialogue = sfFalse;
	}
}

void UpdateDialogue(GameData* _gd)
{
	if (_gd->enigme.dialogue.state == INDIALOGUE)
	{
		UpdateText(_gd, _gd->enigme.dialogue.whoTalk);
	}

	if (_gd->enigme.dialogue.state == DOOR)
	{
		char stringDraw[70];
		sprintf(stringDraw, "%s", _gd->enigme.dialogue.answerPlayer);
		sfText_setString(_gd->texts.doorEnigme.text, stringDraw);
		UpdateButtonDialgoue(_gd);
	}

	//evolution pnj au cours du temsp  
	{
		//si le joueur a parlé a tous les pnj de l'enigme
		if (_gd->enigme.dialogue.isTalk[PNJ_0] == sfTrue
			&& _gd->enigme.dialogue.isTalk[PNJ_1] == sfTrue
			&& _gd->enigme.dialogue.isTalk[PNJ_2] == sfTrue
			&& _gd->enigme.dialogue.isTalk[PNJ_3] == sfTrue)
		{
			_gd->enigme.dialogue.sentence[PNJ_HELP] = SENTENCE_PNJ_HELP_2;
		}
		//si le joueur a au moins parlé a un pnj 
		else if (_gd->enigme.dialogue.isTalk[PNJ_0] == sfTrue
			|| _gd->enigme.dialogue.isTalk[PNJ_1] == sfTrue
			|| _gd->enigme.dialogue.isTalk[PNJ_2] == sfTrue
			|| _gd->enigme.dialogue.isTalk[PNJ_3] == sfTrue)
		{
			_gd->enigme.dialogue.sentence[PNJ_HELP] = SENTENCE_PNJ_HELP_1;
		}
		//sinon phrase de base(init)
	}
}