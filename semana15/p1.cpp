#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <Windows.h>

using namespace std;
using namespace System;


struct Pos {
	int x, y;
};

struct Ficha {
	// Por default las posiciones del pdf
	Pos positions[5] = { Pos{11, 8}, Pos{10 , 8}, Pos{9, 9}, Pos{10, 9}, Pos{11, 9} };
	// Direccion {1,0} hacia la derecha, {-1, 0} hacia la izquierda, {0,1} hacia abajo, {0, -1} hacia la arriba
	Pos dir[4] = { Pos{1, 0}, Pos{-1, 0}, Pos{0, 1}, Pos{0, -1} };
	// indice de la direccion de la ficha
	int currentDir = 0;
};

/*
 * 0 significa casillero vacio
 * 1 significa pared
 * 2 personaje
 */
void genera_muestra_matriz(int **mapa) {
	int _mapa[20][20] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 1, 1, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			mapa[i][j] = _mapa[i][j];
		}
	}
}

bool verificar_pared(int **mapa, Pos *pos, Ficha f) {
	// Calculamos la nueva posicion
	for (int i = 0; i < 5; i++) {
		pos[i].x = f.positions[i].x + f.dir[f.currentDir].x;
		pos[i].y = f.positions[i].y + f.dir[f.currentDir].y;
	}
	// verificamos si la ficha choca con una pared
	for (int i = 0; i < 5; i++) {
		int x = pos[i].x, y = pos[i].y;
		if (mapa[y][x] == 1) {
			return false;
		}
	}
	return true;
}

void printInPosition(Pos p, char c) {

	// No se como hacen para dibujar en una posicion pero esta es otra manera de hacerlo
	COORD coord;
	coord.X = p.x;
	coord.Y = p.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	// se imprime el caracter deseado
	cout << c;
}

void desplazar_ficha(int **mapa, Ficha &f) {

	//Le damos una probabilidad de 30% de que cambie de direccion
	if (rand() % 100 > 70) {
		int aux = rand() % 3 + 1;
		f.currentDir = (f.currentDir + aux) % 4;
	}

	// Variable para las nuevas posiciones de la ficha
	Pos *newPos = new Pos[5];
	
	// verificamos si es valida la nueva posicion
	while (!verificar_pared(mapa, newPos, f)) { // mientras la ficha no este en una posicion valida no podemos despintar/pintar
		int aux = rand() % 3 + 1;
		f.currentDir = (f.currentDir + aux) % 4;
	}

	//despintamos del mapa la ficha
	for (int i = 0; i < 5; i++) {
		int x = f.positions[i].x, y = f.positions[i].y;
		mapa[y][x] = 0;
		printInPosition(f.positions[i], ' ');
	}
	// actualizamos la posicion de la ficha
	for (int i = 0; i < 5; i++) {
		f.positions[i] = newPos[i];
	}
	// pintamos en el nuevo lugar
	for (int i = 0; i < 5; i++) {
		int x = f.positions[i].x, y = f.positions[i].y;
		mapa[y][x] = 2;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		printInPosition(f.positions[i], (char)219);
	}	
}

void pintar_mapa(int **mapa) {
	system("cls");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			switch (mapa[i][j]) {
			case 0:
				cout << ' ';
				break;
			case 1:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
				cout << (char)219;
				break;
			case 2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
				cout << (char)219;
				break;
			}
		}
		cout << endl;
	}
}

int main() {
	srand(time_t(NULL));

	int **mapa = new int*[20];
	for (int i = 0; i < 20; i++) {
		mapa[i] = new int[20];
	}
	Ficha f = Ficha();
	genera_muestra_matriz(mapa);

	pintar_mapa(mapa);

	while (true) {
		desplazar_ficha(mapa, f);
		Sleep(500);
	}


	return 0;
}