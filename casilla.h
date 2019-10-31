//
// Created by mariojacobo2011 on 10/31/19.
//

#ifndef PROYECTO_POO_CASILLA_H
#define PROYECTO_POO_CASILLA_H
#include <vector>
#include <iostream>
#include "producto.h"
using namespace std;

class casilla {
private:
    //boleano esborde; //boleano :v?
    //boleano estalleno;
    bool esborde;
    bool eshome;
    //producto tipo_prod;
    //cantidad limite; //creo que no es necesario
    //cantidad prod_actual; //con el vector productos se soluciona
    int posx; //las posiciones siempre van a ser enteras
    int posy;
    vector<producto> productos;

public:
    //-------------------constructores-----------------
    casilla(int x, int y,bool borde);
    //Vacio...q opinan??? tambien creamos como objetos las casillas vacias?;
    //El constructor de la casilla creo que debe solo tener coordendas, osea siempre se va a crear dentro de un iterador, no fuera
    //casilla(int x, int y,producto produ);
    //las casillas empiezan vacias porque se crean en el iterador de la matriz sin las instrucciones del usuario
    //Lleno
    //Para las coordenadas no creo que debamos usar tipos no nativos porque nunca van a cambiar, siempre van a ser enteros
    //CCasilla(producto tipo_prod,cantidad limite, cantidad prod_actual,boleano estado,coordenada posición);

    //----------------------métodos--------------------
    //void vaciar(matriz & matiriz,coordenada x, coordenada y);
    //void llenar(matriz & matiriz,coordenada x, coordenada y);
    //--- setters
    void ishome(bool valor);
    //--- getters
    int getx();
    int gety();
    vector<int> getvec();
    bool comborde();
    bool escasa();
    //actualizar
};


#endif //PROYECTO_POO_CASILLA_H
