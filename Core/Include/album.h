#pragma once
#include <string>
#include <memory>
#include <vector>


#include "morceau.h"
#include "artiste.h"


class Artiste;
class Album
{

public :

	std::string get_nom();
	void set_nom(const std::string &nom);
	std::map<std::string,std::shared_ptr<Morceau>> get_morceaux();
	void set_artiste(std::shared_ptr<Artiste> artiste);
	void add_morceau(std::shared_ptr<Morceau>& morceau);
	void display_morceaux();
	void display_morceaux_noms();

	std::string get_nom_artiste();
private :

	std::string m_nom;
	std::weak_ptr<Artiste> m_weak_artiste_ptr;//à revoir !!!!
	std::map<std::string,std::shared_ptr<Morceau>> m_morceau;

	
};

