#ifndef _CITY_H
#define _CITY_H

#include <iostream>
#include <array>
#include "GameSpecs.h"

using namespace std;

class Organism;


class City
{
private:
    Organism *map[GRIDSIZE][GRIDSIZE]{};
    //counter variables
    int zombies = 0;
    int humans = 0;

public:
    //---constructors---//
    City();
    virtual ~City();

//    Organism *getOrganism( int x, int y );
//    void setOrganism( Organism *organism, int x, int y );

//    void move();
//    void reset();
    array<int, 2> spawnPoint();
    void spawnOrganisms();
    int counter(char orgType);
    bool hasDiversity();

    //---counters---//
    void incZombies() { zombies++; };
    int zombieCount() { return zombies; };
    void incHumans() { humans++; };
    int humanCount() { return humans; }

    friend ostream& operator<<( ostream &output, City &city );
};

#endif

