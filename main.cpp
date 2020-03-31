#include "tablero.h"
#include <iostream>
using namespace std;

int main() {
  /*
  Menu principal. Aqui se inicia un objeto de la clase tablero. Luego, se inicializan los datos que estan en tablero.txt debajo de la matriz, se inicializan los avatares de los ejercitos y se carga el menu de juego
  */
  tablero hacer;
  hacer.set_datos();
  hacer.set_avatares();
  hacer.menu();
}