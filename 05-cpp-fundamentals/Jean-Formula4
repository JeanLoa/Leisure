#include <iostream>
#include <cmath>

using namespace std;

float x;
int n;

int factorial(int n) {
    int factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    return factorial;
}
double arcsen(float x, int n) {
    double suma = 0.0;
    for (int i = 0; i <= n; ++i) {
        suma += factorial(2 * i) / (pow(4, i) * pow(factorial(i), 2) * (2 * i + 1)) * pow(x, 2 * i + 1);
    }
    return suma;
}

int main() {

    // Solicitar valores para x y n
    cout << "Ingresa el valor de x (0 < x <= 1): " << endl;
    cin >> x;
    while (0 >= x || x > 1) {
        cout << "Ingrese el valor de x (0 < x < 1): " << endl;
        cin >> x;
    }

    cout << "Ingresa el numero de terminos (1 < n < 10): " << endl;
    cin >> n;
    while (1 >= n || n >= 10) {
        cout << "Ingrese el valor de n adecuado (1 < n < 10): " << endl;
        cin >> n;
    }

    cout << "El valor de arcoseno es: " << arcsen(x, n) << endl;

    return 0;
}
