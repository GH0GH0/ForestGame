#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <iostream>

class Personnage
{
    protected:
	//position
	int p_x;
	int p_y;
	//diametre pour la collision(avec une valeur par default)
	int p_d;
	//orientation du joueur
	int p_rotation;
	int p_angle_tir;
	// Caratériqtiques
	int p_vie;
	friend std::ostream& operator<<(std::ostream &strm, const Personnage &a);

    public:

	Personnage();
	Personnage(int x, int y, int d,int vie);
	Personnage(Personnage const& tocopy);
	~Personnage();
	virtual int getX() const;
	virtual int getY() const;
	virtual int getD() const;
	void setOrientation(int angle);
	void marcher(int distance);
	void tirer(int nbDegats);


   

};





#endif // !PERSONNAGE_H

