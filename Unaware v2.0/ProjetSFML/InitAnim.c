#include "InitAnim.h"

void InitAnim(GameData* _gd)
{
	_gd->nbSpriteAnim = 0;
	_gd->push = 0;
	_gd->actualClock.tempClock = sfClock_create();
	_gd->actualClock.tempsCourant = 0.1 + rand() / (float)RAND_MAX;

	//Monde reel
	char chaine1[100] = "../Ressources/Assets/Player/Boy/";
	char chaine2[100] = "../Ressources/Assets/Player/Girl/";
	//Reve
	char chaine3[100] = "../Ressources/Assets/Player/BoyDream/";
	char chaine4[100] = "../Ressources/Assets/Player/GirlDream/";

	char chemin[100];

	if (_gd->choixPerso == 0
		&& _gd->inDream == sfFalse)
	{
		//Garçon
		strcpy(chemin, chaine1); //chemin d'acces au dossier de sprite pour charger l'anim

	}
	else if (_gd->choixPerso == 1
		&& _gd->inDream == sfFalse)
	{
		//Fille
		strcpy(chemin, chaine2);

	}

	if (_gd->choixPerso == 0
		&& _gd->inDream == sfTrue)
	{
		strcpy(chemin, chaine3);
	}
	else if (_gd->choixPerso == 1
		&& _gd->inDream == sfTrue)
	{
		strcpy(chemin, chaine4);
	}


	FILE* f;
	char tab[1000] = { 0 };


	if (!(f = fopen("../Ressources/Assets/Player/Boy/animation.txt", "r"))) //lecteur du fichier
	{
		printf("Erreur d'acces au fichier\n");
		exit(EXIT_FAILURE);
	}



	while (fscanf(f, "%s", tab) != EOF)
	{
		if (!_stricmp(tab, "SPRITES"))
		{
			fscanf(f, "%d", &_gd->nbSpriteAnim);

			_gd->persoDef.Timeline = (sfSprite**)malloc(sizeof(sfSprite*) * _gd->nbSpriteAnim);

			for (int i = 0; i < _gd->nbSpriteAnim; i++)
			{
				fscanf(f, "%s", tab);
				char temp[100] = { 0 };
				strcpy(temp, chemin);
				strcat(temp, tab);
				_gd->persoDef.Timeline[i] = LoadSprite(temp, 1);
			}
		}

		if (!_stricmp(tab, "ANIM"))
		{
			fscanf(f, "%s", tab);

			if (!_stricmp(tab, "MARCHE_HAUT"))
			{
				fscanf(f, "%d", &_gd->persoDef.sequence[hautM].begin);
				fscanf(f, "%d", &_gd->persoDef.sequence[hautM].end);
				fscanf(f, "%f", &_gd->persoDef.sequence[hautM].total);
			}

			if (!_stricmp(tab, "MARCHE_BAS"))
			{
				fscanf(f, "%d", &_gd->persoDef.sequence[basM].begin);
				fscanf(f, "%d", &_gd->persoDef.sequence[basM].end);
				fscanf(f, "%f", &_gd->persoDef.sequence[basM].total);
			}

			if (!_stricmp(tab, "MARCHE_GAUCHE"))
			{
				fscanf(f, "%d", &_gd->persoDef.sequence[gaucheM].begin);
				fscanf(f, "%d", &_gd->persoDef.sequence[gaucheM].end);
				fscanf(f, "%f", &_gd->persoDef.sequence[gaucheM].total);
			}

			if (!_stricmp(tab, "MARCHE_DROITE"))
			{
				fscanf(f, "%d", &_gd->persoDef.sequence[droiteM].begin);
				fscanf(f, "%d", &_gd->persoDef.sequence[droiteM].end);
				fscanf(f, "%f", &_gd->persoDef.sequence[droiteM].total);
			}

			if (!_stricmp(tab, "IDLE_HAUT"))
			{
				fscanf(f, "%d", &_gd->persoDef.sequence[hautI].begin);
				fscanf(f, "%d", &_gd->persoDef.sequence[hautI].end);
				fscanf(f, "%f", &_gd->persoDef.sequence[hautI].total);
			}

			if (!_stricmp(tab, "IDLE_BAS"))
			{
				fscanf(f, "%d", &_gd->persoDef.sequence[basI].begin);
				fscanf(f, "%d", &_gd->persoDef.sequence[basI].end);
				fscanf(f, "%f", &_gd->persoDef.sequence[basI].total);
			}

			if (!_stricmp(tab, "IDLE_GAUCHE"))
			{
				fscanf(f, "%d", &_gd->persoDef.sequence[gaucheI].begin);
				fscanf(f, "%d", &_gd->persoDef.sequence[gaucheI].end);
				fscanf(f, "%f", &_gd->persoDef.sequence[gaucheI].total);
			}

			if (!_stricmp(tab, "IDLE_DROITE"))
			{
				fscanf(f, "%d", &_gd->persoDef.sequence[droiteI].begin);
				fscanf(f, "%d", &_gd->persoDef.sequence[droiteI].end);
				fscanf(f, "%f", &_gd->persoDef.sequence[droiteI].total);
			}
		}
		_gd->player.persoDef = &_gd->persoDef;
	}

	fclose(f);
}

