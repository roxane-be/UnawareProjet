#include "DisplayBedRoomMap.h"

void DisplayBedRoomMap(GameData* _gd)
{
	int transform = 0;
	int puissance = pow(2, 29);
	sfIntRect rectText;
	rectText.width = _gd->mapBedRoom->tilewitdh;
	rectText.height = _gd->mapBedRoom->tileheight;


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
	for (int k = 0; k < _gd->mapBedRoom->nbCalque; k++)
	{
		for (int yMap = camCell.y; yMap <= camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1; yMap++)
		{
			for (int xMap = camCell.x; xMap <= camCell.x + (SCREEN_WIDTH / SIZECELL); xMap++)
			{
				if (IsCellAvailable(yMap, xMap, _gd->mapBedRoom->height, _gd->mapBedRoom->witdh));
				{
					//pour les calque normaux 
					{
						int tempID = _gd->mapBedRoom->mapID[k].idMap[xMap][yMap];
						if (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] < -1)
						{
							transform = (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
							tempID = (puissance % ((_gd->mapBedRoom->mapID[k].idMap[xMap][yMap]) % puissance));
							_gd->mapBedRoom->mapID[k].needRotate[xMap][yMap] = sfTrue;
						}
						else if (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] > 100000)
						{
							transform = (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] / puissance) + 4;
							tempID = (((_gd->mapBedRoom->mapID[k].idMap[xMap][yMap]) % puissance));
							_gd->mapBedRoom->mapID[k].needRotate[xMap][yMap] = sfTrue;
						}
						//collum
						rectText.left = tempID % _gd->mapBedRoom->columns * rectText.height;
						//ligne
						rectText.top = tempID / _gd->mapBedRoom->columns * rectText.width;
						sfVector2f scale = { 1,1 };
						sfVector2f posTransform = { 0,0 };
						float angle = 0;
						if (_gd->mapBedRoom->mapID[k].needRotate[xMap][yMap] == sfTrue)
						{
							RotationSpriteSheet(&scale, &posTransform, &angle, transform);
						}
						sfSprite_setTextureRect(_gd->spriteShip, rectText);
						if (UpperUnderPlayer(_gd->mapBedRoom->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
						{
							BlitSprite(_gd->spriteShip, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
								(yMap * rectText.height) - _gd->cam.y + posTransform.y, angle, scale.x, scale.y, _gd);
						}
					}
					//pour les calques avec des animations dessus 
					for (int i = 0; i < _gd->mapBedRoom->nbAnimSprite; i++)
					{
						int tempID = -1;
						if (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] != _gd->mapBedRoom->animTiled.id[i])
						{
							if (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] < -1)
							{
								transform = (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
								tempID = (puissance % ((_gd->mapBedRoom->mapID[k].idMap[xMap][yMap]) % puissance));
							}
							else if (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] > -1)
							{
								transform = (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] / puissance) + 4;
								tempID = (((_gd->mapBedRoom->mapID[k].idMap[xMap][yMap]) % puissance));
							}
							_gd->mapBedRoom->animTiled.needRotate[i] = sfTrue;
						}
						if ((_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] == _gd->mapBedRoom->animTiled.id[i]
							|| tempID == _gd->mapBedRoom->animTiled.id[i])
							&& strstr(_gd->mapBedRoom->mapID[k].name, "Light") == NULL)
						{
							sfVector2f scale = { 1,1 };
							sfVector2f posTransform = { 0,0 };
							float angle = 0;
							rectText.left = _gd->mapBedRoom->animTiled.spriteAnim[i].id[_gd->mapBedRoom->animTiled.spriteAnim[i].currentAnim] % _gd->mapBedRoom->columns * rectText.width;
							rectText.top = _gd->mapBedRoom->animTiled.spriteAnim[i].id[_gd->mapBedRoom->animTiled.spriteAnim[i].currentAnim] / _gd->mapBedRoom->columns * rectText.height;
							if (tempID == _gd->mapBedRoom->animTiled.id[i]
								&& _gd->mapBedRoom->animTiled.needRotate[i] == sfTrue)
							{
								RotationSpriteSheet(&scale, &posTransform, &angle, transform);
							}
							sfSprite_setTextureRect(_gd->spriteShip, rectText);
							if (UpperUnderPlayer(_gd->mapBedRoom->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
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
			/*for (int i = 0; i < _gd->mapBedRoom->nbCollision; i++)
			{
				sfVector2f scale = { _gd->mapBedRoom->mapCollision[i].size.x / 32,_gd->mapBedRoom->mapCollision[i].size.y / 32 };

				BlitSprite(_gd->blockColli, _gd->mapBedRoom->mapCollision[i].pos.x - _gd->cam.x, _gd->mapBedRoom->mapCollision[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
			}*/
			/*
				for (int i = 0; i < _gd->mapBedRoom->nbInteraction; i++)
				{
					sfVector2f scale = { _gd->mapBedRoom->mapInteraction[i].size.x / 32,_gd->mapBedRoom->mapInteraction[i].size.y / 32 };

					BlitSprite(_gd->blockInterac, _gd->mapBedRoom->mapInteraction[i].pos.x - _gd->cam.x, _gd->mapBedRoom->mapInteraction[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd->window);
				}

				for (int i = 0; i < _gd->mapBedRoom->nbDestructible; i++)
				{
					//if (_gd->mapBedRoom->mapDestructible[i].active == sfTrue)
					{
						sfVector2f scale = { _gd->mapBedRoom->mapDestructible[i].size.x / 32,_gd->mapBedRoom->mapDestructible[i].size.y / 32 };
						BlitSprite(_gd->blockDestruc, _gd->mapBedRoom->mapDestructible[i].pos.x - _gd->cam.x, _gd->mapBedRoom->mapDestructible[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd->window);
					}
				}
			*/
			//bloc de son
			//for (int i = 0; i < _gd->mapBedRoom->nbPointSound; i++)
			//{

			//	BlitSprite(_gd->blockSound, _gd->mapBedRoom->mapPointSound[i].pos.x - _gd->cam.x, _gd->mapBedRoom->mapPointSound[i].pos.y - _gd->cam.y, 0, 1, 1, _gd);

			//}
			//for (int i = 0; i < _gd->mapBedRoom->nbTriggerSound; i++)
			//{
			//	sfVector2f scale = { _gd->mapBedRoom->mapTriggerSound[i].size.x / 32,_gd->mapBedRoom->mapTriggerSound[i].size.y / 32 };

			//	BlitSprite(_gd->blockSound, _gd->mapBedRoom->mapTriggerSound[i].pos.x - _gd->cam.x, _gd->mapBedRoom->mapTriggerSound[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);

			//}
	}

	//pour placer les sprites à des position spéciale
	for (int i = 0; i < _gd->mapBedRoom->nbPoint; i++)
	{
		sfVector2f scale = { 1,1 };
		sfVector2f point = ScreenToWorld(_gd->mapBedRoom->mapPoint[i].pos.x, _gd->mapBedRoom->mapPoint[i].pos.y);



		//if (_gd->mapBedRoom->mapPoint[i].active == sfTrue)
		//{
		//	//printf("%fyo %f\n", _gd->mapParameter.mapPoint[i].pos.y, _gd->player.pos.y);
		//	//sfVector2f scale = { _gd->mapParameter.mapPoint[i].size.x / 32,_gd->mapParameter.mapPoint[i].size.y / 32 };
		//	BlitSprite(_gd->blockPoint, _gd->mapBedRoom->mapPoint[i].pos.x - _gd->cam.x, _gd->mapBedRoom->mapPoint[i].pos.y - _gd->cam.y, 0, 0.5, 0.5, _gd);
		//}
		int tempJ = 0;
		/*for (int j = 0; j < _gd->mapBedRoom->nbProprietySprite; j++)
		{
			rectText.left = _gd->mapBedRoom->proprietySprite[j].id % _gd->mapBedRoom->columns * rectText.height;
			rectText.top = _gd->mapBedRoom->proprietySprite[j].id / _gd->mapBedRoom->columns * rectText.width;
			sfSprite_setTextureRect(_gd->spriteShip, rectText);
			if (!strcmp(_gd->mapBedRoom->mapPoint[i].name, "code_bon")
				&& (IsPointIsInCamera(point.x + 5, point.y + 5, camCell, camCellMax)
					|| IsPointIsInCamera(point.x, point.y, camCell, camCellMax)))
			{
				if (_gd->enigme.doorDigicode.resolvedIntro == sfTrue
					&& !strcmp(_gd->mapBedRoom->proprietySprite[j].name, "green_light"))
				{
					BlitSprite(_gd->spriteShip, _gd->mapBedRoom->mapPoint[i].pos.x - _gd->cam.x + (j % 2 * 64),
						_gd->mapBedRoom->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
				}
				else if (_gd->enigme.doorDigicode.resolvedIntro == sfFalse)
				{
					if (!strcmp(_gd->mapBedRoom->proprietySprite[j].name, "red_light"))
					{
						BlitSprite(_gd->spriteShip, _gd->mapBedRoom->mapPoint[i].pos.x - _gd->cam.x + (j % 2 * 64),
							_gd->mapBedRoom->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
					}
					if (!strcmp(_gd->mapBedRoom->proprietySprite[j].name, "porte_gauche"))
					{
						if (tempJ == 0)
						{
							BlitSprite(_gd->spriteShip, _gd->mapBedRoom->mapPoint[i].pos.x - _gd->cam.x + ((tempJ) % 2 * 64),
								_gd->mapBedRoom->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
						}
						else
						{
							tempJ--;
							BlitSprite(_gd->spriteShip, _gd->mapBedRoom->mapPoint[i].pos.x - _gd->cam.x + ((tempJ) % 2 * 64),
								_gd->mapBedRoom->mapPoint[i].pos.y - _gd->cam.y + ((tempJ / 2) * 64) + 64, 0, scale.x, scale.y, _gd);
							tempJ++;
						}
						tempJ++;
					}
					if (!strcmp(_gd->mapBedRoom->proprietySprite[j].name, "porte_droite"))
					{
						BlitSprite(_gd->spriteShip, _gd->mapBedRoom->mapPoint[i].pos.x - _gd->cam.x + ((j + 1) % 2 * 64),
							_gd->mapBedRoom->mapPoint[i].pos.y - _gd->cam.y + ((((j - 5) / 4) % 3) * 64), 0, scale.x, scale.y, _gd);
					}
				}
			}
		}*/
	}
}


void DisplayBedRoomMapUpper(GameData* _gd)
{
	int transform = 0;
	int puissance = pow(2, 29);
	sfVector2f camCell = ScreenToWorld(_gd->cam.x, _gd->cam.y);
	sfVector2f camCellMax = { camCell.x + (SCREEN_WIDTH / SIZECELL), camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1 };
	sfIntRect rectText;
	rectText.width = _gd->mapBedRoom->tilewitdh;
	rectText.height = _gd->mapBedRoom->tileheight;

	for (int k = 0; k < _gd->mapBedRoom->nbCalque; k++)
	{
		if (strstr(_gd->mapBedRoom->mapID[k].name, "upper") != NULL)
		{
			for (int yMap = camCell.y; yMap <= camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1; yMap++)
			{
				for (int xMap = camCell.x; xMap <= camCell.x + (SCREEN_WIDTH / SIZECELL); xMap++)
				{
					if (IsCellAvailable(yMap, xMap, _gd->mapBedRoom->witdh, _gd->mapBedRoom->height));
					{
						//pour les calque normaux 
						{
							int tempID = _gd->mapBedRoom->mapID[k].idMap[xMap][yMap];
							if (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] < -1)
							{
								transform = (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
								tempID = (puissance % ((_gd->mapBedRoom->mapID[k].idMap[xMap][yMap]) % puissance));
								_gd->mapBedRoom->mapID[k].needRotate[xMap][yMap] = sfTrue;
							}
							else if (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] > 100000)
							{
								transform = (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] / puissance) + 4;
								tempID = (((_gd->mapBedRoom->mapID[k].idMap[xMap][yMap]) % puissance));
								_gd->mapBedRoom->mapID[k].needRotate[xMap][yMap] = sfTrue;
							}
							//collum
							rectText.left = tempID % _gd->mapBedRoom->columns * rectText.height;
							//ligne
							rectText.top = tempID / _gd->mapBedRoom->columns * rectText.width;
							sfVector2f scale = { 1,1 };
							sfVector2f posTransform = { 0,0 };
							float angle = 0;
							if (_gd->mapBedRoom->mapID[k].needRotate[xMap][yMap] == sfTrue)
							{
								RotationSpriteSheet(&scale, &posTransform, &angle, transform);
							}
							sfSprite_setTextureRect(_gd->spriteShip, rectText);
							if (UpperOnPlayer(_gd->mapBedRoom->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
							{
								BlitSprite(_gd->spriteShip, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
									(yMap * rectText.height) - _gd->cam.y + posTransform.y, angle, scale.x, scale.y, _gd);
							}
						}
						//pour les calques avec des animations dessus 
						for (int i = 0; i < _gd->mapBedRoom->nbAnimSprite; i++)
						{
							int tempID = -1;
							if (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] != _gd->mapBedRoom->animTiled.id[i])
							{
								if (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] < -1)
								{
									transform = (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
									tempID = (puissance % ((_gd->mapBedRoom->mapID[k].idMap[xMap][yMap]) % puissance));
								}
								else if (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] > -1)
								{
									transform = (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] / puissance) + 4;
									tempID = (((_gd->mapBedRoom->mapID[k].idMap[xMap][yMap]) % puissance));
								}
								_gd->mapBedRoom->animTiled.needRotate[i] = sfTrue;
							}
							if ((_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] == _gd->mapBedRoom->animTiled.id[i]
								|| tempID == _gd->mapBedRoom->animTiled.id[i])
								&& strstr(_gd->mapBedRoom->mapID[k].name, "Light") == NULL)
							{
								sfVector2f scale = { 1,1 };
								sfVector2f posTransform = { 0,0 };
								float angle = 0;
								rectText.left = _gd->mapBedRoom->animTiled.spriteAnim[i].id[_gd->mapBedRoom->animTiled.spriteAnim[i].currentAnim] % _gd->mapBedRoom->columns * rectText.width;
								rectText.top = _gd->mapBedRoom->animTiled.spriteAnim[i].id[_gd->mapBedRoom->animTiled.spriteAnim[i].currentAnim] / _gd->mapBedRoom->columns * rectText.height;
								if (tempID == _gd->mapBedRoom->animTiled.id[i]
									&& _gd->mapBedRoom->animTiled.needRotate[i] == sfTrue)
								{
									RotationSpriteSheet(&scale, &posTransform, &angle, transform);
								}
								sfSprite_setTextureRect(_gd->spriteShip, rectText);
								if (UpperOnPlayer(_gd->mapBedRoom->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
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
	/*for (int i = 0; i < _gd->mapBedRoom->nbCollision; i++)
	{
		sfVector2f scale = { _gd->mapBedRoom->mapCollision[i].size.x / 32,_gd->mapBedRoom->mapCollision[i].size.y / 32 };

		BlitSprite(_gd->blockColli, _gd->mapBedRoom->mapCollision[i].pos.x - _gd->cam.x, _gd->mapBedRoom->mapCollision[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd->window);
	}

	for (int i = 0; i < _gd->mapBedRoom->nbInteraction; i++)
	{
		sfVector2f scale = { _gd->mapBedRoom->mapInteraction[i].size.x / 32,_gd->mapBedRoom->mapInteraction[i].size.y / 32 };

		BlitSprite(_gd->blockInterac, _gd->mapBedRoom->mapInteraction[i].pos.x - _gd->cam.x, _gd->mapBedRoom->mapInteraction[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd->window);
	}

	for (int i = 0; i < _gd->mapBedRoom->nbDestructible; i++)
	{
		//if (_gd->mapBedRoom->mapDestructible[i].active == sfTrue)
		{
			sfVector2f scale = { _gd->mapBedRoom->mapDestructible[i].size.x / 32,_gd->mapBedRoom->mapDestructible[i].size.y / 32 };
			BlitSprite(_gd->blockDestruc, _gd->mapBedRoom->mapDestructible[i].pos.x - _gd->cam.x, _gd->mapBedRoom->mapDestructible[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd->window);
		}
	}
*/
	}

	//pour placer les sprites à des position spéciale
	for (int i = 0; i < _gd->mapBedRoom->nbPoint; i++)
	{
		sfVector2f scale = { 1,1 };
		sfVector2f point = ScreenToWorld(_gd->mapBedRoom->mapPoint[i].pos.x, _gd->mapBedRoom->mapPoint[i].pos.y);
		//if (_gd->mapBedRoom->mapPoint[i].active == sfTrue)
		//{
		//	//printf("%fyo %f\n", _gd->mapParameter.mapPoint[i].pos.y, _gd->player.pos.y);
		//	//sfVector2f scale = { _gd->mapParameter.mapPoint[i].size.x / 32,_gd->mapParameter.mapPoint[i].size.y / 32 };
		//	BlitSprite(_gd->blockPoint, _gd->mapBedRoom->mapPoint[i].pos.x - _gd->cam.x, _gd->mapBedRoom->mapPoint[i].pos.y - _gd->cam.y, 0, 0.5, 0.5, _gd);
		//}
		int tempJ = 0;
		/*for (int j = 0; j < _gd->mapBedRoom->nbProprietySprite; j++)
		{
			rectText.left = _gd->mapBedRoom->proprietySprite[j].id % _gd->mapBedRoom->columns * rectText.height;
			rectText.top = _gd->mapBedRoom->proprietySprite[j].id / _gd->mapBedRoom->columns * rectText.width;
			sfSprite_setTextureRect(_gd->spriteShip, rectText);
			if (!strcmp(_gd->mapBedRoom->mapPoint[i].name, "code_bon")
				&& (IsPointIsInCamera(point.x + 5, point.y + 5, camCell, camCellMax)
					|| IsPointIsInCamera(point.x, point.y, camCell, camCellMax)))
			{
				if (_gd->enigme.doorDigicode.resolvedIntro == sfTrue
					&& !strcmp(_gd->mapBedRoom->proprietySprite[j].name, "green_light"))
				{
					BlitSprite(_gd->spriteShip, _gd->mapBedRoom->mapPoint[i].pos.x - _gd->cam.x + (j % 2 * 64),
						_gd->mapBedRoom->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
				}
			}
		}*/
	}



	//claque light qui est par dessus de tout
	for (int k = 0; k < _gd->mapBedRoom->nbCalque; k++)
	{
		if (strstr(_gd->mapBedRoom->mapID[k].name, "Light") != NULL)
		{
			for (int yMap = camCell.y; yMap <= camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1; yMap++)
			{
				for (int xMap = camCell.x; xMap <= camCell.x + (SCREEN_WIDTH / SIZECELL); xMap++)
				{
					for (int i = 0; i < _gd->mapBedRoom->nbAnimSprite; i++)
					{
						if (IsCellAvailable(yMap, xMap, _gd->mapBedRoom->height, _gd->mapBedRoom->witdh));
						{
							int tempID = -1;
							if (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] != _gd->mapBedRoom->animTiled.id[i])
							{
								if (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] < -1)
								{
									transform = (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
									tempID = (puissance % ((_gd->mapBedRoom->mapID[k].idMap[xMap][yMap]) % puissance));
								}
								else if (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] > -1)
								{
									transform = (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] / puissance) + 4;
									tempID = (((_gd->mapBedRoom->mapID[k].idMap[xMap][yMap]) % puissance));
								}
								_gd->mapBedRoom->animTiled.needRotate[i] = sfTrue;
							}
							if (_gd->mapBedRoom->mapID[k].idMap[xMap][yMap] == _gd->mapBedRoom->animTiled.id[i]
								|| tempID == _gd->mapBedRoom->animTiled.id[i])
							{
								sfVector2f scale = { 1,1 };
								sfVector2f posTransform = { 0,0 };
								float angle = 0;
								rectText.left = _gd->mapBedRoom->animTiled.spriteAnim[i].id[_gd->mapBedRoom->animTiled.spriteAnim[i].currentAnim] % _gd->mapBedRoom->columns * rectText.width;
								rectText.top = _gd->mapBedRoom->animTiled.spriteAnim[i].id[_gd->mapBedRoom->animTiled.spriteAnim[i].currentAnim] / _gd->mapBedRoom->columns * rectText.height;
								if (tempID == _gd->mapBedRoom->animTiled.id[i]
									&& _gd->mapBedRoom->animTiled.needRotate[i] == sfTrue)
								{
									RotationSpriteSheet(&scale, &posTransform, &angle, transform);
								}
								sfSprite_setTextureRect(_gd->spriteShip, rectText);
								//if (UpperUnderPlayerIntro(_gd->mapBedRoom->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
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