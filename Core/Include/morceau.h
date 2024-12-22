#pragma once
#include <string>
#include <memory>
#include <iostream>

class Morceau
{

public :
	void set_title(const std::string & title);
	std::string get_title();
private :

	std::string m_title;
};


