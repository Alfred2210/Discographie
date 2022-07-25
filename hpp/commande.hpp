#pragma once

#include "../hpp/discographie.hpp"

#include <tuple>


enum class Commande
{
	Ajouter,
	Afficher,
	Enregistrer,
	Charger,
	Quitter

};

std::string recuperer_commande();

std::tuple<Commande, std::string> interpretation_commande(std::string& commande_texte);

bool execution(Discographie& disco, Commande commande, std::string& instruction);