#include "forest.h"
#include <iostream>

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

list<Obstacle*> Forest::getObstacles() {
    return f_obstacles ;
}

list<Batisse>  Forest::getBatisses() {
    return f_batisses ;
}