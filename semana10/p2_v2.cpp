#include <iostream>
#include <math.h>
using namespace std;

void printMenu(){
    cout << "Elija una de las opciones:" << endl;
    cout << "1. Graficar Estrella" << endl;
    cout << "2. Graficar Rombo" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingrese opcion: ";
}

int obtenerN(){
    int n;
    do{
        cout << "Ingresa el valor de n: ";
        cin >> n;
    } while(n < 2 || n > 9);
    return n;
}

void graficar1(int n){
    int size = 2 * n - 1;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i == n - 1 || j == n - 1 || i == j || (size - i - 1) == j)
                cout << n;
            else
                cout << " ";
        }
        cout << endl;
    }
}

void graficar2(int n){
    int size = 2 * n - 1;
    int med = n - 1;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i == med || j == med || abs(i - j) ==  med || i + j == med || 3 * med == i + j)
                cout << n;
            else
                cout << " ";
        }
        cout << endl;
    }
}


int main(){
    int opcion  = 0;
    do{
        printMenu();
        cin >> opcion;
        if(opcion == 3) continue;
        int n = obtenerN();        
        switch(opcion){
            case 1:
            graficar1(n);
            break;
            case 2:
            graficar2(n);
            break;
        }
    }while(opcion != 3);
    return 0;
}