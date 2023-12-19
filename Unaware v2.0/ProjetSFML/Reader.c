#include "Reader.h"

//si on veut récuperer un int qui se trouve dans une chaine de character
void ReadMapInt(FILE* _file, char _charac[], int* _int)
{
	//on calcule la taille de tout ce qui a été lu par le fscanf,on fait un tok pour arrivé jusqu'a au caractère spéciale
	// et après c'est un soustraction pour arriver jusqu'au int voulu

	int sizeCharac = strlen(_charac);
	char* temp = strtok(_charac, "\"");
	int sizeTemp = strlen(temp);

	sizeTemp -= sizeCharac;
	//+1 pour ne pas récuperer -> "
	fseek(_file, sizeTemp + 1, SEEK_CUR);
	fscanf(_file, "%d", _int);
}

//si on veut récuperer un float qui se trouve dans une chaine de character
void ReadMapFloat(FILE* _file, char _charac[], float* _float)
{
	//on calcule la taille de tout ce qui a été lu par le fscanf,on fait un tok pour arrivé jusqu'a au caractère spéciale
	// et après c'est un soustraction pour arriver jusqu'au int voulu

	int sizeCharac = strlen(_charac);
	char* temp = strtok(_charac, "\"");
	int sizeTemp = strlen(temp);

	sizeTemp -= sizeCharac;
	//+1 pour ne pas récuperer -> "
	fseek(_file, sizeTemp + 1, SEEK_CUR);
	fscanf(_file, "%f", _float);
}

//si on veut récuperer une chaine de caractere dans une chaine de character
void ReadMapChar(FILE* _file, char _charac[], char* _char)
{
	//on calcule la taille de tout ce qui a été lu par le fscanf,on fait un tok pour arrivé jusqu'a au caractère spéciale
	// et après c'est un soustraction pour arriver jusqu'au char voulu
	fscanf(_file, "%s", _charac);

	int sizeCharac = strlen(_charac);
	char* temp = strtok(_charac, "\"");
	int sizeTemp = strlen(temp);
	int size_Char;

	sizeTemp -= sizeCharac;
	//+1 pour ne pas récuperer -> "
	fseek(_file, sizeTemp + 1, SEEK_CUR);
	fscanf(_file, "%s", _char);
	//ici on enleve le dernier caract qui est -> " qui est néfaste 
	size_Char = strlen(_char);
	_char[size_Char - 1] = '\0';
}

//fonction pour lire uniquement les calques d'image de la map 
void ReadFileTiledLayer(MapParameter* _mP, char* _sNom)
{
	FILE* file = fopen(_sNom, "rt");
	if (!(file = fopen(_sNom, "rt"))) {
		printf("Erreur d'acces au fichier...1\n");
		exit(0);
	}

	char recupChara[999];
	int currentLayer = 0;
	int currentBlockCollision = 0;
	int currentObjectDecor = 0;

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//printf("%s\n", recupChara);

		//recuperer witdh, height, tilewitdh et tileheight
		if (!strcmp(recupChara, "<map"))
		{
			//recuperer le witdh de la map
			while (strstr(recupChara, "width") == NULL)
			{
				fscanf(file, "%s", recupChara);
				ReadMapInt(file, recupChara, &_mP->witdh);
			}
			fscanf(file, "%s", &recupChara);
			//recuperer le hieght de la map
			while (strstr(recupChara, "height") == NULL)
			{
				fscanf(file, "%s", recupChara);
				ReadMapInt(file, recupChara, &_mP->height);
			}
			fscanf(file, "%s", &recupChara);
			//recuperer le tilewitdh de la map
			while (strstr(recupChara, "tilewidth") == NULL)
			{
				fscanf(file, "%s", recupChara);
				ReadMapInt(file, recupChara, &_mP->tilewitdh);
			}
			fscanf(file, "%s", &recupChara);
			//recuperer le tileheight de la map
			while (strstr(recupChara, "tileheight") == NULL)
			{
				fscanf(file, "%s", recupChara);
				ReadMapInt(file, recupChara, &_mP->tileheight);
			}

		}
		//
		if (strstr(recupChara, "columns"))
		{
			ReadMapInt(file, recupChara, &_mP->columns);
		}

		//on recucpere les id et les name des map qui sont des tableau
		//a chaque fois qu'on a vu un layer, on fait un ++ sur le current pour s'il y a un autre layer par la suite,
		//on n'écrase pas le layer d'avant
		if (!strcmp(recupChara, "<layer"))
		{
			_mP->nbCalque++;
		}
	}

	_mP->id = calloc(_mP->nbCalque, sizeof(int));
	_mP->mapID = (MapID*)calloc(_mP->nbCalque, sizeof(MapID));

	fseek(file, 0, SEEK_SET);
	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);

		if (!strcmp(recupChara, "<layer"))
		{
			//id layer
			while (strstr(recupChara, "id") == NULL)
			{
				fscanf(file, "%s", recupChara);
				ReadMapInt(file, recupChara, &_mP->id[currentLayer]);
			}
			fscanf(file, "%s", &recupChara);
			//name layer
			while (strstr(recupChara, "name") == NULL)
			{
				ReadMapChar(file, recupChara, &_mP->mapID[currentLayer].name);
			}
			//on va jusqu'au id de la map
			while (strstr(recupChara, "encoding=\"csv\">") == NULL)
			{
				fscanf(file, "%s", &recupChara);
				//printf("%s\n", recupChara);
			}

			_mP->mapID[currentLayer].idMap = calloc(_mP->witdh, sizeof(int*));
			_mP->mapID[currentLayer].needRotate = calloc(_mP->witdh, sizeof(sfBool*));
			for (int i = 0; i < _mP->witdh; i++)
			{
				_mP->mapID[currentLayer].idMap[i] = calloc(_mP->height, sizeof(int));
			}
			for (int i = 0; i < _mP->witdh; i++)
			{
				_mP->mapID[currentLayer].needRotate[i] = calloc(_mP->height, sizeof(sfBool));
			}
			for (int j = 0; j < _mP->height; j++)
			{
				for (int i = 0; i < _mP->witdh; i++)
				{
					fscanf(file, "%d", &_mP->mapID[currentLayer].idMap[i][j]);
					_mP->mapID[currentLayer].idMap[i][j]--;
					_mP->mapID[currentLayer].needRotate[i][j] = sfFalse;
					fscanf(file, "%c", &recupChara);
				}
			}

			currentLayer++;
		}
	}

	//printf("calque %d\n", _mP->nbCalque);

	fclose(file);
}

