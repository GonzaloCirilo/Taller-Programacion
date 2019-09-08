// Si estan en visual y sale error descomentar la linea de abajo
//#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

// Funcion para calcular 
char getLineaTel(float sal, int per){
    char aux = (per == 1 && sal <= 500) * 'P' + (per == 1 && sal > 500) * 'O'
        + (per >= 2 && per <= 4 && sal <= 750) * 'P' + (per >= 2 && per <= 4 && sal > 750) * 'O'
        + (per > 4 && sal <= 1000) * 'P' + (per > 4 && sal <= 1000) * 'O';
    return aux;
}

int main(){
    float salario;
    int personas;

    cout << "Ingrese el salario mensual: ";
    cin >> salario;
    cout << "Ingrese número de personas a cargo: ";
    cin >> personas;

    cout << "Tipo de línea al que puede acceder: " << getLineaTel(salario, personas) << endl;
    _getch();
    return 0;
}