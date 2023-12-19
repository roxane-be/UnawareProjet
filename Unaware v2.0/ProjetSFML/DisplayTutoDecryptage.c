#include "DisplayTutoDecryptage.h"

void DisplayTutoDecryptage(GameData* _gd)
{
	BlitSprite(_gd->enigme.decryptage.backgroundDecryptage, 0, 0, 0, 1, 1, _gd);

	for (int i = 0; i < 9; i++)
	{
		if (_gd->enigme.decryptage.isVisible[i] == sfTrue)
		{
			BlitSprite(_gd->enigme.decryptage.backgroundPapier[i], 1135, 0, 0, 1, 1, _gd);
		}

	}

	BlitSprite(_gd->enigme.decryptage.backgroundTutoDecryptage, 0, 0, 0, 1, 1, _gd);

	BlitSprite(_gd->enigme.decryptage.retourDecryptage.buttonSprite[0], _gd->enigme.decryptage.retourDecryptage.pos.x, _gd->enigme.decryptage.retourDecryptage.pos.y,
		0, 1, 1, _gd);

	if (_gd->enigme.decryptage.onSpriteRetourDecryptage == sfTrue
		&& _gd->enigme.decryptage.clickRetourDecryptage == sfFalse)
	{
		BlitSprite(_gd->enigme.decryptage.retourDecryptage.buttonSprite[1], _gd->enigme.decryptage.retourDecryptage.pos.x, _gd->enigme.decryptage.retourDecryptage.pos.y,
			0, 1, 1, _gd);
	}
	if (_gd->enigme.decryptage.clickRetourDecryptage == sfTrue)
	{
		BlitSprite(_gd->enigme.decryptage.retourDecryptage.buttonSprite[2], _gd->enigme.decryptage.retourDecryptage.pos.x, _gd->enigme.decryptage.retourDecryptage.pos.y,
			0, 1, 1, _gd);
	}

	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->enigme.decryptage.retourDecryptage.forme, NULL);
}