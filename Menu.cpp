#include "Menu.h"



Menu::Menu(int width, int height)
{
	font = new sf::Font();
	if (!font->loadFromFile("sansation.ttf"))
	{
		// handle error
	}
	
	menu[0].setFont(*font);
	menu[0].setFillColor(sf::Color(17, 214, 46)); //le couleur du 1er choix du menu
	menu[0].setString("Démarrer"); 
	menu[0].setPosition(sf::Vector2f(width / 2, height / ((MAX_NUMBER_OF_ITEMS + 1) + 5) + height/4));//l'emplacement

	menu[1].setFont(*font);
	menu[1].setFillColor(sf::Color::White);//la couleur par defaut 
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(width / 2, height / ((MAX_NUMBER_OF_ITEMS + 1) + 2) + height / 4));

	menu[2].setFont(*font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / ((MAX_NUMBER_OF_ITEMS + 1) + 0.5 ) + height / 4));

	selecteditemIndex = 0;
	std::cout << "menu construct" << std::endl;
}

Menu::Menu()
{
	Menu::Menu(1080, 720);
}



Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		std::cout << "draw " << i << "lol" << std::endl;
		std::cout << "menu i " << (std::string)menu[i].getString() << "lol" << std::endl;
		window.draw(menu[i]);
		
	}
}

void Menu::MoveUp()
{
	if (selecteditemIndex - 1 >= 0)
	{ 
	  menu[selecteditemIndex].setFillColor(sf::Color::White);
	  selecteditemIndex--;
	  menu[selecteditemIndex].setFillColor(sf::Color(17, 214, 46));
	}
}

void Menu::MoveDown()
{
	if (selecteditemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selecteditemIndex].setFillColor(sf::Color::White);
		selecteditemIndex++;
		menu[selecteditemIndex].setFillColor(sf::Color(17, 214, 46));
	}
}



