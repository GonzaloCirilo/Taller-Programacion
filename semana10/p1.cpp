#include <iostream>
using namespace std;

void printMenu(){
    cout << "1. Calcular Serie" << endl;
    cout << "2. Hallar cantidad de digitos impares" << endl;
    cout << "3. Fin" << endl << endl;
}

void calcularSerie(int n, float *suma){
    for(int i = 1; i <= n; i++) {
        float termino = (float) i / (2 * i * i - 1);
        cout << "El termino " << i << " es: " << termino << endl;
        *suma += termino;
    }
}

void cantidadNumerosImpar(int n, int *cant){
    // Homework ;)
}

int main(){
    int opcion;
    do {
        printMenu();
        cout << "Ingrese la opcion: ";
        cin >> opcion;
        switch(opcion){ //No olvidar las validaciones
            case 1:
                float suma;
                int n;
                cout << "Ingrese el valor de n: ";
                cin >> n;
                calcularSerie(n, &suma);
                cout << "La suma es: " << suma;
                break;
            case 2:
                int n, cant;
                cout << "Ingrese el valor de n: ";
                cin >> n;
                cantidadNumerosImpar(n, &cant);
                cout << "Cantidad de numeros impar es: " << cant;
                break;
        }
    } while(opcion != 3);
    return 0;
}