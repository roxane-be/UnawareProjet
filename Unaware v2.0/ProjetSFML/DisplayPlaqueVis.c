#include "DisplayPlaqueVis.h"

void DisplayHelpButtonBox(GameData* _gd)
{
	//A décommenter lorsqu'on aura les assets du bouton aide pour la boite
	BlitSprite(_gd->utilityPieceBoite.helpButtonBox.buttonSprite[0], _gd->utilityPieceBoite.helpButtonBox.pos.x, _gd->utilityPieceBoite.helpButtonBox.pos.y, 0, 1, 1, _gd);

	if (_gd->utilityPieceBoite.onSpriteHelpButtonBox == sfTrue)
	{
		BlitSprite(_gd->utilityPieceBoite.helpButtonBox.buttonSprite[1], _gd->utilityPieceBoite.helpButtonBox.pos.x, _gd->utilityPieceBoite.helpButtonBox.pos.y, 0, 1, 1, _gd);
	}
	if (_gd->utilityPieceBoite.clickHelpButtonBox == sfTrue)
	{
		BlitSprite(_gd->utilityPieceBoite.helpButtonBox.buttonSprite[2], _gd->utilityPieceBoite.helpButtonBox.pos.x, _gd->utilityPieceBoite.helpButtonBox.pos.y, 0, 1, 1, _gd);
	}

	//sfRenderWindow_drawRectangleShape(_gd->window, _gd->utilityPieceBoite.helpButtonBox.forme, NULL);
}

void DisplayVis(GameData* _gd)
{
	//Affichage Vis du cadre
	for (int i = 0; i < NB_VIS; i++)
	{
		if (_gd->visCadre[i].isVisible == sfTrue)
		{
			//sfRenderWindow_drawRectangleShape(_gd->window, _gd->visCadre[i].forme, NULL);
			if (_gd->enigme.houseBox.resolvedDream_1Box == sfFalse)
			{
				BlitSpriteColor(_gd->visCadre[i].sprite, 1);
			}
			else
			{
				BlitSpriteColor(_gd->visCadre[i].sprite, 2);
			}
			BlitSprite(_gd->visCadre[i].sprite, _gd->visCadre[i].pos.x - 10, _gd->visCadre[i].pos.y - 10, 0.f, 1, 1, _gd);
		}

	}
	//Affichage Pieces disponible

	if (_gd->enigme.houseBox.pieceRecup == sfTrue)
	{
		for (int j = 0; j < _gd->utilityPieceBoite.countPiece; j++)
		{
			if (_gd->visPiece[j].isVisible == sfTrue)
			{
				sfVector2f temp = sfRectangleShape_getPosition(_gd->visPiece[j].forme);

				if (_gd->enigme.houseBox.resolvedDream_1Box == sfFalse)
				{
					BlitSpriteColor(_gd->visPiece[j].sprite, 1);
				}
				else
				{
					BlitSpriteColor(_gd->visPiece[j].sprite, 2);

				}
				BlitSprite(_gd->visPiece[j].sprite, _gd->visPiece[j].pos.x + 5, _gd->visPiece[j].pos.y + 5, 0.f, 1, 1, _gd);

				//sfRenderWindow_drawRectangleShape(_gd->window, _gd->visPiece[j].forme, NULL);
			}
		}
	}

	if (_gd->utilityPieceBoite.isSelected == sfTrue)
	{
		_gd->visPiece[_gd->identifiantVis].isVisible = sfFalse;
	}
}

//Potentiellement a modifier
void DisplayVisRetirer(GameData* _gd)
{
	for (int i = 0; i < 4; i++)
	{
		if (_gd->utilityPieceBoite.visRetirer[i] == sfTrue)
		{
			BlitSprite(_gd->utilityPieceBoite.visRetirerSprite[i], 1700, 130 + (i * 100), 0, 1, 1, _gd);
		}
	}
}

void DisplayVisPlaqueBackground(GameData* _gd)
{
	if (_gd->utilityPieceBoite.plaqueOuverte == sfFalse)
	{
		BlitSprite(_gd->utilityPieceBoite.backgroundVisPlaqueBox, _gd->visCadre[0].pos.x - 10, _gd->visCadre[0].pos.y - 10, 0, 1, 1, _gd);
		BlitSprite(_gd->utilityPieceBoite.backgroundVisPlaqueBox, _gd->visCadre[1].pos.x - 10, _gd->visCadre[1].pos.y - 10, 0, 1, 1, _gd);
		BlitSprite(_gd->utilityPieceBoite.backgroundVisPlaqueBox, _gd->visCadre[2].pos.x - 10, _gd->visCadre[2].pos.y - 10, 0, 1, 1, _gd);
		BlitSprite(_gd->utilityPieceBoite.backgroundVisPlaqueBox, _gd->visCadre[3].pos.x - 10, _gd->visCadre[3].pos.y - 10, 0, 1, 1, _gd);
	}

	if (_gd->enigme.houseBox.resolvedDream_1Box == sfFalse)
	{
		BlitSpriteColor(_gd->utilityPieceBoite.backgroundVisPlaqueBox, 1);
	}
	else
	{
		BlitSpriteColor(_gd->utilityPieceBoite.backgroundVisPlaqueBox, 2);
	}
}
void DisplayTranchePiece(GameData* _gd)
{

	sfVector2f temp = sfRectangleShape_getPosition(_gd->visPiece[_gd->identifiantVis].forme);

	if (_gd->utilityPieceBoite.isSelected == sfTrue)
	{
		BlitSprite(_gd->utilityPieceBoite.tranchePiece[_gd->identifiantVis], temp.x - 70, temp.y - 70, 0, 1, 1, _gd);
	}

}

void DisplayCableRecup(GameData* _gd)
{
	if (_gd->utilityPieceBoite.plaqueOuverte == sfTrue &&
		_gd->utilityPieceBoite.cableRecup == sfFalse &&
		_gd->utilityPieceBoite.resolvedDream_1 == sfFalse)
	{
		BlitSprite(_gd->utilityPieceBoite.cableRecupPlaque.buttonSprite[0], _gd->utilityPieceBoite.cableRecupPlaque.pos.x - 15,
			_gd->utilityPieceBoite.cableRecupPlaque.pos.y - 29, 0, 1, 1, _gd);
		//sfRenderWindow_drawRectangleShape(_gd->window, _gd->utilityPieceBoite.cableRecupPlaque.forme, NULL);
	}

}
void DisplayPlaqueVisBox(GameData* _gd)
{
	if (_gd->utilityPieceBoite.plaqueOuverte == sfFalse)
	{
		BlitSprite(_gd->utilityPieceBoite.backgroundPlaqueBox, 0, 0, 0, 1, 1, _gd);
		BlitSprite(_gd->utilityPieceBoite.diodePlaqueBoxEnigmeNonFini, 1420, 930, 0, 1, 1, _gd);
	}
	else
	{
		BlitSprite(_gd->utilityPieceBoite.backgroundPlaqueBoxFin, 0, 0, 0, 1, 1, _gd);
		BlitSprite(_gd->utilityPieceBoite.diodePlaqueBoxEnigmeFini, 1420, 930, 0, 1, 1, _gd);
	}

	DisplayVisPlaqueBackground(_gd);
	DisplayVis(_gd);
	DisplayHelpButtonBox(_gd);
	DisplayTranchePiece(_gd);
	DisplayCableRecup(_gd);
	DisplayVisRetirer(_gd);

	if (_gd->enigme.houseBox.resolvedDream_1Box == sfFalse)
	{
		BlitSprite(_gd->trap, 0, 0, 0, 1, 1, _gd);
	}
}