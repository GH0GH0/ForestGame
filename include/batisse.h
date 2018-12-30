#ifndef BATISSE_H
#define BATISSE_H
#include "obstacle.h"
class Batisse : public Obstacle
{
 
    public:
    //Constructeurs
    Batisse();
    Batisse(int x, int y, int diametre, int hauteur);
    Batisse(Batisse const& tocopy);
    //Destructeurs
	~Batisse();

};
#endif