#include <stdio.h>

void sortDescending(int denominations[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (denominations[i] < denominations[j]) {
                temp = denominations[i];
                denominations[i] = denominations[j];
                denominations[j] = temp;
            }
        }
    }
}

int main() {
    int denominations[100], n, amount, i, count = 0, coins;

    printf("Enter number of denominations: ");
    scanf("%d", &n);

    printf("Enter denominations: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &denominations[i]);
    }

    printf("Enter amount: ");
    scanf("%d", &amount);

    sortDescending(denominations, n);

    printf("\nGreedy Make Change Solution:\n");
    for (i = 0; i < n; i++) {
        coins = amount / denominations[i];
        if (coins > 0) {
            printf("%d x %d\n", denominations[i], coins);
            count += coins;
            amount = amount % denominations[i];
        }
    }

    if (amount != 0) {
        printf("Remaining amount cannot be changed exactly: %d\n", amount);
    }

    printf("Total coins used: %d\n", count);

    return 0;
}