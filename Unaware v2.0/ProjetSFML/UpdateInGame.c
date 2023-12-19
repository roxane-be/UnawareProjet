#include "UpdateInGame.h"

void UpdateAnimationNPC(GameData* _gd)
{
	//pour les animations idles des pnj
	for (int i = 0; i < _gd->mapIsland->nbNPC; i++)
	{
		_gd->npc[i].currentTime += _gd->frameRate.dt / 10.f;
		float totalTime = _gd->npc[i].npcDef.sequence[_gd->npc[i].idSeq].total;
		int start = _gd->npc[i].npcDef.sequence[_gd->npc[i].idSeq].begin;
		int end = _gd->npc[i].npcDef.sequence[_gd->npc[i].idSeq].end;
		int nbAnim = 1 + (end - start);

		while (_gd->npc[i].currentTime >= totalTime)
		{
			_gd->npc[i].currentTime -= totalTime;
		}
		_gd->npc[i].currentAnim = nbAnim * _gd->npc[i].currentTime / totalTime + start;

	}
}

void UpdateAnimationInterraction(GameData* _gd)
{
	_gd->player.timeInterraction += _gd->frameRate.dt / 10.f;

	if (_gd->player.timeInterraction > 0.05)
	{
		_gd->player.currentAnimInterraction = (_gd->player.currentAnimInterraction + 1) % 2;
		_gd->player.timeInterraction = 0;
		/*if (_gd->player.currentAnimInterraction > 1)
		{
			_gd->player.currentAnimInterraction
		}*/
	}
}

void UpdateSkyIsland(GameData* _gd)
{
	for (int i = 0; i < NB_CLOUD; i++)
	{
		_gd->utilityParallaxe.tabSky[i].pos.x += _gd->utilityParallaxe.tabSky[i].speed;
		if (_gd->utilityParallaxe.tabSky[i].pos.x > 3000)
		{
			_gd->utilityParallaxe.tabSky[i].pos.x = -2000;
		}
	}
	for (int i = 0; i < NB_BIRD; i++)
	{
		_gd->utilityParallaxe.tabBird[i].ttl += _gd->frameRate.dt;
		if (_gd->utilityParallaxe.tabBird[i].display)
		{
			if (_gd->utilityParallaxe.tabBird[i].ttl >= 0.2)
			{
				_gd->utilityParallaxe.tabBird[i].currentAnimBird++;
				_gd->utilityParallaxe.tabBird[i].ttl = 0;
				if (_gd->utilityParallaxe.tabBird[i].currentAnimBird >= NB_ANIM_BIRD)
				{
					_gd->utilityParallaxe.tabBird[i].currentAnimBird = 0;
				}
			}
			_gd->utilityParallaxe.tabBird[i].pos.x += _gd->utilityParallaxe.tabBird[i].speed;
			_gd->utilityParallaxe.tabBird[i].birdTtlMaxOff = rand() % 30;
		}

		if (_gd->utilityParallaxe.tabBird[i].pos.x > 2000
			&& _gd->utilityParallaxe.tabBird[i].display == sfTrue)
		{
			_gd->utilityParallaxe.tabBird[i].display = sfFalse;
		}
		else if (!_gd->utilityParallaxe.tabBird[i].display)
		{
			_gd->utilityParallaxe.tabBird[i].birdTtlOff += _gd->frameRate.dt;
			if (_gd->utilityParallaxe.tabBird[i].birdTtlOff > _gd->utilityParallaxe.tabBird[i].birdTtlMaxOff)
			{
				_gd->utilityParallaxe.tabBird[i].birdTtlOff = 0;
				_gd->utilityParallaxe.tabBird[i].display = sfTrue;
				_gd->utilityParallaxe.tabBird[i].pos.x = -50;
				_gd->utilityParallaxe.tabBird[i].pos.y = 30 + (i * 100) + (i * 315);
				_gd->utilityParallaxe.tabBird[i].currentBird = rand() % NB_TYPE_BIRD;

			}
		}
	}
}

