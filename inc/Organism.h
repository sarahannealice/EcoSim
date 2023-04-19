#ifndef _Organism_H
#define _Organism_H

#include <vector>
#include <iostream>
#include "GameSpecs.h"


class City;

class Organism
{
protected:
    int x{};
    int y{};
    char type;
	bool moved;
	City *map;

public:
    enum { NORTH, NE, EAST, SE, SOUTH, SW, WEST, NW } typedef spaces;

    //---constructors---//
	Organism() = default;
	Organism( City *map, int x, int y, char type): map(map), x(x), y(y), type(type), moved(false) {};
	//---destructor---//
    virtual ~Organism() = default;

    //---methods---//
    char getType() const {return type;};//might not need
    virtual void routine() = 0;
    virtual void move() = 0;
    void placeOrg( int x, int y );

//    virtual void getMoves() = 0;

//    virtual void reproduce() = 0;
    //virtual vector<spaces> moveOptions();



	friend ostream& operator<<( ostream &output, Organism *organism );
};

#endif
