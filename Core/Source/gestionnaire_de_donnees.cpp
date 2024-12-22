#include "gestionnaire_de_donnees.h"



void GestionnaireDeDonnees::texte_a_traite()
{
	
	std::string texte_to_compare, command;
	bool quit = false;

	do
	{
		std::cout << "Entre une commande ( ajouter / afficher / enregistrer / quitter ) :  " << std::endl;
		std::cin >> texte_to_compare;
		std::cin.ignore();

		if (texte_to_compare == "quitter")
		{
			quit = true;
		}
		else if (texte_to_compare == "ajouter")
		{
			std::getline(std::cin, command);
			std::stringstream iss(command);
			std::vector<std::string> vec;
			std::string dataInto;
			vec.clear();

			while (std::getline(iss, dataInto, '|'))
			{
				dataInto.erase(remove_if(dataInto.begin(), dataInto.end(), isspace), dataInto.end());
				if (!dataInto.empty())
				{
					vec.push_back(dataInto);
				}
			}

			if (!vec.empty())
			{
				auto shared_album_ptr = std::make_shared<Album>();
				auto shared_artiste_ptr = std::make_shared<Artiste>();
				auto shared_morceau_ptr = std::make_shared<Morceau>();

				ajouter(vec, shared_album_ptr, shared_artiste_ptr, shared_morceau_ptr);

				auto it_find_artiste_name = m_artiste.find(shared_artiste_ptr->get_nom());

				if (it_find_artiste_name == m_artiste.end())
				{
					shared_album_ptr->add_morceau(shared_morceau_ptr);
					shared_artiste_ptr->add_album(shared_album_ptr);
					m_artiste[shared_artiste_ptr->get_nom()] = shared_artiste_ptr;
				}
				else
				{
					auto album_existe = it_find_artiste_name->second->get_albums().find(shared_album_ptr->get_nom());

					if (album_existe == it_find_artiste_name->second->get_albums().end())
					{
						
						shared_album_ptr->add_morceau(shared_morceau_ptr);
						it_find_artiste_name->second->add_album(shared_album_ptr);
					}
					else
					{
						album_existe->second->add_morceau(shared_morceau_ptr);
					}
				}


			}

		}
		else if (texte_to_compare == "afficher")
		{
			std::cin >> command;
			

			if (command == "morceau")
			{
				for (const auto& [album,artistes] : m_artiste)
				{
					for (auto& i : artistes->get_albums())
					{
						i.second->display_morceaux();
					}
					 
				}
	
			}
			else if (command == "album")
			{
				display_album(m_artiste);
				
				
			}
			else if (command == "artiste")
			{
				display_artiste(m_artiste);
				
			}
			
		}
		else if (texte_to_compare == "enregistrer")
		{
			enregistrer_fichier();
		}
		else if (texte_to_compare == "charger")
		{
			std::string file_name;
			std::cout << "Nom du fichier a charger : " << std::endl;
			std::cin>> file_name;
			std::cin.ignore();
			lire_fichier(file_name);
		}

		
		
	} while (!quit);
}





void GestionnaireDeDonnees::ajouter(std::vector<std::string>& vec, std::shared_ptr<Album>& album, std::shared_ptr<Artiste>& artiste, std::shared_ptr<Morceau>& morceau)
{
	std::string name_morceau = "Morceau inconnu", nameAlbum = "Album inconnu", nameArtiste = "Artiste inconnu";

	for (auto& i : vec)
	{
		if (i == "morceau")
		{
			std::cout << "Nom du morceau  : " << std::endl;
			std::getline(std::cin, name_morceau);
		}
		else if (i == "album")
		{
			std::cout << "Nom de l'Album : " << std::endl;
			std::getline(std::cin, nameAlbum);
		}
		else if (i == "artiste")
		{
			std::cout << "Nom de l'artiste : " << std::endl;
			std::getline(std::cin, nameArtiste);
		}
	}

	morceau->set_title(name_morceau);
	album->set_nom(nameAlbum);
	artiste->set_nom(nameArtiste);

	album->set_artiste(artiste);
}




