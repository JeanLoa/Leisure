#include <iostream>

using namespace std;

int main() {
    int lado;
    cout << "Ingrese la medida del cuadrado:" << endl;
    cin >> lado;

    for (int i = 1; i <= lado; ++i) {
        for (int j = 1; j <= lado; ++j) {
            if (i == 1 || i == lado || j == 1 || j == lado) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
