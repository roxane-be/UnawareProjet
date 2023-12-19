#include "UpdateIA.h"

void UpdateTextIA(GameData* _gd, IAState _whereTalk)
{
	char stringDraw[999];
	sprintf(stringDraw, "%s", _gd->ia_ship.sentenceIA[_whereTalk]);
	sfText_setString(_gd->texts.ia_voice.text, stringDraw);
}

void UpdateTimingIAIntro(GameData* _gd)
{
	if (_gd->ia_ship.actif == sfTrue)
	{
		_gd->ia_ship.timerText += 0.01f;

		if (_gd->ia_ship.timerText >= 2.f)
		{
			_gd->ia_ship.actif = sfFalse;
		}
	}
	else
	{
		_gd->ia_ship.timerText = 0.f;
	}
}
void UpdateTimingIABedRoom(GameData* _gd)
{
	if (_gd->ia_ship.actif == sfTrue)
	{
		_gd->ia_ship.timerText += 0.01f;

		if (_gd->ia_ship.timerText >= 3.5f)
		{
			_gd->ia_ship.actif = sfFalse;
		}
	}
	else
	{
		_gd->ia_ship.timerText = 0.f;
	}
}

void UpdateTimingIABedEnd(GameData* _gd)
{
	if (_gd->ia_ship.actif == sfTrue)
	{
		_gd->ia_ship.timerText += 0.01f;

		if (_gd->ia_ship.timerText >= 3.5f)
		{
			_gd->ia_ship.actif = sfFalse;
		}
	}
	else
	{
		_gd->ia_ship.timerText = 0.f;
	}
}