void GestionnaireDeDonnees::display_album(const std::map<std::string, std::shared_ptr<Artiste>>& artiste)
{
	for (const auto& [nom, artistes] : artiste)
	{
		
		for (const auto& [nom_album, albums] : artistes->get_albums())
		{
			std::cout << albums->get_nom() << " | " << albums->get_nom_artiste() << std::endl;

			for (const auto& [nom_morceau, morceaux] : albums->get_morceaux())
			{
				std::cout << "\t/--> " << morceaux->get_title() << std::endl;
			}
		}
	}


}

void GestionnaireDeDonnees::display_artiste(const std::map<std::string, std::shared_ptr<Artiste>>& artiste)
{
	for (const auto& [nom, artistes] : artiste)
	{
		std::cout << artistes->get_nom() << " | ";

		for (const auto& [nom_album, albums] : artistes->get_albums())
		{
			std::cout << albums->get_nom() << std::endl;

			for (const auto& [nom_morceau, morceaux] : albums->get_morceaux())
			{
				std::cout << "\t/--> " << morceaux->get_title() << std::endl;
			}
		}
	}
}

void GestionnaireDeDonnees::run()
{
	texte_a_traite();
}


//pas termine voir
void GestionnaireDeDonnees::enregistrer_fichier()
{
	std::string nameFile;
	std::cout << "Nom du fichier : ";
	std::cin >> nameFile;
	std::cin.ignore();

	std::ofstream file{ nameFile};
	for (const auto& [album, albums] : m_artiste)
	{

		for (auto& i : albums->get_albums())
		{
			for (auto& [morceau,morceaux] : i.second->get_morceaux())
			{
				file << morceaux->get_title() << " | " << i.second->get_nom() << " | " << i.second->get_nom_artiste() << " | " << std::endl;
			}
		}
	}


}





// morceau : test | album : ty | artiste : jhene

std::vector<std::string> GestionnaireDeDonnees::lire_fichier(std::string const& file_name)
{
	
	
	std::vector<std::string> lignes{};
	std::string ligne{ "" };
	int count = 0;
	std::ifstream fichier{ file_name };
	if (!fichier)
	{
		// Si le fichier ne s'ouvre pas, alors on lance une exception pour le signaler.
		throw std::runtime_error("Fichier impossible à ouvrir.");
	}

	while (std::getline(fichier, ligne,'|'))
	{
		
		auto start = ligne.find_first_not_of(' ');
		auto end = ligne.find_last_not_of(' ');
		std::string trimmedString;
		trimmedString = ligne.substr(start, (end - start) + 1);

		lignes.push_back(trimmedString);
	
	}

	for (size_t i = 0; i < lignes.size(); i += 3)
	{
		if (i + 2 < lignes.size())

		{
			auto shared_morceau_ptr = std::make_shared<Morceau>();
			auto shared_ar_ptr = std::make_shared<Artiste>();
			auto shared_al_ptr = std::make_shared<Album>();
			
			shared_morceau_ptr->set_title(lignes[i]);
			shared_al_ptr->set_nom(lignes[i + 1]);
			shared_ar_ptr->set_nom(lignes[i + 2]);
			shared_al_ptr->set_artiste(shared_ar_ptr);

			shared_ar_ptr->add_album(shared_al_ptr);
			shared_al_ptr->add_morceau(shared_morceau_ptr);

			auto it_find_artiste_name = m_artiste.find(shared_ar_ptr->get_nom());

			if (it_find_artiste_name == m_artiste.end())
			{
				shared_al_ptr->add_morceau(shared_morceau_ptr);
				shared_ar_ptr->add_album(shared_al_ptr);
				m_artiste[shared_ar_ptr->get_nom()] = shared_ar_ptr;
			}
			else
			{
				auto album_existe = it_find_artiste_name->second->get_albums().find(shared_al_ptr->get_nom());

				if (album_existe == it_find_artiste_name->second->get_albums().end())
				{

					shared_al_ptr->add_morceau(shared_morceau_ptr);
					it_find_artiste_name->second->add_album(shared_al_ptr);
				}
				else
				{
					album_existe->second->add_morceau(shared_morceau_ptr);
				}
			}
		}
	}

	return lignes;
}





