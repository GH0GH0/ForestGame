#include "personnage.h"
// #include "forest.h" a voir

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
	this->p_x=tocopy.getX();
	this->p_y=tocopy.getY();
	this->p_d=tocopy.getD();
	this->p_vie=tocopy.getV();
}


Personnage::~Personnage()
{
//cout << "Destruction of the object" ;
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

int Personnage::getV() const
{
	return p_Vie;
}

void Personnage::setOrientation(int angle)
{
	if (angle > 0 && angle < 360)
		p_rotation = angle;
}

void Personnage::avancer(int distance) {
	if (p_x+distance <= f_X_size)
		p_x=p_x - distance;
	
}

void Personnage::reculer(int distance) {
	if (p_x+distance >= 0)
		p_x=p_x - distance;
	
}

void Personnage::monter(int distance) {
	if (p_y+distance >= f_Y_size)
		p_y=p_y + distance;
	
}

void Personnage::descendre(int distance) {
	if (p_y-distance >= 0)
		p_y=p_y - distance;
	
}



void Personnage::tirer(int nbDegats) {
	if (p_vie > 0) {
		p_vie -= nbDegats ;
	}
	//else
	//{
		//Personnage::~Personnage();
	//}
}

std::ostream& operator<<(std::ostream &strm, const Personnage &p) {
	return strm << "Personnage x:" << p.p_x << " y:" << p.p_x << " angle:" << p.p_rotation ;
}
