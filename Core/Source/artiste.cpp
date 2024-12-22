#include "artiste.h"


std::string Artiste::get_nom()
{
	return m_nom;
}

void Artiste::set_nom(const std::string& nom)
{
	m_nom = nom;

}

void Artiste::add_album(std::shared_ptr<Album> album)
{
	auto it = m_album.find(album->get_nom());

	if (it == m_album.end())
	{
		m_album[album->get_nom()] = album;
	}
}

std::map<std::string, std::shared_ptr<Album>>& Artiste::get_albums()
{
	return m_album;
}


