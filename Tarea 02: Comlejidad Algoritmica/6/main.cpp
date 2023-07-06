#include <iostream>
using namespace std;

int main()
{
    int copia = 0;
    int numero;
    cout << "Ingrese un número: ", cin >> numero;

    int contador = 1; copia++;
    while (contador < numero)
    {
        copia++;
        copia++; cout << contador << endl;
        copia++; contador *= 2;
    }
    copia++;
    cout << "\nCopia: " << copia << endl << endl;
}

