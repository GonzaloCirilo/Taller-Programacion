#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int contador = 1;

void Generar_Mensaje(int *Mensaje, int longitud_mensaje){
    for(int i = 0; i < longitud_mensaje; i++){
        Mensaje[i] = rand() % 10; // rango del 0 al 9
    }
}

void Imprimir(int *Mensaje, int longitud_mensaje){
    cout << "Mensaje: " << contador++ << endl << endl;
    for(int i = 0; i < longitud_mensaje; i++){
        cout << Mensaje[i] << " ";
    }
    cout << endl << endl;
}

bool Existe_capicua(int *Mensaje, int longitud_mensaje){
    // Neceistamos  verificar un numero capicua de 3 cifras en las ultimas cuatro cifras
    // Pero este numero debe estar en las ultimas cuatro cifras
    // entonce solo chequeamo para: 
    return Mensaje[longitud_mensaje - 1] == Mensaje[longitud_mensaje - 3] || Mensaje[longitud_mensaje - 2] == Mensaje[longitud_mensaje - 4];
}

int main(){

    srand(time_t(NULL));

    int nCapicua = 0;    

    while(true){

        int nele = rand() % 11 + 10;

        int *Mensaje = new int[nele];

        Generar_Mensaje(Mensaje, nele);

        Imprimir(Mensaje, nele);

        if(Existe_capicua(Mensaje, nele))
            nCapicua++;

        if(nCapicua == 6){
            cout << "\t\tCONTACTO!!!" << endl << endl;
            system("pause");
            break;
        }
        system("pause");

    }

    return 0;
}