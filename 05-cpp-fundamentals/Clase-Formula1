#include <iostream>
#include <cmath> // Para la función pow
#include <conio.h> // para la funcion _getch()
using namespace std;

// Función para calcular el factorial
int factorial(int n) {
    for(int j = 1; j <= n; ++j) {
    
}

// Función para calcular el término según las condiciones dadas
double calcularTermino(int i, double a, double b, int x) {
    if (i % 2 != 0) { // Comprobar si el número de término 'i' es impar
        return pow(-1, i) * pow((a + i),b) / (b + factorial(x));
    } else { // Si el número de término 'i' es par
        return pow(-1, i) *pow((b - i),a) / (b + factorial(x));
    }
}

int main() {
    int i,ii; // Número de término // contador en for
    double a; // Variable 'a'  [2, 4] en la fórmula
    double b; // Variable 'b'  [2, 4] en la fórmula
    int x=1; // Variable 'x'  [1 a 7 y repite] en la fórmula
    double sumaTotal = 0.0; // Suma total 

    cout << "Ingresa el valor de i: "; cin >> i;

    cout << "Ingresa el valor de a: "; cin >> a;
    while (a < 2 || a > 4)
    {   cout << "Valor de a debe estar entre [2,4] solamente\n Vuelva ingresar a por favor: a = \n";
        cin >> a;
    }    
    cout<<"correcto a = " << a << "\n"; 

   cout << "Ingresa el valor de b: "; cin >> b;
   while (b < 2 || b > 4)
    {   cout << "Valor de b debe estar entre [2,4] solamente\n Vuelva ingresar a por favor: a = \n";
        cin >> b;
    }    
    cout<<"correcto b = " << b  << "\n";


    //procedo a calcular la suma de los i terminos
    for (int ii = 1; ii <= i; ++ii) {
      cout<<"termino "<<ii<<": " << calcularTermino(ii, a, b, x)<< " con x = "<<x<<"\n";
      sumaTotal += calcularTermino(ii, a, b, x);
      cout<<"Suma hasta "<<ii<<": "<<sumaTotal<<"\n";_getch();
      x++;
      if(x>7) x=1;
    }

    cout << "El valor de la suma total es: " << sumaTotal;

    return 0;
}
