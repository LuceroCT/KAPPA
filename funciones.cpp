//
// Created by mariojacobo2011 on 10/31/19.
//


#include "funciones.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include <random>
#include <algorithm>
#include "casilla.h"
#include "robot.h"
#include "casilla.h"
#include "almacen.h"
#include "producto.h"
#include "funciones.h"

typedef random_device device;
typedef uniform_int_distribution<int> distribution;
device dev;
int randint(int first, int last) {
    distribution dis(first, last);
    return dis(dev);
}
vector<vector< int > > casillatovecc(vector<casilla> sujeto){
    vector< vector< int > > final;
    for (int i=0;i<sujeto.size();i++){
        final.push_back(sujeto[i].getvec());
    }
    return final;
}
void drawlist(vector<vector <int> > matriz, string caracter){
    vector<int> checar;
    for (int i=0;i<42;i++){
        for (int j=0;j<82;j++){
            checar.push_back(j);
            checar.push_back(42-i);
            if (find(matriz.begin(),matriz.end(),checar)!=matriz.end() || i==0 || j==0 || i==41 || j==81){
                cout << caracter << "";
            }
            else{
                cout << "  " << "";
            }
            checar.clear();
        }
        cout << endl;}}
vector<vector<int> > linea(int x1, int y1,int x2, int y2){
    vector< vector<int> > final;
    vector<int> checar;
    int punto = 0;
    int ysup = max(y2,y1);
    int ymin = min(y2,y1);
    int xsup = max(x2,x1);
    int xmin = min(x2,x1);
    if ((x1-x2) != 0){
        //X1 != X2
        double y2m = y2;
        double y1m = y1;
        double x2m = x2;
        double x1m = x1;
        double m= (y2m-y1m)/(x2m-x1m);
        if (m == 0.0){ //LINEA HORIZONTAL
            //Y1 == Y2
            for (int i=xmin;i<=xsup;i++){
                checar.push_back(i);
                checar.push_back(y1);
                final.push_back(checar);
                checar.clear();
            }
        }
        else{
            for (int i=xmin;i<=xsup;i++){
                punto = m*i - m*x1m + y1m; //Mario ¿Para que es esto?
                checar.push_back(i);
                checar.push_back(punto);
                final.push_back(checar);
                checar.clear();
                punto = 0;
            }
        }
    }
    else{
        for (int i=ymin;i<=ysup;i++){
            checar.push_back(x1);
            checar.push_back(i);
            final.push_back(checar);
            checar.clear();
        }
    }
    return final;
}
vector<vector <int> > poligono(int n){
    vector <vector <int> > final;
    int x;
    int y;
    vector< vector<int> > checar;
    vector<int> puntos;
    if (n>=3){
        for (int i=0;i<n;i++){
            cout << "Ingrese x" << i+1 << " ";
            cin >> x;
            cout << "Ingrese y" << i+1 << " ";
            cin >> y;
            puntos.push_back(x);
            puntos.push_back(y);
        }
        for (int i=0;i<n;i++){
            int b = 2*i;
            if (i!=n-1){
                checar = linea(puntos[b], puntos[b+1], puntos[b+2], puntos[b+3]);
                final.insert(final.end(),checar.begin(),checar.end()) //para que es el último parámetro?
                        ;
                checar.clear();
            }
            else{
                checar = linea(puntos[b], puntos[b+1], puntos[0], puntos[1]);
                final.insert(final.end(),checar.begin(),checar.end());
                checar.clear();
            }
        }
        return final;
    }
    else{
        cout << "No se puede dibujar un poligono con menos de tres lados";
        return final;
    }
}

