#include <vector>
#include<iostream>
#include <cmath>


using namespace std;

//¿q opinan de las variables no nativas?

//typedef string producto;
//typedef int cantidad;
//typedef int coordenada;
//typedef float decimal;
//typedef float tipoArea;
//typedef bool boleano;

class producto{
  private:
  string tipo;
  public:
  producto(string tip);
};

class casilla{
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

class almacen{
  private:
  int npuntos;
  vector<casilla> matriz;
  public:
  almacen(int n);
  vector<casilla> getmatriz();
  //actualizar
  void actmatriz(vector<casilla> sujeto);
};

class robot{
  private:
  int posx;
  int posy;
  int longitud;

  public:
  robot(int x, int y);
  void set_posx(int x);
};




//LUCERO!! anda pensando en el algoritmo para hacer que el robot se mueva en x y en y hasta alcanzar el objetiov teniendo en cuenta que la matriz no es cuadrada :D

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