#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> knapsack(int P, vector<int> &pesos, vector<int> &valores, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(P + 1, 0));

    // Construimos la tabla dp[][]
    for (int i = 1; i <= n; i++) {
        for (int p = 1; p <= P; p++) {
            if (pesos[i - 1] <= p) {
                dp[i][p] = max(valores[i - 1] + dp[i - 1][p - pesos[i - 1]], dp[i - 1][p]);
            } else {
                dp[i][p] = dp[i - 1][p];
            }
        }
    }

    // Devolver el valor máximo que se puede poner en una mochila de capacidad P
    return dp;//[n][P];
}


void imprimirTablaDP(const vector<vector<int>> &dp) {
    for (const auto &fila: dp) {
        for (int valor: fila) {
            cout << valor << " ";
        }
        cout << endl;
    }
}


int main() {
    int P = 12; // Capacidad de la mochila
    vector<int> pesos = {5, 4, 8, 2, 7}; // Pesos de los artículos
    vector<int> valores = {60, 80, 120, 70, 45}; // Valores de los artículos
    int n = pesos.size(); // Número de artículos

    vector<vector<int>> dp = knapsack(P, pesos, valores, n);

    cout << "Valor máximo en la mochila = " << dp[n][P] << endl;

    //cout << "Valor máximo en la mochila = " << knapsack(P, pesos, valores, n) << endl;

    imprimirTablaDP(dp);
    return 0;
}