//
// Created by sarah on 18/04/2023.
//
using namespace std;

#include "../inc/Organism.h"
#include "../inc/City.h"


//places desired organism at x,y location on map
//void Organism::placeOrg(Organism* organism, Coordinate update) {
//    //removes organism from current grid position
//    map->resetOrg(this->xy);
//    cout << "coordinates of new location: " << update.x << " " << update.y << endl;
//    //adds organism to new grid location
//    map->setOrg(organism, update);
//
//}

ostream &operator<<(ostream &output, Organism *organism) {

    //checks organism type and prints in corresponding colour
    switch (organism->type) {
        case ZOMBIE:
            output << " " << ZOMBIECOLOR << organism->type << BLANKCOLOR << " ";
            break;
        case HUMAN:
            output << " " << HUMANCOLOR << organism->type << BLANKCOLOR << " ";
    }
    return output;
}

