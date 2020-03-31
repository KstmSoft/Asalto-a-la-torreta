#include "tablero.h"

tablero::tablero() {
  //Se inicializan las variables necesarias en el codigo
  juego_iniciado = false;
  bonus = 0;
  cant_ejercito = 0;
  torreta[0] = 5;
  torreta[1] = 4;
  ejercito1[1] = 0; //para cambiar cuando se muevan
  ejercito1[0] = 1; //Valor ejercito 1
  ejercito2[1] = 0; //para cambiar cuando se mueven
  ejercito2[0] = 2; //Valor ejercito 2
}

tablero::~tablero() {} //Destructor

void tablero::leer_archivo(string tablero) {
  //Aqui leemos el archivo tablero.txt, unicamente se lee la parte de la matriz. 
  ifstream archivo;
  string texto;
  archivo.open(tablero.c_str());
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

void tablero::set_datos() {
  //En esta parte, se lee lo que esta debajo de la matriz. Los bonus y la cantidad del ejercito
  ifstream archivo("tablero.txt");
  int x = 0, aux;
  string auxiliar;
  while (archivo >> auxiliar) {
    stringstream aux(auxiliar);
    x++;
    if (x == 101) {
      aux >> bonus;
    }
    if (x == 102) {
      aux >> cant_ejercito;
    }
  }
}

void tablero::set_avatares() {
  /*
    La linea 1 de "avatares.txt" equivale a los avatares pertenecientes
    al ejercito 1.
    La linea 2 de "avatares.txt" equivale a los avatares pertenecientes
    al ejercito 2.
    1 representa luchador.
    2 representa tirador.
    3 representa mago.
    se crea variable "avatares" que es un array de vectores.
    para acceder a los avatares del ejercito 1 se emplea:
    avatares[0], para acceder a los avatares del ejercito 2
    se empleta avatares[1], la variable avatares devolverá un vector.
  */
  ifstream archivo("avatares.txt");
  int index = 0;
  for (string linea; getline(archivo, linea);) {
    stringstream ss(linea);
    string segment;
    while (getline(ss, segment, ' ')) {
      avatares[index].push_back(stoi(segment.c_str()));
    }
    index++;
  }
  /*
    Segun el pdf la vida del ejercito es la vida
    de cada avatar sumada, entonces, teniendo en cuenta
    eso se suma la vida teniendo en cuenta el tipo de
    avatar.  
  */
  vector < int > avatar_ej1 = avatares[0];
  vector < int > avatar_ej2 = avatares[1];
  /*Ejercito 1*/
  for (int i = 0; i < avatar_ej1.size(); i++) {
    int vida_extra;
    if (avatar_ej1[i] == 1) { //Luchador 4 de vida
      vida_extra = 4;
    } else if (avatar_ej1[i] == 2) { //Tirador 3 de vida
      vida_extra = 3;
    } else if (avatar_ej1[i] == 3) { //Mago 5 de vida
      vida_extra = 5;
    }
    ejercito1[1] = ejercito1[1] + vida_extra;
  }
  /*Ejercito 2*/
  for (int i = 0; i < avatar_ej2.size(); i++) {
    int vida_extra;
    if (avatar_ej2[i] == 1) { //Luchador 4 de vida
      vida_extra = 4;
    } else if (avatar_ej2[i] == 2) { //Tirador 3 de vida
      vida_extra = 3;
    } else if (avatar_ej2[i] == 3) { //Mago 5 de vida
      vida_extra = 5;
    }
    ejercito2[1] = ejercito2[1] + vida_extra;
  }
}

void tablero::mostrar_archivo() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << camino[i][j] << "   ";
    }
    cout << endl;
  }
}

void tablero::guardar_partida() {
  //Guardamos la partida, pero esto va para la segunda entrega, asi que no es muy importante
  ofstream archive;
  archive.open("partida"".txt", ios::out);

  if (archive.fail()) {
    cout << "No se pudo abrir el archivo.";
    exit(1);
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      archive << camino[i][j] << " ";
    }
    archive << endl;
  }
 /* archive<<bonus<<endl<<torreta[1]<<endl<<ejercito1[1]<<endl;
  archive<<ejercito2[1];
  */
  archive.close();
}

void tablero::cambiar_ejercito(){
  //Esto es para la opcion donde se cambia el ejercito dentro del juego
  cout << "Elija una opción:\n 1: Mover Ejercito 1\n 2: Mover Ejercito 2\n 3: Salir\n";
  cin >> ejercito;
  system("clear");
}

