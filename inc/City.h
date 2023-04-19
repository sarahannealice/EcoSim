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
    bool hasDiversity() const;
    void move();
    void reset();
    bool isHuman(Coordinate xy);
    void placeOrg(Organism* organism, Coordinate xy);
    void resetOrg(Coordinate xy);
    Organism *getOrg(Coordinate xy);

    //---counters---//
    void incZombies() { zombies++; };
    void decZombies() { zombies--; };
    int zombieCount() const { return zombies; };
    void incHumans() { humans++; };
    void decHumans() { humans--; };
    int humanCount() const { return humans; }

    friend ostream& operator<<( ostream &output, City &city );
};

#endif

