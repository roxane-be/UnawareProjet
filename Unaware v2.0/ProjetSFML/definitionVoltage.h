#ifndef DEFINITIONVOLTAGE_H
#define DEFINITIONVOLTAGE_H

#define NB_LEVIER 8
#define SOLUTION_VOLTMETRE 232

typedef enum Etat Etat;
enum Etat
{
	neutre_positif,
	neutre_negatif,
	positif,
	negatif,
};

struct ButtonVoltageBox
{
	sfVector2f pos;
	sfVector2f size;
	sfRectangleShape* forme;
	sfSprite* buttonSprite[3];
};
typedef struct ButtonVoltageBox ButtonVoltageBox;

typedef struct Voltage Voltage;
struct Voltage
{
	int levier[NB_LEVIER];
	sfRectangleShape* rectLevier[NB_LEVIER];
	sfRectangleShape* valider;
	sfRectangleShape* reset;
	Etat etat[NB_LEVIER];
	sfVector2f pos[NB_LEVIER];
	sfSprite* levierNeutre;
	sfSprite* levierPositif;
	sfSprite* levierNegatif;
	int voltmetre;
	sfText* volt;
	sfBool resolvedDream_1;
	sfSprite* plus;
	sfSprite* moins;

	//bouton aide
	ButtonVoltageBox helpButtonVoltageBox;
	sfBool onSpriteHelpButtonVoltageBox;
	sfBool clickHelpButtonVoltageBox;

	ButtonVoltageBox resetButtonVoltageBox;
	ButtonVoltageBox validateButtonVoltageBox;
	sfBool onSpriteValidateVoltageBox;
	sfBool clickValidateVoltageBox;

	sfSprite* backgroundVoltage;
	sfSprite* backgroundTutoVoltage;

	sfSprite* diodeVoltageBoxEnigmeNonFini;
	sfSprite* diodeVoltageBoxEnigmeFini;

	ButtonVoltageBox voltageCard; //bouton pour cliquer sur la carte
	sfBool leavingCard; //booleen pour savoir si la carte est sortie ou non

	//timer pour "l'animation" de la sortie de carte
	char stageCard;
	float timerVoltageCard;

	//Audio interaction
	Sound switchSound;
	Sound deniedSound;
};

#endif // !DEFINITIONVOLTAGE_H
