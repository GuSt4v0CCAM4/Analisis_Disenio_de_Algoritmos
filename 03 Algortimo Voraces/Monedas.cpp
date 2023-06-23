#include <iostream>
#include <vector>
#include <climits>

int cambioMonedas(const std::vector<int>& monedas, int cantidad) {
    std::vector<int> dp(cantidad + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= cantidad; ++i) {
        for (int j = 0; j < monedas.size(); ++j) {
            if (monedas[j] <= i && dp[i - monedas[j]] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - monedas[j]] + 1);
            }
        }
    }

    return dp[cantidad] == INT_MAX ? -1 : dp[cantidad];
}

int main() {
    std::vector<int> monedas = {1, 2, 5};
    int cantidad = 11;

    int minMonedas = cambioMonedas(monedas, cantidad);

    std::cout << "Cantidad mínima de monedas requeridas: " << minMonedas << std::endl;

    return 0;
}
