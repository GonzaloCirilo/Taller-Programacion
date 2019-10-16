#include <iostream>
using namespace std;
/**
 * funcion con parametros por referencia
 * La cantidad de digitos pares y el promedio seran hallados y retornadas
 * en las variables cantPares y promedio respectivamente
 */
void Hallar_promedio_y_cantidad(int n, int &cantPares, double &promedio) {
	// copiamos el valor de n en una variable auxiliar
	int aux = n;
	// variable cont para
	int cont = 0;
	int suma = 0;
	while (aux > 0) {
		cont++;
		int digito = aux % 10;
		aux /= 10;
		if (digito % 2 == 0) {
			cantPares++;
		}
		suma += digito;
	}

	promedio = (double)suma / cont;
}
// Funcion anterior pero usando punteros 
void Hallar_promedio_y_cantidad_punteros(int *n, int *cantPares, double *promedio) {
	// copiamos el valor de n en una variable auxiliar
	// Esta asignacion primero dereferencia el valor del puntero n y luego se lo asigna la referencia
	int *aux = new int;
	*aux = *n;
	// variable cont para
	int *cont = new int;
	int *suma = new int;
	*cont = 0;
	*suma = 0;
	while (*aux > 0) {
		*cont++;
		int digito = *aux % 10;
		*aux /= 10;
		if (digito % 2 == 0) {
			*cantPares++;
		}
		*suma += digito;
	}

	*promedio = (double)*suma / *cont;

}

int main() {
	int n;
	int *nPuntero = &n;
	do {
		cin >> n;
	} while (n <= 0);

	// el valor debe ser el mismo ya nPuntero tiene la direccion de memoria de n
	cout << n << " " << *nPuntero << endl << endl;

	// Resultados
	int cantPares = 0; double promedio = 0;

	Hallar_promedio_y_cantidad(n, cantPares, promedio);

	cout << "El promedio y cantidad de pares es: " << promedio << " " << cantPares << endl << endl;

	int *pCantPares = new int; double *pPromedio = new double;
	*pCantPares = 0;
	*pPromedio = 0;
	Hallar_promedio_y_cantidad_punteros(nPuntero, pCantPares, pPromedio);

	cout << "El promedio y cantidad de pares usando punteros es: " << promedio << " " << cantPares << endl << endl;

	// el valor debe n y nPuntero no debe de cambiar ya que hemos usado variables auxiliares en las funciones
	cout << n << " " << *nPuntero << endl << endl;

	delete[] pCantPares;
	delete[] pPromedio;

	return 0;
}