//fonction collision 
void ReadFileTiledCollision(MapParameter* _mP, char* _sNom)
{
	FILE* file = fopen(_sNom, "rt");
	if (!(file = fopen(_sNom, "rt"))) {
		printf("Erreur d'acces au fichier...2\n");
		exit(0);
	}

	char recupChara[999];
	int currentLayer = 0;
	int currentBlockCollision = 0;
	int currentObjectDecor = 0;

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//printf("%s\n", recupChara);

		//on vient calculer combien il ya de blocs de collision
		if (strstr(recupChara, "name=\"Collision\""))
		{
			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);

			//printf("%s\n", recupChara);
			while (!strcmp(recupChara, "<object"))
			{
				if (!strstr(recupChara, "id="))
				{
					_mP->nbCollision++;
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					//
					fscanf(file, "%s", &recupChara);

				}
			}
		}
	}
	_mP->mapCollision = calloc(_mP->nbCollision, sizeof(MapCollision));
	fseek(file, 0, SEEK_SET);

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//CLAQUE COLLISION
		if (strstr(recupChara, "name=\"Collision\""))
		{
			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);


			while (!strcmp(recupChara, "<object"))
			{
				if (!strstr(recupChara, "id="))
				{
					fscanf(file, "%s", &recupChara);
					ReadMapInt(file, recupChara, &_mP->mapCollision[currentBlockCollision].id);

					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapCollision[currentBlockCollision].pos.x);

					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapCollision[currentBlockCollision].pos.y);

					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapCollision[currentBlockCollision].size.x);

					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapCollision[currentBlockCollision].size.y);
					//printf("%s\n", recupChara);
					fscanf(file, "%s", &recupChara);
					//
					fscanf(file, "%s", &recupChara);

					currentBlockCollision++;
				}
			}
		}
	}

	//printf("collision %d\n", _mP->nbCollision);
	fclose(file);
}

//fonction interaction
void ReadFileTiledInteraction(MapParameter* _mP, char* _sNom)
{
	FILE* file = fopen(_sNom, "rt");
	if (!(file = fopen(_sNom, "rt"))) {
		printf("Erreur d'acces au fichier...3\n");
		exit(0);
	}

	char recupChara[999];
	int currentBlockInteraction = 0;

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//printf("%s\n", recupChara);

		//on vient calculer combien il ya de blocs de collision
		if (strstr(recupChara, "name=\"Interraction\""))
		{
			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);

			while (!strcmp(recupChara, "<object"))
			{

				if (!strstr(recupChara, "id="))
				{
					_mP->nbInteraction++;

					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);

					//
					fscanf(file, "%s", &recupChara);
				}
			}
		}
	}
	_mP->mapInteraction = calloc(_mP->nbInteraction, sizeof(MapInteraction));
	fseek(file, 0, SEEK_SET);

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//CLAQUE COLLISION
		if (strstr(recupChara, "name=\"Interraction\""))
		{
			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);

			while (!strcmp(recupChara, "<object"))
			{

				if (!strstr(recupChara, "id="))
				{
					fscanf(file, "%s", &recupChara);
					ReadMapInt(file, recupChara, &_mP->mapInteraction[currentBlockInteraction].id);
					fscanf(file, "%s", &recupChara);
					ReadMapChar(file, recupChara, &_mP->mapInteraction[currentBlockInteraction].name);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapInteraction[currentBlockInteraction].pos.x);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapInteraction[currentBlockInteraction].pos.y);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapInteraction[currentBlockInteraction].size.x);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapInteraction[currentBlockInteraction].size.y);

					fscanf(file, "%s", &recupChara);
					//
					fscanf(file, "%s", &recupChara);
					currentBlockInteraction++;
				}
			}
		}
	}

	//printf("interaction %d\n", _mP->nbInteraction);
	fclose(file);
}

//fonction destructible
void ReadFileTiledDestructible(MapParameter* _mP, char* _sNom)
{
	FILE* file = fopen(_sNom, "rt");
	if (!(file = fopen(_sNom, "rt"))) {
		printf("Erreur d'acces au fichier..4.\n");
		exit(0);
	}

	char recupChara[999];
	int currentBlockDestructible = 0;

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//printf("%s\n", recupChara);

		//on vient calculer combien il ya de blocs de collision
		if (strstr(recupChara, "name=\"Destructible\""))
		{
			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);

			while (!strcmp(recupChara, "<object"))
			{
				if (!strstr(recupChara, "id="))
				{
					_mP->nbDestructible++;
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
				}
			}
		}
	}
	_mP->mapDestructible = calloc(_mP->nbDestructible, sizeof(MapDestructible));
	fseek(file, 0, SEEK_SET);

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//CLAQUE COLLISION
		if (strstr(recupChara, "name=\"Destructible\""))
		{
			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);
			while (!strcmp(recupChara, "<object"))
			{
				if (!strstr(recupChara, "id="))
				{
					fscanf(file, "%s", &recupChara);
					ReadMapInt(file, recupChara, &_mP->mapDestructible[currentBlockDestructible].id);
					fscanf(file, "%s", &recupChara);

					ReadMapChar(file, recupChara, &_mP->mapDestructible[currentBlockDestructible].name);
					fscanf(file, "%s", &recupChara);
					//fscanf(file, "%s", &recupChara);

					ReadMapFloat(file, recupChara, &_mP->mapDestructible[currentBlockDestructible].pos.x);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapDestructible[currentBlockDestructible].pos.y);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapDestructible[currentBlockDestructible].size.x);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapDestructible[currentBlockDestructible].size.y);
					fscanf(file, "%s", &recupChara);
					//
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					if (!strstr(recupChara, "name=active"))
					{
						fscanf(file, "%s", &recupChara);
						fscanf(file, "%s", &recupChara);

						if (!strcmp(recupChara, "value=\"true\"/>"))
						{
							_mP->mapDestructible[currentBlockDestructible].active = sfTrue;
						}
						else
						{
							_mP->mapDestructible[currentBlockDestructible].active = sfFalse;
						}
						fscanf(file, "%s", &recupChara);
						fscanf(file, "%s", &recupChara);

					}
					if (!strstr(recupChara, "name=recup"))
					{
						fscanf(file, "%s", &recupChara);
						fscanf(file, "%s", &recupChara);
						if (!strcmp(recupChara, "value=\"true\"/>"))
						{

							_mP->mapDestructible[currentBlockDestructible].recup = sfTrue;
						}
						else
						{
							_mP->mapDestructible[currentBlockDestructible].recup = sfFalse;
						}

					}

					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);


					currentBlockDestructible++;
				}
			}
		}
	}

	//printf("destructible %d\n", _mP->nbDestructible);
	fclose(file);
}

