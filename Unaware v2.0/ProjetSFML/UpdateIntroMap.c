#include "UpdateIntroMap.h"

void UpdateIntroMap(GameData* _gd)
{
	for (int i = 0; i < _gd->mapIntro->nbAnimSprite; i++)
	{
		_gd->mapIntro->animTiled.spriteAnim[i].currentTime += _gd->frameRate.dt;
		if (_gd->mapIntro->animTiled.spriteAnim[i].currentTime
			>= (_gd->mapIntro->animTiled.spriteAnim[i].ttl[_gd->mapIntro->animTiled.spriteAnim[i].currentAnim]) / 1000)
		{
			_gd->mapIntro->animTiled.spriteAnim[i].currentAnim++;
			_gd->mapIntro->animTiled.spriteAnim[i].currentTime = 0;
			if (_gd->mapIntro->animTiled.spriteAnim[i].currentAnim >= _gd->mapIntro->animTiled.spriteAnim[i].nbImageInAnim)
			{
				_gd->mapIntro->animTiled.spriteAnim[i].currentAnim = 0;
			}
		}

	}
}

