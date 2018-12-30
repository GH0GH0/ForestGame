#include "personnage.h"
#include <cmath>
#define PI 3.14159265

Personnage::Personnage()
{
	p_x = 0;
	p_y = 0;
	p_d = 0;
	p_vie = 0;
}

Personnage::Personnage(int x, int y, int d, int vie)
{
	p_x = x;
	p_y = y;
	p_d = d;
	p_vie = vie;
}

Personnage::Personnage(Personnage const & tocopy)
{
}

Personnage::~Personnage()
{
}

int Personnage::getX() const
{
	return p_x;
}

int Personnage::getY() const
{
	return p_y;
}

int Personnage::getD() const
{
	return p_d;
}

void Personnage::setOrientation(int angle)
{
	if (angle > 0 && angle < 360)
		p_rotation = angle;
}

void Personnage::marcher(int distance) {

}

void Personnage::tirer(int nbDegats) {
	if (nbDegats > 5 || nbDegats < 0)
	{
		std::cerr << "Valeur de la force incorrecte" << std::endl ;
	} else 
	{
	// Exemple création de tir
	Tir* tir = new Tir(p_x,p_y,50,5,nbDegats) ;
	// Trajectoires
	int cibleX = tir->t_portee*(cos(tir->t_angle*PI/180));
	int cibleY = tir->t_portee*(sin(tir->t_angle*PI/180));
	// Mouvement du tir
	tir->t_x += cibleX ;
	tir->t_y += cibleY ;
	// On vérifie qu'il n'atteint pas les limites de la fenetre
	/*if ((tir->t_x >= window.x) || tir->t_y >= window.y))
	{
		std::cerr << "On a atteint les limites" << std::endl ;
	}*/
	if (p_vie > 0) {
		p_vie -= nbDegats ;
	}
	}
	//else
	//{
		//Personnage::~Personnage();
	//}
}

std::ostream& operator<<(std::ostream &strm, const Personnage &p) {
	return strm << "Personnage x:" << p.p_x << " y:" << p.p_x << " angle:" << p.p_rotation ;
}