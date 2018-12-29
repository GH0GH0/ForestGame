#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"



Game::Game()
{
	perso1 = Personnage(0, 0,1, 20);
	perso2 = Personnage(10, 0,1, 20);
}


Game::~Game()
{
}

void Game::startGame()
{
	bool firstChar=true;
	Personnage* persActuel = &perso1;
	std::cout << "Bateille en Foret" << std::endl;
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

void Game::startGraphic()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(1080, 720), "SFML works!");
	window.setPosition(sf::Vector2i(192, 0));
	Menu menu(1080, 720);

	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				menu.MoveUp();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				menu.MoveDown();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				switch (menu.GetPressedItem())
				{
				 case 0:
					std::cout << "Play button has been pressed" << std::endl;
					break;
				 case 1:
					std::cout << "Option button has been pressed" << std::endl;
					break;
				 case 2:
					 window.close();
					 break;
				}
			}
			if (event.type == sf::Event::Closed)
				window.close();


		}
		


		menu.draw(window);
		window.display();

		window.clear();
	}

}

