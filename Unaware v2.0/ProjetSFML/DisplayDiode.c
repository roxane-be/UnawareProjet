#include "DisplayDiode.h"

void DisplayHelpButtonDiode(GameData* _gd)
{
	if (_gd->enigme.interupteur.interupteurState == tutoDiode)
	{
		BlitSprite(_gd->enigme.interupteur.helpButtonDiode3x3.buttonSprite[0], _gd->enigme.interupteur.helpButtonDiode3x3.pos.x - 50,
			_gd->enigme.interupteur.helpButtonDiode3x3.pos.y - 75, 0, 1, 1, _gd);

		if (_gd->enigme.interupteur.onSpriteHelpButtonDiode3x3 == sfTrue)
		{
			BlitSprite(_gd->enigme.interupteur.helpButtonDiode3x3.buttonSprite[1], _gd->enigme.interupteur.helpButtonDiode3x3.pos.x - 50,
				_gd->enigme.interupteur.helpButtonDiode3x3.pos.y - 75, 0, 1, 1, _gd);
		}
		if (_gd->enigme.interupteur.clickHelpButtonDiode3x3 == sfTrue)
		{
			BlitSprite(_gd->enigme.interupteur.helpButtonDiode3x3.buttonSprite[2], _gd->enigme.interupteur.helpButtonDiode3x3.pos.x - 50,
				_gd->enigme.interupteur.helpButtonDiode3x3.pos.y - 75, 0, 1, 1, _gd);
		}

		//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.interupteur.helpButtonDiode3x3.forme, NULL);
	}
	else if (_gd->enigme.interupteur.interupteurState == symboleDiode)
	{
		BlitSprite(_gd->enigme.interupteur.helpButtonDiodeSymbole.buttonSprite[0], _gd->enigme.interupteur.helpButtonDiodeSymbole.pos.x - 60,
			_gd->enigme.interupteur.helpButtonDiodeSymbole.pos.y - 75, 0, 1, 1, _gd);

		BlitSprite(_gd->enigme.interupteur.symboleButtonDiode.buttonSprite[0], _gd->enigme.interupteur.symboleButtonDiode.pos.x - 25,
			_gd->enigme.interupteur.symboleButtonDiode.pos.y - 50, 0, 1, 1, _gd);

		if (_gd->enigme.interupteur.onSpriteHelpButtonDiodeSymbole == sfTrue)
		{
			BlitSprite(_gd->enigme.interupteur.helpButtonDiodeSymbole.buttonSprite[1], _gd->enigme.interupteur.helpButtonDiodeSymbole.pos.x - 60,
				_gd->enigme.interupteur.helpButtonDiodeSymbole.pos.y - 75, 0, 1, 1, _gd);
		}
		if (_gd->enigme.interupteur.onSpriteSymboleButtonDiode == sfTrue)
		{
			BlitSprite(_gd->enigme.interupteur.symboleButtonDiode.buttonSprite[1], _gd->enigme.interupteur.symboleButtonDiode.pos.x - 50,
				_gd->enigme.interupteur.symboleButtonDiode.pos.y - 70, 0, 1, 1, _gd);
		}

		if (_gd->enigme.interupteur.clickHelpButtonDiodeSymbole == sfTrue)
		{
			BlitSprite(_gd->enigme.interupteur.helpButtonDiodeSymbole.buttonSprite[2], _gd->enigme.interupteur.helpButtonDiodeSymbole.pos.x - 60,
				_gd->enigme.interupteur.helpButtonDiodeSymbole.pos.y - 75, 0, 1, 1, _gd);
		}
		if (_gd->enigme.interupteur.clickSymboleButtonDiode == sfTrue)
		{
			BlitSprite(_gd->enigme.interupteur.symboleButtonDiode.buttonSprite[2], _gd->enigme.interupteur.symboleButtonDiode.pos.x - 25,
				_gd->enigme.interupteur.symboleButtonDiode.pos.y - 50, 0, 1, 1, _gd);
		}

		//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.interupteur.helpButtonDiodeSymbole.forme, NULL);
		//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.interupteur.symboleButtonDiode.forme, NULL);
	}
	else if (_gd->enigme.interupteur.interupteurState == fullDiode)
	{
		BlitSprite(_gd->enigme.interupteur.helpButtonDiodeFin.buttonSprite[0], _gd->enigme.interupteur.helpButtonDiodeFin.pos.x - 50,
			_gd->enigme.interupteur.helpButtonDiodeSymbole.pos.y - 75, 0, 1, 1, _gd);

		if (_gd->enigme.interupteur.onSpriteHelpButtonDiodeFin == sfTrue)
		{
			BlitSprite(_gd->enigme.interupteur.helpButtonDiodeFin.buttonSprite[1], _gd->enigme.interupteur.helpButtonDiodeFin.pos.x - 50,
				_gd->enigme.interupteur.helpButtonDiodeFin.pos.y - 75, 0, 1, 1, _gd);
		}
		if (_gd->enigme.interupteur.clickHelpButtonDiodeFin == sfTrue)
		{
			BlitSprite(_gd->enigme.interupteur.helpButtonDiodeFin.buttonSprite[2], _gd->enigme.interupteur.helpButtonDiodeFin.pos.x - 50,
				_gd->enigme.interupteur.helpButtonDiodeFin.pos.y - 75, 0, 1, 1, _gd);
		}
		//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.interupteur.helpButtonDiodeFin.forme, NULL);
	}
}

