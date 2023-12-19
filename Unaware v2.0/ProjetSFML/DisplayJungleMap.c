#include "DisplayJungleMap.h"

void DisplayCoffre(GameData* _gd, sfIntRect rectText, sfVector2f camCell, sfVector2f camCellMax, int k)
{
	int transform = 0;
	int puissance = pow(2, 29);

	for (int i = 0; i < _gd->mapJungle->nbPoint; i++)
	{
		sfVector2f scale = { 1,1 };
		sfVector2f point = ScreenToWorld(_gd->mapJungle->mapPoint[i].pos.x, _gd->mapJungle->mapPoint[i].pos.y);
		int tempJ = 0;
		for (int j = 0; j < _gd->mapJungle->nbProprietySprite; j++)
		{
			rectText.left = _gd->mapJungle->proprietySprite[j].id % _gd->mapJungle->columns * rectText.height;
			rectText.top = _gd->mapJungle->proprietySprite[j].id / _gd->mapJungle->columns * rectText.width;
			sfSprite_setTextureRect(_gd->spriteJungle, rectText);
			if (!strcmp(_gd->mapJungle->mapPoint[i].name, "CoffreWrong")
				&& (IsPointIsInCamera(point.x + 5, point.y + 5, camCell, camCellMax)
					|| IsPointIsInCamera(point.x, point.y, camCell, camCellMax)))
			{

				if (_gd->CoffreWrong == sfTrue && _gd->inTp == sfFalse
					&& !strcmp(_gd->mapJungle->proprietySprite[j].name, "CoffreWrongBroke"))
				{
					if (tempJ < 5)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j + 1) % 5 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					else if (tempJ >= 5 && tempJ < 5 + 5)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j + 1) % 5 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					else if (tempJ >= 10 && tempJ < 15)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j + 3) % 5 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64 + 64, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					else if (tempJ >= 15)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j + 1) % 5 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64 + 64 + 64, 0, scale.x, scale.y, _gd);
						tempJ++;
					}


				}
				else if (_gd->inTp == sfTrue && _gd->CoffreWrong == sfTrue && _gd->CoffreWrongOpen == sfFalse
					&& strstr(_gd->mapJungle->proprietySprite[j].name, "CoffreWrongOpen") != NULL
					&& strrchr(_gd->mapJungle->proprietySprite[j].name, _gd->AnimCurrentCoffre) != NULL)
				{
					if (tempJ < 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j + 1) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					else if (tempJ >= 4 && tempJ < 4 + 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					else if (tempJ >= 4 + 4 && tempJ < 4 + 4 + 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j - 1) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64 + 64, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					else if (tempJ >= 4 + 4 + 4 && tempJ < 4 + 4 + 4 + 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j + 2) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64 + 64 + 64, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
				}
				else if (_gd->CoffreWrong == sfFalse
					&& strstr(_gd->mapJungle->proprietySprite[j].name, "CoffreWrongClosed") != NULL
					&& strrchr(_gd->mapJungle->proprietySprite[j].name, _gd->AnimCurrentCoffre) != NULL)
				{

					if (tempJ < 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					else if (tempJ >= 4 && tempJ < 4 + 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j + 3) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64 + 64, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
				}
			}
			else if (!strcmp(_gd->mapJungle->mapPoint[i].name, "CoffreGood")
				&& (IsPointIsInCamera(point.x + 5, point.y + 5, camCell, camCellMax)
					|| IsPointIsInCamera(point.x, point.y, camCell, camCellMax)))
			{
				if (_gd->CoffreGood == sfTrue && _gd->inTp == sfFalse
					&& !strcmp(_gd->mapJungle->proprietySprite[j].name, "CoffreGood"))
				{
					if (tempJ < 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j + 1) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					else if (tempJ >= 4 && tempJ < 4 + 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j + 1) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					else if (tempJ >= 4 + 4 && tempJ < 4 + 4 + 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j + 1) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64 + 64, 0, scale.x, scale.y, _gd);
						tempJ++;
					}

					/*if (tempJ < 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j ) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
						printf("%d  ", _gd->mapJungle->proprietySprite[j].id);
						tempJ++;
					}
					else if (tempJ >= 4 && tempJ < 4 + 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64, 0, scale.x, scale.y, _gd);
						printf("%d  ", _gd->mapJungle->proprietySprite[j].id);
						tempJ++;
					}
					else if (tempJ >= 4+4 && tempJ < 4 + 4+4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j-1) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64 +64, 0, scale.x, scale.y, _gd);
						printf("%d  ", _gd->mapJungle->proprietySprite[j].id);
						tempJ++;
					}
					else if (tempJ >= 4 + 4 +4&& tempJ < 4 +4+ 4 + 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j+2) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64 + 64+64, 0, scale.x, scale.y, _gd);
						printf("%d  ", _gd->mapJungle->proprietySprite[j].id);
						tempJ++;
					}*/
				}
				else if (_gd->inTp == sfTrue && _gd->CoffreGood == sfTrue && _gd->CoffreGoodOpen == sfFalse
					&& strstr(_gd->mapJungle->proprietySprite[j].name, "CoffreOpen") != NULL
					&& strrchr(_gd->mapJungle->proprietySprite[j].name, _gd->AnimCurrentCoffre) != NULL)
				{
					if (tempJ < 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j + 1) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					else if (tempJ >= 4 && tempJ < 4 + 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j + 1) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					else if (tempJ >= 4 + 4 && tempJ < 4 + 4 + 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j + 1) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64 + 64, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
				}

				else if (_gd->CoffreGood == sfFalse
					&& strstr(_gd->mapJungle->proprietySprite[j].name, "CoffreGoodClosed") != NULL
					&& strrchr(_gd->mapJungle->proprietySprite[j].name, _gd->AnimCurrentCoffre) != NULL)
				{
					if (tempJ < 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j + 1) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					else if (tempJ >= 4 && tempJ < 4 + 4)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j + 1) % 4 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64 + 64, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
				}
			}
		}
	}
}


