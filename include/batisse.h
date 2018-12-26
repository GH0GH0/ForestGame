#ifndef BATISSE_H
#define BATISSE_H

class Batisse {

    protected:
    //Position
    int o_x ;
    int o_y ;
    // Caractéristiques
    int o_diametre ;
    int o_hauteur ;
    
    public:

    Batisse();
    Batisse(int x, int y, int diametre, int hauteur);
    Batisse(Batisse const& tocopy);
    ~Batisse();
};
#endif