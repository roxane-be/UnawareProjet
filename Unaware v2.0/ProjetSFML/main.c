#include "definition.h"
#include "Init.h"
#include "Display.h"
#include "Update.h"
#include "Input.h"

void main()
{
	GameData gameData = { 0 };

	InitAllGame(&gameData);

	while (sfRenderWindow_isOpen(gameData.window))
	{

		gameData.frameRate.dt = sfTime_asSeconds(sfClock_restart(gameData.frameRate.frameClock));

		InputAllGame(&gameData);
		UpdateAllGame(&gameData);
		DisplayAllGame(&gameData);

		//dt pour gerer les FPS de tout le jeu

		gameData.frameRate.dt = (1.f / 60.f - gameData.frameRate.dt) * 1000.f;
		if (gameData.frameRate.dt > 0)
		{
			Sleep(gameData.frameRate.dt);
		}
	}
	free(gameData.persoDef.Timeline);
}