void ReadFileTiledPoint(MapParameter* _mP, char* _sNom)
{
	FILE* file = fopen(_sNom, "rt");
	if (!(file = fopen(_sNom, "rt"))) {
		printf("Erreur d'acces au fichier...5\n");
		exit(0);
	}

	char recupChara[999];
	int currentPoint = 0;

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//printf("%s\n", recupChara);

		//on vient calculer combien il ya de blocs de collision
		if (strstr(recupChara, "name=\"Point\""))
		{
			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);

			while (!strcmp(recupChara, "<object"))
			{
				if (!strstr(recupChara, "id="))
				{

					_mP->nbPoint++;
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
				}
			}
		}
	}
	_mP->mapPoint = calloc(_mP->nbPoint, sizeof(MapPoint));
	fseek(file, 0, SEEK_SET);

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//CLAQUE COLLISION
		if (strstr(recupChara, "name=\"Point\""))
		{
			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);
			while (!strcmp(recupChara, "<object"))
			{

				if (!strstr(recupChara, "id="))
				{
					fscanf(file, "%s", &recupChara);
					ReadMapInt(file, recupChara, &_mP->mapPoint[currentPoint].id);
					fscanf(file, "%s", &recupChara);
					ReadMapChar(file, recupChara, &_mP->mapPoint[currentPoint].name);
					fscanf(file, "%s", &recupChara);
					ReadMapInt(file, recupChara, &_mP->mapPoint[currentPoint].pos.x);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapInt(file, recupChara, &_mP->mapPoint[currentPoint].pos.y);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);

					if (!strstr(recupChara, "name=spawn"))
					{
						if (!strcmp(recupChara, "value=\"true\"/>"))
						{
							_mP->mapPoint[currentPoint].active = sfTrue;

						}
						else
						{

							_mP->mapPoint[currentPoint].active = sfFalse;
						}
					}

					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);


					currentPoint++;
				}
			}
		}
	}

	//printf("point %d\n", _mP->nbPoint);
	fclose(file);
}

void ReadFileTiledNPC(MapParameter* _mP, char* _sNom)
{
	FILE* file = fopen(_sNom, "rt");
	if (!(file = fopen(_sNom, "rt"))) {
		printf("Erreur d'acces au fichier...6\n");
		exit(0);
	}

	char recupChara[999];
	int currentPoint = 0;

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//printf("%s\n", recupChara);
		//on vient calculer combien il ya de blocs de collision
		if (strstr(recupChara, "name=\"PNJ\"") != NULL)
		{

			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);

			while (!strcmp(recupChara, "<object"))
			{
				if (!strstr(recupChara, "id="))
				{

					_mP->nbNPC++;
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
				}
			}
		}
	}
	_mP->mapNPC = calloc(_mP->nbNPC, sizeof(MapPoint));
	fseek(file, 0, SEEK_SET);

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//CLAQUE COLLISION
		if (strstr(recupChara, "name=\"PNJ\""))
		{
			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);
			while (!strcmp(recupChara, "<object"))
			{
				if (!strstr(recupChara, "id="))
				{
					fscanf(file, "%s", &recupChara);
					ReadMapInt(file, recupChara, &_mP->mapNPC[currentPoint].id);
					fscanf(file, "%s", &recupChara);
					ReadMapChar(file, recupChara, &_mP->mapNPC[currentPoint].name);
					fscanf(file, "%s", &recupChara);
					ReadMapInt(file, recupChara, &_mP->mapNPC[currentPoint].pos.x);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapInt(file, recupChara, &_mP->mapNPC[currentPoint].pos.y);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					printf("%s\n", recupChara);
					currentPoint++;
				}
			}
		}
	}

	//printf("pnj %d\n", _mP->nbNPC);
	fclose(file);
}

