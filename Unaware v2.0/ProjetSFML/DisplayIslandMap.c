#include "DisplayIslandMap.h"

void DisplayPlancheEnigmePuzzle(GameData* _gd, sfIntRect rectText, sfVector2f camCell, sfVector2f camCellMax)
{
	for (int i = 0; i < _gd->mapIsland->nbPoint; i++)
	{
		sfVector2f scale = { 1,1 };
		sfVector2f point = ScreenToWorld(_gd->mapIsland->mapPoint[i].pos.x, _gd->mapIsland->mapPoint[i].pos.y);
		int tempJ = 0;
		for (int j = 0; j < _gd->mapIsland->nbProprietySprite; j++)
		{
			rectText.left = _gd->mapIsland->proprietySprite[j].id % _gd->mapIsland->columns * rectText.height;
			rectText.top = _gd->mapIsland->proprietySprite[j].id / _gd->mapIsland->columns * rectText.width;
			sfSprite_setTextureRect(_gd->spriteIsland, rectText);
			if (strstr(_gd->mapIsland->mapPoint[i].name, "planche")
				&& (IsPointIsInCamera(point.x + 5, point.y + 5, camCell, camCellMax)
					|| IsPointIsInCamera(point.x, point.y, camCell, camCellMax)))
			{
				for (int k = 0; k < _gd->mapIsland->nbDestructible; k++)
				{
					if (!strcmp(_gd->mapIsland->proprietySprite[j].name, "planche0")
						&& strstr(_gd->mapIsland->mapDestructible[k].name, "5_6") != NULL
						&& strstr(_gd->mapIsland->mapPoint[i].name, "5_6")
						&& _gd->mapIsland->mapDestructible[k].recup == sfFalse)
					{
						BlitSprite(_gd->spriteIsland, _gd->mapIsland->mapPoint[i].pos.x - _gd->cam.x,
							_gd->mapIsland->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
					}
					if (!strcmp(_gd->mapIsland->proprietySprite[j].name, "planche0")
						&& strstr(_gd->mapIsland->mapDestructible[k].name, "18") != NULL
						&& strstr(_gd->mapIsland->mapPoint[i].name, "18")
						&& _gd->mapIsland->mapDestructible[k].recup == sfFalse)
					{
						rectText.left -= 32;
						sfSprite_setTextureRect(_gd->spriteIsland, rectText);
						BlitSprite(_gd->spriteIsland, _gd->mapIsland->mapPoint[i].pos.x - _gd->cam.x,
							_gd->mapIsland->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
					}
					if (!strcmp(_gd->mapIsland->proprietySprite[j].name, "planche0")
						&& strstr(_gd->mapIsland->mapDestructible[k].name, "9") != NULL
						&& strstr(_gd->mapIsland->mapPoint[i].name, "9")
						&& _gd->mapIsland->mapDestructible[k].recup == sfFalse)
					{
						rectText.left -= 32;
						sfSprite_setTextureRect(_gd->spriteIsland, rectText);
						BlitSprite(_gd->spriteIsland, _gd->mapIsland->mapPoint[i].pos.x - _gd->cam.x,
							_gd->mapIsland->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
					}
					if (!strcmp(_gd->mapIsland->proprietySprite[j].name, "planche0")
						&& strstr(_gd->mapIsland->mapDestructible[k].name, "7_8") != NULL
						&& strstr(_gd->mapIsland->mapPoint[i].name, "7_8")
						&& _gd->mapIsland->mapDestructible[k].recup == sfFalse)
					{
						BlitSprite(_gd->spriteIsland, _gd->mapIsland->mapPoint[i].pos.x - _gd->cam.x,
							_gd->mapIsland->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
					}
					if (!strcmp(_gd->mapIsland->proprietySprite[j].name, "planche0")
						&& strstr(_gd->mapIsland->mapDestructible[k].name, "23") != NULL
						&& strstr(_gd->mapIsland->mapPoint[i].name, "23")
						&& _gd->mapIsland->mapDestructible[k].recup == sfFalse)
					{
						rectText.left -= 32;
						sfSprite_setTextureRect(_gd->spriteIsland, rectText);
						BlitSprite(_gd->spriteIsland, _gd->mapIsland->mapPoint[i].pos.x - _gd->cam.x,
							_gd->mapIsland->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
					}
					if (!strcmp(_gd->mapIsland->proprietySprite[j].name, "planche0")
						&& strstr(_gd->mapIsland->mapDestructible[k].name, "15_16") != NULL
						&& strstr(_gd->mapIsland->mapPoint[i].name, "15_16")
						&& _gd->mapIsland->mapDestructible[k].recup == sfFalse)
					{
						BlitSprite(_gd->spriteIsland, _gd->mapIsland->mapPoint[i].pos.x - _gd->cam.x,
							_gd->mapIsland->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
					}
				}
			}
		}
	}
}

void DisplayBridge(GameData* _gd, sfIntRect rectText, sfVector2f camCell, sfVector2f camCellMax)
{
	for (int i = 0; i < _gd->mapIsland->nbPoint; i++)
	{
		sfVector2f scale = { 1,1 };
		sfVector2f point = ScreenToWorld(_gd->mapIsland->mapPoint[i].pos.x, _gd->mapIsland->mapPoint[i].pos.y);
		int tempJ = 0;
		for (int j = 0; j < _gd->mapIsland->nbProprietySprite; j++)
		{
			rectText.left = _gd->mapIsland->proprietySprite[j].id % _gd->mapIsland->columns * rectText.height;
			rectText.top = _gd->mapIsland->proprietySprite[j].id / _gd->mapIsland->columns * rectText.width;
			sfSprite_setTextureRect(_gd->spriteIsland, rectText);
			if (!strcmp(_gd->mapIsland->mapPoint[i].name, "pontBlocked")
				&& (IsPointIsInCamera(point.x + 5, point.y + 5, camCell, camCellMax)
					|| IsPointIsInCamera(point.x, point.y, camCell, camCellMax)))
			{
				if (_gd->enigme.utilityPuzzle.resolvedPuzzleDream_1 == sfFalse
					&& !strcmp(_gd->mapIsland->proprietySprite[j].name, "pont_break"))
				{
					BlitSprite(_gd->spriteIsland, _gd->mapIsland->mapPoint[i].pos.x - _gd->cam.x + (j % 2 * 64),
						_gd->mapIsland->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
				}
				if (_gd->enigme.utilityPuzzle.resolvedPuzzleDream_1 == sfTrue
					&& !strcmp(_gd->mapIsland->proprietySprite[j].name, "pont_repare"))
				{
					BlitSprite(_gd->spriteIsland, _gd->mapIsland->mapPoint[i].pos.x - _gd->cam.x + (j % 2 * 64),
						_gd->mapIsland->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
				}
			}
		}
	}
}

void DisplayIslandMap(GameData* _gd)
{
	int transform = 0;
	int puissance = pow(2, 29);
	sfIntRect rectText;
	rectText.width = _gd->mapIsland->tilewitdh;
	rectText.height = _gd->mapIsland->tileheight;

	sfVector2f camCell = ScreenToWorld(_gd->cam.x, _gd->cam.y);
	sfVector2f camCellMax = { camCell.x + (SCREEN_WIDTH / SIZECELL), camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1 };

	for (int k = 0; k < _gd->mapIsland->nbCalque; k++)
	{
		if (!strcmp(_gd->mapIsland->mapID[k].name, "Planche"))
		{
			DisplayPlancheEnigmePuzzle(_gd, rectText, camCell, camCellMax);
		}
		if (!strcmp(_gd->mapIsland->mapID[k].name, "Bridge"))
		{
			DisplayBridge(_gd, rectText, camCell, camCellMax);
		}
		for (int yMap = camCell.y; yMap <= camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1; yMap++)
		{
			for (int xMap = camCell.x; xMap <= camCell.x + (SCREEN_WIDTH / SIZECELL); xMap++)
			{
				if (IsCellAvailable(yMap, xMap, _gd->mapIsland->height, _gd->mapIsland->witdh));
				{
					//pour les calque normaux 
					{
						int tempID = _gd->mapIsland->mapID[k].idMap[xMap][yMap];
						if (_gd->mapIsland->mapID[k].idMap[xMap][yMap] < -1)
						{
							transform = (_gd->mapIsland->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
							tempID = (_gd->mapIsland->mapID[k].idMap[xMap][yMap]) % puissance;
							if (tempID != 0)
							{
								tempID = puissance % tempID;
							}
							else
							{
								transform--;
							}

							_gd->mapIsland->mapID[k].needRotate[xMap][yMap] = sfTrue;
						}
						else if (_gd->mapIsland->mapID[k].idMap[xMap][yMap] > 100000)
						{
							transform = (_gd->mapIsland->mapID[k].idMap[xMap][yMap] / puissance) + 4;
							tempID = (((_gd->mapIsland->mapID[k].idMap[xMap][yMap]) % puissance));
							_gd->mapIsland->mapID[k].needRotate[xMap][yMap] = sfTrue;
						}
						//collum
						rectText.left = tempID % _gd->mapIsland->columns * rectText.height;
						//ligne
						rectText.top = tempID / _gd->mapIsland->columns * rectText.width;
						sfVector2f scale = { 1,1 };
						sfVector2f posTransform = { 0,0 };
						float angle = 0;
						if (_gd->mapIsland->mapID[k].needRotate[xMap][yMap] == sfTrue)
						{
							RotationSpriteSheet(&scale, &posTransform, &angle, transform);
						}
						sfSprite_setTextureRect(_gd->spriteIsland, rectText);
						if (UpperUnderPlayer(_gd->mapIsland->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
						{
							BlitSprite(_gd->spriteIsland, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
								(yMap * rectText.height) - _gd->cam.y + posTransform.y, angle, scale.x, scale.y, _gd);
						}
					}
					//pour les calques avec des animations dessus 
					for (int i = 0; i < _gd->mapIsland->nbAnimSprite; i++)
					{
						int tempID = -1;
						if (_gd->mapIsland->mapID[k].idMap[xMap][yMap] != _gd->mapIsland->animTiled.id[i])
						{
							if (_gd->mapIsland->mapID[k].idMap[xMap][yMap] < -1)
							{
								transform = (_gd->mapIsland->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
								tempID = (_gd->mapIsland->mapID[k].idMap[xMap][yMap]) % puissance;
								if (tempID != 0)
								{
									tempID = puissance % tempID;
								}
								else
								{
									transform--;
								}
							}
							else if (_gd->mapIsland->mapID[k].idMap[xMap][yMap] > -1)
							{
								transform = (_gd->mapIsland->mapID[k].idMap[xMap][yMap] / puissance) + 4;
								tempID = (((_gd->mapIsland->mapID[k].idMap[xMap][yMap]) % puissance));
							}
							_gd->mapIsland->animTiled.needRotate[i] = sfTrue;
						}
						if ((_gd->mapIsland->mapID[k].idMap[xMap][yMap] == _gd->mapIsland->animTiled.id[i]
							|| tempID == _gd->mapIsland->animTiled.id[i])
							&& strstr(_gd->mapIsland->mapID[k].name, "Light") == NULL)
						{
							sfVector2f scale = { 1,1 };
							sfVector2f posTransform = { 0,0 };
							float angle = 0;
							rectText.left = _gd->mapIsland->animTiled.spriteAnim[i].id[_gd->mapIsland->animTiled.spriteAnim[i].currentAnim] % _gd->mapIsland->columns * rectText.width;
							rectText.top = _gd->mapIsland->animTiled.spriteAnim[i].id[_gd->mapIsland->animTiled.spriteAnim[i].currentAnim] / _gd->mapIsland->columns * rectText.height;
							if (tempID == _gd->mapIsland->animTiled.id[i]
								&& _gd->mapIsland->animTiled.needRotate[i] == sfTrue)
							{
								RotationSpriteSheet(&scale, &posTransform, &angle, transform);
							}
							sfSprite_setTextureRect(_gd->spriteIsland, rectText);
							if (UpperUnderPlayer(_gd->mapIsland->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
							{
								BlitSprite(_gd->spriteIsland, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
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
	/*for (int i = 0; i < _gd->mapIsland->nbCollision; i++)
	{
		sfVector2f scale = { _gd->mapIsland->mapCollision[i].size.x / 32,_gd->mapIsland->mapCollision[i].size.y / 32 };
		BlitSprite(_gd->blockColli, _gd->mapIsland->mapCollision[i].pos.x - _gd->cam.x, _gd->mapIsland->mapCollision[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd->window);
	}*/

	//for (int i = 0; i < _gd->mapIsland->nbInteraction; i++)
	//{
	//	sfVector2f scale = { _gd->mapIsland->mapInteraction[i].size.x / 32,_gd->mapIsland->mapInteraction[i].size.y / 32 };

	//	BlitSprite(_gd->blockInterac, _gd->mapIsland->mapInteraction[i].pos.x - _gd->cam.x, _gd->mapIsland->mapInteraction[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd->window);
	//}

	/*for (int i = 0; i < _gd->mapIsland->nbDestructible; i++)
	{
		if (_gd->mapIsland->mapDestructible[i].recup == sfFalse)
		{
			sfVector2f scale = { _gd->mapIsland->mapDestructible[i].size.x / 32,_gd->mapIsland->mapDestructible[i].size.y / 32 };
			BlitSprite(_gd->blockDestruc, _gd->mapIsland->mapDestructible[i].pos.x - _gd->cam.x, _gd->mapIsland->mapDestructible[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
		}
	}*/
	}


	for (int i = 0; i < _gd->mapIsland->nbNPC; i++)
	{
		sfVector2f point = ScreenToWorld(_gd->npc[i].pos.x, _gd->npc[i].pos.y);
		if (_gd->player.pos.y > _gd->npc[i].pos.y
			&& (IsPointIsInCamera(point.x + 5, point.y, camCell, camCellMax)
				|| IsPointIsInCamera(point.x, point.y + 5, camCell, camCellMax)
				|| IsPointIsInCamera(point.x, point.y, camCell, camCellMax)
				|| IsPointIsInCamera(point.x - 5, point.y, camCell, camCellMax)
				|| IsPointIsInCamera(point.x, point.y - 5, camCell, camCellMax)))
		{
			BlitSprite(_gd->npc[i].npcDef.Timeline[_gd->npc[i].currentAnim], _gd->npc[i].pos.x - _gd->cam.x, _gd->npc[i].pos.y - _gd->cam.y, 0, 1, 1, _gd);
		}
	}

}

void DisplayIslandMapUpper(GameData* _gd)
{
	int transform = 0;
	int puissance = pow(2, 29);
	sfVector2f camCell = ScreenToWorld(_gd->cam.x, _gd->cam.y);
	sfVector2f camCellMax = { camCell.x + (SCREEN_WIDTH / SIZECELL), camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1 };
	sfIntRect rectText;
	rectText.width = _gd->mapIsland->tilewitdh;
	rectText.height = _gd->mapIsland->tileheight;
	for (int k = 0; k < _gd->mapIsland->nbCalque; k++)
	{
		if (strstr(_gd->mapIsland->mapID[k].name, "upper") != NULL)
		{
			for (int yMap = camCell.y; yMap <= camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1; yMap++)
			{
				for (int xMap = camCell.x; xMap <= camCell.x + (SCREEN_WIDTH / SIZECELL); xMap++)
				{
					if (IsCellAvailable(yMap, xMap, _gd->mapIsland->witdh, _gd->mapIsland->height));
					{
						//pour les calque normaux 
						{
							int tempID = _gd->mapIsland->mapID[k].idMap[xMap][yMap];
							if (_gd->mapIsland->mapID[k].idMap[xMap][yMap] < -1)
							{
								transform = (_gd->mapIsland->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
								tempID = (_gd->mapIsland->mapID[k].idMap[xMap][yMap]) % puissance;
								if (tempID != 0)
								{
									tempID = puissance % tempID;
								}
								else
								{
									transform--;
								}

								_gd->mapIsland->mapID[k].needRotate[xMap][yMap] = sfTrue;
							}
							else if (_gd->mapIsland->mapID[k].idMap[xMap][yMap] > 100000)
							{
								transform = (_gd->mapIsland->mapID[k].idMap[xMap][yMap] / puissance) + 4;
								tempID = (((_gd->mapIsland->mapID[k].idMap[xMap][yMap]) % puissance));
								_gd->mapIsland->mapID[k].needRotate[xMap][yMap] = sfTrue;
							}
							//collum
							rectText.left = tempID % _gd->mapIsland->columns * rectText.height;
							//ligne
							rectText.top = tempID / _gd->mapIsland->columns * rectText.width;
							sfVector2f scale = { 1,1 };
							sfVector2f posTransform = { 0,0 };
							float angle = 0;
							if (_gd->mapIsland->mapID[k].needRotate[xMap][yMap] == sfTrue)
							{
								RotationSpriteSheet(&scale, &posTransform, &angle, transform);
							}
							sfSprite_setTextureRect(_gd->spriteIsland, rectText);
							if (UpperOnPlayer(_gd->mapIsland->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
							{
								BlitSprite(_gd->spriteIsland, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
									(yMap * rectText.height) - _gd->cam.y + posTransform.y, angle, scale.x, scale.y, _gd);
							}
						}
						////pour les calques avec des animations dessus 
						for (int i = 0; i < _gd->mapIsland->nbAnimSprite; i++)
						{
							int tempID = -1;
							if (_gd->mapIsland->mapID[k].idMap[xMap][yMap] != _gd->mapIsland->animTiled.id[i])
							{
								if (_gd->mapIsland->mapID[k].idMap[xMap][yMap] < -1)
								{
									transform = (_gd->mapIsland->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
									tempID = (_gd->mapIsland->mapID[k].idMap[xMap][yMap]) % puissance;
									if (tempID != 0)
									{
										tempID = puissance % tempID;
									}
									else
									{
										transform--;
									}
								}
								else if (_gd->mapIsland->mapID[k].idMap[xMap][yMap] > -1)
								{
									transform = (_gd->mapIsland->mapID[k].idMap[xMap][yMap] / puissance) + 4;
									tempID = (((_gd->mapIsland->mapID[k].idMap[xMap][yMap]) % puissance));
								}
								_gd->mapIsland->animTiled.needRotate[i] = sfTrue;
							}
							if ((_gd->mapIsland->mapID[k].idMap[xMap][yMap] == _gd->mapIsland->animTiled.id[i]
								|| tempID == _gd->mapIsland->animTiled.id[i])
								&& strstr(_gd->mapIsland->mapID[k].name, "Light") == NULL)
							{
								sfVector2f scale = { 1,1 };
								sfVector2f posTransform = { 0,0 };
								float angle = 0;
								rectText.left = _gd->mapIsland->animTiled.spriteAnim[i].id[_gd->mapIsland->animTiled.spriteAnim[i].currentAnim] % _gd->mapIsland->columns * rectText.width;
								rectText.top = _gd->mapIsland->animTiled.spriteAnim[i].id[_gd->mapIsland->animTiled.spriteAnim[i].currentAnim] / _gd->mapIsland->columns * rectText.height;
								if (tempID == _gd->mapIsland->animTiled.id[i]
									&& _gd->mapIsland->animTiled.needRotate[i] == sfTrue)
								{
									RotationSpriteSheet(&scale, &posTransform, &angle, transform);
								}
								sfSprite_setTextureRect(_gd->spriteIsland, rectText);
								if (UpperOnPlayer(_gd->mapIsland->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
								{
									BlitSprite(_gd->spriteIsland, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
										(yMap * rectText.height) - _gd->cam.y + posTransform.y, angle, scale.x, scale.y, _gd);
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < _gd->mapIsland->nbNPC; i++)
	{
		sfVector2f point = ScreenToWorld(_gd->npc[i].pos.x, _gd->npc[i].pos.y);
		if (_gd->player.pos.y <= _gd->npc[i].pos.y
			&& (IsPointIsInCamera(point.x + 5, point.y, camCell, camCellMax)
				|| IsPointIsInCamera(point.x, point.y + 5, camCell, camCellMax)
				|| IsPointIsInCamera(point.x, point.y, camCell, camCellMax)
				|| IsPointIsInCamera(point.x - 5, point.y, camCell, camCellMax)
				|| IsPointIsInCamera(point.x, point.y - 5, camCell, camCellMax)))
		{
			sfVector2f TempPos = WorldToScreen(point.x, point.y);
			BlitSprite(_gd->npc[i].npcDef.Timeline[_gd->npc[i].currentAnim], _gd->npc[i].pos.x - _gd->cam.x, _gd->npc[i].pos.y - _gd->cam.y, 0, 1, 1, _gd);
		}
	}

}
