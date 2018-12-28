#include "collision.h"



collision::collision()
{
}

bool collision::CercleCercle(Obstacle obstacle, Personnage perso)//pour la collision entre l'obsacle et le personnage qui sont representé comme deux cercle avec leur diametre
{
	int distanceX = obstacle.getX - perso.getX;
	int distanceY = obstacle.getY - perso.getY;
	int distance = sqrt((distanceX*distanceX) + (distanceY*distanceY)); // pour calculer la distance entre le centre des deux cercle

	if (distance <= obstacle.getD/2 + perso.getD/2) {
		return true;
	}
	return false;
}

bool collision::CercleSegment()
{

}


