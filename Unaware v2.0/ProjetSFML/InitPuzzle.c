#include "InitPuzzle.h"

void InitSpriteButtonPuzzle(GameData* _gd)
{
	_gd->enigme.utilityPuzzle.validate.buttonSprite[0] = LoadSprite("../Ressources/Assets/Puzzle/bouton/valider_1.png", 0);
	_gd->enigme.utilityPuzzle.validate.buttonSprite[1] = LoadSprite("../Ressources/Assets/Puzzle/bouton/valider_2.png", 0);
	_gd->enigme.utilityPuzzle.validate.buttonSprite[2] = LoadSprite("../Ressources/Assets/Puzzle/bouton/valider_3.png", 0);

	_gd->enigme.utilityPuzzle.reset.buttonSprite[0] = LoadSprite("../Ressources/Assets/Puzzle/bouton/reinitialiser_1.png", 0);
	_gd->enigme.utilityPuzzle.reset.buttonSprite[1] = LoadSprite("../Ressources/Assets/Puzzle/bouton/reinitialiser_2.png", 0);
	_gd->enigme.utilityPuzzle.reset.buttonSprite[2] = LoadSprite("../Ressources/Assets/Puzzle/bouton/reinitialiser_3.png", 0);

	_gd->enigme.utilityPuzzle.quit.buttonSprite[0] = LoadSprite("../Ressources/Assets/Puzzle/bouton/quitter_1.png", 0);
	_gd->enigme.utilityPuzzle.quit.buttonSprite[1] = LoadSprite("../Ressources/Assets/Puzzle/bouton/quitter_2.png", 0);
	_gd->enigme.utilityPuzzle.quit.buttonSprite[2] = LoadSprite("../Ressources/Assets/Puzzle/bouton/quitter_3.png", 0);

	_gd->enigme.utilityPuzzle.help.buttonSprite[0] = LoadSprite("../Ressources/Assets/Puzzle/bouton/aide_deb_1.png", 0);
	_gd->enigme.utilityPuzzle.help.buttonSprite[1] = LoadSprite("../Ressources/Assets/Puzzle/bouton/aide_deb_2.png", 0);
	_gd->enigme.utilityPuzzle.help.buttonSprite[2] = LoadSprite("../Ressources/Assets/Puzzle/bouton/aide_deb_3.png", 0);
}

void InitButtonPuzzle(GameData* _gd)
{
	//Init de tout les sprite pour les bouttons du puzzle
	InitSpriteButtonPuzzle(_gd);

	//Bouton valider pour le puzzle
	_gd->enigme.utilityPuzzle.validate.pos.x = 294;
	_gd->enigme.utilityPuzzle.validate.pos.y = 735;

	_gd->enigme.utilityPuzzle.validate.size.x = 193;
	_gd->enigme.utilityPuzzle.validate.size.y = 169;

	_gd->enigme.utilityPuzzle.validate.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.utilityPuzzle.validate.forme, _gd->enigme.utilityPuzzle.validate.pos, _gd->enigme.utilityPuzzle.validate.size.x, _gd->enigme.utilityPuzzle.validate.size.y, 0);

	_gd->enigme.utilityPuzzle.onSpriteValidate = sfFalse;
	_gd->enigme.utilityPuzzle.clickValidate = sfFalse;

	//Bouton reset pour le puzzle
	_gd->enigme.utilityPuzzle.reset.pos.x = 490;
	_gd->enigme.utilityPuzzle.reset.pos.y = 735;

	_gd->enigme.utilityPuzzle.reset.size.x = 187;
	_gd->enigme.utilityPuzzle.reset.size.y = 169;

	_gd->enigme.utilityPuzzle.reset.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.utilityPuzzle.reset.forme, _gd->enigme.utilityPuzzle.reset.pos, _gd->enigme.utilityPuzzle.reset.size.x, _gd->enigme.utilityPuzzle.reset.size.y, 0);

	_gd->enigme.utilityPuzzle.onSpriteReset = sfFalse;
	_gd->enigme.utilityPuzzle.clickReset = sfFalse;

	//Bouton pour quitter le puzzle
	_gd->enigme.utilityPuzzle.quit.pos.x = 680;
	_gd->enigme.utilityPuzzle.quit.pos.y = 735;

	_gd->enigme.utilityPuzzle.quit.size.x = 191;
	_gd->enigme.utilityPuzzle.quit.size.y = 169;

	_gd->enigme.utilityPuzzle.quit.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.utilityPuzzle.quit.forme, _gd->enigme.utilityPuzzle.quit.pos, _gd->enigme.utilityPuzzle.quit.size.x, _gd->enigme.utilityPuzzle.quit.size.y, 0);
	
	_gd->enigme.utilityPuzzle.onSpriteQuit = sfFalse;
	_gd->enigme.utilityPuzzle.clickQuit = sfFalse;

	//Bouton pour l'aide du puzzle

	_gd->enigme.utilityPuzzle.help.pos.x = 155;
	_gd->enigme.utilityPuzzle.help.pos.y = 755;

	_gd->enigme.utilityPuzzle.help.size.x = 126;
	_gd->enigme.utilityPuzzle.help.size.y = 143;

	_gd->enigme.utilityPuzzle.help.forme = sfRectangleShape_create();
	createRectangle(_gd->enigme.utilityPuzzle.help.forme, _gd->enigme.utilityPuzzle.help.pos, _gd->enigme.utilityPuzzle.help.size.x, _gd->enigme.utilityPuzzle.help.size.y, 0);

	_gd->enigme.utilityPuzzle.onSpriteHelp = sfFalse;
	_gd->enigme.utilityPuzzle.clickHelp = sfFalse;
}


