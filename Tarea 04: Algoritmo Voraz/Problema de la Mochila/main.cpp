#include <iostream>
#include <algorithm>

using namespace std;

class Objeto {
public:
    int peso;
    int beneficio;

    Objeto(int p, int b) : peso(p), beneficio(b) {}
};

class Mochila {
private:
    int capacidad;
    Objeto** objetos;
    int numObjetos;

public:
    Mochila(int cap, int num) : capacidad(cap), numObjetos(num) {
        objetos = new Objeto*[numObjetos]; //arreglo de punteros a objetos
    }

    void agregarObjeto(int index, int peso, int beneficio) {
        objetos[index] = new Objeto(peso, beneficio);
    }

    double* resolver() {
        double* fracciones = new double[numObjetos];
        int* indices = new int[numObjetos];
        for (int i = 0; i < numObjetos; ++i) {
            indices[i] = i;
        }

        sort(indices, indices + numObjetos, [this](int a, int b) {
            return static_cast<double>(objetos[a]->beneficio) / objetos[a]->peso >
                   static_cast<double>(objetos[b]->beneficio) / objetos[b]->peso;
        });

        int pesoActual = 0;
        for (int i = 0; i < numObjetos; ++i) {
            int indiceActual = indices[i];
            if (pesoActual + objetos[indiceActual]->peso <= capacidad) {
                fracciones[indiceActual] = 1.0;
                pesoActual += objetos[indiceActual]->peso;
            } else {
                fracciones[indiceActual] = static_cast<double>(capacidad - pesoActual) / objetos[indiceActual]->peso;
                break;
            }
        }

        delete[] indices;
        return fracciones;
    }

    ~Mochila() {
        for (int i = 0; i < numObjetos; ++i) {
            delete objetos[i];
        }
        delete[] objetos;
    }
};

int main() {
    int capacidad = 20;
    int numObjetos = 3;

    Mochila mochila(capacidad, numObjetos);

    mochila.agregarObjeto(0, 18, 25);
    mochila.agregarObjeto(1, 15, 24);
    mochila.agregarObjeto(2, 10, 15);

    double* solucion = mochila.resolver();

    cout << "La Mejor Solucion, representado la parte fraccionaria de cada objeto:" << endl;
    for (int i = 0; i < numObjetos; ++i) {
        cout << "Objeto " << i + 1 << ": " << solucion[i] << endl;
    }

    delete[] solucion;

    return 0;
}
