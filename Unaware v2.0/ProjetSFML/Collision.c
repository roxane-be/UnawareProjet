#include "definition.h"

//toute les collisions du jeu
double CrossProduct(sfVector2f u, sfVector2f v)
{
	return u.x * v.x + u.y * v.y;
}

int CollisionAABB(sfVector2f posAABB1, sfVector2f posAABB2, sfVector2f cornerAABB2)
{
	if (posAABB1.x >= posAABB2.x - cornerAABB2.x
		&& posAABB1.x <= posAABB2.x + cornerAABB2.x
		&& posAABB1.y >= posAABB2.y - cornerAABB2.y
		&& posAABB1.y <= posAABB2.y + cornerAABB2.y)
	{
		return 1;
	}
	return 0;
}
//dialogue
int IsColliding(sfVector2f posAABB1, sfVector2f cornerAABB1, sfVector2f posAABB2, sfVector2f cornerAABB2)
{
	if (posAABB1.x + cornerAABB1.x >= posAABB2.x - cornerAABB2.x
		&& posAABB1.x - cornerAABB1.x <= posAABB2.x + cornerAABB2.x
		&& posAABB1.y + cornerAABB1.y >= posAABB2.y - cornerAABB2.y
		&& posAABB1.y - cornerAABB1.y <= posAABB2.y + cornerAABB2.y)
	{
		return 1;
	}
	return 0;
}

int CollisionTriangleMouse(sfVector2f _clickPt, struct Collision _triang[])
{
	//vecteur n et autre
	sfVector2f u, v;
	//résultat crossProduct
	double CP[3];

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//vector v

			v.x = _clickPt.x - _triang[i].vertex[j].x;
			v.y = _clickPt.y - _triang[i].vertex[j].y;

			//vecteur n
			if (j == 2)
			{
				u.x = -(_triang[i].vertex[0].y - _triang[i].vertex[j].y);
				u.y = _triang[i].vertex[0].x - _triang[i].vertex[j].x;
			}
			else
			{
				u.x = -(_triang[i].vertex[j + 1].y - _triang[i].vertex[j].y);
				u.y = _triang[i].vertex[j + 1].x - _triang[i].vertex[j].x;
			}

			CP[j] = CrossProduct(u, v);
		}

		if ((CP[0] > 0 && CP[1] > 0 && CP[2] > 0)
			|| (CP[0] < 0 && CP[1] < 0 && CP[2] < 0))
		{

			return 1;
		}
	}
	return 0;
}

//enigme puzzle
int isCollidingWithMouse(sfRectangleShape* _rect, sfVector2f _mouse, int _center)
{
	sfVector2f rectPos = sfRectangleShape_getPosition(_rect);
	sfVector2f rectSize = sfRectangleShape_getSize(_rect);
	sfVector2f origin = sfRectangleShape_getOrigin(_rect);

	if (_center == 1)
	{
		if (_mouse.x > rectPos.x - origin.x
			&& _mouse.x < rectPos.x + rectSize.x - origin.x
			&& _mouse.y > rectPos.y - origin.y
			&& _mouse.y < rectPos.y + rectSize.y - origin.y)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if (_mouse.x > rectPos.x && _mouse.x < rectPos.x + rectSize.x
			&& _mouse.y > rectPos.y && _mouse.y < rectPos.y + rectSize.y)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int IsCollidingRectangleRectangle(sfRectangleShape* _rectA, sfRectangleShape* _rectB)
{
	sfVector2f rectPosA = sfRectangleShape_getPosition(_rectA);
	sfVector2f rectSizeA = sfRectangleShape_getSize(_rectA);

	sfVector2f rectPosB = sfRectangleShape_getPosition(_rectB);
	sfVector2f rectSizeB = sfRectangleShape_getSize(_rectB);

	if (rectPosA.x < rectPosB.x + rectSizeB.x && rectPosA.x + rectSizeA.x > rectPosB.x
		&& rectPosA.y < rectPosB.y + rectSizeB.y && rectPosA.y + rectSizeA.y > rectPosB.y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}