void ReadFileTiledAnim(MapParameter* _mP, char* _sNom)
{
	FILE* file = fopen(_sNom, "rt");
	if (!(file = fopen(_sNom, "rt"))) {
		printf("Erreur d'acces au fichier...7\n");
		exit(0);
	}
	char recupChara[999] = { 0 };
	int currentIDAnim = 0;
	int currentIDPropriety = 0;

	int idTemp;
	//parcours fichier 1 fois pour savoir combien il y a des sprites animé
	_mP->nbAnimSprite = 0;

	//je lis une premiere fois le fichier pour savoir combien j'ai d'animation
	while (!feof(file))
	{
		fscanf(file, "%s", recupChara);

		if (strstr(recupChara, "id=\""))
		{
			fscanf(file, "%s", recupChara);
			if (strstr(recupChara, "animation"))
			{
				_mP->nbAnimSprite++;
			}
			else if (strstr(recupChara, "etat"))
			{
				_mP->nbProprietySprite++;
			}
		}


	}
	fseek(file, 0, SEEK_SET);
	_mP->animTiled.id = calloc(_mP->nbAnimSprite, sizeof(int));
	_mP->animTiled.needRotate = calloc(_mP->nbAnimSprite, sizeof(sfBool));
	_mP->animTiled.spriteAnim = (AnimationID*)calloc(_mP->nbAnimSprite, sizeof(AnimationID));
	_mP->proprietySprite = (ProprietySprite*)calloc(_mP->nbProprietySprite, sizeof(ProprietySprite));


	//je lis ensuite une seconde fois pour attribuer l'id animation
	while (!feof(file))
	{
		fscanf(file, "%s", recupChara);
		//printf("%s\n", recupChara);

		if (strstr(recupChara, "id=\""))
		{
			ReadMapInt(file, recupChara, &idTemp);
			//printf("%d\n", idTemp);
			fscanf(file, "%s", recupChara);
			fscanf(file, "%s", recupChara);
			//fscanf(file, "%s", recupChara);


			if (strstr(recupChara, "animation"))
			{
				int nbIdImage = 0;

				fscanf(file, "%s", recupChara);
				fscanf(file, "%s", recupChara);
				_mP->animTiled.id[currentIDAnim] = idTemp;
				//ici je calcule combien j'ai d'image dans mon animation

				while (!strcmp(recupChara, "<frame"))
				{
					nbIdImage++;
					fscanf(file, "%s", recupChara);
					fscanf(file, "%s", recupChara);
					fscanf(file, "%s", recupChara);
				}
				_mP->animTiled.spriteAnim[currentIDAnim].id = calloc(nbIdImage, sizeof(int));
				_mP->animTiled.spriteAnim[currentIDAnim].ttl = calloc(nbIdImage, sizeof(int));
				_mP->animTiled.spriteAnim[currentIDAnim].idMother = _mP->animTiled.id[currentIDAnim];
				_mP->animTiled.spriteAnim[currentIDAnim].nbImageInAnim = nbIdImage;
				currentIDAnim++;
			}
			else if (strstr(recupChara, "etat"))
			{
				_mP->proprietySprite[currentIDPropriety].id = idTemp;


				fscanf(file, "%s", recupChara);
				fscanf(file, "%s", recupChara);
				fscanf(file, "%s", recupChara);
				ReadMapChar(file, recupChara, &_mP->proprietySprite[currentIDPropriety].name);
				fscanf(file, "%s", recupChara);

				int size_Char;

				size_Char = strlen(_mP->proprietySprite[currentIDPropriety].name);
				_mP->proprietySprite[currentIDPropriety].name[size_Char - 2] = '\0';

				currentIDPropriety++;
			}
		}
	}
	fseek(file, 0, SEEK_SET);
	currentIDAnim = 0;
	//je lis une troisieme  pour les id des images
	while (!feof(file))
	{
		fscanf(file, "%s", recupChara);
		//printf("%s\n", recupChara);

		if (strstr(recupChara, "id=\""))
		{
			fscanf(file, "%s", recupChara);
			if (strstr(recupChara, "animation"))
			{
				int nbIdImage = 0;

				fscanf(file, "%s", recupChara);
				fscanf(file, "%s", recupChara);
				fscanf(file, "%s", recupChara);
				//ici je calcule combien j'ai d'image dans mon animation
				while (nbIdImage != _mP->animTiled.spriteAnim[currentIDAnim].nbImageInAnim)
				{
					//id

					ReadMapInt(file, recupChara, &_mP->animTiled.spriteAnim[currentIDAnim].id[nbIdImage]);

					fscanf(file, "%s", recupChara);
					fscanf(file, "%s", recupChara);
					fscanf(file, "%s", recupChara);
					fscanf(file, "%s", recupChara);

					nbIdImage++;
				}
				currentIDAnim++;
			}
		}
	}

	fseek(file, 0, SEEK_SET);
	currentIDAnim = 0;
	while (!feof(file))
	{
		fscanf(file, "%s", recupChara);
		//printf("%s\n", recupChara);
		if (strstr(recupChara, "id=\""))
		{
			fscanf(file, "%s", recupChara);
			if (strstr(recupChara, "animation"))
			{

				int nbIdImage = 0;
				fscanf(file, "%s", recupChara);
				fscanf(file, "%s", recupChara);
				fscanf(file, "%s", recupChara);

				//ici je calcule combien j'ai d'image dans mon animation
				while (nbIdImage != _mP->animTiled.spriteAnim[currentIDAnim].nbImageInAnim)
				{

					ReadMapInt(file, recupChara, &_mP->animTiled.spriteAnim[currentIDAnim].id[nbIdImage]);

					//temp
					fscanf(file, "%s", recupChara);
					fscanf(file, "%s", recupChara);
					//printf("%s\n", recupChara);

					ReadMapFloat(file, recupChara, &_mP->animTiled.spriteAnim[currentIDAnim].ttl[nbIdImage]);
					fscanf(file, "%s", recupChara);
					fscanf(file, "%s", recupChara);
					fscanf(file, "%s", recupChara);


					nbIdImage++;
				}
				currentIDAnim++;
			}
		}
	}

	//printf("nb anim : %d,  nbpropri : %d\n", _mP->nbAnimSprite, _mP->nbProprietySprite);

	fclose(file);
}

