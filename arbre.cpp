#include "arbre.h"
#include <iostream>

using namespace std;

Arbre::Arbre() {
    o_x = 0 ;
     o_y = 0 ;
     o_diametre = 0 ;
     o_hauteur = 0 ;
}

Arbre::Arbre(int x , int y, int diametre, int hauteur) : Obstacle(x, y, diametre, hauteur)
{
    
}

Arbre::Arbre(Arbre const& tocopy) {
    o_x = tocopy.o_x ;
    o_y = tocopy.o_y ;
    o_diametre = tocopy.o_diametre ;
    o_hauteur = tocopy.o_hauteur ;
    o_force = tocopy.o_force ;
}

Arbre::~Arbre() {

}

std::string Arbre::getName()
{
	return "arbre";
}