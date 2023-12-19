#include "UpdatePlayer.h"

int CollisionPlayer(GameData* _gd)
{
	switch (_gd->world)
	{
	case intro:
		for (int i = 0; i < _gd->mapIntro->nbCollision; i++)
		{
			if (_gd->player.pos.x + 16 >= _gd->mapIntro->mapCollision[i].pos.x
				&& _gd->player.pos.x - 16 <= _gd->mapIntro->mapCollision[i].pos.x + _gd->mapIntro->mapCollision[i].size.x
				&& _gd->player.pos.y + 59 >= _gd->mapIntro->mapCollision[i].pos.y
				&& _gd->player.pos.y + 28 <= _gd->mapIntro->mapCollision[i].pos.y + _gd->mapIntro->mapCollision[i].size.y)
			{
				return 1;
			}
		}
		return 0;
		break;

	case island:
		for (int i = 0; i < _gd->mapIsland->nbCollision; i++)
		{
			if (_gd->player.pos.x + 16 >= _gd->mapIsland->mapCollision[i].pos.x
				&& _gd->player.pos.x - 16 <= _gd->mapIsland->mapCollision[i].pos.x + _gd->mapIsland->mapCollision[i].size.x
				&& _gd->player.pos.y + 59 >= _gd->mapIsland->mapCollision[i].pos.y
				&& _gd->player.pos.y + 28 <= _gd->mapIsland->mapCollision[i].pos.y + _gd->mapIsland->mapCollision[i].size.y)
			{
				return 1;
			}
		}
		return 0;
		break;
	case bedroom:
		for (int i = 0; i < _gd->mapBedRoom->nbCollision; i++)
		{
			if (_gd->player.pos.x + 16 >= _gd->mapBedRoom->mapCollision[i].pos.x
				&& _gd->player.pos.x - 16 <= _gd->mapBedRoom->mapCollision[i].pos.x + _gd->mapBedRoom->mapCollision[i].size.x
				&& _gd->player.pos.y + 59 >= _gd->mapBedRoom->mapCollision[i].pos.y
				&& _gd->player.pos.y + 28 <= _gd->mapBedRoom->mapCollision[i].pos.y + _gd->mapBedRoom->mapCollision[i].size.y)
			{
				return 1;
			}
		}
		return 0;
		break;
	case jungle:
		for (int i = 0; i < _gd->mapJungle->nbCollision; i++)
		{
			if (_gd->player.pos.x + 16 >= _gd->mapJungle->mapCollision[i].pos.x
				&& _gd->player.pos.x - 16 <= _gd->mapJungle->mapCollision[i].pos.x + _gd->mapJungle->mapCollision[i].size.x
				&& _gd->player.pos.y + 59 >= _gd->mapJungle->mapCollision[i].pos.y
				&& _gd->player.pos.y + 28 <= _gd->mapJungle->mapCollision[i].pos.y + _gd->mapJungle->mapCollision[i].size.y)
			{
				return 1;
			}
		}
		return 0;
		break;
	case shipEnd:
		for (int i = 0; i < _gd->mapShipEnd->nbCollision; i++)
		{
			if (_gd->player.pos.x + 16 >= _gd->mapShipEnd->mapCollision[i].pos.x
				&& _gd->player.pos.x - 16 <= _gd->mapShipEnd->mapCollision[i].pos.x + _gd->mapShipEnd->mapCollision[i].size.x
				&& _gd->player.pos.y + 59 >= _gd->mapShipEnd->mapCollision[i].pos.y
				&& _gd->player.pos.y + 28 <= _gd->mapShipEnd->mapCollision[i].pos.y + _gd->mapShipEnd->mapCollision[i].size.y)
			{
				return 1;
			}
		}
		return 0;
		break;
	default:
		return 0;
		break;
	}

}

void TriggerIA(GameData* _gd)
{
	switch (_gd->world)
	{
	case intro:
		for (int i = 0; i < _gd->mapIntro->nbMapTriggerIA; i++)
		{
			if (_gd->player.pos.x + 16 >= _gd->mapIntro->mapTriggerIA[i].pos.x
				&& _gd->player.pos.x - 16 <= _gd->mapIntro->mapTriggerIA[i].pos.x + _gd->mapIntro->mapTriggerIA[i].size.x
				&& _gd->player.pos.y + 59 >= _gd->mapIntro->mapTriggerIA[i].pos.y
				&& _gd->player.pos.y + 28 <= _gd->mapIntro->mapTriggerIA[i].pos.y + _gd->mapIntro->mapTriggerIA[i].size.y)
			{
				if (_gd->failDream == sfFalse)
				{
					if (!strcmp(_gd->mapIntro->mapTriggerIA[i].name, "intro_1")
						&& _gd->mapIntro->mapTriggerIA[i].done == sfFalse)
					{
						_gd->ia_ship.actif = sfTrue;
						UpdateTextIA(_gd, intro_1);
						_gd->mapIntro->mapTriggerIA[i].done = sfTrue;
						sfSound_play(_gd->aiSound.sound);
					}

					else if (!strcmp(_gd->mapIntro->mapTriggerIA[i].name, "intro_2")
						&& _gd->mapIntro->mapTriggerIA[i].done == sfFalse)
					{
						_gd->ia_ship.actif = sfTrue;
						UpdateTextIA(_gd, intro_2);
						_gd->mapIntro->mapTriggerIA[i].done = sfTrue;
						sfSound_play(_gd->aiSound.sound);
					}

					else if (!strcmp(_gd->mapIntro->mapTriggerIA[i].name, "intro_3")
						&& _gd->mapIntro->mapTriggerIA[i].done == sfFalse)
					{
						_gd->ia_ship.actif = sfTrue;
						UpdateTextIA(_gd, intro_3);
						_gd->mapIntro->mapTriggerIA[i].done = sfTrue;
						sfSound_play(_gd->aiSound.sound);
					}
				}
				else
				{
					if (!strcmp(_gd->mapIntro->mapTriggerIA[i].name, "fail_1")
						&& _gd->mapIntro->mapTriggerIA[i].done == sfFalse)
					{
						_gd->ia_ship.actif = sfTrue;
						UpdateTextIA(_gd, fail_1);
						_gd->mapIntro->mapTriggerIA[i].done = sfTrue;
						sfSound_play(_gd->aiSound.sound);
					}

				}
			}
		}
		break;
	case bedroom:
		for (int i = 0; i < _gd->mapBedRoom->nbMapTriggerIA; i++)
		{
			if (_gd->player.pos.x + 16 >= _gd->mapBedRoom->mapTriggerIA[i].pos.x
				&& _gd->player.pos.x - 16 <= _gd->mapBedRoom->mapTriggerIA[i].pos.x + _gd->mapBedRoom->mapTriggerIA[i].size.x
				&& _gd->player.pos.y + 59 >= _gd->mapBedRoom->mapTriggerIA[i].pos.y
				&& _gd->player.pos.y + 28 <= _gd->mapBedRoom->mapTriggerIA[i].pos.y + _gd->mapBedRoom->mapTriggerIA[i].size.y)
			{
				if (_gd->failDream == sfFalse)
				{
					if (!strcmp(_gd->mapBedRoom->mapTriggerIA[i].name, "hub_1")
						&& _gd->mapBedRoom->mapTriggerIA[i].done == sfFalse)
					{
						_gd->ia_ship.actif = sfTrue;
						UpdateTextIA(_gd, hub_1);
						_gd->mapBedRoom->mapTriggerIA[i].done = sfTrue;
						sfSound_play(_gd->aiSound.sound);
					}

					if (!strcmp(_gd->mapBedRoom->mapTriggerIA[i].name, "hub_2")
						&& _gd->mapBedRoom->mapTriggerIA[i].done == sfFalse)
					{
						_gd->ia_ship.actif = sfTrue;
						UpdateTextIA(_gd, hub_2);
						_gd->mapBedRoom->mapTriggerIA[i].done = sfTrue;
						sfSound_play(_gd->aiSound.sound);
					}
					if (!strcmp(_gd->mapBedRoom->mapTriggerIA[i].name, "hub_3")
						&& _gd->mapBedRoom->mapTriggerIA[i].done == sfFalse)
					{
						_gd->ia_ship.actif = sfTrue;
						UpdateTextIA(_gd, hub_3);
						_gd->mapBedRoom->mapTriggerIA[i].done = sfTrue;
						sfSound_play(_gd->aiSound.sound);
					}
				}
				else
				{
					if (!strcmp(_gd->mapBedRoom->mapTriggerIA[i].name, "fail_2")
						&& _gd->mapBedRoom->mapTriggerIA[i].done == sfFalse)
					{
						_gd->ia_ship.actif = sfTrue;
						UpdateTextIA(_gd, fail_2);
						_gd->mapBedRoom->mapTriggerIA[i].done = sfTrue;
						sfSound_play(_gd->aiSound.sound);
					}

				}
			}
		}
		break;
	case shipEnd:
		for (int i = 0; i < _gd->mapShipEnd->nbMapTriggerIA; i++)
		{
			if (_gd->player.pos.x + 16 >= _gd->mapShipEnd->mapTriggerIA[i].pos.x
				&& _gd->player.pos.x - 16 <= _gd->mapShipEnd->mapTriggerIA[i].pos.x + _gd->mapShipEnd->mapTriggerIA[i].size.x
				&& _gd->player.pos.y + 59 >= _gd->mapShipEnd->mapTriggerIA[i].pos.y
				&& _gd->player.pos.y + 28 <= _gd->mapShipEnd->mapTriggerIA[i].pos.y + _gd->mapShipEnd->mapTriggerIA[i].size.y)
			{
				if (!strcmp(_gd->mapShipEnd->mapTriggerIA[i].name, "end_1")
					&& _gd->mapShipEnd->mapTriggerIA[i].done == sfFalse)
				{
					_gd->ia_ship.actif = sfTrue;
					UpdateTextIA(_gd, end_1);
					_gd->mapShipEnd->mapTriggerIA[i].done = sfTrue;
					sfSound_play(_gd->aiSound.sound);
				}

				if (!strcmp(_gd->mapShipEnd->mapTriggerIA[i].name, "end_2")
					&& _gd->mapShipEnd->mapTriggerIA[i].done == sfFalse)
				{
					_gd->ia_ship.actif = sfTrue;
					UpdateTextIA(_gd, end_2);
					_gd->mapShipEnd->mapTriggerIA[i].done = sfTrue;
					sfSound_play(_gd->aiSound.sound);
				}
				if (!strcmp(_gd->mapShipEnd->mapTriggerIA[i].name, "end_3")
					&& _gd->mapShipEnd->mapTriggerIA[i].done == sfFalse)
				{
					_gd->ia_ship.actif = sfTrue;
					UpdateTextIA(_gd, end_3);
					_gd->mapShipEnd->mapTriggerIA[i].done = sfTrue;
					sfSound_play(_gd->aiSound.sound);
				}
			}
		}

		break;
	default:
		break;
	}
}


