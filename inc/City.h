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
    Organism *grid[GRIDSIZE][GRIDSIZE]{};

public:
    //---constructors---//
    City();
    virtual ~City();

    Organism *getOrganism( int x, int y );
    void setOrganism( Organism *organism, int x, int y );

    void move();
    void reset();
    void spawnOrganisms();
    int countType(char orgType);
    bool hasDiversity();

    friend ostream& operator<<( ostream &output, City &city );
};

#endif

