#include "UpdateIslandMap.h"

void UpdateIslandMap(GameData* _gd)
{
	for (int i = 0; i < _gd->mapIsland->nbAnimSprite; i++)
	{
		_gd->mapIsland->animTiled.spriteAnim[i].currentTime += _gd->frameRate.dt;
		if (_gd->mapIsland->animTiled.spriteAnim[i].currentTime
			>= _gd->mapIsland->animTiled.spriteAnim[i].ttl[_gd->mapIsland->animTiled.spriteAnim[i].currentAnim] / 1000)
		{
			_gd->mapIsland->animTiled.spriteAnim[i].currentAnim++;
			_gd->mapIsland->animTiled.spriteAnim[i].currentTime = 0;
			if (_gd->mapIsland->animTiled.spriteAnim[i].currentAnim >= _gd->mapIsland->animTiled.spriteAnim[i].nbImageInAnim)
			{
				_gd->mapIsland->animTiled.spriteAnim[i].currentAnim = 0;
			}
		}
	}
}