void TriggerPlayerSound(GameData* _gd)
{
	sfTime currentSongTimer;
	char triggerZone[100];
	switch (_gd->world)
	{
	case intro:
		strcpy(triggerZone, "Metal");
		for (int i = 0; i < _gd->mapIntro->nbTriggerSound; i++)
		{
			if (_gd->player.pos.x + 16 >= _gd->mapIntro->mapTriggerSound[i].pos.x
				&& _gd->player.pos.x - 16 <= _gd->mapIntro->mapTriggerSound[i].pos.x + _gd->mapIntro->mapTriggerSound[i].size.x
				&& _gd->player.pos.y + 59 >= _gd->mapIntro->mapTriggerSound[i].pos.y
				&& _gd->player.pos.y + 28 <= _gd->mapIntro->mapTriggerSound[i].pos.y + _gd->mapIntro->mapTriggerSound[i].size.y)
			{
				strcpy(triggerZone, _gd->mapIntro->mapTriggerSound[i].name);
			}
		}

		if (!strcmp(triggerZone, "Glass"))
		{
			if (strcmp(_gd->player.stepName, "Glass"))
			{
				_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Pas/GlassSteps.wav");
				_gd->player.stepSound.isPlaying = sfFalse;
				sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
				strcpy(_gd->player.stepName, "Glass");
			}
		}
		else if (!strcmp(triggerZone, "Carpet"))
		{
			if (strcmp(_gd->player.stepName, "Carpet"))
			{
				_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Pas/CarpetSteps.wav");
				_gd->player.stepSound.isPlaying = sfFalse;
				sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
				strcpy(_gd->player.stepName, "Carpet");
			}
		}
		else if (!strcmp(triggerZone, "Metal"))
		{
			if (strcmp(_gd->player.stepName, "Metal"))
			{
				_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Pas/MetalSteps.wav");
				_gd->player.stepSound.isPlaying = sfFalse;
				sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
				strcpy(_gd->player.stepName, "Metal");
			}
		}
		break;

	case island:
		strcpy(triggerZone, "Grass");
		for (int i = 0; i < _gd->mapIsland->nbTriggerSound; i++)
		{
			if (_gd->player.pos.x + 16 >= _gd->mapIsland->mapTriggerSound[i].pos.x
				&& _gd->player.pos.x - 16 <= _gd->mapIsland->mapTriggerSound[i].pos.x + _gd->mapIsland->mapTriggerSound[i].size.x
				&& _gd->player.pos.y + 59 >= _gd->mapIsland->mapTriggerSound[i].pos.y
				&& _gd->player.pos.y + 28 <= _gd->mapIsland->mapTriggerSound[i].pos.y + _gd->mapIsland->mapTriggerSound[i].size.y)
			{
				strcpy(triggerZone, _gd->mapIsland->mapTriggerSound[i].name);
			}
		}
	/*	if (!strcmp(triggerZone, "Outside"))
		{
			if (_gd->worldAmbience.isPlaying == sfTrue)
			{
				currentSongTimer = sfSound_getPlayingOffset(_gd->worldAmbience.sound);
				sfSound_pause(_gd->worldAmbience.sound);
				_gd->worldAmbience.isPlaying = sfFalse;
				sfSound_play(_gd->worldAmbienceOutside.sound);
				sfSound_setPlayingOffset(_gd->worldAmbienceOutside.sound, currentSongTimer);

			}
		}
		else if (!strcmp(triggerZone, "Inside"))
		{
			if (_gd->worldAmbience.isPlaying == sfFalse)
			{
				currentSongTimer = sfSound_getPlayingOffset(_gd->worldAmbienceOutside.sound);
				sfSound_pause(_gd->worldAmbienceOutside.sound);
				_gd->worldAmbience.isPlaying = sfTrue;
				sfSound_play(_gd->worldAmbience.sound);
				sfSound_setPlayingOffset(_gd->worldAmbience.sound, currentSongTimer);
			}
		}*/

		if (!strcmp(triggerZone, "Wood"))
		{
			if (strcmp(_gd->player.stepName, "Wood"))
			{
				_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Pas/WoodSteps.wav");
				_gd->player.stepSound.isPlaying = sfFalse;
				sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
				strcpy(_gd->player.stepName, "Wood");
			}
		}
		else if (!strcmp(triggerZone, "Dirt"))
		{
			if (strcmp(_gd->player.stepName, "Dirt"))
			{
				_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Pas/DirtSteps.wav");
				_gd->player.stepSound.isPlaying = sfFalse;
				sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
				strcpy(_gd->player.stepName, "Dirt");
			}
		}
		else if (!strcmp(triggerZone, "Carpet"))
		{
			if (strcmp(_gd->player.stepName, "Carpet"))
			{
				_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Pas/CarpetSteps.wav");
				_gd->player.stepSound.isPlaying = sfFalse;
				sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
				strcpy(_gd->player.stepName, "Carpet");
			}
		}
		else if (!strcmp(triggerZone, "Bush"))
		{
			if (_gd->bushSound.isPlaying == sfFalse)
			{
				_gd->bushSound.isPlaying = sfTrue;
				sfSound_play(_gd->bushSound.sound);
			}
		}
		else if (!strcmp(triggerZone, "Grass"))
		{
			if (strcmp(_gd->player.stepName, "Grass"))
			{
				_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Pas/GrassSteps.wav");
				_gd->player.stepSound.isPlaying = sfFalse;
				sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
				strcpy(_gd->player.stepName, "Grass");
			}
		}

		if (strcmp(triggerZone, "Bush"))
		{
			if (_gd->bushSound.isPlaying == sfTrue)
			{
				_gd->bushSound.isPlaying = sfFalse;
			}
		}
		break;

	case bedroom:
		strcpy(triggerZone, "Metal");
		for (int i = 0; i < _gd->mapBedRoom->nbTriggerSound; i++)
		{
			if (_gd->player.pos.x + 16 >= _gd->mapBedRoom->mapTriggerSound[i].pos.x
				&& _gd->player.pos.x - 16 <= _gd->mapBedRoom->mapTriggerSound[i].pos.x + _gd->mapBedRoom->mapTriggerSound[i].size.x
				&& _gd->player.pos.y + 59 >= _gd->mapBedRoom->mapTriggerSound[i].pos.y
				&& _gd->player.pos.y + 28 <= _gd->mapBedRoom->mapTriggerSound[i].pos.y + _gd->mapBedRoom->mapTriggerSound[i].size.y)
			{
				strcpy(triggerZone, _gd->mapBedRoom->mapTriggerSound[i].name);
			}

		}
		if (!strcmp(triggerZone, "Carpet"))
		{
			if (strcmp(_gd->player.stepName, "Carpet"))
			{
				_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Pas/CarpetSteps.wav");
				_gd->player.stepSound.isPlaying = sfFalse;
				sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
				strcpy(_gd->player.stepName, "Carpet");
			}
		}
		else if (!strcmp(triggerZone, "Metal"))
		{
			if (strcmp(_gd->player.stepName, "Metal"))
			{
				_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Pas/MetalSteps.wav");
				_gd->player.stepSound.isPlaying = sfFalse;
				sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
				strcpy(_gd->player.stepName, "Metal");
			}
		}
		break;

	case jungle:
		strcpy(triggerZone, "Grass");
		for (int i = 0; i < _gd->mapJungle->nbTriggerSound; i++)
		{
			if (_gd->player.pos.x + 16 >= _gd->mapJungle->mapTriggerSound[i].pos.x
				&& _gd->player.pos.x - 16 <= _gd->mapJungle->mapTriggerSound[i].pos.x + _gd->mapJungle->mapTriggerSound[i].size.x
				&& _gd->player.pos.y + 59 >= _gd->mapJungle->mapTriggerSound[i].pos.y
				&& _gd->player.pos.y + 28 <= _gd->mapJungle->mapTriggerSound[i].pos.y + _gd->mapJungle->mapTriggerSound[i].size.y)
			{
				strcpy(triggerZone, _gd->mapJungle->mapTriggerSound[i].name);
			}
		}
		if (!strcmp(triggerZone, "Grass"))
		{
			if (strcmp(_gd->player.stepName, "Grass"))
			{
				//printf("Step Grass\n");
				_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Pas/GrassSteps.wav");
				_gd->player.stepSound.isPlaying = sfFalse;
				sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
				strcpy(_gd->player.stepName, "Grass");
			}
		}
		else if (!strcmp(triggerZone, "Dirt"))
		{
			//printf("Dirt\n");
			if (strcmp(_gd->player.stepName, "Dirt"))
			{
				//printf("Step Dirt\n");
				_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Pas/DirtSteps.wav");
				_gd->player.stepSound.isPlaying = sfFalse;
				sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
				strcpy(_gd->player.stepName, "Dirt");
			}
		}
		else if (!strcmp(triggerZone, "Stone"))
		{
			//printf("Stone\n");
			if (strcmp(_gd->player.stepName, "Stone"))
			{
				//printf("Step Stone\n");
				_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde2/Pas/StoneSteps.wav");
				_gd->player.stepSound.isPlaying = sfFalse;
				sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
				strcpy(_gd->player.stepName, "Stone");
			}
		}
		else if (!strcmp(triggerZone, "Metal"))
		{
			if (strcmp(_gd->player.stepName, "Metal"))
			{
				_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Pas/MetalSteps.wav");
				_gd->player.stepSound.isPlaying = sfFalse;
				sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
				strcpy(_gd->player.stepName, "Metal");
			}
		}
		if (strcmp(triggerZone, "Bush"))
		{
			if (_gd->bushSound.isPlaying == sfTrue)
			{
				_gd->bushSound.isPlaying = sfFalse;
			}
		}
		if (!strcmp(triggerZone, "rouge"))
		{
			if (_gd->worldAmbience.isPlaying == sfTrue)
			{
				sfSound_stop(_gd->worldAmbience.sound);
				_gd->worldAmbience.isPlaying = sfFalse;
				sfSound_play(_gd->musicLaby[red].sound);
			}
			if (_gd->currentColor != red)
			{
				if (_gd->currentColor == blue)
				{
					currentSongTimer = sfSound_getPlayingOffset(_gd->musicLaby[blue].sound);
					_gd->lastColor = blue;
				}
				if (_gd->currentColor == green)
				{
					currentSongTimer = sfSound_getPlayingOffset(_gd->musicLaby[green].sound);
					_gd->lastColor = green;
				}
				if (_gd->currentColor == yellow)
				{
					currentSongTimer = sfSound_getPlayingOffset(_gd->musicLaby[yellow].sound);
					_gd->lastColor = yellow;
				}
				_gd->currentColor = red;
				sfSound_play(_gd->musicLaby[red].sound);
				sfSound_setPlayingOffset(_gd->musicLaby[red].sound, currentSongTimer);
			}
		}
		else if (!strcmp(triggerZone, "bleu"))
		{
			if (_gd->currentColor != blue)
			{
				if (_gd->currentColor == red)
				{
					currentSongTimer = sfSound_getPlayingOffset(_gd->musicLaby[red].sound);
					_gd->lastColor = red;
				}
				if (_gd->currentColor == green)
				{
					currentSongTimer = sfSound_getPlayingOffset(_gd->musicLaby[green].sound);
					_gd->lastColor = green;
				}
				if (_gd->currentColor == yellow)
				{
					currentSongTimer = sfSound_getPlayingOffset(_gd->musicLaby[yellow].sound);
					_gd->lastColor = yellow;
				}
				_gd->currentColor = blue;
				sfSound_play(_gd->musicLaby[blue].sound);
				sfSound_setPlayingOffset(_gd->musicLaby[blue].sound, currentSongTimer);
			}
		}
		else if (!strcmp(triggerZone, "vert"))
		{
			if (_gd->currentColor != green)
			{
				if (_gd->currentColor == red)
				{
					currentSongTimer = sfSound_getPlayingOffset(_gd->musicLaby[red].sound);
					_gd->lastColor = red;
				}
				if (_gd->currentColor == blue)
				{
					currentSongTimer = sfSound_getPlayingOffset(_gd->musicLaby[blue].sound);
					_gd->lastColor = blue;
				}
				if (_gd->currentColor == yellow)
				{
					currentSongTimer = sfSound_getPlayingOffset(_gd->musicLaby[yellow].sound);
					_gd->lastColor = yellow;
				}
				_gd->currentColor = green;
				sfSound_play(_gd->musicLaby[green].sound);
				sfSound_setPlayingOffset(_gd->musicLaby[green].sound, currentSongTimer);
			}
		}
		else if (!strcmp(triggerZone, "jaune"))
		{
			if (_gd->currentColor != yellow)
			{
				if (_gd->currentColor == red)
				{
					currentSongTimer = sfSound_getPlayingOffset(_gd->musicLaby[red].sound);
					_gd->lastColor = red;
				}
				if (_gd->currentColor == blue)
				{
					currentSongTimer = sfSound_getPlayingOffset(_gd->musicLaby[blue].sound);
					_gd->lastColor = blue;
				}
				if (_gd->currentColor == green)
				{
					currentSongTimer = sfSound_getPlayingOffset(_gd->musicLaby[green].sound);
					_gd->lastColor = green;
				}
				_gd->currentColor = yellow;
				sfSound_play(_gd->musicLaby[yellow].sound);
				sfSound_setPlayingOffset(_gd->musicLaby[yellow].sound, currentSongTimer);
			}
		}
		else if (!strcmp(triggerZone, "exit"))
		{
			if (_gd->worldAmbience.isPlaying == sfFalse)
			{
				sfSound_stop(_gd->musicLaby[red].sound);
				sfSound_stop(_gd->musicLaby[blue].sound);
				sfSound_stop(_gd->musicLaby[green].sound);
				sfSound_stop(_gd->musicLaby[yellow].sound);
				sfSound_play(_gd->worldAmbience.sound);
				_gd->worldAmbience.isPlaying = sfTrue;
			}
		}
		break;
	case shipEnd:
		strcpy(triggerZone, "Metal");
		for (int i = 0; i < _gd->mapShipEnd->nbTriggerSound; i++)
		{
			if (_gd->player.pos.x + 16 >= _gd->mapShipEnd->mapTriggerSound[i].pos.x
				&& _gd->player.pos.x - 16 <= _gd->mapShipEnd->mapTriggerSound[i].pos.x + _gd->mapShipEnd->mapTriggerSound[i].size.x
				&& _gd->player.pos.y + 59 >= _gd->mapShipEnd->mapTriggerSound[i].pos.y
				&& _gd->player.pos.y + 28 <= _gd->mapShipEnd->mapTriggerSound[i].pos.y + _gd->mapShipEnd->mapTriggerSound[i].size.y)
			{
				strcpy(triggerZone, _gd->mapShipEnd->mapTriggerSound[i].name);
			}

		}
		if (!strcmp(triggerZone, "Carpet"))
		{
			if (strcmp(_gd->player.stepName, "Carpet"))
			{
				_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Monde1/Pas/CarpetSteps.wav");
				_gd->player.stepSound.isPlaying = sfFalse;
				sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
				strcpy(_gd->player.stepName, "Carpet");
			}
		}
		else if (!strcmp(triggerZone, "Metal"))
		{
			if (strcmp(_gd->player.stepName, "Metal"))
			{
				_gd->player.stepSound.buffer = sfSoundBuffer_createFromFile("../Ressources/Sons/Vaisseau/Pas/MetalSteps.wav");
				_gd->player.stepSound.isPlaying = sfFalse;
				sfSound_setBuffer(_gd->player.stepSound.sound, _gd->player.stepSound.buffer);
				strcpy(_gd->player.stepName, "Metal");
			}
		}
		break;
	default:
		break;
	}
}

