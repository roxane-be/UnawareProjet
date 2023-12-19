#include "DisplayShipEndMap.h"

void DisplayShipEndMap(GameData* _gd)
{
	int transform = 0;
	int puissance = pow(2, 29);
	sfIntRect rectText;
	rectText.width = _gd->mapShipEnd->tilewitdh;
	rectText.height = _gd->mapShipEnd->tileheight;

	sfVector2f camCell = ScreenToWorld(_gd->cam.x, _gd->cam.y);
	sfVector2f camCellMax = { camCell.x + (SCREEN_WIDTH / SIZECELL), camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1 };

	for (int k = 0; k < _gd->mapShipEnd->nbCalque; k++)
	{
		for (int yMap = camCell.y; yMap <= camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1; yMap++)
		{
			for (int xMap = camCell.x; xMap <= camCell.x + (SCREEN_WIDTH / SIZECELL); xMap++)
			{
				if (IsCellAvailable(yMap, xMap, _gd->mapShipEnd->height, _gd->mapShipEnd->witdh));
				{
					//pour les calque normaux 
					{
						int tempID = _gd->mapShipEnd->mapID[k].idMap[xMap][yMap];
						if (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] < -1)
						{
							transform = (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
							tempID = (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap]) % puissance;
							if (tempID != 0)
							{
								tempID = puissance % tempID;
							}
							else
							{
								transform--;
							}

							_gd->mapShipEnd->mapID[k].needRotate[xMap][yMap] = sfTrue;
						}
						else if (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] > 100000)
						{
							transform = (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] / puissance) + 4;
							tempID = (((_gd->mapShipEnd->mapID[k].idMap[xMap][yMap]) % puissance));
							_gd->mapShipEnd->mapID[k].needRotate[xMap][yMap] = sfTrue;
						}
						//collum
						rectText.left = tempID % _gd->mapShipEnd->columns * rectText.height;
						//ligne
						rectText.top = tempID / _gd->mapShipEnd->columns * rectText.width;
						sfVector2f scale = { 1,1 };
						sfVector2f posTransform = { 0,0 };
						float angle = 0;
						if (_gd->mapShipEnd->mapID[k].needRotate[xMap][yMap] == sfTrue)
						{
							RotationSpriteSheet(&scale, &posTransform, &angle, transform);
						}
						sfSprite_setTextureRect(_gd->spriteShip, rectText);
						if (UpperUnderPlayer(_gd->mapShipEnd->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
						{
							BlitSprite(_gd->spriteShip, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
								(yMap * rectText.height) - _gd->cam.y + posTransform.y, angle, scale.x, scale.y, _gd);
						}
					}
					//pour les calques avec des animations dessus 
					for (int i = 0; i < _gd->mapShipEnd->nbAnimSprite; i++)
					{
						int tempID = -1;
						if (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] != _gd->mapShipEnd->animTiled.id[i])
						{
							if (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] < -1)
							{
								transform = (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
								tempID = (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap]) % puissance;
								if (tempID != 0)
								{
									tempID = puissance % tempID;
								}
								else
								{
									transform--;
								}
							}
							else if (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] > -1)
							{
								transform = (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] / puissance) + 4;
								tempID = (((_gd->mapShipEnd->mapID[k].idMap[xMap][yMap]) % puissance));
							}
							_gd->mapShipEnd->animTiled.needRotate[i] = sfTrue;
						}
						if ((_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] == _gd->mapShipEnd->animTiled.id[i]
							|| tempID == _gd->mapShipEnd->animTiled.id[i])
							&& strstr(_gd->mapShipEnd->mapID[k].name, "Light") == NULL)
						{
							sfVector2f scale = { 1,1 };
							sfVector2f posTransform = { 0,0 };
							float angle = 0;
							rectText.left = _gd->mapShipEnd->animTiled.spriteAnim[i].id[_gd->mapShipEnd->animTiled.spriteAnim[i].currentAnim] % _gd->mapShipEnd->columns * rectText.width;
							rectText.top = _gd->mapShipEnd->animTiled.spriteAnim[i].id[_gd->mapShipEnd->animTiled.spriteAnim[i].currentAnim] / _gd->mapShipEnd->columns * rectText.height;
							if (tempID == _gd->mapShipEnd->animTiled.id[i]
								&& _gd->mapShipEnd->animTiled.needRotate[i] == sfTrue)
							{
								RotationSpriteSheet(&scale, &posTransform, &angle, transform);
							}
							sfSprite_setTextureRect(_gd->spriteShip, rectText);
							if (UpperUnderPlayer(_gd->mapShipEnd->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
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

void DisplayShipEndMapUpper(GameData* _gd)
{
	int transform = 0;
	int puissance = pow(2, 29);
	sfVector2f camCell = ScreenToWorld(_gd->cam.x, _gd->cam.y);
	sfVector2f camCellMax = { camCell.x + (SCREEN_WIDTH / SIZECELL), camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1 };
	sfIntRect rectText;
	rectText.width = _gd->mapShipEnd->tilewitdh;
	rectText.height = _gd->mapShipEnd->tileheight;
	for (int k = 0; k < _gd->mapShipEnd->nbCalque; k++)
	{
		if (strstr(_gd->mapShipEnd->mapID[k].name, "upper") != NULL)
		{
			for (int yMap = camCell.y; yMap <= camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1; yMap++)
			{
				for (int xMap = camCell.x; xMap <= camCell.x + (SCREEN_WIDTH / SIZECELL); xMap++)
				{
					if (IsCellAvailable(yMap, xMap, _gd->mapShipEnd->witdh, _gd->mapShipEnd->height));
					{
						//pour les calque normaux 
						{
							int tempID = _gd->mapShipEnd->mapID[k].idMap[xMap][yMap];
							if (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] < -1)
							{
								transform = (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
								tempID = (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap]) % puissance;
								if (tempID != 0)
								{
									tempID = puissance % tempID;
								}
								else
								{
									transform--;
								}

								_gd->mapShipEnd->mapID[k].needRotate[xMap][yMap] = sfTrue;
							}
							else if (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] > 100000)
							{
								transform = (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] / puissance) + 4;
								tempID = (((_gd->mapShipEnd->mapID[k].idMap[xMap][yMap]) % puissance));
								_gd->mapShipEnd->mapID[k].needRotate[xMap][yMap] = sfTrue;
							}
							//collum
							rectText.left = tempID % _gd->mapShipEnd->columns * rectText.height;
							//ligne
							rectText.top = tempID / _gd->mapShipEnd->columns * rectText.width;
							sfVector2f scale = { 1,1 };
							sfVector2f posTransform = { 0,0 };
							float angle = 0;
							if (_gd->mapShipEnd->mapID[k].needRotate[xMap][yMap] == sfTrue)
							{
								RotationSpriteSheet(&scale, &posTransform, &angle, transform);
							}
							sfSprite_setTextureRect(_gd->spriteShip, rectText);
							if (UpperOnPlayer(_gd->mapShipEnd->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
							{
								BlitSprite(_gd->spriteShip, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
									(yMap * rectText.height) - _gd->cam.y + posTransform.y, angle, scale.x, scale.y, _gd);
							}
						}
						////pour les calques avec des animations dessus 
						for (int i = 0; i < _gd->mapShipEnd->nbAnimSprite; i++)
						{
							int tempID = -1;
							if (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] != _gd->mapShipEnd->animTiled.id[i])
							{
								if (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] < -1)
								{
									transform = (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
									tempID = (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap]) % puissance;
									if (tempID != 0)
									{
										tempID = puissance % tempID;
									}
									else
									{
										transform--;
									}
								}
								else if (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] > -1)
								{
									transform = (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] / puissance) + 4;
									tempID = (((_gd->mapShipEnd->mapID[k].idMap[xMap][yMap]) % puissance));
								}
								_gd->mapShipEnd->animTiled.needRotate[i] = sfTrue;
							}
							if ((_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] == _gd->mapShipEnd->animTiled.id[i]
								|| tempID == _gd->mapShipEnd->animTiled.id[i])
								&& strstr(_gd->mapShipEnd->mapID[k].name, "Light") == NULL)
							{
								sfVector2f scale = { 1,1 };
								sfVector2f posTransform = { 0,0 };
								float angle = 0;
								rectText.left = _gd->mapShipEnd->animTiled.spriteAnim[i].id[_gd->mapShipEnd->animTiled.spriteAnim[i].currentAnim] % _gd->mapShipEnd->columns * rectText.width;
								rectText.top = _gd->mapShipEnd->animTiled.spriteAnim[i].id[_gd->mapShipEnd->animTiled.spriteAnim[i].currentAnim] / _gd->mapShipEnd->columns * rectText.height;
								if (tempID == _gd->mapShipEnd->animTiled.id[i]
									&& _gd->mapShipEnd->animTiled.needRotate[i] == sfTrue)
								{
									RotationSpriteSheet(&scale, &posTransform, &angle, transform);
								}
								sfSprite_setTextureRect(_gd->spriteShip, rectText);
								if (UpperOnPlayer(_gd->mapShipEnd->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
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


	//claque light qui est par dessus de tout
	for (int k = 0; k < _gd->mapShipEnd->nbCalque; k++)
	{
		if (strstr(_gd->mapShipEnd->mapID[k].name, "Light") != NULL)
		{
			for (int yMap = camCell.y; yMap <= camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1; yMap++)
			{
				for (int xMap = camCell.x; xMap <= camCell.x + (SCREEN_WIDTH / SIZECELL); xMap++)
				{
					for (int i = 0; i < _gd->mapShipEnd->nbAnimSprite; i++)
					{
						if (IsCellAvailable(yMap, xMap, _gd->mapShipEnd->height, _gd->mapShipEnd->witdh));
						{
							int tempID = -1;
							if (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] != _gd->mapShipEnd->animTiled.id[i])
							{
								if (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] < -1)
								{
									transform = (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
									tempID = (puissance % ((_gd->mapShipEnd->mapID[k].idMap[xMap][yMap]) % puissance));
								}
								else if (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] > -1)
								{
									transform = (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] / puissance) + 4;
									tempID = (((_gd->mapShipEnd->mapID[k].idMap[xMap][yMap]) % puissance));
								}
								_gd->mapShipEnd->animTiled.needRotate[i] = sfTrue;
							}
							if (_gd->mapShipEnd->mapID[k].idMap[xMap][yMap] == _gd->mapShipEnd->animTiled.id[i]
								|| tempID == _gd->mapShipEnd->animTiled.id[i])
							{
								sfVector2f scale = { 1,1 };
								sfVector2f posTransform = { 0,0 };
								float angle = 0;
								rectText.left = _gd->mapShipEnd->animTiled.spriteAnim[i].id[_gd->mapShipEnd->animTiled.spriteAnim[i].currentAnim] % _gd->mapShipEnd->columns * rectText.width;
								rectText.top = _gd->mapShipEnd->animTiled.spriteAnim[i].id[_gd->mapShipEnd->animTiled.spriteAnim[i].currentAnim] / _gd->mapShipEnd->columns * rectText.height;
								if (tempID == _gd->mapShipEnd->animTiled.id[i]
									&& _gd->mapShipEnd->animTiled.needRotate[i] == sfTrue)
								{
									RotationSpriteSheet(&scale, &posTransform, &angle, transform);
								}
								sfSprite_setTextureRect(_gd->spriteShip, rectText);
								//if (UpperUnderPlayerIntro(_gd->mapShipEnd->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
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