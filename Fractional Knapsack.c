#include <stdio.h>


struct Item {
    int profit;
    int weight;
    float ratio;
};

void sort(struct Item arr[], int n) {
    int i, j;
    struct Item temp;

    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(arr[i].ratio < arr[j].ratio) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


float fractionalKnapsack(int W, struct Item arr[], int n) {
    float totalProfit = 0.0;

    for(int i = 0; i < n; i++) {
        if(arr[i].weight <= W) {
            totalProfit += arr[i].profit;
            W -= arr[i].weight;
        } else {
            totalProfit += arr[i].profit * ((float)W / arr[i].weight);
            break;
        }
    }

    return totalProfit;
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    printf("Enter profit and weight:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].profit, &arr[i].weight);
        arr[i].ratio = (float)arr[i].profit / arr[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    sort(arr, n);

    float maxProfit = fractionalKnapsack(W, arr, n);

    printf("Maximum Profit = %.2f\n", maxProfit);

    return 0;
}
