#include <stdio.h>

#define MAX 50
#define INF 9999

void makeChangeDP(void) {
    int n, amount, coins[MAX], dp[1000], last[1000];

    printf("Enter number of coin types: ");
    scanf("%d", &n);

    printf("Enter coin values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter amount: ");
    scanf("%d", &amount);

    for (int i = 1; i <= amount; i++) {
        dp[i] = INF;
        last[i] = -1;
    }

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            if (dp[j - coins[i]] + 1 < dp[j]) {
                dp[j] = dp[j - coins[i]] + 1;
                last[j] = coins[i];
            }
        }
    }

    printf("\nMinimum coins required: %d\n", dp[amount]);
    printf("Coins used: ");
    for (int a = amount; a > 0 && last[a] != -1; a -= last[a]) {
        printf("[%d] ", last[a]);
    }
    printf("\n");
}

void knapsackDP(void) {
    int n, cap, w, weight[MAX], value[MAX], dp[MAX][1000] = {0};
    int selected[MAX], selectedCount = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and value of each item:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weight[i], &value[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &cap);

    for (int i = 1; i <= n; i++) {
        for (w = 1; w <= cap; w++) {
            if (weight[i - 1] <= w) {
                int include = value[i - 1] + dp[i - 1][w - weight[i - 1]];
                int exclude = dp[i - 1][w];
                dp[i][w] = include > exclude ? include : exclude;
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("\nMaximum value in knapsack = %d\n", dp[n][cap]);

    int i = n;
    w = cap;

    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected[selectedCount++] = i;
            w -= weight[i - 1];
        }
        i--;
    }

    printf("Items chosen: ");
    for (i = selectedCount - 1; i >= 0; i--) {
        int idx = selected[i] - 1;
        printf("[I%d:W%d,V%d] ", selected[i], weight[idx], value[idx]);
    }
    printf("\n");
}

int main(void) {
    int choice;

    printf("Choose:\n1. Make Change (DP)\n2. 0/1 Knapsack (DP)\n");
    scanf("%d", &choice);

    if (choice == 1) {
        makeChangeDP();
    } else if (choice == 2) {
        knapsackDP();
    } else {
        printf("Invalid choice");
    }

    return 0;
}