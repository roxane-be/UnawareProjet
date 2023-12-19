#include "InitPlaqueVis.h"

void DestroyListVis(GameData* _gd)
{
	ListeVis* tempList = _gd->listeVis;
	if (tempList != NULL)
	{
		if (tempList->toDelete == 1)
		{
			if (tempList->next == NULL)
			{
				free(tempList);
				_gd->listeVis = NULL;
			}
			else
			{
				ListeVis* freeList = tempList;
				_gd->listeVis = tempList->next;

				free(freeList);
				freeList = NULL;
			}
		}
		else if (tempList->toDelete == 0)
		{
			while (tempList->next->toDelete == 0 && tempList->next->next != NULL)
			{
				tempList = tempList->next;
			}
			if (tempList->next->toDelete == 1)
			{
				ListeVis* freeList = tempList->next;
				if (tempList->next->next == NULL)
				{
					tempList->next = NULL;
				}
				else
				{
					tempList->next = tempList->next->next;
				}
				free(freeList);
				freeList = NULL;
			}
		}
	}
}

void DestroyListPiece(GameData* _gd)
{
	ListeVis* tempList = _gd->listePieces;
	if (tempList != NULL)
	{
		if (tempList->toDelete == 1)
		{
			if (tempList->next == NULL)
			{
				free(tempList);
				_gd->listePieces = NULL;
			}
			else
			{
				ListeVis* freeList = tempList;
				_gd->listePieces = tempList->next;

				free(freeList);
				freeList = NULL;
			}
		}
		else if (tempList->toDelete == 0)
		{
			while (tempList->next->toDelete == 0 && tempList->next->next != NULL)
			{
				tempList = tempList->next;
			}
			if (tempList->next->toDelete == 1)
			{
				ListeVis* freeList = tempList->next;
				if (tempList->next->next == NULL)
				{
					tempList->next = NULL;
				}
				else
				{
					tempList->next = tempList->next->next;
				}
				free(freeList);
				freeList = NULL;
			}
		}
	}
}

void InitCableARecup(GameData* _gd)
{
	sfVector2f posCable = { _gd->sizeWindow.width / 2 - 89, 320 };
	sfVector2f sizeCable = { 250, 50 };

	_gd->utilityPieceBoite.cableRecupPlaque.buttonSprite[0] = LoadSprite("../Ressources/Assets/BoxPlaque/cable_seul.png", 0);

	_gd->utilityPieceBoite.cableRecupPlaque.pos = posCable;
	_gd->utilityPieceBoite.cableRecupPlaque.size = sizeCable;

	_gd->utilityPieceBoite.cableRecupPlaque.forme = sfRectangleShape_create();
	createRectangle(_gd->utilityPieceBoite.cableRecupPlaque.forme, _gd->utilityPieceBoite.cableRecupPlaque.pos,
		_gd->utilityPieceBoite.cableRecupPlaque.size.x, _gd->utilityPieceBoite.cableRecupPlaque.size.y, _gd);
}

void InitCadre(GameData* _gd)
{
	sfVector2f size1 = { _gd->sizeWindow.width / 2 - 17, _gd->sizeWindow.height / 2 - 112 };
	sfVector2f pos1 = { _gd->sizeWindow.width / 2 - (size1.x / 2) + 20 , 130 };
	_gd->utilityPieceBoite.cadreBoite[0].pos = pos1;
	_gd->utilityPieceBoite.cadreBoite[0].size = size1;

	sfVector2f size2 = { 800, 300 };
	sfVector2f pos2 = { _gd->sizeWindow.width / 2 - (size1.x / 2), _gd->sizeWindow.height / 2 + 100 };
	_gd->utilityPieceBoite.cadreBoite[1].pos = pos2;
	_gd->utilityPieceBoite.cadreBoite[1].size = size2;

	_gd->utilityPieceBoite.cadreBoite[0].forme = sfRectangleShape_create();
	createRectangle(_gd->utilityPieceBoite.cadreBoite[0].forme, pos1, size1.x, size1.y, 0);

	_gd->utilityPieceBoite.cadreBoite[1].forme = sfRectangleShape_create();
	createRectangle(_gd->utilityPieceBoite.cadreBoite[1].forme, pos2, size2.x, size2.y, 0);
}


