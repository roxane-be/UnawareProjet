#include "DisplayCutScene.h"

void CutSceneTools(GameData* _gd, sfSprite* _sprite[], int _nbImage, float _seconde, int _zoom, int _opacity)
{
	_gd->cinematique.currentTime += _gd->frameRate.dt;
	float tempTaille = 1.0f / _gd->cinematique.pos.z;

	BlitSprite(_sprite[_gd->cinematique.currentAnim], _gd->cinematique.pos.x, _gd->cinematique.pos.y, 0, tempTaille, tempTaille, _gd);

	if (_gd->cinematique.currentTime > _seconde)
	{
		_gd->cinematique.currentTime = 0;
		_gd->cinematique.currentAnim++;
		_gd->cinematique.pos.z = 0.9;
		_gd->cinematique.opacity = 0;
	}

}
//cas =0 -> no opacity
//cas = 1 -> opacity begin
//cas = 2 -> opacity end 
//cas = 3 -> opacity begin and end
void CutSceneToolsOpacity(GameData* _gd, int _opacity, sfSprite* _sprite[], int _cas, float _timeBegin, float _timeEnd)
{


	switch (_cas)
	{
	case 1:
		if (_gd->cinematique.opacity < 255
			&& _gd->cinematique.currentTime < _timeBegin)
		{
			_gd->cinematique.opacity += _opacity;
			sfColor temp = { 255,255,255,_gd->cinematique.opacity };
			sfSprite_setColor(_sprite[_gd->cinematique.currentAnim], temp);
		}
		break;

	case 2:
		if (_gd->cinematique.opacity > 0
			&& _gd->cinematique.currentTime > _timeEnd)
		{
			_gd->cinematique.opacity -= _opacity;
			sfColor temp = { 255,255,255,_gd->cinematique.opacity };
			sfSprite_setColor(_sprite[_gd->cinematique.currentAnim], temp);
		}

		break;
	case 3:
		if (_gd->cinematique.opacity > 0
			&& _gd->cinematique.currentTime > _timeEnd)
		{
			_gd->cinematique.opacity -= _opacity;
			sfColor temp = { 255,255,255,_gd->cinematique.opacity };
			sfSprite_setColor(_sprite[_gd->cinematique.currentAnim], temp);
		}
		else if (_gd->cinematique.opacity < 255
			&& _gd->cinematique.currentTime < _timeBegin)
		{
			_gd->cinematique.opacity += _opacity;
			sfColor temp = { 255,255,255,_gd->cinematique.opacity };
			sfSprite_setColor(_sprite[_gd->cinematique.currentAnim], temp);
		}
		break;
	default:
		break;
	}
}


void DisplayCutSceneIntro(GameData* _gd)
{
	int zoom = 0;
	int opacity = 1;
	float time;
	BlitSprite(_gd->cinematique.blackScreen, _gd->cinematique.pos.x, _gd->cinematique.pos.y, 0, 1, 1, _gd);
	switch (_gd->world)
	{
	case intro:

		switch (_gd->cutSceneState)
		{
		case vaisseauIntro:
			if (_gd->cinematique.currentAnim == NB_CUTSCENE_SHIP_INTRO - 1)
			{
				if (_gd->cinematique.currentTime == 0)
				{
					_gd->cinematique.pos.z = 1;
				}
				_gd->cinematique.pos.z -= 0.00030;
			}
			else if (_gd->cinematique.currentAnim == 1)
			{
				_gd->cinematique.pos.z += 0.00025;
			}

			CutSceneToolsOpacity(_gd, 5, _gd->cinematique.shipIntro, 3, 1, TIME_SHIP_INTRO_0 - 1);
			CutSceneTools(_gd, _gd->cinematique.shipIntro, NB_CUTSCENE_SHIP_INTRO, TIME_SHIP_INTRO_0, zoom, opacity);

			break;
		case vaisseauOpenDoor:
			if (_gd->cinematique.currentTime == 0)
			{
				_gd->cinematique.pos.z = 1;
			}
			if (_gd->cinematique.currentTime == 0
				&& _gd->cinematique.currentAnim == NB_CUTSCENE_SHIP_DOOR - 1)
			{
				_gd->cinematique.opacity = 255;
			}
			if (_gd->cinematique.currentAnim == NB_CUTSCENE_SHIP_DOOR - 1)
			{
				CutSceneToolsOpacity(_gd, 5, _gd->cinematique.shipDoor, 2, 0.3f, 0.3f);
				_gd->cinematique.pos.z -= 0.00050f;
			}
			CutSceneTools(_gd, _gd->cinematique.shipDoor, NB_CUTSCENE_SHIP_DOOR, TIME_SHIP_DOOR, zoom, opacity);
			break;
		case vaisseauSleep:
			if (_gd->cinematique.currentTime == 0)
			{
				_gd->cinematique.pos.z = 1;
			}
			if (_gd->cinematique.currentAnim == NB_CUTSCENE_SHIP_SLEEP - 1)
			{
				CutSceneToolsOpacity(_gd, 5, _gd->cinematique.shipSleep, 3, 1, TIME_SHIP_SLEEP - 1);

			}
			else
			{
				_gd->cinematique.pos.z -= 0.00012f;
			}
			CutSceneTools(_gd, _gd->cinematique.shipSleep, NB_CUTSCENE_SHIP_SLEEP, TIME_SHIP_SLEEP, zoom, opacity);
			break;


		default:
			break;
		}
		break;
	default:
		break;
	}

}

