//
// Created by mariojacobo2011 on 10/31/19.
//

#include "casilla.h"
#include <vector>
#include <iostream>
#include "producto.h"
using namespace std;
casilla::casilla(int x, int y, bool borde){
    posx = x;
    posy = y;
    esborde = borde;
    eshome = false;
}
int casilla::getx(){
    return posx;
}
int casilla::gety(){
    return posy;
}

bool casilla::comborde(){
    return esborde;
}
bool casilla::escasa(){
    return eshome;
}
void casilla::ishome(bool valor){
    eshome  = valor;
}
vector<int> casilla::getvec(){
    vector<int> final;
    final.push_back(posx);
    final.push_back(posy);
    return final;
}