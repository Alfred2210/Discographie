#pragma once
#include <string>
#include <vector>
#include <memory>
#include <map>

#include "album.h"



class Album;

class Artiste
{

public : 
	
	void set_nom(const std::string& nom);
	std::string get_nom();
	void add_album(std::shared_ptr<Album> album);
	
	std::map<std::string, std::shared_ptr<Album>>& get_albums();
private :

	std::string m_nom;
	std::map<std::string,std::shared_ptr<Album>> m_album;


};

