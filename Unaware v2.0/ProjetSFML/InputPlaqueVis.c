#include "InputPlaqueVis.h"

void InputPlaqueVisBox(GameData* _gd)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_gd->window);
	sfVector2f mousePos2f;
	mousePos2f.x = (float)mousePos.x;
	mousePos2f.y = (float)mousePos.y;

	if (_gd->event.type == sfEvtMouseButtonPressed)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft
			&& _gd->utilityPieceBoite.isSelected == sfFalse) //Si clic gauche et que la variable de selection est a "faux"
		{
			_gd->identifiantVis = -1; //On initialise la variable d'identification a -1.

			for (int i = 0; i < NB_PIECES_BOITE * 2; i++) //Au clique gauche, on parcourt la liste des pieces disponible...
			{
				if (isCollidingWithMouse(_gd->visPiece[i].forme, mousePos2f, 1) //...et on verifie si y'a une collision entre la souris et une des pieces.
					&& _gd->visPiece[i].isPosed == 0)
				{
					sfSound_play(_gd->utilityPieceBoite.pickUpCoinSound.sound);
					_gd->identifiantVis = _gd->visPiece[i].identifiant; //Si y'a une collision, on attribue l'identifiant de la piece qui est en collision a la variable d'identification...
					_gd->utilityPieceBoite.isSelected = sfTrue; //...et on met la variable de selection a "vrai"

				}
			}
		}
		else if (_gd->event.mouseButton.button == sfMouseLeft
			&& _gd->utilityPieceBoite.isSelected == sfTrue) //Si clic gauche et que la variable de selection est a "vrai"
		{
			if (IsCollidingRectangleRectangle(_gd->visPiece[_gd->identifiantVis].forme, _gd->visCadre[_gd->identifiantVis].forme)//On verifie si y'a une collision entre la vis selectionnée...
				&& _gd->visPiece[_gd->identifiantVis].identifiant == _gd->visCadre[_gd->identifiantVis].identifiant)//...et la vis du cadre, et egalement que les 2 identifiants soit les memes.
			{
				sfSound_play(_gd->utilityPieceBoite.unscrewSound.sound);
				//sfRectangleShape_setPosition(_gd->visPiece[_gd->identifiantVis].forme, _gd->visCadre[_gd->identifiantVis].pos);
				_gd->visPiece[_gd->identifiantVis].isVisible = sfFalse;
				_gd->visCadre[_gd->identifiantVis].isVisible = sfFalse;
				_gd->visPiece[_gd->identifiantVis].isPosed = sfTrue;
				_gd->utilityPieceBoite.visRetirer[_gd->identifiantVis] = sfTrue;

				_gd->utilityPieceBoite.countVis--;

			}
			else
			{
				sfRectangleShape_setPosition(_gd->visPiece[_gd->identifiantVis].forme, _gd->visPiece[_gd->identifiantVis].pos);
				_gd->visPiece[_gd->identifiantVis].isVisible = sfTrue;
			}
			_gd->utilityPieceBoite.isSelected = sfFalse;
		}

		if (_gd->event.mouseButton.button == sfMouseLeft
			&& isCollidingWithMouse(_gd->utilityPieceBoite.helpButtonBox.forme, mousePos2f, 0))
		{
			_gd->utilityPieceBoite.clickHelpButtonBox = sfTrue;
		}
	}

	if (_gd->event.type == sfEvtMouseButtonReleased)
	{
		if (_gd->event.mouseButton.button == sfMouseLeft)
		{
			_gd->utilityPieceBoite.clickHelpButtonBox = sfFalse;

			if (isCollidingWithMouse(_gd->utilityPieceBoite.helpButtonBox.forme, mousePos2f, 0))
			{
				sfSound_play(_gd->helpSound.sound);
				_gd->inGameState = tuto;
			}
			if (_gd->utilityPieceBoite.plaqueOuverte == sfTrue)
			{
				if (isCollidingWithMouse(_gd->utilityPieceBoite.cableRecupPlaque.forme, mousePos2f, 0))
				{
					sfSound_play(_gd->utilityPieceBoite.wirePickUpSound.sound);
					_gd->utilityPieceBoite.cableRecup = sfTrue;
				}
			}

		}
	}
}