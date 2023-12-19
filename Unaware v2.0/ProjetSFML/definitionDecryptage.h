#ifndef DEFINITIONDECRYPTAGE_H
#define DEFINITIONDECRYPTAGE_H

#define SOLUTION_DECRYPTAGE "UNAWARE"

struct ButtonDecryptageBox
{
	sfVector2f pos;
	sfVector2f size;
	sfRectangleShape* forme;
	sfSprite* buttonSprite[3];
};
typedef struct ButtonDecryptageBox ButtonDecryptageBox;

struct Decryptage
{
	sfSprite* backgroundDecryptage;
	sfSprite* backgroundTutoDecryptage;
	sfSprite* backgroundPapier[9]; // les papiers a recup
	sfBool isVisible[9]; //pour savoir si les papiers sont visible ou pas

	ButtonDecryptageBox validateDecryptage;
	sfBool onSpriteValidateDecryptage;
	sfBool clickValidateDecryptage;

	ButtonDecryptageBox resetDecryptage;
	sfBool onSpriteResetDecryptage;
	sfBool clickResetDecryptage;

	ButtonDecryptageBox quitDecryptage;
	sfBool onSpriteQuitDecryptage;
	sfBool clickQuitDecryptage;

	ButtonDecryptageBox retourDecryptage;
	sfBool onSpriteRetourDecryptage;
	sfBool clickRetourDecryptage;

	ButtonDecryptageBox aideDecryptage;
	sfBool onSpriteAideDecryptage;
	sfBool clickAideDecryptage;

	char word[255];
	sfText* text;
	sfVector2f pos;
	sfBool resolved;

	sfBool PuzzleRec;
	sfBool againOpen;
	sfBool paperRecup[4];
	int nbPaperRecup;
	sfSprite* paperHUD;
	sfSprite* paper;
	sfSprite* plus1;
	sfVector2f posPaperHUD;
	sfBool InRecup;
	float upPlus;
	sfBool TwoPaper;

	//Audio interaction
	Sound bookSound;
	Sound writeSound;
	Sound ripPaperSound;
};
typedef struct Decryptage Decryptage;
#endif // !DEFINITIONDECRYPTAGE_H