vector < vector< int > > rellenar(vector < vector <int >> matriz){
    vector < vector < int > > final;
    vector<int> prueba1;
    vector<int> prueba2;
    vector<int> checar;
    vector<int> transicion;
    vector<int> retransicion;
    final = matriz;
    for (int i=0;i<matriz.size()-1;i++){
        prueba1 = matriz[i+1];
        prueba2 = matriz[i];
        if (prueba1[1]-prueba2[1]>1){
            transicion.push_back(prueba2[1]+1);
            transicion.push_back(prueba1[1]-1);
            checar = relle(transicion);
            for (int i=0;i<checar.size();i++){
                retransicion.push_back(prueba2[0]);
                retransicion.push_back(checar[i]);
                final.push_back(retransicion);
                retransicion.clear();
            }
            transicion.clear();
        }
        else if (prueba1[1]-prueba2[1]<1){
            transicion.push_back(prueba2[1]-1);
            transicion.push_back(prueba1[1]+1);
            checar = relle(transicion);
            for (int i=0;i<checar.size();i++){
                retransicion.push_back(prueba2[0]);
                retransicion.push_back(checar[i]);
                final.push_back(retransicion);
                retransicion.clear();
            }
            transicion.clear();
        }
    }
    return final;
}
vector<int> relle (vector <int> rel){
    vector<int> final;
    for (int i=0;i<rel.size()-1;i++){
        final.push_back(rel[i]);
        if (rel[i+1]>rel[i]){
            for (int m=rel[i]+1;m<rel[i+1];m++){
                final.push_back(m);
            }
        }
        else if (rel[i+1]-rel[i]<0){
            for (int m=rel[i]-1;m>rel[i+1];m--){
                final.push_back(m);
            }
        }
    }
    final.push_back(rel[rel.size()-1]);
    return final;
}

bool insidepoly(vector< vector < int > > sujeto,vector<int> punto){
    int posx = punto[0];
    int posy = punto[1];
    vector<int> xs;
    vector<int> ysp;
    int maxy;
    int miny;
    for (int i=0;i<sujeto.size();i++){
        xs.push_back(sujeto[i][0]);
    }
    int maxx = *max_element(xs.begin(),xs.end());
    int minn = *min_element(xs.begin(),xs.end());
    if (posx <= maxx && posx >= minn){
        for (int i=0;i<sujeto.size();i++){
            if (sujeto[i][0] == posx){
                ysp.push_back(sujeto[i][1]);
            }
        }
        maxy = *max_element(ysp.begin(),ysp.end());
        miny = *min_element(ysp.begin(),ysp.end());
        if (posy <= maxy && posy >= miny){
            return true;
        }
    }
    else{
        return false;
    }
    return false;
}

vector<vector<int> > llenar(vector<vector<int > > sujeto){
    vector< vector< int > > llenado;
    vector<int> checar;
    for (int i=0;i<42;i++){
        for (int j=0;j<82;j++){
            checar.push_back(j);
            checar.push_back(41-i);
            if (insidepoly(sujeto, checar) || find(sujeto.begin(),sujeto.end(),checar)!=sujeto.end()){
                llenado.push_back(checar);
            }
            checar.clear();
        }
    }
    return llenado;
}

void imprimirmatriz(vector<casilla> sujeto){
    vector<vector < int > > matriz;
    vector< int> transicion;
    for (int i=0;i<sujeto.size();i++){
        if (sujeto[i].escasa() == true){
        }
        else{
            transicion.push_back(sujeto[i].getx());
            transicion.push_back(sujeto[i].gety());
            matriz.push_back(transicion);
            transicion.clear();
        }
    }
    drawlist(matriz,".■");
}
void printmatriz(vector<casilla> sujeto, int dimension1, int dimension2){
    int index = 0;
    vector<vector<int > > prueba = casillatovecc(sujeto);
    vector<int> checar;
    for (int i=0;i<dimension1;i++){
        for (int j=0; j<dimension2;j++){
            checar.push_back(j);
            checar.push_back(dimension1-i);
            auto iter = find(prueba.begin(),prueba.end(),checar);
            if (iter!=prueba.end()){
                auto vi = prueba.begin();
                for (int i=0;i<prueba.size();i++){
                    if (vi==iter){
                        index = i;
                        break;
                    }
                    advance(vi,1);
                }
                if (sujeto[index].escasa()){
                    cout << "aa" << "";
                }
                else {
                    cout << ".■" << "";
                }
            }
            else{
                if (i== 0 || j == 0 || i== dimension1-1 || j==dimension2-1){
                    cout << ".■" << "";
                }
                else{
                    cout << " " << "";
                }
            }
        }
        checar.clear();
    }
    cout << endl;
}
void robotrandom(almacen& newsujeto,int cantidad){
    vector<casilla> sujeto = newsujeto.getmatriz();
    int i = sujeto.size()-1;
    vector<int> naleatorios;
    while (naleatorios.size()!=3){
        int prueba = randint(0,i);
        if (find(naleatorios.begin(),naleatorios.end(),prueba)==naleatorios.end()){
            naleatorios.push_back(prueba);
        }
    }
    for (int j=0;j<naleatorios.size();j++){
        int puesto = naleatorios[j];
        sujeto[puesto].ishome(true);
    }
    newsujeto.actmatriz(sujeto);
}



