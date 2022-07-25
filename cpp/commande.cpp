#include "../hpp/commande.hpp"
#include "../hpp/affichage.hpp"
#include "../hpp/tri.hpp"
#include "../hpp/operator.hpp"
#include "../hpp/traitement.hpp"


#include <iostream>
#include <sstream>



std::string recuperer_commande()
{
	std::cout << "> ";

	std::string commande{};
	std::getline(std::cin, commande);
	return commande;
}

std::tuple<Commande, std::string> interpretation_commande(std::string& commande_texte)
{

	std::istringstream flux{ commande_texte };
	std::string premier_mot{};

	flux >> premier_mot;
	premier_mot = traitement_des_espaces(premier_mot);
	std::string instructions{};
	std::getline(flux, instructions);

	instructions = traitement_des_espaces(instructions);
	if (premier_mot == "afficher")
	{
		return { Commande::Afficher,instructions };
	}

	else if (premier_mot == "ajouter")
	{
		return { Commande::Ajouter ,instructions };
	}

	else if (premier_mot == "quitter")
	{
		return { Commande::Quitter ,std::string{} };
	}
	else
	{
		throw std::runtime_error("Commande invalide.");
	}
}

bool execution(Discographie& disco, Commande commande, std::string& instruction)
{
	if (commande == Commande::Afficher)
	{
		if (instruction == "morceau")
		{
			tri_morceau(disco);
			afficher_morceau(disco);

		}
		else if (instruction == "album")
		{
			tri_album(disco);
			afficher_album(disco);

		}
		else if (instruction == "artiste")
		{
			tri_artiste(disco);
			afficher_artiste(disco);

		}
		else
		{
			throw std::runtime_error("erreur  d'affichage inconnue.");
		}
	}

	else if (commande == Commande::Ajouter)
	{
		std::istringstream flux{ instruction };
		Morceau morceau;

		flux >> morceau;

		disco.push_back(morceau);

	}

	else if (commande == Commande::Quitter)
	{
		return false;
	}

	return true;


}