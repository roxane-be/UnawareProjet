#include "DisplayDecryptage.h"

void DisplayButtonDecryptage(GameData* _gd)
{
	//bouton valider
	BlitSprite(_gd->enigme.decryptage.validateDecryptage.buttonSprite[0], _gd->enigme.decryptage.validateDecryptage.pos.x - 25,
		_gd->enigme.decryptage.validateDecryptage.pos.y - 20, 0, 1, 1, _gd);

	if (_gd->enigme.decryptage.onSpriteValidateDecryptage == sfTrue
		&& _gd->enigme.decryptage.clickValidateDecryptage == sfFalse)
	{
		BlitSprite(_gd->enigme.decryptage.validateDecryptage.buttonSprite[1], _gd->enigme.decryptage.validateDecryptage.pos.x - 25,
			_gd->enigme.decryptage.validateDecryptage.pos.y - 20, 0, 1, 1, _gd);
	}
	if (_gd->enigme.decryptage.clickValidateDecryptage == sfTrue)
	{
		BlitSprite(_gd->enigme.decryptage.validateDecryptage.buttonSprite[2], _gd->enigme.decryptage.validateDecryptage.pos.x - 25,
			_gd->enigme.decryptage.validateDecryptage.pos.y - 20, 0, 1, 1, _gd);
	}
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.decryptage.validateDecryptage.forme, NULL);

	//bouton reset
	BlitSprite(_gd->enigme.decryptage.resetDecryptage.buttonSprite[0], _gd->enigme.decryptage.resetDecryptage.pos.x - 25,
		_gd->enigme.decryptage.resetDecryptage.pos.y - 20, 0, 1, 1, _gd);

	if (_gd->enigme.decryptage.onSpriteResetDecryptage == sfTrue
		&& _gd->enigme.decryptage.clickResetDecryptage == sfFalse)
	{
		BlitSprite(_gd->enigme.decryptage.resetDecryptage.buttonSprite[1], _gd->enigme.decryptage.resetDecryptage.pos.x - 25,
			_gd->enigme.decryptage.resetDecryptage.pos.y - 20, 0, 1, 1, _gd);
	}
	if (_gd->enigme.decryptage.clickResetDecryptage == sfTrue)
	{
		BlitSprite(_gd->enigme.decryptage.resetDecryptage.buttonSprite[2], _gd->enigme.decryptage.resetDecryptage.pos.x - 25,
			_gd->enigme.decryptage.resetDecryptage.pos.y - 20, 0, 1, 1, _gd);
	}
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.decryptage.resetDecryptage.forme, NULL);

	//bouton quitter
	BlitSprite(_gd->enigme.decryptage.quitDecryptage.buttonSprite[0], _gd->enigme.decryptage.quitDecryptage.pos.x - 25,
		_gd->enigme.decryptage.quitDecryptage.pos.y - 20, 0, 1, 1, _gd);

	if (_gd->enigme.decryptage.onSpriteQuitDecryptage == sfTrue
		&& _gd->enigme.decryptage.clickQuitDecryptage == sfFalse)
	{
		BlitSprite(_gd->enigme.decryptage.quitDecryptage.buttonSprite[1], _gd->enigme.decryptage.quitDecryptage.pos.x - 25,
			_gd->enigme.decryptage.quitDecryptage.pos.y - 20, 0, 1, 1, _gd);
	}
	if (_gd->enigme.decryptage.clickQuitDecryptage == sfTrue)
	{
		BlitSprite(_gd->enigme.decryptage.quitDecryptage.buttonSprite[2], _gd->enigme.decryptage.quitDecryptage.pos.x - 25,
			_gd->enigme.decryptage.quitDecryptage.pos.y - 20, 0, 1, 1, _gd);
	}
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.decryptage.quitDecryptage.forme, NULL);

	//bouton aide
	BlitSprite(_gd->enigme.decryptage.aideDecryptage.buttonSprite[0], _gd->enigme.decryptage.aideDecryptage.pos.x - 25,
		_gd->enigme.decryptage.aideDecryptage.pos.y - 20, 0, 1, 1, _gd);

	if (_gd->enigme.decryptage.onSpriteAideDecryptage == sfTrue
		&& _gd->enigme.decryptage.clickAideDecryptage == sfFalse)
	{
		BlitSprite(_gd->enigme.decryptage.aideDecryptage.buttonSprite[1], _gd->enigme.decryptage.aideDecryptage.pos.x - 25,
			_gd->enigme.decryptage.aideDecryptage.pos.y - 20, 0, 1, 1, _gd);
	}
	if (_gd->enigme.decryptage.clickAideDecryptage == sfTrue)
	{
		BlitSprite(_gd->enigme.decryptage.aideDecryptage.buttonSprite[2], _gd->enigme.decryptage.aideDecryptage.pos.x - 25,
			_gd->enigme.decryptage.aideDecryptage.pos.y - 20, 0, 1, 1, _gd);
	}
	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.decryptage.aideDecryptage.forme, NULL);
}

void DisplayDecryptage(GameData* _gd)
{
	BlitSprite(_gd->enigme.decryptage.backgroundDecryptage, 0, 0, 0, 1, 1, _gd);

	for (int i = 0; i < 9; i++)
	{
		if (_gd->enigme.decryptage.isVisible[i] == sfTrue)
		{
			BlitSprite(_gd->enigme.decryptage.backgroundPapier[i], 1135, 0, 0, 1, 1, _gd);
		}

	}

	sfVector2f scale = { 1,1 };
	DisplayButtonDecryptage(_gd);
	BlitText(_gd->enigme.decryptage.text, _gd->enigme.decryptage.pos.x, _gd->enigme.decryptage.pos.y, sfBlack, scale, _gd->window);

}