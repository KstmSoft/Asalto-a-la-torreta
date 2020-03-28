#ifndef  _TABLERO_H_
#define _TABLERO_H_
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

class tablero{
  public:
    tablero();
    ~tablero();

    void leer_archivo(string );
    void mostrar_archivo();
    void menu();
    void cambiarValores();
    void mod_bonus(int nuevoValor);
    void mover_ejercito();
    void posiciones_iniciales();
    void set_datos();
    void repartir_bonos();
    void vida_ejercito();
    
  private:
   bool juegoIniciado;
   int camino[10][10];
   int bonus;
   int cantEjercito;
   int arriba=1,abajo=1,derecha=1,izquierda=1;
   int x1,x2,y1,y2;
   char respuesta;
   
};

#endif