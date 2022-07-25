#include "traitement.hpp"

#include <algorithm>


std::string traitement_des_espaces(std::string const& chaine)
{
	std::string chaine_de_carac{ chaine };

	//cherche l'espace 
	auto premier_non_espace{ std::find_if_not(std::begin(chaine_de_carac), std::end(chaine_de_carac), isspace) };
	//supprime l'espace
	chaine_de_carac.erase(std::begin(chaine_de_carac), premier_non_espace);
	//inverse la chaine 
	std::reverse(std::begin(chaine_de_carac), std::end(chaine_de_carac));

	//cherche l'espace , le supprime et inverse la chaine 
	premier_non_espace = std::find_if_not(std::begin(chaine_de_carac), std::end(chaine_de_carac), isspace);
	chaine_de_carac.erase(std::begin(chaine_de_carac), premier_non_espace);
	std::reverse(std::begin(chaine_de_carac), std::end(chaine_de_carac));

	return chaine_de_carac;
}