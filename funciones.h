//
// Created by mariojacobo2011 on 10/31/19.
//
#include <vector>
#include <iostream>
#include <string>
#include "almacen.h"
#include "casilla.h"
#include "robot.h"
#include "producto.h"
using namespace std;

#ifndef PROYECTO_POO_FUNCIONES_H
#define PROYECTO_POO_FUNCIONES_H
void imprimircasilla(vector<casilla> sujeto, int dimension1 , int dimension2);
vector<vector< int > > casillatovecc(vector<casilla> sujeto);
void robotrandom(almacen& newsujeto, int cantidad);
void drawlist(vector<vector <int> > matriz, string caracter);
vector<vector< int > > casillatovecc(vector<casilla> sujeto);
void robotrandom(almacen& newsujeto,int cantidad);
bool insidepoly(vector< vector < int > > sujeto,vector<int> punto);
vector<int> relle (vector <int> rel);
vector < vector< int > > rellenar(vector < vector <int >> matriz);
vector<vector <int> > poligono(int n);
vector<vector<int> > linea(int x1, int y1,int x2, int y2);
vector<vector<int> > llenar(vector<vector<int > > sujeto);
void imprimirmatriz(vector<casilla> sujeto);
void printmatriz(vector<casilla> sujeto, int dimension1, int dimension2);
#endif //PROYECTO_POO_FUNCIONES_H
