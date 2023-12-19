#include "definition.h"

sfVector2f CreateSFVector(float x, float y) //permet de créer un vecteur
{
	sfVector2f newVector = { x,y };
	return newVector;
}

float GetVectorLength(sfVector2f vector) // permet de récuperer la longueur d'un vecteur
{
	return sqrtf(vector.x * vector.x + vector.y * vector.y);
}

float DotProduct(sfVector2f v1, sfVector2f v2) // Produit scalaire 
{
	return v1.x * v2.x + v1.y * v2.y;
}

sfVector2f NormalizeVector(sfVector2f vector) // Normalisation du vecteur
{
	float vectorLength = GetVectorLength(vector);

	if (vectorLength == 0.0f)
	{
		return CreateSFVector(0, 0);
	}

	float newX = vector.x / vectorLength;
	float newY = vector.y / vectorLength;

	return CreateSFVector(newX, newY); // return le vecteur normalisé 
}

sfVector2f RotateVector(sfVector2f vector, float angle) // Rotation du vecteur en fonction d'un angle
{
	float COS = (float)cos(angle);
	float SIN = (float)sin(angle);

	float newX = vector.x * COS - vector.y * SIN;
	float newY = vector.x * SIN + vector.y * COS;

	return CreateSFVector(newX, newY); // return le vecteur avec rotation
}

float DegreesToRadians(float angle) // Conversion degré vers radian
{
	return angle * PI / 180;
}

float RadiansToDegrees(float angle) // Conversion radian vers degré
{
	return (float)angle * 180 / PI;
}

//creer rectangle
void createRectangle(sfRectangleShape* _rect, sfVector2f _pos, float _width, float _height, int _origin)
{
	sfVector2f origin = { _width / 2, _height / 2 };
	sfVector2f size = { _width, _height };

	sfRectangleShape_setFillColor(_rect, sfTransparent);
	sfRectangleShape_setOutlineColor(_rect, sfWhite);
	sfRectangleShape_setOutlineThickness(_rect, 1.0f);
	sfRectangleShape_setSize(_rect, size);
	if (_origin == 1)
	{
		sfRectangleShape_setOrigin(_rect, origin);
	}
	sfRectangleShape_setPosition(_rect, _pos);
}