void UpdateCamera(GameData* _gd)
{
	sfVector2f mapSize /*= { _gd->mapIntro->witdh * _gd->mapIntro->tilewitdh,
		_gd->mapIntro->height * _gd->mapIntro->tileheight }*/;

	switch (_gd->world)
	{
	case intro:
		mapSize.x = (_gd->mapIntro->witdh * _gd->mapIntro->tilewitdh) - 1;
		mapSize.y = (_gd->mapIntro->height * _gd->mapIntro->tileheight) - 1;
		break;
	case island:
		mapSize.x = (_gd->mapIsland->witdh * _gd->mapIsland->tilewitdh) - 1;
		mapSize.y = (_gd->mapIsland->height * _gd->mapIsland->tileheight) - 1;
		break;
	case bedroom:
		mapSize.x = (_gd->mapBedRoom->witdh * _gd->mapBedRoom->tilewitdh) - 1;
		mapSize.y = (_gd->mapBedRoom->height * _gd->mapBedRoom->tileheight) - 1;
		break;
	case jungle:
		mapSize.x = (_gd->mapJungle->witdh * _gd->mapJungle->tilewitdh) - 1;
		mapSize.y = (_gd->mapJungle->height * _gd->mapJungle->tileheight) - 1;
		break;
	case shipEnd:
		mapSize.x = (_gd->mapShipEnd->witdh * _gd->mapShipEnd->tilewitdh) - 1;
		mapSize.y = (_gd->mapShipEnd->height * _gd->mapShipEnd->tileheight) - 1;
		break;
	default:
		break;
	}

	_gd->cam.x = _gd->player.pos.x - _gd->sizeWindow.width / 2;
	_gd->cam.y = _gd->player.pos.y - _gd->sizeWindow.height / 2;

	if (_gd->cam.y < 0)
	{
		_gd->cam.y = 0;
	}
	else if (_gd->cam.y + _gd->sizeWindow.height > mapSize.y)
	{
		_gd->cam.y = mapSize.y - _gd->sizeWindow.height;
	}

	if (_gd->cam.x < 0)
	{
		_gd->cam.x = 0;
	}
	else if (_gd->cam.x + _gd->sizeWindow.width > mapSize.x)
	{
		_gd->cam.x = mapSize.x - _gd->sizeWindow.width;
	}
}

