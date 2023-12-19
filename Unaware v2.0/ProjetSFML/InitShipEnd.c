#include "InitShipEndMap.h"

void InitShipEndMap(GameData* _gd)
{
	_gd->mapShipEnd = calloc(1, sizeof(MapParameter));

	_gd->cam.x = 400;
	_gd->cam.y = 1000;
	_gd->mapShipEnd->nbCalque = 0;
	_gd->mapShipEnd->nbCollision = 0;
	ReadFileTiledLayer(_gd->mapShipEnd, "../Ressources/Map/mapShipEnd.xml");
	//	ReadFileTiledLabyrinthe(_gd->mapShipEnd, "../Ressources/Map/jungleMap.xml"); //spécial son laby
	ReadFileTiledCollision(_gd->mapShipEnd, "../Ressources/Map/mapShipEnd.xml");
	ReadFileTiledInteraction(_gd->mapShipEnd, "../Ressources/Map/mapShipEnd.xml");
	//ReadFileTiledDestructible(_gd->mapShipEnd, "../Ressources/Map/jungleMap.xml");
	ReadFileTiledPoint(_gd->mapShipEnd, "../Ressources/Map/mapShipEnd.xml");
	ReadFileTiledPointSound(_gd->mapShipEnd, "../Ressources/Map/mapShipEnd.xml");
	ReadFileTiledTriggerSound(_gd->mapShipEnd, "../Ressources/Map/mapShipEnd.xml");
	ReadFileTiledTriggerIA(_gd->mapShipEnd, "../Ressources/Map/mapShipEnd.xml");
	ReadFileTiledAnim(_gd->mapShipEnd, "../Ressources/Map/spritesheet_vaisseau.xml");

	//printf("\n\n nb anima %d \n\n", _gd->mapShipEnd->nbAnimSprite);

	////print fichier xml map
	//{
	//	printf("witdh :%d", _gd->mapShipEnd->witdh);
	//	printf("  height : %d   ", _gd->mapShipEnd->height);
	//	printf("  columns : %d   ", _gd->mapShipEnd->columns);
	//	printf("witdh :%d", _gd->mapShipEnd->tilewitdh);
	//	printf("  height : %d\n", _gd->mapShipEnd->tileheight);
	//	for (int k = 0; k < _gd->mapShipEnd->nbCalque; k++)
	//	{
	//		printf("id :%d\t", _gd->mapShipEnd->id[k]);
	//		printf("%s\n", _gd->mapShipEnd->mapID[k].name);
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
	//_gd->spriteJungle = LoadSprite("../Ressources/Map/spritesheet_jungle.png", 0);
	/*_gd->blockColli = LoadSprite("../Ressources/Map/blockColli.png", 0);
	_gd->blockDestruc = LoadSprite("../Ressources/Map/blockDestruc.png", 0);
	_gd->blockInterac = LoadSprite("../Ressources/Map/blockInterac.png", 0);
	_gd->blockPoint = LoadSprite("../Ressources/Map/blockPoint.png", 0);
	_gd->blockSound = LoadSprite("../Ressources/Map/blockSound.png", 0);*/


	//faire spawn le perso au point de spawn de l'intro
	for (int i = 0; i < _gd->mapShipEnd->nbPoint; i++)
	{
		//printf(" name %s\n", _gd->mapShipEnd->mapPoint[i].name);
		if (!strcmp(_gd->mapShipEnd->mapPoint[i].name, "spawn_end"))
		{
			_gd->player.pos.x = _gd->mapShipEnd->mapPoint[i].pos.x;
			_gd->player.pos.y = _gd->mapShipEnd->mapPoint[i].pos.y;
		}
	}
}