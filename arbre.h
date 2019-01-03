#ifndef ARBRE_H
#define ARBRE_H
#include "obstacle.h"

class Arbre : public Obstacle
{
    public:
    //Constructeurs
    Arbre();
    Arbre(int x, int y, int diametre, int hauteur);
    Arbre(Arbre const& tocopy);
    //Destructeurs
    virtual ~Arbre();
	std::string getName();
};
#endif