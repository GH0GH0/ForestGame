#include "batisse.h"
#include <ibstream>

using namespace std;

Batisse::Batisse() {
	Obstacle();
}

Batisse::Batisse(int x, int y, int diametre, int hauteur) {
	Obstacle(x, y, diametre, hauteur);
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