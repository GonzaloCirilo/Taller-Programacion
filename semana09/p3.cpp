#include <iostream>
#include <iomanip>
using namespace std;
// funcion para obtener el n termino de la serie fibonacci
int fibonacci(int n) {
	if (n == 1 || n == 2)
		return 1;
	int fib1 = 1, fib2 = 1, res = 0;
	for (int i = 3; i <= n; i++) {
		// calculamos el valor de la serie para ese indice
		res = fib1 + fib2;
		// actualizamos los valores de fib1 y fib 2
		fib1 = fib2;
		fib2 = res;
	}
	return res;
}

void graficar(int &n) {
	// primero iteramos por las filas
	for (int i = 0; i < n; i++) {
		// imprimimos espacios
		for (int j = 0; j < n - (i + 1); j++) {
			cout << "  ";
		}
		// imprimimos los numeros
		for (int j = 0; j < (i + 1); j++) {
			//int val = n - i
			cout << setw(2) << setfill(' ') << fibonacci(n - i);
		}
		cout << endl;
	}
}
int main() {
	int n;
	do {
		cout << "Ingrese el valor de n: ";
		cin >> n;
	} while (n > 15 || n < 2);
	graficar(n);
	return 0;
}