#include <iostream>

using namespace std;

bool esCapicua(long long n){
    long long aux = 0, temp = n;
    while (temp > 0){
        aux *= 10;
        aux += temp % 10;
        temp /= 10;
    }
    return n == aux;
}

int main(){
    long long n;
    int leidos = 0, capicua = 0;
    do{
        cout << "Ingrese un numero: ";
        cin >> n;
        if(n > 0){
            if(esCapicua(n)){
                capicua++;
            }        
            leidos++;
        }
        
    } while(n > 0);
    cout << "Numeros Leidos = " << leidos << endl;
    cout << "Cantidad de capicuas= " << capicua << endl;
    return 0;
}