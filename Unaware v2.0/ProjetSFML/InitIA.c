#include "InitIA.h"

void InitIA(GameData* _gd)
{
	_gd->ia_ship.dialogueBox = LoadSprite("../Ressources/Assets/Interface/boite_dialogue_ia.png", 0);

	_gd->ia_ship.sentenceIA[intro_1] = SENTENCE_INTRO_1;
	_gd->ia_ship.sentenceIA[intro_2] = SENTENCE_INTRO_2;
	_gd->ia_ship.sentenceIA[intro_3] = SENTENCE_INTRO_3;
	_gd->ia_ship.sentenceIA[fail_1] = SENTENCE_FAIL_1;
	_gd->ia_ship.sentenceIA[hub_1] = SENTENCE_HUB_1;
	_gd->ia_ship.sentenceIA[hub_2] = SENTENCE_HUB_2;
	_gd->ia_ship.sentenceIA[hub_3] = SENTENCE_HUB_3;
	_gd->ia_ship.sentenceIA[fail_2] = SENTENCE_FAIL_2;
	_gd->ia_ship.sentenceIA[end_1] = SENTENCE_END_1;
	_gd->ia_ship.sentenceIA[end_2] = SENTENCE_END_2;
	_gd->ia_ship.sentenceIA[end_3] = SENTENCE_END_3;

	_gd->ia_ship.actif = sfFalse;
	_gd->ia_ship.timerText = 0;

	{
		//dialogue
		_gd->texts.ia_voice.text = LoadText("../Ressources/Text/nasalization.ttf","", 1);
		sfText_setCharacterSize(_gd->texts.ia_voice.text, 23);
		_gd->texts.ia_voice.pos.x = _gd->sizeWindow.width / 2 - 150;
		_gd->texts.ia_voice.pos.y = 900;
	}
}