#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <conio.h>
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

bool verificar_pared(int **mapa, Pos *pos) {
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

void desplazar_ficha(int **mapa, Ficha &f, Pos dir) {

	// Variable para las nuevas posiciones de la ficha
	Pos newPos[5];
	
	// calcular la nueva posicion con el parametro dir
	for (int i = 0; i < 5; i++) {
		newPos[i].x = f.positions[i].x + dir.x;
		newPos[i].y = f.positions[i].y + dir.y;
	}

	// verificacion
	if (verificar_pared(mapa, newPos)) {

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

	char direccion;

	Pos d;
	_getch();
	while (true) {
		
		if (_kbhit()) {
			direccion = _getch();
			switch (direccion) {
			case 77: 
				d = Pos{ 1, 0 };
				break;
			case 75:
				d = Pos{ -1, 0 };
				break;
			case 72:
				d = Pos{ 0, -1 };
				break;
			case 80:
				d = Pos{ 0, 1 };
				break;
			}
			desplazar_ficha(mapa, f, d);
		}	

	}
	return 0;
}