void InitCadrePuzzle(GameData* _gd)
{
	sfVector2f pos1 = { 295 , 143 };
	sfVector2f pos2 = { 894, 140 };

	_gd->enigme.utilityPuzzle.cadre1 = sfRectangleShape_create();
	createRectangle(_gd->enigme.utilityPuzzle.cadre1, pos1, 576, 564, 0);

	_gd->enigme.utilityPuzzle.cadre2 = sfRectangleShape_create();
	createRectangle(_gd->enigme.utilityPuzzle.cadre2, pos2, 765, 766, 0);
}

void InitPuzzle(GameData* _gd)
{
	//Les puzzles ce seront les rectangles correspondant a la bonne forme, mais en invisible pour le joueur.
	_gd->enigme.utilityPuzzle.countPuzzle = 0;
	_gd->enigme.utilityPuzzle.idPuzzle = 0;

	for (int j = 0; j < NB_PIECES_PUZZLE_ILE; j++)
	{
		for (int i = 0; i < NB_PIECES_PUZZLE_ILE; i++)
		{
			_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.countPuzzle].Id = _gd->enigme.utilityPuzzle.countPuzzle;

			_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.countPuzzle].isPosed = 1;
			_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.countPuzzle].isOccupied = 0;
			_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.countPuzzle].width = 153;
			_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.countPuzzle].height = 153;
			_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.countPuzzle].position.x = 894 + (_gd->enigme.utilityPuzzle.puzzle[i].width * i);
			_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.countPuzzle].position.y = 140 + (_gd->enigme.utilityPuzzle.puzzle[j].height * j);
			_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.countPuzzle].forme = sfRectangleShape_create();
			_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.countPuzzle].isVisible = sfTrue;

			createRectangle(_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.countPuzzle].forme, _gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.countPuzzle].position,
				_gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.countPuzzle].width, _gd->enigme.utilityPuzzle.puzzle[_gd->enigme.utilityPuzzle.countPuzzle].height, 0);
			_gd->enigme.utilityPuzzle.countPuzzle++;
		}
	}
}

void DestroyList(GameData* _gd)
{
	ListePosPuzzle* tempList = _gd->enigme.utilityPuzzle.rouky;
	if (tempList != NULL)
	{
		if (tempList->toDelete == 1)
		{
			if (tempList->next == NULL)
			{
				free(tempList);
				_gd->enigme.utilityPuzzle.rouky = NULL;
			}
			else
			{
				ListePosPuzzle* freeList = tempList;
				_gd->enigme.utilityPuzzle.rouky = tempList->next;

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
				ListePosPuzzle* freeList = tempList->next;
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

void InitPiece(GameData* _gd)
{
	//Les pieces seront les parties du puzzle disponible pour le joueur, qu'il devra positionner dans le cadre.
	char tab[255];
	int var = 25;
	_gd->enigme.utilityPuzzle.countPiece = 0;
	_gd->enigme.utilityPuzzle.idPiece = 0;

	for (int j = 0; j < NB_PIECES_PUZZLE_ILE; j++)
	{
		for (int i = 0; i < NB_PIECES_PUZZLE_ILE; i++)
		{
			_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.countPiece].Id = _gd->enigme.utilityPuzzle.countPiece;

			sprintf(tab, "../Ressources/Assets/Puzzle/%d.png", _gd->enigme.utilityPuzzle.countPiece + 1);
			_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.countPiece].sprite = LoadSprite(tab, 0);

			_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.countPiece].isPosed = 0;
			_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.countPiece].isOccupied = 0;
			_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.countPiece].width = 77;
			_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.countPiece].height = 77;
			_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.countPiece].isInPuzzle = sfFalse;
			_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.countPiece].isVisible = sfTrue;

			int temp = (rand() % var);
			int k = 0;

			ListePosPuzzle* tempPos = _gd->enigme.utilityPuzzle.rouky;

			while (k != temp)
			{
				tempPos = tempPos->next;
				k++;
			}

			_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.countPiece].position.x = tempPos->pos.x;
			_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.countPiece].position.y = tempPos->pos.y;
			tempPos->toDelete = 1;
			DestroyList(_gd);

			_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.countPiece].forme = sfRectangleShape_create();
			createRectangle(_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.countPiece].forme, _gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.countPiece].position,
				_gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.countPiece].width, _gd->enigme.utilityPuzzle.piece[_gd->enigme.utilityPuzzle.countPiece].height, 0);
			_gd->enigme.utilityPuzzle.countPiece++;
			var--;
		}
	}
	_gd->enigme.utilityPuzzle.piece[5].isVisible = sfFalse;
	_gd->enigme.utilityPuzzle.piece[6].isVisible = sfFalse;
	_gd->enigme.utilityPuzzle.piece[7].isVisible = sfFalse;
	_gd->enigme.utilityPuzzle.piece[8].isVisible = sfFalse;
	_gd->enigme.utilityPuzzle.piece[9].isVisible = sfFalse;
	_gd->enigme.utilityPuzzle.piece[15].isVisible = sfFalse;
	_gd->enigme.utilityPuzzle.piece[16].isVisible = sfFalse;
	_gd->enigme.utilityPuzzle.piece[18].isVisible = sfFalse;
	_gd->enigme.utilityPuzzle.piece[23].isVisible = sfFalse;
}

