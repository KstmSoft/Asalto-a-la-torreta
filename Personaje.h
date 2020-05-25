#ifndef _PERSONAJE_H_
#define _PERSONAJE_H_

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <vector>
using namespace std;

class Personaje {
   public:
     Personaje(float,float,float,string);
     ~Personaje();
     virtual void Atacar(Personaje *P);
     virtual void Empate(Personaje *P);
     float Poder;
     float Mana;
     float Vida;
     string Nombre;     
};

#endif