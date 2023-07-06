#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int counter = 0;
    string inputA;
    string inputB;

    cout << "Ingrese la cadena A: ";
    cin >> inputA;

    cout << "Ingrese la cadena B: ";
    cin >> inputB;

    for (int i = 0; i < inputA.size(); i++, counter++) // A+1
    {
        for (int j = 0; j < inputB.size(); j++, counter++) // A*(B+1) = A*B + A
        {
            cout << "Carácter A: " << inputA[i] << ", Carácter B: " << inputB[j] << endl;
            counter++; // (A*B)
        }
        counter++;
    }
    counter++;
    // Complejidad: O(A*B)
    cout << "\nNúmero de operaciones: " << counter << endl << endl;
}

