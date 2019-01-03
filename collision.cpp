#include "collision.h"
#include <iostream>

using namespace std;



collision::collision()
{
}

bool collision::CercleCercle(Obstacle obstacle, Personnage perso)//collision entre l'obsacle et le personnage qui sont represent� comme deux cercle avec leur diametre
{
	int distanceX = abs(obstacle.getX - perso.getX);
	int distanceY = abs(obstacle.getY - perso.getY);
	int distance = sqrt((distanceX*distanceX) + (distanceY*distanceY)); // pour calculer la distance entre le centre des deux cercle joueur obstacle

	if (distance <= obstacle.getD/2 + perso.getD/2) 
	{
		return true;
	}
	return false;
}

bool collision::PlayerPlayer(Personnage perso1, Personnage perso2)//collisoin entre le 1er joueur et le 2eme 
{
	int distanceX = abs(perso1.getX - perso2.getX);
	int distanceY = abs(perso1.getY - perso2.getY);
	int distance = sqrt((distanceX * distanceX) + (distanceY * distanceY));// pour calculer la distance entre le centre des deux cercle joueurs
	
	if (distance <= perso1.getD / 2 + perso2.getD / 2)
	{
		return true;
	}
	return false;
}

bool collision::CercleSegment()
{

}


