#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int nele = 15;

struct Docente
{
    int codigo;
    int horas;
    char facultad;
    int minutosT;
};

void genera_arreglo(Docente *arr){
    for(int i = 0; i < nele; i++){
        Docente d = Docente();
        d.codigo = i + 1;
        d.horas = rand() % 37 + 4;
        d.minutosT = rand() % 251;
        int fac = rand() % 3;
        switch(fac){
            case 0:
                d.facultad = 'P';
                break;
            case 1:
                d.facultad = 'I';
                break;
            case 2:
                d.facultad = 'A';
        }
        arr[i] = d;
    }
}

// Funcion auxiliar para imprimir un solo Docente
void imprime_docente(Docente d){
    cout << "Docente " << d.codigo <<":" <<endl;
    cout << "Horas asignadas: " << d.horas << endl;
    cout << "Facultad: " << d.facultad << endl;
    cout << "Minutos de Tardanzas: " << d.minutosT << endl << endl;
}

void imprime_arreglo(Docente *arr){
    cout << "=========DOCENTES=========" << endl << endl;
    for(int i = 0; i < nele; i++){
        imprime_docente(arr[i]);
    }
}

void facultad_con_mas_tardanzas(Docente *arr){
    // guardamos el valor de tardanzas en un arreglo.
    // el posicion 0 es Periodismo, 1 es Ingenieria y 2 es Administracion
    int tardanzas[3] = {};
    for(int i = 0; i < nele; i++){
        switch(arr[i].facultad){
            case 'P':// es periodismo entonces lo sumamos a la posicion 0
                tardanzas[0] += arr[i].minutosT;
                break;
            case 'I':// es ingenieria entonces lo sumamos a la posicion 1
                tardanzas[1] += arr[i].minutosT;
                break;
            case 'A': // es admin entonces lo sumamos a la posicion 2
                tardanzas[2] += arr[i].minutosT;
                break;
        }
    }

    // finalmente recorremos tardanzas para ver cual es el mayor valor
    int mayor = 0;

    for(int i = 0; i < 3; i++){
        if(mayor < tardanzas[i])
            mayor = tardanzas[i];
    }
    cout << "Las facultades con mayor minutos de tardanza son : ";
    for(int i = 0; i < 3; i++){
        if(mayor == tardanzas[i]){
            switch(i){
                case 0:
                    cout << "P ";
                    break;
                case 1:
                    cout << "I ";
                    break;
                case 2:
                    cout << "A";
                    break;
            }
        }
            
    }
    cout << endl << endl;
}

void promedio_de_horas_x_facultad(Docente *arr){
    // guardamos el valor de las horas en un arreglo y la cantidad de docentes
    // el posicion 0 es Periodismo, 1 es Ingenieria y 2 es Administracion
    int horas[3] = {}, nDocentes[3] = {};
    for(int i = 0; i < nele; i++){
        switch(arr[i].facultad){
            case 'P':// es periodismo entonces lo sumamos a la posicion 0
                horas[0] += arr[i].horas;
                nDocentes[0]++;
                break;
            case 'I':// es ingenieria entonces lo sumamos a la posicion 1
                horas[1] += arr[i].horas;
                nDocentes[1]++;
                break;
            case 'A': // es admin entonces lo sumamos a la posicion 2
                horas[2] += arr[i].horas;
                nDocentes[2]++;
                break;
        }
    }

    cout << "Promedio por Facultad:" << endl << endl;
    cout << "Periodismo: " << (double)horas[0]/nDocentes[0] << endl;
    cout << "Ingenieria: " << (double)horas[1]/nDocentes[1] << endl;
    cout << "Administracion: " << (double)horas[2]/nDocentes[2] << endl << endl;
}

void docentes_puntuales(Docente *arr){
    cout << "Docentes puntuales: " << endl << endl;
    int cont = 0;
    for(int i = 0; i < nele; i++){
        // verificamos quienes no tienen minutos tarde
        if(arr[i].minutosT == 0){
            cont++;
            imprime_docente(arr[i]);
        }
    }

    if(cont == 0) 
        cout << "No hay docentes puntuales" << endl << endl;
}

void ordena_arreglo(Docente *arr){
    Docente *arrOrdenado = arr;
    // Ordenamiento burbuja
    for(int i = 0; i < nele; i++){
        for(int  j = i + 1; j < nele; j++){
            if(arrOrdenado[i].facultad > arrOrdenado[j].facultad){// si es mayor por facultad
                Docente aux = arrOrdenado[i];
                arrOrdenado[i] = arrOrdenado[j];
                arrOrdenado[j] = aux;
            }else{
                if(arrOrdenado[i].facultad == arrOrdenado[j].facultad) { // si son iguales
                    if(arrOrdenado[i].minutosT < arrOrdenado[j].minutosT){// ordenar por tardanza
                        Docente aux = arrOrdenado[i];
                        arrOrdenado[i] = arrOrdenado[j];
                        arrOrdenado[j] = aux;
                    }
                }
            }
        }
    }
    
    imprime_arreglo(arrOrdenado);
}

int main(){
    srand(time_t(NULL));

    Docente *arrDocente = new Docente[15];

    genera_arreglo(arrDocente);

    imprime_arreglo(arrDocente);

    facultad_con_mas_tardanzas(arrDocente);

    promedio_de_horas_x_facultad(arrDocente);

    docentes_puntuales(arrDocente);

    ordena_arreglo(arrDocente);

    return 0;
}