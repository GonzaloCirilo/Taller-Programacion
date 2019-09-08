// Si estan en visual y sale error descomentar la linea de abajo
//#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

int calcularPrecio(int m2, int m3){
    int aux = 0;
    aux = (m3 < 70) * (m2 * 2.5) + (m3 >= 70 && m3 <= 150) * (m2 * 5.0) + (m3 > 150) * (m2 * 10);
    return aux * 5;
}

int main() {
    int a;
    cout << "Ingrese el tamaño de la arista (m): " << endl;
    cin >> a;

    int vol = a * a * a;
    int area = a * a;

    cout << "Volumen = " << vol << endl;
    cout << "Su monto a pagar es " << calcularPrecio(area, vol) << " soles"; 
    _getch();
    return 0;
}