void InitAnimPNJ(GameData* _gd, int _id)
{
	_gd->nbSpriteAnim = 0;
	_gd->push = 0;

	char chemin[100];
	char fichier[100];
	sprintf(chemin, "../Ressources/Assets/Player/NPC_%d/", _id);
	sprintf(fichier, "../Ressources/Assets/Player/NPC_%d/animation.txt", _id);
	//char chemin[100] = "../Ressources/Assets/Player/NPC/"; //chemin d'acces au dossier de sprite pour charger l'anim

	FILE* f;
	char tab[1000] = { 0 };

	if (!(f = fopen(fichier, "r"))) //lecteur du fichier
	{
		printf("Erreur d'acces au fichier\n");
		exit(EXIT_FAILURE);
	}

	while (fscanf(f, "%s", tab) != EOF)
	{
		if (!_stricmp(tab, "SPRITES"))
		{
			fscanf(f, "%d", &_gd->nbSpriteAnim);

			_gd->npcDef.Timeline = (sfSprite**)malloc(sizeof(sfSprite*) * _gd->nbSpriteAnim);

			for (int i = 0; i < _gd->nbSpriteAnim; i++)
			{
				fscanf(f, "%s", tab);
				char temp[100] = { 0 };
				strcpy(temp, chemin);
				strcat(temp, tab);
				_gd->npcDef.Timeline[i] = LoadSprite(temp, 1);
			}
		}

		if (!_stricmp(tab, "ANIM"))
		{
			fscanf(f, "%s", tab);

			if (!_stricmp(tab, "MARCHE_HAUT"))
			{
				fscanf(f, "%d", &_gd->npcDef.sequence[hautM].begin);
				fscanf(f, "%d", &_gd->npcDef.sequence[hautM].end);
				fscanf(f, "%f", &_gd->npcDef.sequence[hautM].total);
			}

			if (!_stricmp(tab, "MARCHE_BAS"))
			{
				fscanf(f, "%d", &_gd->npcDef.sequence[basM].begin);
				fscanf(f, "%d", &_gd->npcDef.sequence[basM].end);
				fscanf(f, "%f", &_gd->npcDef.sequence[basM].total);
			}

			if (!_stricmp(tab, "MARCHE_GAUCHE"))
			{
				fscanf(f, "%d", &_gd->npcDef.sequence[gaucheM].begin);
				fscanf(f, "%d", &_gd->npcDef.sequence[gaucheM].end);
				fscanf(f, "%f", &_gd->npcDef.sequence[gaucheM].total);
			}

			if (!_stricmp(tab, "MARCHE_DROITE"))
			{
				fscanf(f, "%d", &_gd->npcDef.sequence[droiteM].begin);
				fscanf(f, "%d", &_gd->npcDef.sequence[droiteM].end);
				fscanf(f, "%f", &_gd->npcDef.sequence[droiteM].total);
			}

			if (!_stricmp(tab, "IDLE_HAUT"))
			{
				fscanf(f, "%d", &_gd->npcDef.sequence[hautI].begin);
				fscanf(f, "%d", &_gd->npcDef.sequence[hautI].end);
				fscanf(f, "%f", &_gd->npcDef.sequence[hautI].total);
			}

			if (!_stricmp(tab, "IDLE_BAS"))
			{
				fscanf(f, "%d", &_gd->npcDef.sequence[basI].begin);
				fscanf(f, "%d", &_gd->npcDef.sequence[basI].end);
				fscanf(f, "%f", &_gd->npcDef.sequence[basI].total);
			}

			if (!_stricmp(tab, "IDLE_GAUCHE"))
			{
				fscanf(f, "%d", &_gd->npcDef.sequence[gaucheI].begin);
				fscanf(f, "%d", &_gd->npcDef.sequence[gaucheI].end);
				fscanf(f, "%f", &_gd->npcDef.sequence[gaucheI].total);
			}

			if (!_stricmp(tab, "IDLE_DROITE"))
			{
				fscanf(f, "%d", &_gd->npcDef.sequence[droiteI].begin);
				fscanf(f, "%d", &_gd->npcDef.sequence[droiteI].end);
				fscanf(f, "%f", &_gd->npcDef.sequence[droiteI].total);
			}
		}
		_gd->npc[_id].npcDef = _gd->npcDef;
	}

	fclose(f);
}

