#include "../hpp/affichage.hpp"

#include "../hpp/operator.hpp"
#include <iostream>


void afficher_morceau(Discographie& disco)
{

	for (auto& morceau : disco)
	{
		std::cout << " --> " << morceau << std::endl;
	}

}
void afficher_album(Discographie& disco)
{

	for (auto& morceau : disco)
	{
		std::cout << "--> " << morceau.album.nom << " | " << morceau.artiste << std::endl;
		std::cout << "\t--> " << morceau.nom << std::endl;
	}

}

void afficher_artiste(Discographie& disco)
{

	for (auto& morceau : disco)
	{
		std::cout << " --> " << morceau.artiste << std::endl;
		std::cout << "\t --> " << morceau.album.nom << std::endl;
		std::cout << " \t\t --> " << morceau.nom << std::endl;
	}

}