void ReadFileTiledPointSound(MapParameter* _mP, char* _sNom)
{
	FILE* file = fopen(_sNom, "rt");
	if (!(file = fopen(_sNom, "rt"))) {
		printf("Erreur d'acces au fichier...8\n");
		exit(0);
	}

	char recupChara[999];
	int currentPoint = 0;
	char lastPointName[999];
	int nbCurrentTypePoint = 0;
	int soundArrayPos = 0;

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//printf("%s\n", recupChara);
		//on vient calculer combien il ya de blocs de collision
		if (strstr(recupChara, "name=\"PointSound\"") != NULL)
		{

			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);

			while (!strcmp(recupChara, "<object"))
			{
				if (!strstr(recupChara, "id="))
				{

					_mP->nbPointSound++;
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);

				}
			}
		}
	}
	_mP->mapPointSound = calloc(_mP->nbPointSound + 1, sizeof(MapPointSound));
	fseek(file, 0, SEEK_SET);

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//CLAQUE COLLISION
		if (strstr(recupChara, "name=\"PointSound\""))
		{
			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);
			while (!strcmp(recupChara, "<object"))
			{
				if (!strstr(recupChara, "id="))
				{
					fscanf(file, "%s", &recupChara);
					ReadMapInt(file, recupChara, &_mP->mapPointSound[currentPoint].id);
					fscanf(file, "%s", &recupChara);
					ReadMapChar(file, recupChara, &_mP->mapPointSound[currentPoint].name);
					fscanf(file, "%s", &recupChara);
					ReadMapInt(file, recupChara, &_mP->mapPointSound[currentPoint].pos.x);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapInt(file, recupChara, &_mP->mapPointSound[currentPoint].pos.y);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapPointSound[currentPoint].minDistance);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);

					if (currentPoint == 0)
					{
						strcpy(lastPointName, &_mP->mapPointSound[currentPoint].name);
					}
					if (!strcmp(&_mP->mapPointSound[currentPoint].name, lastPointName))
					{
						nbCurrentTypePoint++;
						strcpy(lastPointName, &_mP->mapPointSound[currentPoint].name);
					}
					else
					{
						if (!strcmp(lastPointName, "panneau_electrique"))
						{
							//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
							_mP->introPointSound.electricity = calloc(nbCurrentTypePoint, sizeof(Sound));
							_mP->nbElec = soundArrayPos;
						}
						else if (!strcmp(lastPointName, "chat"))
						{
							//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
							_mP->introPointSound.cat = calloc(nbCurrentTypePoint, sizeof(Sound));
							_mP->nbCat = soundArrayPos;
						}
						else if (!strcmp(lastPointName, "ventilation"))
						{
							//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
							_mP->introPointSound.ventilation = calloc(nbCurrentTypePoint, sizeof(Sound));
							_mP->nbVent = soundArrayPos;
						}
						else if (!strcmp(lastPointName, "Console"))
						{
							//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
							_mP->introPointSound.console = calloc(nbCurrentTypePoint, sizeof(Sound));
							_mP->nbConsole = soundArrayPos;
						}
						else if (!strcmp(lastPointName, "Waterfall"))
						{
							//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
							_mP->islandPointSound.waterfall = calloc(nbCurrentTypePoint, sizeof(Sound));
							_mP->nbWaterfall = soundArrayPos;
						}
						else if (!strcmp(lastPointName, "Well"))
						{
						//	printf("%s %d\n", lastPointName, nbCurrentTypePoint);
							_mP->islandPointSound.well = calloc(nbCurrentTypePoint, sizeof(Sound));
							_mP->nbWell = soundArrayPos;
						}
						else if (!strcmp(lastPointName, "Fire"))
						{
							//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
							_mP->islandPointSound.fire = calloc(nbCurrentTypePoint, sizeof(Sound));
							_mP->nbFire = soundArrayPos;
						}
						else if (!strcmp(lastPointName, "Fish"))
						{
							//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
							_mP->islandPointSound.fish = calloc(nbCurrentTypePoint, sizeof(Sound));
							_mP->nbFish = soundArrayPos;
						}
						else if (!strcmp(lastPointName, "Lac"))
						{
							//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
							_mP->islandPointSound.lake = calloc(nbCurrentTypePoint, sizeof(Sound));
							_mP->nbLake = soundArrayPos;
						}
						else if (!strcmp(lastPointName, "Snake"))
						{
							//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
							_mP->junglePointSound.snake = calloc(nbCurrentTypePoint, sizeof(Sound));
							_mP->nbSnake = soundArrayPos;
						}

						soundArrayPos = currentPoint;
						nbCurrentTypePoint = 1;
						strcpy(lastPointName, &_mP->mapPointSound[currentPoint].name);
					}

					currentPoint++;
				}

			}
			if (strcmp(&_mP->mapPointSound[currentPoint + 1].name, lastPointName))
			{
				if (!strcmp(lastPointName, "panneau_electrique"))
				{
					//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
					_mP->introPointSound.electricity = calloc(nbCurrentTypePoint, sizeof(Sound));
					_mP->nbElec = soundArrayPos;
				}
				else if (!strcmp(lastPointName, "chat"))
				{
					//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
					_mP->introPointSound.cat = calloc(nbCurrentTypePoint, sizeof(Sound));
					_mP->nbCat = soundArrayPos;
				}
				else if (!strcmp(lastPointName, "ventilation"))
				{
					//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
					_mP->introPointSound.ventilation = calloc(nbCurrentTypePoint, sizeof(Sound));
					_mP->nbVent = soundArrayPos;
				}
				else if (!strcmp(lastPointName, "Console"))
				{
				//	printf("%s %d\n", lastPointName, nbCurrentTypePoint);
					_mP->introPointSound.console = calloc(nbCurrentTypePoint, sizeof(Sound));
					_mP->nbConsole = soundArrayPos;
				}
				else if (!strcmp(lastPointName, "Waterfall"))
				{
					//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
					_mP->islandPointSound.waterfall = calloc(nbCurrentTypePoint, sizeof(Sound));
					_mP->nbWaterfall = soundArrayPos;
				}
				else if (!strcmp(lastPointName, "Well"))
				{
					//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
					_mP->islandPointSound.well = calloc(nbCurrentTypePoint, sizeof(Sound));
					_mP->nbWell = soundArrayPos;
				}
				else if (!strcmp(lastPointName, "Fire"))
				{
					//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
					_mP->islandPointSound.fire = calloc(nbCurrentTypePoint, sizeof(Sound));
					_mP->nbFire = soundArrayPos;
				}
				else if (!strcmp(lastPointName, "Fish"))
				{
					//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
					_mP->islandPointSound.fish = calloc(nbCurrentTypePoint, sizeof(Sound));
					_mP->nbFish = soundArrayPos;
				}
				else if (!strcmp(lastPointName, "Lac"))
				{
				//	printf("%s %d\n", lastPointName, nbCurrentTypePoint);
					_mP->islandPointSound.lake = calloc(nbCurrentTypePoint, sizeof(Sound));
					_mP->nbLake = soundArrayPos;
				}
				else if (!strcmp(lastPointName, "Snake"))
				{
					//printf("%s %d\n", lastPointName, nbCurrentTypePoint);
					_mP->junglePointSound.snake = calloc(nbCurrentTypePoint, sizeof(Sound));
					_mP->nbSnake = soundArrayPos;
				}
			}
		}
	}

	//printf("pointSound  %d\n", _mP->nbPointSound);
	fclose(file);
}

void ReadFileTiledTriggerSound(MapParameter* _mP, char* _sNom)
{
	FILE* file = fopen(_sNom, "rt");
	if (!(file = fopen(_sNom, "rt"))) {
		printf("Erreur d'acces au fichier...9\n");
		exit(0);
	}

	char recupChara[999];
	int currentBlockInteraction = 0;

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//printf("%s\n", recupChara);

		//on vient calculer combien il ya de blocs de collision
		if (strstr(recupChara, "name=\"TriggerSound\""))
		{
			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);

			while (!strcmp(recupChara, "<object"))
			{

				if (!strstr(recupChara, "id="))
				{
					_mP->nbTriggerSound++;
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);

				}
			}
		}
	}
	_mP->mapTriggerSound = calloc(_mP->nbTriggerSound, sizeof(MapTriggerSound));
	fseek(file, 0, SEEK_SET);

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//CLAQUE COLLISION
		if (strstr(recupChara, "name=\"TriggerSound\""))
		{
			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);
			while (!strcmp(recupChara, "<object"))
			{
				if (!strstr(recupChara, "id="))
				{
					fscanf(file, "%s", &recupChara);
					ReadMapInt(file, recupChara, &_mP->mapTriggerSound[currentBlockInteraction].id);
					fscanf(file, "%s", &recupChara);
					ReadMapChar(file, recupChara, &_mP->mapTriggerSound[currentBlockInteraction].name);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapTriggerSound[currentBlockInteraction].pos.x);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapTriggerSound[currentBlockInteraction].pos.y);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapTriggerSound[currentBlockInteraction].size.x);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapTriggerSound[currentBlockInteraction].size.y);
					fscanf(file, "%s", &recupChara);
					//
					fscanf(file, "%s", &recupChara);
					currentBlockInteraction++;
				}
			}
		}
	}

	//printf("triggerSound %d\n", _mP->nbTriggerSound);
	fclose(file);
}