int TriggerPlayerDestructible(GameData* _gd)
{
	switch (_gd->world)
	{
	case intro:
		for (int i = 0; i < _gd->mapIntro->nbDestructible; i++)
		{
			if (_gd->player.pos.x + 16 >= _gd->mapIntro->mapDestructible[i].pos.x
				&& _gd->player.pos.x - 16 <= _gd->mapIntro->mapDestructible[i].pos.x + _gd->mapIntro->mapDestructible[i].size.x
				&& _gd->player.pos.y + 59 >= _gd->mapIntro->mapDestructible[i].pos.y
				&& _gd->player.pos.y + 28 <= _gd->mapIntro->mapDestructible[i].pos.y + _gd->mapIntro->mapDestructible[i].size.y
				&& _gd->mapIntro->mapDestructible[i].active == sfTrue && _gd->failDream == sfFalse)
			{
				return 1;
			}
		}
		return 0;
		break;

	case island:
		for (int i = 0; i < _gd->mapIsland->nbDestructible; i++)
		{
			if (_gd->player.pos.x + 16 >= _gd->mapIsland->mapDestructible[i].pos.x
				&& _gd->player.pos.x - 16 <= _gd->mapIsland->mapDestructible[i].pos.x + _gd->mapIsland->mapDestructible[i].size.x
				&& _gd->player.pos.y + 59 >= _gd->mapIsland->mapDestructible[i].pos.y
				&& _gd->player.pos.y + 28 <= _gd->mapIsland->mapDestructible[i].pos.y + _gd->mapIsland->mapDestructible[i].size.y
				&& _gd->mapIsland->mapDestructible[i].active == sfTrue)
			{
				return 1;
			}
		}
		return 0;
		break;
	default:
		return 0;
		break;
	}
}

