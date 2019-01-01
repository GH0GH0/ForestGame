#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <iostream>

struct Tir {
	//Attributs
	int t_x ;
	int t_y ;
	int t_angle ;
	int t_portee ;
	int t_force ;
	//Constructeur
	Tir(int x,int y,int angle,int portee,int force);
} ;

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
	// int p_angle_tir;
	// Carat�riqtiques
	int p_vie;
	friend std::ostream& operator<<(std::ostream &strm, const Personnage &a);

    public:

	Personnage();
	Personnage(int x, int y, int d,int vie);
	Personnage(Personnage const& tocopy);
	~Personnage();
	//Getters
	virtual int getX() const;
	virtual int getY() const;
	virtual int getD() const;
	void setOrientation(int angle);
	void avancer (int distance);
	void reculer (int distance);	
	void monter (int distance);
	void descendre (int distance);
	void tirer(int nbDegats);


  
};





#endif // !PERSONNAGE_H

