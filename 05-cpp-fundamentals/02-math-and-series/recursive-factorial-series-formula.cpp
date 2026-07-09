#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

// Función para calcular el factorial
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    else return n * factorial(n - 1);
}

// Función para calcular un término de la serie 
double SerieBinomial(int n, double x) {
    unsigned long long numerator =  pow(-1,n)*factorial(2 * n)*pow(x,n);
    cout<<"numerador = "<<numerator<<"\n";
    unsigned long long denominator = (1-2*n)*pow(factorial(n), 2) * pow(4,n);
    cout<<"\ndenominador = "<<denominator<<"\n";
    return static_cast<double>(numerator) / denominator;
}

// Función para calcular arcsin(x) usando la serie de Taylor
double SumaBinomial(double x, int terms) {
    double sum = 0.0;
    for (int i = 0; i <= terms; ++i) {
        cout<<"\npara n = "<<i<<SerieBinomial(i, x);
        sum += SerieBinomial(i, x);
        cout<<"\
cout<<"\nsuma "<<i<< sum<<"\n";
        _getch();
    }
    return sum;
}

int main() {
    int terms;//  terms es n
    double x;

    // Validar el valor de términos
    do {
        cout << "Ingrese el número de términos (mayor que 1 y mennor que 10): ";
        cin >> terms;
        if (terms < 1 || terms > 10) {
            cout << "Número de términos fuera de rango. Intente nuevamente.\n";
        }
    } while (terms < 1 || terms > 10);

    // Validar el valor de x
    do {
// Validar el valor de x
    do {
        cout << "Ingrese el valor de x (mayor que 0 y menor o igual a 1): ";
        cin >> x;
        if (x <= 0 || x > 1) {
            cout << "Valor de x fuera de rango. Intente nuevamente.\n";
        }
    } while (x <= 0 || x > 1);

    // Calcular y mostrar el valor de arcsin(x)
    double result = SumaBinomial(x, terms);
    cout << "El valor aproximado de arcsin(" << x << ") usando " << terms << " términos es: " << result << endl;

    return 0;
}
