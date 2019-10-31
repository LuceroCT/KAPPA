//
// Created by mariojacobo2011 on 10/31/19.
//
#include <iostream>
#include "almacen.h"
#include "casilla.h"
#include "funciones.h"
#include <vector>
#include <algorithm>
using namespace std;
almacen::almacen(int n){
    vector< vector< int> > matri;
    vector< vector< int > > matrilleno;
    vector<int> prueba;
    vector < casilla > vectorcasi;
    matri = poligono(n);
    matrilleno = llenar(matri);
    for (int i=0;i<matrilleno.size();i++){
        prueba = matrilleno[i];
        if (find(matri.begin(),matri.end(),prueba)!=matri.end()){
            casilla poner(prueba[0],prueba[1],true);
            vectorcasi.push_back(poner);
        }
        else{
            casilla poner(prueba[0],prueba[1],false);
            vectorcasi.push_back(poner);
        }
    }
    matriz = vectorcasi;
}

void almacen::actmatriz(vector<casilla> sujeto){
    matriz = sujeto;
}

vector<casilla> almacen::getmatriz(){
    return matriz;
}