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
    
  private:
   bool juegoIniciado;
   int camino[10][10];
   int bonus;
   int cantEjercito;
};

#endif