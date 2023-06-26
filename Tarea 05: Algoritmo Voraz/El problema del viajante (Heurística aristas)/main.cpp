#include <iostream>
#include <list>
#include <limits>

class Graph {
    int numVertices;
    std::list<std::pair<int, int>>* adjacencyList;

public:
    Graph(int vertices) : numVertices(vertices) {
        adjacencyList = new std::list<std::pair<int, int>>[numVertices];
    }

    void addEdge(int source, int destination, int weight) {
        adjacencyList[source].push_back(std::make_pair(destination, weight));
        adjacencyList[destination].push_back(std::make_pair(source, weight));
    }

    void tsp(int& totalCost) {
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            visited[i] = false;
        }
        visited[0] = true;  // Empezar en el nodo 0

        std::list<std::pair<int, int>> path;
        int currentVertex = 0;
        int minCost = 0;

        for (int count = 0; count < numVertices - 1; ++count) {
            int nextVertex = -1;
            int minWeight = std::numeric_limits<int>::max();

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
                path.push_back(std::make_pair(currentVertex, nextVertex));
                minCost += minWeight;
                currentVertex = nextVertex;
            }
        }

        path.push_back(std::make_pair(currentVertex, 0));
        minCost += adjacencyList[currentVertex].front().second;

        totalCost = minCost;

        std::cout << "Camino óptimo por aristas: ";
        for (const auto& edge : path) {
            std::cout << "(" << edge.first << "," << edge.second << ") ";
        }
        std::cout << std::endl;

        std::cout << "Costo total del camino: " << totalCost << std::endl;

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