void InitPiecePlaque(GameData* _gd)
{
	//Les pieces seront les parties du puzzle disponible pour le joueur, qu'il devra positionner dans le cadre.
	char tab[255];
	int var = 10;

	_gd->utilityPieceBoite.countPiece = 0;
	_gd->utilityPieceBoite.idPiece = 0;

	for (int j = 0; j < NB_PIECES_BOITE; j++)
	{
		for (int i = 0; i < 2; i++)
		{
			_gd->visPiece[_gd->utilityPieceBoite.countPiece].identifiant = _gd->utilityPieceBoite.countPiece;


			sprintf(tab, "../Ressources/Assets/BoxPlaque/pièce/%d.png", _gd->utilityPieceBoite.countPiece);
			_gd->visPiece[_gd->utilityPieceBoite.countPiece].sprite = LoadSprite(tab, 1);
			sprintf(tab, "../Ressources/Assets/BoxPlaque/pièce/_%d.png", _gd->utilityPieceBoite.countPiece);
			_gd->utilityPieceBoite.tranchePiece[_gd->utilityPieceBoite.countPiece] = LoadSprite(tab, 0);

			//printf("%s\n", tab);

			_gd->visPiece[_gd->utilityPieceBoite.countPiece].isPosed = sfFalse;
			_gd->visPiece[_gd->utilityPieceBoite.countPiece].isVisible = sfTrue;
			_gd->visPiece[_gd->utilityPieceBoite.countPiece].size.x = 95;
			_gd->visPiece[_gd->utilityPieceBoite.countPiece].size.y = 95;


			int temp = (rand() % var);
			int k = 0;

			ListeVis* tempPos = _gd->listePieces;

			while (k != temp)
			{
				tempPos = tempPos->next;

				k++;
			}

			//printf("Coucou ! %d\n", k);
			_gd->visPiece[_gd->utilityPieceBoite.countPiece].pos.x = tempPos->pos.x;
			_gd->visPiece[_gd->utilityPieceBoite.countPiece].pos.y = tempPos->pos.y;
			tempPos->toDelete = 1;
			DestroyListPiece(_gd);


			_gd->visPiece[_gd->utilityPieceBoite.countPiece].forme = sfRectangleShape_create();
			createRectangle(_gd->visPiece[_gd->utilityPieceBoite.countPiece].forme, _gd->visPiece[_gd->utilityPieceBoite.countPiece].pos,
				_gd->visPiece[_gd->utilityPieceBoite.countPiece].size.x, _gd->visPiece[_gd->utilityPieceBoite.countPiece].size.y, 1);

			sfRectangleShape_setFillColor(_gd->visPiece[_gd->utilityPieceBoite.countPiece].forme, sfTransparent);

			_gd->utilityPieceBoite.countPiece++;
			var--;

		}

	}
}

void InitListePiece(GameData* _gd)
{

	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < NB_PIECES_BOITE; i++)
		{
			ListeVis* temp = (ListeVis*)calloc(sizeof(ListeVis), 1);


			temp->pos.x = (_gd->utilityPieceBoite.cadreBoite[1].pos.x + 45) + (150 * i);
			temp->pos.y = (_gd->utilityPieceBoite.cadreBoite[1].pos.y + 45) + (150 * j) + 30;
			temp->toDelete = 0;


			temp->next = _gd->listePieces;
			_gd->listePieces = temp;

		}
	}
}

void InitListeVis(GameData* _gd)
{
	for (int j = 0; j < 4; j++)
	{

		ListeVis* temp = (ListeVis*)calloc(sizeof(ListeVis), 1);

		temp->size.x = 105;
		temp->size.y = 100;

		if (j == 0)
		{
			temp->pos.x = _gd->utilityPieceBoite.cadreBoite[0].pos.x;
			temp->pos.y = _gd->utilityPieceBoite.cadreBoite[0].pos.y;
			//printf("%f__%f\n", _gd->utilityPieceBoite.cadreBoite[0].pos.x, _gd->utilityPieceBoite.cadreBoite[0].pos.y);
		}
		if (j == 1)
		{
			temp->pos.x = _gd->utilityPieceBoite.cadreBoite[0].pos.x + _gd->utilityPieceBoite.cadreBoite[0].size.x - temp->size.x;
			temp->pos.y = _gd->utilityPieceBoite.cadreBoite[0].pos.y;
			//printf("%f__%f\n", temp->pos.x, temp->pos.y);
		}
		if (j == 2)
		{
			temp->pos.x = _gd->utilityPieceBoite.cadreBoite[0].pos.x;
			temp->pos.y = _gd->utilityPieceBoite.cadreBoite[0].pos.y + _gd->utilityPieceBoite.cadreBoite[0].size.y - temp->size.y;
			//("%f__%f\n", temp->pos.x, temp->pos.y);
		}
		if (j == 3)
		{
			temp->pos.x = _gd->utilityPieceBoite.cadreBoite[0].pos.x + _gd->utilityPieceBoite.cadreBoite[0].size.x - temp->size.x;
			temp->pos.y = _gd->utilityPieceBoite.cadreBoite[0].pos.y + _gd->utilityPieceBoite.cadreBoite[0].size.y - temp->size.y;
			//printf("%f__%f\n", temp->pos.x, temp->pos.y);
		}

		temp->toDelete = 0;


		temp->next = _gd->listeVis;
		_gd->listeVis = temp;

	}
}

