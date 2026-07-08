#include <stdio.h>
#include <pthread.h>

#define SIZE 1009

int a[SIZE], b[SIZE], sum[SIZE], sub[SIZE];

void *addition(void *arg)
{
    int i;
    for(i = 0; i < SIZE; i++)
        sum[i] = a[i] + b[i];

    pthread_exit(NULL);
}

void *subtraction(void *arg)
{
    int i;
    for(i = 0; i < SIZE; i++)
        sub[i] = a[i] - b[i];

    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2;
    int i;

    for(i = 0; i < SIZE; i++)
    {
        a[i] = i + 1;
        b[i] = i + 2;
    }

    pthread_create(&t1, NULL, addition, NULL);
    pthread_create(&t2, NULL, subtraction, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("First 5 Results:\n");
    for(i = 0; i < 5; i++)
        printf("%d + %d = %d , %d - %d = %d\n",
               a[i], b[i], sum[i], a[i], b[i], sub[i]);

    return 0;
}