void DisplayCutSceneIsland(GameData* _gd)
{
	int zoom = 0;
	int opacity = 1;
	float time;
	BlitSprite(_gd->cinematique.blackScreen, _gd->cinematique.pos.x, _gd->cinematique.pos.y, 0, 1, 1, _gd);
	switch (_gd->world)
	{
	case island:
		switch (_gd->cutSceneState)
		{
		case islandIntro:
			if (_gd->cinematique.currentTime == 0)
			{
				_gd->cinematique.pos.z = 0.9;
			}
			_gd->cinematique.pos.z += 0.00012f;
			CutSceneTools(_gd, _gd->cinematique.IslandIntro, NB_CUTSCENE_ISLAND_INTRO, TIME_ISLAND_INTRO, zoom, opacity);

			break;
		case islandLeaveHouse:

			if (_gd->cinematique.exitHouse == sfFalse)
			{
				if (_gd->cinematique.currentTime == 0)
				{
					_gd->cinematique.pos.z = 1;
					_gd->cinematique.opacity = 255;

				}
				_gd->cinematique.pos.z -= 0.00012f;

				if (_gd->cinematique.currentAnim == NB_CUTSCENE_ISLAND_LEAVE_HOUSE - 1)
				{
					CutSceneToolsOpacity(_gd, 5, _gd->cinematique.IslandLeaveHouse, 2, 1, TIME_ISLAND_LEAVE_HOUSE - 1);
				}

				CutSceneTools(_gd, _gd->cinematique.IslandLeaveHouse, NB_CUTSCENE_ISLAND_LEAVE_HOUSE, TIME_ISLAND_LEAVE_HOUSE, zoom, opacity);
			}
			break;
		case islandPont:
			if (_gd->cinematique.currentAnim == 1)
			{
				_gd->cinematique.pos.z += 0.00025;
			}
			else
			{
				_gd->cinematique.pos.z -= 0.00025;
			}
			if (_gd->cinematique.currentAnim == 0 &&
				_gd->cinematique.currentTime > 2)
			{
				_gd->cinematique.currentTime = 0;
				_gd->cinematique.currentAnim++;
				_gd->cinematique.pos.z = 0.95;
				_gd->cinematique.opacity = 0;
			}
			else if (_gd->cinematique.currentAnim == 2 &&
				_gd->cinematique.currentTime == 0)
			{
				_gd->cinematique.pos.z = 1;
			}
			CutSceneToolsOpacity(_gd, 5, _gd->cinematique.IslandPont, 3, 1, TIME_ISLAND_PONT - 1);
			CutSceneTools(_gd, _gd->cinematique.IslandPont, NB_CUTSCENE_ISLAND_PONT, TIME_ISLAND_PONT, zoom, opacity);
			break;
		case islandDialogue:
			time = 0.8;
			if (_gd->cinematique.currentTime == 0
				&& _gd->cinematique.currentAnim > 0)
			{
				_gd->cinematique.pos.z = 0.95;
				_gd->cinematique.opacity = 255;
			}
			else if (_gd->cinematique.currentAnim == 0)
			{
				_gd->cinematique.pos.z = 1;
			}
			if (_gd->cinematique.currentAnim == NB_CUTSCENE_ISLAND_DIALOGUE - 1)
			{
				_gd->cinematique.pos.z += 0.0002f;
				time = 4;
				CutSceneToolsOpacity(_gd, 5, _gd->cinematique.IslandDialogue, 2, 0, 3.2);
			}
			CutSceneTools(_gd, _gd->cinematique.IslandDialogue, NB_CUTSCENE_ISLAND_DIALOGUE, time, zoom, opacity);
			break;
		case islandEnd:
			time = TIME_ISLAND_END;
			_gd->cinematique.pos.z = 1;
			if (_gd->cinematique.currentAnim == NB_CUTSCENE_ISLAND_END - 1)
			{
				CutSceneToolsOpacity(_gd, 15, _gd->cinematique.IslandEnd, 3, 0.3, 0.3);
				time = 0.6;
			}
			CutSceneTools(_gd, _gd->cinematique.IslandEnd, NB_CUTSCENE_ISLAND_END, time, zoom, opacity);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void DisplayCutSceneBedRoom(GameData* _gd)
{
	int zoom = 0;
	int opacity = 1;
	BlitSprite(_gd->cinematique.blackScreen, _gd->cinematique.pos.x, _gd->cinematique.pos.y, 0, 1, 1, _gd);
	switch (_gd->world)
	{
	case bedroom:
		switch (_gd->cutSceneState)
		{
		case bedRoomIntro:
			if (_gd->cinematique.currentTime == 0)
			{
				_gd->cinematique.pos.z = 1;
			}
			if (_gd->cinematique.currentTime == 0
				&& _gd->cinematique.currentAnim == 1)
			{
				_gd->cinematique.pos.z = 0.95;
			}
			if (_gd->cinematique.currentAnim == 1)
			{
				_gd->cinematique.pos.z += 0.00015f;
			}
			CutSceneTools(_gd, _gd->cinematique.BedRoomIntro, NB_CUTSCENE_BEDROOM_INTRO, TIME_BEDROOM_INTRO, zoom, opacity);
			break;
		case bedRoomExit:
			CutSceneToolsOpacity(_gd, 5, _gd->cinematique.BedRoomExit, 3, 1, TIME_BEDROOM_EXIT - 1);
			CutSceneTools(_gd, _gd->cinematique.BedRoomExit, NB_CUTSCENE_BEDROOM_EXIT, TIME_BEDROOM_EXIT, zoom, opacity);
			break;
		}
		break;
	default:
		break;
	}
}

void DisplayCutSceneJungle(GameData* _gd)
{
	int zoom = 0;
	int opacity = 1;
	float time;
	BlitSprite(_gd->cinematique.blackScreen, _gd->cinematique.pos.x, _gd->cinematique.pos.y, 0, 1, 1, _gd);
	switch (_gd->world)
	{
	case jungle:
		switch (_gd->cutSceneState)
		{
		case JungleEnd:
			_gd->cinematique.pos.z = 1;
			if (_gd->cinematique.currentTime == 0)
			{
				_gd->cinematique.opacity = 255;
			}

			CutSceneTools(_gd, _gd->cinematique.JungleEnd, NB_CUTSCENE_JUNGLE_END, TIME_CUTSCENE_JUNGLE_END, zoom, opacity);
			break;
		case JungleReveil:
			CutSceneToolsOpacity(_gd, 5, _gd->cinematique.JungleReveil, 3, 1, TIME_CUTSCENE_JUNGLE_REVEIL - 1);
			CutSceneTools(_gd, _gd->cinematique.JungleReveil, NB_CUTSCENE_JUNGLE_REVEIL, TIME_CUTSCENE_JUNGLE_REVEIL, zoom, opacity);
			break;
		}
		break;
	}
}

void DisplayCutSceneShipEnd(GameData* _gd)
{
	int zoom = 0;
	int opacity = 1;
	float time;
	BlitSprite(_gd->cinematique.blackScreen, _gd->cinematique.pos.x, _gd->cinematique.pos.y, 0, 1, 1, _gd);
	switch (_gd->world)
	{
	case shipEnd:
		switch (_gd->cutSceneState)
		{
		case EndReveil:
			if (_gd->cinematique.currentTime == 0)
			{
				_gd->cinematique.pos.z = 0.9f;

			}

			_gd->cinematique.pos.z += 0.00012f;

			time = TIME_CUTSCENE_END_REVEIL;
			if (_gd->cinematique.currentAnim == 0)
			{
				CutSceneToolsOpacity(_gd, 15, _gd->cinematique.EndReveil, 3, 0.3, 0.3);
				time = 0.6;
			}
			else
			{
				CutSceneToolsOpacity(_gd, 5, _gd->cinematique.EndReveil, 3, 1, time - 1);
			}
			CutSceneTools(_gd, _gd->cinematique.EndReveil, NB_CUTSCENE_END_REVEIL, time, zoom, opacity);
			break;
		case EndCasque:
			_gd->cinematique.pos.z = 1;
			if (_gd->cinematique.currentTime == 0)
			{
				_gd->cinematique.opacity = 255;
			}
			if (_gd->cinematique.currentAnim == NB_CUTSCENE_END_CASQUE - 1)
			{
				CutSceneToolsOpacity(_gd, 5, _gd->cinematique.EndCasque, 2, 0.3, 0.5);

			}
			CutSceneTools(_gd, _gd->cinematique.EndCasque, NB_CUTSCENE_END_CASQUE, TIME_CUTSCENE_END_CASQUE, zoom, opacity);
			break;
		case EndEnd:
			time = TIME_CUTSCENE_END_END;
			if (_gd->cinematique.currentTime == 0)
			{
				_gd->cinematique.pos.z = 1;
			}
			if (_gd->cinematique.currentTime == 0 && _gd->cinematique.currentAnim == 3)
			{
				_gd->cinematique.pos.z += 0.9f;

			}
			if (_gd->cinematique.currentAnim == NB_CUTSCENE_END_END - 3)
			{
				_gd->cinematique.pos.z += 0.0002f;

			}
			if (_gd->cinematique.currentAnim == NB_CUTSCENE_END_END - 2)
			{
				_gd->cinematique.pos.z -= 0.0002f;
				BlitSprite(_gd->terre, 0, 0, 0, 1, 1, _gd);
			}
			if (_gd->cinematique.currentAnim == NB_CUTSCENE_END_END - 1
				&& _gd->cinematique.currentTime == 0)
			{
				_gd->cinematique.pos.x = 0;
				_gd->cinematique.pos.y = 0;
			}
			if (_gd->cinematique.currentAnim == NB_CUTSCENE_END_END - 1)
			{
				_gd->cinematique.pos.y -= 0.8f;
				time = 110;//100
				BlitSprite(_gd->fondCredit, 0, 0, 0, 1, 1, _gd);
			}
			CutSceneToolsOpacity(_gd, 5, _gd->cinematique.EndEnd, 3, 1, time - 1);

			CutSceneTools(_gd, _gd->cinematique.EndEnd, NB_CUTSCENE_END_END, time, zoom, opacity);


			break;
		}
		break;
	}
}

void DisplayCutSceneFail(GameData* _gd)
{
	int zoom = 0;
	int opacity = 1;
	float time;
	BlitSprite(_gd->cinematique.blackScreen, _gd->cinematique.pos.x, _gd->cinematique.pos.y, 0, 1, 1, _gd);
	switch (_gd->world)
	{
	case intro:
		switch (_gd->cutSceneState)
		{
		case fail:
			time = TIME_FAIL;
			_gd->cinematique.pos.z = 1;
			if (_gd->cinematique.currentAnim == 0)
			{
				CutSceneToolsOpacity(_gd, 15, _gd->cinematique.Fail, 3, 0.3, 0.3);
				time = 0.6;
			}
			CutSceneTools(_gd, _gd->cinematique.Fail, NB_CUTSCENE_FAIL, time, zoom, opacity);
			break;
		default:
			break;
		}
		break;
	case bedroom:
		switch (_gd->cutSceneState)
		{
		case fail:
			time = TIME_FAIL;
			_gd->cinematique.pos.z = 1;
			if (_gd->cinematique.currentAnim == 0)
			{
				CutSceneToolsOpacity(_gd, 15, _gd->cinematique.Fail, 3, 0.3, 0.3);
				time = 0.6;
			}

			CutSceneTools(_gd, _gd->cinematique.Fail, NB_CUTSCENE_FAIL, time, zoom, opacity);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}