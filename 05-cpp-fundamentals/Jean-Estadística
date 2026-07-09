#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

int numeroaleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

void MayoraMenor(const vector<int>& datos) {
    vector<int> copia = datos;  // Hacer una copia para no modificar el original
    sort(copia.begin(), copia.end(), greater<int>());
    cout << "\nOrdenado de mayor a menor: ";
    for (int num : copia) {
        cout << num << " ";
    }
}

void MenoraMayor(const vector<int>& datos) {
    vector<int> copia = datos;  // Hacer una copia para no modificar el original
    sort(copia.begin(), copia.end());
    cout << "\nOrdenado de menor a mayor: ";
    for (int num : copia) {
        cout << num << " ";
    }
}

void Maximo(vector<int>& datos) {
    int max = 0;
    for (int num : datos) {
        if (max < num) {
            max = num;
        }
    }
    cout << "\nEl numero maximo es: " << max;
}
void Minimo(vector<int>& datos) {
    int min = datos[0];
    for (int num : datos) {
        if (min > num) {
            min = num;
        }
    }
    cout << "\nEl numero minimo es: " << min;
}

void Moda(const vector<int>& datos) {
    unordered_map<int, int> contador;

    // Contar la frecuencia de cada valor en el arreglo
    for (int num : datos) {
        contador[num]++;
    }

    int votos = 0;
    int Moda = 0;

    // Encontrar el valor con la mayor frecuencia (la moda)
    for (auto& pair : contador) {
        if (pair.second > votos) {
            votos = pair.second;
            Moda = pair.first;
        }
    }

    cout << "\nLa moda es: " << Moda << " con " << votos << " apariciones";
}

void Mediana(const vector<int>& datos) {
    vector<int> copia = datos;  // Hacer una copia para no modificar el original

    sort(copia.begin(), copia.end());

    double mediana;
    int n = copia.size();
    if (n % 2 == 0) {
        mediana = (copia[n / 2 - 1] + copia[n / 2]) / 2.0;
    }
    else {
        mediana = copia[n / 2];
    }
    cout << "\nLa mediana es: " << mediana;
}

void Promedio(const vector<int>& datos) {
    if (datos.empty()) {
        cout << "No puede calcularse el promedio de un arreglo vacio\n";
        return;
    }

    double suma = 0;
    double promedio;
    for (int num : datos) {
        suma += num;
    }
    promedio = suma / datos.size();
    cout << "\nEl promedio es: " << promedio;
}

void BuscarIndice(const vector<int>& datos) {
    int indice;
    do {
        cout << "\nIngrese que indice buscar (entre 1 y " << datos.size() << "): ";
        cin >> indice;
    } while (indice < 0 || indice > datos.size());

    cout << "El indice " << indice << " tiene valor: " << datos[indice-1];
}

void EliminarIndice(vector<int>& datos) {
    int indice;
    do {
        cout << "\nIngrese que indice eliminar (entre 1 y " << datos.size() << "): ";
        cin >> indice;
    } while (indice < 1 || indice > datos.size());
    int indice_vector = indice - 1;
    datos.erase(datos.begin() + indice_vector);

    cout << "Elemento eliminado correctamente.";
    cout << "\nLos elementos despues de la eliminacion: ";
    for (int num : datos) {
        cout << num << " ";
    }
}

void Sumatoria(vector<int>& datos) {
    int suma = 0;
    for (int i : datos) {
        suma += i;
    }
    cout << "\nLa sumatoria de todos los elementos es: " << suma;
}

void Rango(const vector<int>& datos) {
    int min = *min_element(datos.begin(), datos.end());
    int max = *max_element(datos.begin(), datos.end());
    int rango = max - min;
    cout << "\nEl rango de los elementos es: " << rango << endl;
}
void Frecuencia(const vector<int>& datos) {
    unordered_map<int, int> frecuencia;
    for (int num : datos) {
        frecuencia[num]++;
    }
    vector<int> keys;
    for (const auto& pair : frecuencia) {
        keys.push_back(pair.first);
    }
    sort(keys.begin(), keys.end());
    cout << "\nFrecuencia de los numeros:\n";
    for (int key : keys) {
        cout << key << ": " << frecuencia[key] << " veces\n";
    }
}
string int_to_string(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

void Agrupacion(const vector<int>& datos) {
    vector<int> copia = datos;
    sort(copia.begin(), copia.end());

    int n = copia.size();
    int groupSize = n / 4;
    int remainder = n % 4;

    unordered_map<string, vector<int>> grupos;
    int start = 0;

    for (int i = 0; i < 4; ++i) {
        int currentGroupSize = groupSize + (remainder > 0 ? 1 : 0);
        remainder--;

        string groupName = "Grupo " + int_to_string(i + 1);
        for (int j = start; j < start + currentGroupSize; ++j) {
            grupos[groupName].push_back(copia[j]);
        }
        start += currentGroupSize;
    }

    cout << "\nAgrupacion de los numeros:\n";
    for (const auto& pair : grupos) {
        cout << pair.first << ": ";
        for (int num : pair.second) {
            cout << num << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    int min, max;
    do {
        cout << "Ingrese el tamano del arreglo (entre 1 y 100):\n";
        cin >> n;
    } while (n > 100 || n < 0);

    cout << "Ingrese el rango de elementos (minimo): ";
    cin >> min;

    do {
        cout << "Ingrese el rango de elementos (maximo): ";
        cin >> max;
    } while (max < min);


    vector<int> datos(n);
    cout << "Los datos del arreglo son: ";
    for (int i = 0; i < n; ++i) {
        datos[i] = numeroaleatorio(min, max);
        cout << datos[i] << " ";
    }

    MayoraMenor(datos);
    MenoraMayor(datos);
    Maximo(datos);
    Minimo(datos);
    Moda(datos);
    Mediana(datos);
    Promedio(datos);
    BuscarIndice(datos);
    EliminarIndice(datos);
    Sumatoria(datos);
    Rango(datos);
    Frecuencia(datos);
    Agrupacion(datos);

    return 0;
}
