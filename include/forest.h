#ifndef FOREST_H
#define FOREST_H
#include <list>
#include "obstacle.h"
#include "batisse.h"

class Forest
{
    private:
    // Largeur et longueur de la fenêtre
    int f_X_size ;
    int f_Y_size ;
    // Coordonnées du centre
    int f_x ;
    int f_y ;
    // Listes des objets du jeu
    list<Obstacle*> f_obstacles ;
    list<Batisse> f_batisses ;

    public:
    // Constructeur par défault
    Forest();
    // Constructeur avec params
    Forest(int X_size,int Y_size);
    // Forest(int X_size, int Y_size, list<obstacles*> obstacles);

    //Constructeur de copie
    Forest(Forest const& tocopy);
    ~Forest();

    //Getters
    list<Obstacle*> getObstacles();
    list<Batisse> getBatisses();

};
#endif
