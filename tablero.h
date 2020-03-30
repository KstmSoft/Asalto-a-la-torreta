#ifndef _TABLERO_H_
#define _TABLERO_H_
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <vector>

using namespace std;

class tablero{
  public:
    tablero();
    ~tablero();
    void leer_partida(string ruta); 
    void guardar_partida(); 
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

  private:
    bool juego_iniciado;
    char respuesta;
    vector<int> avatares[2];
    int camino[10][10];
    int numero_jugadores[3];
    int valor_jugadores[3];
    int jugador[2];
    int bonus;
    int cant_ejercito;
    int x1,x2,y1,y2;
    int ejercito1[2];
    int ejercito2[2];
    int ejercito;
    
  protected:
    int torreta[2];
};

#endif