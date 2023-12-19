//#include "definition.h"

//code pour afficher les segments d'un triangle pour les fleches du mastermind

//void affiche_droite(int pos_x1, int pos_y1, int pos_x2, int pos_y2, sfColor colorLine, sfRenderWindow* _Window)
//{
//	sfVertex vertices[2];
//
//	vertices[0].color = colorLine;
//	vertices[1].color = colorLine;
//
//	vertices[0].position.x = (float)pos_x1;
//	vertices[0].position.y = (float)pos_y1;
//
//	vertices[1].position.x = (float)pos_x2;
//	vertices[1].position.y = (float)pos_y2;
//
//	sfRenderWindow_drawPrimitives(_Window, vertices, 2, sfLines, NULL);// pointer to vertex array, number of vertices, primitive
//}
//
//void DisplayTriangles(struct Collision _triangles[], sfRenderWindow* _window)
//{
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			_triangles[i].color = sfGreen;
//			affiche_droite((int)_triangles[i].vertex[j].x, (int)_triangles[i].vertex[j].y, (int)_triangles[i].vertex[(j + 1) % 3].x, (int)_triangles[i].vertex[(j + 1) % 3].y, _triangles[i].color, _window);
//		}
//	}
//}