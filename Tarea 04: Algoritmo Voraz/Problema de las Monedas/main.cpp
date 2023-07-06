#include <iostream>

using namespace std;

class CambioMonedas {
private:
    int* denominaciones;
    int n;
    const int INF = 1e9; // Valor que representa la ausencia de solución

public:
    CambioMonedas(int* valores, int cantidad) {
        denominaciones = valores;
        n = cantidad;
    }

    int* cambioMonedas(int monto) {
        int* solucion = new int[monto + 1];
        int* combinacion = new int[monto];

        for (int i = 0; i <= monto; i++) {
            solucion[i] = INF;
        }

        solucion[0] = 0;

        for (int i = 1; i <= monto; i++) {
            for (int j = 0; j < n; j++) {
                if (denominaciones[j] <= i) {
                    int subproblema = solucion[i - denominaciones[j]];
                    if (subproblema != INF && subproblema + 1 < solucion[i]) {
                        solucion[i] = subproblema + 1;
                    }
                }
            }
        }

        int montoActual = monto;
        int idx = 0;
        while (montoActual > 0) {
            for (int j = 0; j < n; j++) {
                if (denominaciones[j] <= montoActual && solucion[montoActual - denominaciones[j]] == solucion[montoActual] - 1) {
                    combinacion[idx] = denominaciones[j];
                    montoActual -= denominaciones[j];
                    idx++;
                    break;
                }
            }
        }

        delete[] solucion;
        return combinacion;
    }
};

int main() {
    int denominaciones[] = {100, 90, 1};
    int cantidadDenominaciones = sizeof(denominaciones) / sizeof(denominaciones[0]);
    int monto = 180;

    CambioMonedas cambio(denominaciones, cantidadDenominaciones);
    int* combinacion = cambio.cambioMonedas(monto);

    cout << "Combinación de monedas para el monto " << monto << ":" << endl;
    for (int i = 0; i < monto; i++) {
        cout << combinacion[i] << " ";
    }
    cout << endl;

    delete[] combinacion;

    return 0;
}

