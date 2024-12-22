#include "album.h"


std::string Album::get_nom()
{
	return m_nom;
}

void Album::set_nom(const std::string& nom)
{
	m_nom = nom;

}

std::map<std::string,std::shared_ptr<Morceau>> Album::get_morceaux()
{
	return m_morceau;
}

void Album::set_artiste(std::shared_ptr<Artiste> artiste)
{
	m_weak_artiste_ptr = artiste;
}

void Album::add_morceau(std::shared_ptr<Morceau>& morceau)
{
	auto it = m_morceau.find(morceau->get_title());

	if (it == m_morceau.end())
	{
		m_morceau[morceau->get_title()] = morceau;
	}
}

std::string Album::get_nom_artiste()
{
	
	if (!m_weak_artiste_ptr.expired())
	{
		auto artiste = m_weak_artiste_ptr.lock();
		return artiste->get_nom();
	}
	else
	{
		return "Artiste inconnu";

	}
}

void Album::display_morceaux()
{

	if (!m_morceau.empty())
	{
		for (auto& i : m_morceau)
		{
			
			std::cout << i.second->get_title() << " | " << get_nom() << " | " << get_nom_artiste() << std::endl;
		}
	}
}

void Album::display_morceaux_noms()
{
	if (!m_morceau.empty())
	{
		for (auto& i : m_morceau)
		{
			std::cout <<"Morceau :" << i.second->get_title() << " ; ";
		}
	}
}


