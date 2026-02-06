#include <stdio.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k, n1 = m - l + 1, n2 = r - m;
    int L[100], R[100];
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = (low - 1), j, temp;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, i, arr[100], temp[100];
    clock_t start, end;

    printf("Enter n: "); scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (i = 0; i < n; i++) temp[i] = arr[i];
    start = clock();
    mergeSort(temp, 0, n - 1);
    end = clock();
    printf("\nMerge Sort: ");
    for (i = 0; i < n; i++) printf("%d ", temp[i]);
    printf("\nTime: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    for (i = 0; i < n; i++) temp[i] = arr[i];
    start = clock();
    quickSort(temp, 0, n - 1);
    end = clock();
    printf("\nQuick Sort: ");
    for (i = 0; i < n; i++) printf("%d ", temp[i]);
    printf("\nTime: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}