#include "UpdateTimer.h"

void UpdateTimerIsland(GameData* _gd)
{
	_gd->timer.timerTotal -= _gd->frameRate.dt;
	_gd->timer.timerMin = (int)(_gd->timer.timerTotal / 60);
	_gd->timer.timerSec = _gd->timer.timerTotal - _gd->timer.timerMin * 60;

		//A modifier avec nouvelle map
	if (_gd->timer.timerTotal <= 0.f)
	{
		sfSound_stop(_gd->player.stepSound.sound);
		_gd->inGameState = cutscene;
		_gd->cutSceneState = fail;
		_gd->world = intro;
		_gd->enigmeState = none;
		_gd->failDream = sfTrue;
		_gd->inDream = sfFalse;
		InitCutScene(_gd);
		InitSoundAmbience(_gd);
	}
}

void UpdateTimerJungle(GameData* _gd)
{
	_gd->timer.timerTotal -= _gd->frameRate.dt;
	_gd->timer.timerMin = (int)(_gd->timer.timerTotal / 60);
	_gd->timer.timerSec = _gd->timer.timerTotal - _gd->timer.timerMin * 60;

	//A modifier avec nouvelle map
	if (_gd->timer.timerTotal <= 0.f)
	{
		sfSound_stop(_gd->player.stepSound.sound);
		_gd->inGameState = cutscene;
		_gd->cutSceneState = fail;
		_gd->world = bedroom;
		_gd->enigmeState = none;
		_gd->failDream = sfTrue;
		_gd->inDream = sfFalse;
		InitCutScene(_gd);
		InitSoundAmbience(_gd);

	}
}