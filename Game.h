#ifndef GAME_H
#define GAME_H

#include "personnage.h"
#include "obstacle.h"
#include "arbre.h"
#include "rocher.h"
#include "batisse.h"
#include "forest.h"
#include "Menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Game
{
private :                           
	Personnage perso1;
	Personnage perso2;
	enum state { menuGlobal, menu1, option };
	state actualState;
	Menu menu;
public:
	Game();
	~Game();
	void startGame();
	void startGraphic();
	void showmenu(sf::RenderWindow &window);
};

#endif