void DisplayPaper(GameData* _gd, sfVector2f camCell, sfVector2f camCellMax)
{
	for (int i = 0; i < _gd->mapJungle->nbPoint; i++)
	{
		sfVector2f scale = { 1,1 };
		sfVector2f point = ScreenToWorld(_gd->mapJungle->mapPoint[i].pos.x, _gd->mapJungle->mapPoint[i].pos.y);
		int tempJ = 0;
		for (int k = 0; k < _gd->mapJungle->nbDestructible; k++)
		{
			if (!strcmp(_gd->mapJungle->mapPoint[i].name, "Paper1") != NULL
				&& (IsPointIsInCamera(point.x + 5, point.y + 5, camCell, camCellMax)
					|| IsPointIsInCamera(point.x, point.y, camCell, camCellMax))
				&& _gd->enigme.decryptage.paperRecup[0] == sfFalse
				)
			{
				BlitSprite(_gd->enigme.decryptage.paper, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x,
					_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
			}
			if (!strcmp(_gd->mapJungle->mapPoint[i].name, "Paper2") != NULL
				&& (IsPointIsInCamera(point.x + 5, point.y + 5, camCell, camCellMax)
					|| IsPointIsInCamera(point.x, point.y, camCell, camCellMax))
				&& _gd->enigme.decryptage.paperRecup[1] == sfFalse
				)
			{
				BlitSprite(_gd->enigme.decryptage.paper, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x,
					_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
			}
			if (!strcmp(_gd->mapJungle->mapPoint[i].name, "Paper3") != NULL
				&& (IsPointIsInCamera(point.x + 5, point.y + 5, camCell, camCellMax)
					|| IsPointIsInCamera(point.x, point.y, camCell, camCellMax))
				&& _gd->enigme.decryptage.paperRecup[2] == sfFalse
				)
			{
				BlitSprite(_gd->enigme.decryptage.paper, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x,
					_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
			}
			if (!strcmp(_gd->mapJungle->mapPoint[i].name, "Paper4") != NULL
				&& (IsPointIsInCamera(point.x + 5, point.y + 5, camCell, camCellMax)
					|| IsPointIsInCamera(point.x, point.y, camCell, camCellMax))
				&& _gd->enigme.decryptage.paperRecup[3] == sfFalse
				)
			{
				BlitSprite(_gd->enigme.decryptage.paper, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x,
					_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
			}
		}

	}

}

void DisplayFourmi(GameData* _gd, sfVector2f camCell, sfVector2f camCellMax)
{
	for (int i = 0; i < _gd->mapJungle->nbPoint; i++)
	{
		sfVector2f scale = { 1,1 };
		sfVector2f point = ScreenToWorld(_gd->mapJungle->mapPoint[i].pos.x, _gd->mapJungle->mapPoint[i].pos.y);
		int tempJ = 0;


		if (!strcmp(_gd->mapJungle->mapPoint[i].name, "Fourmi") != NULL
			&& (IsPointIsInCamera(point.x + 5, point.y + 5, camCell, camCellMax)
				|| IsPointIsInCamera(point.x, point.y, camCell, camCellMax))
			)
		{
			BlitSprite(_gd->fourmi[_gd->currentAnimFourmi], _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x,
				_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
		}
	}
}


void DisplayPuzzleMap(GameData* _gd, sfIntRect rectText, sfVector2f camCell, sfVector2f camCellMax)
{
	int transform = 0;
	int puissance = pow(2, 29);

	for (int i = 0; i < _gd->mapJungle->nbPoint; i++)
	{
		sfVector2f scale = { 1,1 };
		sfVector2f point = ScreenToWorld(_gd->mapJungle->mapPoint[i].pos.x, _gd->mapJungle->mapPoint[i].pos.y);
		int tempJ = 0;
		for (int j = 0; j < _gd->mapJungle->nbProprietySprite; j++)
		{
			rectText.left = _gd->mapJungle->proprietySprite[j].id % _gd->mapJungle->columns * rectText.height;
			rectText.top = _gd->mapJungle->proprietySprite[j].id / _gd->mapJungle->columns * rectText.width;
			sfSprite_setTextureRect(_gd->spriteJungle, rectText);
			if (!strcmp(_gd->mapJungle->mapPoint[i].name, "puzzle")
				&& (IsPointIsInCamera(point.x + 5, point.y + 5, camCell, camCellMax)
					|| IsPointIsInCamera(point.x, point.y, camCell, camCellMax)))
			{

				if (_gd->enigme.puzzleJungle.resolvedPuzzleJungle == sfFalse
					&& !strcmp(_gd->mapJungle->proprietySprite[j].name, "puzzleIncomplete"))
				{
					if (tempJ < 6)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j) % 6 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					if (tempJ >= 6 && tempJ < 6 * 2)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j) % 6 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					if (tempJ >= 6 * 2 && tempJ < 6 * 3)

					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j) % 6 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64 * 2, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					if (tempJ >= 6 * 3)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j) % 6 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64 * 3, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
				}
				if (_gd->enigme.puzzleJungle.resolvedPuzzleJungle == sfTrue
					&& !strcmp(_gd->mapJungle->proprietySprite[j].name, "puzzleResolved"))
				{
					if (tempJ < 6)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j) % 6 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					if (tempJ >= 6 && tempJ < 6 * 2)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j) % 6 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					if (tempJ >= 6 * 2 && tempJ < 6 * 3)

					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j) % 6 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64 * 2, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
					if (tempJ >= 6 * 3)
					{
						BlitSprite(_gd->spriteJungle, _gd->mapJungle->mapPoint[i].pos.x - _gd->cam.x + ((j) % 6 * 64),
							_gd->mapJungle->mapPoint[i].pos.y - _gd->cam.y + 64 * 3, 0, scale.x, scale.y, _gd);
						tempJ++;
					}
				}
			}
		}
	}


}