void DisplayButton(GameData* _gd)
{
	//bouton Valider
	BlitSprite(_gd->enigme.interupteur.validateButtonDiode.buttonSprite[0], _gd->enigme.interupteur.validateButtonDiode.pos.x - 50,
		_gd->enigme.interupteur.validateButtonDiode.pos.y - 50, 0, 1, 1, _gd);

	if (_gd->enigme.interupteur.onSpriteValidateButtonDiode == sfTrue)
	{
		BlitSprite(_gd->enigme.interupteur.validateButtonDiode.buttonSprite[1], _gd->enigme.interupteur.validateButtonDiode.pos.x - 50,
			_gd->enigme.interupteur.validateButtonDiode.pos.y - 50, 0, 1, 1, _gd);
	}
	if (_gd->enigme.interupteur.clickValidateButtonDiode == sfTrue)
	{
		BlitSprite(_gd->enigme.interupteur.validateButtonDiode.buttonSprite[2], _gd->enigme.interupteur.validateButtonDiode.pos.x - 50,
			_gd->enigme.interupteur.validateButtonDiode.pos.y - 50, 0, 1, 1, _gd);
	}

	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.interupteur.validateButtonDiode.forme, NULL);

	//bouton Quitter
	BlitSprite(_gd->enigme.interupteur.quitButtonDiode.buttonSprite[0], _gd->enigme.interupteur.quitButtonDiode.pos.x - 20,
		_gd->enigme.interupteur.quitButtonDiode.pos.y, 0, 1, 1, _gd);

	if (_gd->enigme.interupteur.onSpriteQuitButtonDiode == sfTrue)
	{
		BlitSprite(_gd->enigme.interupteur.quitButtonDiode.buttonSprite[1], _gd->enigme.interupteur.quitButtonDiode.pos.x - 20,
			_gd->enigme.interupteur.quitButtonDiode.pos.y, 0, 1, 1, _gd);
	}
	if (_gd->enigme.interupteur.clickQuitButtonDiode == sfTrue)
	{
		BlitSprite(_gd->enigme.interupteur.quitButtonDiode.buttonSprite[2], _gd->enigme.interupteur.quitButtonDiode.pos.x - 20,
			_gd->enigme.interupteur.quitButtonDiode.pos.y, 0, 1, 1, _gd);
	}

	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.interupteur.quitButtonDiode.forme, NULL);

	//bouton reset
	BlitSprite(_gd->enigme.interupteur.resetButtonDiode.buttonSprite[0], _gd->enigme.interupteur.resetButtonDiode.pos.x - 30,
		_gd->enigme.interupteur.resetButtonDiode.pos.y - 50, 0, 1, 1, _gd);

	if (_gd->enigme.interupteur.onSpriteResetButtonDiode == sfTrue)
	{
		BlitSprite(_gd->enigme.interupteur.resetButtonDiode.buttonSprite[1], _gd->enigme.interupteur.resetButtonDiode.pos.x - 30,
			_gd->enigme.interupteur.resetButtonDiode.pos.y - 50, 0, 1, 1, _gd);
	}
	if (_gd->enigme.interupteur.clickResetButtonDiode == sfTrue)
	{
		BlitSprite(_gd->enigme.interupteur.resetButtonDiode.buttonSprite[2], _gd->enigme.interupteur.resetButtonDiode.pos.x - 30,
			_gd->enigme.interupteur.resetButtonDiode.pos.y - 50, 0, 1, 1, _gd);
	}

	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.interupteur.resetButtonDiode.forme, NULL);
}

void DisplayDiode(GameData* _gd)
{
	BlitSprite(_gd->enigme.interupteur.backgroundDiode, 0, 0, 0, 1, 1, _gd);

	for (int i = 0; i < _gd->enigme.interupteur.sizeTab.x; i++)
	{
		for (int j = 0; j < _gd->enigme.interupteur.sizeTab.y; j++)
		{

			sfVector2f scale = { 1,1 };
			if (_gd->enigme.interupteur.interupteurState == tutoDiode)
			{
				scale.x = 1;
				scale.y = 1;

			}
			else if (_gd->enigme.interupteur.interupteurState == symboleDiode)
			{
				scale.x = 0.9;
				scale.y = 0.9;

			}
			else if (_gd->enigme.interupteur.interupteurState == fullDiode)
			{
				scale.x = 0.7;
				scale.y = 0.7;
			}

			if (_gd->enigme.interupteur.etat[i][j] == on)
			{
				BlitSprite(_gd->enigme.interupteur.spriteOn, _gd->enigme.interupteur.pos[i][j].x /** i + 70*/,
					_gd->enigme.interupteur.pos[i][j].y /** j + 250*/, 0, scale.x, scale.y, _gd);
				//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.interupteur.rectInterupteur[i][j], NULL);
			}
			else if (_gd->enigme.interupteur.etat[i][j] == off)
			{
				BlitSprite(_gd->enigme.interupteur.spriteOff, _gd->enigme.interupteur.pos[i][j].x /** i + 700*/,
					_gd->enigme.interupteur.pos[i][j].y /*+ j + 200*/, 0, scale.x, scale.y, _gd);
				//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.interupteur.rectInterupteur[i][j], NULL);
			}
		}
	}

	DisplayHelpButtonDiode(_gd);
	DisplayButton(_gd);




}