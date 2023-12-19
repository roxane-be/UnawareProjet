#include "UpdateShipEndMap.h"

void UpdateShipEndMap(GameData* _gd)
{
	for (int i = 0; i < _gd->mapShipEnd->nbAnimSprite; i++)
	{
		_gd->mapShipEnd->animTiled.spriteAnim[i].currentTime += _gd->frameRate.dt;
		if (_gd->mapShipEnd->animTiled.spriteAnim[i].currentTime
			>= _gd->mapShipEnd->animTiled.spriteAnim[i].ttl[_gd->mapShipEnd->animTiled.spriteAnim[i].currentAnim] / 1000)
		{
			_gd->mapShipEnd->animTiled.spriteAnim[i].currentAnim++;
			_gd->mapShipEnd->animTiled.spriteAnim[i].currentTime = 0;
			if (_gd->mapShipEnd->animTiled.spriteAnim[i].currentAnim >= _gd->mapShipEnd->animTiled.spriteAnim[i].nbImageInAnim)
			{
				_gd->mapShipEnd->animTiled.spriteAnim[i].currentAnim = 0;
			}
		}
	}
}