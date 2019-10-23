#include <iostream>
using namespace std;

void printMenu() {
	cout << "Elija una de las opciones:" << endl;
	cout << "1. Graficar Estrella" << endl;
	cout << "2. Graficar Rombo" << endl;
	cout << "3. Salir" << endl;
	cout << "Ingrese opcion: ";
}

int obtenerN() {
	int n;
	do {
		cout << "Ingresa el valor de n: ";
		cin >> n;
	} while (n < 2 || n > 9);
	return n;
}

void repetirCaracter(int veces, char c) {
	for (int i = 0; i < veces; i++) {
		cout << c;
	}
}

void graficar1(int n) {
	int med = n - 1;
	// BLoque superior
	for (int i = 0; i < med; i++) {
		// mostrar espacios a la izquierda
		repetirCaracter(i, ' ');
		// mostramos el numero
		cout << n;
		// mostrar espacios medios
		repetirCaracter(med - (i + 1), ' ');
		//
		cout << n;
		//
		repetirCaracter(med - (i + 1), ' ');
		cout << n;
		cout << endl;
	}
	//Bloque medio
	repetirCaracter(2 * n - 1, n + '0');
	cout << endl;
	// Bloque inferior
	for (int i = 0; i < med; i++) {
		repetirCaracter(med - (i + 1), ' ');
		cout << n;
		repetirCaracter(i, ' ');
		cout << n;
		repetirCaracter(i, ' ');
		cout << n;
		cout << endl;
	}
}

void punta(int n) {
	repetirCaracter(n - 1, ' ');
	cout << n << endl;
}

void graficar2(int n) {
	punta(n);
	for (int i = 0; i < n - 2; i++) {
		repetirCaracter(n - 2 - i, ' ');
		cout << n;
		repetirCaracter(i, ' ');
		cout << n;
		repetirCaracter(i, ' ');
		cout << n;
		cout << endl;
	}
	repetirCaracter(2 * n - 1, n + '0');
	cout << endl;
	for (int i = 0; i < n - 2; i++) {
		repetirCaracter(i + 1, ' ');
		cout << n;
		repetirCaracter(n - 2 - (i + 1), ' ');
		cout << n;
		repetirCaracter(n - 2 - (i + 1), ' ');
		cout << n;
		cout << endl;
	}
	punta(n);
}

int main() {
	int opcion = 0;
	do {
		printMenu();
		cin >> opcion;
		if (opcion == 3) continue;
		int n = obtenerN();
		switch (opcion) {
		case 1:
			graficar1(n);
			break;
		case 2:
			graficar2(n);
			break;
		}
	} while (opcion != 3);
	return 0;
}