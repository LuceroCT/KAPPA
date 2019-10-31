#include <iostream>
#include "almacen.h"
#include "robot.h"
#include "almacen.h"
#include "casilla.h"
#include "producto.h"
#include <algorithm>
#include "funciones.h"
#include <vector>
using namespace std;

int main() {
    vector<robot> robots;
    int n;
    int nrobots;
    int roboeleccion;
    cout << "Para disenar su almacen, inserte el numero de puntos" << endl;
    cin >> n;
    almacen fin(n);
    cout << "El diseno de su almacen es el siguiente:" << endl;
    imprimirmatriz(fin.getmatriz());
    cout << "Cuantos robots desea en el almacen (de 1 a 3)" << endl;
    cin >> nrobots;
    cout << "Desea que la ubicacion de los robots se de forma aleatoria(1) o manual(2)" << endl;
    cin >> roboeleccion;
    if (roboeleccion == 1){
        robotrandom(fin, nrobots);
    }
    else if (roboeleccion == 2){

    }
    cout << "Los robots estan dispuestos de la siguiente forma: " << endl;
    imprimirmatriz(fin.getmatriz());
}