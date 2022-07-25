#include "../hpp/operator.hpp"

#include <sstream>


std::ostream& operator<<(std::ostream& output, Album const& album)
{
	return output << album.nom;
}
std::ostream& operator<<(std::ostream& output, Artiste const& artiste)
{
	return output << artiste.nom;
}
std::ostream& operator<<(std::ostream& output, Morceau const& morceau)
{
	return output << morceau.nom << " | " << morceau.album << " | " << morceau.artiste;

}
std::istream& operator>>(std::istream& input, Morceau& morceau)
{
	std::string texte{};
	std::ostringstream output{};

	//Nom morceau
	while (input >> texte && texte != "|")
	{
		output << texte << " ";
	}

	std::string nom_morceau = output.str();
	if (std::empty(nom_morceau))
	{
		nom_morceau = "Morceau inconnu";
	}

	morceau.nom = nom_morceau;
	output.str(std::string{});

	//Nom album
	while (input >> texte && texte != "|")
	{
		output << texte << " ";
	}

	std::string nom_album = output.str();

	if (std::empty(nom_album))
	{
		nom_album = "Album inconnu";
	}
	morceau.album.nom = nom_album;
	output.str(std::string{});

	//Nom Artiste
	while (input >> texte)
	{
		output << texte << " ";
	}

	std::string nom_artiste = output.str();

	if (std::empty(nom_artiste))
	{
		nom_artiste = "Artiste inconnu";
	}
	morceau.artiste.nom = nom_artiste;

	return input >> morceau.nom >> morceau.album.nom >> morceau.artiste.nom;

}