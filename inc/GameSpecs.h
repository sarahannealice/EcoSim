#ifndef ECOSIM_SIMSPECS_H
#define ECOSIM_SIMSPECS_H

#include <string>
#include <cstdlib>
#include "GameSpecs.h"

using namespace std;

//struct for using grid coordinates
struct Coordinate {
    int x{};
    int y{};
    //---constructors---//
    Coordinate() {x = 0, y = 0;};
    Coordinate(int x, int y) : x(x), y(y) {};
};

//resource for ascii table -- https://en.cppreference.com/w/cpp/language/ascii
//resource for colours -- https://stackoverflow.com/a/54062826
//reason for const vs #define -- https://stackoverflow.com/a/3835772
//---city specs & miscellaneous---//
const int GRIDSIZE = 20;
const int INTERVAL = 300;//time -- used 50 interval to achieve results in roughly 2 minutes
const int ITERATIONS = 1000;//time-steps
const char BLANK = '0';//ascii for 0
const string BLANKCOLOR = "\033[34m";//pale blue

//---human specs---//
const char HUMAN = 'H';//ascii H
const int HUMANSTART = 100;//****change when done troubleshooting**** 70
const int RECRUIT = 3;
const string HUMANCOLOR = "\033[35m";//magenta (95 bright magenta)

//---zombie specs---//
const char ZOMBIE = 'Z';//ascii Z
const int ZOMBIESTART = 25;//****change when done troubleshooting****
const int BREED = 8;
const int STARVE = 3;
const string ZOMBIECOLOR = "\033[92m";//bright green (32 green)

#endif //ECOSIM_SIMSPECS_H
