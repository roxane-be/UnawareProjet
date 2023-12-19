#include "UpdateJungleMap.h"

void UpdateJungleMap(GameData* _gd)
{
	for (int i = 0; i < _gd->mapJungle->nbAnimSprite; i++)
	{
		_gd->mapJungle->animTiled.spriteAnim[i].currentTime += _gd->frameRate.dt;
		if (_gd->mapJungle->animTiled.spriteAnim[i].currentTime
			>= _gd->mapJungle->animTiled.spriteAnim[i].ttl[_gd->mapJungle->animTiled.spriteAnim[i].currentAnim] / 1000)
		{
			_gd->mapJungle->animTiled.spriteAnim[i].currentAnim++;
			_gd->mapJungle->animTiled.spriteAnim[i].currentTime = 0;
			if (_gd->mapJungle->animTiled.spriteAnim[i].currentAnim >= _gd->mapJungle->animTiled.spriteAnim[i].nbImageInAnim)
			{
				_gd->mapJungle->animTiled.spriteAnim[i].currentAnim = 0;
			}
		}
	}

	{
		_gd->currentTimeFourmi += _gd->frameRate.dt;
		if (_gd->currentTimeFourmi >= 0.1f)
		{
			_gd->currentTimeFourmi = 0;
			_gd->currentAnimFourmi++;
			if (_gd->currentAnimFourmi > 15)
			{
				_gd->currentAnimFourmi = 0;
			}
		}
		/*float totalTime = _gd->fourmi.npcDef.sequence[_gd->fourmi.idSeq].total;
		int start = _gd->fourmi.npcDef.sequence[_gd->fourmi.idSeq].begin;
		int end = _gd->fourmi.npcDef.sequence[_gd->fourmi.idSeq].end;
		int nbAnim = 1 + (end - start);
		while (_gd->fourmi.currentTime >= totalTime)
		{
			_gd->fourmi.currentTime -= totalTime;
		}
		_gd->fourmi.currentAnim = nbAnim * _gd->fourmi.currentTime / totalTime + start;*/
	}


	if (_gd->inTp == sfTrue && _gd->CoffreGood == sfTrue
		&& _gd->CoffreGoodOpen == sfFalse)
	{
		_gd->player.interaction = sfFalse;
		_gd->timeAnimCoffre += _gd->frameRate.dt;
		if (_gd->timeAnimCoffre >= 0.6f)
		{
			_gd->AnimCurrentCoffre++;
			_gd->timeAnimCoffre = 0;
			if (_gd->AnimCurrentCoffre - 48 == 5)
			{
				_gd->inTp = sfFalse;
				_gd->CoffreGoodOpen = sfTrue;
				_gd->AnimCurrentCoffre = 48;
				sfSound_stop(_gd->musicLaby[_gd->currentColor].sound);
				_gd->player.pos.x = _gd->mapJungle->mapPoint[2].pos.x;
				_gd->player.pos.y = _gd->mapJungle->mapPoint[2].pos.y;
			}
		}
	}
	else if (_gd->inTp == sfFalse && _gd->CoffreGood == sfFalse)
	{
		
		_gd->timeAnimCoffre += _gd->frameRate.dt;
		if (_gd->timeAnimCoffre >= 0.6f)
		{
			_gd->AnimCurrentCoffre++;
			_gd->timeAnimCoffre = 0;
			if (_gd->AnimCurrentCoffre - 48 == 4)
			{
				_gd->AnimCurrentCoffre = 48;
			}
		}
	}
	else if (_gd->inTp == sfTrue && _gd->CoffreWrong == sfTrue
		&& _gd->CoffreWrongOpen == sfFalse)
	{
		_gd->player.interaction = sfFalse;
		_gd->timeAnimCoffre += _gd->frameRate.dt;
		if (_gd->timeAnimCoffre >= 0.6f)
		{
			_gd->AnimCurrentCoffre++;
			_gd->timeAnimCoffre = 0;
			if (_gd->AnimCurrentCoffre - 48 == 8)
			{
				_gd->player.pos.x = _gd->mapJungle->mapPoint[1].pos.x;
				_gd->player.pos.y = _gd->mapJungle->mapPoint[1].pos.y;
				_gd->inTp = sfFalse;
				_gd->CoffreWrongOpen = sfTrue;
				_gd->AnimCurrentCoffre = 48;
				sfSound_setVolume(_gd->musicLaby[_gd->currentColor].sound, 0);
				sfSound_stop(_gd->musicLaby[_gd->currentColor].sound);
				strcpy(_gd->player.stepName, "rouge");
				_gd->currentColor = red;
				_gd->lastColor = red;
				_gd->musicLaby[red].volume = 100/*_gd->soundGlobal * _gd->soundAmbiance*/;
				sfSound_setVolume(_gd->musicLaby[red].sound, _gd->musicLaby[red].volume);
				sfSound_play(_gd->musicLaby[red].sound);
				_gd->musicLaby[blue].volume = 0;
				sfSound_setVolume(_gd->musicLaby[blue].sound, _gd->musicLaby[blue].volume);
				_gd->musicLaby[green].volume = 0;
				sfSound_setVolume(_gd->musicLaby[green].sound, _gd->musicLaby[green].volume);
				_gd->musicLaby[yellow].volume = 0;
				sfSound_setVolume(_gd->musicLaby[yellow].sound, _gd->musicLaby[yellow].volume);
			}
		}
	}
	else if (_gd->inTp == sfFalse && _gd->CoffreWrong == sfFalse)
	{
		_gd->timeAnimCoffre += _gd->frameRate.dt;
		if (_gd->timeAnimCoffre >= 0.6f)
		{
			_gd->AnimCurrentCoffre++;
			_gd->timeAnimCoffre = 0;
			if (_gd->AnimCurrentCoffre - 48 == 4)
			{
				_gd->AnimCurrentCoffre = 48;
			}
		}
	}
	else if (_gd->inTp == sfTrue && _gd->inFourmiTp ==sfTrue)
	{
		_gd->currentinFourmiTp += _gd->frameRate.dt;
		_gd->player.interaction = sfFalse;

		if (_gd->currentinFourmiTp >= 2.f)
		{
			_gd->currentinFourmiTp = 0;
			_gd->inTp = sfFalse;
			_gd->inFourmiTp = sfFalse;
			_gd->player.pos.x = _gd->mapJungle->mapPoint[1].pos.x;
			_gd->player.pos.y = _gd->mapJungle->mapPoint[1].pos.y;
			sfSound_setVolume(_gd->musicLaby[_gd->currentColor].sound, 0);
			sfSound_stop(_gd->musicLaby[_gd->currentColor].sound);
			strcpy(_gd->player.stepName, "rouge");
			_gd->currentColor = red;
			_gd->lastColor = red;
			_gd->musicLaby[red].volume = 100/*_gd->soundGlobal * _gd->soundAmbiance*/;
			sfSound_setVolume(_gd->musicLaby[red].sound, _gd->musicLaby[red].volume);
			sfSound_play(_gd->musicLaby[red].sound);
			_gd->musicLaby[blue].volume = 0;
			sfSound_setVolume(_gd->musicLaby[blue].sound, _gd->musicLaby[blue].volume);
			_gd->musicLaby[green].volume = 0;
			sfSound_setVolume(_gd->musicLaby[green].sound, _gd->musicLaby[green].volume);
			_gd->musicLaby[yellow].volume = 0;
			sfSound_setVolume(_gd->musicLaby[yellow].sound, _gd->musicLaby[yellow].volume);
		}
	}
	else if (_gd->inTp == sfTrue && _gd->inGrenouilleTp == sfTrue)
	{
	_gd->currentTimeGrenouille += _gd->frameRate.dt;
	_gd->player.interaction = sfFalse;

	if (_gd->currentTimeGrenouille >= 2.f)
	{
		_gd->inTp = sfFalse;
		_gd->inGrenouilleTp = sfFalse;
		_gd->player.pos.x = _gd->mapJungle->mapPoint[1].pos.x;
		_gd->player.pos.y = _gd->mapJungle->mapPoint[1].pos.y;
		sfSound_setVolume(_gd->musicLaby[_gd->currentColor].sound, 0);
		sfSound_stop(_gd->musicLaby[_gd->currentColor].sound);
		strcpy(_gd->player.stepName, "rouge");
		_gd->currentColor = red;
		_gd->lastColor = red;
		_gd->musicLaby[red].volume = 100/*_gd->soundGlobal * _gd->soundAmbiance*/;
		sfSound_setVolume(_gd->musicLaby[red].sound, _gd->musicLaby[red].volume);
		sfSound_play(_gd->musicLaby[red].sound);
		_gd->musicLaby[blue].volume = 0;
		sfSound_setVolume(_gd->musicLaby[blue].sound, _gd->musicLaby[blue].volume);
		_gd->musicLaby[green].volume = 0;
		sfSound_setVolume(_gd->musicLaby[green].sound, _gd->musicLaby[green].volume);
		_gd->musicLaby[yellow].volume = 0;
		sfSound_setVolume(_gd->musicLaby[yellow].sound, _gd->musicLaby[yellow].volume);
	}
	}
}

void UpdateLabyrinth(GameData* _gd)
{
	if (sfSound_getVolume(_gd->musicLaby[_gd->currentColor].sound) < 100 && sfSound_getVolume(_gd->musicLaby[_gd->lastColor].sound) > 0)
	{
		_gd->musicLaby[_gd->lastColor].volume -= 1;
		_gd->musicLaby[_gd->currentColor].volume += 1;
		sfSound_setVolume(_gd->musicLaby[_gd->lastColor].sound, _gd->musicLaby[_gd->lastColor].volume);
		sfSound_setVolume(_gd->musicLaby[_gd->currentColor].sound, _gd->musicLaby[_gd->currentColor].volume);
	}

}