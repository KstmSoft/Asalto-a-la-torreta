#ifndef _LUCHADOR_H_
#define _LUCHADOR_H_
#include "Personaje.h"

class Avatar : public Personaje {

   public:
     Avatar(float,float,float,string);
     ~Avatar();
     virtual void Atacar(Personaje *P);
     virtual void Empate(Personaje *P);
     int Poder;
     int Mana;
     int Vida;   
     string Nombre;  

};

#endif