void ReadFileTiledTriggerIA(MapParameter* _mP, char* _sNom)
{
	FILE* file = fopen(_sNom, "rt");
	if (!(file = fopen(_sNom, "rt"))) {
		printf("Erreur d'acces au fichier...11\n");
		exit(0);
	}

	char recupChara[999];
	int currentBlockInteraction = 0;

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//printf("%s\n", recupChara);

		//on vient calculer combien il ya de blocs de collision
		if (strstr(recupChara, "name=\"TriggerIA\""))
		{
			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);

			while (!strcmp(recupChara, "<object"))
			{

				if (!strstr(recupChara, "id="))
				{
					_mP->nbMapTriggerIA++;
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);

				}

			}
		}
	}
	_mP->mapTriggerIA = calloc(_mP->nbMapTriggerIA, sizeof(MapTriggerIA));
	fseek(file, 0, SEEK_SET);

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//CLAQUE COLLISION
		if (strstr(recupChara, "name=\"TriggerIA\""))
		{
			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);
			while (!strcmp(recupChara, "<object"))
			{
				if (!strstr(recupChara, "id="))
				{
					fscanf(file, "%s", &recupChara);
					ReadMapInt(file, recupChara, &_mP->mapTriggerIA[currentBlockInteraction].id);
					fscanf(file, "%s", &recupChara);
					ReadMapChar(file, recupChara, &_mP->mapTriggerIA[currentBlockInteraction].name);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapTriggerIA[currentBlockInteraction].pos.x);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapTriggerIA[currentBlockInteraction].pos.y);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapTriggerIA[currentBlockInteraction].size.x);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapTriggerIA[currentBlockInteraction].size.y);
					fscanf(file, "%s", &recupChara);
					//
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);

					if (!strstr(recupChara, "name=done"))
					{
						fscanf(file, "%s", &recupChara);
						fscanf(file, "%s", &recupChara);

						if (!strcmp(recupChara, "value=\"true\"/>"))
						{
							_mP->mapTriggerIA[currentBlockInteraction].done = sfTrue;
						}
						else
						{
							_mP->mapTriggerIA[currentBlockInteraction].done = sfFalse;
						}
						fscanf(file, "%s", &recupChara);
						fscanf(file, "%s", &recupChara);

					}
					fscanf(file, "%s", &recupChara);

					currentBlockInteraction++;
					printf("%s\n", recupChara);

				}
			}
		}
	}

	//printf("triggerIA %d\n", _mP->nbMapTriggerIA);
	fclose(file);
}

void ReadFileTiledLabyrinthe(MapParameter* _mP, char* _sNom)
{
	FILE* file = fopen(_sNom, "rt");
	if (!(file = fopen(_sNom, "rt"))) {
		printf("Erreur d'acces au fichier...10\n");
		exit(0);
	}

	char recupChara[999];
	int currentBlockInteraction = 0;

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//printf("%s\n", recupChara);
		//on vient calculer combien il ya de blocs de collision
		if (strstr(recupChara, "name=\"PlayMusic\""))
		{
			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);

			while (!strcmp(recupChara, "<object"))
			{

				if (!strstr(recupChara, "id="))
				{
					_mP->nbMapLabyrinthe++;

					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);

				}
			}
		}
	}
	_mP->mapLabyrinthe = calloc(_mP->nbMapLabyrinthe, sizeof(MapLabyrinthe));
	fseek(file, 0, SEEK_SET);

	while (!feof(file))
	{
		fscanf(file, "%s", &recupChara);
		//CLAQUE COLLISION
		if (strstr(recupChara, "name=\"PlayMusic\""))
		{
			fscanf(file, "%s", &recupChara);
			fscanf(file, "%s", &recupChara);

			while (!strcmp(recupChara, "<object"))
			{

				if (!strstr(recupChara, "id="))
				{
					fscanf(file, "%s", &recupChara);
					ReadMapInt(file, recupChara, &_mP->mapLabyrinthe[currentBlockInteraction].id);
					fscanf(file, "%s", &recupChara);
					ReadMapChar(file, recupChara, &_mP->mapLabyrinthe[currentBlockInteraction].name);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapLabyrinthe[currentBlockInteraction].pos.x);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapLabyrinthe[currentBlockInteraction].pos.y);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapLabyrinthe[currentBlockInteraction].size.x);
					fscanf(file, "%s", &recupChara);
					fscanf(file, "%s", &recupChara);
					ReadMapFloat(file, recupChara, &_mP->mapLabyrinthe[currentBlockInteraction].size.y);

					fscanf(file, "%s", &recupChara);
					//
					fscanf(file, "%s", &recupChara);
					currentBlockInteraction++;
				}
			}
		}
	}

	//printf("chemin music %d\n", _mP->nbMapLabyrinthe);
	fclose(file);
}