int TriggerPlayerInteractionIntro(GameData* _gd, int* _indice)
{
	for (int i = 0; i < _gd->mapIntro->nbInteraction; i++)
	{
		if (_gd->player.pos.x + 16 >= _gd->mapIntro->mapInteraction[i].pos.x
			&& _gd->player.pos.x - 16 <= _gd->mapIntro->mapInteraction[i].pos.x + _gd->mapIntro->mapInteraction[i].size.x
			&& _gd->player.pos.y + 59 >= _gd->mapIntro->mapInteraction[i].pos.y
			&& _gd->player.pos.y + 28 <= _gd->mapIntro->mapInteraction[i].pos.y + _gd->mapIntro->mapInteraction[i].size.y)
		{
			*_indice = i;

			if (_gd->enigme.doorDigicode.resolvedIntro == sfFalse && _gd->failDream == sfFalse)
			{
				_gd->player.interaction = sfTrue;
			}
			else if (!strcmp(_gd->mapIntro->mapInteraction[i].name, "bed"))
			{
				_gd->player.interaction = sfTrue;
			}

			return 1;
		}
	}
	_gd->player.interaction = sfFalse;
	return 0;
}

int TriggerPlayerInteractionIsland(GameData* _gd, int* _indiceInteraction, int* _indiceDestructible)
{
	//interraction avec le puzzle
	for (int i = 0; i < _gd->mapIsland->nbInteraction; i++)
	{
		if (_gd->player.pos.x + 16 >= _gd->mapIsland->mapInteraction[i].pos.x
			&& _gd->player.pos.x - 16 <= _gd->mapIsland->mapInteraction[i].pos.x + _gd->mapIsland->mapInteraction[i].size.x
			&& _gd->player.pos.y + 59 >= _gd->mapIsland->mapInteraction[i].pos.y
			&& _gd->player.pos.y + 28 <= _gd->mapIsland->mapInteraction[i].pos.y + _gd->mapIsland->mapInteraction[i].size.y)
		{
			*_indiceInteraction = i;
			*_indiceDestructible = NULL;

			if (!strcmp(_gd->mapIsland->mapInteraction[i].name, "EnterHouseBox")
				&& _gd->enigme.dialogue.resolvedDream_1 == sfTrue)
			{
				_gd->player.interaction = sfTrue;
			}
			else if (!strcmp(_gd->mapIsland->mapInteraction[i].name, "PuzzleEnigme")
				&& _gd->enigme.utilityPuzzle.resolvedPuzzleDream_1 == sfFalse)
			{
				_gd->player.interaction = sfTrue;
			}
			else if (!strcmp(_gd->mapIsland->mapInteraction[i].name, "DoorEnigme")
				&& _gd->enigme.dialogue.resolvedDream_1 == sfFalse)
			{
				_gd->player.interaction = sfTrue;
			}
			else if (strcmp(_gd->mapIsland->mapInteraction[i].name, "EnterHouseBox")
				&& strcmp(_gd->mapIsland->mapInteraction[i].name, "PuzzleEnigme")
				&& strcmp(_gd->mapIsland->mapInteraction[i].name, "DoorEnigme"))
			{
				_gd->player.interaction = sfTrue;
			}
			return 1;
		}
	}
	for (int i = 0; i < _gd->mapIsland->nbDestructible; i++)
	{
		if (_gd->player.pos.x + 16 >= _gd->mapIsland->mapDestructible[i].pos.x
			&& _gd->player.pos.x - 16 <= _gd->mapIsland->mapDestructible[i].pos.x + _gd->mapIsland->mapDestructible[i].size.x
			&& _gd->player.pos.y + 59 >= _gd->mapIsland->mapDestructible[i].pos.y
			&& _gd->player.pos.y + 28 <= _gd->mapIsland->mapDestructible[i].pos.y + _gd->mapIsland->mapDestructible[i].size.y
			&& _gd->mapIsland->mapDestructible[i].active == sfFalse
			&& strcmp(_gd->mapIsland->mapDestructible[i].name, "PontBlocked")
			&& _gd->mapIsland->mapDestructible[i].recup == sfFalse)
		{
			*_indiceInteraction = NULL;
			*_indiceDestructible = i;
			_gd->player.interaction = sfTrue;

			return 1;
		}
	}

	_gd->player.interaction = sfFalse;
	return 0;

}

int TriggerPlayerInteractionBedRoom(GameData* _gd, int* _indice)
{
	for (int i = 0; i < _gd->mapBedRoom->nbInteraction; i++)
	{
		if (_gd->player.pos.x + 16 >= _gd->mapBedRoom->mapInteraction[i].pos.x
			&& _gd->player.pos.x - 16 <= _gd->mapBedRoom->mapInteraction[i].pos.x + _gd->mapBedRoom->mapInteraction[i].size.x
			&& _gd->player.pos.y + 59 >= _gd->mapBedRoom->mapInteraction[i].pos.y
			&& _gd->player.pos.y + 28 <= _gd->mapBedRoom->mapInteraction[i].pos.y + _gd->mapBedRoom->mapInteraction[i].size.y)
		{
			*_indice = i;

			if (!strcmp(_gd->mapBedRoom->mapInteraction[i].name, "bed"))
			{
				_gd->player.interaction = sfTrue;

			}
			return 1;
		}
	}
	_gd->player.interaction = sfFalse;
	return 0;
}

int TriggerPlayerInteractionJungle(GameData* _gd, int* _indice, int* _indiceDestructible)
{
	for (int i = 0; i < _gd->mapJungle->nbInteraction; i++)
	{
		if (_gd->player.pos.x + 16 >= _gd->mapJungle->mapInteraction[i].pos.x
			&& _gd->player.pos.x - 16 <= _gd->mapJungle->mapInteraction[i].pos.x + _gd->mapJungle->mapInteraction[i].size.x
			&& _gd->player.pos.y + 59 >= _gd->mapJungle->mapInteraction[i].pos.y
			&& _gd->player.pos.y + 28 <= _gd->mapJungle->mapInteraction[i].pos.y + _gd->mapJungle->mapInteraction[i].size.y)
		{
			*_indice = i;
			*_indiceDestructible = NULL;

			if (!strcmp(_gd->mapJungle->mapInteraction[i].name, "wrong"))
			{
				_gd->player.interaction = sfTrue;
			}
			if (!strcmp(_gd->mapJungle->mapInteraction[i].name, "good"))
			{
				_gd->player.interaction = sfTrue;
			}
			if (!strcmp(_gd->mapJungle->mapInteraction[i].name, "TutoLaby"))
			{
				_gd->player.interaction = sfTrue;
			}

			if (_gd->enigme.interupteur.resolvedDiode == sfFalse)
			{
				if (!strcmp(_gd->mapJungle->mapInteraction[i].name, "EnigmeDiodeTuto")
					&& _gd->enigme.interupteur.diodeFini[tutoDiode] == sfFalse)
				{
					_gd->player.interaction = sfTrue;
				}

				if (!strcmp(_gd->mapJungle->mapInteraction[i].name, "EnigmeDiodeSymbole")
					&& _gd->enigme.interupteur.diodeFini[symboleDiode] == sfFalse)
				{
					_gd->player.interaction = sfTrue;
				}

				if (!strcmp(_gd->mapJungle->mapInteraction[i].name, "EnigmeDiodeFull")
					&& _gd->enigme.interupteur.diodeFini[fullDiode] == sfFalse)
				{
					_gd->player.interaction = sfTrue;
				}
			}

			if (_gd->enigme.puzzleJungle.resolvedPuzzleJungle == sfFalse)
			{
				if (!strcmp(_gd->mapJungle->mapInteraction[i].name, "EnigmePuzzleJungle"))
				{
					_gd->player.interaction = sfTrue;
				}
			}

			if (_gd->enigme.decryptage.resolved == sfFalse)
			{
				if (!strcmp(_gd->mapJungle->mapInteraction[i].name, "EnigmeDecryptage"))
				{
					_gd->player.interaction = sfTrue;
				}
			}

			if (!strcmp(_gd->mapJungle->mapInteraction[i].name, "End"))
			{
				_gd->player.interaction = sfTrue;
			}
			return 1;
		}
	}

	for (int j = 0; j < _gd->mapJungle->nbDestructible; j++)
	{
		if (_gd->player.pos.x + 16 >= _gd->mapJungle->mapDestructible[j].pos.x
			&& _gd->player.pos.x - 16 <= _gd->mapJungle->mapDestructible[j].pos.x + _gd->mapJungle->mapDestructible[j].size.x
			&& _gd->player.pos.y + 59 >= _gd->mapJungle->mapDestructible[j].pos.y
			&& _gd->player.pos.y + 28 <= _gd->mapJungle->mapDestructible[j].pos.y + _gd->mapJungle->mapDestructible[j].size.y
			&& _gd->mapJungle->mapDestructible[j].active == sfFalse
			&& _gd->mapJungle->mapDestructible[j].recup == sfFalse)
		{
			*_indice = NULL;
			*_indiceDestructible = j;
			_gd->player.interaction = sfTrue;

			return 1;
		}
	}
	_gd->player.interaction = sfFalse;
	return 0;
}

int TriggerPlayerInteractionShipEnd(GameData* _gd, int* _indice)
{
	for (int i = 0; i < _gd->mapShipEnd->nbInteraction; i++)
	{
		if (_gd->player.pos.x + 16 >= _gd->mapShipEnd->mapInteraction[i].pos.x
			&& _gd->player.pos.x - 16 <= _gd->mapShipEnd->mapInteraction[i].pos.x + _gd->mapShipEnd->mapInteraction[i].size.x
			&& _gd->player.pos.y + 59 >= _gd->mapShipEnd->mapInteraction[i].pos.y
			&& _gd->player.pos.y + 28 <= _gd->mapShipEnd->mapInteraction[i].pos.y + _gd->mapShipEnd->mapInteraction[i].size.y)
		{
			*_indice = i;

			if (!strcmp(_gd->mapShipEnd->mapInteraction[i].name, "End_Game"))
			{
				_gd->player.interaction = sfTrue;
			}
			return 1;
		}
	}
	_gd->player.interaction = sfFalse;
	return 0;
}

