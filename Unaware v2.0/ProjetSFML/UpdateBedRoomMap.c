#include "UpdateBedRoomMap.h"

void UpdateBedRoomMap(GameData* _gd)
{
	for (int i = 0; i < _gd->mapBedRoom->nbAnimSprite; i++)
	{
		_gd->mapBedRoom->animTiled.spriteAnim[i].currentTime += _gd->frameRate.dt;
		if (_gd->mapBedRoom->animTiled.spriteAnim[i].currentTime
			>= (_gd->mapBedRoom->animTiled.spriteAnim[i].ttl[_gd->mapBedRoom->animTiled.spriteAnim[i].currentAnim]) / 1000)
		{
			_gd->mapBedRoom->animTiled.spriteAnim[i].currentAnim++;
			_gd->mapBedRoom->animTiled.spriteAnim[i].currentTime = 0;
			if (_gd->mapBedRoom->animTiled.spriteAnim[i].currentAnim >= _gd->mapBedRoom->animTiled.spriteAnim[i].nbImageInAnim)
			{
				_gd->mapBedRoom->animTiled.spriteAnim[i].currentAnim = 0;
			}
		}

	}
}