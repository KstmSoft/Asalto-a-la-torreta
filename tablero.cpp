#include "tablero.h"

tablero::tablero() {
  //Se inicializan las variables necesarias en el codigo
  juego_iniciado = false;
  bonus = 0;
  cant_ejercito = 0;
  torreta[0] = 5;  
  ejercito1[0] = 1; //Valor ejercito 1
  ejercito2[0] = 2; //Valor ejercito 2
  Ejercito_1.resize(4);
  Ejercito_2.resize(4);
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


void tablero::cambiar_ejercito(){
  //Esto es para la opcion donde se cambia el ejercito dentro del juego
  cout << "Elija una opción:\n 1: Mover Ejercito 1\n 2: Mover Ejercito 2\n 3: Salir\n";
  cin >> ejercito;
  system("clear");
}

void tablero::mostrar_archivo() {
  cout << "    ";
  for(int j = 0;j < 10;j++){      
      cout << j << "   ";
          
    }

    cout << endl << endl;
    

  for(int i = 0;i < 10;i++){
    cout << i << "   ";    
    for(int j = 0;j < 10;j++){      
      cout << camino[i][j] << "   ";      
    }
    cout << endl;

  }
}



void tablero::posiciones_iniciales(){
  cout<<"Organizar Tamaño de la Torre:\n";
  cout<<"1: Un Espacio.\n";
  cout<<"2: Dos Espacios.\n";
  cin>>optn;
  //if(camino)
  switch (optn){
    case 1:
    camino[4][4]=torreta[0];
    torreta[1] = 4;
    break;
    case 2:
    camino[4][4]=torreta[0];
    camino[5][4]=torreta[0]; 
    torreta[1] = 6;   
    break;    
  }
  ejercito1[1] = 2;
  ejercito2[1] = 2;
  x1=4,x2=4;
  y1=0,y2=9;
  camino[x1][y1]=ejercito1[0];//posicion inicial del ejército 1
  camino[x2][y2]=ejercito2[0];//posicion inicial del ejército 2
  //camino[4][4]=torreta[0];//posicion inicial de la torreta

/*
  //AVATARES EJERCITO 1

   //Luchadores
    Ejercito_1[0] = new Avatar(4 ,0.6, 0.7, "Luchador");//primer parámetro es la Vida, segundo Mana, tercero Daño y cuarto Nombre
    Ejercito_1[1] = new Avatar(4, 0.6, 0.7, "Luchador");
   //Tiradores
    Ejercito_1[2] = new Avatar(3, 0.3, 1, "Tirador");
    Ejercito_1[3] = new Avatar(3 , 0.3, 1,"Tirador");
   //Magos 
    Ejercito_1[4] = new Avatar(5 , 1, 0.2, "Mago");

*/

  //AVATARES EJERCITO 2

  //Luchadores
    Ejercito_2[0] = new Avatar(4, 0.6, 0.7, "Luchador");
    Ejercito_2[1] = new Avatar(4, 0.6, 0.7, "Luchador");
   //Tiradores
    Ejercito_2[2] = new Avatar(3, 0.3 , 1, "Tirador");
    Ejercito_2[3] = new Avatar(3, 0.3, 1, "Tirador");
   //Magos 
    Ejercito_2[4] = new Avatar(5 , 1, 0.2, "Mago");

}

//Método que cambia las Posiciones de los ejercitos después de cada enfrentamiento

void tablero::CambioPosiciones(){

  //EJERCITO 1

     //Izquierda       

    if (!(camino[x1][y1 - 1] == torreta[0] || (y1 - 1) < 0 || camino[x1][y1 - 1] == ejercito2[0]))
    {
       camino[x1][y1] = 0;
       y1--;
      // if (camino[x1][y1] == 4) 
       //RestaurarVida(1);
       camino[x1][y1] = ejercito1[0];
    }   
     
     //Arriba

     else if (!(camino[x1 - 1][y1] == torreta[0] || (x1 - 1) < 0 || camino[x1 - 1][y1] == ejercito2[0])) {
         camino[x1][y1] = 0;
         x1--;
         //if (camino[x1][y1] == 4) 
         //RestaurarVida(1);
         camino[x1][y1] = ejercito1[0];

      }
      //Derecha
      
        else if (!(camino[x1][y1 + 1] == torreta[0] || (y1 + 1) > 9 || camino[x1][y1 + 1] == ejercito2[0]))
          {

             camino[x1][y1] = 0;
             y1++;
             //if (camino[x1][y1] == 4) 
             //RestaurarVida(1);
             camino[x1][y1] = ejercito1[0];
          }

          //Abajo

            else if (!(camino[x1 + 1][y1] == torreta[0] || (x1 + 1) > 9 || camino[x1 + 1][y1] == ejercito2[0]))
             {
                camino[x1][y1] = 0;
                x1++;
                //if (camino[x1][y1] == 4) 
                //RestaurarVida(1);
                camino[x1][y1] = ejercito1[0];
             }
              
        //EJERCITO 2

         //Derecha

      if (!(camino[x2][y2 + 1] == torreta[0] || (y2 + 1) > 9 || camino[x2][y2 + 1] == ejercito1[0]))
      {
        camino[x2][y2] = 0;
        y2++;
        //if (camino[x2][y2] == 4) 
        //RestaurarVida(2) ;
        camino[x2][y2] = ejercito2[0];
      }
        
       //Arriba

        else if (!(camino[x2 - 1][y2] == torreta[0] || (x2 - 1) < 0 || camino[x2 - 1][y2] == ejercito1[0]))
         {
            camino[x2][y2] = 0;
            x2--;
            //if (camino[x2][y2] == 4) 
            //RestaurarVida(2);
            camino[x2][y2] = ejercito2[0];
         }     

         //Abajo

        else if (!(camino[x2 + 1][y2] == torreta[0] || (x2 + 1) > 9 || camino[x2 + 1][y2] == ejercito1[0]))
          {
             camino[x2][y2] = 0;
             x2++;
             //if (camino[x2][y2] == 4)
             //RestaurarVida(2);
             camino[x2][y2] = ejercito2[0];  
          }       

          //Izquierda

           else if (camino[x2][y2 - 1] == 4||!(camino[x2][y2 - 1] == torreta[0] || (y2 - 1) < 0 || camino[x2][y2 - 1] == ejercito1[0]))
            {
              camino[x2][y2] = 0;
               y2--;
               //if (camino[x2][y2] == 4) 
               //RestaurarVida(2) ;
               camino[x2][y2] = ejercito2[0];
           }
              
               
              
}

//Método que identifica si los ejercitos estan cerca del enemigo

int tablero::PosicionAtaque(){
  
  //ATAQUE ENTRE EJERCITOS

   //arriba
     if(camino[x1 - 1][y1] == ejercito2[0] || camino[x2 -1][y2] == ejercito1[0] ){     
       return 0;

    }//derecha
    else if(camino[x1][y1 + 1] == ejercito2[0] || camino[x2][y2 + 1] == ejercito1[0]){
       return 0;

    }//abajo
    else if(camino[x1 + 1][y1] == ejercito2[0] || camino[x2 + 1][y2] == ejercito1[0]){
       return 0;

    }//izquierda
    else if(camino[x1][y1 - 1] == ejercito2[0] || camino[x2][y2 - 1] == ejercito1[0]){
       return 0;
    } //Funcion que verifica si la Torreta está cerca
     //arriba
    else if(camino[x2 -1][y2] == torreta[0] ){     
       return 1;

    }//derecha
    else if(camino[x2][y2 + 1] == torreta[0]){
       return 1;

    }//abajo
    else if(camino[x2 + 1][y2] == torreta[0]){
       return 1;

    }//izquierda
    else if(camino[x2][y2 - 1] == torreta[0]){
       return 1;
    }else 

     return 2;

}

//Batalla entre los ejercitos
void tablero::Batalla(int N){

   //Avatares vivos
     int Vivos, Vivos2;
     int s,s2;
  
   // Auxiliares que suman el Poder y Mana de los ejercitos
     int aux = 0,aux2 = 0; 

   // Vector que huardará al Avatar con menor Vida
     vector <Personaje*> H;     
     H.resize(2);

   //Posiciones de los Avatares con menor Vida
     int p = 0,p2 = 0; 
     int auxx ,auxx2;

    //Funcion que hace el ataque de acuerdo al ejercito que está atacando    
     switch(N){
       //Ataca el ejercito 1
       case 1:

          //iterador que va a buscar al menor de los atacantes
          
          for (int i = 0; i < Ejercito_1.size(); i++){
            Vivos = 0;
            
            //suma los poderes del ejercito 1
             if(Ejercito_1[i] -> Vida != 0){

                aux +=  Ejercito_1[i] -> Poder; 
                
             }
            //Busca al Avatar con menor Vida del ejercito 1
             if(auxx > Ejercito_1[i] -> Vida){

                if( Ejercito_1[i] -> Vida != 0){
  
                 auxx = Ejercito_1[i] -> Vida;
                 p = i;
  
                } 
            }

            Vivos = 0;

            for (int j = 0; j < Ejercito_1.size(); j++){
               if(Ejercito_1[j] -> Vida != 0){
                   Vivos+=1;
                   s = j;
                 }
             }
            

          }
          //Iterador que va a buscar al menor de los atacados          
          
          for (int i = 0; i < Ejercito_2.size(); i++){     
                      
             //Suma de los Mana del ejercito Atacado
             if(Ejercito_2[i] -> Vida != 0){

                aux2 +=  Ejercito_2[i] -> Mana;           

             }
              
             if(auxx2 > Ejercito_2[i] -> Vida){
               if( Ejercito_2[i] -> Vida != 0){
                auxx2 = Ejercito_2[i] -> Vida;
                 p2 = i;
               }
                
             }                  
            
            Vivos2 = 0;

            for (int j = 0; j < Ejercito_2.size(); j++){
               if(Ejercito_2[j] -> Vida != 0){
                    Vivos2+=1;
                    s2 = j;
                 }
             }  

          }        
	 
           //Funcion que ataca al último Avatar vivo
          if (Vivos == 1){
            p = s;
          }
          
          if (Vivos2 == 1){
            p2 = s;
          }
          

          //Funcion que ataca de acuerdo a la suma de los Poderes y Manas del ejercito
          if(aux > aux2){
            // Si el Poder es mayor que em Mana
            Ejercito_1[0] -> Atacar(Ejercito_2[p2]);

          }else if(aux2 > aux){

             // Si el Mana es mayor que em Poder
             Ejercito_2[0] -> Atacar(Ejercito_1[p]);

          }else if(aux == aux2){

            //si Mana y Poder son iguales
            Ejercito_1[0] -> Empate(Ejercito_2[p2]);
            Ejercito_2[0] -> Empate(Ejercito_1[p]);

          }
          

          
       break;

       case 2:
          
          
         

          for (int i = 0; i < Ejercito_2.size(); i++){
             //Suma de los Poderes del ejercito Atacante
             if(Ejercito_2[i] -> Vida != 0){

                aux +=  Ejercito_2[i] -> Poder;
                Vivos2 +=1;

             }

             if(auxx > Ejercito_2[i] -> Vida){
               if( Ejercito_2[i] -> Vida != 0){
                auxx = Ejercito_2[i] -> Vida;
                 p = i;
               } 
             }

             Vivos = 0;

            for (int j = 0; j < Ejercito_2.size(); j++){
               if(Ejercito_2[j] -> Vida != 0){
                   Vivos+=1;
                   s = j;
                 }
             }
          } 

          
          
          for (int i = 0; i < Ejercito_1.size(); i++){
            //suma los Mana del ejercito atacado
             if(Ejercito_1[i] -> Vida != 0){

                aux2 +=  Ejercito_1[i] -> Mana; 

             }
            //Busca al Avatar con menor Vida del ejercito 1
             if(auxx2 > Ejercito_1[i] -> Vida){

              if( Ejercito_1[i] -> Vida != 0){

               auxx2 = Ejercito_1[i] -> Vida;
               p2 = i;

              } 
            }

            Vivos2 = 0;

            for (int j = 0; j < Ejercito_1.size(); j++){
               if(Ejercito_1[j] -> Vida != 0){
                   Vivos2+=1;
                   s2 = j;
                 }
             }

          } 

            //Funcion que ataca al último Avatar vivo
          if (Vivos == 1){
            p = s;
          }
          
          if (Vivos2 == 1){
            p2 = s;
          }

          //Funcion que ataca de acuerdo a la suma de los Poderes y Manas del ejercito
          if(aux > aux2){
            // Si el Poder es mayor que em Mana
            Ejercito_2[0] -> Atacar(Ejercito_1[p2]);

          }else if(aux2 > aux){

             // Si el Mana es mayor que em Poder
             Ejercito_1[0] -> Atacar(Ejercito_2[p]);

          }else if(aux == aux2){

            //si Mana y Poder son iguales
            Ejercito_1[0] -> Empate(Ejercito_2[p2]);
            Ejercito_2[0] -> Empate(Ejercito_1[p]);
               
          } 
         
       break;

     } 

     CambioPosiciones();      

}

//Método para configurar los Avatares del ejerctito

void tablero::Avatares(){
    
    cout<< "Tiene " << (cant_ejercito / 2) << " posibles Avatar para escoger.\n";
    string Opcion;

    
    for (int i = 0;i < (cant_ejercito / 2); i++ ){

      
      cout << "Para elegir sus Avatar seleccione una de las siguintes opciones y luego presione enter:\n 1. Mago\n 2. Tirador\n 3. Luchador\n\n";

      cout << "Avatar [" << i + 1 << "]\n";
      
      int x = 0;
      cin >> x;
      cout << endl;

      switch(x){
       //Mago
        case 1:
        Ejercito_1[i] = new Avatar(5 , 1, 0.2, "Mago");
        break;
        //Tirador
        case 2:
        Ejercito_1[i] = new Avatar(3 , 0.3, 1,"Tirador");
        break;
        //Luchador
        case 3:
        Ejercito_1[i] = new Avatar(4, 0.6, 0.7, "Luchador");
        
        break;
      }
      system("clear");
    }
    
}


void tablero::VidaTorreta(){ 
   
  if(camino[3][4]==ejercito2[0]&&n==1){//arriba
     torreta[1]=torreta[1]-1;
     n--;
  }else if(camino[4][3]==2&&e==1){//derecha
     torreta[1]=torreta[1]-1;
     e--;
  }else if(camino[5][4]==2&&s==1){//abajo
     torreta[1]=torreta[1]-1;
     s--;
  }else if(camino[4][5]==2&&o==1){//izquierda
     torreta[1]=torreta[1]-1;
     o--;
  }else if(optn==2){
       if(camino[5][5]==2&&e2==1){
           torreta[1]=torreta[1]-1;
           e2--;
       }else if(camino[5][3]==2&&o2==1){
          torreta[1]=torreta[1]-1;
          o2--;
       }else if(camino[6][4]==2&&s==1){
          torreta[1]=torreta[1]-1;
          s--;
       }
  }      
}


void tablero::mover_ejercito() {
  //Con este metodo, el usuario va poder mover su ejercito, y de paso tambien se verifica los estados del juego.
  cout << "¿Qué ejercito desea mover: 1 o 2?\n";
  cin >> ejercito;
  system("clear");
  do {
    do {
    
      MostrarDatos();
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
              case 'f':
              
              if(PosicionAtaque() == 0){
                Batalla(1);
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

              case 'f':           

              if(PosicionAtaque() == 0){
                Batalla(2);
              }else if(PosicionAtaque() == 1){
              VidaTorreta();
              }        

            break;
          }
        }
      }
      system("clear");
    } while (respuesta != 'e');
    switch(respuesta){
        case 'e':
        cambiar_ejercito();
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

void tablero::MostrarDatos(){

 cout << "\n";
  if (torreta[1] == 0) {
        cout << "La torreta ha sido destruida. Por favor inicie otra partida\n";
      } else {
        cout << "Vida de la Torreta: " << torreta[1] << endl;
      }

       //Mostrar informacion de los ejercitos
        cout << "    Ejercito 1    ";
        cout << "  Ejercito 2\n ";  
      for(int i = 0; i < Ejercito_1.size()+1; i++){
          //Nombre ejercito 1
           cout <<i<< ". "<< Ejercito_1[i] -> Nombre <<": ";
          //Vida ejercito 1
           cout << Ejercito_1[i] -> Vida;
           
           if(Ejercito_1[i] -> Nombre== "Tirador"){
             cout << "   "; 
           }if(Ejercito_1[i] -> Nombre== "Mago"){
             cout << "      "; 
           }else if(Ejercito_1[i] -> Nombre== "Luchador"){
             cout << "  ";
           }

          //Nombre ejercito 2
           cout <<i<< ". "<< Ejercito_2[i] -> Nombre <<" ";
          //Vida ejercito 2
           cout << Ejercito_2[i] -> Vida <<"\n ";          

      }
      cout << "\n";
}


void tablero::mod_bonus(int nuevoValor) {
  //Metodo para cambiar de valor el bonus
  bonus = nuevoValor;
}
//guarda la partida en un archivo plano
void tablero::guardar_partida(string nombre) {
  ofstream archive;
  string name;
  name=nombre+".txt";
  archive.open(name);
  if(archive.fail()){
    cout << "No se pudo abrir el archivo.";
    exit(1);
  }
  //guarda la matriz
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      archive<<camino[i][j]<<" ";
    }
    archive << endl;
  }
  archive << endl;
  //guarda la vida de los ejercitos y torreta
  if(optn==2){
    archive<<optn<<" ";
    archive<<torreta[1]<<" ";
    archive<<n<<" "<<s<<" ";
    archive<<o<<" "<<o2<<" ";
    archive<<e<<" "<<e2<<" ";
    archive<<ejercito1[1]<<" ";
    archive<<ejercito2[1]<<" "; 

  }else if(optn==1){
  archive<<optn<<" ";
  archive<<torreta[1]<<" ";
  archive<<n<<" "<<s<<" ";
  archive<<o<<" "<<e<<" ";
  archive<<ejercito1[1]<<" ";
  archive<<ejercito2[1]<<" ";  
  archive.close();
  }
}

