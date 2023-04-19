#ifndef _Zombie_H
#define _Zombie_H

#include <vector>
#include "City.h"
#include "Organism.h"

class Zombie : public Organism
{
protected:
    char type = ZOMBIE;
    int breedCount;
    int starveCount;
public:
    //---constructors---//
	Zombie() = default;
	Zombie( City *city, int x, int y, char type) : Organism(city, x, y, type), breedCount(0), starveCount(0) {
        city->incZombies();
    };

    //---destructor---//
	~Zombie() override;

    //---methods---//
	void move() override;
    void routine() override;
    vector<spaces> findFood();
//    bool breed();
//    void starve();

    //vector<spaces> moveOptions() override;

};
#endif
