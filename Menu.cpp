#include "Menu.h"



Menu::Menu(int width, int height)
{
	if (!font.loadFromFile("sansation.ttf"))
	{
		// handle error
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Green);
	menu[0].setString("Démarrer");
	menu[0].setPosition(sf::Vector2f(width / 2, height / ((MAX_NUMBER_OF_ITEMS + 1) + 5) + height/4));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(width / 2, height / ((MAX_NUMBER_OF_ITEMS + 1) + 2) + height / 4));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / ((MAX_NUMBER_OF_ITEMS + 1) + 0.5 ) + height / 4));

	selecteditemIndex = 0;
}




Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selecteditemIndex - 1 >= 0)
	{ 
	  menu[selecteditemIndex].setFillColor(sf::Color::White);
	  selecteditemIndex--;
	  menu[selecteditemIndex].setFillColor(sf::Color::Green);
	}
}

void Menu::MoveDown()
{
	if (selecteditemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selecteditemIndex].setFillColor(sf::Color::White);
		selecteditemIndex++;
		menu[selecteditemIndex].setFillColor(sf::Color::Green);
	}
}
