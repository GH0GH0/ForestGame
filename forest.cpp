#include "forest.h"

using namespace std;

Forest::Forest() {
    f_X_size = 0 ;
    f_Y_size = 0 ;
    int f_x = 0 ;
    int f_y = 0 ;
    f_obstacles.clear();
    f_batisses.clear();
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
    f_batisses = tocopy.f_batisses ;
    }
}

Forest::~Forest() {

}

void Forest::Destroy_obstacles(Obstacle* obstacle)
{
	f_obstacles.remove(obstacle);
	obstacle = NULL;
}

void Forest::addObstacle(Obstacle *obstacle)
{
	f_obstacles.push_back(obstacle);
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
