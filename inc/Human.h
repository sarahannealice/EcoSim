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
	Human( City *city, Coordinate xy, char type) : Organism(city, xy, type), recruitCount(0) {
        city->incHumans();
    };

    //---destructor---//
	~Human() override = default;

    //---methods---//
    void move() override;
    void routine() override;
    vector<Coordinate> viableSpaces();

    //---routine specifics---//
    void recruit();

};

#endif
