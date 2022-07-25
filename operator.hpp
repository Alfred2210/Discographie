#pragma once

#include "discographie.hpp"



std::ostream& operator<<(std::ostream& output, Album const& album);
std::ostream& operator<<(std::ostream& output, Artiste const& artiste);

std::ostream& operator<<(std::ostream& output, Morceau const& morceau);
std::istream& operator>>(std::istream& input, Morceau& morceau);