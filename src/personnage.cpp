#include "personnage.h"
#include <cmath>
#define PI 3.14159265

Personnage::Personnage()
{
	p_x = 0;
	p_y = 0;
<<<<<<< HEAD
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
>>>>>>> master
}

{
}

<<<<<<< HEAD
int Personnage::getX() {
	return p_x ;
}

int Personnage::getY() {
	return p_y ;
}
=======
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

void Personnage::marcher(int distance) {
<<<<<<< HEAD
// 3 pixels max de déplacement
}

void Personnage::tirer(int forceFrappe, int porteeFrappe, int angle_tir) {
	if (p_vie > 0) {
		p_vie -= forceFrappe ;
	}
	// Quand le joueur va tirer, la balle va bouger de X pixels selon l'angle de frappe, si il touche un obstacle ou un joueur, ça diminue la force ou ça tue le joueur, sinon on enlève sa vie, je sais pas si on peut faire ça sans SFML
=======

}

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
>>>>>>> master
}

std::ostream& operator<<(std::ostream &strm, const Personnage &p) {
	return strm << "Personnage x:" << p.p_x << " y:" << p.p_x << " angle:" << p.p_rotation ;
}