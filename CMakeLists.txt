cmake_minimum_required(VERSION 3.24)
project(EcoSim)

set(CMAKE_CXX_STANDARD 17)

add_executable(EcoSim src/main.cpp inc/City.h inc/GameSpecs.h inc/Human.h inc/Organism.h inc/Zombie.h inc/SimSpecs.h)
