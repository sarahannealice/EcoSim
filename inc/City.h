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

    //---methods---//
    array<int, 2> spawnPoint();
    void spawnOrganisms();
    int counter(char orgType);
    bool hasDiversity();
    void move();
    bool isHuman(Coordinate xy);
    void setOrg(Organism* organism, Coordinate xy);
    Organism *getOrg(Coordinate xy);
    void removeOrg(Coordinate xy);


//    void reset();

    //---counters---//
    void incZombies() { zombies++; };
    int zombieCount() const { return zombies; };
    void incHumans() { humans++; };
    int humanCount() const { return humans; }

    friend ostream& operator<<( ostream &output, City &city );
};

#endif

