#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <Windows.h>

const double PI = 3.14159;
using namespace std;

struct Position {
	int x = 0, y = 0;
};

struct EnemingoCircular {
	int points = 16;
	Position *arrPos = new Position[points];
	Position center = Position();

	// el indice nos ayudara a recorrer todas las posiciones del circulo
	int index = 0;

	// para saber si esta en la vista
	bool spawned = false;
	
	int color = 0;
};

/**
 * parameters:
 * points = Cuantos puntos quiero que tenga el movimiento circular
 * r = radio del circulo
 * arr = arreglo con las posiciones del movimiento circular
 * center = Punto medio del circulo
 */
void generateCicularPoints(int points, double r, Position *arr, Position center) {
	// calcular el ancho del angulo de cada seccion
	double section = 2 * PI / points;
	for (int i = 0; i < points; i++) {
		// calular el angulo para esta posicion
		double angle = section * i;
		// Crear la nueva posicion
		Position p = Position();
		p.x = (int)(center.x + r * cos(angle));
		p.y = (int)(center.y + r * sin(angle));
		// Agregar la nueva posicion al arreglo
		arr[i] = p;
	}
}

void printInPosition(Position p, char c) {

	// No se como hacen para dibujar en una posicion pero esta es otra manera de hacerlo
	COORD coord;
	coord.X = p.x;
	coord.Y = p.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	// se imprime el caracter deseado
	cout << c;
}

int main() {
	srand(time(NULL));

	/**
	 * definir el movimiento de preferncia poner un numero para para el parametro pints
	 */

	EnemingoCircular *arrE = new EnemingoCircular[5];

	for (int i = 0; i < 5; i++) {
		EnemingoCircular ec = EnemingoCircular();
		Position center = Position();
		center.x = rand() % 50 + 20;
		center.y = rand() % 10+ 10;
		ec.center = center;
		ec.color = i + 1;
		generateCicularPoints(ec.points, 9, ec.arrPos, ec.center);
		arrE[i] = ec;
	}

	// Para aparecer nuevos enemigos
	int cont = 0;


	// Cada cuanto tiempo aparece
	int spawntime = 3;
	
	while (true) {
		for (int i = 0; i < 5; i++) {
			if (arrE[i].spawned) {

				// Dibujar del color definido
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), arrE[i].color);
				// Dibujamos el centro
				printInPosition(arrE[i].center, '*');

				printInPosition(arrE[i].arrPos[arrE[i].index++], char(1));

				// cuando el indice sea el valor de points debe regresar al inicio del arreglo
				arrE[i].index %= arrE[i].points;
			}			
		}

		spawntime--;
		if (spawntime == 0) {
			spawntime = 3;
			if(cont < 5)
				arrE[cont++].spawned = true;
		}
		
	
		Sleep(1000);
		system("cls");
	}
	return 0;
}
