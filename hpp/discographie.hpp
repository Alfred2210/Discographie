#pragma once
#include <vector>
#include <string>

struct Album
{
	std::string nom;
};

struct Artiste
{
	std::string nom;

};

struct Morceau
{

	std::string nom;
	Album album;
	Artiste artiste;
};
using Discographie = std::vector<Morceau>;