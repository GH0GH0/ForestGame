#ifndef COLLISION_H
#define COOLISION_H
#include "obstacle.h"
#include "batisse.h"
#include "personnage.h"
 class collision
{
   public:
	  collision();
	
	  static bool CercleCercle(Obstacle obstacle, Personnage perso); //collision entre le joueur et l'obstacle 
	  static bool PlayerPlayer(Personnage perso1, Personnage perso2);// collision entres les deux joueurs
	  static bool CercleSegment();
};

#endif // !COLLISION_H