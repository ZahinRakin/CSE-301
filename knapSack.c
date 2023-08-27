#include <stdio.h>
#include <stdlib.h>

void fractionalKnapsack(int weights[], int benefits[], int n, int maxWeight) {
    double ratios[n];
    for (int i = 0; i < n; i++) {
        ratios[i] = (double)benefits[i] / weights[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratios[j] < ratios[j + 1]) {
                double tempRatio = ratios[j];
                ratios[j] = ratios[j + 1];
                ratios[j + 1] = tempRatio;

                int tempWeight = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = tempWeight;

                int tempBenefit = benefits[j];
                benefits[j] = benefits[j + 1];
                benefits[j + 1] = tempBenefit;
            }
        }
    }

    int currentWeight = 0;
    double totalBenefit = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weights[i] <= maxWeight) {
            totalBenefit += benefits[i];
            currentWeight += weights[i];
            printf("Item %d: %d units\n", i + 1, weights[i]);
        } else {
            double fraction = (double)(maxWeight - currentWeight) / weights[i];
            totalBenefit += fraction * benefits[i];
            printf("Item %d: %.2f units\n", i + 1, fraction);
            break;
        }
    }

    printf("Maximum benefit: %.2f\n", totalBenefit);
}

int main() {
    int weights[] = {10, 20, 30};
    int benefits[] = {60, 100, 120};
    int n = sizeof(weights) / sizeof(weights[0]);
    int maxWeight = 50;

    fractionalKnapsack(weights, benefits, n, maxWeight);

    return 0;
}
