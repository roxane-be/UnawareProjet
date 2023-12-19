#include "UpdateDiode.h"

void UpdateButtonJungle(GameData* _gd)
{
	sfVector2i posMouseI = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f posMouseF = { posMouseI.x, posMouseI.y };

	if (isCollidingWithMouse(_gd->enigme.interupteur.helpButtonDiode3x3.forme, posMouseF, 0))
	{
		_gd->enigme.interupteur.onSpriteHelpButtonDiode3x3 = sfTrue;
	}
	else
	{
		_gd->enigme.interupteur.onSpriteHelpButtonDiode3x3 = sfFalse;
	}

	if (isCollidingWithMouse(_gd->enigme.interupteur.helpButtonDiodeSymbole.forme, posMouseF, 0))
	{
		_gd->enigme.interupteur.onSpriteHelpButtonDiodeSymbole = sfTrue;
	}
	else
	{
		_gd->enigme.interupteur.onSpriteHelpButtonDiodeSymbole = sfFalse;
	}

	if (isCollidingWithMouse(_gd->enigme.interupteur.symboleButtonDiode.forme, posMouseF, 0))
	{
		_gd->enigme.interupteur.onSpriteSymboleButtonDiode = sfTrue;
	}
	else
	{
		_gd->enigme.interupteur.onSpriteSymboleButtonDiode = sfFalse;
	}

	if (isCollidingWithMouse(_gd->enigme.interupteur.helpButtonDiodeFin.forme, posMouseF, 0))
	{
		_gd->enigme.interupteur.onSpriteHelpButtonDiodeFin = sfTrue;
	}
	else
	{
		_gd->enigme.interupteur.onSpriteHelpButtonDiodeFin = sfFalse;
	}

	if (isCollidingWithMouse(_gd->enigme.interupteur.validateButtonDiode.forme, posMouseF, 0))
	{
		_gd->enigme.interupteur.onSpriteValidateButtonDiode = sfTrue;
	}
	else
	{
		_gd->enigme.interupteur.onSpriteValidateButtonDiode = sfFalse;
	}

	if (isCollidingWithMouse(_gd->enigme.interupteur.quitButtonDiode.forme, posMouseF, 0))
	{
		_gd->enigme.interupteur.onSpriteQuitButtonDiode = sfTrue;
	}
	else
	{
		_gd->enigme.interupteur.onSpriteQuitButtonDiode = sfFalse;
	}

	if (isCollidingWithMouse(_gd->enigme.interupteur.resetButtonDiode.forme, posMouseF, 0))
	{
		_gd->enigme.interupteur.onSpriteResetButtonDiode = sfTrue;
	}
	else
	{
		_gd->enigme.interupteur.onSpriteResetButtonDiode = sfFalse;
	}
}