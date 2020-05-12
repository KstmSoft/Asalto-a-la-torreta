#ifndef _TABLERO_H_
#define _TABLERO_H_
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include "Personaje.h"
#include "Avatar.h"

using namespace std;

class tablero{
  public:
    tablero();
    ~tablero();
    void leer_partida(string ruta); 
    void leer_archivo(string tablero);
    void mostrar_archivo();
    void menu();
    void set_datos();
    void set_avatares();
    void mod_bonus(int nuevoValor);
    void mover_ejercito();
    void posiciones_iniciales();
    void cambiar_valores();
    void repartir_bonos();
    void cambiar_ejercito();
    void atacar();
    void guardar_partida(string);
    void cargar_datos(string); 

  private:
    bool juego_iniciado;
    char respuesta;
    vector<int> avatares[2];
    int camino[11][10];
    int numero_jugadores[3];
    int valor_jugadores[3];
    int jugador[2];
    int bonus;
    int cant_ejercito;
    int x1,x2,y1,y2;
    int ejercito1[2];
    int ejercito2[2];
    int ejercito;
    int n=1,s=1,e=1,o=1,e2=1,o2=1,optn;
    vector <Personaje*> Ejercito_1;
    vector <Personaje*> Ejercito_2; 
    
  protected:
  //La torreta es protegida.
    int torreta[2];
};

#endif