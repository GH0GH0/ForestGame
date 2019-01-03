//#include <SFML/Graphics.hpp>
#include "Game.h"
#include <string>
//#include"menu1.h"
#include <fstream>

using namespace std;

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
	cout << "Bataille en Foret" << endl;

	int sizeX = 0;
	int sizeY = 0;
	// Coordonnées de la forêt
	int error = 0
	cout << "saisir la taille de la foret " << endl;
	do {
	error++
	if (error > 1) {
		cout << "Coordonnées de la forêt incorrectes" << endl ;
	}
	cout << "saisir la taille X " << endl;
	cin >> sizeX  ;
	cout << "saisir la taille Y " << endl;
	cin >> sizeY  ;
	} 
	while (sizeX < 0 || sizeY < 0);
	Forest foret(sizeX, sizeY); 
	// ==========================
	// Obstacles 
	int nbrO = 0;
	do {
	cout << "saisir le nombre d'obstacle " << endl;
	cin >> nbrO;
	} while (nbrO < 0) ;
	for (int i=0; i<nbrO;i++){
	int posX = 0;
	int posY = 0;
	int hauteur = 0;
	int diametre = 0;
	int typeO = 0;

	cout << "saisir la position X " << endl;
	cin >> posX;
	cout << "saisir la position Y " << endl;
	cin >> posY;
	cout << "saisir la hauteur " << endl;
	cin >> hauteur;
	cout << "saisir le diametre " << endl;
	cin >> diametre;
	do {
	cout << "saisir le type de l'obstacle : \n 0: arbre \n 1:rocher \n 2:batisse " << endl;
	cin >> typeO;
	if(typeO==0)
		foret.addObstacle(new Arbre(posX, posY, diametre, hauteur));
		cout << "Obstacle ajouté ! " << endl;
	else if (typeO ==1 )
		foret.addObstacle(new Rocher(posX, posY, diametre, hauteur));
		cout << "Obstacle ajouté ! " << endl;
	else if (typeO==2)
		foret.addObstacle(new Batisse(posX, posY, diametre, hauteur));
		cout << "Obstacle ajouté ! " << endl;	
	}
	} while (typeO < 0 || typeO > 2) ;
	// Sauvegarde dans le fichier 
	foret.save("save.txt");
	/*while (true)
	{   
		if(firstChar)
			cout << "Pers1" << endl;
		else
			cout << "Pers2" << endl;
		cout << "orientation" << endl;
		int angle;
		cin >> angle;
		persActuel->setOrientation(angle);
		cout << "distance" << endl;
		cout << "angle" << endl;
		cout << "tir" << endl;
		int distance;
		cin >> distance;
		cout << *persActuel << endl;
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
		cout << "erreur de chargement de titre.png" << endl;
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
				//cout << "Play button has been pressed" << endl;


				window.clear();
				//menu1.draw(window);
				window.display();
				break;
			case 1:
				cout << "Option button has been pressed" << endl;
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