void UpdatePointPlayerSoundIntro(GameData* _gd)
{
	float factor;
	float distance;
	float minDistance;

	for (int i = 0; i < _gd->mapIntro->nbPointSound; i++)
	{
		distance = sqrtf((_gd->player.pos.x - _gd->mapIntro->mapPointSound[i].pos.x) *
			(_gd->player.pos.x - _gd->mapIntro->mapPointSound[i].pos.x) +
			(_gd->player.pos.y - _gd->mapIntro->mapPointSound[i].pos.y) *
			(_gd->player.pos.y - _gd->mapIntro->mapPointSound[i].pos.y));
		minDistance = _gd->mapIntro->mapPointSound[i].minDistance;
		if (distance <= minDistance)
		{
			if (!strcmp(_gd->mapIntro->mapPointSound[i].name, "panneau_electrique"))
			{
				sfSound_setPosition(_gd->mapIntro->introPointSound.electricity[i - _gd->mapIntro->nbElec].sound, (sfVector3f) { _gd->mapIntro->mapPointSound[i].pos.x, _gd->mapIntro->mapPointSound[i].pos.y, 0.f });
				factor = 1 - distance / minDistance;
				sfSound_setVolume(_gd->mapIntro->introPointSound.electricity[i - _gd->mapIntro->nbElec].sound, _gd->soundGlobal * factor * _gd->soundAmbiance);
				if (_gd->mapIntro->introPointSound.electricity[i - _gd->mapIntro->nbElec].isPlaying == sfFalse)
				{
					//printf("distance %f - id %d\n", minDistance, i);
					sfSound_play(_gd->mapIntro->introPointSound.electricity[i - _gd->mapIntro->nbElec].sound);
					_gd->mapIntro->introPointSound.electricity[i - _gd->mapIntro->nbElec].isPlaying = sfTrue;
				}
			}
			if (!strcmp(_gd->mapIntro->mapPointSound[i].name, "ventilation"))
			{
				sfSound_setPosition(_gd->mapIntro->introPointSound.ventilation[i - _gd->mapIntro->nbVent].sound, (sfVector3f) { _gd->mapIntro->mapPointSound[i].pos.x, _gd->mapIntro->mapPointSound[i].pos.y, 0.f });
				factor = 1 - distance / minDistance;
				sfSound_setVolume(_gd->mapIntro->introPointSound.ventilation[i - _gd->mapIntro->nbVent].sound, _gd->soundGlobal * factor * _gd->soundAmbiance);
				if (_gd->mapIntro->introPointSound.ventilation[i - _gd->mapIntro->nbVent].isPlaying == sfFalse)
				{
					//printf("distance %f - id %d\n", minDistance, i);
					sfSound_play(_gd->mapIntro->introPointSound.ventilation[i - _gd->mapIntro->nbVent].sound);
					_gd->mapIntro->introPointSound.ventilation[i - _gd->mapIntro->nbVent].isPlaying = sfTrue;
				}
			}
			if (!strcmp(_gd->mapIntro->mapPointSound[i].name, "chat"))
			{
				sfSound_setPosition(_gd->mapIntro->introPointSound.cat[i - _gd->mapIntro->nbCat].sound, (sfVector3f) { _gd->mapIntro->mapPointSound[i].pos.x, _gd->mapIntro->mapPointSound[i].pos.y, 0.f });
				factor = 1 - distance / minDistance;
				sfSound_setVolume(_gd->mapIntro->introPointSound.cat[i - _gd->mapIntro->nbCat].sound, _gd->soundGlobal * factor * _gd->soundAmbiance);
				if (_gd->mapIntro->introPointSound.cat[i - _gd->mapIntro->nbCat].isPlaying == sfFalse)
				{
					//printf("distance %f - id %d\n", minDistance, i);
					sfSound_play(_gd->mapIntro->introPointSound.cat[i - _gd->mapIntro->nbCat].sound);
					_gd->mapIntro->introPointSound.cat[i - _gd->mapIntro->nbCat].isPlaying = sfTrue;
				}
			}
			if (!strcmp(_gd->mapIntro->mapPointSound[i].name, "Console"))
			{
				sfSound_setPosition(_gd->mapIntro->introPointSound.console[i - _gd->mapIntro->nbConsole].sound, (sfVector3f) { _gd->mapIntro->mapPointSound[i].pos.x, _gd->mapIntro->mapPointSound[i].pos.y, 0.f });
				factor = 1 - distance / minDistance;
				sfSound_setVolume(_gd->mapIntro->introPointSound.console[i - _gd->mapIntro->nbConsole].sound, _gd->soundGlobal * factor * _gd->soundAmbiance);
				//printf("distance %f - id %d\n", minDistance, i);
			}
		}
		else
		{
			if (!strcmp(_gd->mapIntro->mapPointSound[i].name, "panneau_electrique"))
			{
				if (_gd->mapIntro->introPointSound.electricity[i - _gd->mapIntro->nbElec].isPlaying == sfTrue)
				{
					sfSound_stop(_gd->mapIntro->introPointSound.electricity[i - _gd->mapIntro->nbElec].sound);
					_gd->mapIntro->introPointSound.electricity[i - _gd->mapIntro->nbElec].isPlaying = sfFalse;
					sfSound_setVolume(_gd->mapIntro->introPointSound.electricity[i - _gd->mapIntro->nbElec].sound, 0);
				}
			}
			if (!strcmp(_gd->mapIntro->mapPointSound[i].name, "ventilation"))
			{
				if (_gd->mapIntro->introPointSound.ventilation[i - _gd->mapIntro->nbVent].isPlaying == sfTrue)
				{
					sfSound_stop(_gd->mapIntro->introPointSound.ventilation[i - _gd->mapIntro->nbVent].sound);
					_gd->mapIntro->introPointSound.ventilation[i - _gd->mapIntro->nbVent].isPlaying = sfFalse;
					sfSound_setVolume(_gd->mapIntro->introPointSound.ventilation[i - _gd->mapIntro->nbVent].sound, 0);
				}
			}
			if (!strcmp(_gd->mapIntro->mapPointSound[i].name, "chat"))
			{
				if (_gd->mapIntro->introPointSound.cat[i - _gd->mapIntro->nbCat].isPlaying == sfTrue)
				{
					sfSound_stop(_gd->mapIntro->introPointSound.cat[i - _gd->mapIntro->nbCat].sound);
					_gd->mapIntro->introPointSound.cat[i - _gd->mapIntro->nbCat].isPlaying = sfFalse;
					sfSound_setVolume(_gd->mapIntro->introPointSound.cat[i - _gd->mapIntro->nbCat].sound, 0);
				}
			}
			if (!strcmp(_gd->mapIntro->mapPointSound[i].name, "Console"))
			{
				sfSound_setVolume(_gd->mapIntro->introPointSound.console[i - _gd->mapIntro->nbConsole].sound, 0);
			}
		}
	}
}

