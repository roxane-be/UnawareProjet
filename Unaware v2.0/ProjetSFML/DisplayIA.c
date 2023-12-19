#include "DisplayIA.h"

void DisplayIA(GameData* _gd)
{
	switch (_gd->world)
	{
	case intro:
		if (_gd->ia_ship.actif == sfTrue)
		{
			BlitSprite(_gd->ia_ship.dialogueBox, _gd->sizeWindow.width / 2 - 230, 800, 0, 0.8, 0.8, _gd);

			BlitText(_gd->texts.ia_voice.text,
				_gd->texts.ia_voice.pos.x,
				_gd->texts.ia_voice.pos.y,
				sfBlack, (sfVector2f) { 1, 1 }, _gd->window);
		}
		break;
	case bedroom:
		if (_gd->ia_ship.actif == sfTrue)
		{
			BlitSprite(_gd->ia_ship.dialogueBox, _gd->sizeWindow.width / 2 - 230, 800, 0, 0.8, 0.8, _gd);

			BlitText(_gd->texts.ia_voice.text,
				_gd->texts.ia_voice.pos.x,
				_gd->texts.ia_voice.pos.y - 45,
				sfBlack, (sfVector2f) { 1, 1 }, _gd->window);
		}
		break;
	case shipEnd:
		if (_gd->ia_ship.actif == sfTrue)
		{
			BlitSprite(_gd->ia_ship.dialogueBox, _gd->sizeWindow.width / 2 - 230, 800, 0, 0.8, 0.8, _gd);

			BlitText(_gd->texts.ia_voice.text,
				_gd->texts.ia_voice.pos.x,
				_gd->texts.ia_voice.pos.y - 45,
				sfBlack, (sfVector2f) { 1, 1 }, _gd->window);
		}
		break;
	default:
		break;
	}

}