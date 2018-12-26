#include "Game.h"



Game::Game()
{
	perso1 = Personnage(0, 0, 20);
	perso2 = Personnage(10, 0, 20);
}


Game::~Game()
{
}

void Game::startGame()
{
	bool firstChar=true;
	Personnage* persActuel = &perso1;
	std::cout << "assasin creed pixel" << std::endl;
	while (true)
	{   
		if(firstChar)
			std::cout << "Pers1" << std::endl;
		else
			std::cout << "Pers2" << std::endl;
		std::cout << "orientation" << std::endl;
		int angle;
		std::cin >> angle;
		persActuel->setOrientation(angle);
		std::cout << "distance" << std::endl;
		std::cout << "angle" << std::endl;
		std::cout << "tir" << std::endl;
		int distance;
		std::cin >> distance;
		std::cout << *persActuel << std::endl;
		firstChar = !firstChar;
		if (firstChar)
			persActuel = &perso1;
		else
			persActuel = &perso2;
	}
}
