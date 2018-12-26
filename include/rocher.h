#ifndef ROCHER_H
#define ROCHER_H
#include "obstacle.h"

class Rocher : public Obstacle
{
    public:
    //Constructeurs
    Rocher();
    Rocher(int x, int y, int diametre, int hauteur);
    Rocher(Rocher const& tocopy);
    //Destructeurs
    ~Rocher();
};
#endif