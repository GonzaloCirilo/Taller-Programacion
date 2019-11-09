#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int nele = 15;

struct Empleado {
    int codigo = 0;
	int horasT = 0;
	char oficina;
	int minutosT = 0;
};

void generarArr(Empleado *arr) {
	for (int i = 0; i < nele; i++) {
		Empleado e = Empleado();
        e.codigo = i + 1;
		e.horasT = rand() % 30 + 20;
		e.minutosT = rand() % 181;
		int op = rand() % 3;
		switch (op)
		{
		case 0:
			e.oficina = 'C';
			break;
		case 1: 
			e.oficina = 'S';
			break;
		case 2:
			e.oficina = 'L';
			break;
		default:
			break;
		}
		arr[i] = e;
	}
}

void mostrarUnEmpleado(Empleado e, int codigo) {
	cout << "Empleado " << e.codigo << endl;
	cout << "	Horas Trabajadas: " << e.horasT << endl;
	cout << "	Oficina: " << e.oficina << endl;
	cout << "	Minutos tardanza: " << e.minutosT << endl << endl;
}

void imprimeArreglo(Empleado *arr, int n) {
	for (int i = 0; i < n; i++) {
		mostrarUnEmpleado(arr[i], i + 1);
	}
}

void emplMasTrabaj(Empleado *arr) {
	// Primer for para hallar el mayor
	int max = 0;
	for (int i = 0; i < nele; i++) {
		if (arr[i].horasT > max) {
			max = arr[i].horasT;
		}
	}
	// Vemos quienes tienen ese mayor valor
	cout << "Los empleados con mayor numero de trabajo son: ";
	for (int i = 0; i < nele; i++) {
		if (arr[i].horasT == max) {
			cout << i + 1 << " ";
		}
	}
	cout << endl << endl;
}

void promedioTardanzasOfi(Empleado *arr) {
	int contC = 0, contS = 0, contL = 0;
	float sumaC = 0, sumaS = 0, sumaL = 0;
	for (int i = 0; i < nele; i++) {
		switch (arr[i].oficina) {
		case 'C':
			contC++;
			sumaC += arr[i].minutosT;
			break;
		case 'S':
			contS++;
			sumaS += arr[i].minutosT;
			break;
		case 'L':
			contL++;
			sumaL += arr[i].minutosT;
			break;
		}
	}

	cout << "El promedio de Contabilidad es : " << sumaC / contC << endl;
	cout << "El promedio de Sistemas es : " << sumaS / contS << endl;
	cout << "El promedio de Logistica es : " << sumaL / contL << endl << endl;
}

void empleadosPunt(Empleado *arr) {
	cout << "Los empleados puntuales son: ";
	for (int i = 0; i < nele; i++) {
		if (arr[i].minutosT == 0) {
			cout << i << " ";
		}
	}
	cout << endl << endl;
}

void ordenarArr(Empleado *arr) {
    Empleado *vOrdenado = new Empleado[nele];
    vOrdenado = arr;
	// Primero Ordenar el arreglo

    for(int i = 0; i < nele; i++){
        for(int j = i + 1; j < nele; j++){
            if(vOrdenado[j].horasT > vOrdenado[i].horasT){
                Empleado aux = vOrdenado[j];
                vOrdenado[j] = vOrdenado[i];
                vOrdenado[i] = aux;
            }
        }
    }
    // Creas 3 arreglos auxiliares y un contador para cada arreglo
    int contC = 0, contS = 0, contL = 0;
    Empleado *arrC = new Empleado[nele], *arrS = new Empleado[nele], *arrL = new Empleado[nele]; 
	
	for (int i = 0; i < nele; i++) {
		switch (arr[i].oficina) { // distribuir los empleados segun su oficina
		case 'C':
			arrC[contC++] =  vOrdenado[i];
			break;
		case 'S':
			arrS[contS++] =  vOrdenado[i];
			break;
		case 'L':
			arrL[contL++] =  vOrdenado[i];
			break;
		}
	}

	//mostrar cada uno de los arreglos con la funcion
    cout << "=================== Empleados ordenados por horas de trabajo y oficina ===================" << endl;
    cout << "CONTABILIDAD" << endl;
    imprimeArreglo(arrC, contC);
    cout << "SISTEMAS" << endl;
    imprimeArreglo(arrS, contS);
    cout << "LOGISTICA" << endl;
    imprimeArreglo(arrL, contL);
}

int main() {
	Empleado *arr = new Empleado[15];

	generarArr(arr);

	imprimeArreglo(arr, nele);
	
	emplMasTrabaj(arr);

	promedioTardanzasOfi(arr);

	empleadosPunt(arr);

	ordenarArr(arr);

	return 0;
}