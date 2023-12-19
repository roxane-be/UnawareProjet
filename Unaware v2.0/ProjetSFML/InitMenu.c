#include "InitMenu.h"

//void InitButtonMenu(Buttons* _button, sfVector2f _pos, float _scaleX, float _scaleY, sfSprite* _sprite, char* _text, GameData* _gd)
//{
//	_button->pos = _pos;
//	_button->w = GetSizeFromSprite(_button->sprite).x * _scaleX;
//	_button->h = GetSizeFromSprite(_button->sprite).y * _scaleY;
//	_button->text = LoadText(_text, 1);
//}

void InitSpriteMenu(GameData* _gd)
{
	_gd->buttons[0].sprite[0] = LoadSprite("../Ressources/Assets/Menu/Nouvelle_Partie.png", 0);
	_gd->buttons[1].sprite[1] = LoadSprite("../Ressources/Assets/Menu/Options.png", 0);
	_gd->buttons[2].sprite[2] = LoadSprite("../Ressources/Assets/Menu/Credits.png", 0);
	_gd->buttons[3].sprite[3] = LoadSprite("../Ressources/Assets/Menu/Controles.png", 0);
	_gd->buttons[4].sprite[4] = LoadSprite("../Ressources/Assets/Menu/Quitter.png", 0);
	_gd->buttons[5].sprite[5] = LoadSprite("../Ressources/Assets/Menu/Volume.png", 0);
	_gd->buttons[6].sprite[6] = LoadSprite("../Ressources/Assets/Menu/MenuBack.png", 0);

	_gd->selectSprite[0] = LoadSprite("../Ressources/Assets/Menu/Selection_Rectangle_Big.png", 0);
	_gd->selectSprite[1] = LoadSprite("../Ressources/Assets/Menu/Selection_Rectangle_Small.png", 0);

	_gd->background = LoadSprite("../Ressources/Assets/Menu/Title_Background_Ship.png", 0);

	_gd->returnMenu = LoadSprite("../Ressources/Assets/Menu/retourson.png", 0);
}

