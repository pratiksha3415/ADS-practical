#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    // Build dp table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Trace back and print selected items
    int w = W;
    cout << "Items included (0-based index): ";
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i - 1 << " ";  // Item index
            w -= wt[i - 1];        // Reduce remaining capacity
        }
    }
    cout << endl;

    return dp[n][W];
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int val[n], wt[n];

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int maxValue = knapsack(W, wt, val, n);

    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}
