#ifndef COLLISION_H
#define COOLISION_H
#include "obstacle.h"
#include"batisse.h"
#include "personnage.h"
 class collision
{
   public:
	  collision();
	
	  static bool CercleCercle(Obstacle obstacle, Personnage perso);
	  static bool CercleSegment();
};

#endif // !COLLISION_H