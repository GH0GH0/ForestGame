#include "Game.h"
#include <iostream>

using namespace std ;

// Itérateurs
    list<Obstacle*>::iterator it_obstacles ;
    list<Batisse>::iterator it_batisses ;


Game::Game()
{
	foret = Forest(60,60);
	perso1 = Personnage(0, 0, 20);
	perso2 = Personnage(10, 0, 20);
}


Game::~Game()
{
}

void Game::collision(Personnage const& p) {
	// On vérifie avec les obstacles
for (it_obstacles = foret.getObstacles().begin(); it_obstacles!=foret.getObstacles().end(); it_obstacles++)
{
	// On utilise (*iterateur)->methode parce que iterateur renvoie un pointeur sur un objet de la classe
	if (p.getX() == (*it_obstacles)->getX() || p.getY() == (*it_obstacles)->getY())
	{
		cout << "COLLISION !" << endl ;
	}
}
	// On vérifie avec les batisses
for (it_batisses = foret.getBatisses().begin(); it_batisses!= foret.getBatisses().end(); it_batisses++)
{
	// Ici l'itérateur renvoie directement un objet de type batisse
	if (p.getX() == it_batisses->getX() || p.getY() == it_batisses->getY())
	{
		cout << "COLLISION !" << endl ;
	}
}
}

void Game::startGame()
{
	bool firstChar=true;
	Personnage* persActuel = &perso1;
	cout << "assasin creed pixel" << std::endl;
	while (true)
	{   
		if(firstChar)
			cout << "Pers1" << std::endl;
		else
			cout << "Pers2" << std::endl;
		cout << "orientation" << std::endl;
		int angle;
		cin >> angle;
		persActuel->setOrientation(angle);
		cout << "distance" << std::endl;
		cout << "angle" << std::endl;
		cout << "tir" << std::endl;
		int distance;
		cin >> distance;
		cout << *persActuel << std::endl;
		firstChar = !firstChar;
		if (firstChar)
			persActuel = &perso1;
		else
			persActuel = &perso2;
	}
}
