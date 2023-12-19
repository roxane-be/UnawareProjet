#include "definition.h"

//Fonctions génériques 

void DrawPixel(sfImage* _sNom, int x, int y, sfColor _sColor)
{
	sfVector2u tempoVector = sfImage_getSize(_sNom);

	if (x >= 0 && x < tempoVector.x && y >= 0 && y < tempoVector.y)
	{
		sfImage_setPixel(_sNom, x, y, _sColor);
	}
}

//Sprites
sfSprite* LoadSprite(char* _sNom, int _isCentered)
{
	sfSprite* tempoSprite;
	sfTexture* tempoText = sfTexture_createFromFile(_sNom, NULL);
	tempoSprite = sfSprite_create();
	sfSprite_setTexture(tempoSprite, tempoText, sfTrue);

	sfTexture_setSmooth(tempoText, sfTrue);

	if (_isCentered == 1)
	{
		sfVector2u tempoVector = sfTexture_getSize(tempoText);
		sfVector2f tempoVectorFloat = { (float)tempoVector.x / 2.0, (float)tempoVector.y / 2.0 };
		sfSprite_setOrigin(tempoSprite, tempoVectorFloat);
	}
	return tempoSprite;
}

void BlitSprite(sfSprite* _sprite, float _x, float _y,
	float _angle, float _scaleX, float _scaleY, GameData* _gd)
{
	sfVector2f tempPos = { _x, _y };
	sfSprite_setPosition(_sprite, tempPos);

	sfSprite_setRotation(_sprite, _angle);

	sfVector2f tempScale = { _scaleX * SCALE_X(_gd->sizeWindow.width), _scaleY * SCALE_Y(_gd->sizeWindow.height) };
	//sfVector2f tempScale = { _scaleX , _scaleY };
	sfSprite_setScale(_sprite, tempScale);

	sfRenderWindow_drawSprite(_gd->window, _sprite, NULL);
}

void DeleteSprite(sfSprite* _sprite)
{
	sfTexture_destroy(sfSprite_getTexture(_sprite));
	sfSprite_destroy(_sprite);
}

void BlitSpriteColor(sfSprite* _sprite, int _alpha)
{
	//modif l'opacité
	if (_alpha == 0)
	{
		sfColor tempColor = { 255,255,255,170 };
		sfSprite_setColor(_sprite, tempColor);
	}
	//modif la couleur 
	else if (_alpha == 1)
	{
		sfColor tempColor = { 100,100,100,255 };
		sfSprite_setColor(_sprite, tempColor);
	}
	//remettre sa couleur comme à l'origine 
	else if (_alpha == 2)
	{
		sfColor tempColor = { 255,255,255,255 };
		sfSprite_setColor(_sprite, tempColor);
	}

}

sfVector2u GetSizeFromSprite(sfSprite* _sprite)
{
	return sfTexture_getSize(sfSprite_getTexture(_sprite));
}

//Textes 
sfText* LoadText(const char* _font,const char* _text, int _isCentered)
{
	sfFont* tempPolice = sfFont_createFromFile(_font);
	sfText* TempText = sfText_create();
	sfText_setFont(TempText, tempPolice);
	sfText_setString(TempText, _text);
	sfText_setCharacterSize(TempText, TEXT_SIZE);
	if (_isCentered)
	{
		sfFloatRect tempSize = sfText_getLocalBounds(TempText);
		sfVector2f tempOffset = { tempSize.width / 2, tempSize.height / 2 };
		sfText_setOrigin(TempText, tempOffset);
	}
	return TempText;
}

void BlitText(sfText* _text, float _x, float _y, sfColor _color, sfVector2f _scale,
	sfRenderWindow* _window)
{
	sfVector2f tempPos = { _x, _y };
	sfText_setPosition(_text, tempPos);
	sfText_setColor(_text, _color);
	sfText_setScale(_text, _scale);
	sfRenderWindow_drawText(_window, _text, NULL);
}

