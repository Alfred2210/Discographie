#include "../hpp/tri.hpp"

#include <algorithm>

//Good

void tri_morceau(Discographie& disco)
{
	std::sort(disco.begin(), disco.end(), [](Morceau a, Morceau b) {return a.nom < b.nom; });
}

//Good
void tri_album(Discographie& disco)
{
	std::sort(disco.begin(), disco.end(), [](Morceau a, Morceau b) {
		if (a.album.nom < b.album.nom)
			return true;
		return a.album.nom < b.album.nom&& a.nom < b.nom; });
}

//A voir si c'est bien(tri_artiste)

void tri_artiste(Discographie& disco)
{
	std::sort(disco.begin(), disco.end(), [](Morceau a, Morceau b) {

		if (a.artiste.nom < b.artiste.nom)
			return true;
		return a.artiste.nom == b.artiste.nom && a.album.nom < b.album.nom&& a.nom < b.nom; });
}