void InteractionPlayerIntro(GameData* _gd, int _indice)
{
	//permet de lancer le mastermind de l'intro
	if (_gd->enigme.doorDigicode.resolvedIntro == sfFalse
		&& !strcmp(_gd->mapIntro->mapInteraction[_indice].name, "mastermind_intro"))
	{
		sfSound_stop(_gd->player.stepSound.sound);
		sfSound_play(_gd->enigme.doorDigicode.interactSound.sound);
		_gd->inGameState = enigme;
		_gd->enigmeState = mastermindIntro;
		InitMastermindIntro(_gd);
	}

	//permet d'aller dans le monde island grace au lit
	if (!strcmp(_gd->mapIntro->mapInteraction[_indice].name, "bed"))
	{
		sfSound_stop(_gd->player.stepSound.sound);
		_gd->cutSceneState = vaisseauSleep;
		_gd->inGameState = cutscene;
		InitCutScene(_gd);
		/*_gd->world = jungle;
		InitJungle(_gd);*/



	}
}

void InteractionPlayerIsland(GameData* _gd, int _indiceInteraction, int _indiceDestructible)
{
	sfTime currentSongTimer;
	//permet de lancer l'enigme du puzzle
	if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "PuzzleEnigme")
		&& _gd->enigme.utilityPuzzle.resolvedPuzzleDream_1 == sfFalse
		&& _gd->player.pos.x > 700)
	{
		sfSound_stop(_gd->player.stepSound.sound);
		sfSound_play(_gd->enigme.utilityPuzzle.woodPickUpSound.sound);
		_gd->inGameState = enigme;
		_gd->enigmeState = puzzleIsland;
		_gd->enigme.utilityPuzzle.openFirstTime = sfTrue;
	}
	if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "BoxEnigme"))
	{
		sfSound_stop(_gd->player.stepSound.sound);
		_gd->inGameState = enigme;
		_gd->enigmeState = mastermindBox;
		_gd->enigmeBox = box;
	}

	//point de tp de l'island
	{
		//permet d'aller dans la maison du début
		if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "EnterHouse"))
		{
			sfSound_stop(_gd->player.stepSound.sound);
			for (int i = 0; i < _gd->mapIsland->nbPoint; i++)
			{
				if (!strcmp(_gd->mapIsland->mapPoint[i].name, "spawn_house"))
				{
					if (_gd->worldAmbience.isPlaying == sfFalse)
					{
						currentSongTimer = sfSound_getPlayingOffset(_gd->worldAmbienceOutside.sound);
						sfSound_pause(_gd->worldAmbienceOutside.sound);
						_gd->worldAmbience.isPlaying = sfTrue;
						sfSound_play(_gd->worldAmbience.sound);
						sfSound_setPlayingOffset(_gd->worldAmbience.sound, currentSongTimer);
					}
					_gd->player.pos.x = _gd->mapIsland->mapPoint[i].pos.x;
					_gd->player.pos.y = _gd->mapIsland->mapPoint[i].pos.y;

				}
			}
		}

		//permet de sortir de la maison du début et de retourner sur l'ile
		if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "ExitHouseSpawn"))
		{
			sfSound_stop(_gd->player.stepSound.sound);
			if (_gd->cinematique.exitHouse == sfFalse)
			{
				_gd->cutSceneState = islandLeaveHouse;
				_gd->inGameState = cutscene;
				InitCutScene(_gd);

			}
			for (int i = 0; i < _gd->mapIsland->nbPoint; i++)
			{
				if (!strcmp(_gd->mapIsland->mapPoint[i].name, "spawn_island"))
				{
					if (_gd->worldAmbience.isPlaying == sfTrue)
					{
						currentSongTimer = sfSound_getPlayingOffset(_gd->worldAmbience.sound);
						sfSound_pause(_gd->worldAmbience.sound);
						_gd->worldAmbience.isPlaying = sfFalse;
						sfSound_play(_gd->worldAmbienceOutside.sound);
						sfSound_setPlayingOffset(_gd->worldAmbienceOutside.sound, currentSongTimer);

					}
					_gd->player.pos.x = _gd->mapIsland->mapPoint[i].pos.x;
					_gd->player.pos.y = _gd->mapIsland->mapPoint[i].pos.y;
				}
			}
		}
		//permet d'aller dans le premier tipi
		if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "EnterTipi1"))
		{
			sfSound_stop(_gd->player.stepSound.sound);
			for (int i = 0; i < _gd->mapIsland->nbPoint; i++)
			{
				if (!strcmp(_gd->mapIsland->mapPoint[i].name, "spawnTipi1"))
				{
					if (_gd->worldAmbience.isPlaying == sfFalse)
					{
						currentSongTimer = sfSound_getPlayingOffset(_gd->worldAmbienceOutside.sound);
						sfSound_pause(_gd->worldAmbienceOutside.sound);
						_gd->worldAmbience.isPlaying = sfTrue;
						sfSound_play(_gd->worldAmbience.sound);
						sfSound_setPlayingOffset(_gd->worldAmbience.sound, currentSongTimer);
					}
					_gd->player.pos.x = _gd->mapIsland->mapPoint[i].pos.x;
					_gd->player.pos.y = _gd->mapIsland->mapPoint[i].pos.y;
				}
			}
		}
		//permet de sorti du tipi 2 et de retourner sur l'ile
		if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "ExitTipi1"))
		{
			sfSound_stop(_gd->player.stepSound.sound);
			for (int i = 0; i < _gd->mapIsland->nbPoint; i++)
			{
				if (!strcmp(_gd->mapIsland->mapPoint[i].name, "spawn_island_tipi1"))
				{
					if (_gd->worldAmbience.isPlaying == sfTrue)
					{
						currentSongTimer = sfSound_getPlayingOffset(_gd->worldAmbience.sound);
						sfSound_pause(_gd->worldAmbience.sound);
						_gd->worldAmbience.isPlaying = sfFalse;
						sfSound_play(_gd->worldAmbienceOutside.sound);
						sfSound_setPlayingOffset(_gd->worldAmbienceOutside.sound, currentSongTimer);

					}
					_gd->player.pos.x = _gd->mapIsland->mapPoint[i].pos.x;
					_gd->player.pos.y = _gd->mapIsland->mapPoint[i].pos.y;
				}
			}
		}
		//permet d'aller dans le deuxieme  tipi
		if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "EnterTipi2"))
		{
			sfSound_stop(_gd->player.stepSound.sound);
			for (int i = 0; i < _gd->mapIsland->nbPoint; i++)
			{
				if (!strcmp(_gd->mapIsland->mapPoint[i].name, "spawnTipi2"))
				{
					if (_gd->worldAmbience.isPlaying == sfFalse)
					{
						currentSongTimer = sfSound_getPlayingOffset(_gd->worldAmbienceOutside.sound);
						sfSound_pause(_gd->worldAmbienceOutside.sound);
						_gd->worldAmbience.isPlaying = sfTrue;
						sfSound_play(_gd->worldAmbience.sound);
						sfSound_setPlayingOffset(_gd->worldAmbience.sound, currentSongTimer);
					}
					_gd->player.pos.x = _gd->mapIsland->mapPoint[i].pos.x;
					_gd->player.pos.y = _gd->mapIsland->mapPoint[i].pos.y;
				}
			}
		}
		//permet de sorti du tipi 2 et de retourner sur l'ile
		if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "ExitTipi2"))
		{
			sfSound_stop(_gd->player.stepSound.sound);
			for (int i = 0; i < _gd->mapIsland->nbPoint; i++)
			{
				if (!strcmp(_gd->mapIsland->mapPoint[i].name, "spawn_island_tipi2"))
				{
					if (_gd->worldAmbience.isPlaying == sfTrue)
					{
						currentSongTimer = sfSound_getPlayingOffset(_gd->worldAmbience.sound);
						sfSound_pause(_gd->worldAmbience.sound);
						_gd->worldAmbience.isPlaying = sfFalse;
						sfSound_play(_gd->worldAmbienceOutside.sound);
						sfSound_setPlayingOffset(_gd->worldAmbienceOutside.sound, currentSongTimer);

					}
					_gd->player.pos.x = _gd->mapIsland->mapPoint[i].pos.x;
					_gd->player.pos.y = _gd->mapIsland->mapPoint[i].pos.y;
				}
			}
		}
		//permet d'aller dans le troisieme  tipi
		if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "EnterTipi3"))
		{
			sfSound_stop(_gd->player.stepSound.sound);
			for (int i = 0; i < _gd->mapIsland->nbPoint; i++)
			{
				if (!strcmp(_gd->mapIsland->mapPoint[i].name, "spawnTipi3"))
				{
					if (_gd->worldAmbience.isPlaying == sfFalse)
					{
						currentSongTimer = sfSound_getPlayingOffset(_gd->worldAmbienceOutside.sound);
						sfSound_pause(_gd->worldAmbienceOutside.sound);
						_gd->worldAmbience.isPlaying = sfTrue;
						sfSound_play(_gd->worldAmbience.sound);
						sfSound_setPlayingOffset(_gd->worldAmbience.sound, currentSongTimer);
					}
					_gd->player.pos.x = _gd->mapIsland->mapPoint[i].pos.x;
					_gd->player.pos.y = _gd->mapIsland->mapPoint[i].pos.y;
				}
			}
		}
		//permet de sorti du tipi 3 et de retourner sur l'ile
		if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "ExitTipi3"))
		{
			sfSound_stop(_gd->player.stepSound.sound);
			for (int i = 0; i < _gd->mapIsland->nbPoint; i++)
			{
				if (!strcmp(_gd->mapIsland->mapPoint[i].name, "spawn_island_tipi3"))
				{
					if (_gd->worldAmbience.isPlaying == sfTrue)
					{
						currentSongTimer = sfSound_getPlayingOffset(_gd->worldAmbience.sound);
						sfSound_pause(_gd->worldAmbience.sound);
						_gd->worldAmbience.isPlaying = sfFalse;
						sfSound_play(_gd->worldAmbienceOutside.sound);
						sfSound_setPlayingOffset(_gd->worldAmbienceOutside.sound, currentSongTimer);

					}
					_gd->player.pos.x = _gd->mapIsland->mapPoint[i].pos.x;
					_gd->player.pos.y = _gd->mapIsland->mapPoint[i].pos.y;
				}
			}
		}
		//permet d'aller dans le quetrieme  tipi
		if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "EnterTipi4"))
		{
			sfSound_stop(_gd->player.stepSound.sound);
			for (int i = 0; i < _gd->mapIsland->nbPoint; i++)
			{
				if (!strcmp(_gd->mapIsland->mapPoint[i].name, "spawnTipi4"))
				{
					if (_gd->worldAmbience.isPlaying == sfFalse)
					{
						currentSongTimer = sfSound_getPlayingOffset(_gd->worldAmbienceOutside.sound);
						sfSound_pause(_gd->worldAmbienceOutside.sound);
						_gd->worldAmbience.isPlaying = sfTrue;
						sfSound_play(_gd->worldAmbience.sound);
						sfSound_setPlayingOffset(_gd->worldAmbience.sound, currentSongTimer);
					}
					_gd->player.pos.x = _gd->mapIsland->mapPoint[i].pos.x;
					_gd->player.pos.y = _gd->mapIsland->mapPoint[i].pos.y;
				}
			}
		}
		//permet de sorti du tipi 4 et de retourner sur l'ile
		if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "ExitTipi4"))
		{
			sfSound_stop(_gd->player.stepSound.sound);
			for (int i = 0; i < _gd->mapIsland->nbPoint; i++)
			{
				if (!strcmp(_gd->mapIsland->mapPoint[i].name, "spawn_island_tipi4"))
				{
					if (_gd->worldAmbience.isPlaying == sfTrue)
					{
						currentSongTimer = sfSound_getPlayingOffset(_gd->worldAmbience.sound);
						sfSound_pause(_gd->worldAmbience.sound);
						_gd->worldAmbience.isPlaying = sfFalse;
						sfSound_play(_gd->worldAmbienceOutside.sound);
						sfSound_setPlayingOffset(_gd->worldAmbienceOutside.sound, currentSongTimer);

					}
					_gd->player.pos.x = _gd->mapIsland->mapPoint[i].pos.x;
					_gd->player.pos.y = _gd->mapIsland->mapPoint[i].pos.y;
				}
			}
		}

		if (_gd->enigme.dialogue.resolvedDream_1 == sfTrue)
		{
			if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "EnterHouseBox"))
			{
				sfSound_stop(_gd->player.stepSound.sound);
				for (int i = 0; i < _gd->mapIsland->nbPoint; i++)
				{
					if (!strcmp(_gd->mapIsland->mapPoint[i].name, "spawn_houseBox"))
					{
						if (_gd->worldAmbience.isPlaying == sfFalse)
						{
							currentSongTimer = sfSound_getPlayingOffset(_gd->worldAmbienceOutside.sound);
							sfSound_pause(_gd->worldAmbienceOutside.sound);
							_gd->worldAmbience.isPlaying = sfTrue;
							sfSound_play(_gd->worldAmbience.sound);
							sfSound_setPlayingOffset(_gd->worldAmbience.sound, currentSongTimer);
						}
						_gd->player.pos.x = _gd->mapIsland->mapPoint[i].pos.x;
						_gd->player.pos.y = _gd->mapIsland->mapPoint[i].pos.y;
					}
				}
			}
			if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "ExitHouseBox"))
			{
				sfSound_stop(_gd->player.stepSound.sound);
				for (int i = 0; i < _gd->mapIsland->nbPoint; i++)
				{
					if (!strcmp(_gd->mapIsland->mapPoint[i].name, "spawn_island_house"))
					{
						if (_gd->worldAmbience.isPlaying == sfTrue)
						{
							currentSongTimer = sfSound_getPlayingOffset(_gd->worldAmbience.sound);
							sfSound_pause(_gd->worldAmbience.sound);
							_gd->worldAmbience.isPlaying = sfFalse;
							sfSound_play(_gd->worldAmbienceOutside.sound);
							sfSound_setPlayingOffset(_gd->worldAmbienceOutside.sound, currentSongTimer);

						}
						_gd->player.pos.x = _gd->mapIsland->mapPoint[i].pos.x;
						_gd->player.pos.y = _gd->mapIsland->mapPoint[i].pos.y;
					}
				}
			}
		}
	}

	//permet de gerer toute les planches pour reconstruire le puzzle
	if (_gd->enigme.utilityPuzzle.resolvedPuzzleDream_1 == sfFalse)
	{
		if (!strcmp(_gd->mapIsland->mapDestructible[_indiceDestructible].name, "planche18"))
		{
			_gd->enigme.utilityPuzzle.piece[18].isVisible = sfTrue;
			_gd->mapIsland->mapDestructible[_indiceDestructible].recup = sfTrue;
			_gd->enigme.utilityPuzzle.recupPlanche = sfTrue;
			_gd->enigme.utilityPuzzle.nbPlancheRecup++;
			sfSound_setVolume(_gd->enigme.utilityPuzzle.woodPickUpSound.sound, _gd->soundGlobal * _gd->soundInterraction);
			sfSound_play(_gd->enigme.utilityPuzzle.woodPickUpSound.sound);
		}
		else if (!strcmp(_gd->mapIsland->mapDestructible[_indiceDestructible].name, "planche5_6"))
		{
			_gd->enigme.utilityPuzzle.piece[5].isVisible = sfTrue;
			_gd->enigme.utilityPuzzle.piece[6].isVisible = sfTrue;
			_gd->mapIsland->mapDestructible[_indiceDestructible].recup = sfTrue;
			_gd->enigme.utilityPuzzle.recupPlanche = sfTrue;
			_gd->enigme.utilityPuzzle.isTwoPlanche = sfTrue;
			_gd->enigme.utilityPuzzle.nbPlancheRecup += 2;
			sfSound_setVolume(_gd->enigme.utilityPuzzle.woodPickUpSound.sound, _gd->soundGlobal * _gd->soundInterraction);
			sfSound_play(_gd->enigme.utilityPuzzle.woodPickUpSound.sound);
		}
		else if (!strcmp(_gd->mapIsland->mapDestructible[_indiceDestructible].name, "planche15_16")
			&& _gd->player.pos.x < 800)
		{
			_gd->enigme.utilityPuzzle.piece[15].isVisible = sfTrue;
			_gd->enigme.utilityPuzzle.piece[16].isVisible = sfTrue;
			_gd->mapIsland->mapDestructible[_indiceDestructible].recup = sfTrue;
			_gd->enigme.utilityPuzzle.recupPlanche = sfTrue;
			_gd->enigme.utilityPuzzle.isTwoPlanche = sfTrue;
			_gd->enigme.utilityPuzzle.nbPlancheRecup += 2;
			sfSound_setVolume(_gd->enigme.utilityPuzzle.woodPickUpSound.sound, _gd->soundGlobal * _gd->soundInterraction);
			sfSound_play(_gd->enigme.utilityPuzzle.woodPickUpSound.sound);
		}
		else if (!strcmp(_gd->mapIsland->mapDestructible[_indiceDestructible].name, "planche9"))
		{
			_gd->enigme.utilityPuzzle.piece[9].isVisible = sfTrue;
			_gd->mapIsland->mapDestructible[_indiceDestructible].recup = sfTrue;
			_gd->enigme.utilityPuzzle.nbPlancheRecup++;
			_gd->enigme.utilityPuzzle.recupPlanche = sfTrue;
			sfSound_setVolume(_gd->enigme.utilityPuzzle.woodPickUpSound.sound, _gd->soundGlobal * _gd->soundInterraction);
			sfSound_play(_gd->enigme.utilityPuzzle.woodPickUpSound.sound);
		}
		else if (!strcmp(_gd->mapIsland->mapDestructible[_indiceDestructible].name, "planche_23"))
		{
			_gd->enigme.utilityPuzzle.piece[23].isVisible = sfTrue;
			_gd->mapIsland->mapDestructible[_indiceDestructible].recup = sfTrue;
			_gd->enigme.utilityPuzzle.recupPlanche = sfTrue;
			_gd->enigme.utilityPuzzle.nbPlancheRecup++;
			sfSound_setVolume(_gd->enigme.utilityPuzzle.woodPickUpSound.sound, _gd->soundGlobal * _gd->soundInterraction);
			sfSound_play(_gd->enigme.utilityPuzzle.woodPickUpSound.sound);
		}
		else if (!strcmp(_gd->mapIsland->mapDestructible[_indiceDestructible].name, "planche7_8"))
		{
			_gd->enigme.utilityPuzzle.piece[7].isVisible = sfTrue;
			_gd->enigme.utilityPuzzle.piece[8].isVisible = sfTrue;
			_gd->mapIsland->mapDestructible[_indiceDestructible].recup = sfTrue;
			_gd->enigme.utilityPuzzle.recupPlanche = sfTrue;
			_gd->enigme.utilityPuzzle.isTwoPlanche = sfTrue;
			_gd->enigme.utilityPuzzle.nbPlancheRecup += 2;
			sfSound_setVolume(_gd->enigme.utilityPuzzle.woodPickUpSound.sound, _gd->soundGlobal * _gd->soundInterraction);
			sfSound_play(_gd->enigme.utilityPuzzle.woodPickUpSound.sound);
		}
	}

	//permet de parler au pnj de l'ile pour l'engime
	else
	{
		if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "PNJHelp"))
		{
			sfSound_stop(_gd->player.stepSound.sound);
			_gd->enigme.dialogue.state = INDIALOGUE;
			_gd->enigmeState = dialogueIsland;
			_gd->enigme.dialogue.whoTalk = PNJ_HELP;
			if (_gd->npc[0].voice.isPlaying == sfFalse)
			{
				sfSound_setVolume(_gd->npc[0].voice.sound, _gd->soundGlobal * _gd->soundInterraction);
				sfSound_play(_gd->npc[0].voice.sound);
				_gd->npc[0].voice.isPlaying = sfTrue;
			}
		}
		else if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "PNJ_0"))
		{
			sfSound_stop(_gd->player.stepSound.sound);
			_gd->enigme.dialogue.state = INDIALOGUE;
			_gd->enigmeState = dialogueIsland;
			_gd->enigme.dialogue.whoTalk = PNJ_0;
			_gd->enigme.dialogue.isTalk[PNJ_0] = sfTrue;
			if (_gd->npc[1].voice.isPlaying == sfFalse)
			{
				sfSound_setVolume(_gd->npc[1].voice.sound, _gd->soundGlobal * _gd->soundInterraction);
				sfSound_play(_gd->npc[1].voice.sound);
				_gd->npc[1].voice.isPlaying = sfTrue;
			}
		}
		else if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "PNJ_1"))
		{
			sfSound_stop(_gd->player.stepSound.sound);
			_gd->enigme.dialogue.state = INDIALOGUE;
			_gd->enigmeState = dialogueIsland;
			_gd->enigme.dialogue.whoTalk = PNJ_1;
			_gd->enigme.dialogue.isTalk[PNJ_1] = sfTrue;
			if (_gd->npc[2].voice.isPlaying == sfFalse)
			{
				sfSound_setVolume(_gd->npc[2].voice.sound, _gd->soundGlobal * _gd->soundInterraction);
				sfSound_play(_gd->npc[2].voice.sound);
				_gd->npc[2].voice.isPlaying = sfTrue;
			}
		}
		else if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "PNJ_2"))
		{
			sfSound_stop(_gd->player.stepSound.sound);
			_gd->enigme.dialogue.state = INDIALOGUE;
			_gd->enigmeState = dialogueIsland;
			_gd->enigme.dialogue.whoTalk = PNJ_2;
			_gd->enigme.dialogue.isTalk[PNJ_2] = sfTrue;
			if (_gd->npc[3].voice.isPlaying == sfFalse)
			{
				sfSound_setVolume(_gd->npc[3].voice.sound, _gd->soundGlobal * _gd->soundInterraction);
				sfSound_play(_gd->npc[3].voice.sound);
				_gd->npc[3].voice.isPlaying = sfTrue;
			}
		}
		else if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "PNJ_3"))
		{
			sfSound_stop(_gd->player.stepSound.sound);
			_gd->enigme.dialogue.state = INDIALOGUE;
			_gd->enigmeState = dialogueIsland;
			_gd->enigme.dialogue.whoTalk = PNJ_3;
			_gd->enigme.dialogue.isTalk[PNJ_3] = sfTrue;
			if (_gd->npc[4].voice.isPlaying == sfFalse)
			{
				sfSound_setVolume(_gd->npc[4].voice.sound, _gd->soundGlobal * _gd->soundInterraction);
				sfSound_play(_gd->npc[4].voice.sound);
				_gd->npc[4].voice.isPlaying = sfTrue;
			}
		}
		if (!strcmp(_gd->mapIsland->mapInteraction[_indiceInteraction].name, "DoorEnigme")
			&& _gd->enigme.dialogue.resolvedDream_1 == sfFalse)
		{
			sfSound_stop(_gd->player.stepSound.sound);
			if (_gd->enigme.dialogue.letterSound.isPlaying == sfFalse)
			{
				sfSound_play(_gd->enigme.dialogue.letterSound.sound);
				_gd->enigme.dialogue.letterSound.isPlaying = sfTrue;
			}
			_gd->enigme.dialogue.state = DOOR;
			_gd->enigmeState = dialogueIsland;
		}
	}
}

