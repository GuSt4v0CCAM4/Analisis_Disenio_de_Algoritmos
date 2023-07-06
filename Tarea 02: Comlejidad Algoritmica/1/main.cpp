#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int counter = 0;

    int num;
    cout << "Ingrese un número: ";
    cin >> num;

    for (int i = 0; i <= num; i++, counter++) // n+2
    {
        if (i % 2 == 0)
        {
            cout << "Número par encontrado: " << i << endl;
            counter += 2;
        }
    }
    counter++;
    // Complejidad: O(n)
    cout << "\nContador: " << counter << endl << endl;
}

