#ifndef _Organism_H
#define _Organism_H

#include <iostream>
#include "GameSpecs.h"

using namespace std;

class City;

class Organism
{
protected:
	int x;
	int y;
    int type;
	bool moved;
	City *city;

	enum { NORTH, NE, EAST, SE, SOUTH, SW, WEST, NW };

public:
	Organism();
	Organism( City *city, int x, int y, int type);
	virtual ~Organism();

	virtual void move() = 0;
	//virtual void spawn() = 0;
	//virtual int getSpecies() = 0; //this could also be coded concrete here
	//virtual void getPosition() = 0;

	void setPosition( int x, int y );
	void endTurn();
	bool isTurn();

	friend ostream& operator<<( ostream &output, Organism *organism );
};

#endif
