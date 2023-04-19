#ifndef _Organism_H
#define _Organism_H

#include <vector>
#include <iostream>
#include "GameSpecs.h"


class City;

class Organism
{
protected:
    char type;
	bool moved;
	City *map;

public:
    Coordinate xy;
    int x{};
    int y{};
    enum { NORTH, NE, EAST, SE, SOUTH, SW, WEST, NW } typedef spaces;

    //---constructors---//
	Organism() = default;
	Organism(City *map, Coordinate xy, char type): map(map), xy(xy), type(type), moved(false) {};
	//---destructor---//
    virtual ~Organism() = default;

    //---methods---//
    char getType() const {return type;};//might not need
    virtual void routine() = 0;
    virtual void move() = 0;
    void placeOrg(Coordinate xy);

//    virtual void getMoves() = 0;

//    virtual void reproduce() = 0;
    //virtual vector<spaces> moveOptions();



	friend ostream& operator<<( ostream &output, Organism *organism );

};

#endif
