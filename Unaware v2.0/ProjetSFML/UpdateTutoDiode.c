#include "UpdateTutoDiode.h"

void UpdateTutoDiodeJungle(GameData* _gd)
{
	sfVector2i posMouseI = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouseF = { posMouseI.x, posMouseI.y };

	//A rajouter les differents bouton retour

	if (isCollidingWithMouse(_gd->enigme.interupteur.retourButtonDiode.forme, posMouseF, 0))
	{
		_gd->enigme.interupteur.onSpriteRetourButtonDiode = sfTrue;
	}
	else
	{
		_gd->enigme.interupteur.onSpriteRetourButtonDiode = sfFalse;
	}

	if (_gd->enigme.interupteur.interupteurState == symboleDiode)
	{
		if (isCollidingWithMouse(_gd->enigme.interupteur.symboleButtonDiodeTuto.forme, posMouseF, 0))
		{
			_gd->enigme.interupteur.onSpriteSymboleButtonDiodeTuto = sfTrue;
		}
		else
		{
			_gd->enigme.interupteur.onSpriteSymboleButtonDiodeTuto = sfFalse;
		}
	}


}