#pragma once
#include<iostream>

using namespace std;

class Puesto
{
	//atributos
protected: string puesto;
		 //constructor(metodo especial, se llama igual que la clase, puede no tener nada)
protected:
	Puesto() {//clase abstracta, no deriva de nada y sirve para ser heredada	
	}
	Puesto(string pue) {
		puesto = pue;
	}
};