void InteractionPlayerBedRoom(GameData* _gd, int _indice)
{
	//permet d'aller dans le monde island grace au lit
	if (!strcmp(_gd->mapBedRoom->mapInteraction[_indice].name, "bed"))
	{
		sfSound_stop(_gd->player.stepSound.sound);
		/*sfSound_stop(_gd->player.stepSound.sound);
		sfSound_play(_gd->bedInteract.sound);*/
		_gd->world = bedroom;
		_gd->cutSceneState = bedRoomExit;
		_gd->inGameState = cutscene;
		_gd->enigmeState = none;
		InitCutScene(_gd);
	}
}

void InteractionPlayerJungle(GameData* _gd, int _indice, int _indiceDestructible)
{
	//interaction enigme
	{
		if (_gd->enigme.interupteur.resolvedDiode == sfFalse)
		{
			if (!strcmp(_gd->mapJungle->mapInteraction[_indice].name, "EnigmeDiodeTuto")
				&& _gd->enigme.interupteur.diodeFini[tutoDiode] == sfFalse)
			{
				sfSound_stop(_gd->player.stepSound.sound);
				_gd->inGameState = enigme;
				_gd->enigmeState = diodeJungle;
				_gd->enigme.interupteur.interupteurState = tutoDiode;
				InitDiode(_gd);
			}
			if (!strcmp(_gd->mapJungle->mapInteraction[_indice].name, "EnigmeDiodeSymbole")
				&& _gd->enigme.interupteur.diodeFini[symboleDiode] == sfFalse)
			{
				sfSound_stop(_gd->player.stepSound.sound);
				_gd->inGameState = enigme;
				_gd->enigmeState = diodeJungle;
				_gd->enigme.interupteur.interupteurState = symboleDiode;
				InitDiode(_gd);
			}
			if (!strcmp(_gd->mapJungle->mapInteraction[_indice].name, "EnigmeDiodeFull")
				&& _gd->enigme.interupteur.diodeFini[fullDiode] == sfFalse)
			{
				sfSound_stop(_gd->player.stepSound.sound);
				_gd->inGameState = enigme;
				_gd->enigmeState = diodeJungle;
				_gd->enigme.interupteur.interupteurState = fullDiode;
				InitDiode(_gd);
			}
		}

		if (_gd->enigme.puzzleJungle.resolvedPuzzleJungle == sfFalse)
		{
			if (!strcmp(_gd->mapJungle->mapInteraction[_indice].name, "EnigmePuzzleJungle"))
			{
				sfSound_stop(_gd->player.stepSound.sound);
				_gd->inGameState = enigme;
				_gd->enigmeState = puzzleJungle;
				InitPuzzleJungle(_gd);
			}
		}

		if (_gd->enigme.decryptage.resolved == sfFalse)
		{
			if (!strcmp(_gd->mapJungle->mapInteraction[_indice].name, "EnigmeDecryptage"))
			{
				sfSound_stop(_gd->player.stepSound.sound);
				sfSound_play(_gd->enigme.decryptage.bookSound.sound);
				_gd->inGameState = enigme;
				_gd->enigmeState = decryptageJungle;

			}
		}
	}

	if (!strcmp(_gd->mapJungle->mapInteraction[_indice].name, "TutoLaby"))
	{
		sfSound_stop(_gd->player.stepSound.sound);
		_gd->inGameState = tuto;
		_gd->enigmeState = labyrinthe;
	}

	if (!strcmp(_gd->mapJungle->mapInteraction[_indice].name, "good"))
	{
		if (_gd->CoffreGood == sfFalse)
		{
			_gd->inTp = sfTrue;
			_gd->timeAnimCoffre = 0;
			_gd->AnimCurrentCoffre = 48;
			_gd->CoffreGood = sfTrue;
			_gd->enigme.decryptage.InRecup = sfTrue;
			_gd->enigme.decryptage.isVisible[4] = sfTrue;
			_gd->enigme.decryptage.isVisible[5] = sfTrue;
			_gd->enigme.decryptage.nbPaperRecup++;
			_gd->enigme.decryptage.nbPaperRecup++;
			_gd->labyFinish = sfTrue;
			_gd->enigme.decryptage.TwoPaper = sfTrue;

		}
	}
	if (!strcmp(_gd->mapJungle->mapInteraction[_indice].name, "wrong"))
	{
		if (_gd->currentColor == yellow)
		{
			if (_gd->CoffreWrong == sfFalse)
			{
				_gd->inTp = sfTrue;
				_gd->timeAnimCoffre = 0;
				_gd->AnimCurrentCoffre = 48;
				_gd->CoffreWrong = sfTrue;
				_gd->player.interaction = sfFalse;

			}
		}
		if (_gd->currentColor == green)
		{
			_gd->inFourmiTp = sfTrue;
			_gd->inTp = sfTrue;
			sfSound_play(_gd->voiceFourmi.sound);

		}

		if (_gd->currentColor == blue)
		{
			_gd->inGrenouilleTp = sfTrue;
			_gd->inTp = sfTrue;
			_gd->currentTimeGrenouille = 0;
			_gd->player.interaction = sfFalse;
			sfSound_play(_gd->enigme.interupteur.fireflyQuit.sound);
		}

		//_gd->player.pos.x = _gd->mapJungle->mapPoint[1].pos.x;
		//_gd->player.pos.y = _gd->mapJungle->mapPoint[1].pos.y;
		//sfSound_setVolume(_gd->musicLaby[_gd->currentColor].sound, 0);
		//sfSound_stop(_gd->musicLaby[_gd->currentColor].sound);
		//strcpy(_gd->player.stepName, "rouge");
		//_gd->currentColor = red;
		//_gd->lastColor = red;
		//_gd->musicLaby[red].volume = 100/*_gd->soundGlobal * _gd->soundAmbiance*/;
		//sfSound_setVolume(_gd->musicLaby[red].sound, _gd->musicLaby[red].volume);
		//sfSound_play(_gd->musicLaby[red].sound);
		//_gd->musicLaby[blue].volume = 0;
		//sfSound_setVolume(_gd->musicLaby[blue].sound, _gd->musicLaby[blue].volume);
		//_gd->musicLaby[green].volume = 0;
		//sfSound_setVolume(_gd->musicLaby[green].sound, _gd->musicLaby[green].volume);
		//_gd->musicLaby[yellow].volume = 0;
		//sfSound_setVolume(_gd->musicLaby[yellow].sound, _gd->musicLaby[yellow].volume);

	//else if(_gd->currentColor != yellow)
	//{
	//	sfSound_setVolume(_gd->musicLaby[_gd->currentColor].sound, 0);
	//	sfSound_stop(_gd->musicLaby[_gd->currentColor].sound);
	//	strcpy(_gd->player.stepName, "rouge");
	//	_gd->currentColor = red;
	//	_gd->lastColor = red;
	//	_gd->musicLaby[red].volume = 100/*_gd->soundGlobal * _gd->soundAmbiance*/;
	//	sfSound_setVolume(_gd->musicLaby[red].sound, _gd->musicLaby[red].volume);
	//	sfSound_play(_gd->musicLaby[red].sound);
	//	_gd->musicLaby[blue].volume = 0;
	//	sfSound_setVolume(_gd->musicLaby[blue].sound, _gd->musicLaby[blue].volume);
	//	_gd->musicLaby[green].volume = 0;
	//	sfSound_setVolume(_gd->musicLaby[green].sound, _gd->musicLaby[green].volume);
	//	_gd->musicLaby[yellow].volume = 0;
	//	sfSound_setVolume(_gd->musicLaby[yellow].sound, _gd->musicLaby[yellow].volume);
	//}

	}

	if (!strcmp(_gd->mapJungle->mapDestructible[_indiceDestructible].name, "Paper1")
		&& _gd->mapJungle->mapDestructible[_indiceDestructible].recup == sfFalse
		&& _gd->player.pos.y < 8000 && _gd->player.pos.y > 5000
		&& _gd->player.pos.x > 5000)
	{
		sfSound_play(_gd->helpSound.sound);
		_gd->mapJungle->mapDestructible[_indiceDestructible].recup = sfTrue;
		_gd->enigme.decryptage.paperRecup[0] = sfTrue;
		_gd->enigme.decryptage.nbPaperRecup++;
		_gd->enigme.decryptage.InRecup = sfTrue;
		_gd->enigme.decryptage.isVisible[0] = sfTrue;

	}

	else if (!strcmp(_gd->mapJungle->mapDestructible[_indiceDestructible].name, "Paper2")
		&& _gd->mapJungle->mapDestructible[_indiceDestructible].recup == sfFalse)
	{
		sfSound_play(_gd->helpSound.sound);
		_gd->mapJungle->mapDestructible[_indiceDestructible].recup = sfTrue;
		_gd->enigme.decryptage.nbPaperRecup++;
		_gd->enigme.decryptage.paperRecup[1] = sfTrue;
		_gd->enigme.decryptage.InRecup = sfTrue;
		_gd->enigme.decryptage.isVisible[1] = sfTrue;
	}
	else if (!strcmp(_gd->mapJungle->mapDestructible[_indiceDestructible].name, "Paper3")
		&& _gd->mapJungle->mapDestructible[_indiceDestructible].recup == sfFalse)
	{
		sfSound_play(_gd->helpSound.sound);
		_gd->mapJungle->mapDestructible[_indiceDestructible].recup = sfTrue;
		_gd->enigme.decryptage.nbPaperRecup++;
		_gd->enigme.decryptage.paperRecup[2] = sfTrue;
		_gd->enigme.decryptage.InRecup = sfTrue;
		_gd->enigme.decryptage.isVisible[2] = sfTrue;
	}
	else if (!strcmp(_gd->mapJungle->mapDestructible[_indiceDestructible].name, "Paper4")
		&& _gd->mapJungle->mapDestructible[_indiceDestructible].recup == sfFalse)
	{
		sfSound_play(_gd->helpSound.sound);
		_gd->mapJungle->mapDestructible[_indiceDestructible].recup = sfTrue;
		_gd->enigme.decryptage.nbPaperRecup++;
		_gd->enigme.decryptage.paperRecup[3] = sfTrue;
		_gd->enigme.decryptage.InRecup = sfTrue;
		_gd->enigme.decryptage.isVisible[3] = sfTrue;
	}

	if (!strcmp(_gd->mapJungle->mapInteraction[_indice].name, "End"))
	{
		sfSound_stop(_gd->player.stepSound.sound);
		_gd->cutSceneState = JungleEnd;
		_gd->inGameState = cutscene;
		_gd->world = jungle;
		InitCutScene(_gd);
	}
}

