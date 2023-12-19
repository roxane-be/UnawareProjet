#include "InitJungleMap.h"
#include "Reader.h"

void InitJungleMap(GameData* _gd)
{
	_gd->mapJungle = calloc(1, sizeof(MapParameter));

	_gd->cam.x = 400;
	_gd->cam.y = 1000;
	_gd->mapJungle->nbCalque = 0;
	_gd->mapJungle->nbCollision = 0;
	ReadFileTiledLayer(_gd->mapJungle, "../Ressources/Map/jungleMap.xml");
	//ReadFileTiledLabyrinthe(_gd->mapJungle, "../Ressources/Map/jungleMap.xml"); //spécial son laby
	ReadFileTiledCollision(_gd->mapJungle, "../Ressources/Map/jungleMap.xml");
	ReadFileTiledInteraction(_gd->mapJungle, "../Ressources/Map/jungleMap.xml");
	ReadFileTiledDestructible(_gd->mapJungle, "../Ressources/Map/jungleMap.xml");
	ReadFileTiledPoint(_gd->mapJungle, "../Ressources/Map/jungleMap.xml");
	ReadFileTiledPointSound(_gd->mapJungle, "../Ressources/Map/jungleMap.xml");
	ReadFileTiledTriggerSound(_gd->mapJungle, "../Ressources/Map/jungleMap.xml");
	ReadFileTiledAnim(_gd->mapJungle, "../Ressources/Map/spritesheet_jungle.xml");

	//printf("\n\n nb anima %d \n\n", _gd->mapJungle->nbAnimSprite);

	//print fichier xml map
	{
		/*printf("witdh :%d", _gd->mapJungle->witdh);
		printf("  height : %d   ", _gd->mapJungle->height);
		printf("  columns : %d   ", _gd->mapJungle->columns);
		printf("witdh :%d", _gd->mapJungle->tilewitdh);
		printf("  height : %d\n", _gd->mapJungle->tileheight);
		for (int k = 0; k < _gd->mapJungle->nbCalque; k++)
		{
			printf("id :%d\t", _gd->mapJungle->id[k]);
			printf("%s\n", _gd->mapJungle->mapID[k].name);
		}*/
	}

	/*printf("\n\n\n");
	{
		for (int k = 0; k < gd.mapParameter.nbObjectDecor; k++)
		{
			printf("id :%d\t", gd.mapParameter.prof[k].id);
			printf("name :%s\t", gd.mapParameter.prof[k].name);
			printf("x :%.2f\t", gd.mapParameter.prof[k].pos.x);
			printf("y :%.2f\n", gd.mapParameter.prof[k].pos.y);
		}
	}*/
	/*//print fichier xml sprite sheet 1
	{
		for (int i = 0; i < gd.mapParameter.nbAnimSpriteForet; i++)
		{
			printf("id ANIM : %d\tnbImgage :%d\n", gd.mapParameter.animTiled.id[i], gd.mapParameter.animTiled.spriteAnim[i].nbImageInAnim);
			for (int j = 0; j < gd.mapParameter.animTiled.spriteAnim[i].nbImageInAnim; j++)
			{
				printf("\t\t\t%d->%fsec\n", gd.mapParameter.animTiled.spriteAnim[i].id[j], gd.mapParameter.animTiled.spriteAnim[i].ttl[j]);
				gd.mapParameter.animTiled.spriteAnim[i].ttlMAX += gd.mapParameter.animTiled.spriteAnim[i].ttl[j];
			}
			gd.mapParameter.animTiled.spriteAnim[i].currentAnim = 0;
			printf(" total:%d\n", gd.mapParameter.animTiled.spriteAnim[i].ttlMAX);
			printf("\n");
		}
	}*/

	//_gd->spriteForet = LoadSprite("../Ressources/Map/assets_foret.png", 0);
	_gd->spriteJungle = LoadSprite("../Ressources/Map/spritesheet_jungle.png", 0);
	/*_gd->blockColli = LoadSprite("../Ressources/Map/blockColli.png", 0);
	_gd->blockDestruc = LoadSprite("../Ressources/Map/blockDestruc.png", 0);
	_gd->blockInterac = LoadSprite("../Ressources/Map/blockInterac.png", 0);
	_gd->blockPoint = LoadSprite("../Ressources/Map/blockPoint.png", 0);
	_gd->blockSound = LoadSprite("../Ressources/Map/blockSound.png", 0);*/


	//faire spawn le perso au point de spawn de l'intro
	for (int i = 0; i < _gd->mapJungle->nbPoint; i++)
	{
		//printf(" name %s\n", _gd->mapJungle->mapPoint[i].name);
		if (!strcmp(_gd->mapJungle->mapPoint[i].name, "spawn_jugnle"))
		{
			_gd->player.pos.x = _gd->mapJungle->mapPoint[i].pos.x;
			_gd->player.pos.y = _gd->mapJungle->mapPoint[i].pos.y;
		}
	}

	/*_gd->player.pos.x = 6026;
	_gd->player.pos.y = 5482;*/
}

void DestroyJungleMap(GameData* _gd)
{
	//free des calque map ID, double tableau
	for (int k = 0; k < _gd->mapJungle->nbCalque; k++)
	{
		for (int i = 0; i < _gd->mapJungle->witdh; i++)
		{
			free(_gd->mapJungle->mapID[k].idMap[i]);
			_gd->mapJungle->mapID[k].idMap[i] = NULL;
			free(_gd->mapJungle->mapID[k].needRotate[i]);
			_gd->mapJungle->mapID[k].needRotate[i] = NULL;
		}
		free(_gd->mapJungle->mapID[k].idMap);
		_gd->mapJungle->mapID[k].idMap = NULL;
		free(_gd->mapJungle->mapID[k].needRotate);
		_gd->mapJungle->mapID[k].needRotate = NULL;

	}

	//free de la mapID
	free(_gd->mapJungle->mapID);
	_gd->mapJungle->mapID = NULL;
	free(_gd->mapJungle->id);
	_gd->mapJungle->id = NULL;
	//free de la map de collision
	free(_gd->mapJungle->mapCollision);
	_gd->mapJungle->mapCollision = NULL;
	//free de la map d'interraction
	free(_gd->mapJungle->mapInteraction);
	_gd->mapJungle->mapInteraction = NULL;
	//free de la map de destructible
	free(_gd->mapJungle->mapDestructible);
	_gd->mapJungle->mapDestructible = NULL;
	//free de la map de point
	free(_gd->mapJungle->mapPoint);
	_gd->mapJungle->mapPoint = NULL;
	//free de la map de NPC
	free(_gd->mapJungle->mapNPC);
	_gd->mapJungle->mapNPC = NULL;
	//free des animations de tiled
	free(_gd->mapJungle->animTiled.id);
	_gd->mapJungle->animTiled.id = NULL;
	free(_gd->mapJungle->animTiled.needRotate);
	_gd->mapJungle->animTiled.needRotate = NULL;
	free(_gd->mapJungle->animTiled.spriteAnim);
	_gd->mapJungle->animTiled.spriteAnim = NULL;
	//free des propriété du sprite
	free(_gd->mapJungle->proprietySprite);
	_gd->mapJungle->proprietySprite = NULL;
	//free de la map de point de son
	free(_gd->mapJungle->mapPointSound);
	_gd->mapJungle->mapPointSound = NULL;
	//free de la map de point de trigger son
	free(_gd->mapJungle->mapTriggerSound);
	_gd->mapJungle->mapTriggerSound = NULL;

	//free de la map 
	free(_gd->mapJungle);
	_gd->mapJungle = NULL;

}