#include <stdio.h>
#include <time.h>

int main() {
    int array[100], n, key, i;
    clock_t start, end;
    
    double time_taken;

    printf("Linear Search O(n)\n");
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) scanf("%d", &array[i]);

    printf("Search element: ");
    scanf("%d", &key);

    start = clock();
    for (i = 0; i < n; i++) {
        if (array[i] == key) {
            printf("%d found at location %d\n", key, i + 1);
            break;
        }
    }
    end = clock();

    if (i == n) printf("%d not found\n", key);

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time: %f s\n", time_taken);

    return 0;
}