#include "../hpp/commande.hpp"


int main()
{
	Artiste  Jhene_Aiko{ "Jhene Aiko" };
	Artiste  The_Weekend{ "The Weekend" };

	Album  Souled_Out{ "Souled Out" };
	Album  Sail_Out{ "Sail Out" };
	Album  Dawn_FM{ "Dawn FM" };


	Morceau  Ways{ "Ways", Souled_Out.nom,Jhene_Aiko.nom };
	Morceau  Bed_Peace{ "Bed Peace", Sail_Out.nom,Jhene_Aiko.nom };
	Morceau  Sacrifice{ "Sacrifice", Dawn_FM.nom,The_Weekend.nom };

	Discographie discographie{ Ways,Bed_Peace,Sacrifice };

	bool continuer{ true };
	do
	{
		std::string entree = recuperer_commande();
		auto [commande, instruction] = interpretation_commande(entree);
		execution(discographie, commande, instruction);
	} while (continuer);

}