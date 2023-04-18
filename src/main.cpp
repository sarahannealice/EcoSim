//
// Created by W0068332 on 11/21/2021.
//
//Example main.cpp
//This supposes that city->step() calls the move method of each organism in the city
//in a single pass causing each to perform all tasks that it can.

#include <iostream>
#include <chrono>
#include <thread>
#include "../inc/Organism.h"
#include "../inc/City.h"

using namespace std;

//function that prints blank lines to 'clear screen'
void ClearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main() {
    int generation = 0;//generation counter
    City *city = new City();

    chrono:: milliseconds interval(INTERVAL);

    while (city->hasDiversity()) { //while both humans and zombies exist
        this_thread::sleep_for(interval);
        ClearScreen();

        cout << *city; //prints city
        cout << "generation: " << generation << endl;
        cout << "humans: " << city->countType(HUMAN) << endl;
        cout << "zombies: " << city->countType(ZOMBIE) << endl;

        /*
        city->move(); //includes all actions
        city->reset(); //resets moved flags
         */

        generation++;//increases generation each
    }//end while
}//end main