void tablero::atacar() {
  /*
    Esta funcion se encarga de realizar ataques al ejercito contrario
    Para atacar el ejercito contrario debe estar cerca al ejercito jugador (esto desbloquea todos los avatares)
    Al estar lejos, solo podrá usar arqueros.

    Al atacar el ejercito enemigo, deberá seleccionar a que avatar desea ejecutar, al ejecutarlo, la vida
    del ejercito disminuirá en funcion a la vida del avatar.
  */
  system("clear");
  int respuesta;
  cout << "Puedes usar los siguientes avatares: " << endl;
  vector < int > avatar = (ejercito == ejercito1[0] ? avatares[0] : avatares[1]);//Avatares del ejercito jugador
  vector < int > avatar_disponibles;

  //Esta condición detecta si el ejercito esta cerca del otro.
  if (!(camino[ejercito == ejercito1[0] ? x2 - 1 : x1 - 1][ejercito == ejercito1[0] ? y2 : y1] == ejercito1[0] || camino[ejercito == ejercito1[0] ? x2 : x1][ejercito == ejercito1[0] ? y2 + 1 : y1 + 1] == ejercito1[0] || camino[ejercito == ejercito1[0] ? x2 + 1 : x1 + 1][ejercito == ejercito1[0] ? y2 : y1] == ejercito1[0] || camino[ejercito == ejercito1[0] ? x2 : x1][ejercito == ejercito1[0] ? y2 - 1 : y1 - 1] == ejercito1[0])) {
    for (int i = 0; i < avatar.size(); i++) if (avatar[i] != 1 && avatar[i] != 3) avatar_disponibles.push_back(avatar[i]);
  } else {
    avatar_disponibles = avatar;
  }

  for (int i = 0; i < avatar_disponibles.size(); i++) {
    cout << i << ". ";
    if (avatar_disponibles[i] == 1) {
      cout << "Luchador (4)";
    } else if (avatar_disponibles[i] == 2) {
      cout << "Tirador (3)";
    } else if (avatar_disponibles[i] == 3) {
      cout << "Mago (5)";
    }
    cout << endl;
  }

  cin >> respuesta;
  //Por ahora no afecta a el juego que avatar seleccione para atacar.

  cout << "¿A qué avatar enemigo desea atacar?: " << endl;
  vector < int > enemigo = (ejercito == ejercito1[0] ? avatares[1] : avatares[0]);//Avatares enemigos
  for (int i = 0; i < enemigo.size(); i++) {
    cout << i << ". ";
    if (enemigo[i] == 1) {
      cout << "Luchador (4)";
    } else if (enemigo[i] == 2) {
      cout << "Tirador (3)";
    } else if (enemigo[i] == 3) {
      cout << "Mago (5)";
    }
    cout << endl;
  }

  cin >> respuesta;

  system("clear");
  if (enemigo[respuesta] == 1) {
    cout << "Mataste un luchador! se restará (4) de vida al equipo contrario.";
    (ejercito == ejercito1[0] ? ejercito2[1] = ejercito2[1] - 4 : ejercito1[1] = ejercito1[1] - 4);
  } else if (enemigo[respuesta] == 2) {
    cout << "Mataste un tirador! se restará (3) de vida al equipo contrario.";
    (ejercito == ejercito1[0] ? ejercito2[1] = ejercito2[1] - 3 : ejercito1[1] = ejercito1[1] - 3);
  } else if (enemigo[respuesta] == 3) {
    cout << "Mataste un luchador! se restará (5) de vida al equipo contrario.";
    (ejercito == ejercito1[0] ? ejercito2[1] = ejercito2[1] - 5 : ejercito1[1] = ejercito1[1] - 5);
  }
  (ejercito == ejercito1[0] ? avatares[1] : avatares[0]).erase((ejercito == ejercito1[0] ? avatares[1] : avatares[0]).begin() + respuesta);
  cout << endl << endl;
  cout << "Presiona cualquier tecla para continuar..." << endl;
  cin.ignore();
  cin.get();
  system("clear");
}

void tablero::posiciones_iniciales() {
  //Se cargan las posiciones iniciales del juego.
  x1 = 4, x2 = 4;
  y1 = 0, y2 = 9;
  camino[x1][y1] = ejercito1[0]; //Posicion inicial del ejército 1
  camino[x2][y2] = ejercito2[0]; //Posicion inicial del ejército 2
  camino[4][4] = torreta[0]; //Posicion inicial de la torreta
}

