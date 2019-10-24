#include <iostream> 
#include <math.h>
using namespace std;

void Area_Volumen(float r, float h, float *area, float *volumen){
    // g es calculado por el teorema de pitagoras
    float g = sqrt(h * h + r * r);
    float pi = 3.14159;
    *area = pi * r * g + pi * r * r;
    *volumen = (1/3) * pi * r * r * h;
}

int main(){

    float r, h;

    do {
        cout << "Ingrese el valor de r: ";
        cin >> r;
    } while (r <= 0);

    do {
        cout << "Ingrese el valor de h: ";
        cin >> h;
    } while (h <= 0);

    float *a, *v;

    Area_Volumen(r, h, a, v);

    cout << "El area del cono es: " << a << endl;
    cout << "El volumen del cono es: " << v << endl; 

    return 0;
}