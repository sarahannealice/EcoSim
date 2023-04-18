//
// Created by sarah on 18/04/2023.
//

#ifndef ECOSIM_SIMSPECS_H
#define ECOSIM_SIMSPECS_H

#include <string>
#include "SimSpecs.h"

using namespace std;

//resource for colours -- https://www.geeksforgeeks.org/how-to-print-colored-text-in-c/
//reason for const vs #define -- https://stackoverflow.com/a/3835772
//---city specs & miscellaneous---//
const int GRIDSIZE = 20;
const int INTERVAL = 1000;//time
const int ITERATIONS = 1000;//time-steps
const int BLANKCOLOR = 5;

//---human specs---//
const char HUMAN = 72;//ascii H
const int HUMANSTART =  50;
const int RECRUIT = 3;
const int HUMANCOLOR = 3;

//---zombie specs---//
const char ZOMBIE = 90;//ascii Z
const int ZOMBIESTART = 5;
const int BREED = 8;
const int STARVE = 3;
const int ZOMBIECOLOR = 4;

#endif //ECOSIM_SIMSPECS_H
