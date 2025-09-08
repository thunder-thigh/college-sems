#include <stdio.h>
#include <stdlib.h>

// structure to represent an item
typedef struct {
    int value;
    int weight;
    double ratio;
} Item;

// comparator function to sort items by value-to-weight ratio (descending)
int cmp(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemB->ratio > itemA->ratio) return 1;
    else if (itemB->ratio < itemA->ratio) return -1;
    else return 0;
}

// Fractional Knapsack function
double fractionalKnapsack(int capacity, Item items[], int n) {
    // Calculate ratio for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Sort items by ratio
    qsort(items, n, sizeof(Item), cmp);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            // Take full item
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            // Take fractional part
            double fraction = ((double)remainingCapacity) / items[i].weight;
            totalValue += items[i].value * fraction;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    Item items[n];

    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    double maxValue = fractionalKnapsack(capacity, items, n);

    printf("Maximum value in knapsack = %.2lf\n", maxValue);

    return 0;
}

