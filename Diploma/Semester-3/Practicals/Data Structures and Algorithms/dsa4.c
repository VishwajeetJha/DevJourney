//Data Structure and Algorithms Practical 4: Binary Search

#include <stdio.h>
int main() {
    int N;
    printf("Enter size of array: ");
    scanf("%d", &N);
    int a[N];
    int i, j, m, x;
    int l = 0, u = N - 1;
    printf("Enter elements of array: \n"); 
    for (i = 0; i < N; i++) {
        printf("Element at Index No %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("Enter Number you want to search: ");
    scanf("%d", &x);
   
    while (l <= u) {
        m = l + (u - l) / 2;
        if (a[m] == x) {
            printf("\nNumber Found at Index %d.", m);
            break;
        } else if (N>1 && a[0] > a[1]) { //if first ele > second, 5>4 then it is Desc right.
        
            if (a[m] < x) {
                u = m - 1;
            } else {
                l = m + 1;
            }
        } 
        else { // by comparing we have already found the order innit? -- ascending
            if (a[m] > x) {
                u = m - 1;
            } else {
                l = m + 1;
            }
        }
    }
    if (l > u) {
        printf("Number Not found in Array\n");
    }
    return 0;
}
