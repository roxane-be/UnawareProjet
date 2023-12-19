#include "InitCutScene.h"

void InitCutScene(GameData* _gd)
{
	_gd->cinematique.currentAnim = 0;
	_gd->cinematique.currentTime = 0;
	_gd->cinematique.pos.x = _gd->sizeWindow.width / 2;
	_gd->cinematique.pos.y = _gd->sizeWindow.height / 2;
	_gd->cinematique.pos.z = 1.0;
	_gd->cinematique.opacity = 0;

	switch (_gd->cutSceneState)
	{
	case vaisseauIntro:
		if (_gd->cinematique.currentAnim == 0
			&& _gd->cinematique.currentTime == 0)
		{
			_gd->cinematique.blackScreen = LoadSprite("../Ressources/cinematique/vaisseau_intro/blackScreen.png", 1);

			if (_gd->choixPerso == 0)
			{
				//cinematique vaisseau intro
				_gd->cinematique.shipIntro[0] = LoadSprite("../Ressources/cinematique/vaisseau_intro/0_g.png", 1);
				_gd->cinematique.shipIntro[1] = LoadSprite("../Ressources/cinematique/vaisseau_intro/1_g.png", 1);
				_gd->cinematique.shipIntro[2] = LoadSprite("../Ressources/cinematique/vaisseau_intro/2_g.png", 1);

			}
			else if (_gd->choixPerso == 1)
			{
				//cinematique vaisseau intro
				_gd->cinematique.shipIntro[0] = LoadSprite("../Ressources/cinematique/vaisseau_intro/0_f.png", 1);
				_gd->cinematique.shipIntro[1] = LoadSprite("../Ressources/cinematique/vaisseau_intro/1_f.png", 1);
				_gd->cinematique.shipIntro[2] = LoadSprite("../Ressources/cinematique/vaisseau_intro/2_f.png", 1);
			}
		}
		break;

	case vaisseauOpenDoor: //ouverture de la porte du vaisseai
		_gd->cinematique.shipDoor[0] = LoadSprite("../Ressources/cinematique/vaisseau_porte/0.png", 1);
		_gd->cinematique.shipDoor[1] = LoadSprite("../Ressources/cinematique/vaisseau_porte/1.png", 1);
		_gd->cinematique.shipDoor[2] = LoadSprite("../Ressources/cinematique/vaisseau_porte/2.png", 1);
		break;

	case vaisseauSleep: //quand l'on va se coucher dans le vaisseau
		if (_gd->choixPerso == 0)
		{
			_gd->cinematique.shipSleep[0] = LoadSprite("../Ressources/cinematique/vaisseau_fin/0.png", 1);
			_gd->cinematique.shipSleep[1] = LoadSprite("../Ressources/cinematique/vaisseau_fin/1_g.png", 1);
			_gd->cinematique.shipSleep[2] = LoadSprite("../Ressources/cinematique/vaisseau_fin/2_g.png", 1);
			_gd->cinematique.shipSleep[3] = LoadSprite("../Ressources/cinematique/vaisseau_fin/3.png", 1);

		}
		else if (_gd->choixPerso == 1)
		{
			_gd->cinematique.shipSleep[0] = LoadSprite("../Ressources/cinematique/vaisseau_fin/0.png", 1);
			_gd->cinematique.shipSleep[1] = LoadSprite("../Ressources/cinematique/vaisseau_fin/1_f.png", 1);
			_gd->cinematique.shipSleep[2] = LoadSprite("../Ressources/cinematique/vaisseau_fin/2_f.png", 1);
			_gd->cinematique.shipSleep[3] = LoadSprite("../Ressources/cinematique/vaisseau_fin/3.png", 1);
		}
		break;

	case islandIntro: // réveil dans le lit de l'island
		if (_gd->choixPerso == 0)
		{
			_gd->cinematique.IslandIntro[0] = LoadSprite("../Ressources/cinematique/island_intro/0_g.png", 1);
			_gd->cinematique.IslandIntro[1] = LoadSprite("../Ressources/cinematique/island_intro/1_g.png", 1);
		}
		else if (_gd->choixPerso == 1)
		{
			_gd->cinematique.IslandIntro[0] = LoadSprite("../Ressources/cinematique/island_intro/0_f.png", 1);
			_gd->cinematique.IslandIntro[1] = LoadSprite("../Ressources/cinematique/island_intro/1_f.png", 1);
		}
		_gd->cinematique.exitHouse = sfFalse;
		break;

	case islandLeaveHouse: //sortie de la maison de l'island pour la premiere fois au reveil
		_gd->cinematique.IslandLeaveHouse[0] = LoadSprite("../Ressources/cinematique/island_maison/0.png", 1);
		_gd->cinematique.IslandLeaveHouse[1] = LoadSprite("../Ressources/cinematique/island_maison/1.png", 1);
		break;

	case islandPont: //après la réparation du puzzle pont
		if (_gd->choixPerso == 0)
		{
			_gd->cinematique.IslandPont[0] = LoadSprite("../Ressources/cinematique/island_pont/1_g.png", 1);
			_gd->cinematique.IslandPont[1] = LoadSprite("../Ressources/cinematique/island_pont/0.png", 1);
			_gd->cinematique.IslandPont[2] = LoadSprite("../Ressources/cinematique/island_pont/2.png", 1);
		}
		else if (_gd->choixPerso == 1)
		{
			_gd->cinematique.IslandPont[0] = LoadSprite("../Ressources/cinematique/island_pont/1_f.png", 1);
			_gd->cinematique.IslandPont[1] = LoadSprite("../Ressources/cinematique/island_pont/0.png", 1);
			_gd->cinematique.IslandPont[2] = LoadSprite("../Ressources/cinematique/island_pont/2.png", 1);
		}
		break;

	case islandDialogue: //lorsque l'on resout la mot de passe de la porte de l'island
		if (_gd->choixPerso == 0)
		{
			_gd->cinematique.IslandDialogue[0] = LoadSprite("../Ressources/cinematique/island_dialogue/0.png", 1);
			_gd->cinematique.IslandDialogue[1] = LoadSprite("../Ressources/cinematique/island_dialogue/1_g.png", 1);
			_gd->cinematique.IslandDialogue[2] = LoadSprite("../Ressources/cinematique/island_dialogue/2_g.png", 1);
		}
		else if (_gd->choixPerso == 1)
		{
			_gd->cinematique.IslandDialogue[0] = LoadSprite("../Ressources/cinematique/island_dialogue/0.png", 1);
			_gd->cinematique.IslandDialogue[1] = LoadSprite("../Ressources/cinematique/island_dialogue/1_f.png", 1);
			_gd->cinematique.IslandDialogue[2] = LoadSprite("../Ressources/cinematique/island_dialogue/2_f.png", 1);
		}
		break;

	case islandEnd: //quand on ramasse la carte dans la box de l'island
		_gd->cinematique.IslandEnd[0] = LoadSprite("../Ressources/cinematique/island_fin/0.png", 1);
		_gd->cinematique.IslandEnd[1] = LoadSprite("../Ressources/cinematique/vaisseau_intro/WhiteScreen.png", 1);
		break;

	case bedRoomIntro: //réveil dans la chambre, reparation de l'ia
		if (_gd->choixPerso == 0)
		{
			_gd->cinematique.BedRoomIntro[0] = LoadSprite("../Ressources/cinematique/chambre_intro/0_g.png", 1);
			_gd->cinematique.BedRoomIntro[1] = LoadSprite("../Ressources/cinematique/chambre_intro/1_g.png", 1);
			_gd->cinematique.BedRoomIntro[2] = LoadSprite("../Ressources/cinematique/chambre_intro/2_g.png", 1);
			_gd->cinematique.BedRoomIntro[3] = LoadSprite("../Ressources/cinematique/chambre_intro/3_g.png", 1);
		}
		else if (_gd->choixPerso == 1)
		{
			_gd->cinematique.BedRoomIntro[0] = LoadSprite("../Ressources/cinematique/chambre_intro/0_f.png", 1);
			_gd->cinematique.BedRoomIntro[1] = LoadSprite("../Ressources/cinematique/chambre_intro/1_f.png", 1);
			_gd->cinematique.BedRoomIntro[2] = LoadSprite("../Ressources/cinematique/chambre_intro/2_f.png", 1);
			_gd->cinematique.BedRoomIntro[3] = LoadSprite("../Ressources/cinematique/chambre_intro/3_f.png", 1);
		}
		break;
	case bedRoomExit: //réveil dans la chambre, reparation de l'ia
		if (_gd->choixPerso == 0)
		{
			_gd->cinematique.BedRoomExit[0] = LoadSprite("../Ressources/cinematique/chambre_exit/0_g.png", 1);
		}
		else if (_gd->choixPerso == 1)
		{
			_gd->cinematique.BedRoomExit[0] = LoadSprite("../Ressources/cinematique/chambre_exit/0_f.png", 1);
		}
		_gd->cinematique.BedRoomExit[1] = LoadSprite("../Ressources/cinematique/chambre_exit/1.png", 1);

		break;
	case JungleReveil: //réveil dans la chambre, reparation de l'ia
		_gd->cinematique.JungleReveil[0] = LoadSprite("../Ressources/cinematique/jungle_reveil/0.png", 1);
		break;
	case JungleEnd:
		_gd->cinematique.JungleEnd[0] = LoadSprite("../Ressources/cinematique/jungle_end/0.png", 1);
		_gd->cinematique.JungleEnd[1] = LoadSprite("../Ressources/cinematique/jungle_end/1.png", 1);
		_gd->cinematique.JungleEnd[2] = LoadSprite("../Ressources/cinematique/jungle_end/2.png", 1);
		_gd->cinematique.JungleEnd[3] = LoadSprite("../Ressources/cinematique/jungle_end/3.png", 1);
		_gd->cinematique.JungleEnd[4] = LoadSprite("../Ressources/cinematique/jungle_end/4.png", 1);
		_gd->cinematique.JungleEnd[5] = LoadSprite("../Ressources/cinematique/jungle_end/5.png", 1);
		_gd->cinematique.JungleEnd[6] = LoadSprite("../Ressources/cinematique/jungle_end/6.png", 1);
		_gd->cinematique.JungleEnd[7] = LoadSprite("../Ressources/cinematique/jungle_end/7.png", 1);
		_gd->cinematique.JungleEnd[8] = LoadSprite("../Ressources/cinematique/jungle_end/8.png", 1);
		break;
	case EndReveil:
		if (_gd->choixPerso == 0)
		{
			_gd->cinematique.EndReveil[0] = LoadSprite("../Ressources/cinematique/vaisseau_intro/WhiteScreen.png", 1);
			_gd->cinematique.EndReveil[1] = LoadSprite("../Ressources/cinematique/end_reveil/0_g.png", 1);
			_gd->cinematique.EndReveil[2] = LoadSprite("../Ressources/cinematique/end_reveil/1_g.png", 1);
		}
		else if (_gd->choixPerso == 1)
		{
			_gd->cinematique.EndReveil[0] = LoadSprite("../Ressources/cinematique/vaisseau_intro/WhiteScreen.png", 1);
			_gd->cinematique.EndReveil[1] = LoadSprite("../Ressources/cinematique/end_reveil/0_f.png", 1);
			_gd->cinematique.EndReveil[2] = LoadSprite("../Ressources/cinematique/end_reveil/1_f.png", 1);
		}
		break;
	case EndCasque:
		if (_gd->choixPerso == 0)
		{
		_gd->cinematique.EndCasque[0] = LoadSprite("../Ressources/cinematique/end_casque/0_g.png", 1);
		_gd->cinematique.EndCasque[1] = LoadSprite("../Ressources/cinematique/end_casque/1_g.png", 1);
		_gd->cinematique.EndCasque[2] = LoadSprite("../Ressources/cinematique/end_casque/2_g.png", 1);
		}
		else if (_gd->choixPerso == 1)
		{
			_gd->cinematique.EndCasque[0] = LoadSprite("../Ressources/cinematique/end_casque/0_f.png", 1);
			_gd->cinematique.EndCasque[1] = LoadSprite("../Ressources/cinematique/end_casque/1_f.png", 1);
			_gd->cinematique.EndCasque[2] = LoadSprite("../Ressources/cinematique/end_casque/2_f.png", 1);
		}
		break;
	case EndEnd:
		if (_gd->choixPerso == 0)
		{
		_gd->cinematique.EndEnd[0] = LoadSprite("../Ressources/cinematique/end_end/0.png", 1);
		_gd->cinematique.EndEnd[1] = LoadSprite("../Ressources/cinematique/end_end/1_g.png", 1);
		_gd->cinematique.EndEnd[2] = LoadSprite("../Ressources/cinematique/end_end/2.png", 1);
		_gd->cinematique.EndEnd[3] = LoadSprite("../Ressources/cinematique/end_end/3.png", 1);
		}
		else if (_gd->choixPerso == 1)
		{
			_gd->cinematique.EndEnd[0] = LoadSprite("../Ressources/cinematique/end_end/0.png", 1);
			_gd->cinematique.EndEnd[1] = LoadSprite("../Ressources/cinematique/end_end/1_f.png", 1);
			_gd->cinematique.EndEnd[2] = LoadSprite("../Ressources/cinematique/end_end/2.png", 1);
			_gd->cinematique.EndEnd[3] = LoadSprite("../Ressources/cinematique/end_end/3.png", 1);
		}
		_gd->cinematique.EndEnd[4] = LoadSprite("../Ressources/cinematique/end_end/CreditJeu.png", 0);
		_gd->fondCredit = LoadSprite("../Ressources/cinematique/end_end/fondCredit.png", 0);
		_gd->terre = LoadSprite("../Ressources/cinematique/end_end/terre.png", 0);
		break;
	case fail:
		if (_gd->choixPerso == 0)
		{
			_gd->cinematique.Fail[0] = LoadSprite("../Ressources/cinematique/vaisseau_intro/WhiteScreen.png", 1);
			_gd->cinematique.Fail[1] = LoadSprite("../Ressources/cinematique/chambre_intro/0_g.png", 1);
		}
		else if (_gd->choixPerso == 1)
		{
			_gd->cinematique.Fail[0] = LoadSprite("../Ressources/cinematique/vaisseau_intro/WhiteScreen.png", 1);
			_gd->cinematique.Fail[1] = LoadSprite("../Ressources/cinematique/chambre_intro/0_f.png", 1);
		}
		break;
	default:
		break;
	}
}

