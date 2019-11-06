#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Empleado{
    int nombre;
    char sexo;
    int sueldo = 0; // Agregar valor por defecto para la funcion max
};

void Mostrar_datos_empleado(Empleado e){
    cout << "   Sexo: " << e.sexo << endl;
    cout << "   Sueldo: " << e.sueldo << endl;
    cout << endl;
}

void Generar_Datos(int n, Empleado *arr){
    for(int i = 0; i < n; i++){
        Empleado e = Empleado();
        e.nombre = i + 1;
        e.sexo = rand() % 2 == 0 ? 'F' : 'M';
        e.sueldo = rand() % 10000 + 930;
        arr[i] = e;
    }
}

void Mostrar_Datos(int n, Empleado *arr){
    for(int i = 0; i < n; i++){
        cout << "Empleado " << arr[i].nombre << ":" << endl;
        Mostrar_datos_empleado(arr[i]);
    }
}

void Promedio_Sueldo_Mujeres(int n,  Empleado *arr){
    float suma = 0; int cantMujeres = 0;
    for(int i = 0; i < n; i++){
        if(arr[i].sexo == 'F'){
            suma += arr[i].sueldo;
            cantMujeres++;
        }
    }
    cout << "El promedio del sueldo de mujeres es: "<< suma / cantMujeres << endl << endl;
}

void Mayor_Sueldo(int n, Empleado *arr){
    Empleado aux = Empleado(); 
    for(int i = 0; i < n; i++){
        if(arr[i].sueldo > aux.sueldo){
            aux = arr[i];
        }
    }
    cout << "Empleado con mayor sueldo es el numero " << aux.nombre << endl;
    Mostrar_datos_empleado(aux);
}

void Ordenar_por_sueldo(int n, Empleado *arr){
    Empleado *vOrdenado = new Empleado[n];
    vOrdenado = arr;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(vOrdenado[j].sueldo < vOrdenado[i].sueldo){
                Empleado aux = vOrdenado[j];
                vOrdenado[j] = vOrdenado[i];
                vOrdenado[i] = aux;
            }
        }
    } 

    cout << "=======Empleados ordenados=======" << endl << endl;

    Mostrar_Datos(n, vOrdenado);
}


int main(){
    srand(time(NULL));
    int n;
    cout << "Ingrese el numero de empleados: ";
    cin >> n;

    Empleado *vEmpleados = new Empleado[n];

    Generar_Datos(n, vEmpleados);

    Mostrar_Datos(n, vEmpleados);

    Promedio_Sueldo_Mujeres(n, vEmpleados);

    Mayor_Sueldo(n, vEmpleados);

    Ordenar_por_sueldo(n, vEmpleados);

    return 0;
}