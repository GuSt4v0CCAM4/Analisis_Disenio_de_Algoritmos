#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int contador = 0;

    int limite;
    cout << "Ingrese el límite: ";
    cin >> limite;

    for (int i = 0; i <= limite; i++, contador++) // Iteración externa
    {
        for (int j = i; j <= limite; j++, contador++) // Iteración interna
        {
            cout << "Valor i: " << i << ", Valor j: " << j << endl;
            contador++; // Incrementar contador
        }
        contador++; // Incrementar contador
    }
    contador++; // Incrementar contador

    cout << "\nConteo: " << contador << endl << endl;
    // Verificación del conteo
}
