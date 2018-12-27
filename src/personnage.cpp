#include "personnage.h"

Personnage::Personnage()
{
	p_x = 0;
	p_y = 0;
	p_vie = 0;
}

Personnage::Personnage(int x, int y, int vie)
{
	p_x = x;
	p_y = y;
	p_vie = vie;
}

Personnage::Personnage(Personnage const& tocopy)
{
	p_x = tocopy.p_x ;
	p_y = tocopy.p_y ;
	p_vie = tocopy.p_vie ;
}

Personnage::~Personnage()
{
}

int Personnage::getX() {
	return p_x ;
}

int Personnage::getY() {
	return p_y ;
}
void Personnage::setOrientation(int angle)
{
	if (angle > 0 && angle < 360)
		p_rotation = angle;
}

void Personnage::marcher(int distance) {
// 3 pixels max de déplacement
}

void Personnage::tirer(int forceFrappe, int porteeFrappe, int angle_tir) {
	if (p_vie > 0) {
		p_vie -= forceFrappe ;
	}
	// Quand le joueur va tirer, la balle va bouger de X pixels selon l'angle de frappe, si il touche un obstacle ou un joueur, ça diminue la force ou ça tue le joueur, sinon on enlève sa vie, je sais pas si on peut faire ça sans SFML
}

std::ostream& operator<<(std::ostream &strm, const Personnage &p) {
	return strm << "Personnage x:" << p.p_x << " y:" << p.p_x << " angle:" << p.p_rotation ;
}