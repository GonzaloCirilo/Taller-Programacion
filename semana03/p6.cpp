// Si estan en visual y sale error descomentar la linea de abajo
//#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

int calcularPuntajeGrado(char grado){
    int aux = 0;
    aux = (grado == 'B') * 3 + (grado == 'I') * 7 + (grado == 'M') * 20;
    return aux;
}

int calcularPuntajeNivel(char nivel){
    int aux = 0;
    aux = (nivel == 'T') * 7 + (nivel == 'Q') * 10 + (nivel == 'R') * 2;
    return aux;
}

int calcularPuntajeEsp(char esp){
    int aux = 0;
    aux = (esp == 'A') * 1 + (esp == 'B') * 10 + (esp == 'C') * 15 + (esp == 'D') * 25;
    return aux;
}

int main(){
    char grado, nivel, esp;
    
    cout << "Grado (B: bachiller; I: ingeniero; M: magíster): ";
    cin >> grado;
    cout << "Nivel (T: tercio; Q: quinto; R: regular): ";
    cin >> nivel;
    cout << "Especialización (A: no tiene; B: solo SAP; C: solo JAVA; D: SAP y JAVA): ";
    cin >> esp;

    int pGrado = calcularPuntajeGrado(grado);
    int pNivel = calcularPuntajeNivel(nivel);
    int pEsp = calcularPuntajeEsp(esp);

    int total = pGrado + pNivel + pEsp;

    cout << "Puntaje Obtenido: " << pGrado << " + " << pNivel << " + " << pEsp << " = " << total << endl;

    char resp = (total >= 24) * 'S' + (total < 24) * 'N';
    cout << "Ingresa a (S=Sí, N=No): " << resp << endl;

    _getch();
    return 0;
}