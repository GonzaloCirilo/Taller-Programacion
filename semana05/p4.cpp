#include <iostream>

using namespace std;

int main(){
    int n;
    long long suma = 0;
    do
    {
        cout << "Ingrese un numero natural: ";
        cin >> n;
    } while (n <= 0);


    for(int i = 0; i <= n; i++){
        suma += i * i;
    }

    cout << "La suma es: " << suma;
    
    return 0;
}