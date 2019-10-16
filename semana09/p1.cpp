#include <iostream>
#include <math.h>
using namespace std;
// funcion para mostrar el menu de opciones
void printMenu() {
	cout << "Menú de opciones" << endl;
	cout << "1. Calcular la serie" << endl;
	cout << "2. Hallar cantidad de dígitos pares" << endl;
	cout << "3. Fin" << endl;
	cout << "Ingrese opcion: ";
}
// funcion factorial
long long factorial(int n) {
	int res = 1;
	for (int i = 1; i <= n; i++) {
		res *= i;
	}
	return res;
}
// el parametro res tendra la respuesta ya que es un parametro por referencia
void calculoSerie(int &n, double &y, double &res) {
	if (n == 1) { // si nos piden solo el primer termino devolvemos n
		res = 1;
	}
	else {
        // declaramos variables auxiliares
		int constante = 3;
		int exponente = 2;
        // iniciamos la variable en uno porque iteraremos desde el segundo termino
		res = 1;
        //iteracion desde el 2do termino hasta n
		for (int i = 2; i <= n; i++) {
			int signo = 0;
            // calculamos el signo en base a la posicion del termino
			if (i % 2 == 0)
				signo = -1;
			else
				signo = 1;
            // Calculamos el termino
			double termino = (double)signo * (double)constante * (double)pow(y, exponente) / factorial(constante);

            // actualizamos los valores de las variables auxiliares
			constante += 2;
			exponente += 2;
            // El termmino hallado lo sumamos a la variable respuesta
			res += termino;
		}
	}
}

void cantDigitosPar(int n, int &res) {
	int aux = n;
	while (aux > 0) {
		int digito = aux % 10;
		aux /= 10;
		if (digito % 2 == 0) { // si eldigito es par actualizamos el resultado
			res++;
		}
	}
}

int main() {
	int opcion; double res = 0;
	int n; double y;
	do {
		printMenu();
		cin >> opcion;

		switch (opcion) {
		case 1:
            // Leemos las variales con sus validaciones
			do {
                cout << "Ingrese el valor de n: ";
			    cin >> n;
            } while(n <= 0);
			do{
                cout << "Ingrese el valor de y: ";
                cin >> y;
            } while(y > 3.6 || y < 1.2);
			res = 0;
			calculoSerie(n, y, res);
			cout << res << endl;
			break;
		case 2:
			int r = 0;
            // Leemos la variale con sus validacion
            do{
                cout << "Ingrese el valor de n: " << endl;
			    cin >> n;
            }while(n <= 0);			
			cantDigitosPar(n, r);
			cout << r << endl;
			break;
		}

	} while (opcion != 3);
	return 0;
}