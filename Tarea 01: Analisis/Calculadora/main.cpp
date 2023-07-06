#include <iostream>
#include <cmath>

using namespace std;

typedef double (*Ptr_operation)(double, double); // Definición del tipo de puntero a función

// Definición de las funciones
double suma(double a, double b) {
    return a + b;
}

double resta(double a, double b) {
    return a - b;
}

double multiplicacion(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    return a / b;
}

double potencia(double a, double b) {
    return pow(a, b);
}

double radicacion(double a, double b) {
    return pow(a, 1 / b);
}

int main() {
    double a, b, resultado;
    int opc;
    Ptr_operation vector_operaciones[6] = {&suma, &resta, &multiplicacion, &division, &potencia, &radicacion};
    // Se declara un array de punteros a funciones

    cout << "Ingrese dos números: ";
    cin >> a >> b;
    cout << "Opcion: ";
    cin >> opc;

    resultado = (*vector_operaciones[opc])(a, b);
    // Se llama a la función correspondiente según la opción elegida

    cout << "El resultado es: " << resultado;
    return 0;
}

