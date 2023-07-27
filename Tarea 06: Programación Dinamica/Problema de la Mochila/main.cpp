#include <iostream>
#include <vector>
using namespace std;
class Knapsack {
private:
    int numObjects;
    int capacity;
    vector<int> weights;
    vector<int> profits;
    vector<vector<int>> dpTable;

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

public:
    Knapsack(int n, int m) : numObjects(n), capacity(m), weights(n), profits(n) {}

    void readObjectDetails() {
        for (int i = 0; i < numObjects; i++) {
            cout << "Peso del Objeto " << i + 1 << ": ";
            cin >> weights[i];
            cout << "Benficio del Objeto " << i + 1 << ": ";
            cin >> profits[i];
        }
    }

    void knapsack01() {
        dpTable.resize(numObjects + 1, vector<int>(capacity + 1, 0));

        for (int i = 1; i <= numObjects; i++) {
            for (int j = 1; j <= capacity; j++) {
                if (weights[i - 1] <= j) {
                    dpTable[i][j] = max(profits[i - 1] + dpTable[i - 1][j - weights[i - 1]], dpTable[i - 1][j]);
                } else {
                    dpTable[i][j] = dpTable[i - 1][j];
                }
            }
        }

        cout << "Tabla:" << endl;
        for (int i = 0; i <= numObjects; i++) {
            for (int j = 0; j <= capacity; j++) {
                cout << dpTable[i][j] << " ";
            }
            cout << endl;
        }

        cout << "El maximo beneficios es: " << dpTable[numObjects][capacity] << endl;
    }
};

int main() {
    int n=3;
    int m=6;


    Knapsack knapsack(n, m);
    knapsack.readObjectDetails();
    knapsack.knapsack01();

    return 0;
}
