#include <iostream>
using namespace std;

int main() {
    int arr[5];
    int max, min;
    
    cout << "Ingrese 5 numeros:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    
    max = arr[0];
    min = arr[0];
    
    for (int i = 1; i < 5; i++) {  // Comenzar en 1 ya que 0 ya está considerado
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    cout << "El numero menor es " << min << endl;
    cout << "El numero mayor es " << max << endl;

    return 0;
}
