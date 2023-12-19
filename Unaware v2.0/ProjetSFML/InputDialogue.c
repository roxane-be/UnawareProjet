#include "InputDialogue.h"

void InputButtonDialogue(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f tempPos = { 0, 0 };
	tempPos.x = (float)mousePos.x;
	tempPos.y = (float)mousePos.y;

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (isCollidingWithMouse(_gd->enigme.dialogue.helpDialogue.forme, tempPos, 0))
			{
				_gd->enigme.dialogue.clickHelpDialogue = sfTrue;
			}
			if (isCollidingWithMouse(_gd->enigme.dialogue.validatePassword.forme, tempPos, 0))
			{
				_gd->enigme.dialogue.clickValidateDialogue = sfTrue;
			}
			if (isCollidingWithMouse(_gd->enigme.dialogue.quitDialogue.forme, tempPos, 0))
			{
				_gd->enigme.dialogue.clickQuitDialogue = sfTrue;
				_gd->enigme.dialogue.letterSound.isPlaying = sfFalse;
			}
		}
	}

	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->enigme.dialogue.clickQuitDialogue = sfFalse;
			_gd->enigme.dialogue.clickValidateDialogue = sfFalse;
			_gd->enigme.dialogue.clickHelpDialogue = sfFalse;

			if (isCollidingWithMouse(_gd->enigme.dialogue.helpDialogue.forme, tempPos, 0))
			{
				sfSound_play(_gd->helpSound.sound);
				_gd->inGameState = tuto;
			}

			if (isCollidingWithMouse(_gd->enigme.dialogue.validatePassword.forme, tempPos, 0))
			{
				//Verification du mot de passe pour le bouton valider
				if (!strcmp(_gd->enigme.dialogue.answerPlayer, SOLUTION_ENIGME_DIALOGUE_0)
					|| !strcmp(_gd->enigme.dialogue.answerPlayer, SOLUTION_ENIGME_DIALOGUE_1))
				{
					sfSound_play(_gd->sucessSound.sound);
					_gd->enigme.dialogue.state = NONE;
					_gd->cutSceneState = islandDialogue;
					_gd->enigme.dialogue.resolvedDream_1 = sfTrue;
					_gd->inGameState = cutscene; //enigme
					_gd->enigmeState = none; //mastermindBox
					DeleteDialogueSprite(_gd);
					InitCutScene(_gd);
				}
				else
				{
					sfSound_play(_gd->errorSound.sound);
				}
			}

			if (isCollidingWithMouse(_gd->enigme.dialogue.quitDialogue.forme, tempPos, 0))
			{
				_gd->enigme.dialogue.state = NONE;
				_gd->enigmeState = none;
			}
		}
	}
}

