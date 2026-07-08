#include <stdio.h>

#define MAX 20

struct item { 
    int id, w, v; float r; 
};
struct job { 
    int id, d, p; 
};

void sortItems(struct item a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i].r < a[j].r) { 
                struct item t = a[i]; a[i] = a[j]; a[j] = t; 
            }
}

void sortJobs(struct job a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i].p < a[j].p) { 
                struct job t = a[i]; a[i] = a[j]; a[j] = t; 
            }
}

void knapSack(void) {
    struct item a[MAX];
    int n, cap;
    printf("\n--- Fractional Knapsack ---\nEnter Number of Items: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        a[i].id = i + 1;
        printf("Item %d\n  Weight: ", a[i].id); scanf("%d", &a[i].w);
        printf("  Value: "); scanf("%d", &a[i].v);
        a[i].r = (float)a[i].v / a[i].w;
    }
    printf("Enter Maximum Knapsack Capacity: ");
    scanf("%d", &cap);
    sortItems(a, n);
    float total = 0;
    printf("\n%-8s %-8s %-8s %-8s\n", "ID", "Weight", "Value", "Ratio");
    for (int i = 0; i < n && cap > 0; i++) {
        int take = cap < a[i].w ? cap : a[i].w;
        total += a[i].r * take;
        printf("%-8d %-8d %-8d %-8.2f %s\n", a[i].id, a[i].w, a[i].v, a[i].r,
               take == a[i].w ? "Full" : "Partial");
        cap -= take;
    }
    printf("Final Profit in Knapsack: %.2f\n\n", total);
}

void jobScheduling(void) {
    struct job a[MAX];
    int slot[MAX] = {0}, res[MAX], n, total = 0;
    printf("\n--- Job Scheduling with Deadlines ---\nEnter number of jobs: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Job %d\n  ID: ", i + 1); scanf("%d", &a[i].id);
        printf("  Deadline: "); scanf("%d", &a[i].d);
        printf("  Profit: "); scanf("%d", &a[i].p);
    }
    sortJobs(a, n);
    for (int i = 0; i < n; i++)
        for (int j = (a[i].d < MAX ? a[i].d : MAX) - 1; j >= 0; j--)
            if (!slot[j]) { slot[j] = 1; res[j] = i; total += a[i].p; break; }

    printf("\nOptimal Job Sequence:\n");
    for (int i = 0; i < MAX; i++)
        if (slot[i]) printf("Slot [%d-%d]: Job %d (Profit: %d)\n", i, i + 1, a[res[i]].id, a[res[i]].p);
    printf("Total Profit: %d\n\n", total);
}

int main(void) {
    int choice;
    for (;;) {
        printf("\nGreedy Algorithm Menu\n\n1. Fractional Knapsack\n2. Job Scheduling\n3. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) knapSack();
        else if (choice == 2) jobScheduling();
        else if (choice == 3) break;
        else printf("Invalid choice! Try again.\n");
    }
    return 0;
}