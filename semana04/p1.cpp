#include <iostream>
using namespace std;
int main()
{
	int ubicacion, llamada;
	cout << "Ingrese la ubicación: ";
	cin >> ubicacion;

	if (ubicacion < 0 || ubicacion > 1) {
		cout << "Error en el tipo de ubicación " << endl;
		system("pause");
		return 0;
	}

	cout << "Ingrese la hora de la llamada: ";
	cin >> llamada;

	if ((llamada < 0 || llamada >= 2400) || (llamada % 100) >= 60) {
		cout << "Error en la hora de la llamada " << endl;
		system("pause");
		return 0;
	}

	int e = 0;

	if (ubicacion == 1) {
		e += 2000;
	}
	else if(ubicacion == 0) {
		e += 1000;
	}

	if (llamada >= 0 && llamada <= 600) {
		e += 500;
	}
	else if (llamada > 600 && llamada <= 1200) {
		e += 200;
	}
	else if (llamada > 1200 && llamada <= 1800) {
		e += 300;
	}
	else if (llamada > 1800 && llamada < 2400) {
		e += 400;
	}

	// Mostrar accion
	if (e >= 1000 && e < 1500) {
		cout << "POSIBLE RESCATE" << endl;
	}
	else if (e >= 1500 && e < 1800) {
		cout << "RESCATE EN ALERTA AMARILLA" << endl;
	}
	else if (e >= 1800 && e < 2200) {
		cout << "RESCATE EN ALERTA ROJA" << endl;
	}
	else {
		cout << "RESCATE INMINENTE" << endl;
	}



}