#include <iostream>

using namespace std;

int main() {
	int n;
	float b;

	do {
		cout << "Ingrese el valor de N: ";
		cin >> n;
	} while (n < 0);

	do {
		cout << "Ingrese el valor de b: ";
		cin >> b;
	} while (b < 1 || b >5);

	float resultado = 0;

	for (int i = 0; i < n; i++) {
		float termino = (float)((i + 1) * 2 * b) / (i * 3 + 4);
		
		
		//cout << "===========" << termino << endl;
		resultado += termino;
		//resultado += (i % 2 == -1 ? -1 : 1) *((i + 1) * 2 * b) / (i * 3 + 4);
	}

	cout << "Resultado: " << resultado;

	return 0;
}