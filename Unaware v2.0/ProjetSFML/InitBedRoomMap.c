#include "InitBedRoomMap.h"

void InitBedRoomMap(GameData* _gd)
{
	_gd->mapBedRoom = calloc(1, sizeof(MapParameter));

	_gd->cam.x = 400;
	_gd->cam.y = 1000;
	_gd->mapBedRoom->nbCalque = 0;
	_gd->mapBedRoom->nbCollision = 0;
	ReadFileTiledLayer(_gd->mapBedRoom, "../Ressources/Map/hubMap.xml");
	ReadFileTiledCollision(_gd->mapBedRoom, "../Ressources/Map/hubMap.xml");
	ReadFileTiledInteraction(_gd->mapBedRoom, "../Ressources/Map/hubMap.xml");
	ReadFileTiledDestructible(_gd->mapBedRoom, "../Ressources/Map/hubMap.xml");
	ReadFileTiledPoint(_gd->mapBedRoom, "../Ressources/Map/hubMap.xml");
	ReadFileTiledPointSound(_gd->mapBedRoom, "../Ressources/Map/hubMap.xml");
	ReadFileTiledTriggerSound(_gd->mapBedRoom, "../Ressources/Map/hubMap.xml");
	ReadFileTiledTriggerIA(_gd->mapBedRoom, "../Ressources/Map/hubMap.xml");
	ReadFileTiledAnim(_gd->mapBedRoom, "../Ressources/Map/spritesheet_vaisseau_hub.xml");
	
	//print pour map
	/*printf("witdh :%d", _gd->mapBedRoom->witdh);
	printf("  height : %d   ", _gd->mapBedRoom->height);
	printf("  columns : %d   ", _gd->mapBedRoom->columns);
	printf("witdh :%d", _gd->mapBedRoom->tilewitdh);
	printf("  height : %d\n", _gd->mapBedRoom->tileheight);
	for (int k = 0; k < _gd->mapBedRoom->nbCalque; k++)
	{
		printf("id :%d\t", _gd->mapBedRoom->id[k]);
		printf("%s\n", _gd->mapBedRoom->mapID[k].name);*/
		/*for (int yMap = 0; yMap < _gd->mapIntro->height; yMap++)
		{
			for (int xMap = 0; xMap < _gd->mapIntro->witdh; xMap++)
			{
				printf("%d, ", _gd->mapIntro->mapID[k].idMap[xMap][yMap]);
			}
			printf("\n");
		}*/

	//}
	//faire spawn le perso au point de spawn de l'intro
	for (int i = 0; i < _gd->mapBedRoom->nbPoint; i++)
	{
		//printf(" name %s\n", _gd->mapBedRoom->mapPoint[i].name);
		if (!strcmp(_gd->mapBedRoom->mapPoint[i].name, "spawn_hub") && _gd->failDream == sfFalse)
		{
			_gd->player.pos.x = _gd->mapBedRoom->mapPoint[i].pos.x;
			_gd->player.pos.y = _gd->mapBedRoom->mapPoint[i].pos.y;
			/*	printf("%d   %d  ", _gd->mapBedRoom.mapPoint[i]->pos.x, _gd->mapBedRoom.mapPoint[i]->pos.y);
				printf("       %f   %f  ", _gd->player.pos.x, _gd->player.pos.y);*/
		}
		else if (!strcmp(_gd->mapBedRoom->mapPoint[i].name, "spawn_fail") && _gd->failDream == sfTrue)
		{
			_gd->player.pos.x = _gd->mapBedRoom->mapPoint[i].pos.x;
			_gd->player.pos.y = _gd->mapBedRoom->mapPoint[i].pos.y;
		}
	}

}

void DestroyBedRoomMap(GameData* _gd)
{
	for (int k = 0; k < _gd->mapBedRoom->nbCalque; k++)
	{
		for (int i = 0; i < _gd->mapBedRoom->witdh; i++)
		{
			free(_gd->mapBedRoom->mapID[k].idMap[i]);
			_gd->mapBedRoom->mapID[k].idMap[i] = NULL;
			free(_gd->mapBedRoom->mapID[k].needRotate[i]);
			_gd->mapBedRoom->mapID[k].needRotate[i] = NULL;
		}
		free(_gd->mapBedRoom->mapID[k].idMap);
		_gd->mapBedRoom->mapID[k].idMap = NULL;
		free(_gd->mapBedRoom->mapID[k].needRotate);
		_gd->mapBedRoom->mapID[k].needRotate = NULL;

	}

	free(_gd->mapBedRoom->mapID);
	_gd->mapBedRoom->mapID = NULL;
	free(_gd->mapBedRoom->id);
	_gd->mapBedRoom->id = NULL;
	free(_gd->mapBedRoom->mapCollision);
	_gd->mapBedRoom->mapCollision = NULL;
	free(_gd->mapBedRoom->mapInteraction);
	_gd->mapBedRoom->mapInteraction = NULL;
	free(_gd->mapBedRoom->mapDestructible);
	_gd->mapBedRoom->mapDestructible = NULL;
	free(_gd->mapBedRoom->mapPoint);
	_gd->mapBedRoom->mapPoint = NULL;
	free(_gd->mapBedRoom->mapNPC);
	_gd->mapBedRoom->mapNPC = NULL;
	free(_gd->mapBedRoom->animTiled.id);
	_gd->mapBedRoom->animTiled.id = NULL;
	free(_gd->mapBedRoom->animTiled.needRotate);
	_gd->mapBedRoom->animTiled.needRotate = NULL;
	free(_gd->mapBedRoom->animTiled.spriteAnim);
	_gd->mapBedRoom->animTiled.spriteAnim = NULL;
	free(_gd->mapBedRoom->proprietySprite);
	_gd->mapBedRoom->proprietySprite = NULL;
	free(_gd->mapBedRoom->mapPointSound);
	_gd->mapBedRoom->mapPointSound = NULL;
	free(_gd->mapBedRoom->mapTriggerSound);
	_gd->mapBedRoom->mapTriggerSound = NULL;
	free(_gd->mapBedRoom->introPointSound.cat);
	_gd->mapBedRoom->introPointSound.cat = NULL;
	free(_gd->mapBedRoom->introPointSound.ventilation);
	_gd->mapBedRoom->introPointSound.ventilation = NULL;

	free(_gd->mapBedRoom);
	_gd->mapBedRoom = NULL;
}