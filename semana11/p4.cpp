#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void generarYMostrarDatos(int *arr) {
	for (int i = 0; i < 15; i++) {
		arr[i] = rand() % 88 + 32;
		if (i != 0)
			cout << "-";
		cout << arr[i];
	}
	cout << endl;
}

void calcularMarcasFueraDeLimite(int *arr){
    int cont = 0;
    for(int i = 0; i < 15; i++){
        if(arr[i] > 37){ // si el valor del azucar sobrepasa 37 (valor permitido)
            cont++;
        }
    }
    cout << cont << " marca(s) sobrepasan el valor permitido" << endl;
}

void marcaConMayorAzucar(int *arr){
    int max = 0;
    for(int i = 0; i < 15; i++){
        if(arr[i] > max){ // si en esta posicion hay un valor mayor que max
            max = arr[i]; // entonces max debe tener ese valor
        }
    }
    // Debemos mostrar todas la(s) marca(s) que tienen ese valor maximo
    cout << "La(s) marca(s) ";
    for(int i = 0; i < 15; i++){
        if(arr[i] == max){
            cout << i << " ";
        }
    }
    cout << "tiene(n) la mayor cantidad de azucar" << endl;
}

void reporte(int *arr){
    int cont = 0;
    for(int i = 0; i < 15; i++){
        if(arr[i] <= 37){
            cont++;
            cout << "La Marca " << i + 1 << ": cumple con la norma" <<endl;
        }
    }
    if(cont == 0){// si ninguno cumple la norma mostrar mensaje
        cout << "No hay marcas que cumplan con la norma" << endl;
    }
}

int main() {
	srand(time(NULL));
	int *arr = new int[15];
	generarYMostrarDatos(arr);
    calcularMarcasFueraDeLimite(arr);
    marcaConMayorAzucar(arr);
    reporte(arr);
	return 0;
}
