#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Tareas {
public:
    int beneficio;
    int plazo;

    Tareas(int b, int t) : beneficio(b), plazo(t) {}
};

class Planificador {
private:
    int numTareas;
    Tareas** tareas;

public:
    Planificador(int n) : numTareas(n) {
        tareas = new Tareas*[numTareas];
    }

    void agregarTarea(int index, int beneficio, int plazo) {
        tareas[index] = new Tareas(beneficio, plazo);
    }

    static bool compararBeneficio(const Tareas* t1, const Tareas* t2) {
        return t1->beneficio > t2->beneficio;
    }

    void ordenarTareas() {
        sort(tareas, tareas + numTareas, compararBeneficio);

        vector<Tareas*> tareasAsignadas(numTareas, nullptr);
        vector<bool> tiempoUsado(numTareas, false);

        for (int i = 0; i < numTareas; i++) {
            int tiempo = min(tareas[i]->plazo, numTareas);
            while (tiempo > 0 && tiempoUsado[tiempo - 1]) {
                tiempo--;
            }
            if (tiempo > 0) {
                tareasAsignadas[tiempo - 1] = tareas[i];
                tiempoUsado[tiempo - 1] = true;
            }
        }

        for (int i = 0; i < numTareas; i++) {
            tareas[i] = tareasAsignadas[i];
        }
    }

    Tareas* getTarea(int index) {
        return tareas[index];
    }
};

int main() {
    Planificador planificador(6);

    planificador.agregarTarea(0, 20, 3);
    planificador.agregarTarea(1, 15, 1);
    planificador.agregarTarea(2, 10, 1);
    planificador.agregarTarea(3, 7, 3);
    planificador.agregarTarea(4, 5, 1);
    planificador.agregarTarea(5, 3, 3);

    planificador.ordenarTareas();

    for (int i = 0; i < 6; i++) {
        Tareas* tarea = planificador.getTarea(i);
        cout << "Tarea " << i+1 << ": Beneficio = " << tarea->beneficio << ", Plazo = " << tarea->plazo << endl;
    }

    return 0;
}
