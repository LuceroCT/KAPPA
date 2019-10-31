//
// Created by mariojacobo2011 on 10/31/19.
//

#ifndef PROYECTO_POO_ALMACEN_H
#define PROYECTO_POO_ALMACEN_H
#include <vector>
#include <iostream>
#include "casilla.h"
using namespace std;

class almacen {
private:
    int npuntos;
    vector<casilla> matriz;
public:
    almacen(int n);
    vector<casilla> getmatriz();
    //actualizar
    void actmatriz(vector<casilla> sujeto);
};


#endif //PROYECTO_POO_ALMACEN_H