void InteractionPlayerShipEnd(GameData* _gd, int _indice)
{
	if (!strcmp(_gd->mapShipEnd->mapInteraction[_indice].name, "End_Game"))
	{
		sfSound_stop(_gd->player.stepSound.sound);
		_gd->cutSceneState = EndCasque;
		_gd->inGameState = cutscene;
		_gd->world = shipEnd;
		InitCutScene(_gd);
	}
}


void InputPlayer(GameData* _gd)
{
	//7 de base
	float speed = 7.f;
	_gd->push = 0;
	int indiceInteraction = 0;

	if (_gd->enigme.dialogue.state == NONE
		&& _gd->inTp == sfFalse)
	{
		if (sfKeyboard_isKeyPressed(sfKeyZ) && !_gd->push)
		{
			_gd->player.pos.y -= speed;
			_gd->player.dir = haut;
			_gd->player.idSeq = hautM;
			_gd->push = 1;
			if (CollisionPlayer(_gd))
			{
				_gd->player.pos.y += speed;
			}
			else if (TriggerPlayerDestructible(_gd))
			{
				_gd->player.pos.y += speed;
			}
		}

		if (sfKeyboard_isKeyPressed(sfKeyS) && !_gd->push)
		{
			_gd->player.pos.y += speed;
			_gd->player.dir = bas;
			_gd->player.idSeq = basM;
			_gd->push = 1;
			if (CollisionPlayer(_gd))
			{
				_gd->player.pos.y -= speed;
			}
			else if (TriggerPlayerDestructible(_gd))
			{
				_gd->player.pos.y -= speed;
			}

		}

		if (sfKeyboard_isKeyPressed(sfKeyQ) && !_gd->push)
		{
			_gd->player.pos.x -= speed;
			_gd->player.dir = gauche;
			_gd->player.idSeq = gaucheM;
			_gd->push = 1;
			if (CollisionPlayer(_gd))
			{
				_gd->player.pos.x += speed;
			}
			else if (TriggerPlayerDestructible(_gd))
			{
				_gd->player.pos.x += speed;
			}
		}

		if (sfKeyboard_isKeyPressed(sfKeyD) && !_gd->push)
		{
			_gd->player.pos.x += speed;
			_gd->player.dir = droite;
			_gd->player.idSeq = droiteM;
			_gd->push = 1;
			if (CollisionPlayer(_gd))
			{
				_gd->player.pos.x -= speed;
			}
			else if (TriggerPlayerDestructible(_gd))
			{
				_gd->player.pos.x -= speed;
			}
		}

		TriggerPlayerSound(_gd);
		if (_gd->push == 1 && _gd->player.stepSound.isPlaying == sfFalse)
		{
			sfSound_play(_gd->player.stepSound.sound);
			_gd->player.stepSound.isPlaying = sfTrue;
		}
		else if (_gd->push == 0 && _gd->player.stepSound.isPlaying == sfTrue)
		{
			sfSound_stop(_gd->player.stepSound.sound);
			_gd->player.stepSound.isPlaying = sfFalse;
		}
		//dialogue
		TriggerIA(_gd);
	}

}