void UpdatePointPlayerSoundIsland(GameData* _gd)
{
	float factor;
	float distance;
	float minDistance;

	for (int i = 0; i < _gd->mapIsland->nbPointSound; i++)
	{
		distance = sqrtf((_gd->player.pos.x - _gd->mapIsland->mapPointSound[i].pos.x) *
			(_gd->player.pos.x - _gd->mapIsland->mapPointSound[i].pos.x) +
			(_gd->player.pos.y - _gd->mapIsland->mapPointSound[i].pos.y) *
			(_gd->player.pos.y - _gd->mapIsland->mapPointSound[i].pos.y));
		minDistance = _gd->mapIsland->mapPointSound[i].minDistance;
		if (distance <= minDistance)
		{
			if (!strcmp(_gd->mapIsland->mapPointSound[i].name, "Lac"))
			{
				sfSound_setPosition(_gd->mapIsland->islandPointSound.lake[i - _gd->mapIsland->nbLake].sound, (sfVector3f) { _gd->mapIsland->mapPointSound[i].pos.x, _gd->mapIsland->mapPointSound[i].pos.y, 0.f });
				factor = 1 - distance / minDistance;
				sfSound_setVolume(_gd->mapIsland->islandPointSound.lake[i - _gd->mapIsland->nbLake].sound, 50 * factor);
				if (_gd->mapIsland->islandPointSound.lake[i - _gd->mapIsland->nbLake].isPlaying == sfFalse)
				{
					//printf("distance %f - id %d\n", minDistance, i);
					sfSound_play(_gd->mapIsland->islandPointSound.lake[i - _gd->mapIsland->nbLake].sound);
					_gd->mapIsland->islandPointSound.lake[i - _gd->mapIsland->nbLake].isPlaying = sfTrue;
				}
			}
			if (!strcmp(_gd->mapIsland->mapPointSound[i].name, "Fish"))
			{
				sfSound_setPosition(_gd->mapIsland->islandPointSound.fish[i - _gd->mapIsland->nbFish].sound, (sfVector3f) { _gd->mapIsland->mapPointSound[i].pos.x, _gd->mapIsland->mapPointSound[i].pos.y, 0.f });
				factor = 1 - distance / minDistance;
				sfSound_setVolume(_gd->mapIsland->islandPointSound.fish[i - _gd->mapIsland->nbFish].sound, _gd->soundGlobal * factor * _gd->soundAmbiance);
				//printf("distance %f - id %d\n", minDistance, i);
			}
			if (!strcmp(_gd->mapIsland->mapPointSound[i].name, "Waterfall"))
			{
				sfSound_setPosition(_gd->mapIsland->islandPointSound.waterfall[i - _gd->mapIsland->nbWaterfall].sound, (sfVector3f) { _gd->mapIsland->mapPointSound[i].pos.x, _gd->mapIsland->mapPointSound[i].pos.y, 0.f });
				factor = 1 - distance / minDistance;
				sfSound_setVolume(_gd->mapIsland->islandPointSound.waterfall[i - _gd->mapIsland->nbWaterfall].sound, _gd->soundGlobal * factor * _gd->soundAmbiance);
				if (_gd->mapIsland->islandPointSound.waterfall[i - _gd->mapIsland->nbWaterfall].isPlaying == sfFalse)
				{
					//printf("distance %f - id %d\n", minDistance, i);
					sfSound_play(_gd->mapIsland->islandPointSound.waterfall[i - _gd->mapIsland->nbWaterfall].sound);
					_gd->mapIsland->islandPointSound.waterfall[i - _gd->mapIsland->nbWaterfall].isPlaying = sfTrue;
				}
			}
			if (!strcmp(_gd->mapIsland->mapPointSound[i].name, "Fire"))
			{
				sfSound_setPosition(_gd->mapIsland->islandPointSound.fire[i - _gd->mapIsland->nbFire].sound, (sfVector3f) { _gd->mapIsland->mapPointSound[i].pos.x, _gd->mapIsland->mapPointSound[i].pos.y, 0.f });
				factor = 1 - distance / minDistance;
				sfSound_setVolume(_gd->mapIsland->islandPointSound.fire[i - _gd->mapIsland->nbFire].sound, _gd->soundGlobal * factor * _gd->soundAmbiance);
				if (_gd->mapIsland->islandPointSound.fire[i - _gd->mapIsland->nbFire].isPlaying == sfFalse)
				{
					//printf("distance %f - id %d\n", minDistance, i);
					sfSound_play(_gd->mapIsland->islandPointSound.fire[i - _gd->mapIsland->nbFire].sound);
					_gd->mapIsland->islandPointSound.fire[i - _gd->mapIsland->nbFire].isPlaying = sfTrue;
				}
			}
			if (!strcmp(_gd->mapIsland->mapPointSound[i].name, "Well"))
			{
				sfSound_setPosition(_gd->mapIsland->islandPointSound.well[i - _gd->mapIsland->nbWell].sound, (sfVector3f) { _gd->mapIsland->mapPointSound[i].pos.x, _gd->mapIsland->mapPointSound[i].pos.y, 0.f });
				factor = 1 - distance / minDistance;
				sfSound_setVolume(_gd->mapIsland->islandPointSound.well[i - _gd->mapIsland->nbWell].sound, _gd->soundGlobal * factor * _gd->soundAmbiance);
				if (_gd->mapIsland->islandPointSound.well[i - _gd->mapIsland->nbWell].isPlaying == sfFalse)
				{
					//printf("distance %f - id %d\n", minDistance, i);
					sfSound_play(_gd->mapIsland->islandPointSound.well[i - _gd->mapIsland->nbWell].sound);
					_gd->mapIsland->islandPointSound.well[i - _gd->mapIsland->nbWell].isPlaying = sfTrue;
				}
			}
		}
		else
		{
			if (!strcmp(_gd->mapIsland->mapPointSound[i].name, "Lac"))
			{
				if (_gd->mapIsland->islandPointSound.lake[i - _gd->mapIsland->nbLake].isPlaying == sfTrue)
				{
					sfSound_stop(_gd->mapIsland->islandPointSound.lake[i - _gd->mapIsland->nbLake].sound);
					_gd->mapIsland->islandPointSound.lake[i - _gd->mapIsland->nbLake].isPlaying = sfFalse;
					sfSound_setVolume(_gd->mapIsland->islandPointSound.lake[i - _gd->mapIsland->nbLake].sound, 0);
				}
			}
			if (!strcmp(_gd->mapIsland->mapPointSound[i].name, "Fish"))
			{
				sfSound_setVolume(_gd->mapIsland->islandPointSound.fish[i - _gd->mapIsland->nbFish].sound, 0);
			}
			if (!strcmp(_gd->mapIsland->mapPointSound[i].name, "Waterfall"))
			{
				if (_gd->mapIsland->islandPointSound.waterfall[i - _gd->mapIsland->nbWaterfall].isPlaying == sfTrue)
				{
					sfSound_stop(_gd->mapIsland->islandPointSound.waterfall[i - _gd->mapIsland->nbWaterfall].sound);
					_gd->mapIsland->islandPointSound.waterfall[i - _gd->mapIsland->nbWaterfall].isPlaying = sfFalse;
					sfSound_setVolume(_gd->mapIsland->islandPointSound.waterfall[i - _gd->mapIsland->nbWaterfall].sound, 0);
				}
			}
			if (!strcmp(_gd->mapIsland->mapPointSound[i].name, "Fire"))
			{
				if (_gd->mapIsland->islandPointSound.fire[i - _gd->mapIsland->nbFire].isPlaying == sfTrue)
				{
					sfSound_stop(_gd->mapIsland->islandPointSound.fire[i - _gd->mapIsland->nbFire].sound);
					_gd->mapIsland->islandPointSound.fire[i - _gd->mapIsland->nbFire].isPlaying = sfFalse;
					sfSound_setVolume(_gd->mapIsland->islandPointSound.fire[i - _gd->mapIsland->nbFire].sound, 0);
				}
			}
			if (!strcmp(_gd->mapIsland->mapPointSound[i].name, "Well"))
			{
				if (_gd->mapIsland->islandPointSound.well[i - _gd->mapIsland->nbWell].isPlaying == sfTrue)
				{
					sfSound_stop(_gd->mapIsland->islandPointSound.well[i - _gd->mapIsland->nbWell].sound);
					_gd->mapIsland->islandPointSound.well[i - _gd->mapIsland->nbWell].isPlaying = sfFalse;
					sfSound_setVolume(_gd->mapIsland->islandPointSound.well[i - _gd->mapIsland->nbWell].sound, 0);
				}
			}
		}
	}
}

