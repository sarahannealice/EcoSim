//
// Created by sarah on 18/04/2023.
//
#include <windows.h> //used for colours
#include "../inc/Organism.h"

Organism::Organism() {

}

Organism::Organism(City *city, int x, int y, int type) {

}

Organism::~Organism() {

}

void Organism::setPosition(int x, int y) {

}

void Organism::endTurn() {

}

bool Organism::isTurn() {
    return false;
}

ostream &operator<<(ostream &output, Organism *organism) {

/*
    //checks organism type and prints in corresponding colour
    switch (organism->type) {
        case HUMAN:
            output << " " << Color(HUMANCOLOR) << organism.
            break;

    }
    */
    return output;
}

