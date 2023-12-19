#ifndef DEFINITIONCABLE_H
#define DEFINITIONCABLE_H

#define NB_CABLE 4 

struct ButtonCableBox
{
	sfVector2f pos;
	sfVector2f size;
	sfRectangleShape* forme;
	sfSprite* buttonSprite[3];
};
typedef struct ButtonCableBox ButtonCableBox;

struct Cable
{
	//Start and end connectors
	sfSprite* spriteConnector;
	sfRectangleShape* rectangleStart;
	sfRectangleShape* rectangleEnd;
	sfVector2f posStart;
	sfVector2f posEnd;
	float width;
	float height;

	//The cable
	sfSprite* spriteCable;
	sfVector2f posCable;
	sfVector2f direction;
	sfBool click;
	sfBool isPlaced;
	float length;
	int id;
};
typedef struct Cable Cable;

struct UtilityCable
{
	sfSprite* backgroundCable;
	int idCable;
	sfBool resolvedDream_1;

	//bouton aide pour le cable de la boite
	ButtonCableBox helpButtonCableBox;
	sfBool onSpriteHelpButtonCableBox;
	sfBool clickHelpButtonCableBox;
	//tuto cable boite
	sfSprite* backgroundTutoCableBox;

	sfBool switchOn_Off; //si false : off / si true : on

	ButtonCableBox validateOnButtonCableBox;
	sfBool onSpriteValidateOnCableBox;
	sfBool clickValidateOnCableBox;

	ButtonCableBox validateOffButtonCableBox;
	sfBool onSpriteValidateOffCableBox;
	sfBool clickValidateOffCableBox;

	sfBool cableRaccorder;
	sfSprite* diodeCableBoxEnigmeNonFini;
	sfSprite* diodeCableBoxEnigmeFini;

	//Audio interaction
	Sound wiresSound;
	Sound powerOnSound;
	Sound switchOnOff;
};
typedef struct UtilityCable UtilityCable;

#endif