void UpdatePointPlayerSoundHub(GameData* _gd)
{
	float factor;
	float distance;
	float minDistance;

	for (int i = 0; i < _gd->mapBedRoom->nbPointSound; i++)
	{
		distance = sqrtf((_gd->player.pos.x - _gd->mapBedRoom->mapPointSound[i].pos.x) *
			(_gd->player.pos.x - _gd->mapBedRoom->mapPointSound[i].pos.x) +
			(_gd->player.pos.y - _gd->mapBedRoom->mapPointSound[i].pos.y) *
			(_gd->player.pos.y - _gd->mapBedRoom->mapPointSound[i].pos.y));
		minDistance = _gd->mapBedRoom->mapPointSound[i].minDistance;
		if (distance <= minDistance)
		{
			if (!strcmp(_gd->mapBedRoom->mapPointSound[i].name, "ventilation"))
			{
				sfSound_setPosition(_gd->mapBedRoom->introPointSound.ventilation[i - _gd->mapBedRoom->nbVent].sound, (sfVector3f) { _gd->mapBedRoom->mapPointSound[i].pos.x, _gd->mapBedRoom->mapPointSound[i].pos.y, 0.f });
				factor = 1 - distance / minDistance;
				sfSound_setVolume(_gd->mapBedRoom->introPointSound.ventilation[i - _gd->mapBedRoom->nbVent].sound, _gd->soundGlobal * factor * _gd->soundAmbiance);
				if (_gd->mapBedRoom->introPointSound.ventilation[i - _gd->mapBedRoom->nbVent].isPlaying == sfFalse)
				{
					//printf("distance %f - id %d\n", minDistance, i);
					sfSound_play(_gd->mapBedRoom->introPointSound.ventilation[i - _gd->mapBedRoom->nbVent].sound);
					_gd->mapBedRoom->introPointSound.ventilation[i - _gd->mapBedRoom->nbVent].isPlaying = sfTrue;
				}
			}
			if (!strcmp(_gd->mapBedRoom->mapPointSound[i].name, "chat"))
			{
				sfSound_setPosition(_gd->mapBedRoom->introPointSound.cat[i - _gd->mapBedRoom->nbCat].sound, (sfVector3f) { _gd->mapBedRoom->mapPointSound[i].pos.x, _gd->mapBedRoom->mapPointSound[i].pos.y, 0.f });
				factor = 1 - distance / minDistance;
				sfSound_setVolume(_gd->mapBedRoom->introPointSound.cat[i - _gd->mapBedRoom->nbCat].sound, _gd->soundGlobal * factor * _gd->soundAmbiance);
				if (_gd->mapBedRoom->introPointSound.cat[i - _gd->mapBedRoom->nbCat].isPlaying == sfFalse)
				{
					//printf("distance %f - id %d\n", minDistance, i);
					sfSound_play(_gd->mapBedRoom->introPointSound.cat[i - _gd->mapBedRoom->nbCat].sound);
					_gd->mapBedRoom->introPointSound.cat[i - _gd->mapBedRoom->nbCat].isPlaying = sfTrue;
				}
			}
		}
		else
		{
			if (!strcmp(_gd->mapBedRoom->mapPointSound[i].name, "ventilation"))
			{
				if (_gd->mapBedRoom->introPointSound.ventilation[i - _gd->mapBedRoom->nbVent].isPlaying == sfTrue)
				{
					sfSound_stop(_gd->mapBedRoom->introPointSound.ventilation[i - _gd->mapBedRoom->nbVent].sound);
					_gd->mapBedRoom->introPointSound.ventilation[i - _gd->mapBedRoom->nbVent].isPlaying = sfFalse;
					sfSound_setVolume(_gd->mapBedRoom->introPointSound.ventilation[i - _gd->mapBedRoom->nbVent].sound, 0);
				}
			}
			if (!strcmp(_gd->mapBedRoom->mapPointSound[i].name, "chat"))
			{
				if (_gd->mapBedRoom->introPointSound.cat[i - _gd->mapBedRoom->nbCat].isPlaying == sfTrue)
				{
					sfSound_stop(_gd->mapBedRoom->introPointSound.cat[i - _gd->mapBedRoom->nbCat].sound);
					_gd->mapBedRoom->introPointSound.cat[i - _gd->mapBedRoom->nbCat].isPlaying = sfFalse;
					sfSound_setVolume(_gd->mapBedRoom->introPointSound.cat[i - _gd->mapBedRoom->nbCat].sound, 0);
				}
			}
		}
	}
}

