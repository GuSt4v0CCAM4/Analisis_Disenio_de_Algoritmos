#include <iostream>

using namespace std;

class Potencia {
private:
    double base;
    int exponente;

public:
    Potencia(double b, int e) {
        base = b;
        exponente = e;
    }

    double calcular() {
        if (exponente == 0) {
            return 1;
        } else if (exponente % 2 == 0) {
            double temp = Potencia(base, exponente / 2).calcular();
            return temp * temp;
        } else {
            double temp = Potencia(base, exponente / 2).calcular();
            return base * temp * temp;
        }
    }
};

int main() {
    double base;
    int exponente;

    cout << "Ingrese la base: ";
    cin >> base;

    cout << "Ingrese el exponente: ";
    cin >> exponente;

    Potencia potencia(base, exponente);
    double resultado = potencia.calcular();

    cout << "El resultado es: " << resultado << endl;

    return 0;
}
