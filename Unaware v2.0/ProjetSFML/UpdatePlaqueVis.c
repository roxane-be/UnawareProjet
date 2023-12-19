#include "UpdatePlaqueVis.h"

void UpdatePlaqueVisBox(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f mousePos2f;
	mousePos2f.x = (float)mousePos.x;
	mousePos2f.y = (float)mousePos.y;

	if (isCollidingWithMouse(_gd->utilityPieceBoite.helpButtonBox.forme, mousePos2f, 0))
	{
		_gd->utilityPieceBoite.onSpriteHelpButtonBox = sfTrue;
	}
	else
	{
		_gd->utilityPieceBoite.onSpriteHelpButtonBox = sfFalse;
	}

	if (_gd->utilityPieceBoite.isSelected == sfTrue)
	{
		sfRectangleShape_setPosition(_gd->visPiece[_gd->identifiantVis].forme, mousePos2f);
	}

	if (_gd->utilityPieceBoite.countVis == 0
		&& _gd->utilityPieceBoite.resolvedDream_1 == sfFalse
		&& sfSound_getStatus(_gd->utilityPieceBoite.unscrewSound.sound) == 0)
	{
		if (_gd->utilityPieceBoite.plateSound.isPlaying == 0)
		{
			sfSound_play(_gd->utilityPieceBoite.plateSound.sound);
			_gd->utilityPieceBoite.plateSound.isPlaying = 1;
		}

		_gd->utilityPieceBoite.plaqueOuverte = sfTrue;
	}

	if (_gd->utilityPieceBoite.cableRecup == sfTrue)
	{
		_gd->inGameState = enigme;
		_gd->enigmeState = cableBox;
		_gd->utilityPieceBoite.resolvedDream_1 = sfTrue;
		_gd->utilityPieceBoite.cableRecup = sfFalse;
	}

}