void tablero::mover_ejercito() {
  //Con este metodo, el usuario va poder mover su ejercito, y de paso tambien se verifica los estados del juego.
  cout << "¿Qué ejercito desea mover: 1 o 2?\n";
  cin >> ejercito;
  system("clear");
  do {
    do {
      if (torreta[1] == 0) {
        cout << "La torreta ha sido destruida. Por favor inicie otra partida\n";
      } else {
        cout << "Vida de la Torreta: " << torreta[1] << endl;
      }
      if (ejercito1[1] == 0) {
        cout << "El ejército 1 ha sido destruido. Por favor inicie otra partida\n";
      } else {
        cout << "Vida ejercito 1: " << ejercito1[1] << endl;
      }
      if (ejercito2[1] == 0) {
        cout << "El ejército 2 ha sido destruido. Por favor inicie otra partida\n";
      } else {
        cout << "Vida ejercito 2: " << ejercito2[1] << endl;
      }
      mostrar_archivo();
      cout << "Para desplazarse use la letra: \n w: Arriba\n d: Derecha \n a: Izquierda\n s: Abajo \n f: Atacar\n e: Cambiar Ejército o Salir\n";
      cin >> respuesta;
      respuesta = tolower(respuesta);
      if (!(ejercito1[1] == 0 || ejercito2[1] == 0 || torreta[1] == 0)) {
        if (ejercito == ejercito1[0]) {
          switch (respuesta) { //Movimientos ejercito 1
            case 'w': //Arriba
              if (!(camino[x1 - 1][y1] == torreta[0] || (x1 - 1) < 0 || camino[x1 - 1][y1] == ejercito2[0])) {
                camino[x1][y1] = 0;
                x1--;
                if (camino[x1][y1] == 4) ejercito1[1] = ejercito1[1] + 1;
                camino[x1][y1] = ejercito1[0];
              }
              break;
            case 'd': //Derecha
              if (!(camino[x1][y1 + 1] == torreta[0] || (y1 + 1) > 9 || camino[x1][y1 + 1] == ejercito2[0])) {
                camino[x1][y1] = 0;
                y1++;
                if (camino[x1][y1] == 4) ejercito1[1] = ejercito1[1] + 1;
                camino[x1][y1] = ejercito1[0];
              }
              break;
            case 'a': //Izquierda
              if (!(camino[x1][y1 - 1] == torreta[0] || (y1 - 1) < 0 || camino[x1][y1 - 1] == ejercito2[0])) {
                camino[x1][y1] = 0;
                y1--;
                if (camino[x1][y1] == 4) ejercito1[1] = ejercito1[1] + 1;
                camino[x1][y1] = ejercito1[0];
              }
              break;
            case 's': //Abajo
              if (!(camino[x1 + 1][y1] == torreta[0] || (x1 + 1) > 9 || camino[x1 + 1][y1] == ejercito2[0])) {
                camino[x1][y1] = 0;
                x1++;
                if (camino[x1][y1] == 4) ejercito1[1] = ejercito1[1] + 1;
                camino[x1][y1] = ejercito1[0];
              }
              break;
          }
        } else if (ejercito == ejercito2[0]){
          switch (respuesta) { //Movimientos ejercito 2
            case 'w': //Arriba
              if (!(camino[x2 - 1][y2] == torreta[0] || (x2 - 1) < 0 || camino[x2 - 1][y2] == ejercito1[0])) {
                camino[x2][y2] = 0;
                x2--;
                if (camino[x2][y2] == 4) ejercito2[1] = ejercito2[1] + 1;
                camino[x2][y2] = ejercito2[0];
              }
              break;
            case 'd': //Derecha
              if (!(camino[x2][y2 + 1] == torreta[0] || (y2 + 1) > 9 || camino[x2][y2 + 1] == ejercito1[0])) {
                camino[x2][y2] = 0;
                y2++;
                if (camino[x2][y2] == 4) ejercito2[1] = ejercito2[1] + 1;
                camino[x2][y2] = ejercito2[0];
              }
              break;
            case 'a': //Izquierda
              if (!(camino[x2][y2 - 1] == torreta[0] || (y2 - 1) < 0 || camino[x2][y2 - 1] == ejercito1[0])) {
                camino[x2][y2] = 0;
                y2--;
                if (camino[x2][y2] == 4) ejercito2[1] = ejercito2[1] + 1;
                camino[x2][y2] = ejercito2[0];
              }
              break;
            case 's': //Abajo
              if (!(camino[x2 + 1][y2] == torreta[0] || (x2 + 1) > 9 || camino[x2 + 1][y2] == ejercito1[0])) {
                camino[x2][y2] = 0;
                x2++;
                if (camino[x2][y2] == 4) ejercito2[1] = ejercito2[1] + 1;
                camino[x2][y2] = ejercito2[0];
              }
              break;
          };
        }
      }
      system("clear");
    } while (respuesta != 'e' && respuesta != 'f');
    switch(respuesta){
      case 'e':
        cambiar_ejercito();
        break;
      case 'f':
        atacar();
        break;
    }
  } while (ejercito != 3);
}

void tablero::repartir_bonos() {
  //Se reparten los bonos por el mapa
  int x, a, b;
  srand(time(NULL));
  while (x < bonus) {
    a = rand() % 10;
    b = rand() % 10;
    if (camino[a][b] == 0) {
      camino[a][b] = 4;
      x++;
    }
  }
}

