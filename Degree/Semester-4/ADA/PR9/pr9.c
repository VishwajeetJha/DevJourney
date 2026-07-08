#include <stdio.h>
#include <string.h>

#define MAX 20
#define INF 999999

void matrixChain(int p[], int n) {
    int m[MAX][MAX], q;

    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INF;

            for (int k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    printf("\nMinimum number of multiplications = %d\n", m[1][n]);
}

int lcs(char x[], char y[]) {
    int m = strlen(x), n = strlen(y), dp[MAX][MAX] = {0};

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main(void) {
    int choice, n, p[MAX];
    char X[MAX], Y[MAX];

    printf("Choose:\n1. Matrix Chain Multiplication\n2. LCS/SCS\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter number of matrices: ");
        scanf("%d", &n);

        printf("Enter dimensions (p0 p1 ... pn):\n");

        for (int i = 0; i <= n; i++) {
            scanf("%d", &p[i]);
        }

        matrixChain(p, n);
    } else if (choice == 2) {
        int len;

        printf("Enter first string: ");
        scanf("%49s", X);

        printf("Enter second string: ");
        scanf("%49s", Y);

        len = lcs(X, Y);

        printf("\nLength of Longest Common Subsequence (LCS) = %d", len);
        printf("\nLength of Shortest Common Supersequence (SCS) = %lu\n", strlen(X) + strlen(Y) - len);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}