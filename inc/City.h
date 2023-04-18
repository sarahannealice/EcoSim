#ifndef _CITY_H
#define _CITY_H

#include <iostream>
#include <array>
#include "SimSpecs.h"

using namespace std;

class Organism;

const int GRID_WIDTH = GRIDSIZE;
const int GRID_HEIGHT = GRIDSIZE;

class City
{
protected:
    Organism *grid[GRID_HEIGHT][GRID_WIDTH];

public:
    //---constructors---//
    City();
    virtual ~City();

    Organism *getOrganism( int x, int y );
    void setOrganism( Organism *organism, int x, int y );

    void move();
    void reset();
    void spawnHuman();
    void spawnZombie();
    int countTyoe(char orgType);
    bool hasDiversity();
    array<int, 2> emptySpot();

    friend ostream& operator<<( ostream &output, City &city );
};

#endif

