#pragma once
#include<mysql.h>
#include<iostream>

using namespace std;

class conexion_bd
{
private : MYSQL* conectar;//variable tipo mysql
public : 
	void abrir_conexion() {
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "jyzene", "Ocarinaoft!me123", "db_productos", 3306, NULL, 0);
	}
	MYSQL* getConectar() {
		return conectar;
	}
	void cerrar_conexion() {
		mysql_close(conectar);
	}
};

