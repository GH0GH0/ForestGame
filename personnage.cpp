#include "personnage.h"

sf::Texture perso;
sf::Sprite sprite_perso;
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