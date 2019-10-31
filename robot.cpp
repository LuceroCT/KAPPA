//
// Created by mariojacobo2011 on 10/31/19.
//

#include "robot.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

robot::robot(int x, int y){
    posx = x;
    posy = y;
    longitud = 2;
}
void robot::set_posx(int x){
    posx = x;
}
void robot::set_posy(int y){
    posy = y;
}
void robot::mover(int x, int y){
    if(posx != x ){
        if (posx < x){
            set_posx(posx++);
        }
        else
            set_posx(posx--);
    }

    if(posx != y ){
        if (posy < y){
            set_posy(posy++);
        }
        else
            set_posx(posx--);
    }
}