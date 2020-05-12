#include "Avatar.h"

Avatar::Avatar(float Vida,float Mana, float Poder,string Nombre) : Personaje(Vida,Mana,Poder,Nombre){

}

Avatar::~Avatar(){

}

void Avatar::Atacar(Personaje *P){

   if(P -> Vida != 0){
     P -> Vida -= 0.5;

     if( P -> Vida < 0){
        P -> Vida = 0;
     } 
   }
}

void Avatar::Empate(Personaje *P){

 if(P -> Vida != 0){
     P -> Vida -= 0.2;

     if( P -> Vida < 0){
        P -> Vida = 0;
     } 
   }
}