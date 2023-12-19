#include "Input.h"

void InputInterractionIntro(GameData* _gd)
{
	int indiceInteraction = 0;
	//gestion de l'interaction avec E
	switch (_gd->inGameState)
	{
	case exploration:
		if (TriggerPlayerInteractionIntro(_gd, &indiceInteraction))
		{
			if (_gd->event.type == sfEvtKeyPressed)
			{
				if (_gd->event.key.code == sfKeyE)
				{
					InteractionPlayerIntro(_gd, indiceInteraction);
				}
			}
		}
	default:
		break;
	}
}

void InputInterractionIsland(GameData* _gd)
{
	int indiceInteraction = 0;
	int indiceDestructible = 0;
	//gestion de l'interaction avec E
	switch (_gd->inGameState)
	{
	case exploration:
		if (TriggerPlayerInteractionIsland(_gd, &indiceInteraction, &indiceDestructible))
		{
			if (_gd->event.type == sfEvtKeyPressed)
			{
				if (_gd->event.key.code == sfKeyE)
				{
					InteractionPlayerIsland(_gd, indiceInteraction, indiceDestructible);
				}
			}
		}
	default:
		break;
	}
}

void InputInterractionBedRoom(GameData* _gd)
{
	int indiceInteraction = 0;
	//gestion de l'interaction avec E
	switch (_gd->inGameState)
	{
	case exploration:
		if (TriggerPlayerInteractionBedRoom(_gd, &indiceInteraction))
		{
			if (_gd->event.type == sfEvtKeyPressed)
			{
				if (_gd->event.key.code == sfKeyE)
				{
					InteractionPlayerBedRoom(_gd, indiceInteraction);
				}
			}
		}
	default:
		break;
	}
}

void InputInterractionJungle(GameData* _gd)
{
	int indiceInteraction = 0;
	int indiceDestructible = 0;

	//gestion de l'interaction avec E
	switch (_gd->inGameState)
	{
	case exploration:
		if (TriggerPlayerInteractionJungle(_gd, &indiceInteraction, &indiceDestructible))
		{
			if (_gd->event.type == sfEvtKeyPressed)
			{
				if (_gd->event.key.code == sfKeyE)
				{
					InteractionPlayerJungle(_gd, indiceInteraction, indiceDestructible);
				}
			}
		}
	default:
		break;
	}
}

void InputInterractionShipEnd(GameData* _gd)
{
	int indiceInteraction = 0;
	//gestion de l'interaction avec E
	switch (_gd->inGameState)
	{
	case exploration:
		if (TriggerPlayerInteractionShipEnd(_gd, &indiceInteraction))
		{
			if (_gd->event.type == sfEvtKeyPressed)
			{
				if (_gd->event.key.code == sfKeyE)
				{
					InteractionPlayerShipEnd(_gd, indiceInteraction);
				}
			}
		}
	default:
		break;
	}
}


void InputIntro(GameData* _gd)
{
	switch (_gd->inGameState)
	{
	case enigme:
		switch (_gd->enigmeState)
		{
		case mastermindIntro:
			//input pour le mastermind
			InputMastermindIntro(_gd);
			break;
		default:
			break;
		}
	case tuto:
		switch (_gd->enigmeState)
		{
		case mastermindIntro:
			InputTutoMastermindIntro(_gd);
			break;

		default:
			break;
		}
		break;
	default:
		break;

	}
}

void InputButtonQuitBox(GameData* _gd, sfVector2f _mousePos)
{
	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (isCollidingWithMouse(_gd->enigme.houseBox.buttonQuitBox.forme, _mousePos, 0))
			{
				_gd->enigme.houseBox.clickQuitButtonBox = sfTrue;
			}
		}
	}

	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->enigme.houseBox.clickQuitButtonBox = sfFalse;

			if (isCollidingWithMouse(_gd->enigme.houseBox.buttonQuitBox.forme, _mousePos, 0))
			{
					_gd->inGameState = exploration;
					_gd->enigmeState = none;
					_gd->enigmeBox = none;
			}
		}
	}

}