void InputDialogue(GameData* _gd)
{
	if (_gd->enigme.dialogue.state == DOOR)
	{
		InputButtonDialogue(_gd);

		if (_gd->event.type == sfEvtKeyPressed)
		{
			int sizeChar = strlen(_gd->enigme.dialogue.answerPlayer);
			//only the alphabet in upper case
			if (_gd->event.key.code >= sfKeyA
				&& _gd->event.key.code <= sfKeyZ
				&& sizeChar < 6)
			{
				sfSound_play(_gd->enigme.dialogue.writeSound.sound);

				char temp[2] = { _gd->event.key.code + 65 };
				strcat(_gd->enigme.dialogue.answerPlayer, temp);
				//printf("%s\n", _gd->enigme.dialogue.answerPlayer);
			}
			//remove the last character
			if (_gd->event.key.code == sfKeyBackspace && sizeChar > 0)
			{
				sfSound_play(_gd->enigme.dialogue.writeSound.sound);
				sizeChar--;
				_gd->enigme.dialogue.answerPlayer[sizeChar] = '\0';
			}

			// verification de si le mot de passe est le bon 
			if (_gd->event.key.code == sfKeyEnter)
			{
				if (!strcmp(_gd->enigme.dialogue.answerPlayer, SOLUTION_ENIGME_DIALOGUE_0)
					|| !strcmp(_gd->enigme.dialogue.answerPlayer, SOLUTION_ENIGME_DIALOGUE_1))
				{
					sfSound_play(_gd->sucessSound.sound);
					_gd->enigme.dialogue.state = NONE;
					_gd->cutSceneState = islandDialogue;
					_gd->enigme.dialogue.resolvedDream_1 = sfTrue;
					_gd->inGameState = cutscene; //enigme
					_gd->enigmeState = none; //mastermindBox
					DeleteDialogueSprite(_gd);
					InitCutScene(_gd);
				}
				else
				{
					sfSound_play(_gd->errorSound.sound);
				}
			}

			if (_gd->event.key.code == sfKeyEscape)
			{
				_gd->enigme.dialogue.state = NONE;
			}
		}
	}

	else if (_gd->enigme.dialogue.state == INDIALOGUE)
	{
		if (_gd->event.type == sfEvtKeyPressed)
		{
			if (_gd->event.key.code == sfKeySpace)
			{
				//Dialogue du pnj d'aide
				//dialogue de base sans avoir parlé a aucun pnj
				if (_gd->enigme.dialogue.whoTalk == PNJ_HELP
					&& _gd->enigme.dialogue.sentence[PNJ_HELP] == SENTENCE_PNJ_HELP_0_1)
				{
					_gd->enigme.dialogue.sentence[PNJ_HELP] = SENTENCE_PNJ_HELP_0_2;
				}
				else if (_gd->enigme.dialogue.whoTalk == PNJ_HELP
					&& _gd->enigme.dialogue.sentence[PNJ_HELP] == SENTENCE_PNJ_HELP_0_2)
				{
					_gd->enigme.dialogue.state = NONE;
					_gd->enigmeState = none;
					_gd->enigme.dialogue.sentence[PNJ_HELP] = SENTENCE_PNJ_HELP_0_1;
					_gd->npc[0].voice.isPlaying = sfFalse;
				}

				//dilaogue après avoir parlé a au moins 1 des pnj
				if (_gd->enigme.dialogue.whoTalk == PNJ_HELP
					&& _gd->enigme.dialogue.sentence[PNJ_HELP] == SENTENCE_PNJ_HELP_1)
				{
					_gd->enigme.dialogue.state = NONE;
					_gd->enigmeState = none;
					_gd->enigme.dialogue.sentence[PNJ_HELP] = SENTENCE_PNJ_HELP_1;
					_gd->npc[0].voice.isPlaying = sfFalse;
				}

				//diloague quand on a parlé au 4 pnj
				if (_gd->enigme.dialogue.whoTalk == PNJ_HELP
					&& _gd->enigme.dialogue.sentence[PNJ_HELP] == SENTENCE_PNJ_HELP_2)
				{
					_gd->enigme.dialogue.state = NONE;
					_gd->enigmeState = none;
					_gd->enigme.dialogue.sentence[PNJ_HELP] = SENTENCE_PNJ_HELP_2;
					_gd->npc[0].voice.isPlaying = sfFalse;
				}

				//Dialogue du pnj 0
				if (_gd->enigme.dialogue.whoTalk == PNJ_0
					&& _gd->enigme.dialogue.sentence[PNJ_0] == SENTENCE_PNJ_0_1)
				{
					_gd->enigme.dialogue.state = NONE;
					_gd->enigmeState = none;
					_gd->enigme.dialogue.sentence[PNJ_0] = SENTENCE_PNJ_0_1;
					_gd->npc[1].voice.isPlaying = sfFalse;
				}

				//Dialogue du pnj 1
				if (_gd->enigme.dialogue.whoTalk == PNJ_1
					&& _gd->enigme.dialogue.sentence[PNJ_1] == SENTENCE_PNJ_1_1)
				{
					_gd->enigme.dialogue.state = NONE;
					_gd->enigmeState = none;
					_gd->enigme.dialogue.sentence[PNJ_1] = SENTENCE_PNJ_1_1;
					_gd->npc[2].voice.isPlaying = sfFalse;
				}

				//Dialogue du pnj 2
				if (_gd->enigme.dialogue.whoTalk == PNJ_2
					&& _gd->enigme.dialogue.sentence[PNJ_2] == SENTENCE_PNJ_2_1)
				{
					_gd->enigme.dialogue.state = NONE;
					_gd->enigmeState = none;
					_gd->enigme.dialogue.sentence[PNJ_2] == SENTENCE_PNJ_2_1;
					_gd->npc[3].voice.isPlaying = sfFalse;
				}

				//Dialogue du pnj 3
				if (_gd->enigme.dialogue.whoTalk == PNJ_3
					&& _gd->enigme.dialogue.sentence[PNJ_3] == SENTENCE_PNJ_3_1)
				{
					_gd->enigme.dialogue.sentence[PNJ_3] = SENTENCE_PNJ_3_2;
				}
				else if (_gd->enigme.dialogue.whoTalk == PNJ_3
					&& _gd->enigme.dialogue.sentence[PNJ_3] == SENTENCE_PNJ_3_2)
				{
					_gd->enigme.dialogue.state = NONE;
					_gd->enigmeState = none;
					_gd->enigme.dialogue.sentence[PNJ_3] = SENTENCE_PNJ_3_1;
					_gd->npc[4].voice.isPlaying = sfFalse;
				}
			}
		}
	}
}