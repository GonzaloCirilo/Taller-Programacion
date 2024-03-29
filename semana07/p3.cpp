#include <iostream>
using namespace std;

int main() {

	int n;

	do {
		cout << "Ingrese un número: ";
		cin >> n;
	} while (n >= 15 || n < 4);

	int constante = 39;
	int orientacion = 1;

	for (int i = 0; i < n; i++) {
		//int cantEspacios = constante - i;
		//Dibujamos espacios hasta la posicion adecuada
		for (int j = 0; j < constante - i; j++) {
			cout << " ";
		}
		if (i == 0) { // Estamos en la primera fila
			cout << (char)196;
		}
		else {
			//calculando la longitud de cada piso de la piramide
			int longitudPiso = (i * 2 + 1);
			for (int j = 0; j < longitudPiso; j++) {
				if (j == 0 || j == longitudPiso - 1) { // Estamos en los extremos
					if (orientacion == 1) { // ((i+1)%2 == 1)
						cout << (char)196;
					}
					else if (orientacion == -1) {
						cout << (char)179;
					}
				}
				else {
					cout << (char)250;
				}
			}
		}
		cout << endl;
		orientacion *= -1;
	}
	return 0;
}