void InitListeChaine(GameData* _gd)
{
	for (int j = 0; j < NB_PIECES_PUZZLE_ILE; j++)
	{
		for (int i = 0; i < NB_PIECES_PUZZLE_ILE; i++)
		{
			ListePosPuzzle* temp = (ListePosPuzzle*)calloc(sizeof(ListePosPuzzle), 1);

			temp->pos.x = 315 + (77 * (j * 1.50));
			temp->pos.y = 155 + (77 * (i * 1.50));
			temp->toDelete = 0;

			temp->next = _gd->enigme.utilityPuzzle.rouky;
			_gd->enigme.utilityPuzzle.rouky = temp;
		}
	}
}

void InitAllPuzzle(GameData* _gd)
{
	_gd->enigme.utilityPuzzle.backgroundInterface = LoadSprite("../Ressources/Assets/Puzzle/interface_game.png", 0);
	_gd->enigme.utilityPuzzle.plusPlanche = LoadSprite("../Ressources/Assets/Puzzle/plus1.png", 0);
	_gd->enigme.utilityPuzzle.planche = LoadSprite("../Ressources/Assets/Puzzle/tit_planche.png", 0);
	_gd->enigme.utilityPuzzle.resolvedPuzzleDream_1 = sfFalse;

	InitCadrePuzzle(_gd);
	InitButtonPuzzle(_gd);
	InitPuzzle(_gd);
	InitListeChaine(_gd);
	InitPiece(_gd);
	_gd->enigme.utilityPuzzle.isSelected = 0;
	_gd->enigme.utilityPuzzle.nbPlancheRecup = 0;
	_gd->enigme.utilityPuzzle.openFirstTime = sfFalse;
	InitTutoPuzzle(_gd); //init du tuto de l'enigme
}

void DeletePuzzleSprite(GameData* _gd)
{
	DeleteSprite(_gd->enigme.utilityPuzzle.backgroundInterface);
	DeleteSprite(_gd->enigme.utilityPuzzle.plusPlanche);
	DeleteSprite(_gd->enigme.utilityPuzzle.backgroundTutoPuzzle);

	for (int i = 0; i < 3; i++)
	{
		DeleteSprite(_gd->enigme.utilityPuzzle.quit.buttonSprite[i]);
		DeleteSprite(_gd->enigme.utilityPuzzle.help.buttonSprite[i]);
		DeleteSprite(_gd->enigme.utilityPuzzle.reset.buttonSprite[i]);
		DeleteSprite(_gd->enigme.utilityPuzzle.validate.buttonSprite[i]);
		DeleteSprite(_gd->enigme.utilityPuzzle.retour.buttonSprite[i]);

	}

	for (int i = 0; i < NB_PIECES_PUZZLE_ILE * NB_PIECES_PUZZLE_ILE; i++)
	{
		DeleteSprite(_gd->enigme.utilityPuzzle.piece[i].sprite);
		sfRectangleShape_destroy(_gd->enigme.utilityPuzzle.puzzle[i].forme);
		sfRectangleShape_destroy(_gd->enigme.utilityPuzzle.piece[i].forme);

	}

	sfRectangleShape_destroy(_gd->enigme.utilityPuzzle.validate.forme);
	sfRectangleShape_destroy(_gd->enigme.utilityPuzzle.quit.forme);
	sfRectangleShape_destroy(_gd->enigme.utilityPuzzle.reset.forme);
	sfRectangleShape_destroy(_gd->enigme.utilityPuzzle.help.forme);
	sfRectangleShape_destroy(_gd->enigme.utilityPuzzle.retour.forme);

	sfRectangleShape_destroy(_gd->enigme.utilityPuzzle.cadre1);
	sfRectangleShape_destroy(_gd->enigme.utilityPuzzle.cadre2);

}