void UpdatePointPlayerSoundJungle(GameData* _gd)
{
	float factor;
	float distance;
	float minDistance;

	for (int i = 0; i < _gd->mapJungle->nbPointSound; i++)
	{
		distance = sqrtf((_gd->player.pos.x - _gd->mapJungle->mapPointSound[i].pos.x) *
			(_gd->player.pos.x - _gd->mapJungle->mapPointSound[i].pos.x) +
			(_gd->player.pos.y - _gd->mapJungle->mapPointSound[i].pos.y) *
			(_gd->player.pos.y - _gd->mapJungle->mapPointSound[i].pos.y));
		minDistance = _gd->mapJungle->mapPointSound[i].minDistance;
		if (distance <= minDistance)
		{
			if (!strcmp(_gd->mapJungle->mapPointSound[i].name, "Snake"))
			{
				sfSound_setPosition(_gd->mapJungle->junglePointSound.snake[i - _gd->mapJungle->nbSnake].sound, (sfVector3f) { _gd->mapJungle->mapPointSound[i].pos.x, _gd->mapJungle->mapPointSound[i].pos.y, 0.f });
				factor = 1 - distance / minDistance;
				sfSound_setVolume(_gd->mapJungle->junglePointSound.snake[i - _gd->mapJungle->nbSnake].sound, _gd->soundGlobal * factor * _gd->soundAmbiance);
				if (_gd->mapJungle->junglePointSound.snake[i - _gd->mapJungle->nbSnake].isPlaying == sfFalse)
				{
					sfSound_play(_gd->mapJungle->junglePointSound.snake[i - _gd->mapJungle->nbSnake].sound);
					_gd->mapJungle->junglePointSound.snake[i - _gd->mapJungle->nbSnake].isPlaying = sfTrue;
				}
			}
		}
		else
		{
			if (!strcmp(_gd->mapJungle->mapPointSound[i].name, "Snake"))
			{
				if (_gd->mapJungle->junglePointSound.snake[i - _gd->mapJungle->nbSnake].isPlaying == sfTrue)
				{
					sfSound_stop(_gd->mapJungle->junglePointSound.snake[i - _gd->mapJungle->nbSnake].sound);
					_gd->mapJungle->junglePointSound.snake[i - _gd->mapJungle->nbSnake].isPlaying = sfFalse;
					sfSound_setVolume(_gd->mapJungle->junglePointSound.snake[i - _gd->mapJungle->nbSnake].sound, 0);
				}
			}
		}
	}
}

