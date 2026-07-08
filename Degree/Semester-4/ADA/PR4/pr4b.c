#include <stdio.h>

void sortByFinishTime(int start[], int finish[], int activity[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (finish[i] > finish[j]) {
                temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;

                temp = start[i];
                start[i] = start[j];
                start[j] = temp;

                temp = activity[i];
                activity[i] = activity[j];
                activity[j] = temp;
            }
        }
    }
}

int main() {
    int start[100], finish[100], activity[100], selected[100];
    int n, i, lastFinish, selectedCount = 0;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        activity[i] = i + 1;
    }

    printf("Enter start and finish times:\n");
    for (i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
    }

    sortByFinishTime(start, finish, activity, n);

    selected[selectedCount++] = activity[0];
    lastFinish = finish[0];

    for (i = 1; i < n; i++) {
        if (start[i] >= lastFinish) {
            selected[selectedCount++] = activity[i];
            lastFinish = finish[i];
        }
    }

    printf("\nSelected activities: ");
    for (i = 0; i < selectedCount; i++) {
        printf("A%d ", selected[i]);
    }
    printf("\nTotal selected activities: %d\n", selectedCount);

    return 0;
}