void InputBoxBox(GameData* _gd)
{
	sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouse2f = { posMouse.x,posMouse.y };

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft) //Clic gauche
		{
			//fleche à gauche, pour aller a gauche
			if (CollisionTriangleMouse(posMouse2f, &_gd->arrowTriBox[0]))
			{
				_gd->clickSpriteArrowLeft = sfTrue;
			}
			//fleche à droite, pour aller a droite
			if (CollisionTriangleMouse(posMouse2f, &_gd->arrowTriBox[1]))
			{
				_gd->clickSpriteArrowRight = sfTrue;
			}
		}
	}

	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		_gd->clickSpriteArrowLeft = sfFalse;
		_gd->clickSpriteArrowRight = sfFalse;

		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (CollisionTriangleMouse(posMouse2f, &_gd->arrowTriBox[0]))
			{
				sfSound_play(_gd->boxSwishSound.sound);
				switch (_gd->enigmeState)
				{
				case mastermindBox:
					_gd->enigmeState = voltageBox;
					break;
				case plaqueBox:
					_gd->enigmeState = mastermindBox;
					break;
				case cableBox:
					_gd->enigmeState = plaqueBox;
					break;
				case voltageBox:
					_gd->enigmeState = cableBox;
					break;
				}
			}
			//fleche à droite, pour aller a droite
			if (CollisionTriangleMouse(posMouse2f, &_gd->arrowTriBox[1]))
			{
				sfSound_play(_gd->boxSwishSound.sound);
				switch (_gd->enigmeState)
				{
				case mastermindBox:
					_gd->enigmeState = plaqueBox;
					break;
				case plaqueBox:
					_gd->enigmeState = cableBox;
					break;
				case cableBox:
					_gd->enigmeState = voltageBox;
					break;
				case voltageBox:
					_gd->enigmeState = mastermindBox;
					break;
				}
			}
		}
	}

	//input pour la gestion totale de la boite en fonction de l'enigme en cours
	switch (_gd->enigmeState)
	{
	case mastermindBox:
		//input pour le mastermind
		if (_gd->enigme.houseBox.resolvedDream_1Box == sfFalse)
		{
			InputMastermindBox(_gd);
		}
		break;
	case plaqueBox:
		//Input enigme plaque avec vis
		if (_gd->utilityPieceBoite.resolvedDream_1 == sfFalse
			&& _gd->enigme.houseBox.resolvedDream_1Box == sfTrue)
		{
			InputPlaqueVisBox(_gd);
		}
		break;
	case cableBox:
		if (_gd->utilityCable.resolvedDream_1 == sfFalse
			&& _gd->utilityPieceBoite.resolvedDream_1 == sfTrue)
		{
			InputCableBox(_gd);
		}
		break;
	case voltageBox:
		if (_gd->enigme.voltage.resolvedDream_1 == sfFalse
			&& _gd->utilityCable.resolvedDream_1 == sfTrue)
		{
			InputVoltageBox(_gd);
		}
		break;
	default:
		break;
	}
	InputButtonQuitBox(_gd, posMouse2f);

}

void InputTutoIsland(GameData* _gd)
{
	//permet de gerer tout les tuto des enigmes de l'ile
	switch (_gd->enigmeState)
	{
	case puzzleIsland:
		InputTutoPuzzle(_gd);
		break;
	case dialogueIsland:
		InputTutoDialogue(_gd);
		break;
	case mastermindBox:
		InputTutoBox(_gd);
		break;
	case plaqueBox:
		InputTutoBox(_gd);
		break;
	case cableBox:
		InputTutoBox(_gd);
		break;
	case voltageBox:
		InputTutoBox(_gd);
		break;
	default:
		break;
	}
}

void InputIsland(GameData* _gd)
{
	switch (_gd->inGameState)
	{
	case enigme:

		if (_gd->enigmeBox == box)
		{
			InputBoxBox(_gd);
		}

		switch (_gd->enigmeState)
		{
		case puzzleIsland:
			//input puzzle pont
			InputPuzzle(_gd);
			break;

		default:
			break;
		}

	case tuto:
		InputTutoIsland(_gd);
		break;

	case exploration:

		switch (_gd->enigmeState)
		{
		case dialogueIsland:
			InputDialogue(_gd);
			break;
		default:
			break;
		}

	default:
		break;

	}
}