void InitVis(GameData* _gd)
{
	char tab[255];
	int var = 4;

	_gd->utilityPieceBoite.countVis = 0;
	_gd->utilityPieceBoite.idVis = 0;

	for (int j = 0; j < 4; j++)
	{

		_gd->visCadre[_gd->utilityPieceBoite.countVis].identifiant = _gd->utilityPieceBoite.countVis;

		//printf("%d\n", _gd->visCadre[_gd->utilityPieceBoite.countVis].identifiant);

		sprintf(tab, "../Ressources/Assets/BoxPlaque/pièce/vis_%d.png", _gd->utilityPieceBoite.countVis);
		_gd->visCadre[_gd->utilityPieceBoite.countVis].sprite = LoadSprite(tab, 0);

		//printf("%s\n", tab);

		_gd->visCadre[_gd->utilityPieceBoite.countVis].isPosed = sfTrue;
		_gd->visCadre[_gd->utilityPieceBoite.countVis].isVisible = sfTrue;



		int temp = (rand() % var);
		int k = 0;

		ListeVis* tempPos = _gd->listeVis;

		while (k != temp)
		{

			tempPos = tempPos->next;

			k++;
		}

		//printf("Coucou ! %d\n", k);
		_gd->visCadre[_gd->utilityPieceBoite.countVis].size.x = tempPos->size.x;
		_gd->visCadre[_gd->utilityPieceBoite.countVis].size.y = tempPos->size.y;

		_gd->visCadre[_gd->utilityPieceBoite.countVis].pos.x = tempPos->pos.x;
		_gd->visCadre[_gd->utilityPieceBoite.countVis].pos.y = tempPos->pos.y;

		tempPos->toDelete = 1;

		DestroyListVis(_gd);


		_gd->visCadre[_gd->utilityPieceBoite.countVis].forme = sfRectangleShape_create();
		createRectangle(_gd->visCadre[_gd->utilityPieceBoite.countVis].forme, _gd->visCadre[_gd->utilityPieceBoite.countVis].pos,
			_gd->visCadre[_gd->utilityPieceBoite.countVis].size.x, _gd->visCadre[_gd->utilityPieceBoite.countVis].size.y, 0);

		//sfRectangleShape_setFillColor(_gd->visCadre[_gd->utilityPieceBoite.countVis].forme, sfBlue);
		_gd->utilityPieceBoite.countVis++;
		var--;
		//printf("%d\n", countPiece);


	}
}

void InitVisRetirer(GameData* _gd)
{
	_gd->utilityPieceBoite.visRetirerSprite[0] = LoadSprite("../Ressources/Assets/BoxPlaque/pièce/__vis0.png", 0);
	_gd->utilityPieceBoite.visRetirerSprite[1] = LoadSprite("../Ressources/Assets/BoxPlaque/pièce/__vis1.png", 0);
	_gd->utilityPieceBoite.visRetirerSprite[2] = LoadSprite("../Ressources/Assets/BoxPlaque/pièce/__vis2.png", 0);
	_gd->utilityPieceBoite.visRetirerSprite[3] = LoadSprite("../Ressources/Assets/BoxPlaque/pièce/__vis3.png", 0);

	_gd->utilityPieceBoite.visRetirer[0] = sfFalse;
	_gd->utilityPieceBoite.visRetirer[1] = sfFalse;
	_gd->utilityPieceBoite.visRetirer[2] = sfFalse;
	_gd->utilityPieceBoite.visRetirer[3] = sfFalse;
}

