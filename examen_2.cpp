#include <iostream>
#include<conio.h>
#include"Empleados.h"
#include<mysql.h>

void insert();
void select();
void create();

using namespace std;

int q_estado;
int opc;
MYSQL* conectar;//variable tipo mysql
MYSQL_ROW fila;
MYSQL_RES* resultado;


int main()
{
    string nombres, apellidos, direccion, fecha_nacimiento, fecha_inicio_labores, fechaingreso;
    int telefono, DPI;
    bool genero;
    
    cout << "ingrese los nombres: ";
    cin >> nombres;
    cout << "ingrese los apellidos: ";
    cin >> apellidos;
    cout << "ingrese la direccion: ";
    cin >> direccion;
    cout << "ingrese el telefono: ";
    cin >> telefono;
    cout << "ingrese el dpi: ";
    cin >> DPI;
    cout << "ingrese el genero: ";
    cin >> genero;
    cout << "ingrese la fecha de nacimiento: ";
    cin >> fecha_nacimiento;
    cout << "ingrese la fecha de inicio de labores: ";
    cin >> fecha_inicio_labores;
    cout << "ingrese la fecha de ingreso: ";
    cin >> fechaingreso;

    Empleados c = Empleados(nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, fecha_inicio_labores, fechaingreso);
    c.crear();
    c.leer();



    system("pause");
    return 0;
}



