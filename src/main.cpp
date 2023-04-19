//
// Created by W0068332 on 11/21/2021.
//
//Example main.cpp
//This supposes that city->step() calls the move method of each organism in the city
//in a single pass causing each to perform all tasks that it can.

#include <iostream>
#include <chrono>
#include <thread>
#include "../inc/GameSpecs.h"
#include "../inc/Organism.h"
#include "../inc/City.h"

using namespace std;

//function that prints blank lines to 'clear screen'
void ClearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main() {
    int generation = 0;//generation counter
    City *map = new City();

    //intro
    cout << BLANKCOLOR;
    cout << "*.* ecosystem simulation between zombies and humans *.*\n\n";

    chrono:: milliseconds interval(INTERVAL);

    while (map->hasDiversity()) { //while both humans and zombies exist
        this_thread::sleep_for(interval);

        cout << *map; //prints city
        cout << "generation: " << generation << endl;
        cout << "humans: " << map->humanCount() << endl;
        cout << "zombies: " << map->zombieCount() << endl;

        map->move(); //includes all actions
        map->reset(); //resets moved flags

        generation++;//increases generation each
        if (generation >= ITERATIONS) {
            break;
        }
        ClearScreen();
    }//end while
}//end main

