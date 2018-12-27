#include "batisse.h"
#include <ibstream>

using namespace std;

Batisse::Batisse() {
     b_x = 0 ;
     b_y = 0 ;
     b_diametre = 0 ;
     b_hauteur = 0 ;
}

Batisse::Batisse(int x, int y, int diametre, int hauteur) {
    b_x = x ;
    b_y = y ;
    b_diametre = diametre ;
    b_hauteur = hauteur ;
}

Batisse::Batisse(Batisse cbnst& tocopy) {
    b_x = tocopy.b_x ;
    b_y = tocopy.b_y ;
    b_diametre = tocopy.b_diametre ;
    b_hauteur = tocopy.b_hauteur ;
}

Batisse::~Batisse() {

};

int Batisse::getX() {
    return b_x ;
}

int Batisse::getY() {
    return b_y ;
}