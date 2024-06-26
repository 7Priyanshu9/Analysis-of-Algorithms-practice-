#include <stdio.h>

int knapSack(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0; // Base Cases
            } else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
                // Choose between including or excluding the item
            } else {
                K[i][w] = K[i - 1][w]; // Exclude the item if it doesn't fit
            }
        }
    }

    return K[n][W]; // Return the maximum value that can be put in a knapsack of capacity W
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int val[n], wt[n];

    printf("Enter the values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter the weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Max value that can be put in a knapsack of capacity %d is %d\n", W, knapSack(W, wt, val, n));

    return 0;
}

// Number of items (n): 3
// Capacity of the knapsack (W): 50
// Values of items: 60 100 120
// Weights of items: 10 20 30