#include <iostream>
using namespace std;

// Function to get the maximum total value in the knapsack
double fractionalKnapsack(int W, int value[], int weight[], int n) {
    // Sorting items by descending value/weight ratio (Simple Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double r1 = (double)value[j] / weight[j];
            double r2 = (double)value[j + 1] / weight[j + 1];
            if (r1 < r2) {
                swap(value[j], value[j + 1]);
                swap(weight[j], weight[j + 1]);
            }
        }
    }

    double finalValue = 0.0; // Variable to store final value

    for (int i = 0; i < n; i++) {
        if (W >= weight[i]) {
            // If we can take the whole item
            W -= weight[i];
            finalValue += value[i];
        } else {
            // If we can only take a fraction of the item
            finalValue += value[i] * ((double)W / weight[i]);
            break; // Knapsack is full
        }
    }
    return finalValue;
}

int main() {
    int n, W;

    // Taking user input
    cout << "Enter no. of items: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int value[n], weight[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter value for item " << i + 1 << ": ";
        cin >> value[i];
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter weight for item " << i + 1 << ": ";
        cin >> weight[i];
    }

    double maxValue = fractionalKnapsack(W, value, weight, n);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}