void LoadButtonsMenu(GameData* _gd)
{
	/*for (int i = 0; i < 5; i++)
	{
		_gd->buttons[i].w = GetSizeFromSprite(_gd->buttons[i].sprite[i]).x;
		_gd->buttons[i].h = GetSizeFromSprite(_gd->buttons[i].sprite[i]).y;
		_gd->buttons[i].pos.x = SCREEN_WIDTH / 2 - _gd->buttons[i].w / 2;
		_gd->buttons[i].pos.y = 200 + _gd->buttons[i].h;

		_gd->buttons[i].forme = sfRectangleShape_create();
		createRectangle(_gd->buttons[i].forme, _gd->buttons[i].pos, (float)_gd->buttons[i].w, (float)_gd->buttons[i].h, 0);
	}*/

	_gd->buttons[0].w = GetSizeFromSprite(_gd->buttons[0].sprite[0]).x;
	_gd->buttons[0].h = GetSizeFromSprite(_gd->buttons[0].sprite[0]).y;
	_gd->buttons[0].pos.x = _gd->sizeWindow.width / 2 - _gd->buttons[0].w / 2;
	_gd->buttons[0].pos.y = 325;

	_gd->buttons[0].forme = sfRectangleShape_create();
	createRectangle(_gd->buttons[0].forme, _gd->buttons[0].pos, (float)_gd->buttons[0].w, (float)_gd->buttons[0].h, 0);

	_gd->buttons[1].w = GetSizeFromSprite(_gd->buttons[1].sprite[1]).x;
	_gd->buttons[1].h = GetSizeFromSprite(_gd->buttons[1].sprite[1]).y;
	_gd->buttons[1].pos.x = _gd->sizeWindow.width / 2 - _gd->buttons[1].w / 2;
	_gd->buttons[1].pos.y = 350 + _gd->buttons[0].h;

	_gd->buttons[1].forme = sfRectangleShape_create();
	createRectangle(_gd->buttons[1].forme, _gd->buttons[1].pos, (float)_gd->buttons[1].w, (float)_gd->buttons[1].h, 0);

	_gd->buttons[2].w = GetSizeFromSprite(_gd->buttons[2].sprite[2]).x;
	_gd->buttons[2].h = GetSizeFromSprite(_gd->buttons[2].sprite[2]).y;
	_gd->buttons[2].pos.x = _gd->sizeWindow.width / 2 - _gd->buttons[2].w / 2;
	_gd->buttons[2].pos.y = 375 + _gd->buttons[0].h + (float)_gd->buttons[1].h;

	_gd->buttons[2].forme = sfRectangleShape_create();
	createRectangle(_gd->buttons[2].forme, _gd->buttons[2].pos, (float)_gd->buttons[2].w, (float)_gd->buttons[2].h, 0);

	_gd->buttons[3].w = GetSizeFromSprite(_gd->buttons[3].sprite[3]).x;
	_gd->buttons[3].h = GetSizeFromSprite(_gd->buttons[3].sprite[3]).y;
	_gd->buttons[3].pos.x = _gd->sizeWindow.width / 2 - _gd->buttons[3].w / 2;
	_gd->buttons[3].pos.y = 400 + _gd->buttons[0].h + _gd->buttons[1].h + _gd->buttons[2].h;

	_gd->buttons[3].forme = sfRectangleShape_create();
	createRectangle(_gd->buttons[3].forme, _gd->buttons[3].pos, (float)_gd->buttons[3].w, (float)_gd->buttons[3].h, 0);

	_gd->buttons[4].w = GetSizeFromSprite(_gd->buttons[4].sprite[4]).x;
	_gd->buttons[4].h = GetSizeFromSprite(_gd->buttons[4].sprite[4]).y;
	_gd->buttons[4].pos.x = _gd->sizeWindow.width / 2 - _gd->buttons[4].w / 2;
	_gd->buttons[4].pos.y = 425 + _gd->buttons[0].h + _gd->buttons[1].h + _gd->buttons[2].h + _gd->buttons[3].h;

	_gd->buttons[4].forme = sfRectangleShape_create();
	createRectangle(_gd->buttons[4].forme, _gd->buttons[4].pos, (float)_gd->buttons[4].w, (float)_gd->buttons[4].h, 0);

	_gd->onSpriteBN = sfFalse;
	_gd->onSpriteBC = sfFalse;
	_gd->onSpriteBQ = sfFalse;
	_gd->onSpriteSO = sfFalse;
	_gd->onSpriteSA = sfFalse;
}

