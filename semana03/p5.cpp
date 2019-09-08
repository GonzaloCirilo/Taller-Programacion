// Si estan en visual y sale error descomentar la linea de abajo
//#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

int convertirBase3(int n){
    int aux = (n % 3)
        + (n >= 3) * ((n / 3) % 3) * 10 
        + (n >= 9) * ((n / (3 * 3)) % 3) * 100
        + (n >= 27) * ((n / (3 * 3 * 3)) % 3) * 1000
        + (n >= 81) * ((n / (3 * 3 * 3 *3)) % 3) * 10000;
    return aux;
}

int main(){
    char apellido;
    int edad;
    float peso;
    cout << "Ingrese la primera letra de su apellido:";
    cin >> apellido;
    cout << "Ingrese edad: ";
    cin >> edad;
    cout << "Ingrese peso: ";
    cin >> peso;

    cout << "Datos convertidos para comunicarse" << endl;
    cout << "Primera letra del apellido: " << convertirBase3((int) apellido) << endl;
    cout << "Edad: " << convertirBase3(edad) << endl;
    cout << "Edad peso: " << convertirBase3((int) peso) << endl;

    _getch();
    return 0;
}