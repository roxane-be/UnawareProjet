#include "DisplayTutoDiode.h"

void DisplayTutoDiode(GameData* _gd)
{
	BlitSprite(_gd->enigme.interupteur.backgroundDiode, 0, 0, 0, 1, 1, _gd);

	if (_gd->enigme.interupteur.interupteurState == tutoDiode)
	{
		BlitSprite(_gd->enigme.interupteur.backgroundTutoDiode3x3, 0, -10, 0, 1, 1, _gd);
	}
	else if (_gd->enigme.interupteur.interupteurState == symboleDiode)
	{
		BlitSprite(_gd->enigme.interupteur.backgroundTutoDiodeSymbole, 0, -10, 0, 1, 1, _gd);

		BlitSprite(_gd->enigme.interupteur.symboleButtonDiodeTuto.buttonSprite[0], _gd->enigme.interupteur.symboleButtonDiodeTuto.pos.x - 25,
			_gd->enigme.interupteur.symboleButtonDiodeTuto.pos.y - 50, 0, 1, 1, _gd);

		if (_gd->enigme.interupteur.onSpriteSymboleButtonDiodeTuto == sfTrue)
		{
			BlitSprite(_gd->enigme.interupteur.symboleButtonDiodeTuto.buttonSprite[1], _gd->enigme.interupteur.symboleButtonDiodeTuto.pos.x - 50,
				_gd->enigme.interupteur.symboleButtonDiodeTuto.pos.y - 70, 0, 1, 1, _gd);
		}
		if (_gd->enigme.interupteur.clickSymboleButtonDiodeTuto == sfTrue)
		{
			BlitSprite(_gd->enigme.interupteur.symboleButtonDiodeTuto.buttonSprite[2], _gd->enigme.interupteur.symboleButtonDiodeTuto.pos.x - 25,
				_gd->enigme.interupteur.symboleButtonDiodeTuto.pos.y - 50, 0, 1, 1, _gd);
		}

		//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.interupteur.symboleButtonDiodeTuto.forme, NULL);
	}
	else if (_gd->enigme.interupteur.interupteurState == fullDiode)
	{
		BlitSprite(_gd->enigme.interupteur.backgroundTutoDiodeFin, 0, -10, 0, 1, 1, _gd);
	}

	BlitSprite(_gd->enigme.interupteur.retourButtonDiode.buttonSprite[0], _gd->enigme.interupteur.retourButtonDiode.pos.x - 40,
		_gd->enigme.interupteur.retourButtonDiode.pos.y - 40, 0, 1, 1, _gd);

	if (_gd->enigme.interupteur.onSpriteRetourButtonDiode == sfTrue)
	{
		BlitSprite(_gd->enigme.interupteur.retourButtonDiode.buttonSprite[1], _gd->enigme.interupteur.retourButtonDiode.pos.x - 40,
			_gd->enigme.interupteur.retourButtonDiode.pos.y - 40, 0, 1, 1, _gd);
	}
	if (_gd->enigme.interupteur.clickRetourButtonDiode == sfTrue)
	{
		BlitSprite(_gd->enigme.interupteur.retourButtonDiode.buttonSprite[2], _gd->enigme.interupteur.retourButtonDiode.pos.x - 40,
			_gd->enigme.interupteur.retourButtonDiode.pos.y - 40, 0, 1, 1, _gd);
	}

	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.interupteur.retourButtonDiode.forme, NULL);
}