//Sons
void SoundPlay(char* _filename)
{
	sfSoundBuffer* buffer = 0;
	sfSound* sound = 0;

	buffer = sfSoundBuffer_createFromFile(_filename);
	sound = sfSound_create();
	sfSound_setBuffer(sound, buffer);
	sfSound_play(sound);
}

//Fonction camera
sfVector2f ScreenToWorld(float _x, float _y)
{
	sfVector2f tempResultat =
	{
		floorf(_x / SIZECELL) ,
		floorf(_y / SIZECELL) };

	return tempResultat;
}

sfVector2f WorldToScreen(float _x, float _y)
{
	sfVector2f tempResultat =
	{
		(_x)*SIZECELL,
		(_y)*SIZECELL };

	return tempResultat;
}

int RandomInt(int _min, int _max)
{
	return rand() % (_max - _min + 1) + _min;
}

//Gestion de grille
float getX(int column)
{
	return(column * 32);
}

float getY(int line)
{
	return (line * 32);
}

int getColumn(float x)
{
	return (int)floorf(x / 32.0f);
}

int getLine(float y)
{
	return (int)floorf(y / 32.0f);
}

int IsCellAvailable(int line, int column, int tailleL, int tailleC)
{
	return (line >= 0) && (line < tailleL) && (column >= 0) && (column < tailleC);
}

int IsPointIsInCamera(float line, float column, sfVector2f min, sfVector2f max)
{
	return (line >= min.x) && (line < max.x) && (column >= min.y) && (column < max.y);
}


void RotationSpriteSheet(sfVector2f* _scale, sfVector2f* _pos, float* _angle, int transform)
{
	if (transform == 4)
	{
		_scale->x = -1;
		_pos->x = 64;
	}
	else if (transform == 3)
	{
		_pos->x = 64;
		*_angle = 90;
	}
	else if (transform == 2)
	{
		_pos->x = 64;
		_pos->y = 64;
		*_angle = 180;
	}
	else if (transform == 1)
	{
		_scale->x = -1;
		_pos->x = 64;
		_pos->y = 64;
		*_angle = 90;
	}
	else if (transform == 5)
	{
		_scale->x = -1;
		*_angle = -90;
	}
	else if (transform == 6)
	{
		_scale->y = -1;
		_pos->y = 64;
	}
	else if (transform == 7)
	{
		_pos->y = 64;
		*_angle = -90;
	}
}


int UpperUnderPlayer(char _name[999], int _posPlayer, int _posUpper)
{
	if (!strstr(_name, "upper"))
	{
		return 1;
	}
	else if (strstr(_name, "Base") != NULL
		&& _posPlayer - BASE_UPPER > _posUpper)
	{
		return 1;
	}
	else if (strstr(_name, "Top") != NULL
		&& _posPlayer - UPPER_TOP > _posUpper)
	{
		return 1;
	}
	else if (strstr(_name, "Beam") != NULL)
	{
		if (_posPlayer - 64 > _posUpper + 64)
		{
			return 1;
		}
	}
	else if (_posPlayer - UPPER > _posUpper)
	{
		return 1;
	}

	return 0;
}


int UpperOnPlayer(char _name[999], int _posPlayer, int _posUpper)
{
	if (strstr(_name, "Base") != NULL
		&& _posPlayer - BASE_UPPER <= _posUpper)
	{
		return 1;
	}
	if (strstr(_name, "Beam") != NULL)
	{
		if (_posPlayer - 64 <= _posUpper + 64)
		{
			return 1;
		}

	}
	if (strstr(_name, "Top") != NULL
		&& _posPlayer - UPPER_TOP <= _posUpper)
	{
		return 1;
	}
	else if (_posPlayer - UPPER <= _posUpper
		&& strstr(_name, "upper") != NULL
		&& !strstr(_name, "Base")
		&& !strstr(_name, "Beam"))
	{
		return 1;
	}
	return 0;
}