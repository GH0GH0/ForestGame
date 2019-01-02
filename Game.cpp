//#include <SFML/Graphics.hpp>
#include "Game.h"

//#include"menu1.h"
#include <fstream>

Game::Game()
{
	perso1 = Personnage(0, 0,1, 20);
	perso2 = Personnage(10, 0,1, 20);
	menu = Menu(1080, 720);
}


Game::~Game()
{
}

void Game::startGame()
{
	bool firstChar=true;
	Personnage* persActuel = &perso1;
	std::cout << "Bateille en Foret" << std::endl;

	

	int sizeX = 0;
	int sizeY = 0;
	std::cout << "saisir la taille de la foret " << std::endl;
	std::cout << "saisir la taille X " << std::endl;
	std::cin >> sizeX  ;
	std::cout << "saisir la taille Y " << std::endl;
	std::cin >> sizeY  ;
	Forest foret(sizeX, sizeY); 
	int nbrO = 0;
	std::cout << "saisir le nombre d'obstacle " << std::endl;
	std::cin >> nbrO;
	for (int i=0; i<nbrO;i++){
	int posX = 0;
	int posY = 0;
	int hauteur = 0;
	int diametre = 0;
	int typeO = 0;

	std::cout << "saisir la position X " << std::endl;
	std::cin >> posX;
	std::cout << "saisir la position Y " << std::endl;
	std::cin >> posY;
	std::cout << "saisir la hauteur " << std::endl;
	std::cin >> hauteur;
	std::cout << "saisir le diametre " << std::endl;
	std::cin >> diametre;
	std::cout << "saisir le type de l'obstacle : \n 0: arbre \n 1:rocher \n 2:batisse " << std::endl;
	std::cin >> typeO;
	if(typeO==0)
		foret.addObstacle(new Arbre(posX, posY, diametre, hauteur));
	else if (typeO ==1 )
		foret.addObstacle(new Rocher(posX, posY, diametre, hauteur));
	else if (typeO==2)
		foret.addObstacle(new Batisse(posX, posY, diametre, hauteur));
	}
	
	foret.save("save.txt");
	/*while (true)
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
	}*/
}

void Game::startGraphic()
{
	sf::Texture titre;
	sf::Sprite sprite_titre;
	sf::RenderWindow window;
	window.create(sf::VideoMode(1080, 720), "SFML works!");
	window.setPosition(sf::Vector2i(0, 0));
	//menu = Menu(1080, 720);
	//Menu1 menu1(1080, 720);
	actualState = state::menuGlobal;
	//window.setMouseCursorVisible(false); //pour faire disparaitre le curseur de souris


	if (!titre.loadFromFile("titre.png"))
	{
		std::cout << "erreur de chargement de titre.png" << std::endl;
	}
	titre.setSmooth(true);
	bool updateFPS = true;
	sprite_titre.setTexture(titre);
	sprite_titre.setPosition(150, 60);
	while (window.isOpen())
	{    
		//sf::Event event;
		if (actualState == state::menuGlobal)
		{
			//window.draw(sprite_titre);
			showmenu(window);
		}
			
			


		}
		
		
		//menu1.draw(window);
		//menu.draw(window);
		//window.display();

		//window.clear();
	}

void Game::showmenu(sf::RenderWindow &window)
{
//	window.draw(sprite_titre);
	menu.draw(window);

	window.display();
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
				//std::cout << "Play button has been pressed" << std::endl;


				window.clear();
				//menu1.draw(window);
				window.display();
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

}