void InitSelecteurPerso(GameData* _gd)
{
	_gd->backgroundSelectPerso = LoadSprite("../Ressources/Assets/Menu/Selection/fond.png", 0);
	_gd->backgroundGarcon = LoadSprite("../Ressources/Assets/Menu/Selection/garçon.png", 0);
	_gd->backgroundFille = LoadSprite("../Ressources/Assets/Menu/Selection/fille.png", 0);

	//Garçon
	_gd->buttonsSelecteur[0].sprite[0] = LoadSprite("../Ressources/Assets/Menu/Selection/cadre_blanc_1.png", 0);
	_gd->buttonsSelecteur[0].sprite[1] = LoadSprite("../Ressources/Assets/Menu/Selection/cadre_vert_1.png", 0);
	_gd->buttonsSelecteur[0].sprite[2] = LoadSprite("../Ressources/Assets/Menu/Selection/font_blanc_opacite_1.png", 0);
	_gd->buttonsSelecteur[0].sprite[3] = LoadSprite("../Ressources/Assets/Menu/Selection/font_noir_opacite_2.png", 0);

	_gd->onSpriteButtonSelectG = sfFalse;
	_gd->clickButtonSelectG = sfFalse;

	_gd->buttonsSelecteur[0].pos.x = 200;
	_gd->buttonsSelecteur[0].pos.y = 40;

	_gd->buttonsSelecteur[0].w = 420;
	_gd->buttonsSelecteur[0].h = 770;

	_gd->buttonsSelecteur[0].forme = sfRectangleShape_create();
	createRectangle(_gd->buttonsSelecteur[0].forme, _gd->buttonsSelecteur[0].pos, _gd->buttonsSelecteur[0].w, _gd->buttonsSelecteur[0].h, 0);

	//Fille
	_gd->buttonsSelecteur[1].sprite[0] = LoadSprite("../Ressources/Assets/Menu/Selection/cadre_blanc_1.png", 0);
	_gd->buttonsSelecteur[1].sprite[1] = LoadSprite("../Ressources/Assets/Menu/Selection/cadre_vert_1.png", 0);
	_gd->buttonsSelecteur[1].sprite[2] = LoadSprite("../Ressources/Assets/Menu/Selection/font_blanc_opacite_1.png", 0);
	_gd->buttonsSelecteur[1].sprite[3] = LoadSprite("../Ressources/Assets/Menu/Selection/font_noir_opacite_2.png", 0);

	_gd->onSpriteButtonSelectF = sfFalse;
	_gd->clickButtonSelectF = sfFalse;

	_gd->buttonsSelecteur[1].pos.x = _gd->sizeWindow.width - 600;
	_gd->buttonsSelecteur[1].pos.y = 40;

	_gd->buttonsSelecteur[1].w = 420;
	_gd->buttonsSelecteur[1].h = 770;

	_gd->buttonsSelecteur[1].forme = sfRectangleShape_create();
	createRectangle(_gd->buttonsSelecteur[1].forme, _gd->buttonsSelecteur[1].pos, _gd->buttonsSelecteur[1].w, _gd->buttonsSelecteur[1].h, 0);

	_gd->choixPerso = -1;
	_gd->isSelect = sfFalse;

	_gd->buttonCadreText.sprite[0] = LoadSprite("../Ressources/Assets/Menu/Selection/cadre_texte_1.png", 0);
	_gd->buttonCadreText.sprite[1] = LoadSprite("../Ressources/Assets/Menu/Selection/cadre_texte_vert_1.png", 0);

	_gd->buttonCadreText.pos.x = 340;
	_gd->buttonCadreText.pos.y = 850;

	_gd->buttonCadreText.w = 1286;
	_gd->buttonCadreText.h = 187;

	_gd->buttonCadreText.forme = sfRectangleShape_create();
	createRectangle(_gd->buttonCadreText.forme, _gd->buttonCadreText.pos, _gd->buttonCadreText.w, _gd->buttonCadreText.h, 0);

	_gd->onSpriteCadreText = sfFalse;
	_gd->clickCadreText = sfFalse;

	_gd->texts.namePerso.text = LoadText("../Ressources/Text/nasalization.ttf","Entrez votre pseudo", 1);
	sfText_setCharacterSize(_gd->texts.namePerso.text, 60);
	_gd->texts.namePerso.pos.x = 600;
	_gd->texts.namePerso.pos.y = 920;

	//Ouais c'est super moche, mais je savais plus comment faire autrement
	_gd->tempNameG[0] = 'S';
	_gd->tempNameG[1] = 'p';
	_gd->tempNameG[2] = 'i';
	_gd->tempNameG[3] = 'k';
	_gd->tempNameG[4] = 'e';
	_gd->tempNameG[5] = '\0';

	_gd->tempNameF[0] = 'L';
	_gd->tempNameF[1] = 'u';
	_gd->tempNameF[2] = 'n';
	_gd->tempNameF[3] = 'a';
	_gd->tempNameF[4] = '\0';

}

void InitCredit(GameData* _gd)
{
	_gd->credit = LoadSprite("../Ressources/Assets/Menu/creditPage.png", 0);
	_gd->quitCredit = sfRectangleShape_create();
	//temp
	sfVector2f pos = { 66,77 };
	createRectangle(_gd->quitCredit, pos, 165, 142, 0);
	sfRectangleShape_setOutlineColor(_gd->quitCredit, sfRed);
}

void InitOptions(GameData* _gd)
{
	_gd->options = LoadSprite("../Ressources/Assets/Menu/optionPage.png", 0);
	_gd->volume = LoadSprite("../Ressources/Assets/Menu/VolumePage.png", 0);

	_gd->quitOptions = sfRectangleShape_create();
	//temp
	sfVector2f pos = { 66,77 };
	createRectangle(_gd->quitOptions, pos, 165, 142, 0);
	sfRectangleShape_setOutlineColor(_gd->quitOptions, sfRed);

	_gd->buttons[5].w = GetSizeFromSprite(_gd->buttons[5].sprite[5]).x;
	_gd->buttons[5].h = GetSizeFromSprite(_gd->buttons[5].sprite[5]).y;
	_gd->buttons[5].pos.x = _gd->sizeWindow.width / 2 - _gd->buttons[3].w / 2;
	_gd->buttons[5].pos.y = 350;

	_gd->buttons[5].forme = sfRectangleShape_create();
	createRectangle(_gd->buttons[5].forme, _gd->buttons[5].pos, (float)_gd->buttons[5].w, (float)_gd->buttons[5].h, 0);
	_gd->onSpriteBV = sfFalse;
}

