#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Tarea {
    int id;
    int tiempoRafaga;
    int tiempoRestante;
};

void planificarTareas(const vector<Tarea>& tareas, int quantumTiempo) {
    queue<Tarea> colaTareas;

    for (const auto& tarea : tareas) {
        colaTareas.push(tarea);
    }

    while (!colaTareas.empty()) {
        Tarea tareaActual = colaTareas.front();
        colaTareas.pop();

        int tiempoEjecucion = min(quantumTiempo, tareaActual.tiempoRestante);
        tareaActual.tiempoRestante -= tiempoEjecucion;

        cout << "Ejecutando Tarea " << tareaActual.id << " durante " << tiempoEjecucion << " unidades de tiempo." << endl;

        if (tareaActual.tiempoRestante > 0) {
            colaTareas.push(tareaActual);
        }
    }

    cout << "Todas las tareas han sido ejecutadas correctamente." << endl;
}

int main() {
    vector<Tarea> tareas = {{1, 10, 10}, {2, 5, 5}, {3, 8, 8}};
    int quantumTiempo = 4;

    planificarTareas(tareas, quantumTiempo);

    return 0;
}

