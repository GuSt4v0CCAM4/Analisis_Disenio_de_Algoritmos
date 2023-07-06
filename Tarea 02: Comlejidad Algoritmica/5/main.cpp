#include <iostream>
using namespace std;

int main() {
    int copia = 0;
    int valor;
    cout << "Ingrese un valor: ";
    cin >> valor;

    for (int i = 0; i <= valor; i++, copia++) {
        copia++;
        if (i % 2 == 0) {
            copia++;
            cout << i << endl;
        }
    }
    copia++;
    for (int i = 0; i <= valor; i++, copia++) {
        copia++;
        if (i % 2 != 0) {
            copia++;
            cout << i << endl;
        }
    }
    copia++;

    cout << "\nConteo: " << copia << endl << endl;
}