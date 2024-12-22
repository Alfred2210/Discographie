#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <memory>
#include <map>
#include <fstream>


#include "artiste.h"

class GestionnaireDeDonnees
{
public:
	void ajouter(std::vector<std::string>& vec, std::shared_ptr<Album>& album, std::shared_ptr<Artiste>& artiste, std::shared_ptr<Morceau>& morceau);
	
	void texte_a_traite();
	void run();
	void enregistrer_fichier();
	std::vector<std::string> lire_fichier(std::string const& file_name);
	void display_album(const std::map<std::string, std::shared_ptr<Artiste>>& artiste);
	 void display_artiste(const std::map<std::string, std::shared_ptr<Artiste>>& artiste);
private:
	std::map<std::string, std::shared_ptr<Artiste>> m_artiste;

};