//carga los datos de las partidas anteriores
void tablero::cargar_datos(string ruta){
  ifstream leer;
  int dato,x;
  string auxiliar,name;
  name=ruta+".txt";
  leer.open(name.c_str());
 for(int i=0;i<11;i++){    
    for(int j=0;leer>>auxiliar;j++){
      stringstream aux(auxiliar);
      aux>>dato;
      camino[i][j]=dato;      
    }
   
  }
 
    leer.close();
   //carga las posiciones de los ejercitos
   for(int i=0;i<10;i++)
     for (int j = 0; j < 10; j++) {
      if(camino[i][j]==2){   
        x2=i;y2=j;
        ejercito2[0]=camino[i][j];                
        }else if(camino[i][j]==1){
          x1=i;y1=j;
          ejercito1[0]=camino[i][j];          
        }
    }
    
   //carga los datos de torreta y ejercitos
    optn=camino[10][0];
    if(optn==1){
      torreta[1]=camino[10][1];
      n=camino[10][2];
      s=camino[10][3];
      o=camino[10][4];
      e=camino[10][5];
      ejercito1[1]=camino[10][6];
      ejercito2[1]=camino[10][7];
      camino[4][4]=torreta[0];
      
    }else if(optn==2){
        torreta[1]=camino[10][1];
        n=camino[10][2];
        s=camino[10][3];
        o=camino[10][4];
        o2=camino[10][5];
        e=camino[10][6];
        e2=camino[10][7];
        ejercito1[1]=camino[10][8];
        ejercito2[1]=camino[10][9];
        camino[4][4]=torreta[0];
        camino[5][4]=torreta[0];
    }  
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
        system("clear");
        repartir_bonos();
        posiciones_iniciales();        
        mostrar_archivo();
        break;
      case 2:
        system("clear");
        cout << "Bonos disponibles: " << bonus << endl;
        cout << "Tropas por ejercito: " << cant_ejercito << endl;
        break;
      case 3:
        system("clear");
        string name;
        cout<<"nombre de la partida: \n";
        cin>>name;
        cargar_datos(name);        
        cout<<"Vida torreta: "<<torreta[1]<<endl;
        cout<<"Vida ejercito 1: "<<ejercito1[1]<<endl;
        cout<<"Vida ejercito 2: "<<ejercito2[1]<<endl;
        mostrar_archivo();
        mover_ejercito();
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
        Avatares();
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
  system("clear");
  cout << "nombre de la partida: \n";
  string nombree;
  cin >> nombree;
  guardar_partida(nombree);
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