void InputSymboleDiodeJungle(GameData* _gd)
{
	sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouse2f = { posMouse.x,posMouse.y };

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (isCollidingWithMouse(_gd->enigme.interupteur.retourButtonDiode.forme, posMouse2f, 0))
			{
				_gd->enigme.interupteur.clickRetourButtonDiode = sfTrue;
			}
		}
	}

	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->enigme.interupteur.clickRetourButtonDiode = sfFalse;

			if (isCollidingWithMouse(_gd->enigme.interupteur.retourButtonDiode.forme, posMouse2f, 0))
			{
				sfSound_play(_gd->enigme.interupteur.fireflyInstruction.sound);
				_gd->inGameState = enigme;
			}
		}
	}
}

void InputLabyrintheTuto(GameData* _gd)
{
	sfVector2i posMouse = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouse2f = { posMouse.x,posMouse.y };

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			if (isCollidingWithMouse(_gd->retourTutoLaby.forme, posMouse2f, 0))
			{
				_gd->clickRetourTutoLaby = sfTrue;
			}
		}
	}
	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->clickRetourTutoLaby = sfFalse;

			if (isCollidingWithMouse(_gd->retourTutoLaby.forme, posMouse2f, 0))
			{
				_gd->inGameState = exploration;
				_gd->enigmeState = none;
			}
		}
	}
}

void InputTutoJungle(GameData* _gd)
{
	//permet de gerer tout les tuto des enigmes de l'ile
	switch (_gd->enigmeState)
	{
	case diodeJungle:
		InputTutoDiode(_gd);
		break;
	case puzzleJungle:
		InputTutoPuzzleJungle(_gd);
		break;
	case decryptageJungle:
		InputTutoDecryptage(_gd);
		break;
	case labyrinthe:
		InputLabyrintheTuto(_gd);
		break;
	default:
		break;
	}
}

void InputJungle(GameData* _gd)
{
	switch (_gd->inGameState)
	{
	case enigme:
		switch (_gd->enigmeState)
		{
		case diodeJungle:
			//input pour le mastermind
			InputDiode(_gd);
			break;
		case puzzleJungle:
			//input du puzzle jungle
			InputPuzzleJungle(_gd);
			break;
		case decryptageJungle:
			//input du decryptage
			InputDecryptage(_gd);
			break;
		default:
			break;
		}
	case tuto:
		InputTutoJungle(_gd);
		break;
	case symbole:
		//pour les symboles des diodes
		InputSymboleDiodeJungle(_gd);
		break;
	default:
		break;
	}
}


void InputInGame(GameData* _gd)
{
	switch (_gd->world)
	{
	case intro:
		InputIntro(_gd);
		InputInterractionIntro(_gd);
		break;
	case island:
		InputIsland(_gd);
		InputInterractionIsland(_gd);
		break;
	case bedroom:
		InputInterractionBedRoom(_gd);
		break;
	case jungle:
		InputJungle(_gd);
		InputInterractionJungle(_gd);
		break;
	case shipEnd:
		InputInterractionShipEnd(_gd);
		break;
	default:
		break;
	}

	if (_gd->event.type == sfEvtKeyPressed
		&& _gd->inGameState != cutscene)
	{
		if (_gd->event.key.code == sfKeyEscape)
		{
			sfSound_stop(_gd->player.stepSound.sound);
			_gd->gameState = pause;
			MuteSound(_gd);

		}
	}
}

void InputAllGame(GameData* _gd)
{
	while (sfRenderWindow_pollEvent(_gd->window, &_gd->event))
	{
		if (_gd->event.type == sfEvtClosed) exit(0);

		switch (_gd->gameState)
		{
		case menu:
			InputMenu(_gd);
			break;
		case selecteurPerso:
			InputSelecteurPerso(_gd);
			break;
		case play:
			InputInGame(_gd);
			break;
		case pause:
			InputPause(_gd);
			break;
		case controle:
			InputControle(_gd);
			break;
		case credit:
			InputCredit(_gd);
			break;
		case option:
			InputOptions(_gd);
			break;
		case volume:
			InputVolume(_gd);
			break;
		default:
			break;
		}
	}
}