void InitVolume(GameData* _gd)
{
	_gd->volume = LoadSprite("../Ressources/Assets/Menu/VolumePage.png", 0);
	_gd->barrVolume = LoadSprite("../Ressources/Assets/Menu/barrVolume.png", 0);
	_gd->soundTest = LoadSprite("../Ressources/Assets/Menu/iconeson1.png", 0);
	_gd->cursorVolume = LoadSprite("../Ressources/Assets/Menu/cursorVolume.png", 0);

	_gd->quitVolume = sfRectangleShape_create();
	//temp
	sfVector2f pos = { 66,77 };
	createRectangle(_gd->quitVolume, pos, 165, 142, 0);
	sfRectangleShape_setOutlineColor(_gd->quitVolume, sfRed);

	for (int i = 0; i < NB_CAT_SOUND; i++)
	{
		char stringDraw[999];
		_gd->posBarrVolume[i].x = 700;
		_gd->posBarrVolume[i].y = 310 + (i * 155);
		_gd->posCursorVolume[i].x = _gd->posBarrVolume[i].x;
		_gd->posCursorVolume[i].y = _gd->posBarrVolume[i].y;

		_gd->posCursorVolumeRect[i].x = _gd->posCursorVolume[i].x + 43;
		_gd->posCursorVolumeRect[i].y = _gd->posCursorVolume[i].y - 20;

		_gd->rectVolume[i] = sfRectangleShape_create();
		sfVector2f pos = { _gd->posCursorVolumeRect[i].x+30,_gd->posCursorVolumeRect[i].y };
		createRectangle(_gd->rectVolume[i], pos, 700, 80, 0);
		sfRectangleShape_setOutlineColor(_gd->rectVolume[i], sfRed);

		_gd->volumePourcentage[i] = LoadText("../Ressources/Text/nasalization.ttf", "", 1);
		sprintf(stringDraw, "%.f%%", (_gd->soundInterraction * 100));
		sfText_setString(_gd->volumePourcentage[i], stringDraw);

	}
	for (int i = 0; i < NB_CAT_SOUND - 1; i++)
	{
		sfVector2f temp = { _gd->posCursorVolumeRect[i].x + 860, _gd->posCursorVolumeRect[i].y + 2 + 155 };
		_gd->rectTestVolume[i] = sfRectangleShape_create();
		createRectangle(_gd->rectTestVolume[i], temp, 75, 75, 0);
		sfRectangleShape_setOutlineColor(_gd->rectTestVolume[i], sfBlue);
	}
}

void InitControle(GameData* _gd)
{
	_gd->controle = LoadSprite("../Ressources/Assets/Menu/controlePage.png", 0);

	_gd->quitControle = sfRectangleShape_create();
	sfVector2f pos = { 66,77 };
	createRectangle(_gd->quitControle, pos, 165, 142, 0);
}

void InitMenu(GameData* _gd)
{
	InitSpriteMenu(_gd);
	InitSoundMenu(_gd);
	LoadButtonsMenu(_gd);
	InitSelecteurPerso(_gd);
	InitCredit(_gd);
	InitOptions(_gd);
	InitControle(_gd);
	InitVolume(_gd);
}

void DeleteSpriteSelecteurPerso(GameData* _gd)
{
	//DeleteSprite(_gd->backgroundSelectPerso);
	DeleteSprite(_gd->backgroundFille);
	DeleteSprite(_gd->backgroundGarcon);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			DeleteSprite(_gd->buttonsSelecteur[i].sprite[j]);
		}
		DeleteSprite(_gd->buttonCadreText.sprite[i]);
		sfRectangleShape_destroy(_gd->buttonsSelecteur[i].forme);
	}

	sfFont_destroy(sfText_getFont(_gd->texts.namePerso.text));
	sfText_destroy(_gd->texts.namePerso.text);
	sfRectangleShape_destroy(_gd->buttonCadreText.forme);
}