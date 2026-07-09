#include <iostream>

using namespace std;

int main() {
    int num;

    cout << "Ingrese el numero de tabla que desea ver:" << endl;
    cin >> num;

    cout << "La tabla de " << num << " es:" << endl;

    for (int i = 1; i <= 10; ++i) {
        cout << num << " x " << i << " = " << (num * i) << endl;
    }

    return 0;
}
