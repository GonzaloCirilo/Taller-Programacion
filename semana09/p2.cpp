#include <iostream>
using namespace std;

void areaYPerimetro(double *l, double *area, double *perimetro){
    *area = *l * *l;
    *perimetro = *l * 4;
}

int main(){
    double *l = new double;

    do{
        cout << "Ingrese el valor de l: ";
        cin >> *l;
    } while(*l <= 0.0);

    double *pArea = new double, *pPerimetro = new double;

    areaYPerimetro(l, pArea, pPerimetro);

    cout<<"El area y el perimetro es: " << *pArea << " y " << *pPerimetro;

    return 0;
}