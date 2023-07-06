#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int count = 0;

    int input;
    cout << "Ingrese un número: ";
    cin >> input;

    for (int i = 0; i <= input; i++, count++)
    {
        int j = 1;
        count++;
        while (j < input)
        {
            count++;
            cout << j << endl;
            count++;
            j *= 2;
            count++;
        }
        count++;
    }
    count++;
    cout << "\nConteo: " << count << endl << endl;
}
