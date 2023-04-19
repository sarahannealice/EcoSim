//
// Created by sarah on 18/04/2023.
//
using namespace std;

#include "../inc/Organism.h"



//places desired organism at x,y location on map
void Organism::placeOrg(Coordinate xy) {
    city->setOrg();
}

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

