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
const int ITERATIONS = 5000;//time-steps
const char BLANK = 48;//ascii for 0
const string BLANKCOLOR = "\033[34m";//pale blue

//---human specs---//
const char HUMAN = 72;//ascii H
const int HUMANSTART =  50;
const int RECRUIT = 3;
const string HUMANCOLOR = "\033[93m";//yellow

//---zombie specs---//
const char ZOMBIE = 90;//ascii Z
const int ZOMBIESTART = 5;
const int BREED = 8;
const int STARVE = 3;
const string ZOMBIECOLOR = "\033[92m";//green

//---colors provided by David---//
//0  = black				//9  = bright blue
//1  = blue					//10 = bright green
//2  = green				//11 = bright turquoise
//3  = turquoise			//12 = bright red
//4  = red					//13 = bright pink
//5  = pink					//14 = bright yellow
//6  = yellow				//15 = bright white
//7  = white regular		//16+ = solid blocks
//8  = white pale

#endif //ECOSIM_SIMSPECS_H
