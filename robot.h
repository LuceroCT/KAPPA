//
// Created by mariojacobo2011 on 10/31/19.
//

#ifndef PROYECTO_POO_ROBOT_H
#define PROYECTO_POO_ROBOT_H


class robot {
private:
  int posx;
  int posy;
  int longitud;
  public:
  robot(int x, int y);
  void set_posx(int x);
  void set_posy(int y);
  void mover(int x,int y);
};


#endif //PROYECTO_POO_ROBOT_H
