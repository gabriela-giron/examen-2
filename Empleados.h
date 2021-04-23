#pragma once
#include "Persona.h"
#include <mysql.h>
#include<string>
#include"conexion_bd.h"
#include<iostream>

using namespace std;


class Empleados : Persona{
	//atributos
private: string fecha_inicio_labores, fechaingreso;
	   //constructor
public:
	Empleados() {
	}
	Empleados(string nom, string ape, string dir, int tel, string f_n, string f_i_l, string fi, int dpi, bool g) : Persona(nom, ape, dir, tel, f_n, f_i_l, fi, dpi, g) {
		//envia las variables para ya no volver a nombrarlas
		fecha_inicio_labores = f_i_l;
		fechaingreso = fi;
	}
	//metodo set
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setFecha_nacimiento(string f_n) { fecha_nacimiento = f_n; }
	void setFechaingreso(string fi) { fechaingreso = fi; }
	void setDPI(int dpi) { dpi = dpi; }
	void setGenero(bool g) { genero = g; }
	//metodo get
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_nacimiento() { return fecha_nacimiento; }
	string getFechaingreso() { return fechaingreso; }
	int getDPI() { return dpi; }
	bool getGenero() { return genero; }

	//metodo
	void crear() {
		int q_estado;
		conexion_bd cn = conexion_bd();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string d = to_string(DPI);
			string insert = "INSERT INTO EMPLEADOS(nombres,apellidos,direccion, telefono, DPI, genero, fecha_nacimiento, fecha_inicio_labores, fechaingreso) VALUES('" + nombres + "','" + apellidos + "','" + direccion + "','" + t + "','" + d + "','" + genero + "','" + fecha_nacimiento + "','" + fecha_inicio_labores + "','" + , fechaingreso + "');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Se logró insertar! :3" << endl;
			}
			else {
				cout << "no se pudo :((" << endl;
			}
		
		}
		else {

		}
		cn.cerrar_conexion();



	}

	void leer() {
		int q_estado;
		conexion_bd cn = conexion_bd();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from empleados";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "--------------------------------------------------------------Empleados-----------------------------------------------------------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << fila[6] << " | " << fila[7] << " | " << fila[8] << " | " << fila[9] << " | " << fila[10] << endl;
				}
			}
			else {
				cout << "algo fallo :(((" << endl;
			}
		}
		else {
			cout << "hubo un error :(" << endl;
		}
		cn.cerrar_conexion();
	}
};



/*class Empleados
{
	//atributos
protected: string nombres, apellidos, direccion, fecha_nacimiento, fecha_inicio_labores, fechaingreso;
		 int telefono, dpi;
		 bool genero;
		 //constructor(metodo especial, se llama igual que la clase, puede no tener nada)
protected:
	Empleados() {//clase abstracta, no deriva de nada y sirve para ser heredada	
	}
	Empleados(string nom, string ape, string dir, string f_n, string f_i_l, string fi, int tel, int dpi, bool g) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		fecha_nacimiento = f_n;
		fecha_inicio_labores = f_i_l;
		fechaingreso = fi;
		telefono = tel;
		dpi = dpi;
		genero = g;
	}
};*/