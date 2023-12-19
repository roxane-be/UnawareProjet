#ifndef DEFINITIONDIALOGUE_H
#define DEFINITIONDIALOGUE_H

#define SENTENCE_PNJ_HELP_0_1 "Meuhjour étranger !\nPouvez-vous m'euuhder a\ncomprendre ce village ?\nJ'ai beau essayer de parler\navec les autres meuh..."
#define SENTENCE_PNJ_HELP_0_2 "leurs réponses ne sont pas\ncohérentes pour meuuh.\nCertains sont meuhme cachés,\nn'ayez pas peur d'explorer les\nenvirons pour tous les trouver."

#define SENTENCE_PNJ_HELP_1 "Ces quatre-là meuu rendent\nvraiment fou avec leurs drôles\nde phrases !\nAvez vous compris quelque chose ?\nJ'eumerais bien une peumme .."

#define SENTENCE_PNJ_HELP_2 "Je meuh demande s'il n'y a pas\nun meuhssage caché derriere\ntout ça.\nAvez vous vu cette grande maison ?\nSi seulement j'étais plus meuhtite\npour y rentrer."

#define SENTENCE_PNJ_0_1 "Bonjour !\nVous est-il déjà arrivé de jouer\nla bonne lors d'une partie ?\nJe crois que cela aide à\natteindre la victoire !"

#define SENTENCE_PNJ_1_1 "Hoya voyageur !\nOn m'a toujours dis de foncer\nquand elle était blanche, mais\nje n'ai jamais compris\npourquoi.. Quelle belle journée."
#define SENTENCE_PNJ_2_1 "Pshiitt.. \nCelle que vous possédez\nest-elle vitale ou postale ?\nC'est un secret ?\nRacontez moi tout, hihi, je veux\nsavoir."

#define SENTENCE_PNJ_3_1 "C'est étrange, en avez-vous utilisé\n une pour trouver ce village ?\nJe n'ai jamais vu votre tête par ici..\nQue dites-vous ? .."
#define SENTENCE_PNJ_3_2 "Qu'une vache arc-en-ciel vous\n a indiqué votre route ?!\nQuelle histoire étrange .."

#define SOLUTION_ENIGME_DIALOGUE_0 "CARTE"
#define SOLUTION_ENIGME_DIALOGUE_1 "CARTES"
#define NB_PNJ 5
#define NB_PNJ_ENIGME 4
#define NB_PNJ_HELP 1
#define NB_SENTENCES 5


struct ButtonDialogue
{
	sfVector2f pos;
	sfVector2f size;
	sfRectangleShape* forme;
	sfSprite* buttonSprite[3];
};
typedef struct ButtonDialogue ButtonDialogue;


struct Dialogue
{
	//booleen pour savoir si on a parlé au pnj,
	//utile pour le dialogue du pnj Help
	sfBool isTalk[NB_PNJ];
	char* sentence[NB_SENTENCES];
	//utile pour si le joueur entre le mdp 
	char answerPlayer[999];
	//peut changer

	//savoir dans quel state on se situe
	int state;
	//savoir à qui le joueur parle ou en collision avec lequel
	int whoTalk;

	//savoir si l'enigme a été resolu ou non 
	sfBool resolvedDream_1;

	sfSprite* backgroundDialogue;

	//bouton quitter
	ButtonDialogue quitDialogue;
	sfBool onSpriteQuitDialogue;
	sfBool clickQuitDialogue;

	//bouton entrée
	ButtonDialogue validatePassword;
	sfBool onSpriteValidateDialogue;
	sfBool clickValidateDialogue;

	//bouton d'aide pour le mot de passe 
	ButtonDialogue helpDialogue;
	sfBool onSpriteHelpDialogue;
	sfBool clickHelpDialogue;

	//Gestion tuto
	sfSprite* backgroundTutoDialogue;
	//bouton retour pour le tuto du dialogue
	ButtonDialogue retourDialogue;
	sfBool clickRetourDialogue;
	sfBool onSpriteRetourDialogue;

	//Audio interaction
	Sound letterSound;
	Sound writeSound;
};
typedef struct Dialogue Dialogue;

enum DialogueState
{
	//pnj enigme
	PNJ_0,
	PNJ_1,
	PNJ_2,
	PNJ_3,

	//pnj help
	PNJ_HELP,
	//enter code enigme
	DOOR,

	INDIALOGUE,
	NONE,
};
typedef enum DialogueState DialogueState;

#endif // !DEFINITIONDIALOGUE_H
