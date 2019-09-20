#include <iostream>
using namespace std;
int main(){
    char marca, sist;
    float precio;
    do{
        cout << "Marca (M: Mabe; L: LG; C: Coldex): ";
        cin >> marca;
    } while(marca != 'M' && marca != 'L' && marca != 'C');

    do{
        cout << "Sistema de enfriamiento (F: Auto Frost; N: No Frost): ";
        cin >> sist;
    } while(sist != 'F' && sist != 'N');

    switch (marca) {
    case 'M':
        if(sist == 'F'){
            precio = 895.9;
        }else{
            precio = 1250;
        }
        break;
    case 'L':
        if(sist == 'F'){
            precio = 975;
        }else{
            precio = 1650;
        }
        break;
    case 'C':
        if(sist == 'F'){
            precio = 937.7;
        }else{
            precio = 1379;
        }
        break;
    }
    
    cout << "Monto a pagar: " << precio << endl;
    return 0;
}