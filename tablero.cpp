#include "tablero.h"

tablero::tablero(){
  juegoIniciado = false;
  bonus = 0;
  cantEjercito = 0;
}

tablero::~tablero(){}

void tablero::vida_ejercito(){  
  if(camino[3][4]==2&&arriba==1){
     torreta[0]=torreta[0]-1;
     arriba--;
  }else if(camino[4][3]==2&&izquierda==1){
     torreta[0]=torreta[0]-1;
     izquierda--;
  }else if(camino[5][4]==2&&abajo==1){
     torreta[0]=torreta[0]-1;
     abajo--;
  }else if(camino[4][5]==2&&derecha==1){
     torreta[0]=torreta[0]-1;
     derecha--;
  }  
}

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

void tablero::mod_bonus(int nuevoValor){
  bonus = nuevoValor;
}

void tablero::menu() {
  int opcion;
  do{
    if (!juegoIniciado) {
      
      cout << "Para continuar, seleccione alguna de las siguientes opciones:" << endl;
      cout << "1. Mostrar tablero" << endl;
      cout << "2. Mostrar configuracion" << endl;
      cout << "3. Cargar ultima partida" << endl;
      cout << "0. Salir" << endl;
      cin >> opcion;
      switch (opcion) {
      case 1:
        juegoIniciado = true;
        leer_archivo("tablero.txt");
        mostrar_archivo();
        break;
      case 2:
        cout << "Bonos disponibles: " << bonus << endl;
        cout << "Tropas por ejercito: " << cantEjercito << endl;
        break;
      case 3:
        cout << "Trabajando en ello..." << endl << endl;
        break;

      }
    }else{
      
      cout << "1. Mostrar configuracion" << endl;
      cout << "2. Jugar" << endl;
      cout << "3. Cambiar valores" << endl;
      cout << "0. Salir" << endl;
      cin >> opcion;
      switch (opcion) {
      case 1:
        cout << "Bonos disponibles: " << bonus << endl;
        cout << "Tropas por ejercito: " << cantEjercito << endl;
        break;
        case 2: 

        //system("clear");
        mostrar_archivo();
        //mover_ejercito();
        break;
      case 3:
        cambiarValores();
        break;
        
      }
    }
  }while(opcion!=0);
  cout << "Guardando partida...";
}

void tablero::cambiarValores(){
  int opcionV;
        cout << "¿Que deseas cambiar?" << endl;
        cout << "1. Cantidad Bonus" << endl;
        cout << "2. Numero de avatares" << endl;
        cin >> opcionV;
        switch(opcionV){
        case 1: 
        int nuevoValor;
        cout << "Ingresa nuevo valor: ";
        cin >> nuevoValor;
        mod_bonus(nuevoValor);
        cout << "Bono modificado a: " << nuevoValor << endl << endl;
        break;
        case 2:
        int num;
        cout << "Ingresa nuevo valor: ";
        cin >> num;
        cantEjercito = num;
        cout << "Numero de tropas por ejercito cambiado a: " << cantEjercito << endl << endl;
        break;
        default: cout << "Escoge una opcion correcta." << endl;
  }
}