#include "InitIntroMap.h"
#include "Reader.h"


void InitIntroMap(GameData* _gd)
{
	_gd->mapIntro = calloc(1, sizeof(MapParameter));

	_gd->cam.x = 400;
	_gd->cam.y = 1000;
	_gd->mapIntro->nbCalque = 0;
	_gd->mapIntro->nbCollision = 0;
	ReadFileTiledLayer(_gd->mapIntro, "../Ressources/Map/mapShip.xml");
	ReadFileTiledCollision(_gd->mapIntro, "../Ressources/Map/mapShip.xml");
	ReadFileTiledInteraction(_gd->mapIntro, "../Ressources/Map/mapShip.xml");
	ReadFileTiledDestructible(_gd->mapIntro, "../Ressources/Map/mapShip.xml");
	ReadFileTiledPoint(_gd->mapIntro, "../Ressources/Map/mapShip.xml");
	ReadFileTiledPointSound(_gd->mapIntro, "../Ressources/Map/mapShip.xml");
	ReadFileTiledTriggerSound(_gd->mapIntro, "../Ressources/Map/mapShip.xml");
	ReadFileTiledTriggerIA(_gd->mapIntro, "../Ressources/Map/mapShip.xml");
	ReadFileTiledAnim(_gd->mapIntro, "../Ressources/Map/spritesheet_vaisseau.xml");

	//printf("\n\n nb anima %d \n\n", _gd->mapIntro->nbAnimSprite);

	//print fichier xml map
	//{
	//	printf("witdh :%d", _gd->mapIntro->witdh);
	//	printf("  height : %d   ", _gd->mapIntro->height);
	//	printf("  columns : %d   ", _gd->mapIntro->columns);
	//	printf("witdh :%d", _gd->mapIntro->tilewitdh);
	//	printf("  height : %d\n", _gd->mapIntro->tileheight);
	//	for (int k = 0; k < _gd->mapIntro->nbCalque; k++)
	//	{
	//		printf("id :%d\t", _gd->mapIntro->id[k]);
	//		printf("%s\n", _gd->mapIntro->mapID[k].name);
	//		/*for (int yMap = 0; yMap < _gd->mapIntro->height; yMap++)
	//		{
	//			for (int xMap = 0; xMap < _gd->mapIntro->witdh; xMap++)
	//			{
	//				printf("%d, ", _gd->mapIntro->mapID[k].idMap[xMap][yMap]);
	//			}
	//			printf("\n");
	//		}*/

	//	}
	//}

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
	_gd->spriteShip = LoadSprite("../Ressources/Map/spritesheet_vaisseau.png", 0);
	/*_gd->blockColli = LoadSprite("../Ressources/Map/blockColli.png", 0);
	_gd->blockDestruc = LoadSprite("../Ressources/Map/blockDestruc.png", 0);
	_gd->blockInterac = LoadSprite("../Ressources/Map/blockInterac.png", 0);
	_gd->blockPoint = LoadSprite("../Ressources/Map/blockPoint.png", 0);
	_gd->blockSound = LoadSprite("../Ressources/Map/blockSound.png", 0);*/


	//faire spawn le perso au point de spawn de l'intro
	for (int i = 0; i < _gd->mapIntro->nbPoint; i++)
	{
		//printf(" name %s\n", _gd->mapIntro->mapPoint[i].name);
		if (!strcmp(_gd->mapIntro->mapPoint[i].name, "spawn_intro") && _gd->failDream == sfFalse)
		{
			_gd->player.pos.x = _gd->mapIntro->mapPoint[i].pos.x;
			_gd->player.pos.y = _gd->mapIntro->mapPoint[i].pos.y;
		}
		else if (!strcmp(_gd->mapIntro->mapPoint[i].name, "spawn_fail") && _gd->failDream == sfTrue)
		{
			_gd->player.pos.x = _gd->mapIntro->mapPoint[i].pos.x;
			_gd->player.pos.y = _gd->mapIntro->mapPoint[i].pos.y;
		}
	}


}



void DestroyIntroMap(GameData* _gd)
{
	for (int k = 0; k < _gd->mapIntro->nbCalque; k++)
	{
		for (int i = 0; i < _gd->mapIntro->witdh; i++)
		{
			free(_gd->mapIntro->mapID[k].idMap[i]);
			_gd->mapIntro->mapID[k].idMap[i] = NULL;
			free(_gd->mapIntro->mapID[k].needRotate[i]);
			_gd->mapIntro->mapID[k].needRotate[i] = NULL;
		}
		free(_gd->mapIntro->mapID[k].idMap);
		_gd->mapIntro->mapID[k].idMap = NULL;
		free(_gd->mapIntro->mapID[k].needRotate);
		_gd->mapIntro->mapID[k].needRotate = NULL;

	}

	free(_gd->mapIntro->mapID);
	_gd->mapIntro->mapID = NULL;
	free(_gd->mapIntro->id);
	_gd->mapIntro->id = NULL;
	free(_gd->mapIntro->mapCollision);
	_gd->mapIntro->mapCollision = NULL;
	free(_gd->mapIntro->mapInteraction);
	_gd->mapIntro->mapInteraction = NULL;
	free(_gd->mapIntro->mapDestructible);
	_gd->mapIntro->mapDestructible = NULL;
	free(_gd->mapIntro->mapPoint);
	_gd->mapIntro->mapPoint = NULL;
	free(_gd->mapIntro->mapNPC);
	_gd->mapIntro->mapNPC = NULL;
	free(_gd->mapIntro->animTiled.id);
	_gd->mapIntro->animTiled.id = NULL;
	free(_gd->mapIntro->animTiled.needRotate);
	_gd->mapIntro->animTiled.needRotate = NULL;
	free(_gd->mapIntro->animTiled.spriteAnim);
	_gd->mapIntro->animTiled.spriteAnim = NULL;
	free(_gd->mapIntro->proprietySprite);
	_gd->mapIntro->proprietySprite = NULL;
	free(_gd->mapIntro->mapPointSound);
	_gd->mapIntro->mapPointSound = NULL;
	free(_gd->mapIntro->mapTriggerSound);
	_gd->mapIntro->mapTriggerSound = NULL;
	//free de l'ia a faire
	free(_gd->mapIntro->introPointSound.cat);
	_gd->mapIntro->introPointSound.cat = NULL;
	free(_gd->mapIntro->introPointSound.ventilation);
	_gd->mapIntro->introPointSound.ventilation = NULL;
	free(_gd->mapIntro->introPointSound.electricity);
	_gd->mapIntro->introPointSound.electricity = NULL;

	free(_gd->mapIntro);
	_gd->mapIntro = NULL;
}