void DeleteCutScene(GameData* _gd)
{
	switch (_gd->cutSceneState)
	{
	case vaisseauIntro:
		if (_gd->cinematique.currentAnim > 0)
		{
			DeleteSprite(_gd->cinematique.shipIntro[_gd->cinematique.currentAnim - 1]);
		}
		break;
	case vaisseauOpenDoor:
		if (_gd->cinematique.currentAnim > 0)
		{
			DeleteSprite(_gd->cinematique.shipDoor[_gd->cinematique.currentAnim - 1]);
		}
		break;
	case vaisseauSleep:
		if (_gd->cinematique.currentAnim > 0)
		{
			DeleteSprite(_gd->cinematique.shipSleep[_gd->cinematique.currentAnim - 1]);
		}
		break;
	case islandIntro:
		if (_gd->cinematique.currentAnim > 0)
		{
			DeleteSprite(_gd->cinematique.IslandIntro[_gd->cinematique.currentAnim - 1]);
		}
		break;
	case islandPont:
		if (_gd->cinematique.currentAnim > 0)
		{
			DeleteSprite(_gd->cinematique.IslandPont[_gd->cinematique.currentAnim - 1]);
		}
		break;
	case islandDialogue:
		if (_gd->cinematique.currentAnim > 0)
		{
			DeleteSprite(_gd->cinematique.IslandDialogue[_gd->cinematique.currentAnim - 1]);
		}
		break;
	case islandEnd:
		if (_gd->cinematique.currentAnim > 0)
		{
			DeleteSprite(_gd->cinematique.IslandEnd[_gd->cinematique.currentAnim - 1]);
		}
		break;
	case bedRoomIntro:
		if (_gd->cinematique.currentAnim > 0)
		{
			DeleteSprite(_gd->cinematique.BedRoomIntro[_gd->cinematique.currentAnim - 1]);
		}
		break;
	case JungleEnd:
		if (_gd->cinematique.currentAnim > 0)
		{
			DeleteSprite(_gd->cinematique.JungleEnd[_gd->cinematique.currentAnim - 1]);
		}
		break;
	case EndReveil:
		if (_gd->cinematique.currentAnim > 0)
		{
			DeleteSprite(_gd->cinematique.EndReveil[_gd->cinematique.currentAnim - 1]);
		}
		break;
	case EndCasque:
		if (_gd->cinematique.currentAnim > 0)
		{
			DeleteSprite(_gd->cinematique.EndCasque[_gd->cinematique.currentAnim - 1]);
		}
		break;
	case EndEnd:
		if (_gd->cinematique.currentAnim > 0)
		{
			DeleteSprite(_gd->cinematique.EndEnd[_gd->cinematique.currentAnim - 1]);
		}
		break;
	case fail:
		if (_gd->cinematique.currentAnim > 0)
		{
			DeleteSprite(_gd->cinematique.Fail[_gd->cinematique.currentAnim - 1]);
		}
		break;
	default:
		break;
	}
}