#ifndef _Organism_H
#define _Organism_H

#include <vector>
#include <iostream>
#include "GameSpecs.h"


class City;

class Organism
{
protected:
	int x;
	int y;
    char type;
	bool moved;
	City *map;

	enum { NORTH, NE, EAST, SE, SOUTH, SW, WEST, NW } typedef spaces;

public:
    //---constructors---//
	Organism() = default;
	Organism( City *map, int x, int y, char type): map(map), x(x), y(y), type(type), moved(false) {};
	//---destructor---//
    virtual ~Organism() = default;


    char getType() const {return type;};

//    virtual void getMoves() = 0;

//	virtual void move() = 0;
//    virtual void routine() = 0;
//    virtual void reproduce() = 0;
    //virtual vector<spaces> moveOptions();

//	void setPosition( int x, int y );


	friend ostream& operator<<( ostream &output, Organism *organism );
};

#endif