//temoin fonction pour lire tiled
//void ReadFileTiled(GameData* _gd)
//{
//	//lecture fichier map 
//	{
//		FILE* file = fopen("../Ressources/Map/mapShip.xml", "rt");
//		if (!(file = fopen("../Ressources/Map/mapShip.xml", "rt"))) {
//			printf("Erreur d'acces au fichier...\n");
//			exit(0);
//		}
//
//		char recupChara[999];
//		int currentLayer = 0;
//		int currentBlockCollision = 0;
//		int currentObjectDecor = 0;
//
//		while (!feof(file))
//		{
//			fscanf(file, "%s", &recupChara);
//			//printf("%s\n", recupChara);
//
//			//recuperer witdh, height, tilewitdh et tileheight
//			if (!strcmp(recupChara, "<map"))
//			{
//				//recuperer le witdh de la map
//				while (strstr(recupChara, "width") == NULL)
//				{
//					fscanf(file, "%s", recupChara);
//					ReadMapInt(file, recupChara, &_gd->mapParameter.witdh);
//				}
//				fscanf(file, "%s", &recupChara);
//				//recuperer le hieght de la map
//				while (strstr(recupChara, "height") == NULL)
//				{
//					fscanf(file, "%s", recupChara);
//					ReadMapInt(file, recupChara, &_gd->mapParameter.height);
//				}
//				fscanf(file, "%s", &recupChara);
//				//recuperer le tilewitdh de la map
//				while (strstr(recupChara, "tilewidth") == NULL)
//				{
//					fscanf(file, "%s", recupChara);
//					ReadMapInt(file, recupChara, &_gd->mapParameter.tilewitdh);
//				}
//				fscanf(file, "%s", &recupChara);
//				//recuperer le tileheight de la map
//				while (strstr(recupChara, "tileheight") == NULL)
//				{
//					fscanf(file, "%s", recupChara);
//					ReadMapInt(file, recupChara, &_gd->mapParameter.tileheight);
//				}
//
//			}
//			//
//			if (!strcmp(recupChara, "columns=\"20\">"))
//			{
//				ReadMapInt(file, recupChara, &_gd->mapParameter.columns);
//			}
//
//			//on recucpere les id et les name des map qui sont des tableau
//			//a chaque fois qu'on a vu un layer, on fait un ++ sur le current pour s'il y a un autre layer par la suite,
//			//on n'écrase pas le layer d'avant
//			if (!strcmp(recupChara, "<layer"))
//			{
//				_gd->mapParameter.nbCalque++;
//			}
//			//pour le calque de profondeur
//			/*if (!strcmp(recupChara, "name=\"objectDecor\""))
//			{
//				fscanf(file, "%s", &recupChara);
//				fscanf(file, "%s", &recupChara);
//
//				while (!strcmp(recupChara, "<object"))
//				{
//					if (!strstr(recupChara, "id="))
//					{
//						_mapParameter->nbObjectDecor++;
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//					}
//					fscanf(file, "%s", &recupChara);
//				}
//			}*/
//
//			//on vient calculer combien il ya de blocs de collision
//			if (!strcmp(recupChara, "name=\"collisionMove\">"))
//			{
//				fscanf(file, "%s", &recupChara);
//				//printf("%s\n", recupChara);
//				while (!strcmp(recupChara, "<object"))
//				{
//					if (!strstr(recupChara, "id="))
//					{
//						_gd->mapParameter.nbCollision++;
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						//
//						fscanf(file, "%s", &recupChara);
//
//					}
//				}
//			}
//		}
//
//		_gd->mapParameter.id = calloc(_gd->mapParameter.nbCalque, sizeof(int));
//
//		_gd->mapParameter.mapID = (MapID*)calloc(_gd->mapParameter.nbCalque, sizeof(MapID));
//		//_mapParameter->prof = calloc(_mapParameter->nbObjectDecor, sizeof(struct Profondeur));
//		_gd->mapParameter.mapCollision = calloc(_gd->mapParameter.nbCollision, sizeof(MapCollision));
//		fseek(file, 0, SEEK_SET);
//		while (!feof(file))
//		{
//			fscanf(file, "%s", &recupChara);
//
//			if (!strcmp(recupChara, "<layer"))
//			{
//				//id layer
//				while (strstr(recupChara, "id") == NULL)
//				{
//					fscanf(file, "%s", recupChara);
//					ReadMapInt(file, recupChara, &_gd->mapParameter.id[currentLayer]);
//				}
//				fscanf(file, "%s", &recupChara);
//				//name layer
//				while (strstr(recupChara, "name") == NULL)
//				{
//					ReadMapChar(file, recupChara, &_gd->mapParameter.mapID[currentLayer].name);
//				}
//				//on va jusqu'au id de la map
//				while (strstr(recupChara, "encoding=\"csv\">") == NULL)
//				{
//					fscanf(file, "%s", &recupChara);
//					//printf("%s\n", recupChara);
//				}
//
//				_gd->mapParameter.mapID[currentLayer].idMap = calloc(_gd->mapParameter.witdh, sizeof(int*));
//				_gd->mapParameter.mapID[currentLayer].needRotate = calloc(_gd->mapParameter.witdh, sizeof(sfBool*));
//				for (int i = 0; i < _gd->mapParameter.witdh; i++)
//				{
//					_gd->mapParameter.mapID[currentLayer].idMap[i] = calloc(_gd->mapParameter.height, sizeof(int));
//				}
//				for (int i = 0; i < _gd->mapParameter.witdh; i++)
//				{
//					_gd->mapParameter.mapID[currentLayer].needRotate[i] = calloc(_gd->mapParameter.height, sizeof(sfBool));
//				}
//
//				for (int i = 0; i < _gd->mapParameter.witdh; i++)
//				{
//					for (int j = 0; j < _gd->mapParameter.height; j++)
//					{
//						fscanf(file, "%d", &_gd->mapParameter.mapID[currentLayer].idMap[i][j]);
//						_gd->mapParameter.mapID[currentLayer].idMap[i][j]--;
//						_gd->mapParameter.mapID[currentLayer].needRotate[i][j] = sfFalse;
//						fscanf(file, "%c", &recupChara);
//					}
//				}
//
//				currentLayer++;
//			}
//			//CALQUE OBJECT DECOR 
//			/*if (!strcmp(recupChara, "name=\"objectDecor\""))
//			{
//				fscanf(file, "%s", &recupChara);
//				fscanf(file, "%s", &recupChara);
//
//				while (!strcmp(recupChara, "<object"))
//				{
//					if (!strstr(recupChara, "id="))
//					{
//						fscanf(file, "%s", &recupChara);
//						ReadMapInt(file, recupChara, &_mapParameter->prof[currentObjectDecor].id);
//						fscanf(file, "%s", &recupChara);
//						ReadMapChar(file, recupChara, &_mapParameter->prof[currentObjectDecor].name);
//						fscanf(file, "%s", &recupChara);
//						ReadMapFloat(file, recupChara, &_mapParameter->prof[currentObjectDecor].pos.x);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						ReadMapFloat(file, recupChara, &_mapParameter->prof[currentObjectDecor].pos.y);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						printf("%s\n", recupChara);
//						currentObjectDecor++;
//					}
//					fscanf(file, "%s", &recupChara);
//				}
//			}*/
//
//			//CLAQUE COLLISION
//			if (!strcmp(recupChara, "name=\"collisionMove\">"))
//			{
//				fscanf(file, "%s", &recupChara);
//
//				while (!strcmp(recupChara, "<object"))
//				{
//					if (!strstr(recupChara, "id="))
//					{
//						fscanf(file, "%s", &recupChara);
//						ReadMapInt(file, recupChara, &_gd->mapParameter.mapCollision[currentBlockCollision].id);
//
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						ReadMapFloat(file, recupChara, &_gd->mapParameter.mapCollision[currentBlockCollision].pos.x);
//
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						ReadMapFloat(file, recupChara, &_gd->mapParameter.mapCollision[currentBlockCollision].pos.y);
//
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						ReadMapFloat(file, recupChara, &_gd->mapParameter.mapCollision[currentBlockCollision].size.x);
//
//						fscanf(file, "%s", &recupChara);
//						fscanf(file, "%s", &recupChara);
//						ReadMapFloat(file, recupChara, &_gd->mapParameter.mapCollision[currentBlockCollision].size.y);
//						//printf("%s\n", recupChara);
//						fscanf(file, "%s", &recupChara);
//						//
//						fscanf(file, "%s", &recupChara);
//
//						currentBlockCollision++;
//					}
//				}
//			}
//		}
//
//		printf("%d\n", _gd->mapParameter.nbCalque);
//		//printf("%d\n", _mapParameter->nbObjectDecor);
//		printf("%d\n", _gd->mapParameter.nbCollision);
//
//		fclose(file);
//	}
//
//	{
//	}
//	//lecture fichier image tiled pour animation
//	/*{
//		FILE* file = fopen("../Ressources/Map/mapShip.xml", "rt");
//		if (!(file = fopen("../Ressources/Map/mapShip.xml", "rt"))) {
//			printf("Erreur d'acces au fichier...\n");
//			exit(0);
//		}
//		char recupChara[999] = { 0 };
//		int currentID = 0;
//		//parcours fichier 1 fois pour savoir combien il y a des sprites animé
//		_gd->mapParameter.nbAnimSpriteForet = 0;
//
//		//je lis une premiere fois le fichier pour savoir combien j'ai d'animation
//		while (!feof(file))
//		{
//			fscanf(file, "%s", recupChara);
//			//printf("%s\n", recupChara);
//			if (strstr(recupChara, "id=\"") &&
//				!strstr(recupChara, "tileid=\""))
//			{
//				//printf("%s\n", recupChara);
//				_gd->mapParameter.nbAnimSpriteForet++;
//			}
//		}
//		fseek(file, 0, SEEK_SET);
//		_gd->mapParameter.animTiled.id = calloc(_gd->mapParameter.nbAnimSpriteForet, sizeof(int));
//		_gd->mapParameter.animTiled.spriteAnim = (AnimationID*)calloc(_gd->mapParameter.nbAnimSpriteForet, sizeof(AnimationID));
//
//		//je lis ensuite une seconde fois pour attribuer l'id animation
//		while (!feof(file))
//		{
//			fscanf(file, "%s", recupChara);
//			//printf("%s\n", recupChara);
//			if (strstr(recupChara, "id=\"") &&
//				!strstr(recupChara, "tileid=\""))
//			{
//				int nbIdImage = 0;
//				ReadMapInt(file, recupChara, &_gd->mapParameter.animTiled.id[currentID]);
//
//				fscanf(file, "%s", recupChara);
//				fscanf(file, "%s", recupChara);
//				fscanf(file, "%s", recupChara);
//
//				//ici je calcule combien j'ai d'image dans mon animation
//
//				while (!strcmp(recupChara, "<frame"))
//				{
//					//id
//					fscanf(file, "%s", recupChara);
//					nbIdImage++;
//					//temp
//					fscanf(file, "%s", recupChara);
//					fscanf(file, "%s", recupChara);
//
//				}
//				_gd->mapParameter.animTiled.spriteAnim[currentID].id = calloc(nbIdImage, sizeof(int));
//				_gd->mapParameter.animTiled.spriteAnim[currentID].ttl = calloc(nbIdImage, sizeof(int));
//				_gd->mapParameter.animTiled.spriteAnim[currentID].idMother = _gd->mapParameter.animTiled.id[currentID];
//				_gd->mapParameter.animTiled.spriteAnim[currentID].nbImageInAnim = nbIdImage;
//				currentID++;
//
//			}
//		}
//		fseek(file, 0, SEEK_SET);
//		currentID = 0;
//		//je lis une troisieme  pour les id des images
//		while (!feof(file))
//		{
//			fscanf(file, "%s", recupChara);
//			//printf("%s\n", recupChara);
//			if (strstr(recupChara, "id=\"") &&
//				!strstr(recupChara, "tileid=\""))
//			{
//				int nbIdImage = 0;
//
//				fscanf(file, "%s", recupChara);
//				fscanf(file, "%s", recupChara);
//				fscanf(file, "%s", recupChara);
//
//				//ici je calcule combien j'ai d'image dans mon animation
//				while (nbIdImage != _gd->mapParameter.animTiled.spriteAnim[currentID].nbImageInAnim)
//				{
//					//id
//					ReadMapInt(file, recupChara, &_gd->mapParameter.animTiled.spriteAnim[currentID].id[nbIdImage]);
//					fscanf(file, "%s", recupChara);
//					fscanf(file, "%s", recupChara);
//
//					fscanf(file, "%s", recupChara);
//					fscanf(file, "%s", recupChara);
//
//					nbIdImage++;
//				}
//				currentID++;
//			}
//		}
//
//		fseek(file, 0, SEEK_SET);
//		currentID = 0;
//		while (!feof(file))
//		{
//			fscanf(file, "%s", recupChara);
//			//printf("%s\n", recupChara);
//			if (strstr(recupChara, "id=\"") &&
//				!strstr(recupChara, "tileid=\""))
//			{
//				int nbIdImage = 0;
//				fscanf(file, "%s", recupChara);
//				fscanf(file, "%s", recupChara);
//				fscanf(file, "%s", recupChara);
//
//				//ici je calcule combien j'ai d'image dans mon animation
//				while (nbIdImage != _gd->mapParameter.animTiled.spriteAnim[currentID].nbImageInAnim)
//				{
//					//id
//					ReadMapInt(file, recupChara, &_gd->mapParameter.animTiled.spriteAnim[currentID].id[nbIdImage]);
//					//temp
//					fscanf(file, "%s", recupChara);
//					fscanf(file, "%s", recupChara);
//					//printf("%s\n", recupChara);
//					ReadMapFloat(file, recupChara, &_gd->mapParameter.animTiled.spriteAnim[currentID].ttl[nbIdImage]);
//					//printf("%f\n", _gd->animTiled.spriteAnim[currentID].ttl[nbIdImage]);
//					fscanf(file, "%s", recupChara);
//					fscanf(file, "%s", recupChara);
//
//					nbIdImage++;
//				}
//				currentID++;
//			}
//		}
//		fclose(file);
//	}
//	*/
//}