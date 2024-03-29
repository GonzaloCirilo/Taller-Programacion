#include <iostream>
using namespace std;
// funcion factorial
long long factorial(int n) {
	long long res = 1; // el valor por defecto siempre es 1 por que multiplicaremos valores
	for (int i = 1; i <= n; i++) {
		res *= i;
	}
	return res;
}

int main() {
	int n;

	do {
		cout << "Ingrese el valor de N: ";
		cin >> n;
	} while (n < 0 || n > 120);


	if (n > 10) { // si n es mayor el termino de esa posicion es despreciable
		cout << "El valor del número e es: 2.71828";
	}
	else {
		float res = 0; // variable respuesta
		for (int i = 1; i <= n; i++) {
			long long numerador = i * i;
			long long denominador = 2 * factorial(i);

			res += (float)(numerador) / denominador;
		}

		cout << "El valor del número e es: " << res;
	}

	

	return 0;
}