void UpdateIdle(GameData* _gd)
{
	if (_gd->push == 0)
	{
		_gd->player.currentAnim = 0;

		if (_gd->player.dir == haut)
		{
			_gd->player.idSeq = hautI;
		}

		if (_gd->player.dir == bas)
		{
			_gd->player.idSeq = basI;
		}

		if (_gd->player.dir == droite)
		{
			_gd->player.idSeq = droiteI;
		}

		if (_gd->player.dir == gauche)
		{
			_gd->player.idSeq = gaucheI;
		}
	}
}

void UpdateAnimation(GameData* _gd)
{
	_gd->player.currentTime += _gd->frameRate.dt / 10.f;

	float totalTime = _gd->player.persoDef->sequence[_gd->player.idSeq].total;
	int start = _gd->player.persoDef->sequence[_gd->player.idSeq].begin;
	int end = _gd->player.persoDef->sequence[_gd->player.idSeq].end;
	int nbAnim = 1 + (end - start);

	while (_gd->player.currentTime >= totalTime)
	{
		_gd->player.currentTime -= totalTime;
	}
	UpdateIdle(_gd);

	_gd->player.currentAnim = nbAnim * _gd->player.currentTime / totalTime + start;
}

void UpdatePlayer(GameData* _gd)
{
	InputPlayer(_gd);
	UpdateAnimation(_gd);
}