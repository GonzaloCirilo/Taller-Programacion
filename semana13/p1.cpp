#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
 
void Generar_Mensaje(char *men, int nele) {
	
	for (int i = 0; i < nele; i++) {
		men[i] = (char)(rand() % 26 + 'A');
	}
}

void Imprimir_Mensaje(char *men, int nele) {
	for (int i = 0; i < nele; i++) {
		cout << men[i] << " ";
	}
	cout << endl;
}

bool esSW(char *men, int nele) {
	return men[0] == 'S' && men[nele - 1] == 'W';
}

bool esSis(char *men, int nele) {
	char arr[3] = { 'S', 'I', 'S' };
	int cont = 0;
	for (int i = 0; i < nele; i++) {
		if (men[i] == arr[cont]) {
			cont++;
		}
	}
	return cont == 3;
}

int main() {
	srand(time(NULL));
	int cont = 1;
	char *men;
	while (true){
		cout << "MENSAJE : " << cont++ << endl;
		int nele = rand() % 10 + 20;
		men = new char[nele];
		Generar_Mensaje(men, nele);

		Imprimir_Mensaje(men, nele);

		if (esSW(men, nele)) {
			cout << "ES UN ALUMNO DE SOFTWARE" << endl << endl;
		}
		else if (esSis(men, nele)) {
			cout << "ES UN ALUMNO DE SISTEMAS" << endl << endl;
		}
		else {
			cout << "ES UN ALUMNO DE COMINICA " << endl << endl;
		}


		system("pause");
		cout << endl;

	}
	return 0;
}