void InitButtonHelpBox(GameData* _gd)
{
	//A décommenter lorsqu'on aura les assets du bouton help
	_gd->utilityPieceBoite.helpButtonBox.buttonSprite[0] = LoadSprite("../Ressources/Assets/Box/aide.png", 0);
	_gd->utilityPieceBoite.helpButtonBox.buttonSprite[1] = LoadSprite("../Ressources/Assets/Box/aide2.png", 0);
	_gd->utilityPieceBoite.helpButtonBox.buttonSprite[2] = LoadSprite("../Ressources/Assets/Box/aide3.png", 0);


	_gd->utilityPieceBoite.onSpriteHelpButtonBox = sfFalse;
	_gd->utilityPieceBoite.clickHelpButtonBox = sfFalse;

	_gd->utilityPieceBoite.helpButtonBox.pos.x = 0;
	_gd->utilityPieceBoite.helpButtonBox.pos.y = 100;

	_gd->utilityPieceBoite.helpButtonBox.size.x = 170;
	_gd->utilityPieceBoite.helpButtonBox.size.y = 300;

	_gd->utilityPieceBoite.helpButtonBox.forme = sfRectangleShape_create();
	createRectangle(_gd->utilityPieceBoite.helpButtonBox.forme, _gd->utilityPieceBoite.helpButtonBox.pos, _gd->utilityPieceBoite.helpButtonBox.size.x, _gd->utilityPieceBoite.helpButtonBox.size.y, 0);
}

void InitBackground(GameData* _gd)
{
	_gd->utilityPieceBoite.backgroundPlaqueBox = LoadSprite("../Ressources/Assets/BoxPlaque/interface_2.png", 0);
	_gd->utilityPieceBoite.backgroundPlaqueBoxFin = LoadSprite("../Ressources/Assets/BoxPlaque/interface_fin.png", 0);
	_gd->utilityPieceBoite.backgroundVisPlaqueBox = LoadSprite("../Ressources/Assets/BoxPlaque/pièce/trou.png", 0);
	_gd->utilityPieceBoite.diodePlaqueBoxEnigmeFini = LoadSprite("../Ressources/Assets/Mastermind/diode_verte.png", 0);
	_gd->utilityPieceBoite.diodePlaqueBoxEnigmeNonFini = LoadSprite("../Ressources/Assets/Mastermind/diode_rouge.png", 0);
}

void InitPlaqueVisBox(GameData* _gd)
{
	_gd->utilityPieceBoite.plaqueOuverte = sfFalse;
	_gd->utilityPieceBoite.cableRecup = sfFalse;
	_gd->utilityPieceBoite.resolvedDream_1 = sfFalse;
	_gd->utilityPieceBoite.isSelected = 0;
	InitBackground(_gd);
	InitButtonHelpBox(_gd);
	InitCadre(_gd);
	InitListePiece(_gd);
	InitListeVis(_gd);
	InitPiecePlaque(_gd);
	InitVis(_gd);
	InitCableARecup(_gd);
	InitVisRetirer(_gd);
}

void DeletePlaqueVisSprite(GameData* _gd)
{
	DeleteSprite(_gd->utilityPieceBoite.backgroundPlaqueBox);
	DeleteSprite(_gd->utilityPieceBoite.backgroundPlaqueBoxFin);
	DeleteSprite(_gd->utilityPieceBoite.backgroundVisPlaqueBox);
	DeleteSprite(_gd->utilityPieceBoite.diodePlaqueBoxEnigmeFini);
	DeleteSprite(_gd->utilityPieceBoite.diodePlaqueBoxEnigmeNonFini);
	DeleteSprite(_gd->utilityPieceBoite.cableRecupPlaque.buttonSprite[0]);
	DeleteSprite(_gd->utilityPieceBoite.backgroundTutoVis);

	for (int i = 0; i < 10; i++)
	{
		DeleteSprite(_gd->visPiece[i].sprite);
		DeleteSprite(_gd->utilityPieceBoite.tranchePiece[i]);
		sfRectangleShape_destroy(_gd->visPiece[i].forme);
	}
	for (int i = 0; i < 4; i++)
	{
		DeleteSprite(_gd->visCadre[i].sprite);
		DeleteSprite(_gd->utilityPieceBoite.visRetirerSprite[i]);
		sfRectangleShape_destroy(_gd->visCadre[i].forme);
	}
	for (int i = 0; i < 3; i++)
	{
		DeleteSprite(_gd->utilityPieceBoite.helpButtonBox.buttonSprite[i]);
	}

	sfRectangleShape_destroy(_gd->utilityPieceBoite.cableRecupPlaque.forme);
	sfRectangleShape_destroy(_gd->utilityPieceBoite.helpButtonBox.forme);
	for (int i = 0; i < 2; i++)
	{
		sfRectangleShape_destroy(_gd->utilityPieceBoite.cadreBoite[i].forme);
	}
}