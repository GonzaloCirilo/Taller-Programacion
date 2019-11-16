#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    srand(time_t(NULL));
    // una matriz podria definirse como un arreglo de arreglos. Exiten dos variantes
    // matriz estatica al darle = {} inicializa todos los valores de la matriz en 0
    int ejemplo[20][20] = {};
    
    // matriz dinamica - con esta resolveremos el ejercicio 
    int **matriz = new int*[50];

    // Inicializamos cada uno de los 50 arreglos on una longitud de 4 como pide el problema
    for(int i = 0; i < 50; i++){
        matriz[i] = new int[4];

        //una vez inicializado le damos un valor inicial
        // 0 - sera la atencion de empleados
        // 1 - calidad de comida
        // 2 - precios justos
        // 3 - ambiente
        for(int j = 0; j < 4; j++){
            matriz[i][j] = rand() % 10 + 1;
        }
    }

    // Mostramos la matriz 
    // el caracter \t es como precionar la tecla tab

    cout << "Atencion\tCalidad\t\tPrecios\t\tAmbiente" << endl;

    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 4; j++){
            cout << matriz[i][j] << "\t\t";
        }
        cout << endl;
    }
    cout << endl;
    // 1) Determinar los aspectos que tienen mayor promedio
    // arreglo que tendra los promedios de cada categoria
    float *promedios = new float[4];
    for(int j = 0; j < 4; j++){
        promedios[j] = 0;
    }

    //inicializamos en 0

    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 4; j++){
            promedios[j] += matriz[i][j];
        }
    }

    // tenemos todas las sumas, solo faltaria dividrlo entre la cantidad que es 50
    // tambien calulamos el mayor con solo la suma ya que todos se dividen entre la misma cantidad
    float max = 0;
    for(int j = 0; j < 4; j++){
        promedios[j] /= 50;
        if(promedios[j] > max){
            max = promedios[j];
        }
    }

    cout << "Los aspectos con mayor promedio: ";
    for(int j = 0; j < 4; j++){
        if(max == promedios[j]){
            switch(j){
                case 0:
                    cout << "Atencion ";
                    break;
                case 1:
                    cout << "Calidad ";
                    break;
                case 2:
                    cout << "Precios ";
                    break;
                case 3:
                    cout << "Ambiente ";
                    break;
            }
        }
    }

    cout << endl << endl;

    // 2) Determina para la calidad de comida, la distribucion de frecuencias de las calificaciones

    // Como son dies valores posibles la cantidad de personas se guardara en un arreglo
    
    int *cantidadPersonas = new int[10];

    // Inicializamos cantidad de personas
    for(int i = 0; i < 10; i++){
        cantidadPersonas[i] = 0;
    }

    // Por cada persona...
    for(int i = 0; i < 50; i++){
        //vemos el valor de la canlidad (indice 1)
        int calidad = matriz[i][1];

        // luego para este valor de la calidad aumentamos la cantidad en uno
        // sin embargo a calidad le restamos 1
        // porque el arreglo va de 0 a 9 y el valor de calidad es de 1- 10
        cantidadPersonas[calidad - 1]++;
    }

    //Mostramos la informacion
    cout << "Resumen de personas Calidad de comida" << endl << endl;

    // iteramos el arreglo cantidadPersonas
    for(int i = 0; i < 10; i++){
        cout << i + 1 << ": " << cantidadPersonas[i] << " persona(s)." << endl;
    }
    cout << endl;


    // 3) Determinar la cantidad de personas que califican como excelente la atencion de los empleados
    int personas = 0;
    for(int i = 0; i < 50; i++){
        // recodar que 0 - atencion de empleados
        if(matriz[i][0] == 10){
            personas++;
        }
    }

    cout << "Personas que calificaron atencion excelente:  " << personas << endl;


    return 0;
}