void InitAnimFourmi(GameData* _gd,NPC _npc)
{
	_gd->nbSpriteAnim = 0;
	_gd->push = 0;

	char chemin[100];
	char fichier[100];
	sprintf(chemin, "../Ressources/Assets/Player/NPC_Fourmi/");
	sprintf(fichier, "../Ressources/Assets/Player/NPC_Fourmi/animation.txt");
	//char chemin[100] = "../Ressources/Assets/Player/NPC/"; //chemin d'acces au dossier de sprite pour charger l'anim

	FILE* f;
	char tab[1000] = { 0 };

	if (!(f = fopen(fichier, "r"))) //lecteur du fichier
	{
		printf("Erreur d'acces au fichier\n");
		exit(EXIT_FAILURE);
	}

	while (fscanf(f, "%s", tab) != EOF)
	{
		if (!_stricmp(tab, "SPRITES"))
		{
			fscanf(f, "%d", &_gd->nbSpriteAnim);

			_gd->npcDef.Timeline = (sfSprite**)malloc(sizeof(sfSprite*) * _gd->nbSpriteAnim);

			for (int i = 0; i < _gd->nbSpriteAnim; i++)
			{
				fscanf(f, "%s", tab);
				char temp[100] = { 0 };
				strcpy(temp, chemin);
				strcat(temp, tab);
				_gd->npcDef.Timeline[i] = LoadSprite(temp, 1);
			}
		}

		if (!_stricmp(tab, "ANIM"))
		{
			fscanf(f, "%s", tab);

			if (!_stricmp(tab, "MARCHE_HAUT"))
			{
				fscanf(f, "%d", &_gd->npcDef.sequence[hautM].begin);
				fscanf(f, "%d", &_gd->npcDef.sequence[hautM].end);
				fscanf(f, "%f", &_gd->npcDef.sequence[hautM].total);
			}

			if (!_stricmp(tab, "MARCHE_BAS"))
			{
				fscanf(f, "%d", &_gd->npcDef.sequence[basM].begin);
				fscanf(f, "%d", &_gd->npcDef.sequence[basM].end);
				fscanf(f, "%f", &_gd->npcDef.sequence[basM].total);
			}

			if (!_stricmp(tab, "MARCHE_GAUCHE"))
			{
				fscanf(f, "%d", &_gd->npcDef.sequence[gaucheM].begin);
				fscanf(f, "%d", &_gd->npcDef.sequence[gaucheM].end);
				fscanf(f, "%f", &_gd->npcDef.sequence[gaucheM].total);
			}

			if (!_stricmp(tab, "MARCHE_DROITE"))
			{
				fscanf(f, "%d", &_gd->npcDef.sequence[droiteM].begin);
				fscanf(f, "%d", &_gd->npcDef.sequence[droiteM].end);
				fscanf(f, "%f", &_gd->npcDef.sequence[droiteM].total);
			}

			if (!_stricmp(tab, "IDLE_HAUT"))
			{
				fscanf(f, "%d", &_gd->npcDef.sequence[hautI].begin);
				fscanf(f, "%d", &_gd->npcDef.sequence[hautI].end);
				fscanf(f, "%f", &_gd->npcDef.sequence[hautI].total);
			}

			if (!_stricmp(tab, "IDLE_BAS"))
			{
				fscanf(f, "%d", &_gd->npcDef.sequence[basI].begin);
				fscanf(f, "%d", &_gd->npcDef.sequence[basI].end);
				fscanf(f, "%f", &_gd->npcDef.sequence[basI].total);
			}

			if (!_stricmp(tab, "IDLE_GAUCHE"))
			{
				fscanf(f, "%d", &_gd->npcDef.sequence[gaucheI].begin);
				fscanf(f, "%d", &_gd->npcDef.sequence[gaucheI].end);
				fscanf(f, "%f", &_gd->npcDef.sequence[gaucheI].total);
			}

			if (!_stricmp(tab, "IDLE_DROITE"))
			{
				fscanf(f, "%d", &_gd->npcDef.sequence[droiteI].begin);
				fscanf(f, "%d", &_gd->npcDef.sequence[droiteI].end);
				fscanf(f, "%f", &_gd->npcDef.sequence[droiteI].total);
			}
		}
		_npc.npcDef= _gd->npcDef;
	}

	fclose(f);
}