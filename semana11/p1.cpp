#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void generarYMostrarDatos(int *arr) {
	for (int i = 0; i < 30; i++) {
		arr[i] = rand() % 4 + 1;
		if (i != 0)
			cout << "-";
		cout << arr[i];
	}
	cout << endl;
}

void listaPuntajes(int *arr, int *cantXPunt) {
	for (int i = 0; i < 30; i++) {
		cantXPunt[arr[i] - 1]++; 
	}

	for (int i = 0; i < 4; i++) {
		cout << "La cantidad de personas que votaron por " << i + 1 << " es:" << cantXPunt[i] << endl;
	}
	cout << endl;
}

void mayorVotacion(int *cantXPunt) {
	int  aux = -1, tipoPuntaje = 0;
	for (int i = 0; i < 4; i++) {
		if (cantXPunt[i] > aux) {
			aux = cantXPunt[i];
			tipoPuntaje = i + 1;
		}
	}
	cout << "El puntaje con mayor votos es: " << tipoPuntaje;
}

int main() {
	srand(time(NULL));
	int *arr = new int[30];

	int *cantidadPorPuntaje = new int[4];

	for (int i = 0; i < 4; i++) {
		cantidadPorPuntaje[i] = 0;
	}
	
	generarYMostrarDatos(arr);

	listaPuntajes(arr, cantidadPorPuntaje);

	mayorVotacion(cantidadPorPuntaje);
	
	return 0;
}