void tablero::mod_bonus(int nuevoValor) {
  //Metodo para cambiar de valor el bonus
  bonus = nuevoValor;
}

void tablero::menu() {
  int opcion;
  do {
    if (!juego_iniciado) {
      //Pantalla de bienvenida, para visualizarla correctamente debemos expandir la ventana de comandos al maximo:
      cout << "   ▄▄▄· .▄▄ ·  ▄▄▄· ▄▄▌ ▄▄▄▄▄           ▄▄▄·     ▄▄▌   ▄▄▄·     ▄▄▄▄▄      ▄▄▄  ▄▄▄  ▄▄▄ .▄▄▄▄▄ ▄▄▄· " << endl;
      cout << "  ▐█ ▀█ ▐█ ▀. ▐█ ▀█ ██• •██  ▪         ▐█ ▀█     ██•  ▐█ ▀█     •██  ▪     ▀▄ █·▀▄ █·▀▄.▀·•██  ▐█ ▀█ " << endl;
      cout << "  ▄█▀▀█ ▄▀▀▀█▄▄█▀▀█ ██▪  ▐█.▪ ▄█▀▄     ▄█▀▀█     ██▪  ▄█▀▀█      ▐█.▪ ▄█▀▄ ▐▀▀▄ ▐▀▀▄ ▐▀▀▪▄ ▐█.▪▄█▀▀█ " << endl;
      cout << "  ▐█ ▪▐▌▐█▄▪▐█▐█ ▪▐▌▐█▌▐▌▐█▌·▐█▌.▐▌    ▐█ ▪▐▌    ▐█▌▐▌▐█ ▪▐▌     ▐█▌·▐█▌.▐▌▐█•█▌▐█•█▌▐█▄▄▌ ▐█▌·▐█ ▪▐▌" << endl;
      cout << "   ▀  ▀  ▀▀▀▀  ▀  ▀ .▀▀▀ ▀▀▀  ▀█▄▀▪     ▀  ▀     .▀▀▀  ▀  ▀      ▀▀▀  ▀█▄▀▪.▀  ▀.▀  ▀ ▀▀▀  ▀▀▀  ▀  ▀ " << endl;
      cout << "Para continuar, seleccione alguna de las siguientes opciones:" << endl;
      cout << "1. Mostrar tablero" << endl;
      cout << "2. Mostrar configuracion" << endl;
      cout << "3. Cargar ultima partida" << endl;
      cout << "0. Salir" << endl;
      cin >> opcion;

      switch (opcion) {
      case 1:
        juego_iniciado = true;
        leer_archivo("tablero.txt");
        posiciones_iniciales();
        system("clear");
        repartir_bonos();
        mostrar_archivo();
        break;
      case 2:
        system("clear");
        cout << "Bonos disponibles: " << bonus << endl;
        cout << "Tropas por ejercito: " << cant_ejercito << endl;
        break;
      case 3:
        system("clear");
        
        leer_archivo("partida.txt");
        mostrar_archivo();
        //cout << "Trabajando en ello..." << endl << endl;
        break;
      }
    } else {
      cout << "1. Mostrar configuracion" << endl;
      cout << "2. Jugar" << endl;
      cout << "3. Cambiar valores" << endl;
      cout << "0. Salir" << endl;
      cin >> opcion;
      switch (opcion) {
      case 1:
        system("clear");
        cout << "Bonos disponibles: " << bonus << endl;
        cout << "Tropas por ejercito: " << cant_ejercito << endl;
        break;
      case 2:
        system("clear");
        mostrar_archivo();
        mover_ejercito();
        break;
      case 3:
        system("clear");
        cambiar_valores();
        break;
      }
    }
  } while (opcion != 0);
  guardar_partida();
  cout << "Guardando partida...\n";
}

void tablero::cambiar_valores() {
  //Metodo para cambiar los valores, de acuerdo a como lo necesite el usuario
  int opcionV;
  cout << "¿Que deseas cambiar?" << endl;
  cout << "1. Cantidad Bonus" << endl;
  cout << "2. Numero de avatares" << endl;
  cin >> opcionV;
  switch (opcionV) {
  case 1:
    system("clear");
    int nuevoValor;
    cout << "Ingresa nuevo valor: ";
    cin >> nuevoValor;
    mod_bonus(nuevoValor);
    cout << "Bono modificado a: " << nuevoValor << endl << endl;
    break;
  case 2:
    system("clear");
    int num;
    cout << "Ingresa nuevo valor: ";
    cin >> num;
    cant_ejercito = num;
    cout << "Numero de tropas por ejercito cambiado a: " << cant_ejercito << endl << endl;
    break;
  default:
    cout << "Escoge una opcion correcta." << endl;
  }
}