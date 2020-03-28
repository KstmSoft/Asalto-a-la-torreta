#include "tablero.h"

tablero::tablero(){
  juegoIniciado = false;
  bonus = 0;
  cantEjercito = 0;
  torreta[0]=4;
}

tablero::~tablero(){}

void tablero::leer_archivo(string tablero){
  ifstream archivo;
  string texto;
  archivo.open("tablero.txt");
  if (archivo.fail()) {
    cout << "¡Error al cargar el tablero!\n";
    exit(1);
  }
  int c = 0;
  while (!archivo.eof()) {
    getline(archivo, texto);
    istringstream f(texto);
    string s;
    int i = 0;
    while (getline(f, s, '\t')) {
      camino[c][i] = stoi(s);
      i++;
    }
    c++;
  }
  archivo.close();
}

void tablero::mostrar_archivo(){
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << camino[i][j] << "   ";
    }
    cout << endl;
  }
}