#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	//Primero declaramos variables:
	int signo;
	float termino; // determinar el signo en cada termino
	float sumatoria; // variable respuesta
	int contadordenominador;
	int N, x, a;
	//incializamos las variables:
	signo = (-1);
	sumatoria = 0;
	contadordenominador = 1;
	//Pedimos las variables que nos faltan:
	do {
		cout << "Ingrese N: ";
		cin >> N;
	} while (N > 20 || N < 0); //Pedimos y validamos N, el numero de terminos

	cout << "ingrese x: ";
	cin >> x;//Pedimos X, y no lo validamos porque X puede tomar cualquier valor

	do {
		cout << "Ingrese a: ";
		cin >> a;
	} while (a == 0);//Pedimos y validamos que a no sea 0
	// Calculo de la serie
	for (int i = 1; i <= N; i++) {
		float numerador = ((i + 1)*(pow(x, i)));
		float denomiador = (contadordenominador*a);
		
		//Comenzamos con el ciclo repetitivo, el cual nos va ir sacando cada termino
		termino =  numerador/denomiador;//Hallamos el termino
		// Actualizando los valores para las siguientes iteraciones
		termino = termino * signo;//le aplicamos el signo multiplicando por -1
		sumatoria = sumatoria + termino;//Y los vamos acumulando dentro de la variable sumatoria
		signo = signo * (-1);//alternamos el signo para el siguiente termino
		contadordenominador += 2;//Aumentamos el denominador en 2, también para el siguiente termino
	}
	// Mostramos resultado
	cout << "Resultado de la serie: " << sumatoria << endl;//imprimimos el resultado
	system("pause");
	return 0;
}