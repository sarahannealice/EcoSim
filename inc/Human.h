#ifndef _Human_H
#define _Human_H

#include "City.h"
#include "Organism.h"

class Human : public Organism
{
private:
    char type = HUMAN;
    int recruitCount;
public:
    //---constructors---//
	Human() = default;
	Human( City *city, int x, int y, char type) : Organism(city, x, y, type), recruitCount(0) {
        city->incHumans();
    };

    //---destructor---//
	~Human() override = default;

//	void move();
};

#endif
