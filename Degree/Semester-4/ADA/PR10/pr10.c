#include <stdio.h>

int board[10], count;

int safe(int row, int col) {
    for (int i = 1; i < col; i++) {
        if (board[i] == row || board[i] - i == row - col || board[i] + i == row + col) {
            return 0;
        }
    }
    return 1;
}

void printSolution(int n) {
    printf("\nSolution %d:\n", ++count);

    for (int i = 1; i <= n; i++) {
        printf("%d ", board[i]);
    }
}

void solve(int col, int n) {
    for (int row = 1; row <= n; row++) {
        if (safe(row, col)) {
            board[col] = row;

            if (col == n) {
                printSolution(n);
            } else {
                solve(col + 1, n);
            }
        }
    }
}

int main(void) {
    int n;

    printf("Enter number of queens (4 or 8): ");
    scanf("%d", &n);

    solve(1, n);
    printf("\nTotal solutions: %d", count);
    return 0;
}