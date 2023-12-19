#include "DisplayIntroMap.h"


//void RotationSpriteSheet(MapParameter* _map, int _id, sfBool _rotate,
//	int _xMap, int _yMap, GameData* _gd, sfSprite* _sprite)
//{
//	int puissance = pow(2, 29);
//	int transform;
//
//
//	//pour une transformation de 4(toujours <-1 dans vs)
//	if (_id < -1)
//	{
//		//*-1 pour mettre le id positif
//		transform = (_id / puissance) * -1 + 1;
//		//printf("transfor :%d  ", transform);
//		//formule id= 2^29 %(id %2^29), *-1 pour mettre id positif
//		int tempID = (puissance % ((_id) % puissance));
//		//printf("%d\n",tempID );
//		_rotate = sfTrue;
//		//int tempID = _gd->mapIsland->mapID[k].idMap[xMap][yMap];
//		sfSprite* tempSprite = _sprite;
//		sfVector2f scale;
//		if (transform == 4)
//		{
//			scale.x = -1;
//			scale.y = 1;
//		}
//		if (transform == 3)
//		{
//			scale.x = 1;
//			scale.y = 1;
//		}
//		if (transform == 2)
//		{
//			scale.x = 1;
//			scale.y = 1;
//		}
//		if (transform == 1)
//		{
//			scale.x = -1;
//			scale.y = 1;
//		}
//		sfIntRect rectText;
//		rectText.width = _map->tilewitdh;
//		rectText.height = _map->tileheight;
//		//collum
//		rectText.left = tempID % _map->columns * rectText.width;
//		//ligne
//		rectText.top = tempID / _map->columns * rectText.height;
//		sfSprite_setTextureRect(tempSprite, rectText);
//		if (transform == 4)
//		{
//			BlitSprite(tempSprite, (_xMap * rectText.width) - _gd->cam.x + 64, (_yMap * rectText.height) - _gd->cam.y, 0, scale.x, scale.y, _gd);
//		}
//		if (transform == 3)
//		{
//			BlitSprite(tempSprite, (_xMap * rectText.width) - _gd->cam.x + 64, (_yMap * rectText.height) - _gd->cam.y, 90, scale.x, scale.y, _gd);
//		}
//		if (transform == 2)
//		{
//			BlitSprite(tempSprite, (_xMap * rectText.width) - _gd->cam.x + 64, (_yMap * rectText.height) - _gd->cam.y + 64, 180, scale.x, scale.y, _gd);
//		}
//		if (transform == 1)
//		{
//			BlitSprite(tempSprite, (_xMap * rectText.width) - _gd->cam.x + 64, (_yMap * rectText.height) - _gd->cam.y + 64, 90, scale.x, scale.y, _gd);
//		}
//		_rotate = sfTrue;
//	}
//
//	transform = (_id / puissance);
//	if (transform == 1)
//	{
//		int tempID = (((_id) % puissance));
//		sfSprite* tempSprite = _sprite;
//		sfVector2f scale;
//		scale.x = -1;
//		scale.y = 1;
//		sfIntRect rectText;
//		rectText.width = _map->tilewitdh;
//		rectText.height = _map->tileheight;
//		//collum
//		rectText.left = tempID % _map->columns * rectText.width;
//		//ligne
//		rectText.top = tempID / _map->columns * rectText.height;
//		sfSprite_setTextureRect(tempSprite, rectText);
//		BlitSprite(tempSprite, (_xMap * rectText.width) - _gd->cam.x, (_yMap * rectText.height) - _gd->cam.y, -90, scale.x, scale.y, _gd);
//		_rotate = sfTrue;
//	}
//
//	if (transform == 2)
//	{
//		int tempID = (((_id) % puissance));
//		sfSprite* tempSprite = _sprite;
//		sfVector2f scale;
//		scale.x = 1;
//		scale.y = -1;
//		sfIntRect rectText;
//		rectText.width = _map->tilewitdh;
//		rectText.height = _map->tileheight;
//		//collum
//		rectText.left = tempID % _gd->mapIntro->columns * rectText.width;
//		//ligne
//		rectText.top = tempID / _gd->mapIntro->columns * rectText.height;
//		sfSprite_setTextureRect(tempSprite, rectText);
//		BlitSprite(tempSprite, (_xMap * rectText.width) - _gd->cam.x, (_yMap * rectText.height) - _gd->cam.y + 64, 0, scale.x, scale.y, _gd);
//		_rotate = sfTrue;
//	}
//	if (transform == 3)
//	{
//		int tempID = (((_id) % puissance));
//		sfSprite* tempSprite = _sprite;
//		sfVector2f scale;
//		scale.x = 1;
//		scale.y = 1;
//		sfIntRect rectText;
//		rectText.width = _map->tilewitdh;
//		rectText.height = _map->tileheight;
//		//collum
//		rectText.left = tempID % _map->columns * rectText.width;
//		//ligne
//		rectText.top = tempID / _map->columns * rectText.height;
//		sfSprite_setTextureRect(tempSprite, rectText);
//		BlitSprite(tempSprite, (_xMap * rectText.width) - _gd->cam.x, (_yMap * rectText.height) - _gd->cam.y + 64, -90, scale.x, scale.y, _gd);
//		_rotate = sfTrue;
//	}
//
//
//}



