#include <iostream>
#include <vector>
#include <queue>

struct Tarea {
    int id;
    int tiempoRafaga;
    int tiempoRestante;
};

void planificarTareas(const std::vector<Tarea>& tareas, int quantumTiempo) {
    std::queue<Tarea> colaTareas;

    for (const auto& tarea : tareas) {
        colaTareas.push(tarea);
    }

    while (!colaTareas.empty()) {
        Tarea tareaActual = colaTareas.front();
        colaTareas.pop();

        int tiempoEjecucion = std::min(quantumTiempo, tareaActual.tiempoRestante);
        tareaActual.tiempoRestante -= tiempoEjecucion;

        std::cout << "Ejecutando Tarea " << tareaActual.id << " durante " << tiempoEjecucion << " unidades de tiempo." << std::endl;

        if (tareaActual.tiempoRestante > 0) {
            colaTareas.push(tareaActual);
        }
    }

    std::cout << "Todas las tareas han sido ejecutadas correctamente." << std::endl;
}

int main() {
    std::vector<Tarea> tareas = {{1, 10, 10}, {2, 5, 5}, {3, 8, 8}};
    int quantumTiempo = 4;

    planificarTareas(tareas, quantumTiempo);

    return 0;
}

