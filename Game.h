#ifndef GAME_H
#define GAME_H

#include "personnage.h"
#include "obstacle.h"
#include "arbre.h"
#include "batisse.h"
#include "forest.h"
#include <iostream>

class Game
{
private :                           
	Personnage perso1;
	Personnage perso2;
public:
	Game();
	~Game();
	void startGame();
	void startGraphic();
};

#endif