void UpdatePointPlayerSoundShipEnd(GameData* _gd)
{
	float factor;
	float distance;
	float minDistance;

	for (int i = 0; i < _gd->mapShipEnd->nbPointSound; i++)
	{
		distance = sqrtf((_gd->player.pos.x - _gd->mapShipEnd->mapPointSound[i].pos.x) *
			(_gd->player.pos.x - _gd->mapShipEnd->mapPointSound[i].pos.x) +
			(_gd->player.pos.y - _gd->mapShipEnd->mapPointSound[i].pos.y) *
			(_gd->player.pos.y - _gd->mapShipEnd->mapPointSound[i].pos.y));
		minDistance = _gd->mapShipEnd->mapPointSound[i].minDistance;
		if (distance <= minDistance)
		{
			if (!strcmp(_gd->mapShipEnd->mapPointSound[i].name, "panneau_electrique"))
			{
				sfSound_setPosition(_gd->mapShipEnd->introPointSound.electricity[i - _gd->mapShipEnd->nbElec].sound, (sfVector3f) { _gd->mapShipEnd->mapPointSound[i].pos.x, _gd->mapShipEnd->mapPointSound[i].pos.y, 0.f });
				factor = 1 - distance / minDistance;
				sfSound_setVolume(_gd->mapShipEnd->introPointSound.electricity[i - _gd->mapShipEnd->nbElec].sound, _gd->soundGlobal * factor * _gd->soundAmbiance);
				if (_gd->mapShipEnd->introPointSound.electricity[i - _gd->mapShipEnd->nbElec].isPlaying == sfFalse)
				{
					//printf("distance %f - id %d\n", minDistance, i);
					sfSound_play(_gd->mapShipEnd->introPointSound.electricity[i - _gd->mapShipEnd->nbElec].sound);
					_gd->mapShipEnd->introPointSound.electricity[i - _gd->mapShipEnd->nbElec].isPlaying = sfTrue;
				}
			}
			if (!strcmp(_gd->mapShipEnd->mapPointSound[i].name, "ventilation"))
			{
				sfSound_setPosition(_gd->mapShipEnd->introPointSound.ventilation[i - _gd->mapShipEnd->nbVent].sound, (sfVector3f) { _gd->mapShipEnd->mapPointSound[i].pos.x, _gd->mapShipEnd->mapPointSound[i].pos.y, 0.f });
				factor = 1 - distance / minDistance;
				sfSound_setVolume(_gd->mapShipEnd->introPointSound.ventilation[i - _gd->mapShipEnd->nbVent].sound, _gd->soundGlobal * factor * _gd->soundAmbiance);
				if (_gd->mapShipEnd->introPointSound.ventilation[i - _gd->mapShipEnd->nbVent].isPlaying == sfFalse)
				{
					//printf("distance %f - id %d\n", minDistance, i);
					sfSound_play(_gd->mapShipEnd->introPointSound.ventilation[i - _gd->mapShipEnd->nbVent].sound);
					_gd->mapShipEnd->introPointSound.ventilation[i - _gd->mapShipEnd->nbVent].isPlaying = sfTrue;
				}
			}
		}
		else
		{
			if (!strcmp(_gd->mapShipEnd->mapPointSound[i].name, "panneau_electrique"))
			{
				if (_gd->mapShipEnd->introPointSound.electricity[i - _gd->mapShipEnd->nbElec].isPlaying == sfTrue)
				{
					sfSound_stop(_gd->mapShipEnd->introPointSound.electricity[i - _gd->mapShipEnd->nbElec].sound);
					_gd->mapShipEnd->introPointSound.electricity[i - _gd->mapShipEnd->nbElec].isPlaying = sfFalse;
					sfSound_setVolume(_gd->mapShipEnd->introPointSound.electricity[i - _gd->mapShipEnd->nbElec].sound, 0);
				}
			}
			if (!strcmp(_gd->mapShipEnd->mapPointSound[i].name, "ventilation"))
			{
				if (_gd->mapShipEnd->introPointSound.ventilation[i - _gd->mapShipEnd->nbVent].isPlaying == sfTrue)
				{
					sfSound_stop(_gd->mapShipEnd->introPointSound.ventilation[i - _gd->mapShipEnd->nbVent].sound);
					_gd->mapShipEnd->introPointSound.ventilation[i - _gd->mapShipEnd->nbVent].isPlaying = sfFalse;
					sfSound_setVolume(_gd->mapShipEnd->introPointSound.ventilation[i - _gd->mapShipEnd->nbVent].sound, 0);
				}
			}
		}
	}
}