#include <stdio.h>

#define MAX 20
#define INF 999999

void matrixChain(int p[], int n) {
    int m[MAX][MAX], i, j, k, L, q;

    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INF;

            for (k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    printf("Minimum number of multiplications = %d\n", m[1][n]);
}

int main(void) {
    int n, p[MAX];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions (p0 p1 ... pn):\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    matrixChain(p, n);
    return 0;
}