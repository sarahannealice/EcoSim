#ifndef ECOSIM_SIMSPECS_H
#define ECOSIM_SIMSPECS_H

#include <string>
#include <cstdlib>
#include "GameSpecs.h"

using namespace std;

//resource for ascii table -- https://en.cppreference.com/w/cpp/language/ascii
//resource for colours -- https://stackoverflow.com/a/54062826
//reason for const vs #define -- https://stackoverflow.com/a/3835772
//---city specs & miscellaneous---//
const int GRIDSIZE = 20;
const int INTERVAL = 1000;//time
const int ITERATIONS = 1000;//time-steps
const char BLANK = '0';//ascii for 0
const string BLANKCOLOR = "\033[34m";//pale blue

//---human specs---//
const char HUMAN = 'H';//ascii H
const int HUMANSTART =  5;//****change when done troubleshooting****
const int RECRUIT = 3;
const string HUMANCOLOR = "\033[95m";//bright magenta

//---zombie specs---//
const char ZOMBIE = 'Z';//ascii Z
const int ZOMBIESTART = 5;
const int BREED = 8;
const int STARVE = 3;
const string ZOMBIECOLOR = "\033[92m";//bright green

#endif //ECOSIM_SIMSPECS_H
