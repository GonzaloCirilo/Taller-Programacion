#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void generar(int *arr, int n){
    for(int i = 0; i < n ; i++){
        arr[i] = rand() % 9 + 1;
    }
}

void mostrar(int *arr, int n){
    for(int i = 0; i < n; i++){
        if(i != 0)
            cout << "-";
        cout << arr[i];
    }
    cout << endl;
}

void cantidadDeCadaDigito(int *arr, int n){
    for(int i = 1; i <= 9; i++) {// Una iteracion por cada digito
        int cont = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == i)
                cont++;
        }
        cout << "El numero " << i << " se repitio " << cont << " veces" << endl;
    }
}

void cambiarDigitoPrimo(int *arr, int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == 2 || arr[i] == 3 || arr[i] == 5 || arr[i] == 7)
        arr[i]++;
    }
}

int main(){
    srand(time(NULL));
    int n;
    do {
        cout << "Ingrese el valor de n" << endl;
        cin >> n;
    } while(n <= 0 || n > 40);

    int *arr = new int[n];

    generar(arr, n);

    mostrar(arr, n);

    cantidadDeCadaDigito(arr, n);

    cambiarDigitoPrimo(arr, n);

    mostrar(arr, n);


    return 0;
}