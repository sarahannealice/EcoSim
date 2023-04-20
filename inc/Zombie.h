#ifndef _Zombie_H
#define _Zombie_H

#include <vector>
#include "City.h"
#include "Organism.h"

class Zombie : public Organism
{
protected:
    int breedCount{};
    int starveCount{};

public:
    //---constructors---//
	Zombie() = default;
	Zombie( City *map, Coordinate xy, char type) : Organism(map, xy, type), breedCount(0), starveCount(0) {
        map->incZombies();
    };

    //---destructor---//
	~Zombie() override = default;

    //---methods---//
	void move() override;
    void routine() override;
    void starve();
    void reproduce();
    vector<Coordinate> viableSpaces();
};
#endif
