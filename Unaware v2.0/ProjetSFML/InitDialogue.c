#include "InitDialogue.h"

void InitButtonHelpDialogue(GameData* _gd)
{
	_gd->enigme.dialogue.helpDialogue.buttonSprite[0] = LoadSprite("../Ressources/Assets/Dialogue/aide__1.png", 0);
	_gd->enigme.dialogue.helpDialogue.buttonSprite[1] = LoadSprite("../Ressources/Assets/Dialogue/aide__2.png", 0);
	_gd->enigme.dialogue.helpDialogue.buttonSprite[2] = LoadSprite("../Ressources/Assets/Dialogue/aide__3.png", 0);

	_gd->enigme.dialogue.clickHelpDialogue = sfFalse;
	_gd->enigme.dialogue.onSpriteHelpDialogue = sfFalse;

	_gd->enigme.dialogue.helpDialogue.pos.x = _gd->sizeWindow.width / 2 + 170;
	_gd->enigme.dialogue.helpDialogue.pos.y = 200;

	_gd->enigme.dialogue.helpDialogue.size.x = 400;
	_gd->enigme.dialogue.helpDialogue.size.y = 200;

	_gd->enigme.dialogue.helpDialogue.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.dialogue.helpDialogue.forme, _gd->enigme.dialogue.helpDialogue.pos, _gd->enigme.dialogue.helpDialogue.size.x, _gd->enigme.dialogue.helpDialogue.size.y, 0);
}

void InitButtonValidateDialogue(GameData* _gd)
{
	//Partie a décommenter lorsqu'on aura les assets du bouton valider
	_gd->enigme.dialogue.validatePassword.buttonSprite[0] = LoadSprite("../Ressources/Assets/Dialogue/entree.png", 0);
	_gd->enigme.dialogue.validatePassword.buttonSprite[1] = LoadSprite("../Ressources/Assets/Dialogue/entree2.png", 0);
	//_gd->enigme.dialogue.validatePassword.buttonSprite[2] = LoadSprite("../Ressources/Assets/Dialogue/____3.png", 0);


	_gd->enigme.dialogue.validatePassword.pos.x = _gd->sizeWindow.width / 2 + 450;
	_gd->enigme.dialogue.validatePassword.pos.y = 750;

	_gd->enigme.dialogue.validatePassword.size.x = 200;
	_gd->enigme.dialogue.validatePassword.size.y = 150;

	_gd->enigme.dialogue.validatePassword.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.dialogue.validatePassword.forme, _gd->enigme.dialogue.validatePassword.pos, _gd->enigme.dialogue.validatePassword.size.x, _gd->enigme.dialogue.validatePassword.size.y, 0);
	sfRectangleShape_setOutlineColor(_gd->enigme.dialogue.validatePassword.forme, sfBlack);
}

void InitButtonQuitDialogue(GameData* _gd)
{
	_gd->enigme.dialogue.quitDialogue.buttonSprite[0] = LoadSprite("../Ressources/Assets/Dialogue/quitter_1.png", 0);
	_gd->enigme.dialogue.quitDialogue.buttonSprite[1] = LoadSprite("../Ressources/Assets/Dialogue/quitter_2.png", 0);
	_gd->enigme.dialogue.quitDialogue.buttonSprite[2] = LoadSprite("../Ressources/Assets/Dialogue/quitter_3.png", 0);

	_gd->enigme.dialogue.quitDialogue.pos.x = _gd->sizeWindow.width - 200;
	_gd->enigme.dialogue.quitDialogue.pos.y = 25;

	_gd->enigme.dialogue.quitDialogue.size.x = 150;
	_gd->enigme.dialogue.quitDialogue.size.y = 150;

	_gd->enigme.dialogue.quitDialogue.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.dialogue.quitDialogue.forme, _gd->enigme.dialogue.quitDialogue.pos, _gd->enigme.dialogue.quitDialogue.size.x, _gd->enigme.dialogue.quitDialogue.size.y, 0);
}


void InitDialogue(GameData* _gd)
{
	InitButtonHelpDialogue(_gd);
	InitButtonValidateDialogue(_gd);
	InitButtonQuitDialogue(_gd);
	InitTutoDialogue(_gd);

	_gd->enigme.dialogue.backgroundDialogue = LoadSprite("../Ressources/Assets/Dialogue/background.png", 0);

	_gd->player.pos.x = 100;
	_gd->player.pos.y = 100;
	_gd->player.interaction = sfFalse;
	_gd->enigme.dialogue.state = NONE;

	_gd->enigme.dialogue.sentence[PNJ_0] = SENTENCE_PNJ_0_1;
	_gd->enigme.dialogue.sentence[PNJ_1] = SENTENCE_PNJ_1_1;
	_gd->enigme.dialogue.sentence[PNJ_2] = SENTENCE_PNJ_2_1;
	_gd->enigme.dialogue.sentence[PNJ_3] = SENTENCE_PNJ_3_1;
	_gd->enigme.dialogue.sentence[PNJ_HELP] = SENTENCE_PNJ_HELP_0_1;
	_gd->enigme.dialogue.whoTalk = PNJ_HELP;

	_gd->enigme.dialogue.resolvedDream_1 = sfFalse;
	strcpy(_gd->enigme.dialogue.answerPlayer, "");


	for (int i = 0; i < NB_PNJ_ENIGME; i++)
	{
		_gd->pnjPos[i].x = i * 320 + 300;
		_gd->pnjPos[i].y = 200;
	}

	for (int i = NB_PNJ_ENIGME; i < NB_PNJ_ENIGME + NB_PNJ_HELP; i++)
	{
		_gd->pnjPos[i].x = 200;
		_gd->pnjPos[i].y = 700;
	}

	{
		//dialogue
		_gd->texts.dialogue.text = LoadText("../Ressources/Text/nasalization.ttf","", 1);
		sfText_setCharacterSize(_gd->texts.dialogue.text, 23);
		_gd->texts.dialogue.pos.x = 700;
		_gd->texts.dialogue.pos.y = 750;
		//door dialogue
		_gd->texts.doorEnigme.text = LoadText("../Ressources/Text/HoneyCute.otf","", 1);
		sfText_setCharacterSize(_gd->texts.doorEnigme.text, 150);
		_gd->texts.doorEnigme.pos.x = 780;
		_gd->texts.doorEnigme.pos.y = 715;
		
	}
}

void DeleteDialogueSprite(GameData* _gd)
{
	DeleteSprite(_gd->enigme.dialogue.backgroundDialogue);
	DeleteSprite(_gd->enigme.dialogue.backgroundTutoDialogue);

	for (int i = 0; i < 3; i++)
	{
		DeleteSprite(_gd->enigme.dialogue.helpDialogue.buttonSprite[i]);
		DeleteSprite(_gd->enigme.dialogue.quitDialogue.buttonSprite[i]);
		DeleteSprite(_gd->enigme.dialogue.retourDialogue.buttonSprite[i]);

	}
	for (int i = 0; i < 2; i++)
	{
		DeleteSprite(_gd->enigme.dialogue.validatePassword.buttonSprite[i]);

	}

	sfRectangleShape_destroy(_gd->enigme.dialogue.helpDialogue.forme);
	sfRectangleShape_destroy(_gd->enigme.dialogue.quitDialogue.forme);
	sfRectangleShape_destroy(_gd->enigme.dialogue.retourDialogue.forme);
	sfRectangleShape_destroy(_gd->enigme.dialogue.validatePassword.forme);

	sfFont_destroy(sfText_getFont(_gd->texts.doorEnigme.text));

}