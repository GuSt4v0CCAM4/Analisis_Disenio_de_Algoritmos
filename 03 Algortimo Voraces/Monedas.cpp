#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int cambioMonedas(const vector<int>& monedas, int cantidad) {
    vector<int> dp(cantidad + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= cantidad; ++i) {
        for (int j = 0; j < monedas.size(); ++j) {
            if (monedas[j] <= i && dp[i - monedas[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - monedas[j]] + 1);
            }
        }
    }

    return dp[cantidad] == INT_MAX ? -1 : dp[cantidad];
}

int main() {
    vector<int> monedas = {1, 2, 5};
    int cantidad = 11;

    int minMonedas = cambioMonedas(monedas, cantidad);

    cout << "Cantidad mínima de monedas requeridas: " << minMonedas << endl;

    return 0;
}
