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

   void mod_bonus(int nuevoValor);
    
  private:

   // int bonus;
   // int cantEjercito;
};

#endif