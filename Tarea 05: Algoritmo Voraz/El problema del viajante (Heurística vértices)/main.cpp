#include <iostream>
#include <list>
#include <limits>
using namespace std;
class Graph {
    int numVertices;
    list<pair<int, int>>* adjacencyList;

public:
    Graph(int vertices) : numVertices(vertices) {
        adjacencyList = new list<pair<int, int>>[numVertices];
    }

    void addEdge(int source, int destination, int weight) {
        adjacencyList[source].push_back(make_pair(destination, weight));
        adjacencyList[destination].push_back(make_pair(source, weight));
    }

    void tsp(int& totalCost) {
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            visited[i] = false;
        }
        visited[0] = true;  // Empezar en el nodo 0

        list<int> path;
        path.push_back(0);

        int currentVertex = 0;
        int minCost = 0;

        for (int count = 0; count < numVertices - 1; ++count) {
            int nextVertex = -1;
            int minWeight = numeric_limits<int>::max();

            for (const auto& neighbor : adjacencyList[currentVertex]) {
                int vertex = neighbor.first;
                int weight = neighbor.second;

                if (!visited[vertex] && weight < minWeight) {
                    nextVertex = vertex;
                    minWeight = weight;
                }
            }

            if (nextVertex != -1) {
                visited[nextVertex] = true;
                path.push_back(nextVertex);
                minCost += minWeight;
                currentVertex = nextVertex;
            }
        }

        path.push_back(0);
        minCost += adjacencyList[currentVertex].front().second;

        totalCost = minCost;

        cout << "Camino óptimo: ";
        for (int vertex : path) {
            cout << vertex << " ";
        }
        cout << endl;

        // Mostrar el costo total del camino
        cout << "Costo total del camino: " << totalCost << endl;

        delete[] visited;
    }

    ~Graph() {
        delete[] adjacencyList;
    }
};

int main() {
    Graph graph(6);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 55);
    graph.addEdge(0, 3, 25);
    graph.addEdge(0, 4, 45);
    graph.addEdge(1, 2, 20);
    graph.addEdge(1, 3, 25);
    graph.addEdge(1, 4, 40);
    graph.addEdge(2, 3, 15);
    graph.addEdge(2, 4, 30);
    graph.addEdge(3, 4, 50);

    int totalCost = 0;
    graph.tsp(totalCost);

    return 0;
}
