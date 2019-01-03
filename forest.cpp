#include "forest.h"

using namespace std;

Forest::Forest() {
    f_X_size = 0 ;
    f_Y_size = 0 ;
    int f_x = 0 ;
    int f_y = 0 ;
    f_obstacles.clear();
    //f_batisses.clear();
} 

Forest::Forest(int X_size,int Y_size) {
    f_X_size = X_size ;
    f_Y_size = Y_size ;
    f_x = f_X_size / 2 ;
    f_y = f_Y_size / 2 ;
}

Forest::Forest(Forest const& tocopy) {
    if (this != &tocopy)
    {
    f_X_size = tocopy.f_X_size ;
    f_Y_size = tocopy.f_Y_size ;
    f_x = tocopy.f_x ;
    f_y = tocopy.f_y ;
    f_obstacles = tocopy.f_obstacles ;
    //f_batisses = tocopy.f_batisses ;
    }
}

Forest::~Forest() {

}

void Forest::Destroy_obstacles(Obstacle* obstacle)
{
    if(obstacle) {
	f_obstacles.remove(obstacle);
	obstacle = NULL;
    }
    else {
        cerr << "Cet obstacle n'existe pas" << endl ;
    }
}

void Forest::addObstacle(Obstacle *obstacle)
{
    if (obstacle != NULL)
    {
        // On recupere toutes les coordonnes de l'obstacle
        int ox = obstacle->getX() ;
        int oy = obstacle->getY() ;
        int orayon = obstacle->getD() / 2 ; 
        // On vérifie que l'obstacle sera à l'interieur de la fenetre, en veillant à ce que le cercle qui représente l'obstacle soit bien à l'interieur de la foret
        // * Les obstacles sont représentés par des cercles dont le (x,y) en est le centre 
        if ((ox + orayon > f_X_size) || (oy + orayon > f_Y_size))
        {
            cerr << "Coordonnées de l'obstacle hors limites de la foret " << endl;
            return ;
        } 
        else {
            // Itérateurs
            list<Obstacle*>::iterator it ;
            for (it = f_obstacles.begin(); it!= f_obstacles.end(); it++)
            {
	            // On utilise (*iterateur)->methode parce que iterateur renvoie un pointeur sur un objet de la classe
                int ix = (*it)->getX() ;
                // int ox2 = (*it)->getX() + ( (*it)->getD() / 2) ;
                int iy = (*it)->getY() ;
                // int oy2 = (*it)->getY() + ( (*it)->getD() / 2) ;
                int irayon = (*it)->getD()/2 ;
                // ==============
                // J'ai utilisé la même technique que Ghozali pour la collision
                int distanceX = abs(ox - ix);
	            int distanceY = abs(oy- iy);
	            int distance = sqrt((distanceX*distanceX) + (distanceY*distanceY)); 

	            if (distance <= orayon + irayon) 
	            {
                    cerr << "Obstacles supersposés ! " << endl ;
		        return;
	            }
            }
        }
	f_obstacles.push_back(obstacle);
    }
}

void Forest::clearAllObstacles()
{
	f_obstacles.clear();
}

void Forest::save(std::string filename)
{
	std::ofstream myfile(filename);
	if (myfile.is_open()) {
		myfile << f_X_size << ", " << f_Y_size << "\n";
		myfile << f_obstacles.size() << "\n";
		for (std::list<Obstacle*>::iterator it = f_obstacles.begin(); it != f_obstacles.end();  ++it)
		{
			myfile  << (*it)->getName() << ", " << (*it)->getX() << ", " << (*it)->getY() << ", " << (*it)->getD() << ", " << (*it)->getH() << "\n";
		}
		myfile.close();
	}
}

void Forest::load(std::string filename)
{
}
