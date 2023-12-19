#include "InputSelecteurPerso.h"

void InputSelecteurPerso(GameData* _gd)
{
	if (_gd->clickCadreText == sfTrue)
	{
		if (_gd->event.type == sfEvtKeyPressed)
		{
			int sizeChar = strlen(_gd->persoName);
			//only the alphabet in upper case
			if (_gd->event.key.code >= sfKeyA
				&& _gd->event.key.code <= sfKeyZ
				&& sizeChar < 20)
			{
				//sfSound_play(_gd->enigme.dialogue.writeSound.sound);

				char temp[2] = { _gd->event.key.code + 65 };
				strcat(_gd->persoName, temp);
				//printf("%s\n", _gd->persoName);
			}
			//remove the last character
			if (_gd->event.key.code == sfKeyBackspace && sizeChar > 0)
			{
				//sfSound_play(_gd->enigme.dialogue.writeSound.sound);
				sizeChar--;
				_gd->persoName[sizeChar] = '\0';
			}
		}
	}
}