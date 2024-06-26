#include <stdio.h>

#define MAX_ITEMS 100

struct Item {
    float value;
    float weight;
    float ratio; // Value-to-weight ratio
};

float fractionalKnapsack(struct Item items[], int n, float capacity) {
    // Sort items by value-to-weight ratio in descending order
    qsort(items, n, sizeof(items[0]), [](const void* a, const void* b) {
        struct Item* item1 = (struct Item*)a;
        struct Item* item2 = (struct Item*)b;
        return item1->ratio > item2->ratio ? -1 : 1;
    });

    float totalValue = 0.0f;
    int i = 0;

    // Include items until the knapsack is full or all items are considered
    while ((capacity > 0) && (i < n)) {
        float fraction = capacity / items[i].weight;

        // If item can be included completely
        if (fraction >= 1) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
            i++;
        } else {
            // Include a fraction of the item
            totalValue += items[i].ratio * capacity;
            capacity = 0; // Break out since knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n;
    float capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the fractional knapsack: ");
    scanf("%f", &capacity);

    struct Item items[MAX_ITEMS];

    printf("Enter the values and weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &items[i].value, &items[i].weight);
        items[i].ratio = items[i].value / items[i].weight; // Calculate ratio
    }

    printf("Maximum value that can be put in a fractional knapsack of capacity %.1f is %.1f\n", capacity, fractionalKnapsack(items, n, capacity));

    return 0;
}

// Number of items (n) (same as 0/1 Knapsack): 3
// Capacity of the fractional knapsack (capacity): 50.0
// Values of items: 60.0 100.0 120.0
// Weights of items: 10.0 20.0 30.0