#pragma once
#include<iostream>

using namespace std;

class Persona
{
	//atributos
protected: string nombres, apellidos, direccion, fecha_nacimiento;
		 int telefono, dpi;
		 bool genero;
		 //constructor(metodo especial, se llama igual que la clase, puede no tener nada)
protected:
	Persona() {//clase abstracta, no deriva de nada y sirve para ser heredada	
	}
	Persona(string nom, string ape, string dir, string f_n, int tel, int dpi, bool g) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = f_n;
		dpi = dpi;
		genero = g;
	}
};

