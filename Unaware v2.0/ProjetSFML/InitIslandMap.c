#include "InitIslandMap.h"

void InitIslandMap(GameData* _gd)
{
	_gd->mapIsland = calloc(1, sizeof(MapParameter));

	_gd->cam.x = 400;
	_gd->cam.y = 1000;
	_gd->mapIsland->nbCalque = 0;
	_gd->mapIsland->nbCollision = 0;

	ReadFileTiledLayer(_gd->mapIsland, "../Ressources/Map/islandMap.xml");
	ReadFileTiledCollision(_gd->mapIsland, "../Ressources/Map/islandMap.xml");
	ReadFileTiledDestructible(_gd->mapIsland, "../Ressources/Map/islandMap.xml");
	ReadFileTiledInteraction(_gd->mapIsland, "../Ressources/Map/islandMap.xml");
	ReadFileTiledPoint(_gd->mapIsland, "../Ressources/Map/islandMap.xml");
	ReadFileTiledAnim(_gd->mapIsland, "../Ressources/Map/spritesheet_reve1.xml");
	ReadFileTiledNPC(_gd->mapIsland, "../Ressources/Map/islandMap.xml");
	ReadFileTiledPointSound(_gd->mapIsland, "../Ressources/Map/islandMap.xml");
	ReadFileTiledTriggerSound(_gd->mapIsland, "../Ressources/Map/islandMap.xml");

	//print fichier xml map
	/*{
		printf("witdh :%d", _gd->mapIsland->witdh);
		printf("  height : %d   ", _gd->mapIsland->height);
		printf("  columns : %d   ", _gd->mapIsland->columns);
		printf("witdh :%d", _gd->mapIsland->tilewitdh);
		printf("  height : %d\n", _gd->mapIsland->tileheight);

		for (int k = 0; k < _gd->mapIsland->nbCalque; k++)
		{
			printf("id :%d\t", _gd->mapIsland->id[k]);
			printf("%s\n", _gd->mapIsland->mapID[k].name);


		}
	}*/

	_gd->spriteIsland = LoadSprite("../Ressources/Map/spritesheet_reve1.png", 0);
	/*_gd->blockColli = LoadSprite("../Ressources/Map/blockColli.png", 0);
	_gd->blockDestruc = LoadSprite("../Ressources/Map/blockDestruc.png", 0);
	_gd->blockInterac = LoadSprite("../Ressources/Map/blockInterac.png", 0);
	_gd->blockPoint = LoadSprite("../Ressources/Map/blockPoint.png", 0);*/


	//faire spawn le perso au point de spawn de l'intro
	for (int i = 0; i < _gd->mapIsland->nbPoint; i++)
	{

		if (!strcmp(_gd->mapIsland->mapPoint[i].name, "spawn_house_wake_up"))
		{
			_gd->player.pos.x = _gd->mapIsland->mapPoint[i].pos.x;
			_gd->player.pos.y = _gd->mapIsland->mapPoint[i].pos.y;
		}

	}
	//printf("pnj : %d\n", _gd->mapIsland->nbNPC);

	for (int i = 0; i < _gd->mapIsland->nbNPC; i++)
	{
		char chemin[100];
		sprintf(chemin, "../Ressources/Assets/Player/cadre_pnj/pnj_dialogue_%d.png", i);
		_gd->npc[i].pos.x = _gd->mapIsland->mapNPC[i].pos.x;
		_gd->npc[i].pos.y = _gd->mapIsland->mapNPC[i].pos.y;
		_gd->npc[i].currentAnim = 0;
		_gd->npc[i].currentTime = 0.f;
		_gd->npc[i].dir = bas;
		_gd->npc[i].idSeq = basI;
		_gd->npc[i].dialogueBox = LoadSprite("../Ressources/Assets/Dialogue/boite_dialogue1.png", 0);
		_gd->npc[i].pnjBox = LoadSprite(chemin, 0);


		InitAnimPNJ(_gd, i);
	}
}

void DestroyIslandMap(GameData* _gd)
{
	//free des calque map ID, double tableau
	for (int k = 0; k < _gd->mapIsland->nbCalque; k++)
	{
		for (int i = 0; i < _gd->mapIsland->witdh; i++)
		{
			free(_gd->mapIsland->mapID[k].idMap[i]);
			_gd->mapIsland->mapID[k].idMap[i] = NULL;
			free(_gd->mapIsland->mapID[k].needRotate[i]);
			_gd->mapIsland->mapID[k].needRotate[i] = NULL;
		}
		free(_gd->mapIsland->mapID[k].idMap);
		_gd->mapIsland->mapID[k].idMap = NULL;
		free(_gd->mapIsland->mapID[k].needRotate);
		_gd->mapIsland->mapID[k].needRotate = NULL;

	}

	//free de la mapID
	free(_gd->mapIsland->mapID);
	_gd->mapIsland->mapID = NULL;
	free(_gd->mapIsland->id);
	_gd->mapIsland->id = NULL;
	//free de la map de collision
	free(_gd->mapIsland->mapCollision);
	_gd->mapIsland->mapCollision = NULL;
	//free de la map d'interraction
	free(_gd->mapIsland->mapInteraction);
	_gd->mapIsland->mapInteraction = NULL;
	//free de la map de destructible
	free(_gd->mapIsland->mapDestructible);
	_gd->mapIsland->mapDestructible = NULL;
	//free de la map de point
	free(_gd->mapIsland->mapPoint);
	_gd->mapIsland->mapPoint = NULL;
	//free de la map de NPC
	free(_gd->mapIsland->mapNPC);
	_gd->mapIsland->mapNPC = NULL;
	//free des animations de tiled
	free(_gd->mapIsland->animTiled.id);
	_gd->mapIsland->animTiled.id = NULL;
	free(_gd->mapIsland->animTiled.needRotate);
	_gd->mapIsland->animTiled.needRotate = NULL;
	free(_gd->mapIsland->animTiled.spriteAnim);
	_gd->mapIsland->animTiled.spriteAnim = NULL;
	//free des propriété du sprite
	free(_gd->mapIsland->proprietySprite);
	_gd->mapIsland->proprietySprite = NULL;
	//free de la map de point de son
	free(_gd->mapIsland->mapPointSound);
	_gd->mapIsland->mapPointSound = NULL;
	//free de la map de point de trigger son
	free(_gd->mapIsland->mapTriggerSound);
	_gd->mapIsland->mapTriggerSound = NULL;

	//free de la map 
	free(_gd->mapIsland);
	_gd->mapIsland = NULL;


}