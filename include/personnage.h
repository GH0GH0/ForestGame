#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <iostream>

class Personnage
{
    protected:
	//position
	int p_x;
	int p_y;
	//orientation du joueur
	int p_rotation;
	int p_angle_tir;
	// Caractéristiques
	int p_vie;
	// J'ai initialisé ça en attendant
	int p_forceFrappe = 5 ;
	int p_porteeFrappe = 5;
	friend std::ostream& operator<<(std::ostream &strm, const Personnage &a);

    public:

	Personnage();
	Personnage(int x, int y, int vie);
	Personnage(Personnage const& tocopy);
	~Personnage();
	// Getters
	virtual int getX() const;
	virtual int getY() const;
	void setOrientation(int angle);
	void marcher(int distance);
	void tirer(int forceFrappe, int porteeFrappe, int angle_tir);


   

};





#endif // !PERSONNAGE_H

