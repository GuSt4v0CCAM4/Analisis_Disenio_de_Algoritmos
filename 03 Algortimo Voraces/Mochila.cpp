#include <iostream>
#include <vector>
#include <algorithm>

struct Objeto {
    int peso;
    int valor;
};

int mochila(int capacidad, const std::vector<Objeto>& objetos) {
    int n = objetos.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacidad + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacidad; ++w) {
            if (objetos[i - 1].peso <= w) {
                dp[i][w] = std::max(objetos[i - 1].valor + dp[i - 1][w - objetos[i - 1].peso], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacidad];
}

int main() {
    std::vector<Objeto> objetos = {{2, 12}, {1, 10}, {3, 20}, {2, 15}, {4, 30}};
    int capacidad = 5;

    int valorMaximo = mochila(capacidad, objetos);

    std::cout << "Valor máximo que se puede obtener: " << valorMaximo << std::endl;

    return 0;
}