void DisplayIntroMap(GameData* _gd)
{
	int transform = 0;
	int puissance = pow(2, 29);
	sfIntRect rectText;
	rectText.width = _gd->mapIntro->tilewitdh;
	rectText.height = _gd->mapIntro->tileheight;


	sfVector2f camCell = ScreenToWorld(_gd->cam.x, _gd->cam.y);
	sfVector2f camCellMax = { camCell.x + (SCREEN_WIDTH / SIZECELL), camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1 };


	//for (int i = camCell.y - 1; i <= camCell.y + (SCREEN_HEIGHT / SIZECELL); i++)
	//{
	//	for (int j = camCell.x - 1; j <= camCell.x + (SCREEN_WIDTH / SIZECELL); j++)
	//	{
	//		sfVector2f tempPos = WorldToScreen(j, i);
	//		//printf("%f   %f\n", tempPos.x, tempPos.y);
	//		//BlitSprite(_gd->map.sprite, tempPos.x - _gd->map.cam.x, tempPos.y - _gd->map.cam.y, 0, _gd);
	//	}
	//}

	//printf(" %f\n", camCell.y + (SCREEN_HEIGHT / SIZECELL));
	for (int k = 0; k < _gd->mapIntro->nbCalque; k++)
	{
		for (int yMap = camCell.y; yMap <= camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1; yMap++)
		{
			for (int xMap = camCell.x; xMap <= camCell.x + (SCREEN_WIDTH / SIZECELL); xMap++)
			{
				if (IsCellAvailable(yMap, xMap, _gd->mapIntro->height, _gd->mapIntro->witdh));
				{
					//pour les calque normaux 
					{
						int tempID = _gd->mapIntro->mapID[k].idMap[xMap][yMap];
						if (_gd->mapIntro->mapID[k].idMap[xMap][yMap] < -1)
						{
							transform = (_gd->mapIntro->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
							tempID = (puissance % ((_gd->mapIntro->mapID[k].idMap[xMap][yMap]) % puissance));
							_gd->mapIntro->mapID[k].needRotate[xMap][yMap] = sfTrue;
						}
						else if (_gd->mapIntro->mapID[k].idMap[xMap][yMap] > 100000)
						{
							transform = (_gd->mapIntro->mapID[k].idMap[xMap][yMap] / puissance) + 4;
							tempID = (((_gd->mapIntro->mapID[k].idMap[xMap][yMap]) % puissance));
							_gd->mapIntro->mapID[k].needRotate[xMap][yMap] = sfTrue;
						}
						//collum
						rectText.left = tempID % _gd->mapIntro->columns * rectText.height;
						//ligne
						rectText.top = tempID / _gd->mapIntro->columns * rectText.width;
						sfVector2f scale = { 1,1 };
						sfVector2f posTransform = { 0,0 };
						float angle = 0;
						if (_gd->mapIntro->mapID[k].needRotate[xMap][yMap] == sfTrue)
						{
							RotationSpriteSheet(&scale, &posTransform, &angle, transform);
						}
						sfSprite_setTextureRect(_gd->spriteShip, rectText);
						if (UpperUnderPlayer(_gd->mapIntro->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
						{
							BlitSprite(_gd->spriteShip, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
								(yMap * rectText.height) - _gd->cam.y + posTransform.y, angle, scale.x, scale.y, _gd);
						}
					}
					//pour les calques avec des animations dessus 
					for (int i = 0; i < _gd->mapIntro->nbAnimSprite; i++)
					{
						int tempID = -1;
						if (_gd->mapIntro->mapID[k].idMap[xMap][yMap] != _gd->mapIntro->animTiled.id[i])
						{
							if (_gd->mapIntro->mapID[k].idMap[xMap][yMap] < -1)
							{
								transform = (_gd->mapIntro->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
								tempID = (puissance % ((_gd->mapIntro->mapID[k].idMap[xMap][yMap]) % puissance));
							}
							else if (_gd->mapIntro->mapID[k].idMap[xMap][yMap] > -1)
							{
								transform = (_gd->mapIntro->mapID[k].idMap[xMap][yMap] / puissance) + 4;
								tempID = (((_gd->mapIntro->mapID[k].idMap[xMap][yMap]) % puissance));
							}
							_gd->mapIntro->animTiled.needRotate[i] = sfTrue;
						}
						if ((_gd->mapIntro->mapID[k].idMap[xMap][yMap] == _gd->mapIntro->animTiled.id[i]
							|| tempID == _gd->mapIntro->animTiled.id[i])
							&& strstr(_gd->mapIntro->mapID[k].name, "Light") == NULL)
						{
							sfVector2f scale = { 1,1 };
							sfVector2f posTransform = { 0,0 };
							float angle = 0;
							rectText.left = _gd->mapIntro->animTiled.spriteAnim[i].id[_gd->mapIntro->animTiled.spriteAnim[i].currentAnim] % _gd->mapIntro->columns * rectText.width;
							rectText.top = _gd->mapIntro->animTiled.spriteAnim[i].id[_gd->mapIntro->animTiled.spriteAnim[i].currentAnim] / _gd->mapIntro->columns * rectText.height;
							if (tempID == _gd->mapIntro->animTiled.id[i]
								&& _gd->mapIntro->animTiled.needRotate[i] == sfTrue)
							{
								RotationSpriteSheet(&scale, &posTransform, &angle, transform);
							}
							sfSprite_setTextureRect(_gd->spriteShip, rectText);
							if (UpperUnderPlayer(_gd->mapIntro->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
							{
								BlitSprite(_gd->spriteShip, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
									(yMap * rectText.height) - _gd->cam.y + posTransform.y, angle, scale.x, scale.y, _gd);
							}
						}
					}
				}

			}
		}
	}

	//truc pour voir les carré de tiled, calque objet
	{
		//claque collision 
			/*for (int i = 0; i < _gd->mapIntro->nbCollision; i++)
			{
				sfVector2f scale = { _gd->mapIntro->mapCollision[i].size.x / 32,_gd->mapIntro->mapCollision[i].size.y / 32 };

				BlitSprite(_gd->blockColli, _gd->mapIntro->mapCollision[i].pos.x - _gd->cam.x, _gd->mapIntro->mapCollision[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
			}*/
			/*
				for (int i = 0; i < _gd->mapIntro->nbInteraction; i++)
				{
					sfVector2f scale = { _gd->mapIntro->mapInteraction[i].size.x / 32,_gd->mapIntro->mapInteraction[i].size.y / 32 };

					BlitSprite(_gd->blockInterac, _gd->mapIntro->mapInteraction[i].pos.x - _gd->cam.x, _gd->mapIntro->mapInteraction[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd->window);
				}

				for (int i = 0; i < _gd->mapIntro->nbDestructible; i++)
				{
					//if (_gd->mapIntro->mapDestructible[i].active == sfTrue)
					{
						sfVector2f scale = { _gd->mapIntro->mapDestructible[i].size.x / 32,_gd->mapIntro->mapDestructible[i].size.y / 32 };
						BlitSprite(_gd->blockDestruc, _gd->mapIntro->mapDestructible[i].pos.x - _gd->cam.x, _gd->mapIntro->mapDestructible[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd->window);
					}
				}
			*/
			//bloc de son
			//for (int i = 0; i < _gd->mapIntro->nbPointSound; i++)
			//{

			//	BlitSprite(_gd->blockSound, _gd->mapIntro->mapPointSound[i].pos.x - _gd->cam.x, _gd->mapIntro->mapPointSound[i].pos.y - _gd->cam.y, 0, 1, 1, _gd);

			//}
			//for (int i = 0; i < _gd->mapIntro->nbTriggerSound; i++)
			//{
			//	sfVector2f scale = { _gd->mapIntro->mapTriggerSound[i].size.x / 32,_gd->mapIntro->mapTriggerSound[i].size.y / 32 };

			//	BlitSprite(_gd->blockSound, _gd->mapIntro->mapTriggerSound[i].pos.x - _gd->cam.x, _gd->mapIntro->mapTriggerSound[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);

			//}
	}

	//pour placer les sprites à des position spéciale
	for (int i = 0; i < _gd->mapIntro->nbPoint; i++)
	{
		sfVector2f scale = { 1,1 };
		sfVector2f point = ScreenToWorld(_gd->mapIntro->mapPoint[i].pos.x, _gd->mapIntro->mapPoint[i].pos.y);



		//if (_gd->mapIntro->mapPoint[i].active == sfTrue)
		//{
		//	//printf("%fyo %f\n", _gd->mapParameter.mapPoint[i].pos.y, _gd->player.pos.y);
		//	//sfVector2f scale = { _gd->mapParameter.mapPoint[i].size.x / 32,_gd->mapParameter.mapPoint[i].size.y / 32 };
		//	BlitSprite(_gd->blockPoint, _gd->mapIntro->mapPoint[i].pos.x - _gd->cam.x, _gd->mapIntro->mapPoint[i].pos.y - _gd->cam.y, 0, 0.5, 0.5, _gd);
		//}
		int tempJ = 0;
		for (int j = 0; j < _gd->mapIntro->nbProprietySprite; j++)
		{
			rectText.left = _gd->mapIntro->proprietySprite[j].id % _gd->mapIntro->columns * rectText.height;
			rectText.top = _gd->mapIntro->proprietySprite[j].id / _gd->mapIntro->columns * rectText.width;
			sfSprite_setTextureRect(_gd->spriteShip, rectText);
			if (!strcmp(_gd->mapIntro->mapPoint[i].name, "code_bon")
				&& (IsPointIsInCamera(point.x + 5, point.y + 5, camCell, camCellMax)
					|| IsPointIsInCamera(point.x, point.y, camCell, camCellMax)))
			{
				if (_gd->enigme.doorDigicode.resolvedIntro == sfTrue
					&& !strcmp(_gd->mapIntro->proprietySprite[j].name, "green_light"))
				{
					BlitSprite(_gd->spriteShip, _gd->mapIntro->mapPoint[i].pos.x - _gd->cam.x + (j % 2 * 64),
						_gd->mapIntro->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
				}
				else if (_gd->enigme.doorDigicode.resolvedIntro == sfFalse)
				{
					if (!strcmp(_gd->mapIntro->proprietySprite[j].name, "red_light"))
					{
						BlitSprite(_gd->spriteShip, _gd->mapIntro->mapPoint[i].pos.x - _gd->cam.x + (j % 2 * 64),
							_gd->mapIntro->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
					}
					if (!strcmp(_gd->mapIntro->proprietySprite[j].name, "porte_gauche"))
					{
						if (tempJ == 0)
						{
							BlitSprite(_gd->spriteShip, _gd->mapIntro->mapPoint[i].pos.x - _gd->cam.x + ((tempJ) % 2 * 64),
								_gd->mapIntro->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
						}
						else
						{
							tempJ--;
							BlitSprite(_gd->spriteShip, _gd->mapIntro->mapPoint[i].pos.x - _gd->cam.x + ((tempJ) % 2 * 64),
								_gd->mapIntro->mapPoint[i].pos.y - _gd->cam.y + ((tempJ / 2) * 64) + 64, 0, scale.x, scale.y, _gd);
							tempJ++;
						}
						tempJ++;
					}
					if (!strcmp(_gd->mapIntro->proprietySprite[j].name, "porte_droite"))
					{
						BlitSprite(_gd->spriteShip, _gd->mapIntro->mapPoint[i].pos.x - _gd->cam.x + ((j + 1) % 2 * 64),
							_gd->mapIntro->mapPoint[i].pos.y - _gd->cam.y + ((((j - 5) / 4) % 3) * 64), 0, scale.x, scale.y, _gd);
					}
				}
			}
		}
	}
}


void DisplayIntroMapUpper(GameData* _gd)
{
	int transform = 0;
	int puissance = pow(2, 29);
	sfVector2f camCell = ScreenToWorld(_gd->cam.x, _gd->cam.y);
	sfVector2f camCellMax = { camCell.x + (SCREEN_WIDTH / SIZECELL), camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1 };
	sfIntRect rectText;
	rectText.width = _gd->mapIntro->tilewitdh;
	rectText.height = _gd->mapIntro->tileheight;

	for (int k = 0; k < _gd->mapIntro->nbCalque; k++)
	{
		if (strstr(_gd->mapIntro->mapID[k].name, "upper") != NULL)
		{
			for (int yMap = camCell.y; yMap <= camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1; yMap++)
			{
				for (int xMap = camCell.x; xMap <= camCell.x + (SCREEN_WIDTH / SIZECELL); xMap++)
				{
					if (IsCellAvailable(yMap, xMap, _gd->mapIntro->witdh, _gd->mapIntro->height));
					{
						//pour les calque normaux 
						{
							int tempID = _gd->mapIntro->mapID[k].idMap[xMap][yMap];
							if (_gd->mapIntro->mapID[k].idMap[xMap][yMap] < -1)
							{
								transform = (_gd->mapIntro->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
								tempID = (puissance % ((_gd->mapIntro->mapID[k].idMap[xMap][yMap]) % puissance));
								_gd->mapIntro->mapID[k].needRotate[xMap][yMap] = sfTrue;
							}
							else if (_gd->mapIntro->mapID[k].idMap[xMap][yMap] > 100000)
							{
								transform = (_gd->mapIntro->mapID[k].idMap[xMap][yMap] / puissance) + 4;
								tempID = (((_gd->mapIntro->mapID[k].idMap[xMap][yMap]) % puissance));
								_gd->mapIntro->mapID[k].needRotate[xMap][yMap] = sfTrue;
							}
							//collum
							rectText.left = tempID % _gd->mapIntro->columns * rectText.height;
							//ligne
							rectText.top = tempID / _gd->mapIntro->columns * rectText.width;
							sfVector2f scale = { 1,1 };
							sfVector2f posTransform = { 0,0 };
							float angle = 0;
							if (_gd->mapIntro->mapID[k].needRotate[xMap][yMap] == sfTrue)
							{
								RotationSpriteSheet(&scale, &posTransform, &angle, transform);
							}
							sfSprite_setTextureRect(_gd->spriteShip, rectText);
							if (UpperOnPlayer(_gd->mapIntro->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
							{
								BlitSprite(_gd->spriteShip, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
									(yMap * rectText.height) - _gd->cam.y + posTransform.y, angle, scale.x, scale.y, _gd);
							}
						}
						//pour les calques avec des animations dessus 
						for (int i = 0; i < _gd->mapIntro->nbAnimSprite; i++)
						{
							int tempID = -1;
							if (_gd->mapIntro->mapID[k].idMap[xMap][yMap] != _gd->mapIntro->animTiled.id[i])
							{
								if (_gd->mapIntro->mapID[k].idMap[xMap][yMap] < -1)
								{
									transform = (_gd->mapIntro->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
									tempID = (puissance % ((_gd->mapIntro->mapID[k].idMap[xMap][yMap]) % puissance));
								}
								else if (_gd->mapIntro->mapID[k].idMap[xMap][yMap] > -1)
								{
									transform = (_gd->mapIntro->mapID[k].idMap[xMap][yMap] / puissance) + 4;
									tempID = (((_gd->mapIntro->mapID[k].idMap[xMap][yMap]) % puissance));
								}
								_gd->mapIntro->animTiled.needRotate[i] = sfTrue;
							}
							if ((_gd->mapIntro->mapID[k].idMap[xMap][yMap] == _gd->mapIntro->animTiled.id[i]
								|| tempID == _gd->mapIntro->animTiled.id[i])
								&& strstr(_gd->mapIntro->mapID[k].name, "Light") == NULL)
							{
								sfVector2f scale = { 1,1 };
								sfVector2f posTransform = { 0,0 };
								float angle = 0;
								rectText.left = _gd->mapIntro->animTiled.spriteAnim[i].id[_gd->mapIntro->animTiled.spriteAnim[i].currentAnim] % _gd->mapIntro->columns * rectText.width;
								rectText.top = _gd->mapIntro->animTiled.spriteAnim[i].id[_gd->mapIntro->animTiled.spriteAnim[i].currentAnim] / _gd->mapIntro->columns * rectText.height;
								if (tempID == _gd->mapIntro->animTiled.id[i]
									&& _gd->mapIntro->animTiled.needRotate[i] == sfTrue)
								{
									RotationSpriteSheet(&scale, &posTransform, &angle, transform);
								}
								sfSprite_setTextureRect(_gd->spriteShip, rectText);
								if (UpperOnPlayer(_gd->mapIntro->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
								{
									BlitSprite(_gd->spriteShip, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
										(yMap * rectText.height) - _gd->cam.y + posTransform.y, angle, scale.x, scale.y, _gd);
								}
							}
						}
					}
				}
			}
		}
	}


	//truc pour voir les carré de tiled, calque objet
	{
		//claque collision 
	/*for (int i = 0; i < _gd->mapIntro->nbCollision; i++)
	{
		sfVector2f scale = { _gd->mapIntro->mapCollision[i].size.x / 32,_gd->mapIntro->mapCollision[i].size.y / 32 };

		BlitSprite(_gd->blockColli, _gd->mapIntro->mapCollision[i].pos.x - _gd->cam.x, _gd->mapIntro->mapCollision[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd->window);
	}

	for (int i = 0; i < _gd->mapIntro->nbInteraction; i++)
	{
		sfVector2f scale = { _gd->mapIntro->mapInteraction[i].size.x / 32,_gd->mapIntro->mapInteraction[i].size.y / 32 };

		BlitSprite(_gd->blockInterac, _gd->mapIntro->mapInteraction[i].pos.x - _gd->cam.x, _gd->mapIntro->mapInteraction[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd->window);
	}

	for (int i = 0; i < _gd->mapIntro->nbDestructible; i++)
	{
		//if (_gd->mapIntro->mapDestructible[i].active == sfTrue)
		{
			sfVector2f scale = { _gd->mapIntro->mapDestructible[i].size.x / 32,_gd->mapIntro->mapDestructible[i].size.y / 32 };
			BlitSprite(_gd->blockDestruc, _gd->mapIntro->mapDestructible[i].pos.x - _gd->cam.x, _gd->mapIntro->mapDestructible[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd->window);
		}
	}
*/
	}

	//pour placer les sprites à des position spéciale
	for (int i = 0; i < _gd->mapIntro->nbPoint; i++)
	{
		sfVector2f scale = { 1,1 };
		sfVector2f point = ScreenToWorld(_gd->mapIntro->mapPoint[i].pos.x, _gd->mapIntro->mapPoint[i].pos.y);
		//if (_gd->mapIntro->mapPoint[i].active == sfTrue)
		//{
		//	//printf("%fyo %f\n", _gd->mapParameter.mapPoint[i].pos.y, _gd->player.pos.y);
		//	//sfVector2f scale = { _gd->mapParameter.mapPoint[i].size.x / 32,_gd->mapParameter.mapPoint[i].size.y / 32 };
		//	BlitSprite(_gd->blockPoint, _gd->mapIntro->mapPoint[i].pos.x - _gd->cam.x, _gd->mapIntro->mapPoint[i].pos.y - _gd->cam.y, 0, 0.5, 0.5, _gd);
		//}
		int tempJ = 0;
		for (int j = 0; j < _gd->mapIntro->nbProprietySprite; j++)
		{
			rectText.left = _gd->mapIntro->proprietySprite[j].id % _gd->mapIntro->columns * rectText.height;
			rectText.top = _gd->mapIntro->proprietySprite[j].id / _gd->mapIntro->columns * rectText.width;
			sfSprite_setTextureRect(_gd->spriteShip, rectText);
			if (!strcmp(_gd->mapIntro->mapPoint[i].name, "code_bon")
				&& (IsPointIsInCamera(point.x + 5, point.y + 5, camCell, camCellMax)
					|| IsPointIsInCamera(point.x, point.y, camCell, camCellMax)))
			{
				if ((_gd->enigme.doorDigicode.resolvedIntro == sfTrue || _gd->failDream == sfTrue)
					&& !strcmp(_gd->mapIntro->proprietySprite[j].name, "green_light"))
				{
					BlitSprite(_gd->spriteShip, _gd->mapIntro->mapPoint[i].pos.x - _gd->cam.x + (j % 2 * 64),
						_gd->mapIntro->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
				}
			}
		}
	}



	//claque light qui est par dessus de tout
	for (int k = 0; k < _gd->mapIntro->nbCalque; k++)
	{
		if (strstr(_gd->mapIntro->mapID[k].name, "Light") != NULL)
		{
			for (int yMap = camCell.y; yMap <= camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1; yMap++)
			{
				for (int xMap = camCell.x; xMap <= camCell.x + (SCREEN_WIDTH / SIZECELL); xMap++)
				{
					for (int i = 0; i < _gd->mapIntro->nbAnimSprite; i++)
					{
						if (IsCellAvailable(yMap, xMap, _gd->mapIntro->height, _gd->mapIntro->witdh));
						{
							int tempID = -1;
							if (_gd->mapIntro->mapID[k].idMap[xMap][yMap] != _gd->mapIntro->animTiled.id[i])
							{
								if (_gd->mapIntro->mapID[k].idMap[xMap][yMap] < -1)
								{
									transform = (_gd->mapIntro->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
									tempID = (puissance % ((_gd->mapIntro->mapID[k].idMap[xMap][yMap]) % puissance));
								}
								else if (_gd->mapIntro->mapID[k].idMap[xMap][yMap] > -1)
								{
									transform = (_gd->mapIntro->mapID[k].idMap[xMap][yMap] / puissance) + 4;
									tempID = (((_gd->mapIntro->mapID[k].idMap[xMap][yMap]) % puissance));
								}
								_gd->mapIntro->animTiled.needRotate[i] = sfTrue;
							}
							if (_gd->mapIntro->mapID[k].idMap[xMap][yMap] == _gd->mapIntro->animTiled.id[i]
								|| tempID == _gd->mapIntro->animTiled.id[i])
							{
								sfVector2f scale = { 1,1 };
								sfVector2f posTransform = { 0,0 };
								float angle = 0;
								rectText.left = _gd->mapIntro->animTiled.spriteAnim[i].id[_gd->mapIntro->animTiled.spriteAnim[i].currentAnim] % _gd->mapIntro->columns * rectText.width;
								rectText.top = _gd->mapIntro->animTiled.spriteAnim[i].id[_gd->mapIntro->animTiled.spriteAnim[i].currentAnim] / _gd->mapIntro->columns * rectText.height;
								if (tempID == _gd->mapIntro->animTiled.id[i]
									&& _gd->mapIntro->animTiled.needRotate[i] == sfTrue)
								{
									RotationSpriteSheet(&scale, &posTransform, &angle, transform);
								}
								sfSprite_setTextureRect(_gd->spriteShip, rectText);
								//if (UpperUnderPlayerIntro(_gd->mapIntro->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
								{
									BlitSprite(_gd->spriteShip, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
										(yMap * rectText.height) - _gd->cam.y + posTransform.y, angle, scale.x, scale.y, _gd);
								}
							}
						}
					}
				}
			}
		}
	}
}