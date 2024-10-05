#include <iostream>
#include <vector>
using namespace std;

// A utility function to return the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table dp[] in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 50;  // Capacity of the knapsack
    vector<int> weights = {10, 20, 30};  // Weights of items
    vector<int> values = {60, 100, 120}; // Values of items
    int n = weights.size();

    cout << "Maximum value in Knapsack: " << knapsack(W, weights, values, n) << endl;

    return 0;
}
