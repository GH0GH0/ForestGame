#ifndef BATISSE_H
#define BATISSE_H
#include "obstacle.h"

class Batisse {

    protected:
    //Position
    int b_x ;
    int b_y ;
    // Caractéristiques
    int b_diametre ;
    int b_hauteur ;
    
    public:
    //Constructeurs
    Batisse();
    Batisse(int x, int y, int diametre, int hauteur);
    Batisse(Batisse const& tocopy);
    ~Batisse();
     //Getters
    virtual int getX();
    virtual int getY();
};
#endif