void DisplayJungleMap(GameData* _gd)
{
	int transform = 0;
	int puissance = pow(2, 29);
	sfIntRect rectText;
	rectText.width = _gd->mapJungle->tilewitdh;
	rectText.height = _gd->mapJungle->tileheight;

	sfVector2f camCell = ScreenToWorld(_gd->cam.x, _gd->cam.y);
	sfVector2f camCellMax = { camCell.x + (SCREEN_WIDTH / SIZECELL), camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1 };

	for (int k = 0; k < _gd->mapJungle->nbCalque; k++)
	{
		if ((!strcmp(_gd->mapJungle->mapID[k].name, "Paper")))
		{
			DisplayPaper(_gd, camCell, camCellMax);
		}
		if ((!strcmp(_gd->mapJungle->mapID[k].name, "NPC")))
		{
			DisplayFourmi(_gd, camCell, camCellMax);
		}
		if ((!strcmp(_gd->mapJungle->mapID[k].name, "Puzzle")))
		{
			DisplayPuzzleMap(_gd, rectText, camCell, camCellMax);
		}
		if ((!strcmp(_gd->mapJungle->mapID[k].name, "Coffre_upper")))
		{
			DisplayCoffre(_gd, rectText, camCell, camCellMax, k);
		}
		else
		{
			for (int yMap = camCell.y; yMap <= camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1; yMap++)
			{
				for (int xMap = camCell.x; xMap <= camCell.x + (SCREEN_WIDTH / SIZECELL); xMap++)
				{
					if (IsCellAvailable(yMap, xMap, _gd->mapJungle->height, _gd->mapJungle->witdh));
					{
						//pour les calque normaux 
						{
							int tempID = _gd->mapJungle->mapID[k].idMap[xMap][yMap];
							if (_gd->mapJungle->mapID[k].idMap[xMap][yMap] < -1)
							{
								transform = (_gd->mapJungle->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
								tempID = (_gd->mapJungle->mapID[k].idMap[xMap][yMap]) % puissance;
								if (tempID != 0)
								{
									tempID = puissance % tempID;
								}
								else
								{
									transform--;
								}
								_gd->mapJungle->mapID[k].needRotate[xMap][yMap] = sfTrue;
							}
							else if (_gd->mapJungle->mapID[k].idMap[xMap][yMap] > 100000)
							{
								transform = (_gd->mapJungle->mapID[k].idMap[xMap][yMap] / puissance) + 4;
								tempID = (((_gd->mapJungle->mapID[k].idMap[xMap][yMap]) % puissance));
								_gd->mapJungle->mapID[k].needRotate[xMap][yMap] = sfTrue;
							}
							//collum
							rectText.left = tempID % _gd->mapJungle->columns * rectText.height;
							//ligne
							rectText.top = tempID / _gd->mapJungle->columns * rectText.width;
							sfVector2f scale = { 1,1 };
							sfVector2f posTransform = { 0,0 };
							float angle = 0;
							if (_gd->mapJungle->mapID[k].needRotate[xMap][yMap] == sfTrue)
							{
								RotationSpriteSheet(&scale, &posTransform, &angle, transform);
							}
							sfSprite_setTextureRect(_gd->spriteJungle, rectText);
							if (UpperUnderPlayer(_gd->mapJungle->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0
								&& strstr(_gd->mapJungle->mapID[k].name, "Light") == NULL)
							{
								BlitSprite(_gd->spriteJungle, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
									(yMap * rectText.height) - _gd->cam.y + posTransform.y, angle, scale.x, scale.y, _gd);
							}
						}
						//pour les calques avec des animations dessus 
						for (int i = 0; i < _gd->mapJungle->nbAnimSprite; i++)
						{
							int tempID = -1;
							if (_gd->mapJungle->mapID[k].idMap[xMap][yMap] != _gd->mapJungle->animTiled.id[i])
							{
								if (_gd->mapJungle->mapID[k].idMap[xMap][yMap] < -1)
								{
									transform = (_gd->mapJungle->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
									tempID = (_gd->mapJungle->mapID[k].idMap[xMap][yMap]) % puissance;
									if (tempID != 0)
									{
										tempID = puissance % tempID;
									}
									else
									{
										transform--;
									}
								}
								else if (_gd->mapJungle->mapID[k].idMap[xMap][yMap] > -1)
								{
									transform = (_gd->mapJungle->mapID[k].idMap[xMap][yMap] / puissance) + 4;
									tempID = (((_gd->mapJungle->mapID[k].idMap[xMap][yMap]) % puissance));
								}
								_gd->mapJungle->animTiled.needRotate[i] = sfTrue;
							}
							if ((_gd->mapJungle->mapID[k].idMap[xMap][yMap] == _gd->mapJungle->animTiled.id[i]
								|| tempID == _gd->mapJungle->animTiled.id[i])
								&& strstr(_gd->mapJungle->mapID[k].name, "Light") == NULL)
							{
								sfVector2f scale = { 1,1 };
								sfVector2f posTransform = { 0,0 };
								float angle = 0;
								rectText.left = _gd->mapJungle->animTiled.spriteAnim[i].id[_gd->mapJungle->animTiled.spriteAnim[i].currentAnim] % _gd->mapJungle->columns * rectText.width;
								rectText.top = _gd->mapJungle->animTiled.spriteAnim[i].id[_gd->mapJungle->animTiled.spriteAnim[i].currentAnim] / _gd->mapJungle->columns * rectText.height;
								if (tempID == _gd->mapJungle->animTiled.id[i]
									&& _gd->mapJungle->animTiled.needRotate[i] == sfTrue)
								{
									RotationSpriteSheet(&scale, &posTransform, &angle, transform);
								}
								sfSprite_setTextureRect(_gd->spriteJungle, rectText);
								if (UpperUnderPlayer(_gd->mapJungle->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0
									&& (strcmp(_gd->mapJungle->mapID[k].name, "Coffre_upper")))
								{
									BlitSprite(_gd->spriteJungle, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
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
	/*for (int i = 0; i < _gd->mapJungle->nbCollision; i++)
	{
		sfVector2f scale = { _gd->mapJungle->mapCollision[i].size.x / 32,_gd->mapJungle->mapCollision[i].size.y / 32 };
		BlitSprite(_gd->blockColli, _gd->mapJungle->mapCollision[i].pos.x - _gd->cam.x, _gd->mapJungle->mapCollision[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd->window);
	}*/

	//for (int i = 0; i < _gd->mapJungle->nbInteraction; i++)
	//{
	//	sfVector2f scale = { _gd->mapJungle->mapInteraction[i].size.x / 32,_gd->mapJungle->mapInteraction[i].size.y / 32 };

	//	BlitSprite(_gd->blockInterac, _gd->mapJungle->mapInteraction[i].pos.x - _gd->cam.x, _gd->mapJungle->mapInteraction[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd->window);
	//}

	/*for (int i = 0; i < _gd->mapJungle->nbDestructible; i++)
	{
		if (_gd->mapJungle->mapDestructible[i].recup == sfFalse)
		{
			sfVector2f scale = { _gd->mapJungle->mapDestructible[i].size.x / 32,_gd->mapJungle->mapDestructible[i].size.y / 32 };
			BlitSprite(_gd->blockDestruc, _gd->mapJungle->mapDestructible[i].pos.x - _gd->cam.x, _gd->mapJungle->mapDestructible[i].pos.y - _gd->cam.y, 0, scale.x, scale.y, _gd);
		}
	}*/
	}

	//pôur pnj
	/*for (int i = 0; i < _gd->mapJungle->nbNPC; i++)
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
	}*/
}

void DisplayJungleMapUpper(GameData* _gd)
{
	int transform = 0;
	int puissance = pow(2, 29);
	sfVector2f camCell = ScreenToWorld(_gd->cam.x, _gd->cam.y);
	sfVector2f camCellMax = { camCell.x + (SCREEN_WIDTH / SIZECELL), camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1 };
	sfIntRect rectText;
	rectText.width = _gd->mapJungle->tilewitdh;
	rectText.height = _gd->mapJungle->tileheight;
	for (int k = 0; k < _gd->mapJungle->nbCalque; k++)
	{
		//if ((strstr(_gd->mapJungle->mapID[k].name, "Beam") != NULL))
		//{
		//	//DisplayBeamJungle(_gd, k);
		//}
		//else
		if (strstr(_gd->mapJungle->mapID[k].name, "upper") != NULL)
		{
			for (int yMap = camCell.y; yMap <= camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1; yMap++)
			{
				for (int xMap = camCell.x; xMap <= camCell.x + (SCREEN_WIDTH / SIZECELL); xMap++)
				{
					if (IsCellAvailable(yMap, xMap, _gd->mapJungle->witdh, _gd->mapJungle->height));
					{
						//pour les calque normaux 
						{
							int tempID = _gd->mapJungle->mapID[k].idMap[xMap][yMap];
							if (_gd->mapJungle->mapID[k].idMap[xMap][yMap] < -1)
							{
								transform = (_gd->mapJungle->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
								tempID = (_gd->mapJungle->mapID[k].idMap[xMap][yMap]) % puissance;
								if (tempID != 0)
								{
									tempID = puissance % tempID;
								}
								else
								{
									transform--;
								}
								_gd->mapJungle->mapID[k].needRotate[xMap][yMap] = sfTrue;
							}
							else if (_gd->mapJungle->mapID[k].idMap[xMap][yMap] > 100000)
							{
								transform = (_gd->mapJungle->mapID[k].idMap[xMap][yMap] / puissance) + 4;
								tempID = (((_gd->mapJungle->mapID[k].idMap[xMap][yMap]) % puissance));
								_gd->mapJungle->mapID[k].needRotate[xMap][yMap] = sfTrue;
							}
							//collum
							rectText.left = tempID % _gd->mapJungle->columns * rectText.height;
							//ligne
							rectText.top = tempID / _gd->mapJungle->columns * rectText.width;
							sfVector2f scale = { 1,1 };
							sfVector2f posTransform = { 0,0 };
							float angle = 0;
							if (_gd->mapJungle->mapID[k].needRotate[xMap][yMap] == sfTrue)
							{
								RotationSpriteSheet(&scale, &posTransform, &angle, transform);
							}
							sfSprite_setTextureRect(_gd->spriteJungle, rectText);
							if (UpperOnPlayer(_gd->mapJungle->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0
								&& strstr(_gd->mapJungle->mapID[k].name, "Light") == NULL
								)
							{
								BlitSprite(_gd->spriteJungle, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
									(yMap * rectText.height) - _gd->cam.y + posTransform.y, angle, scale.x, scale.y, _gd);
							}
						}
						////pour les calques avec des animations dessus 
						for (int i = 0; i < _gd->mapJungle->nbAnimSprite; i++)
						{
							int tempID = -1;
							if (_gd->mapJungle->mapID[k].idMap[xMap][yMap] != _gd->mapJungle->animTiled.id[i])
							{
								if (_gd->mapJungle->mapID[k].idMap[xMap][yMap] < -1)
								{
									transform = (_gd->mapJungle->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
									tempID = (_gd->mapJungle->mapID[k].idMap[xMap][yMap]) % puissance;
									if (tempID != 0)
									{
										tempID = puissance % tempID;
									}
									else
									{
										transform--;
									}
								}
								else if (_gd->mapJungle->mapID[k].idMap[xMap][yMap] > -1)
								{
									transform = (_gd->mapJungle->mapID[k].idMap[xMap][yMap] / puissance) + 4;
									tempID = (((_gd->mapJungle->mapID[k].idMap[xMap][yMap]) % puissance));
								}
								_gd->mapJungle->animTiled.needRotate[i] = sfTrue;
							}
							if ((_gd->mapJungle->mapID[k].idMap[xMap][yMap] == _gd->mapJungle->animTiled.id[i]
								|| tempID == _gd->mapJungle->animTiled.id[i])
								&& strstr(_gd->mapJungle->mapID[k].name, "Light") == NULL
								)
							{
								sfVector2f scale = { 1,1 };
								sfVector2f posTransform = { 0,0 };
								float angle = 0;
								rectText.left = _gd->mapJungle->animTiled.spriteAnim[i].id[_gd->mapJungle->animTiled.spriteAnim[i].currentAnim] % _gd->mapJungle->columns * rectText.width;
								rectText.top = _gd->mapJungle->animTiled.spriteAnim[i].id[_gd->mapJungle->animTiled.spriteAnim[i].currentAnim] / _gd->mapJungle->columns * rectText.height;
								if (tempID == _gd->mapJungle->animTiled.id[i]
									&& _gd->mapJungle->animTiled.needRotate[i] == sfTrue)
								{
									RotationSpriteSheet(&scale, &posTransform, &angle, transform);
								}
								sfSprite_setTextureRect(_gd->spriteJungle, rectText);
								if (UpperOnPlayer(_gd->mapJungle->mapID[k].name, _gd->player.pos.y, yMap * rectText.height) != 0)
								{
									BlitSprite(_gd->spriteJungle, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
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
	for (int k = 0; k < _gd->mapJungle->nbCalque; k++)
	{
		if (strstr(_gd->mapJungle->mapID[k].name, "Light") != NULL)
		{
			for (int yMap = camCell.y; yMap <= camCell.y + (SCREEN_HEIGHT / SIZECELL) + 1; yMap++)
			{
				for (int xMap = camCell.x; xMap <= camCell.x + (SCREEN_WIDTH / SIZECELL); xMap++)
				{
					if (IsCellAvailable(yMap, xMap, _gd->mapJungle->height, _gd->mapJungle->witdh));
					{
						{
							int tempID = _gd->mapJungle->mapID[k].idMap[xMap][yMap];
							if (_gd->mapJungle->mapID[k].idMap[xMap][yMap] < -1)
							{
								transform = (_gd->mapJungle->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
								tempID = (_gd->mapJungle->mapID[k].idMap[xMap][yMap]) % puissance;
								if (tempID != 0)
								{
									tempID = puissance % tempID;
								}
								else
								{
									transform--;
								}
								_gd->mapJungle->mapID[k].needRotate[xMap][yMap] = sfTrue;
							}
							else if (_gd->mapJungle->mapID[k].idMap[xMap][yMap] > 100000)
							{
								transform = (_gd->mapJungle->mapID[k].idMap[xMap][yMap] / puissance) + 4;
								tempID = (((_gd->mapJungle->mapID[k].idMap[xMap][yMap]) % puissance));
								_gd->mapJungle->mapID[k].needRotate[xMap][yMap] = sfTrue;
							}
							//collum
							rectText.left = tempID % _gd->mapJungle->columns * rectText.height;
							//ligne
							rectText.top = tempID / _gd->mapJungle->columns * rectText.width;
							sfVector2f scale = { 1,1 };
							sfVector2f posTransform = { 0,0 };
							float angle = 0;
							if (_gd->mapJungle->mapID[k].needRotate[xMap][yMap] == sfTrue)
							{
								RotationSpriteSheet(&scale, &posTransform, &angle, transform);
							}
							sfSprite_setTextureRect(_gd->spriteJungle, rectText);
							{
								BlitSprite(_gd->spriteJungle, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
									(yMap * rectText.height) - _gd->cam.y + posTransform.y, angle, scale.x, scale.y, _gd);
							}
						}

						for (int i = 0; i < _gd->mapJungle->nbAnimSprite; i++)
						{
							int tempID = -1;
							if (_gd->mapJungle->mapID[k].idMap[xMap][yMap] != _gd->mapJungle->animTiled.id[i])
							{
								if (_gd->mapJungle->mapID[k].idMap[xMap][yMap] < -1)
								{
									transform = (_gd->mapJungle->mapID[k].idMap[xMap][yMap] / puissance) * -1 + 1;
									tempID = (_gd->mapJungle->mapID[k].idMap[xMap][yMap]) % puissance;
									if (tempID != 0)
									{
										tempID = puissance % tempID;
									}
									else
									{
										transform--;
									}
								}
								else if (_gd->mapJungle->mapID[k].idMap[xMap][yMap] > -1)
								{
									transform = (_gd->mapJungle->mapID[k].idMap[xMap][yMap] / puissance) + 4;
									tempID = (((_gd->mapJungle->mapID[k].idMap[xMap][yMap]) % puissance));
								}
								_gd->mapJungle->animTiled.needRotate[i] = sfTrue;
							}
							if ((_gd->mapJungle->mapID[k].idMap[xMap][yMap] == _gd->mapJungle->animTiled.id[i]
								|| tempID == _gd->mapJungle->animTiled.id[i]))
							{
								sfVector2f scale = { 1,1 };
								sfVector2f posTransform = { 0,0 };
								float angle = 0;
								rectText.left = _gd->mapJungle->animTiled.spriteAnim[i].id[_gd->mapJungle->animTiled.spriteAnim[i].currentAnim] % _gd->mapJungle->columns * rectText.width;
								rectText.top = _gd->mapJungle->animTiled.spriteAnim[i].id[_gd->mapJungle->animTiled.spriteAnim[i].currentAnim] / _gd->mapJungle->columns * rectText.height;
								if (tempID == _gd->mapJungle->animTiled.id[i]
									&& _gd->mapJungle->animTiled.needRotate[i] == sfTrue)
								{
									RotationSpriteSheet(&scale, &posTransform, &angle, transform);
								}
								sfSprite_setTextureRect(_gd->spriteJungle, rectText);
								{
									BlitSprite(_gd->spriteJungle, (xMap * rectText.width) - _gd->cam.x + posTransform.x,
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
